#include <omp.h>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int tamanho = 10;
    



    int **matriz = (int **) malloc(sizeof(int*)*tamanho);
    int *p_i;
    int *p_j;  
    /*
    for(p_i = (int *) matriz; p_i< (int*)matriz+(tamanho*tamanho); p_i++){
	*(p_i) = rand()%256;
    }*/
    for (int i = 0; i < tamanho; i++) {
        *(matriz + i) = (int *)malloc(tamanho * sizeof(int));
    }

    for (int i = 0; i < tamanho; i++) {
        int *row = *(matriz + i);
        for (int j = 0; j < tamanho; j++) {
            *(row + j) = rand() % 256;
            cout<<*(row + j)<<'\n';
        }
    }
    
    
    for (int i = 0; i < tamanho; i++) {
        int *row = *(matriz + i);

        for (int j = 0; j < tamanho; j++) {
		    int soma = 0;
		    int numero_elementos = 0
		    if(row+1){
//		    	soma, numero_elementos++;
		    }
		    if(row-1){
		    	
		    }
		    if(row+tamanho){
		    	
		    }
		    if(row-tamanho){
		    	
		    }
		    if(row+tamanho+1){
		    	
		    }
		    if(row-tamanho+1){
		    	
		    }
		    if(row+tamanho-1){
		    	
		    }
		    
		    if(row+tamanho-1){
		    	
		    }
		    
		    
	        *(row + j) = (row +1)
            
        }
    }
    
    
    /*for(p_i = (int *) matriz; p_i< (int*)matriz+(tamanho*tamanho); p_i++){
	*(p_i) = (*(p_i-1) + *(p_i+1))/2;
    }*/

    /*for (int **i = matriz; i<matriz +(tamanho); i++)
        **i=rand()%256;

    for(int **i = matriz; i<matriz+(tamanho);i++)
        cout<<'\n'<<**i;*/
    cout<<"Olá mundo"<<'\n';
    free(matriz);
    return 0;






}
