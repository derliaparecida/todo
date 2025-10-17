// src/dao/TarefaDAO.cpp
#include "TarefaDAO.hpp"
#include <iostream>

TarefaDAO::TarefaDAO(Database &db) : db(db) {}

bool TarefaDAO::salvar(const Tarefa &tarefa)
{
    std::cout << "[DAO] Salvando tarefa: " << tarefa.getTitulo() << std::endl;
    // TODO: adicionar INSERT no banco
    return true;
}

bool TarefaDAO::atualizar(const Tarefa &tarefa)
{
    std::cout << "[DAO] Atualizando tarefa: " << tarefa.getTitulo() << std::endl;
    return true;
}

bool TarefaDAO::excluir(int id)
{
    std::cout << "[DAO] Excluindo tarefa com ID: " << id << std::endl;
    return true;
}

std::vector<Tarefa> TarefaDAO::listar()
{
    std::cout << "[DAO] Listando tarefas..." << std::endl;
    return {};
}
