#ifndef USUARIOCONTROLLER_HPP
#define USUARIOCONTROLLER_HPP

#include "../models/Usuario.hpp"
#include "../utils/Database.hpp"
#include <string>
#include <optional>

using std::string;

class UsuarioController
{
private:
    std::optional<Usuario> usuarioLogado;

public:
    // Cadastro
    bool cadastrarUsuario(Database &db, const string &nome, const string &senha, const string &email);

    // Login
    bool loginUsuario(Database &db, const string &email, const string &senha);

    // Retorna usuário logado
    bool isUsuarioLogado() const { return usuarioLogado.has_value(); }

    // Retorna o usuário logado??
    std::optional<Usuario> getUsuarioLogado() const { return usuarioLogado; }

    // Logout
    void logout() { usuarioLogado.reset(); }
};

#endif // USUARIOCONTROLLER_HPP
