#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <sqlite3.h>
#include "../utils/Database.hpp"

using std::string;

class Usuario
{
private:
    string nome;
    string senha;
    string email;

public:
    // Construtor
    Usuario(const string &nome, const string &senha, const string &email);

    // Getters
    string getNome() const;
    string getEmail() const;

    // Métodos
    bool autenticar(const string &senha) const;
    bool salvar(Database &db);
    static bool login(Database &db, const string &email, const string &senha);
};

#endif // USUARIO_HPP
