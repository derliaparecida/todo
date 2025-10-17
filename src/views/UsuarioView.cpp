#include "UsuarioView.hpp"
#include <iostream>
#include <string>
#include "../dao/TarefaDAO.hpp"
#include "../controllers/TarefaController.hpp"
#include "../views/TarefaView.hpp"

using std::cin;
using std::cout;
using std::string;

void UsuarioView::menu(Database &db, UsuarioController &controller)
{
    int opcao = 0;
    do
    {
        cout << "\n=== CADASTRO DE USUÁRIO ===\n";
        cout << "1. Cadastrar usuário\n";
        cout << "2. Login\n";
        cout << "0. Sair\n";
        cout << "Escolha 1, 2 ou 0: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrar(db, controller);
            break;
        case 2:
        {
            bool logado = login(db, controller);
            if (logado)
            {
                // Mostrar menu de tarefas apenas para usuário logado
                TarefaDAO tarefaDao(db);
                TarefaController tarefaController(tarefaDao);
                TarefaView tarefaView(tarefaController);
                tarefaView.menu(); // chama menu de tarefas
            }
            break;
        }
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida!\n";
            break;
        }
    } while (opcao != 0);
}
// para cadastrar
void UsuarioView::cadastrar(Database &db, UsuarioController &controller)
{
    string nome, senha, email;

    cout << "Digite o nome: ";
    cin >> nome;
    cout << "Digite a senha: ";
    cin >> senha;
    cout << "Digite o email: ";
    cin >> email;

    controller.cadastrarUsuario(db, nome, senha, email);
}
// para logar
bool UsuarioView::login(Database &db, UsuarioController &controller)
{
    string email, senha;

    cout << "Digite o email: ";
    cin >> email;
    cout << "Digite a senha: ";
    cin >> senha;

    // Retorna o resultado do controller (true = login ok)
    return controller.loginUsuario(db, email, senha);
}
