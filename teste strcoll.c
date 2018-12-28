#include <stdio.h>
#include <stdlib.h>

int main(){
    char palavra1[10];
    char palavra2[10];
    
    int retorno;
    
    scanf("%s", &palavra1); scanf("%s", &palavra2);
    
    retorno = strcoll(palavra2, palavra1);
    if(retorno==0){
    	printf("São Iguais");
    }else if (retorno==1){
        printf("Palavra 2 maior que 1");
    }else{
        printf("Palavra 1 maior que 2");
    }
}
