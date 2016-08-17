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

**Ambiente do elevador:**

O arquivo com a definição de ambiente deve seguir os seguintes padrões:

**Nome:** *ambiente-elevador.txt*

| Formato Dentro do arquivo | Explicação |
|:----:|:------:|
|X,Y|**_X_** são os andares do predio & **_Y_** é a capacidade maxima de pessoas no elevador|

Caso seja requisitado realizar varios testes com diferentes configurações basta inserir o arquivo com linhas separadas para cada tipo de teste, exemplo:

| X e Y | Explicação | 
|:---:|:---:|
| 10,5 | Andares, Pessoas |
| 50,15 | Andares, Pessoas |
| 150,30| Andares, Pessoas |

>**NOTA:** TODA linha deve ser separada por ENTER e NÂO deve haver mais de haver mais que o X e Y.
>Andares e Pessoas na tabela é meramente ilustrativo para fins de entendimento.

**Passageiros:**

