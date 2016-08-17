####Este trabalho tem por objetivo exercitar primitivas básicas da Linguagem C e iniciar a discussão sobre problemas complexos e a sua solução.


Você foi contratado pela Acima e Avante Elevadores para projetar a próxima geração de elevadores da empresa. De forma a reduzir os custos de desenvolvimento, você optou por implementar
um simulador orientado a eventos do controlador de elevador. O ambiente de funcionamento de um elevador consiste do número de andares do prédio e da sua capacidade. Durante a operação do
elevador, há basicamente dois eventos a serem considerados: 

- o elevador é chamado em algum andar.
- o passageiro pressiona o andar para o qual ele deseja ir.

Sempre que o elevador atende um chamado, a entrada do passageiro é sujeita a haver espaço no elevador. O elevador pode postergar o atendimento do chamado se estiver cheio. Para fins de
simplificação num primeiro momento, você não considera os tempos de aceleração e desaceleração do elevador. Mais ainda, você considera que todos os tempos são expressos em uma unidade de
tempo Jepslon. Assim, para percorrer a distância de um andar a outro, é necessário 1 Jepslon.
Para 1 ou mais passageiros entrarem ou sairem do elevador também é necessário 1 Jepslon.
Em termos da estratégia de escalonamento, você pode usar algo tão simples quanto FIFO, embora o elevador vá ficar se movimentando desnecessariamente. Há várias estratégias que podem
ser usadas e são encontradas na literatura. Pelo menos DUAS ESTRATÉGIAS devem ser implementadas.
Para cada passageiro transportado, você deve imprimir o tempo de espera e o tempo dentro do elevador até o seu destino, ambos em Jepslons. Você pode também imprimir a taxa de ocupação do
elevador, assim como a distância percorrida e o número de vezes que a porta foi aberta e fechada.
Assim, elabore um programa com as seguintes características:

1. Projete o seu simulador, incluindo as estruturas de dados a serem utilizadas, assim como a
estratégia a ser adotada pelo elevador.

2. O programa deve ser implementado em 3 módulos. O primeiro módulo deve tratar dos
procedimentos de entrada e saída. O segundo módulo contém a lógica do simulador. O terceiro
módulo contem o programa principal. Deve ainda ser definido um arquivo de protótipos e
definiçõescontendo as estruturas de dados e protótipos das funções dos vários módulos. A
compilação do programa deve utilizar o utilitário Make.

3. Todas as estruturas de dados devem ser alocadas dinamicamente, assim como devem ser
desalocadas após o processamento. As rotinas de teste de configuração também devem ser
implementadas usando estruturas de alocação dinâmica.

4. O programa deve receber dois parâmetros pela linha de comando, utilizando a primitiva
getopt:
  1. arquivo descrevendo o ambiente do elevador
  2. seqüência de eventos a serem tratados.
  
  Por simplicidade, você pode considerar que cada passageiro é um evento, indicando o andar no   qual ele chamou o elevador e o andar de destino. Faz parte do trabalho gerar cargas realistas,
  que, por exemplo, tenham uma distribuição de freqüência dos andares desigual indicando um   andar de entrada e saída do prédio.
  
5. Realize várias execuções do seu simulador, mostrando a correção do seu funcionamento.

O programa implementado deve ser avaliado para várias configurações, utilizando as funções getrusage e gettimeofday. Deve-se também distinguir entre os tempos de computação e tempos
de entrada e saída. Comente sobre os tempos de usuário e os tempos de sistema e sua relação com os tempos de relógio.


##Documentação

Deve ser clara e objetiva, descrevendo as soluções adotadas e justificando bem as escolhas realizadas. Devem possuir também uma análise de complexidade detalhada das soluções. Em
termos de análise de resultados, avalie o desempenho e funcionamento de seu algoritmo para diversas configurações e avalie também o tempo de execução dos mesmos. Lembre-se, o importante é você
apresentar maturidade técnica em suas discussões.

**Observações:**
- O código fonte do trabalho deve ser submetido para compilação e execução em ambiente Linux, tendo como padrão os computadores dos laboratórios do DCOMP.
- Deve ser escrito na linguagem C (trabalhos implementados em outras linguagens como C++/Java/Python e outras não serão aceitos);
- As estruturas de dados devem ser alocadas dinamicamente e o código deve ser modularizado utilizando os arquivos .c .h.
- O utilitário Make deve ser utilizado para compilar o programa;
- A saída deve ser impressa no arquivo pedido seguindo estritamente o formato da especicação caso contrário o resultado será considerado errado;
- O arquivo executável deve ser chamado de tp1.
- Faça seu código de forma legível



>**Universidade Federal de São João del Rei Departamento de Ciência da Computação Bacharelado em Ciência da Computação Algoritmos e Estruturas de Dados III***

>*Professor:* Leonardo Chaves Dutra da Rocha

