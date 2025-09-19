#include "UsuarioController.hpp"
#include <iostream>

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
        std::cout << "Usuário cadastrado com sucesso!" << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Erro ao cadastrar usuário." << std::endl;
        return false;
    }
}

// Realiza o login de um usuário
bool UsuarioController::loginUsuario(
    Database &db,
    const std::string &email,
    const std::string &senha)
{
    if (Usuario::login(db, email, senha))
    {
        std::cout << "Login realizado com sucesso!" << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Email ou senha inválidos." << std::endl;
        return false;
    }
}
