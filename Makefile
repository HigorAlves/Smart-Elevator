compile:	main.c funcoes.c
	gcc main.c funcoes.c -O3 -o tp1
executa:
	./tp1 -a 10 -c 10 -e elevador.txt -p passageiros.txt -g 10000000
clean:
	rm -rf tp1 OUT_SJF.txt OUT_FIFO.txt
