#Trabalho Pratico AEDS III

**Data de entrega 05/08**
>Dupla Higor Alves e Pedro Oliveira.

###Ambiente do Elevador

>O ambietne do elevador é definido pelo arquivo de entrada.

**_Deve conter no arquivo:_**

- [ ] Número de Andares do Prédio.
- [ ] Número maximo de passegeiros que o elevador comporta.

>A velocidade do elevador é de 1 Jepslon.

###Estrategias Usadas

- Velocidade do Elevador é Constante (Não possui aceleração).
- Todos os tempos são definidos pela velocidade de tempo, Jepslon.
- A entrada de um ou mais passageiros no elevador no mesmo andar gasta 1 Jepslon.

**FIFO:** First in First Out, o primeiro a entrar vai ser sempre o primeiro a sair.

**SmartElev:** Esta função grava a moda das entradas, com isso o elevador sabe em qual andar ficar em stand-by para economizar Jepslon. Já que ele fica no andar mais requisitado.

>Quando estiver cheio o elevador irá ignorar o chamado ate abrir um espaço vago (nos dois casos estrategicos).

####Descrição da SmartElev

Sabendo qual andar é mais requisitado, ele irá ficar em stand-by nele, economizando Jepslon's, so saindo deste estado quando é requisitado;

**Caso 1:** Seja requisitado em dois lugares ao mesmo tempo ele vai ate o mais proximo;

**Caso 2:** Seja requisitado em dois andares ou mais, acima/abaixo do que esta em stand-by, ele vai ate o mais distante e desce/sobe buscando os outros.

##Padrão dos arquivos de entrada

*Os arquivos devem seguir esta formatação padrão para que funcione sem complicações.*

###Ambiente do elevador:

**Nome:** *ambiente-elevador.txt*

No arquivo devem ter um X,Y como no exemplo:
```
X,Y
```
Onde **_X_** é o número total de andares do predio onde o elevador esta, e **_Y_** é a capacidade maxima de passageiros que o elevador suporta.
> **NOTA:** *X* e *Y* devem ser inteiros!

Caso seja requisitado realizar varios testes com diferentes configurações basta inserir o arquivo com linhas separadas para cada tipo de teste, exemplo:
```
10,5
5,8
150,34
```
TODA linha deve ser separada por ENTER, e NÂO deve haver mais que o X e Y.

###Passageiros:

**Nome:** *passageiros.txt*

Dentro do arquivo cada passageiro tem 3 variaveis para cada passageiro *X Y Z* as quais DEVEM estar separadas por espaço. O significado de cada uma esta explicado na tabela logo abaixo.

| X | Y | Z |
|:-:|:-:|:-:|
|Identificador unico da pessoa (Inteiro)|Andar onde ela está (Inteiro)|Andar para a qual ela irá (Inteiro)|

Caso queira adicionar mais de um passageiro por andar siga o exemplo:
```
X Y Z,X Y Z,X Y Z,X Y Z

X Y Z,X Y Z
```
Neste exemplo acima, vemos que os passageiros separados por **,** isso faz com que o programa reconheça que cada vez q ele ler a **,** ira saber que é um novo passageiro.
>**NOTA:** passageiros com mesmo *Y* (andar onde está) estão sempre na mesma linha.

Entre as duas linhas de passageiros vemos que há um espaço (ENTER), este espaço é usado para avisar o programa que ao chegar nesta leitura ele sabera que esta sendo chamado de outro andar.
