#include <stdio.h>
#include <string.h>
#define TAMANHO 201
void zerarArray(char stringZerada[])
{
    for (int i = 0; i < TAMANHO; ++i)
    {
        stringZerada[i] = 0;
    }
}
void inserirSimbolo(char stringLinha[],char simbolo, int quantidade)
{
    int y;
    zerarArray(stringLinha);
    for(y=0; y<quantidade; y++)
    {
        stringLinha[y]=simbolo;
    }
    printf("%s", stringLinha);
}
int main()
{
    FILE *fptrFilePointer;
    fptrFilePointer = fopen("gera-figura.txt","w");
    char stringFragmento[TAMANHO];
    int quantidade_linhas,x,quantidades_asterisco,quantidade_espacos;
    quantidades_asterisco =1;


    printf("Insira numero de linhas e pressione [Enter][MAX:100] ");
    scanf("%d",&quantidade_linhas);//printf("%d\n", i);
    quantidade_espacos = quantidade_linhas;
    for(x=0; x<quantidade_linhas; x++)
    {
        inserirSimbolo(stringFragmento,' ',quantidade_espacos);
        fputs(stringFragmento,fptrFilePointer);
        inserirSimbolo(stringFragmento,'*',quantidades_asterisco);
        fputs(stringFragmento,fptrFilePointer);
        fputs("\n",fptrFilePointer);
        printf("\n");
        quantidades_asterisco+=2;
        quantidade_espacos--;
    }
    quantidades_asterisco -=2;
    fclose(fptrFilePointer);
    return 0;
}
