#ifndef TAREFACONTROLLER_HPP
#define TAREFACONTROLLER_HPP

#include "../models/Tarefa.hpp"
#include "../dao/TarefaDAO.hpp"
#include <vector>

class TarefaController
{
private:
    TarefaDAO &dao;

public:
    TarefaController(TarefaDAO &dao);
    bool criarTarefa(const Tarefa &tarefa);
    bool atualizarTarefa(const Tarefa &t);
    bool excluirTarefa(int id);
    std::vector<Tarefa> listarTarefas();
};

#endif
