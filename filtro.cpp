// filtro.cpp
#include "filtro.h"
#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

double filtro(int ** matriz, int tamanho, int threads){
    int **temp_matriz = (int **) malloc(sizeof(int*) * tamanho);
    for (int i = 0; i < tamanho; i++) {
        *(temp_matriz+i) = (int *) malloc(tamanho * sizeof(int));
    }
    // copia matriz para temp_matriz
    for (int i = 0; i < tamanho; i++) {
        int *linha_temp = *(temp_matriz+i);
        int *linha = *(matriz+i);
        for (int j = 0; j < tamanho; j++) {
            *(linha_temp+j) = *(linha+j);
        }
    }
    // na aplicação do filtro, sera medido o tempo
    // omp parallel
    omp_set_num_threads(threads);
    double inicio, fim;
    inicio = omp_get_wtime();
      
    #pragma omp parallel for
    for (int i = 0; i < tamanho; i++) {
            int *linha = *(matriz + i);
            int *linha_temp = *(temp_matriz+i);

        for (int j = 0; j < tamanho; j++) {
		    int soma = 0;
		    int numero_elementos = 0;
            // verificar as fronteiras da matriz 
		    if(j+1<tamanho){
                numero_elementos++;
                soma+=*(linha_temp+j+1);
		    }
		    if(j-1>=0){
                numero_elementos++;
                soma+=*(linha_temp+j-1);
		    }
		    if(i+1<tamanho){
                numero_elementos++;
                soma+=*(*(temp_matriz+i+1)+j);
		    }
		    // mesma coisa que int *linha = *(matriz + i-1);
		    // no entanto, nao podemos redefinir o valor de linha
		    if(i-1>=0){
                numero_elementos++;
                soma += *(*(temp_matriz+i-1)+j);
		    }
		    if(j+1<tamanho && i+1<tamanho){
		    	numero_elementos++;
                soma += *(*(temp_matriz+i+1)+j+1);
		    }
		    if(j+1<tamanho && i-1>=0){
		    	numero_elementos++;
                soma += *(*(temp_matriz+i-1)+j+1);
		    }
		    if(j-1>=0 && i+1<tamanho){
		    	numero_elementos++;
                soma += *(*(temp_matriz+i+1)+j-1);
		    }
		    
		    if(j-1>=0 && i-1>=0){
		    	numero_elementos++;
                soma += *(*(temp_matriz+i-1)+j-1);
		    }
		    

	        *(linha + j) = soma/numero_elementos;
            
        }
    }
    fim = double(omp_get_wtime() - inicio);   
    for (int i = 0; i < tamanho; i++) {
        free(*(temp_matriz + i));
    }
    free(temp_matriz);

    return (double)fim;


}

void imprimeMatriz(int **matriz, int tamanho){
    for (int i = 0; i < tamanho; i++) {
        int *linha = *(matriz + i);
        for (int j = 0; j < tamanho; j++) {
            cout<<*(linha + j)<<',';

        }
        cout<<'\n';
    }

}
