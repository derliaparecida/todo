#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <string>

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
};

#endif // TAREFA_HPP
