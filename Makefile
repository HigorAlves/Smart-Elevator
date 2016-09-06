compile:
	gcc main.c funcoes.c -o tp1
clean:
	rm -rf tp1
	clear
	@echo "Arquivos limpados com sucesso!"
executa:
	./tp1 -p passageiros.txt -c 10 -o fifo -a 10
executa2:
	./tp1 -e elevador.txt -p passageiros.txt -o fifo
