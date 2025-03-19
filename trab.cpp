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
        int *linha = *(matriz + i);
        for (int j = 0; j < tamanho; j++) {
            *(linha + j) = rand() % 256;
            if(j==tamanho-1)
                cout<<*(linha + j);
            else
                cout<<*(linha + j)<<',';
        }
        cout<<'\n';
    }
    cout<<'\n';

    int **temp_matriz = (int **) malloc(sizeof(int*) * tamanho);
    for (int i = 0; i < tamanho; i++) {
        temp_matriz[i] = (int *) malloc(tamanho * sizeof(int));
    }

    // Copy the content from matriz to temp_matriz
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            temp_matriz[i][j] = matriz[i][j];
        }
    }



    /*
     * *30 *20 *10
     * *15 25 *40
     * *16 *3 *29
     *
     */

    
    for (int i = 0; i < tamanho; i++) {
        int *linha = *(matriz + i);
        int *linha_temp = *(temp_matriz+1)

        for (int j = 0; j < tamanho; j++) {
		    int soma = 0;
		    int numero_elementos = 0;

		    if(j+1<tamanho){
                numero_elementos++;
                soma+=*(linha+j+1);
		    }
		    if(j-1>=0){
                numero_elementos++;
                soma+=*(linha+j-1);
		    }
		    if(i+1<tamanho){
                numero_elementos++;
                soma+=*(*(matriz+i+1)+j);
		    }
		    // mesma coisa que int *linha = *(matriz + i-1);
		    // no entanto, nao podemos redefinir o valor de linha
		    if(i-1>=0){
                numero_elementos++;
                soma += *(*(matriz+i-1)+j);
		    }
		    if(j+1<tamanho && i+1<tamanho){
		    	numero_elementos++;
                soma += *(*(matriz+i+1)+j+1);
		    }
		    if(j+1<tamanho && i-1>=0){
		    	numero_elementos++;
                soma += *(*(matriz+i-1)+j+1);
		    }
		    if(j-1>=0 && i+1<tamanho){
		    	numero_elementos++;
                soma += *(*(matriz+i+1)+j-1);
		    }
		    
		    if(j-1>=0 && i-1>=0){
		    	numero_elementos++;
                soma += *(*(matriz+i-1)+j-1);
		    }
		    

	        *(linha + j) = soma/numero_elementos;
            
        }
    }




    for (int i = 0; i < tamanho; i++) {
        int *linha = *(matriz + i);
        for (int j = 0; j < tamanho; j++) {
            cout<<*(linha + j)<<',';

        }
        cout<<'\n';
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
