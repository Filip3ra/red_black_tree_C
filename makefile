#----------------- Makefile do Filipera -----------------#
all: tree
tree:	main.o	tree.o
	gcc -o prog main.o tree.o

tree.o:	tree.c
	gcc -o tree.o -c tree.c -W -Wall -ansi -pedantic -ggdb3
main.o:	main.c	tree.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic -ggdb3	
clean:
	rm -rf *.o
	rm -rf tree	
	rm -rf prog
exec:
	valgrind ./prog

# all:       nome das regras a serem executadas
#
# clean:     apaga arquivo intermediário
#
# TAB: 	     espaços devem ser feitos com TAB
#
# -Wall:     Ativa avisos não comuns, pode dar conselhos úteis
#
# -pedantic: Ativa avisos de acordo com o padrao C
#
# -ansi:     Compila o programa de acordo com o padrão ANSI
#
# ggdb3:     Adiciona informações extras no debug
