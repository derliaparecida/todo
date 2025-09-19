#include "UsuarioView.hpp"
#include <iostream>

void UsuarioView::menu(Database &db, UsuarioController &controller)
{
    int opcao = 0;
    do
    {
        std::cout << "\n=== CADASTRO DE USUÁRIO ===\n";
        std::cout << "1. Cadastrar usuário\n";
        std::cout << "2. Login\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha 1, 2 ou 0: ";
        std::cin >> opcao;

        switch (opcao)
        {
        case 1:
            cadastrar(db, controller);
            break;
        case 2:
            login(db, controller);
            break;
        case 0:
            std::cout << "Saindo...\n";
            break;
        default:
            std::cout << "Opção inválida!\n";
            break;
        }
    } while (opcao != 0);
}
// para cadastrar
void UsuarioView::cadastrar(Database &db, UsuarioController &controller)
{
    std::string nome, senha, email;

    std::cout << "Digite o nome: ";
    std::cin >> nome;
    std::cout << "Digite a senha: ";
    std::cin >> senha;
    std::cout << "Digite o email: ";
    std::cin >> email;

    controller.cadastrarUsuario(db, nome, senha, email);
}
// para logar
void UsuarioView::login(Database &db, UsuarioController &controller)
{
    std::string email, senha;

    std::cout << "Digite o email: ";
    std::cin >> email;
    std::cout << "Digite a senha: ";
    std::cin >> senha;

    controller.loginUsuario(db, email, senha);
}
