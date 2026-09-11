#ifndef CALCULA_COLLATZ_H
#define CALCULA_COLLATZ_H

using ull = unsigned long long;
//recebe um número e calcula a quantidade de passos até chegar em 1, verificar se o número ultrapassou o limiar e se bateu o recorde de passos
void calcula_collatz(
    ull& numero_para_calcular, 
    const ull& limiar, 
    ull& recorde_numero, 
    ull& recorde_saltos, 
    ull& QTD 
);
#endif