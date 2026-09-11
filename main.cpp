#include <iostream>
#include <vector>
#include <pthread.h>

#include "./include/calcula_collatz.h"
#include "./include/gerador_de_saida.h"
#include "./include/calcula_intervalo_bloco.h"
#include "./include/tipos.h"
#include "./include/rotina_worker_bloco.h"
#include "./include/relogio.h"

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
    double tempo_total_global = 0.0;

    const ModoOperacao modo = static_cast<ModoOperacao>(std::stoi(argv[5]));
    const TipoParticao particao = static_cast<TipoParticao>(std::stoi(argv[6]));
    const std::string arquivo_saida = argv[7];

    ull recorde_numero_global = 0;//numero que bateu o recorde
    ull recorde_saltos_global = 0;//quantidade de passos do número recorde
    ull QTD_global=0;//quantidade de números acima do limiar

    if(modo != ModoOperacao::THREAD && modo != ModoOperacao::PROCESSO){
        std::cerr << "Erro: Modo inválido. Use 1 para THREAD ou 2 para PROCESSO.\n";
        return EXIT_FAILURE;
    }
    if(particao != TipoParticao::BLOCO && particao != TipoParticao::CICLICA){
        std::cerr << "Erro: Partição inválida. Use BLOCO ou CICLICA.\n";
        return EXIT_FAILURE;
    }

    std::vector<ResultadoWorker> relatorios_globais(W);
    Relogio relogio_global;

    switch (modo) {
        case ModoOperacao::THREAD:{
            std::vector<pthread_t> threads(W);
            std::vector<ArgumentosThreadBloco> dados_de_cada_threads(W);

            if(particao == TipoParticao::BLOCO){
                relogio_global.iniciar_marcacao();

                for (int id_thread = 0; id_thread < W; ++id_thread){
                    const std::pair<ull, ull> intervalo = calcula_intervalo_bloco(INICIO_INTERVALO, FIM_INTERVALO, W, id_thread);
                    dados_de_cada_threads[id_thread] = {id_thread, intervalo.first, intervalo.second, LIMIAR, &relatorios_globais[id_thread]};
                    pthread_create(&threads[id_thread], nullptr, rotina_worker_bloco, &dados_de_cada_threads[id_thread]);
                }
                //fica esperando cada thread terminar seu trabalho
                for (int id = 0; id < W; ++id){
                    pthread_join(threads[id], nullptr); 
                }

                relogio_global.parar_marcacao();
                tempo_total_global = relogio_global.calcular_tempo_total();
            } 
            if(particao == TipoParticao::CICLICA){
                std::cout << "Modo: THREAD, Partição: CICLICA\n";
            }
            break;
        }
        case ModoOperacao::PROCESSO:
            std::cout << "Modo: PROCESSO\n";
            break;
    }
    
    return EXIT_SUCCESS;
}