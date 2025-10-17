#include <iostream>
#include "models/Usuario.hpp"
#include "controllers/UsuarioController.hpp"
#include "utils/Database.hpp"
#include "views/UsuarioView.hpp"
#include "models/Tarefa.hpp"
#include "controllers/TarefaController.hpp"
#include "views/TarefaView.hpp"
#include "dao/TarefaDAO.hpp"

#include <string>
using std::cerr;
using std::cout;
using std::endl;
using std::string;

// --- função auxiliar para testar criação de tarefa ---
void testarCriarTarefa(Database &db)
{
    TarefaDAO dao(db);
    TarefaController controller(dao);
    TarefaView view(controller);

    view.criarTarefaInterativa();
}

int main()
{
    // Cria ou abre o banco
    Database db("todo.db");
    if (!db.open())
    {
        cerr << "Não foi possível abrir o banco." << endl;
        return 1;
    }

    // Cria a tabela de usuários, se não existir
    string sqlUsuarios = "CREATE TABLE IF NOT EXISTS usuarios ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "nome TEXT NOT NULL, "
                         "senha TEXT NOT NULL, "
                         "email TEXT NOT NULL);";
    if (!db.execute(sqlUsuarios))
    {
        cerr << "Erro ao criar tabela de usuários." << endl;
        return 1;
    }

    // Cria a tabela de tarefas
    string sqlTarefas = "CREATE TABLE IF NOT EXISTS tarefas ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "titulo TEXT NOT NULL, "
                        "grupo TEXT, "
                        "status TEXT, "
                        "pomodoros INTEGER, "
                        "prazo TEXT, "
                        "notas TEXT);";
    if (!db.execute(sqlTarefas))
    {
        cerr << "Erro ao criar tabela de tarefas." << endl;
        return 1;
    }

    UsuarioController usuarioController;
    UsuarioView::menu(db, usuarioController);

    if (usuarioController.isUsuarioLogado())
    {
        // Cria DAO passando o Database já aberto
        TarefaDAO tarefaDAO(db);

        // Cria o controller passando o DAO (construtor exige TarefaDAO&)
        TarefaController tarefaController(tarefaDAO);

        // Cria a view passando o controller (construtor exige TarefaController&)
        TarefaView tarefaView(tarefaController);

        // Chama o menu da view (sem parâmetros, conforme sua implementação)
        tarefaView.menu();
    }
    else
    {
        cout << "Você precisa estar logado para acessar o menu de tarefas.\n";
    }

    db.close();
    return 0;
}
