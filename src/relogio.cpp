#include "../include/relogio.h"

void Relogio::iniciar_marcacao_sequencia() {
    tempo_inicio_sequencia = std::chrono::high_resolution_clock::now();
}

void Relogio::parar_marcacao_sequencia() {
    tempo_fim_sequencia = std::chrono::high_resolution_clock::now();
}

double Relogio::calcular_tempo_total() {
    std::chrono::duration<double> duracao = tempo_fim_sequencia - tempo_inicio_sequencia;
    return duracao.count();
}