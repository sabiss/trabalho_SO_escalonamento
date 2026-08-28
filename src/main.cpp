#include <iostream>
#include <string>
#include <utility>
#include "../include/calcula_sequencia.h"
#include "../include/gerador_de_saida.h"

using ull = unsigned long long;

int main(int argc, char* argv[]){
    if (argc != 8) {
        std::cerr << "Erro: Quantidade incorreta de argumentos.\n";
        std::cerr << "Uso correto: ./varredor <Inicio Intervalo> <Fim Intervalo> <LIMIAR> <Qtd. Trabalhadores> <modo> <particao> <arquivo_saida>\n";
        return EXIT_FAILURE;
    }

    const ull INICIO_INTERVALO = std::stoull(argv[1]);
    const ull FIM_INTERVALO = std::stoull(argv[2]);
    const ull TAMANHO_INTERVALO = FIM_INTERVALO - INICIO_INTERVALO;
    const ull LIMIAR = std::stoull(argv[3]);
    const int W = std::stoi(argv[4]);
    double tempo_total = 0.0;

    const std::string modo = argv[5];
    const std::string particao = argv[6];
    const std::string arquivo_saida = argv[7];

    std::pair<ull, ull>recorde = {0,0};
    ull QTD=0;

    calcula_sequencia(INICIO_INTERVALO, FIM_INTERVALO, recorde, QTD, LIMIAR, tempo_total);
    gerar_arquivo_saida(arquivo_saida, modo, particao, W, TAMANHO_INTERVALO, tempo_total, tempo_total, tempo_total, 0.0, QTD, recorde);
    
    return EXIT_SUCCESS;
}