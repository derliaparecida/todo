#ifndef TAREFACONTROLLER_HPP
#define TAREFACONTROLLER_HPP

#include "../models/Tarefa.hpp"
#include "../dao/ITarefaDAO.hpp"
#include <vector>

// Abstração/Dependência: controlador depende da interface ITarefaDAO

class TarefaController
{
private:
    ITarefaDAO &dao;

public:
    TarefaController(ITarefaDAO &dao);
    bool criarTarefa(const Tarefa &tarefa);
    bool atualizarTarefa(const Tarefa &t);
    bool excluirTarefa(int id);
    std::vector<Tarefa> listarTarefas();
};

#endif
