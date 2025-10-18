// src/dao/TarefaDAO.hpp
#ifndef TAREFADAO_HPP
#define TAREFADAO_HPP

#include "../models/Tarefa.hpp"
#include "../utils/Database.hpp"
#include "ITarefaDAO.hpp"
#include <vector>

// HERANÇA: herdando a interface ITarefaDAO, e usa override para implementar os métodos

class TarefaDAO : public ITarefaDAO
{
private:
    Database &db;

public:
    explicit TarefaDAO(Database &db);

    bool salvar(const Tarefa &tarefa) override;
    bool atualizar(const Tarefa &tarefa) override;
    bool excluir(int id) override;
    std::vector<Tarefa> listar() override;
};

#endif
