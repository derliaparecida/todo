#include <iostream>
#include "models/Usuario.hpp"
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
                      "id TEXT PRIMARY KEY, "
                      "nome TEXT NOT NULL, "
                      "senha TEXT NOT NULL, "
                      "email TEXT NOT NULL);";
    if (!db.execute(sql))
    {
        std::cerr << "Erro ao criar tabela." << std::endl;
        return 1;
    }

    // Cria um usuário
    Usuario u("1", "ana", "1234", "ana@email.com");

    // Salva o usuário
    if (u.salvar(db))
    {
        std::cout << "Usuário salvo com sucesso!" << std::endl;
    }
    else
    {
        std::cerr << "Falha ao salvar usuário." << std::endl;
    }

    db.close();
    return 0;
}
