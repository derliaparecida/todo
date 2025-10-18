#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <string>
#include "Pomodoro.hpp"

class Tarefa
{
private:
    int id;
    std::string titulo;
    std::string grupo;
    std::string status;
    int pomodoros;
    std::string prazo;
    std::string notas;
    Pomodoro pomodoroConfig; // composição: cada tarefa contém uma configuração de Pomodoro

public:
    // Construtores
    Tarefa();
    Tarefa(const std::string &titulo);

    // Getters e Setters
    int getId() const;
    void setId(int id);

    std::string getTitulo() const;
    void setTitulo(const std::string &titulo);

    std::string getGrupo() const;
    void setGrupo(const std::string &grupo);

    std::string getStatus() const;
    void setStatus(const std::string &status);

    int getPomodoros() const;
    void setPomodoros(int pomodoros);

    std::string getPrazo() const;
    void setPrazo(const std::string &prazo);

    std::string getNotas() const;
    void setNotas(const std::string &notas);

    // Composição: acesso à configuração de Pomodoro
    Pomodoro getPomodoroConfig() const;
    void setPomodoroConfig(const Pomodoro &p);
};

#endif // TAREFA_HPP
