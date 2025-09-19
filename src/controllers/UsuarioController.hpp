#ifndef USUARIOCONTROLLER_HPP
#define USUARIOCONTROLLER_HPP
#include "../models/Usuario.hpp"
#include "../utils/Database.hpp"
#include <string>

class UsuarioController
{
public:
    // Cadastro de usuário
    bool cadastrarUsuario(
        Database &db,
        const std::string &nome,
        const std::string &senha,
        const std::string &email);

    // Login de usuário
    bool loginUsuario(
        Database &db,
        const std::string &email,
        const std::string &senha);
};

#endif // USUARIOCONTROLLER_HPP
