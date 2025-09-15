#ifndef GRUPO_HPP
#define GRUPO_HPP
#include <string>
#include <vector>

class Grupo {
private:
    std::string nome;
    std::vector<std::string> tarefas;
public:
    Grupo(const std::string& nome);
    void adicionarTarefa(const std::string& tarefa);
    void removerTarefa(const std::string& tarefa);
    std::string getNome() const;
    // ... outros métodos ...
};

#endif // GRUPO_HPP
