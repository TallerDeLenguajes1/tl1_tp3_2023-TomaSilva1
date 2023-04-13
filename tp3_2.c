#include <stdio.h>
#include <stdlib.h>


//void cargar(int **mes, float *prom);
void mostrar(int **mes, float *prom);


int main(){

int **mes = malloc(5*sizeof(int*));
float prom[5];
int alto=0, anioA, mesA;

for (int i = 0; i < 5; i++)
    {
        mes[i]= malloc(3*sizeof(int));
        for (int j = 0; j < 3; j++)
        {
            mes[i][j]= 10000+rand()%(50000-10000);
            prom[i]+= mes[i][j];

            if (mes[i][j] > alto)
            {
                alto = mes[i][j];
                anioA = i+1;
                mesA = j+1;
            }
        }  
    }

mostrar(mes, prom);

printf("anio de mayor ganancia: %d\n", anioA);
printf("Mes de mayor ganancia: %d\n", mesA);
printf("Monto : %d\n", alto);

return 0;
}

void mostrar(int **mes, float *prom){
    for (int i = 0; i < 5; i++)
    {
        printf("========ANIO NRO: %d========\n", i+1);
        for (int j = 0; j < 3; j++)
        {
            printf("Ganancia del mes %d --> %d\n", j+1,mes[i][j]);
        }
        printf("Promedio de este anio: %.2f\n", prom[i]/3);
    }
}