#include <string>
#include "Usuario.hpp"
#include <iostream>

using std::string;

// Construtor
Usuario::Usuario(const string &nome,
                 const string &senha,
                 const string &email)
    : nome(nome), senha(senha), email(email) {}

// Getters
string Usuario::getNome() const { return nome; }
string Usuario::getEmail() const { return email; }

bool Usuario::autenticar(const string &senhaDigitada) const
{
    return senha == senhaDigitada;
}

// Cadastra usuário no banco
bool Usuario::salvar(Database &db)
{
    sqlite3 *conn = db.getDB();
    if (!conn)
    {
        std::cerr << "Erro ao conectar com o banco de dados!" << std::endl;
        return false;
    }

    const char *sql = "INSERT INTO usuarios (nome, senha, email) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(conn, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        std::cerr << "Erro: " << sqlite3_errmsg(conn) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, nome.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, senha.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) != SQLITE_DONE)
    {
        std::cerr << "Erro ao inserir usuário: " << sqlite3_errmsg(conn) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

// Login
bool Usuario::login(Database &db, const string &email, const string &senha)
{
    string sql = "SELECT senha FROM usuarios WHERE email = '" + email + "';";
    bool autenticado = false;

    auto callback = [](void *data, int argc, char **argv, char **colName) -> int
    {
        string senhaBanco = argv[0] ? argv[0] : "";
        string *senhaInformada = static_cast<string *>(data);
        if (*senhaInformada == senhaBanco)
        {
            *senhaInformada = "ok";
        }
        return 0;
    };

    string senhaTemp = senha;
    db.executeWithCallback(sql, callback, &senhaTemp);
    autenticado = (senhaTemp == "ok");
    return autenticado;
}
