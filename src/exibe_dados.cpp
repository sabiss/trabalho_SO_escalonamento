#include <utility>
#include <iostream>
#include "exibe_dados.h"

using ull = unsigned long long;

void exibe_dados(const std::pair<ull, ull>& recorde, const ull& QTD){
    std::cout << "===============================================================\n";
    std::cout << "A quantidade de números no qual os passos ultrapassaram o limiar foi de: " << QTD << "\n";
    std::cout << "Os recordes foram do número " << recorde.first << " com [" << recorde.second << "] passos\n";
}