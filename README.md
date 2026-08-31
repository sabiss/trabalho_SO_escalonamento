# Varredor

**Descrição**
Esse é o meu trabalho que contempla o assunto de processos e threads da disciplicna de Sistemas Operacionais do curso de Tecnologia da Informação - UFRN/IMD

**Como Compilar**
No terminal, dentro da pasta do projeto, utilize os seguintes comandos:
* Limpar compilações e binários anteriores: `make clean`
* Gerar o executável final: `make`

**Como Executar**
O programa exige a passagem exata de 7 parâmetros via linha de comando, respeitando a seguinte ordem:
`./varredor <INICIO_INTERVALO> <FIM_INTERVALO> <LIMIAR> <W> <modo> <particao> <arquivo_saida>`

* **INICIO_INTERVALO:** O limite inferior do intervalo numérico.
* **FIM_INTERVALO:** O limite superior do intervalo numérico.
* **LIMIAR:** Quantidade mínima de passos para que um número ative a contagem da variável QTD.
* **W:** Número de unidades de execução simultâneas (use 1 para o modo sequencial).
* **modo:** A arquitetura de execução desejada (`linear`, `thread` ou `processo`).
* **particao:** A estratégia de divisão dos dados (`1` para linear, `bloco` ou `ciclico` para concorrência).
* **arquivo_saida:** O nome do arquivo CSV onde os dados gerados serão anexados.

**Exemplo de Execução (Modo Linear)**
Para testar o programa em via única (sem divisão de carga), execute:
`./varredor 100039468 8100078936 268 1 linear 1 resultado.csv`
