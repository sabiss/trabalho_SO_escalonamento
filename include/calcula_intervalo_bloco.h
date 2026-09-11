#ifndef CALCULA_INTERVALO_BLOCO_H
#define CALCULA_INTERVALO_BLOCO_H

#include <utility>

using ull = unsigned long long;

std::pair<ull, ull> calcula_intervalo_bloco(
    const ull& inicio_intervalo_global, 
    const ull& fim_intervalo_global, 
    const int& W, 
    const int& id_worker);

#endif