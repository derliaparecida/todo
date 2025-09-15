#ifndef TAREFA_HPP
#define TAREFA_HPP
#include <string>
#include <vector>

class Tarefa {
private:
    std::string titulo;
    std::string grupo;
    std::string status;
    int pomodoros;
    std::string prazo;
    std::string notas;
public:
    Tarefa(const std::string& titulo);
    void setGrupo(const std::string& grupo);
    void setStatus(const std::string& status);
    void setPomodoros(int quantidade);
    void setPrazo(const std::string& prazo);
    void setNotas(const std::string& notas);
    std::string getTitulo() const;
    // ... outros ...
};

#endif // TAREFA_HPP
