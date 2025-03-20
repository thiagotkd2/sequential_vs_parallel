#include <omp.h>
#include <iostream>
#include <cstdlib>
#include "filtro.h"
#include <fstream>
using namespace std;
int main()
{
    int tamanho = 10;
    int tamanho_matrizes[] = {1000,5000,10000};
    int tamanho_matrizes_length =sizeof(tamanho_matrizes) / sizeof(tamanho_matrizes[0]); 
    int qtd_threads[] = {1,2,4,8};
    int qtd_threads_length =sizeof(qtd_threads) / sizeof(qtd_threads[0]);

    ofstream outFile("resultados.txt");
    if (outFile.is_open()) {
        cout<<"Escrevendo arquivo..."<<'\n';
        for(int l = 0; l<tamanho_matrizes_length; l++){ // iterar por l tamanhos
            int tamanho = tamanho_matrizes[l];

            for(int i = 0; i<qtd_threads_length; i++){ // iterar por i threads possiveis
                int threads = qtd_threads[i];
                int **matriz = (int **) malloc(sizeof(int*)*tamanho);
                for (int j = 0; j < tamanho; j++) {
                    *(matriz + j) = (int *)malloc(tamanho * sizeof(int));
                }

                for (int j = 0; j < tamanho; j++) { // gerar valores aleatorios
                    int *linha = *(matriz + j);
                    for (int k = 0; k < tamanho; k++) {
                        *(linha + k) = rand() % 256;
                    }
                }

                // aplicar 10 vezes cada mediçao
                double tempo[10];
                outFile<<tamanho<<","<<threads<<'\n';

                for(int j = 0; j<10; j++){
                    tempo[j]=filtro(matriz, tamanho, threads);
                    if(j!=9)
                        outFile<<tempo[j]<<',';
                    else
                        outFile<<tempo[j]<<endl;
                }
                outFile<<'\n'<<'\n';
                for (int j = 0; j < tamanho; j++) {
                    free(*(matriz + j));
                }
                free(matriz);
            }

        }
        outFile.close();

    }else{

        cerr<<"Erro para criar o arquivo."<<endl;
    }

    
   
    return 0;
}
