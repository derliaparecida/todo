#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <sqlite3.h>
#include "../utils/Database.hpp"

class Usuario
{
private:
    std::string nome;
    std::string senha;
    std::string email;

public:
    // Construtor
    Usuario(const std::string &nome, const std::string &senha, const std::string &email);

    // Getters
    std::string getNome() const;
    std::string getEmail() const;

    // Métodos
    bool autenticar(const std::string &senha) const;
    bool salvar(Database &db);
    static bool login(Database &db, const std::string &email, const std::string &senha);
};

#endif // USUARIO_HPP
