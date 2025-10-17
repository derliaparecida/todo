#include "TarefaController.hpp"

TarefaController::TarefaController(TarefaDAO &dao) : dao(dao) {}

bool TarefaController::criarTarefa(const Tarefa &t) { return dao.salvar(t); }
bool TarefaController::atualizarTarefa(const Tarefa &t) { return dao.atualizar(t); }
bool TarefaController::excluirTarefa(int id) { return dao.excluir(id); }
std::vector<Tarefa> TarefaController::listarTarefas() { return dao.listar(); }
