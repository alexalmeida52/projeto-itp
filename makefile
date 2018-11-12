all:
	gcc -c ./src/panel.c -I ./include -o ./obj/panel.o
	gcc -c ./src/help.c -I ./include -o ./obj/help.o
	gcc -c ./src/operaBin.c -I ./include -o ./obj/operaBin.o
	gcc -c ./src/selectTable.c -I ./include -o ./obj/selectTable.o
	gcc -c ./src/createTable.c -I ./include -o ./obj/createTable.o
	gcc -c ./src/deleteTable.c -I ./include -o ./obj/deleteTable.o

	gcc ./main.c ./obj/*.o -I ./include -o ./main

run:
	./main

clear:
	rm ./obj/*.o
	rm ./main
