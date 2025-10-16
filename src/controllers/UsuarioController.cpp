#include "UsuarioController.hpp"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

// Realiza o cadastro de um novo usuário
bool UsuarioController::cadastrarUsuario(
    Database &db,
    const std::string &nome,
    const std::string &senha,
    const std::string &email)
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

// Realiza o login de um usuário
bool UsuarioController::loginUsuario(
    Database &db,
    const string &email,
    const string &senha)
{
    if (Usuario::login(db, email, senha))
    {
        cout << "Login realizado com sucesso!" << endl;
        return true;
    }
    else
    {
        cerr << "Email ou senha inválidos." << endl;
        return false;
    }
}
