#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void cargar(char **nom);
void mostrar(char **nom);

int main(){

char **nom = malloc(sizeof(char)*5);



fflush(stdin);
cargar(nom);
fflush(stdin);
mostrar(nom);

return 0;
}

void cargar(char **nom){
    for (int i = 0; i < 5; i++)
    {
        nom[i]=malloc(sizeof(char)*20);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nom[i]);
    }
}

void mostrar(char **nom){
    for (int i = 0; i < 5; i++)
    {
       printf("Nombre: %s\n", nom[i]);
    }
}