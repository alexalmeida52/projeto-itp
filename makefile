all:
	gcc -c ./src/panel.c -I ./include -o ./obj/panel.o
	gcc -c ./src/help.c -I ./include -o ./obj/help.o
	gcc -c ./src/selectTable.c -I ./include -o ./obj/selectTable.o
	gcc -c ./src/createTable.c -I ./include -o ./obj/createTable.o

	gcc ./main.c ./obj/*.o -I ./include -o ./main

run:
	rm ./obj/*.o
	rm ./main
	./main

clear:
	rm ./obj/*.o
	rm ./main