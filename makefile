stringMe: kaurIshnoorA2.o kaurIshnoorA2Main.o
	gcc -Wall -std=c99 kaurIshnoorA2.o kaurIshnoorA2Main.o -o stringMe
	mv stringMe bin
kaurIshnoorA2.o: src/kaurIshnoorA2.c include/kaurIshnoorA2.h
	gcc -Wall -std=c99 -c src/kaurIshnoorA2.c
kaurIshnoorA2Main.o: src/kaurIshnoorA2Main.c include/kaurIshnoorA2.h
	gcc -Wall -std=c99 -c src/kaurIshnoorA2Main.c
clean:
	rm *.o bin/stringMe
