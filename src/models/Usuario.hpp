#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <sqlite3.h>
#include "../utils/Database.hpp"

class Usuario
{
private:
    std::string id;
    std::string nome;
    std::string senha;
    std::string email;

public:
    // Construtor
    Usuario(const std::string &id, const std::string &nome, const std::string &senha, const std::string &email);

    // Getters
    std::string getNome() const;
    std::string getEmail() const;

    // Autenticação
    bool autenticar(const std::string &senha) const;

    // Salvar usuário no banco de dados usando prepared statements
    bool salvar(Database &db);
};

#endif // USUARIO_HPP
