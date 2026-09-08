#ifndef CALCULA_INTERVALO_H
#define CALCULA_INTERVALO_H

#include <utility>

using ull = unsigned long long;

std::pair<ull, ull> calcula_intervalo(const ull& inicio_intervalo_global, const ull& fim_intervalo_global, const ull tamanho_intervalo, const int& W, const int& id_worker);

#endif