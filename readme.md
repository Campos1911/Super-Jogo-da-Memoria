# Super Jogo da Memória


<p align="center">Esse projeto foi feito para um trabalho da disciplina de Programação I, no curso de Engenharia Elétrica, da Universidade Federal do Espírito Santo (UFES).</p>

## Observação sobre o código

O jogo foi desenvolvido no sistema operacional "Windows". Portanto, é preferivel que o código seja testado em máquinas com esse sistema instalado, para evitar possíveis problemas de incompatibilidade.


Tabela de conteúdos
=================
<p align="center">
 <a href="#objetivo">Objetivo</a> •
 <a href="#status-do-jogo">Status</a> • 
 <a href="#bibliotecas-utilizadas">Bibliotecas Utilizadas</a> • 
 <a href="#escolhas-tomadas-na-programação">Escolhas Tomadas</a> •
 <a href="#implementações-posteriores">Implementações Posteriores</a> • 
 <a href="#como-rodar-o-jogo">Como rodar o jogo?</a> • 
 <a href="#licença">Licença</a> •
 <a href="#segunda-versão---coisas-acrescentadas">Segunda Versão</a> •
 <a href="#autor">Autor</a>
 </p>

# Status do Jogo
<h4 align="center"> 
	🔴🟢🟡  Super Jogo da Memória -> Concluído🚧 <-  🔴🟢🟡
</h4>

# Objetivo
O jogo da memória tem por objetivo fornecer um tabuleiro com determinadas peças randômicas, a fim de formar pares de peças iguais, de modo que o jogo chegará ao fim quando não existirem mais pares possíves.

# Como Rodar o Jogo?
Antes de começar, você vai precisar ter instalado em sua máquina um compilador de linguagem " C ", por exemplo o GCC. Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/)

* Para rodar o código, você precisa ir até o terminal e digitar: gcc TX-ANTHONI-CAMPOS -o jogo (O "x" representa a versão jogada)

* Em seguida, será criado o arquivo " jogo.exe "

* Para jogar basta digitar: " ./jogo "

# Bibliotecas Utilizadas
Para esse projeto, optei por utilizar as seguintes bibliotecas padrões da linguagem C:

### Stdio.h:
Utilizada para entrada e saída da linguagem (printf e scanf).

### Stdlib.h:
Utilizada para as funções randômicas (srand e rand).

### Time.h:
Foi utilizada no desenvolvimento do projeto, quando a função "srand" estava recebendo o valor "time(NULL)". Apesar de não estar utilizando no código atual, deixei como opção para substituir a variável "semente", de modo que o código gere valores aleatórios sem que o usuário insira valor algum.

![Capturar](https://user-images.githubusercontent.com/119754605/212426798-f26be41a-f7ce-46ea-9735-fb82856b4595.PNG)


# Escolhas Tomadas na Programação

## Função para randomizar letras

![Capturar](https://user-images.githubusercontent.com/119754605/212426798-f26be41a-f7ce-46ea-9735-fb82856b4595.PNG)

As condições apontadas pela imagem postas para que o "randomizador" fornecesse apenas letras maiúsculas de A a Z. Ou seja, o "65" é referente ao ponto de partida (no caso, o "A" maiúsculo na tabela ANSI), e o 26 é o total de "amostras" que ele pode percorrer acima do "65".

## Função que altera entre 0's e 1's

![Capturar](https://user-images.githubusercontent.com/119754605/212427726-0221cf87-c3f3-495d-8e70-97dbbf50633b.PNG)

Essa função é responsável por alterar uma matriz alternativa quando o jogador acerta a posição de duas cartas semelhantes.

![Capturar](https://user-images.githubusercontent.com/119754605/212427891-d4383d03-0977-40a3-9758-3a4eb6e34d84.PNG)

## If's presentes dentro da MAIN

![Capturar](https://user-images.githubusercontent.com/119754605/212428133-4e69bc95-3cfd-450a-8f67-25ac77dd8563.PNG)

### Primeiro If

![Capturar](https://user-images.githubusercontent.com/119754605/212429363-47795815-0054-4935-8bb4-ad779fd49cca.PNG)


Utilizado para encerrar o programa quando o usuário inserir as coordenadas "0, 0, 0, 0"

### Segundo If

![Capturar](https://user-images.githubusercontent.com/119754605/212429842-5c0515f9-50dc-41bc-92c4-3402c35769fd.PNG)

Utilizado para alertar o jogador sobre coordenadas inválidas inseridas por ele

### Terceiro If

![Capturar](https://user-images.githubusercontent.com/119754605/212429578-c33662d7-c155-4707-b1c5-3e682dbce2fa.PNG)

Se as coordenadas indicadas possuírem valores iguais, o código contabiliza um "aux" a menos (subtrai um par presente), troca a mesma posição na matriz máscara de "0" para "1", de modo que essas casas ficarão aparentes na próxima impressão.

### Quarto If

![Capturar](https://user-images.githubusercontent.com/119754605/212429658-83fbec9a-bc14-401a-8c2d-cd5b42864b48.PNG)

Bastante parecido com o segundo if, porém, depois de demonstrar as casas que o usuário solicitou, ele muda os valores delas para "0" na matriz máscara, de modo que essas cartas ficarão ocultas na próxima impressão.

### Quinto If

![Capturar](https://user-images.githubusercontent.com/119754605/212430253-007ce609-f4aa-4182-9b00-01cd7378334f.PNG)


Utilizado para alertar sobre o fim de pares disponíveis para o jogador encontrar

# Implementações Posteriores

### Cores ao acertar e errar:

![Capturar](https://user-images.githubusercontent.com/119754605/216483966-5034cf1e-2659-4933-a255-b3c78ad4b18b.PNG)

Agora, quando o usuário acertar ou errar, o terminal mudará de cor, para indicar se foi uma escolha correta ou incorreta.

### Coordenada já descoberta

![Capturar](https://user-images.githubusercontent.com/119754605/213897859-99525dbb-3456-47fb-848a-55bb759fd6c4.PNG)

Se o jogador tentar inserir uma coordenada já descoberta por ele, o jogo muda para a cor vermelha e alerta sobre a escolha incorreta.

# Segunda Versão - Coisas acrescentadas	

## Structs

![Capturar](https://user-images.githubusercontent.com/119754605/215234696-38530fc8-998e-450c-8516-7a031c22d8f6.PNG)

Foram criadas duas structs, para armazenar a pontuação e o nome dos jogadores.

## Função "zera_struct"

![Capturar](https://user-images.githubusercontent.com/119754605/215234774-1e92dabe-b2d0-4507-97dd-4ccb6a1842e2.PNG)

Basicamente, foi utilizada para zerar a pontuação da struct, antes de começar a contabilizar.

## Impressão de arquivo com records

![Capturar](https://user-images.githubusercontent.com/119754605/215234616-cb1538f3-d735-4d6d-9300-455239d818c4.PNG)

Aqui, esse trecho de código cria um arquivo com o nome "Result_.txt", para salvar os pontos obtidos ao longo do jogo.

![Capturar](https://user-images.githubusercontent.com/119754605/215234886-86d9ed7e-6ef4-457e-baf5-2cedaa9565c5.PNG)

Esse é outro trecho, que também salva os pontos em um arquivo (com o nome fornecido pelos jogadores) e printa a tabela de pontos na tela (ao acertar algum par).

## Contatenando nomes para gerar arquivo "Result_"

Utilizando a função da "strcat" da "string.h", concatenei a string "Result_" com o nome do arquivo passado na chamada do programa

![Capturar](https://user-images.githubusercontent.com/119754605/216596958-da55bf82-d540-47ae-b687-761ea22558f4.PNG)

# Autor 
Projeto desenvolvido por Anthoni Campos - Entre em contato!

[![Gmail Badge](https://img.shields.io/badge/-anthonithomes@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:anthonithomes@gmail.com)](mailto:anthonithomes@gmail.com)

# Licença

* Clique no botão azul para acessar informações sobre a licença: [MIT](https://github.com/Campos1911/Jogo-da-memoria/blob/main/LICENSE)
