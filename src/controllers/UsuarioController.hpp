#ifndef USUARIOCONTROLLER_HPP
#define USUARIOCONTROLLER_HPP
#include "../models/Usuario.hpp"
#include "../utils/Database.hpp"
#include <string>

using std::string;

class UsuarioController
{
public:
    // Cadastro de usuário
    bool cadastrarUsuario(
        Database &db,
        const string &nome,
        const string &senha,
        const string &email);

    // Login de usuário
    bool loginUsuario(
        Database &db,
        const string &email,
        const string &senha);
};

#endif // USUARIOCONTROLLER_HPP
