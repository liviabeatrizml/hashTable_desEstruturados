## :family_man_woman_girl_boy: Equipe
:man_teacher: Professor: [Kennedy Reurison Lopes](https://github.com/kennedyufersa).<br />
:man_student: Integrante: [Arthur Kellyson Pinheiro de Negreiros](https://github.com/Arthurkellysonp). <br />
:woman_student: Integrante: [Geísa Morais Gabriel](https://github.com/Geisa-mg).<br />
:man_student: Integrante: [Leonardo Inácio Guilherme Dantas](https://github.com/LeonardoIGD).<br />
:woman_student: Integrante: [Livia Beatriz Maia de Lima](https://github.com/liviabeatrizml).<br />
:man_student: Integrante: [Pedro Makson Fontes da Costa](https://github.com/PedroMakson).


## Hash Table (Tabela de Dispersão)
> Uma Tabela de Dispersão ou Hash é uma estrutura de dados, semelhante a vetor de elementos, que associa seus dados a chaves específicas para facilitar na sua busca. Por meio dessa tabela também torna-se possível inserir e remover os elementos nela contidos. A utilização da estrutura hash tem como propósito fundamental realizar busca de dados de maneira constante (complexidade O(1)), mas isso nem sempre é possível, pois no momento de inserção de diversos elementos na tabela há grandes chances de haver colisões, o que altera a complexidade para O(n), semelhante a de uma lista.   

Baseado no estudo da Tabela de Dispersão, bem como em sua utilização em linguagem C++, implementou-se uma pasta contendo os arquivos necessários para buscar, inserir e remover cidades brasileiras baseadas nas localidades. Nesse sentido, a fim de tratar as possíveis colisões previstas, visto a gama de municípios, fez-se o uso do endereçamento aberto através da sondagem linear. Dessa forma, o espaço fica alocado de uma forma eficiente. No entanto, a sondagem linear, uma vez que procura adicionar um elemento na primeira posição livre seguinte, também prejudica o desempenho da busca quando se elimina um determinado elemento, mas esse problema pode ser resolvido. 

 -  Alteração no código pré-determinado pelo professor
	-   Arquivos não alterados
	    -   bancoDeDados - Mantemos as mesmas informações das cidades;
	    -   cidade.cpp - Não alteramos nada nesse arquivo para mantermos a mesma estrutura dada pelo professor.
	-   Arquivos alterados
		-   bancoDeDadosTemp - Organizamos um banco de dados menor contendo apenas informações de algumas cidades para facilitar os testes;
		-   lerArquivos.cpp - Alterações a forma que os dados do banco de dados são apresentados com o printf no terminal;
		-   Hash.cpp - Criamos novas funções para a aplicação um novo método de inserção de elementos na tabela e tratamento de colisões;
		-   main.cpp - Modificamos o arquivo para adicionar todas as cidades na tabela Hash.
