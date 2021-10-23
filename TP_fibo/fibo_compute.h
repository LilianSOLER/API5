#ifndef FIBO_COMPUTE_H
#define FIBO_COMPUTE_H

typedef struct donnees_matrice {
    int l, c;
    unsigned long long int **donnees;
} matrice;


unsigned long long int fibo_rec(int n);
unsigned long long int fibo_iter(int n);
unsigned long long int fibo_rec2(unsigned long long int n);
unsigned long long int fibo_rec2_aux(unsigned long long int n,unsigned long long int a, unsigned long long int b);
unsigned long long int puissance (float x,unsigned long long int n);
unsigned long long int fibo_golden(unsigned long long int n );


#endif
