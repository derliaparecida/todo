#ifndef ITAREFADAO_HPP
#define ITAREFADAO_HPP

#include <vector>
#include "../models/Tarefa.hpp"

// criar a interface ITarefaDAO para utilizar abstração

class ITarefaDAO
{
public:
    virtual bool salvar(const Tarefa &tarefa) = 0;
    virtual bool atualizar(const Tarefa &tarefa) = 0;
    virtual bool excluir(int id) = 0;
    virtual std::vector<Tarefa> listar() = 0;
    virtual ~ITarefaDAO() = default;
};

#endif // ITAREFADAO_HPP
