compile:
	gcc funcoes.h main.c funcoes.c -o tp1
clean:
	rm -rf tp1
	clear
	@echo "Arquivos limpados com sucesso!"
executa:
	./tp1 -p p.txt -c 10 -o fifo -a 10
executa2:
	./tp1 -e e.txt -p p.txt -o fifo 
