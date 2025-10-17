// models/TarefaBase.hpp
#ifndef TAREFABASE_HPP
#define TAREFABASE_HPP

#include <string>
using namespace std;

// TODO: criar tarefa base para herança

class TarefaBase
{
protected:
    int id;
    string titulo;
    string status;
    string notas;

public:
    TarefaBase(const string &titulo) : titulo(titulo), status("pendente") {}
    virtual ~TarefaBase() {}
    virtual std::string tipo() const { return "base"; }

    // getters
    int getId() const { return id; }
    string getTitulo() const { return titulo; }
    string getStatus() const { return status; }
    string getNotas() const { return notas; }

    // setters
    void setStatus(const string &s) { status = s; }
    void setNotas(const string &n) { notas = n; }

    // método virtual puro
    virtual void exibirDetalhes() const = 0;
};

#endif
