#include <fstream>
#include <iomanip>
#include <iostream>

using ull = unsigned long long;

void gerar_arquivo_saida(std::string arquivo_saida, const std::string& modo, const std::string& particao, const int& W, const ull& TAMANHO_INTERVALO, const double& tempo_total, const double& tempo_max_worker, const double& tempo_min_worker, const double& tempo_agregacao, const ull& QTD, const ull& recorde_numero, const ull& recorde_saltos) {
    
    std::ofstream arquivo(arquivo_saida, std::ios::app);

    if (arquivo.is_open()) {
        //grava as variáveis
        arquivo << modo << ","
                << particao << ","
                << W << ","
                << TAMANHO_INTERVALO << ",";

        //duas casas decimais para os dados
        arquivo << std::scientific << std::setprecision(2);
        
        arquivo << tempo_total << ","
                << tempo_max_worker << ","
                << tempo_min_worker << ","
                << tempo_agregacao << ",";

        arquivo.unsetf(std::ios_base::floatfield);
        
        //Grava os resultados matemáticos
        arquivo << QTD << ","
                << recorde_numero << ","
                << recorde_saltos << "\n";

        arquivo.close();
    } else {
        std::cerr << "Erro ao tentar abrir ou criar o arquivo: " << arquivo_saida << "\n";
    }
}