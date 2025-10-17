// src/dao/TarefaDAO.hpp
#ifndef TAREFADAO_HPP
#define TAREFADAO_HPP

#include "../models/Tarefa.hpp"
#include "../utils/Database.hpp"
#include <vector>

class TarefaDAO
{
private:
    Database &db;

public:
    explicit TarefaDAO(Database &db);

    bool salvar(const Tarefa &tarefa);
    bool atualizar(const Tarefa &tarefa);
    bool excluir(int id);
    std::vector<Tarefa> listar();
};

#endif
