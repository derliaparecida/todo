#ifndef TAREFAVIEW_HPP
#define TAREFAVIEW_HPP

#include "../controllers/TarefaController.hpp"
#include "../models/Tarefa.hpp"
#include <string>

class TarefaView
{
private:
    TarefaController &controller;

public:
    TarefaView(TarefaController &controller);
    void criarTarefaInterativa();
    void listarTarefas();
    void editarTarefa();
    void excluirTarefa();

    void menu(); // exibe o menu principal de tarefas
};

#endif
