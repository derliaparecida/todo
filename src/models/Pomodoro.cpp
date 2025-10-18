#include "Pomodoro.hpp"

Pomodoro::Pomodoro(int duracao, int pausaCurta, int pausaLonga)
    : duracao(duracao), pausaCurta(pausaCurta), pausaLonga(pausaLonga) {}

int Pomodoro::getDuracao() const { return duracao; }
int Pomodoro::getPausaCurta() const { return pausaCurta; }
int Pomodoro::getPausaLonga() const { return pausaLonga; }

void Pomodoro::configurar(int duracao, int pausaCurta, int pausaLonga)
{
    this->duracao = duracao;
    this->pausaCurta = pausaCurta;
    this->pausaLonga = pausaLonga;
}
