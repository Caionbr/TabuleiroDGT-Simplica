# Xadrez DGT Simplificado
### Projeto Final Sistemas Microprocessados - 2022.2 - UFC

   A rápida popularização do Xadrez na era moderna e com o avanço da tecnologia, houve a necessidade da criação de tabuleiros inteligentes que auxiliassem na transmissão de jogos em tempo real. Visto isso, os tabuleiros DGTs foram rapidamente tomando conta dos circuitos internacionais e sendo utilizados em massa nos principais campeonatos. O tabuleiro consiste em uma série de sensores, que conseguem identificar a localização de todas as peças, bem como e uma saída Serial, para uma possível transmissão do jogo via Internet.  
Muitos entusiastas do xadrez possuem a necessidade de registrar as suas partidas presenciais para uma possível análise posterior, bem como utilizar o auxílio de software de cálculo, como o Stockfish. Entretanto, o preço dos tabuleiros DGTs se mostram um grande entrave para o consumo destes, uma vez que o seu valor gira em torno de 9 mil reais.  
Pensando nisso, o objetivo deste projeto é construir um tabuleiro que replique algumas funcionalidades dos tabuleiros DGTs, de maneira simplificada.

## Integrantes

* Caio Nobre - 521326
* Letícia Neri - 496518
* Lucas Mariano - 537455
* Mirailton Costa - 521325

## Componentes

* Dois microprocessadores STM32F070F6P6
* Módulo Serial I2C para Display LCD
* Cabo Conversor USB para Serial DB9 (RS232)
* Módulo Conversor Serial RS232 para TTL
* Malha matricial 8x8 com diodos
* Display LCD 16x2
* Bateria para a alimentação do projeto (3.3 V)

## Descrição

O projeto consiste em utilizar uma malha matricial 8x8 semelhante à utilizada no teclado matricial, com diodos entre as aberturas, onde é montada a estrutura do tabuleiro. Um micro (Modelo F070F6P6) ficará responsável pela leitura de todas as colunas e outro micro (Modelo F070F6P6) ficará responsável pela leitura das linhas. Dessa forma, ambos trabalharão juntos para localizar cada peça no tabuleiro.  
Como previamente sabemos a posição inicial de cada peça no tabuleiro, basta fazer um monitoramento dos movimentos de cada peça para acompanhar a sua localização em tempo real, o que será feito a partir da comunicação do microprocessador mestre com o PC. Os dados de cada jogada serão enviados para um computador que irá salvar o histórico da partida e a posição atual do jogo em tempo real.  
Por fim, o display LCD 16x2 irá servir para interfacear o relógio da partida, onde este mostrará o tempo restante de cada jogador a cada jogada realizada no tabuleiro.  





