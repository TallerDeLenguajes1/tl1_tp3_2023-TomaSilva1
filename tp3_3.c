#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void cargar(char **nom, int cant);
void mostrar(char **nom, int cant);
void liberarMem(char **nom, int cant);

int main(){
int cant;

printf("Ingrese la cantidad de nombre que quiere ingresar: ");
scanf("%d",&cant);


char **nom = malloc(sizeof(char)*cant);



fflush(stdin);
cargar(nom,cant);
fflush(stdin);
mostrar(nom,cant);
liberarMem(nom,cant);


return 0;
}

void cargar(char **nom, int cant){
    for (int i = 0; i < cant; i++)
    {
        nom[i]=malloc(sizeof(char)*20);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nom[i]);
    }
}

void mostrar(char **nom, int cant){
    for (int i = 0; i < cant; i++)
    {
       printf("Nombre: %s\n", nom[i]);
    }
}

void liberarMem(char **nom, int cant){
    for (int i = 0; i < cant; i++)
    {
        free(nom[i]);
    }
    free(nom);
}