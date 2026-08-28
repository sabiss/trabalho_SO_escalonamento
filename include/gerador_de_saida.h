#ifndef GERADOR_ARQUIVO_H
#define GERADOR_ARQUIVO_H

#include <utility>

using ull = unsigned long long;

void gerar_arquivo_saida(std::string arquivo_saida, const std::string& modo, const std::string& particao, const int& W, const ull& TAMANHO_INTERVALO, const double& tempo_total, const double& tempo_max_worker, const double& tempo_min_worker, const double& tempo_agregacao, const ull& QTD, const std::pair<ull,ull>& recorde);

#endif