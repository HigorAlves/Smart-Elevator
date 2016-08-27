compila:
	gcc main.c funcoes.c funcoes.h -o tp1
	clear
	@echo "Compilacao feita com sucesso, nome do arquivo tp1"
clean:
	rm -rf tp1
	clear
	@echo "Arquivos limpados com sucesso!"
