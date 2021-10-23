
# -O2 pour que "inline" fonctionne bien par défaut
CFLAGS= -Wall -Werror -O2
CC=gcc

all: mesure_tris

mesure_tris: mesure_tris.o tris.o
	$(CC) $(CFLAGS) mesure_tris.o tris.o -o mesure_tris -lm

clean:
	rm -f mesure_tris *.o
