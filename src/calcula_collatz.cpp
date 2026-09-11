#include "../include/calcula_collatz.h"
#include "../include/relogio.h"
#include "../include/tipos.h"

void calcula_collatz(
    ull& numero_para_calcular, 
    const ull& limiar, 
    ull& recorde_numero, 
    ull& recorde_saltos, 
    ull& QTD
) {
    const ull numero_inicial = numero_para_calcular;
    ull passos = 0;

    while(numero_para_calcular != 1){
        bool numero_para_calcular_eh_par = numero_para_calcular%2==0;
        passos++;

        if(numero_para_calcular_eh_par){
            numero_para_calcular = numero_para_calcular/2;
        }else{
            numero_para_calcular = 3*numero_para_calcular + 1;
        }
    }

    bool recorde_passos_ultrapassado = recorde_saltos < passos;

    if(recorde_passos_ultrapassado){
        recorde_saltos = passos;
        recorde_numero = numero_inicial;
    }

    bool precisou_mais_passos_que_o_limiar = passos > limiar;

    if(precisou_mais_passos_que_o_limiar)QTD++;
}