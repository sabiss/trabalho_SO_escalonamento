#ifndef RELOGIO_H
#define RELOGIO_H
#include <chrono>

class Relogio {
private:
    std::chrono::high_resolution_clock::time_point tempo_inicio_sequencia;
    std::chrono::high_resolution_clock::time_point tempo_fim_sequencia;

public:
    void iniciar_marcacao_sequencia();
    void parar_marcacao_sequencia();
    double calcular_tempo_total();
};

#endif