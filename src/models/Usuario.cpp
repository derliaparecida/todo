#include "Usuario.hpp"
#include <iostream>

Usuario::Usuario(const std::string &id, const std::string &nome, const std::string &senha, const std::string &email)
    : id(id), nome(nome), senha(senha), email(email) {}

std::string Usuario::getNome() const { return nome; }

std::string Usuario::getEmail() const { return email; }

bool Usuario::autenticar(const std::string &senhaDigitada) const
{
    return senha == senhaDigitada;
}

bool Usuario::salvar(Database &db)
{
    sqlite3 *conn = db.getDB();
    if (!conn)
    {
        std::cerr << "Erro ao conectar com o banco de dados!" << std::endl;
        return false;
    }

    const char *sql = "INSERT INTO usuarios (id, nome, senha, email) VALUES (?, ?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(conn, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Erro ao preparar statement: " << sqlite3_errmsg(conn) << std::endl;
        return false;
    }

    // Vincula os parâmetros
    sqlite3_bind_text(stmt, 1, id.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, nome.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, senha.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, email.c_str(), -1, SQLITE_TRANSIENT);

    // Executa a query
    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        std::cerr << "Erro ao inserir usuário: " << sqlite3_errmsg(conn) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}
