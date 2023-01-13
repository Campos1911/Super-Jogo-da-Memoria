<h1 align="center">Super Jogo da Memória</h1>

<p align="center">Esse projeto foi feito para um trabalho da disciplina de Programação I, no curso de Engenharia Elétrica, da Universidade Federal do Espírito Santo (UFES).</p>

Tabela de conteúdos
=================
<p align="center">
 <a href="#objetivo">Objetivo</a> •
 <a href="#status-do-jogo">Status</a> • 
 <a href="#bibliotecas-utilizadas">Bibliotecas Utilizadas</a> • 
 <a href="#escolhas-tomadas-na-programação">Escolhas Tomadas</a> • 
 <a href="#licenc-a">Licença</a> • 
 <a href="#autor">Autor</a>
</p>

# Autor 
Anthoni Bernardi Thomes Campos 


# Status do Jogo
<h4 align="center"> 
	🔴🟢🟡  Super Jogo da Memória -> Em construção...  🔴🟢🟡
</h4>

# Objetivo
O jogo da memória tem por objetivo fornecer um tabuleiro com determinadas peças randômicas, a fim de formar pares de peças iguais, de modo que o jogo chegará ao fim quando não existirem mais pares possíves.

# Bibliotecas Utilizadas
Para esse projeto, optei por utilizar as seguintes bibliotecas padrões da linguagem C:

### Stdio.h:
Utilizada para entrada e saída da linguagem (printf e scanf).

### Stdlib.h:
Utilizada para as funções randômicas (srand e rand).

### Time.h:
Foi utilizada no desenvolvimento do projeto, quando a função "srand" estava recebendo o "valor" time(NULL). Apesar de não estar utilizando no código atual, deixei como opção para substituir a variável "semente", de modo que o código gere valores aleatórios sem que o usuário insira valor algum.

![Capturar](https://user-images.githubusercontent.com/119754605/212426798-f26be41a-f7ce-46ea-9735-fb82856b4595.PNG)

### Conio.h

Utilizada para as funções "system("cls")" e "system("color")", responsáveis, respectivamente, por limpar o terminal e definir uma cor para as letras.

![Capturar](https://user-images.githubusercontent.com/119754605/212427251-8831c0c8-35e2-4664-bc1a-c39a27cb617d.PNG)

# Escolhas Tomadas na Programação

# Função para randomizar letras

![Capturar](https://user-images.githubusercontent.com/119754605/212426798-f26be41a-f7ce-46ea-9735-fb82856b4595.PNG)

As condições apontadas pela imagem postas para que o "randomizador" fornecesse apenas letras maiúsculas de A a Z. Ou seja, o "65" é referente ao ponto de partida (no caso, o "A" maiúsculo na tabela ANSI), e o 26 é o total de "amostras" que ele pode percorrer acima do "65".