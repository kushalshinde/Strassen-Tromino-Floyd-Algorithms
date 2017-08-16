program: stra.o tro.o floyd.o

stra.o: shinde_pa2_stra.c
	gcc -g shinde_pa2_stra.c -lm -o stra.o

tro.o: shinde_pa2_tro.c
	gcc -g shinde_pa2_tro.c -lm -o tro.o

floyd.o: shinde_pa2_floyd.c
	gcc -g shinde_pa2_floyd.c -o floyd.o

clean:
	rm floyd.o stra.o tro.o				
