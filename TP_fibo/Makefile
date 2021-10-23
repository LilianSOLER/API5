
# utilisation des règles implicites connues par Make
# pour compiler de nombreux langages
# Ces règles (et les variables utilisée) sont visibles en lançant "make -p"

# Nésitez pas à ajuster ces variables si nécessaires
CC=gcc
# "-MMD -MF .$*.d" permet de faire générer un fichier
# de dépendance qui sera inclus par Make (cf 'include' plus bas)
CFLAGS=-O2 -g -MMD -MF .$*.d
CPPFLAGS=-Wall -Werror #-Wextra
LDLIBS=-lm

# Liste des programmes à compiler
PROGS=fibo

# cible 'all' par défaut (la première du fichier)
# on contruit tous les programmes 
all: $(PROGS)

# pour chaque programme, on indique les fichiers objets
# qui le compose. Un programme (par exemple 'fibo') doit
# dépendre d'un fichier object du même nom ('fibo.o' pour
# cet exemple) si on veut utiliser les règles implicites
# de Make (sinon, il faut donner explicitement la commande)
fibo: fibo.o fibo_compute.o

# on inclut les fichiers de dépendance autogénérés
include $(wildcard .*.d)

# cibles qui ne sont pas réellement à construire
# (pas de fichier nommés 'all' ou 'clean')
.PHONY: all clean

clean:
	$(RM) $(PROGS) *.o .*.d
