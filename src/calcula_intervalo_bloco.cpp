#include <utility>
#include "../include/calcula_intervalo_bloco.h"

using ull = unsigned long long;

std::pair<ull, ull> calcula_intervalo_bloco(
    const ull& inicio_intervalo_global, 
    const ull& fim_intervalo_global, 
    const int& W, 
    const int& id_worker
) {
    const ull tamanho_intervalo_global = fim_intervalo_global - inicio_intervalo_global + 1;
    
    ull tamanho_fatia = tamanho_intervalo_global / W;
    ull inicio_intervalo_worker = inicio_intervalo_global + (id_worker * tamanho_fatia);
    //se caso tiver resto, o último worker é quem vai pegar ele pra dividir
    ull fim_intervalo_worker = (id_worker == W - 1) ? fim_intervalo_global : inicio_intervalo_worker + tamanho_fatia - 1;

    return std::make_pair(inicio_intervalo_worker, fim_intervalo_worker);
}