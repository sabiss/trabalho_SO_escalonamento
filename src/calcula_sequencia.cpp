#include <utility>
#include <chrono>
#include "calcula_sequencia.h"
#include "relogio.h"

using ull = unsigned long long;

void calcula_sequencia(const ull& inicio_intervalo, const ull& fim_intervalo, std::pair<ull, ull>& recorde, ull& QTD, const ull& limiar, double& tempo_total){
    Relogio relogio;
    relogio.iniciar_marcacao_sequencia();
    for(ull numero_do_intervalo = inicio_intervalo; numero_do_intervalo <= fim_intervalo; numero_do_intervalo++){
        ull numero = numero_do_intervalo;
        ull passos = 0;

        while(numero != 1){
            bool numero_eh_par = numero%2==0;
            passos++;

            if(numero_eh_par){
                numero = numero/2;
            }else{
                numero = 3*numero + 1;
            }
        }

        bool recorde_passos_ultrapassado = recorde.first < passos;
        if(recorde_passos_ultrapassado){
          recorde.first = passos;
          recorde.second = numero;  
        }

        bool precisou_mais_passos_que_o_limiar = passos > limiar;
        if(precisou_mais_passos_que_o_limiar)QTD++;
    }
    relogio.parar_marcacao_sequencia();
    tempo_total = relogio.calcular_tempo_total();

}