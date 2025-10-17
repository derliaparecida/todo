#include "TarefaView.hpp"
#include <iostream>
#include <limits>

using namespace std;

// Construtor
TarefaView::TarefaView(TarefaController &controller) : controller(controller) {}

// Menu principal
void TarefaView::menu()
{
    int opcao = -1;
    while (opcao != 0)
    {
        cout << "\n=== MENU DE TAREFAS ===\n";
        cout << "1. Criar nova tarefa\n";
        cout << "2. Listar tarefas\n";
        cout << "3. Editar tarefa\n";
        cout << "4. Excluir tarefa\n";
        cout << "0. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcao)
        {
        case 1:
            criarTarefaInterativa();
            break;
        case 2:
            listarTarefas();
            break;
        case 3:
            editarTarefa();
            break;
        case 4:
            excluirTarefa();
            break;
        case 0:
            cout << "Voltando...\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }
    }
}

// Criar tarefa
void TarefaView::criarTarefaInterativa()
{
    string titulo;
    cout << "Título da tarefa: ";
    getline(cin, titulo);

    Tarefa t(titulo);
    if (controller.criarTarefa(t))
        cout << "Tarefa criada com sucesso!\n";
    else
        cout << "Erro ao criar tarefa.\n";
}

// Listar tarefas
void TarefaView::listarTarefas()
{
    auto tarefas = controller.listarTarefas();
    if (tarefas.empty())
    {
        cout << "Nenhuma tarefa cadastrada.\n";
        return;
    }

    cout << "\n=== Lista de Tarefas ===\n";
    for (const auto &t : tarefas)
    {
        cout << t.getId() << " - " << t.getTitulo() << " [" << t.getStatus() << "]\n";
    }
}

// Editar tarefa
void TarefaView::editarTarefa()
{
    int id;
    cout << "Digite o ID da tarefa a editar: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string novoTitulo;
    cout << "Novo título: ";
    getline(cin, novoTitulo);

    Tarefa t(novoTitulo);
    t.setId(id);

    if (controller.atualizarTarefa(t))
        cout << "Tarefa atualizada!\n";
    else
        cout << "Erro ao atualizar tarefa.\n";
}

// Excluir tarefa
void TarefaView::excluirTarefa()
{
    int id;
    cout << "Digite o ID da tarefa a excluir: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (controller.excluirTarefa(id))
        cout << "Tarefa excluída!\n";
    else
        cout << "Erro ao excluir tarefa.\n";
}
