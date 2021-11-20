
#include "arbrebin.h"
#include "bfile.h"
#include "fap.h"
#include "huffman_code.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tab[256];
} TableOcc_t;

struct code_char HuffmanCode[256];

void ConstruireTableOcc(FILE *fichier, TableOcc_t *TableOcc) {

    int c;

    /* A COMPLETER ... */
    printf("Programme realise (ConstruireTableOcc)\n");

   //Reserver la memoire pour la table d'occurence    
    TableOcc = (TableOcc_t*) malloc(sizeof(TableOcc_t));
    //Initialiser la table d'occurence a zero
    for (int i = 0; i < 256; i++) {
        TableOcc->tab[i] = 0;
    }
    //Compte le nombre d'occurence de chaque caractere
    while ((c = fgetc(fichier)) != EOF) {
        TableOcc->tab[c]++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (TableOcc->tab[i] != 0)
            printf("Occurences du caractere %c (code %d) : %d\n", i, i,
                TableOcc->tab[i]);
    }
}

fap InitHuffman(TableOcc_t *TableOcc) {
    /* A COMPLETER */
    printf("Programme realise (InitHuffman)\n");
    
    fap F = creer_fap_vide();
    Arbre tmp;
    for (int i = 0; i < 256; i++) {
        if (TableOcc->tab[i] != 0) {
            tmp = NouveauNoeud(ArbreVide(), (Element) i, ArbreVide());
            F = inserer(F, tmp, TableOcc->tab[i]);
        }
    }
    return F;
}

Arbre ConstruireArbre(fap file) {
    /* A COMPLETER */
    printf("Programme non realise (ConstruireArbre)\n");
    return ArbreVide();
}


void ConstruireCode(Arbre huff) {
    /* A COMPLETER */
    printf("Programme non realise (ConstruireCode)\n");
}

void Encoder(FILE *fic_in, FILE *fic_out, Arbre ArbreHuffman) {
    /* A COMPLETER */
    printf("Programme non realise (Encoder)\n");
}

int main(int argc, char *argv[]) {

    TableOcc_t TableOcc;
    FILE *fichier;
    FILE *fichier_encode;

    fichier = fopen(argv[1], "r");
    /* Construire la table d'occurences */
    ConstruireTableOcc(fichier, &TableOcc);
    fclose(fichier);

    /* Initialiser la FAP */
    fap file = InitHuffman(&TableOcc);

    /* Construire l'arbre d'Huffman */
    Arbre ArbreHuffman = ConstruireArbre(file);

        AfficherArbre(ArbreHuffman);

    /* Construire la table de codage */
    ConstruireCode(ArbreHuffman);

    /* Encodage */
    fichier = fopen(argv[1], "r");
    fichier_encode = fopen(argv[2], "w");

    Encoder(fichier, fichier_encode, ArbreHuffman);

    fclose(fichier_encode);
    fclose(fichier);

    return 0;
}
