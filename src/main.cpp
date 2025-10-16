#include <iostream>
#include "models/Usuario.hpp"
#include "controllers/UsuarioController.hpp"
#include "utils/Database.hpp"
#include "views/UsuarioView.hpp"

#include <string>
using std::cerr;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // Cria ou abre o banco
    Database db("todo.db");
    if (!db.open())
    {
        cerr << "Não foi possível abrir o banco." << endl;
        return 1;
    }

    // Cria a tabela se não existir
    string sql = "CREATE TABLE IF NOT EXISTS usuarios ("
                 "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "nome TEXT NOT NULL, "
                 "senha TEXT NOT NULL, "
                 "email TEXT NOT NULL);";
    if (!db.execute(sql))
    {
        cerr << "Erro ao criar tabela." << endl;
        return 1;
    }

    // Instancia o controller de usuário
    UsuarioController usuarioController;

    // Cadstro usando view
    UsuarioView::menu(db, usuarioController);

    db.close();
    return 0;
}
