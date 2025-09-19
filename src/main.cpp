#include <iostream>
#include "models/Usuario.hpp"
#include "controllers/UsuarioController.hpp"
#include "utils/Database.hpp"

int main()
{
    // Cria ou abre o banco
    Database db("todo.db");
    if (!db.open())
    {
        std::cerr << "Não foi possível abrir o banco." << std::endl;
        return 1;
    }

    // Cria a tabela se não existir
    std::string sql = "CREATE TABLE IF NOT EXISTS usuarios ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "nome TEXT NOT NULL, "
                      "senha TEXT NOT NULL, "
                      "email TEXT NOT NULL);";
    if (!db.execute(sql))
    {
        std::cerr << "Erro ao criar tabela." << std::endl;
        return 1;
    }

    // Instancia o controller de usuário
    UsuarioController usuarioController;

    // Cadastro de usuário
    usuarioController.cadastrarUsuario(db, "bb", "1234", "bb@email.com");

    // TODO: Login de usuário
    usuarioController.loginUsuario(db, "bb@email.com", "1234");

    db.close();
    return 0;
}
