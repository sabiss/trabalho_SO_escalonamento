#include <utility>

using ull = unsigned long long;

std::pair<ull, ull> calcula_intervalo(const ull& inicio_intervalo_global, const ull& fim_intervalo_global, const ull tamanho_intervalo, const int& W, const int& id_worker) {
    ull tamanho_fatia = tamanho_intervalo / W;
    ull inicio_intervalo_worker = inicio_intervalo_global + (id_worker * tamanho_fatia);
    //se caso tiver resto, o último worker é quem vai pegar ele pra dividir
    ull fim_intervalo_worker = (id_worker == W - 1) ? fim_intervalo_global : inicio_intervalo_worker + tamanho_fatia - 1;

    return std::make_pair(inicio_intervalo_worker, fim_intervalo_worker);
}