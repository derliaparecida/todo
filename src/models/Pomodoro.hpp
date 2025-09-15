#ifndef POMODORO_HPP
#define POMODORO_HPP

class Pomodoro {
private:
    int duracao;
    int pausaCurta;
    int pausaLonga;
public:
    Pomodoro(int duracao = 25, int pausaCurta = 5, int pausaLonga = 15);
    int getDuracao() const;
    int getPausaCurta() const;
    int getPausaLonga() const;
    void configurar(int duracao, int pausaCurta, int pausaLonga);
};

#endif // POMODORO_HPP
