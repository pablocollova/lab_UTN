#include <stdio.h>
#include <stdlib.h>

int cargaArregloRandom(int a[],int v, int dim);
void muestraArregloIterativo(int a[], int v);
void muestraArregloRecursivo(int a[], int v, int i);
int sumaArregloIterativo(int a[], int v);
int sumaArregloRecursivo(int a[], int v, int i);
int sumaArregloRecursivoPro(int a[], int v, int i);

#define DIM 40000

int main()
{
    int a[DIM];
    int vA=0;
    int f=18;
  ///  printf("\n El factorial de %d es %d \n", f, factorial(f));

    vA = cargaArregloRandom(a,vA,DIM);
/*
    printf("\n Muestra arreglo iterativo........ %d\n");
    muestraArregloIterativo(a,vA);

    printf("\n Muestra arreglo recursivo........ \n");
    muestraArregloRecursivo(a,vA,0);
*/
//   printf("\n %d", sumaArregloIterativo(a,vA));
//   printf("\n %d", sumaArregloRecursivo(a,vA,0));
   printf("\n %d", sumaArregloRecursivoPro(a,vA,0));

    printf("\nHello world!\n");
    return 0;
}

int factorial(int x){
    int rta;
    if(x==0){
        rta=1;
    }else{
        rta=x*factorial(x-1);
    }
    return rta;
}

int cargaArregloRandom(int a[],int v, int dim){
    for(;v<dim;v++){
        a[v]=rand()%10;
    }
    return v;
}

void muestraArregloIterativo(int a[], int v){
    for(int i=0;i<v;i++){
        printf("%c %d ", (i%10==0)?'\n':'-', a[i]);
    }
}

void muestraArregloRecursivo(int a[], int v, int i){
    if(i<v){
        printf("%c %d ", (i%10==0)?'\n':'-', a[i]);
        muestraArregloRecursivo(a,v,i+1); /// va i+1 NUNCA i++
    }
}

int sumaArregloIterativo(int a[], int v){
    int suma=0;
    for(int i=0;i<v;i++){
        suma+=a[i];
    }
    return suma;
}

int sumaArregloRecursivo(int a[], int v, int i){
    int suma=0;
    if(i<v){
        suma=a[i]+sumaArregloRecursivo(a,v,i+1);
    }
    return suma;
}

int sumaArregloRecursivoPro(int a[], int v, int i){
    return (i<v) ? a[i]+sumaArregloRecursivo(a,v,i+1) : 0;
}
