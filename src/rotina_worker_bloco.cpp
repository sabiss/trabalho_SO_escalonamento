#include "../include/rotina_worker_bloco.h"
#include "../include/tipos.h"
#include "../include/calcula_collatz.h"
#include "../include/relogio.h"

void* rotina_worker_bloco(void* dados_threads) {
    ArgumentosThreadBloco* dados = (ArgumentosThreadBloco*) dados_threads;

    Relogio relogio;
    relogio.iniciar_marcacao();

    for(ull numero_do_intervalo = dados->inicio_intervalo; numero_do_intervalo <= dados->fim_intervalo; numero_do_intervalo++){
        calcula_collatz(
            numero_do_intervalo, 
            dados->limiar, 
            dados->relatorio->recorde_numero, 
            dados->relatorio->recorde_saltos, 
            dados->relatorio->qtd_acima_limiar
        );
    }

    relogio.parar_marcacao();
    dados->relatorio->tempo_execucao = relogio.calcular_tempo_total();
    return nullptr; 
}