# Project2-PROG

GROUP MEMBERS:
- Mariana Lima Teixeira
- Ricardo André Araújo de Matos

PROGRAM DEVELOPMENT STATE:

  O objetivo deste trabalho foi alcançado. Além do proposto, foram melhoradas as interações com o jogo, apresentando-se texto em 
  ASCII Art (do site https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20 fonte star wars) e centralizado o 
  jogo ligeiramente, o que melhora a interface com o utilizador.
  
  Partiu-se do pressuposto, quanto ao ficheiro de vencedores, que este poderia ainda não existir ou então estar vazio, sendo então 
  criado um novo e rescrito com as informações necessárias. Isto permitirá ao utilizador, caso acrescente novos mapas (assumidos como 
  sendo válidos), não ter que criar um ficheiro para os vencedores. Além disso, só seria possível mostrar os (eventuais) vencedores 
  de um dado maze na condição de esse maze existir.
  
  Por outro lado, também se assumiu que os labirintos (mazes) apenas contêm saídas na sua delimitação ou periferia. Nenhuma indicação
  foi dada para o que acontecia para o caso de tal não acontecer, e tendo em conta que os robôs não tem visão, estes poderiam muito 
  bem ir ao encontro destes postes. 
  
  Também se assumiu que quando os robôs vivos R colidem com robôs mortos/presos r são representados por um único carater r,
  algo que não estava muito percetível nas especificações do trabalho.
   
  Finalmente, partiu-se do princípio que
  Apenas métodos utilizados foram implementados no código submetido.
  
MAIN DIFFICULTIES: 

   A maior dificuldade sentida foi na transição para um paradigma de linguagem orientada por objetos, mudança que obviamente nos 
   obrigou a reconstruir grande parte do código do outro projeto. Uma vez que este trabalho era centrado em OOP, optámos por 
   usar quase unicamente classes, fazendo: uma classe "Menu", que ficou com a responsiblidade de mapear inputs para ficheiros, chamar 
   as diversas opções do menu, etc; outra classe, LeaderBoard, que tem como responsabilidade gerir os ficheiros dos vencedores; a 
   classe, Game_Object, da qual os restantes objetos do jogo derivam (os postes, os robôs e o player).
   