#include "Tarefa.hpp"

Tarefa::Tarefa() : id(0), titulo(""), grupo(""), status("pendente"), pomodoros(0), prazo(""), notas("") {}
Tarefa::Tarefa(const std::string &titulo) : id(0), titulo(titulo), grupo(""), status("pendente"), pomodoros(0), prazo(""), notas("") {}

int Tarefa::getId() const { return id; }
void Tarefa::setId(int id) { this->id = id; }

std::string Tarefa::getTitulo() const { return titulo; }
void Tarefa::setTitulo(const std::string &titulo) { this->titulo = titulo; }

std::string Tarefa::getGrupo() const { return grupo; }
void Tarefa::setGrupo(const std::string &grupo) { this->grupo = grupo; }

std::string Tarefa::getStatus() const { return status; }
void Tarefa::setStatus(const std::string &status) { this->status = status; }

int Tarefa::getPomodoros() const { return pomodoros; }
void Tarefa::setPomodoros(int pomodoros) { this->pomodoros = pomodoros; }

std::string Tarefa::getPrazo() const { return prazo; }
void Tarefa::setPrazo(const std::string &prazo) { this->prazo = prazo; }

std::string Tarefa::getNotas() const { return notas; }
void Tarefa::setNotas(const std::string &notas) { this->notas = notas; }
