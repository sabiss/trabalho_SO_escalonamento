#ifndef TIPOS_H
#define TIPOS_H

#include <string>

using ull = unsigned long long;

enum class ModoOperacao {
    LINEAR=1,
    THREAD,
    PROCESSO
};

enum class TipoParticao {
    BLOCO=1,
    CICLICA 
};

struct ResultadoWorker {
    ull qtd_acima_limiar = 0;
    ull recorde_numero = 0;
    ull recorde_saltos = 0;
    double tempo_execucao = 0.0;
};

#endif