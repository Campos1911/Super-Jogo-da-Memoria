# Super Jogo da Memória


<p align="center">Esse projeto foi feito para um trabalho da disciplina de Programação I, no curso de Engenharia Elétrica, da Universidade Federal do Espírito Santo (UFES).</p>

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
 <a href="#autor">Autor</a>
 </p>

# Status do Jogo
<h4 align="center"> 
	🔴🟢🟡  Super Jogo da Memória -> Em desenvolvimento 🚧 <-  🔴🟢🟡
</h4>

# Objetivo
O jogo da memória tem por objetivo fornecer um tabuleiro com determinadas peças randômicas, a fim de formar pares de peças iguais, de modo que o jogo chegará ao fim quando não existirem mais pares possíves.

# Como Rodar o Jogo?
Antes de começar, você vai precisar ter instalado em sua máquina um compilador de linguagem " C ", por exemplo o GCC. Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/)

* Para rodar o código, você precisa ir até o terminal e digitar: gcc jogo.c -o jogo

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

### Conio.h:

Utilizada para as funções "system("cls")" e "system("color")", responsáveis, respectivamente, por limpar o terminal e definir uma cor para as letras.

![Capturar](https://user-images.githubusercontent.com/119754605/212427251-8831c0c8-35e2-4664-bc1a-c39a27cb617d.PNG)

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

### Cores ao acertar e errar

![Capturar](https://user-images.githubusercontent.com/119754605/213035087-81f1db98-54d9-4105-a625-52db03fdb0c5.PNG)

Agora, quando o usuário acertar ou errar, o terminal mudará de cor, para indicar se foi uma escolha correta ou incorreta.

### Coordenada já descoberta

![Capturar](https://user-images.githubusercontent.com/119754605/213897859-99525dbb-3456-47fb-848a-55bb759fd6c4.PNG)

Se o jogador tentar inserir uma coordenada já descoberta por ele, o jogo muda para a cor vermelha e alerta sobre a escolha incorreta.

# Autor 
Projeto desenvolvido por Anthoni Campos - Entre em contato!

[![Gmail Badge](https://img.shields.io/badge/-anthonithomes@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:anthonithomes@gmail.com)](mailto:anthonithomes@gmail.com)

# Licença

* Clique no botão azul para acessar informações sobre a licença: [MIT](https://github.com/Campos1911/Jogo-da-memoria/blob/main/LICENSE)