// src/dao/TarefaDAO.cpp
#include "TarefaDAO.hpp"
#include <iostream>
#include <sstream>
#include <sqlite3.h>

TarefaDAO::TarefaDAO(Database &db) : db(db) {}

bool TarefaDAO::salvar(const Tarefa &tarefa)
{
    std::cout << "[DAO] Salvando tarefa: " << tarefa.getTitulo() << std::endl;
    sqlite3 *dbPtr = db.getDB();
    if (!dbPtr)
    {
        std::cerr << "DB não está aberto." << std::endl;
        return false;
    }

    std::string sql = "INSERT INTO tarefas (titulo, grupo, status, pomodoros, prazo, notas) VALUES (?1, ?2, ?3, ?4, ?5, ?6);";
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(dbPtr, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Erro prepare INSERT: " << sqlite3_errmsg(dbPtr) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, tarefa.getTitulo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, tarefa.getGrupo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, tarefa.getStatus().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, tarefa.getPomodoros());
    sqlite3_bind_text(stmt, 5, tarefa.getPrazo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, tarefa.getNotas().c_str(), -1, SQLITE_TRANSIENT);

    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Erro ao executar INSERT: " << sqlite3_errmsg(dbPtr) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool TarefaDAO::atualizar(const Tarefa &tarefa)
{
    std::cout << "[DAO] Atualizando tarefa: " << tarefa.getTitulo() << std::endl;
    sqlite3 *dbPtr = db.getDB();
    if (!dbPtr)
    {
        std::cerr << "DB não está aberto." << std::endl;
        return false;
    }

    std::string sql = "UPDATE tarefas SET titulo = ?1, grupo = ?2, status = ?3, pomodoros = ?4, prazo = ?5, notas = ?6 WHERE id = ?7;";
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(dbPtr, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Erro prepare UPDATE: " << sqlite3_errmsg(dbPtr) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, tarefa.getTitulo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, tarefa.getGrupo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, tarefa.getStatus().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, tarefa.getPomodoros());
    sqlite3_bind_text(stmt, 5, tarefa.getPrazo().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, tarefa.getNotas().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 7, tarefa.getId());

    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Erro ao executar UPDATE: " << sqlite3_errmsg(dbPtr) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool TarefaDAO::excluir(int id)
{
    std::cout << "[DAO] Excluindo tarefa com ID: " << id << std::endl;
    sqlite3 *dbPtr = db.getDB();
    if (!dbPtr)
    {
        std::cerr << "DB não está aberto." << std::endl;
        return false;
    }

    std::string sql = "DELETE FROM tarefas WHERE id = ?1;";
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(dbPtr, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Erro prepare DELETE: " << sqlite3_errmsg(dbPtr) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, id);

    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cerr << "Erro ao executar DELETE: " << sqlite3_errmsg(dbPtr) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

std::vector<Tarefa> TarefaDAO::listar()
{
    std::cout << "[DAO] Listando tarefas..." << std::endl;
    std::vector<Tarefa> tarefas;
    sqlite3 *dbPtr = db.getDB();
    if (!dbPtr)
    {
        std::cerr << "DB não está aberto." << std::endl;
        return tarefas;
    }

    std::string sql = "SELECT id, titulo, grupo, status, pomodoros, prazo, notas FROM tarefas;";
    sqlite3_stmt *stmt = nullptr;
    if (sqlite3_prepare_v2(dbPtr, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Erro prepare SELECT: " << sqlite3_errmsg(dbPtr) << std::endl;
        return tarefas;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        Tarefa t;
        t.setId(sqlite3_column_int(stmt, 0));
        const unsigned char *titulo = sqlite3_column_text(stmt, 1);
        const unsigned char *grupo = sqlite3_column_text(stmt, 2);
        const unsigned char *status = sqlite3_column_text(stmt, 3);
        int pomodoros = sqlite3_column_int(stmt, 4);
        const unsigned char *prazo = sqlite3_column_text(stmt, 5);
        const unsigned char *notas = sqlite3_column_text(stmt, 6);

        if (titulo)
            t.setTitulo(reinterpret_cast<const char *>(titulo));
        if (grupo)
            t.setGrupo(reinterpret_cast<const char *>(grupo));
        if (status)
            t.setStatus(reinterpret_cast<const char *>(status));
        t.setPomodoros(pomodoros);
        if (prazo)
            t.setPrazo(reinterpret_cast<const char *>(prazo));
        if (notas)
            t.setNotas(reinterpret_cast<const char *>(notas));

        tarefas.push_back(t);
    }

    sqlite3_finalize(stmt);
    return tarefas;
}
