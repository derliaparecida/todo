#include "UsuarioController.hpp"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

bool UsuarioController::cadastrarUsuario(Database &db, const std::string &nome, const std::string &senha, const std::string &email)
{
    Usuario usuario(nome, senha, email);
    if (usuario.salvar(db))
    {
        cout << "Usuário cadastrado com sucesso!" << endl;
        return true;
    }
    else
    {
        cerr << "Erro ao cadastrar usuário." << endl;
        return false;
    }
}

bool UsuarioController::loginUsuario(Database &db, const std::string &email, const std::string &senha)
{
    if (Usuario::login(db, email, senha))
    {
        cout << "Login realizado com sucesso!" << endl;

        // Cria objeto do usuário logado , refazer usando BD
        usuarioLogado = Usuario("Usuário", senha, email);

        return true;
    }
    else
    {
        cerr << "Email ou senha inválidos." << endl;
        return false;
    }
}
