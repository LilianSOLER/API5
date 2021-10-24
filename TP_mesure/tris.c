#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

/*
generation_aleatoire
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : les valeurs t[0..n-1] ont ete initialisees avec n valeurs aleatoires
           prises dans [0,2147483647] selon une loi uniforme.
Pre-condition : le generateur aleatoire doit avoir ete initialise avec "srand"
*/

void generation_aleatoire(int t[], int n) {
  int i ;

  for (i=0 ; i<n ; i++) {
	  t[i] = rand() ;
  } ;
}

/*
generation_aleatoire_non_uniforme
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : les valeurs t[0..n-1] ont ete initialisees avec n valeurs aleatoires
           prises dans [0,2147483647].
Pre-condition : le generateur aleatoire doit avoir ete initialise avec "srand"
*/
void generation_aleatoire_non_uniforme(int t[], int n) {
  int i;
  int x = 0;

  for (i=0; i < n; i++) {
    t[i] = x;
    x = x + ((rand() % 10) - 2);
  }
}

/*
tri_insertion
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : le tableau t est trie en ordre croissant
*/
long long int c1 = 0;
int cmp_tri_insertion(int a, int b) {
  c1++;
  return a > b;
}
void tri_insertion(int t[], int n) {
  int i,j;
  int Clef;

  for(i=1; i < n; i++) {
    
    Clef = t[i];
    
    j = i - 1;
    
    /* Decalage des valeurs du tableau */
    while((j >= 0) && (cmp_tri_insertion(t[j], Clef))) {
      t[j+1] = t[j];
      j = j - 1;
    }
    
    /* insertion de la clef */
    t[j+1] = Clef;
  }
}

/*
tri_segmentation
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : le tableau t est trie en ordre croissant
*/

long long int c2 = 0;
void tri_segmentation(int t[], int n) {
  if (n <= 1){
    return;
  }

  int pivotv = t[0],pivot = 1,size = n - 1,tmp = 0;

  while (pivot != size) {
    if (t[pivot] > pivotv) {
      tmp = t[pivot];
      t[pivot] = t[size];
      t[size] = tmp;
      size--;
    } else
    pivot++;
    c2++;
  }
  if (t[pivot] > pivotv){
    pivot--;
  }
    
  c2++;
  t[0] = t[pivot];
  t[pivot] = pivotv;

  int nsize = n - pivot - 1;
  int t2[nsize];
  for (int i = 0; i < nsize; i++){
    t2[i] = t[pivot+i+1];
  }
    
  tri_segmentation(t, pivot);
  tri_segmentation(t2, nsize);

  for (int i = 0; i < nsize; i++){
    t[pivot+i+1] = t2[i];
  }
    
}



void lancer_mesures() {

  //unsigned int germe ;
  int T[100];
  //int res;

  //printf("Valeur du germe pour la fonction de tirage aleatoire ? ") ;
  //res=scanf("%d", &germe) ;
  //assert(res==1);
  //srand(germe);
  srand(2);
  

  // do {
  // 	printf("Valeur de N ? \n") ;
  // 	res=scanf("%d", &N) ;
	// assert(res==1);
  // } while (N<1 || N > NMAX) ;

  long long int X = 10000;
  long long int N = 1000;

  long long int c1_moy_array[X], c2_moy_array[X],c1_moy_moy_array[N], c2_moy_moy_array[N];
  long long int c1_moy = 0, c2_moy = 0;
  for(N = 1; N < 1000; N++){
    printf("N,%lld;", N);
    for(int i = 0; i < X; i++){
      c1 = 0;
      generation_aleatoire(T, N) ; /* initialisation du tableau T */
      tri_insertion(T, N) ;	/* tri de T */
      c1_moy += c1;
      c1_moy_array[i] = c1;

      c2 = 0;
      generation_aleatoire(T, N) ; /* initialisation du tableau T */
      tri_segmentation(T, N) ;	/* tri de T */
      c2_moy += c2;
      c2_moy_array[i] = c2;

      printf("c1,%lld,c2,%lld;", c1, c2);
    }
    printf("\n");

    c1_moy /= X-1;
    c1_moy_moy_array[N] = c1_moy;
    long long int c1_variance = 0;
    for(int k = 0; k < X; k++){
      c1_variance += (long long int) pow(c1_moy_array[k] - c1_moy,2);
    }
    double c1_ecart_type = sqrt(c1_variance/X);

    c2_moy /= X-1;
    c2_moy_moy_array[N] = c2_moy;
    long long int c2_variance = 0;
    for(int k = 0; k < X; k++){
      c2_variance += (long long int) pow(c2_moy_array[k] - c2_moy,2);
    }
    double c2_ecart_type = sqrt(c2_variance/X);
    printf("c1_moy,%lld,c2_moy,%lld;",c1_moy, c2_moy);
    printf("c1_ecart_type,%f,c2_ecart_type,%f\n",c1_ecart_type,c2_ecart_type);
  }
  printf("----\n");
  long long int c1_moy_moy = 0, c2_moy_moy = 0;
  printf("RESULTAT GLOBALE\n");
  for(int i = 1; i < 1000; i++){
    printf("c1_moy_moy_array,%lld,c2_moy_moy_array,%lld;",c1_moy_moy_array[i], c2_moy_moy_array[i]);
    c1_moy_moy += c1_moy_moy_array[i];
    c2_moy_moy += c2_moy_moy_array[i];
  }
  printf("\n");
  c1_moy_moy /= 999;
  c2_moy_moy /= 999;
  printf("c1_moy_moy,%lld,c2_moy_moy,%lld\n",c1_moy_moy, c2_moy_moy);



  // long long int c_moy_array[X];

  // // long long int c1_moy = 0;
  // for(int j = 0; j < X; j++){
  //   c1 = 0;
  //   generation_aleatoire(T, N) ; /* initialisation du tableau T */
  //   tri_insertion(T, N) ;	/* tri de T */
  //   c1_moy += c1;
  //   c_moy_array[j] = c1;
  //   printf("%d sur %lld : %lld\n",j+1, X, c1);
  // }
  // c1_moy /= X;
  // long long int c1_variance = 0;
  // for(int k = 0; k < X; k++){
  //   c1_variance += (long long int) pow(c_moy_array[k] - c1_moy,2);
  // }
  // double c1_ecart_type = sqrt(c1_variance/X);
  // printf("Moyenne 1 : %lld\n", c1_moy);
  // printf("Ecart Type 1 : %f\n", c1_ecart_type);

  // printf("\n");

  // long long int c2_moy = 0;
  // for(int j = 0; j < X; j++){
  //   c2 = 0;
  //   generation_aleatoire(T, N) ; /* initialisation du tableau T */
  //   tri_segmentation(T, N) ;	/* tri de T */
  //   c2_moy += c2;
  //   c_moy_array[j] = c2;
  //   printf("%d sur %lld : %lld\n",j, X, c2);
  // }
  // c2_moy /= X;
  // long long int c2_variance = 0;
  // for(int k = 0; k < X; k++){
  //   c2_variance += (long long int) pow(c_moy_array[k] - c2_moy,2);
  // }
  // double c2_ecart_type = sqrt(c2_variance/X);
  // printf("Moyenne 2 : %lld\n", c2_moy);
  // printf("Ecart Type 2 : %f\n", c2_ecart_type);
}
