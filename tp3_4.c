#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; 
}typedef Producto;

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; 
}typedef Cliente;

void cargar1(Cliente *client, int cant1);
void mostrar1(Cliente *client, int cant1);
float precio(Producto *aux);
void liberarMem(Cliente *client, int cant1);

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

int main(){

int cant1;

printf("Ingrese la cantidad de clientes: ");
scanf("%d", &cant1);

if (cant1 <= 5)
{
    Cliente *client = malloc(sizeof(Cliente)*cant1);

    cargar1(client,cant1);

    mostrar1(client,cant1);

    liberarMem(client,cant1);
}else{
    printf("Solo se permiten 5 clientes por dia.");
}




return 0;
}

void cargar1(Cliente *client, int cant1){
    int k;
    char buffer[100];
    srand(time(NULL));
    for (int i = 0; i < cant1; i++)
    {
        client->ClienteID = i+1;
        fflush(stdin);
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        gets(buffer);
        
        client->NombreCliente = malloc(sizeof(char)*strlen(buffer)+1);

        strcpy(client->NombreCliente,buffer);

        client->CantidadProductosAPedir = rand()%5+1;

        client->Productos = malloc (sizeof(Producto)*client->CantidadProductosAPedir);

            //-------------------------------------------------------------

        for (int j = 0; j < client->CantidadProductosAPedir; j++)

        {
            client->Productos[j].ProductoID = j+1;
            client->Productos[j].Cantidad = rand()%(10+1);
            client->Productos[j].PrecioUnitario = 10+rand()%(100-10);
            k = rand()%6;
            client->Productos[j].TipoProducto = TiposProductos[k];
        }
        client++;
    }
}

void mostrar1(Cliente *client, int cant1){
    float precioFinal;
    for (int i = 0; i < cant1; i++){
        fflush(stdin);
        printf("======CLIENTE NRO :%d======\n", i+1);
        printf("Id del cliente: %d\n", client->ClienteID);
        printf("nombre del cliente: %s\n", client->NombreCliente);
        printf("Cantidad de productos: %d\n",client->CantidadProductosAPedir);
        printf("-Productos-\n");
        fflush(stdin);
        for (int j = 0; j < client->CantidadProductosAPedir; j++)
        {
            fflush(stdin);
            printf("-->Id del producto: %d\n", client->Productos->ProductoID);
            printf("-->Cantidad de producto: %d\n",client->Productos->Cantidad);
            printf("-->Tipo: %s\n",client->Productos->TipoProducto);
            printf("-->Precio: %.2f\n",client->Productos->PrecioUnitario);
            precioFinal += precio(client->Productos);
            puts("------------------");
            client->Productos++;
        }
        printf("Total: %.2f\n",precioFinal);
        client++;
    }
}

float precio(Producto *aux){
    float total;
    total = aux->PrecioUnitario * aux->Cantidad;
    return total;
}

void liberarMem(Cliente *client, int cant1){
    for (int i = 0; i < cant1; i++)
    {
        free(client->Productos);
        free(client->NombreCliente);
    }
    free(client); 
}