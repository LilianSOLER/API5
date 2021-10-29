#ifndef FIBO_COMPUTE_H
#define FIBO_COMPUTE_H

typedef struct matrice22 {
    int a,b,c,d;
} matrice22;

typedef struct matrice21 {
    int a,b;
} matrice21;


unsigned long long int fibo_rec(int n);
unsigned long long int fibo_iter(int n);
unsigned long long int fibo_rec2(unsigned long long int n);
unsigned long long int fibo_rec2_aux(unsigned long long int n,unsigned long long int a, unsigned long long int b);
unsigned long long int puissance (float x,unsigned long long int n);
unsigned long long int fibo_golden(unsigned long long int n );
matrice22 mult(matrice22 m, matrice22 l);
matrice21 mult_dif(matrice22 m, matrice21 l);
matrice22 puissancem (matrice22 m,unsigned long long int n);
matrice21 fibo_matrice(unsigned long long int n);

#endif
