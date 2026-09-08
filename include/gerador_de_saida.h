#ifndef GERADOR_DE_SAIDA_H
#define GERADOR_DE_SAIDA_H

#include <string>

using ull = unsigned long long;

void gerar_arquivo_saida(std::string arquivo_saida, const int& modo, const std::string& particao, const int& W, const ull& TAMANHO_INTERVALO, const double& tempo_total, const double& tempo_max_worker, const double& tempo_min_worker, const double& tempo_agregacao, const ull& QTD, const ull& recorde_numero, const ull& recorde_saltos);

#endif