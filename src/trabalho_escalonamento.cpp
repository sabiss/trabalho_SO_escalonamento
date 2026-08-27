#include <iostream>
#include "utils/calcula_sequencia.h"
#include "utils/exibe_dados.h"

using ull = unsigned long long;

int main(){
    const ull ULTIMOS_NUM_MATRICULA = 39468; 
    const ull INICIO_INTERVALO = 100000000 +  ULTIMOS_NUM_MATRICULA;
    const ull FIM_INTERVALO  = INICIO_INTERVALO + 8000000000 + ULTIMOS_NUM_MATRICULA;
    const ull LIMIAR = 200 + (ULTIMOS_NUM_MATRICULA%10);

    std::pair<ull, ull>recorde = {0,0};
    ull QTD=0;

    calcula_sequencia(INICIO_INTERVALO, FIM_INTERVALO, recorde, QTD, LIMIAR);
    exibir_dados(recorde, QTD);
}