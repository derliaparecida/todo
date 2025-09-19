#pragma once
#include "../controllers/UsuarioController.hpp"
#include "../utils/Database.hpp"

class UsuarioView
{
public:
    static void menu(Database &db, UsuarioController &controller);
    static void cadastrar(Database &db, UsuarioController &controller);
    static void login(Database &db, UsuarioController &controller);
};
