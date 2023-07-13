#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTO 100
#define MAX_NOMBRE 30

void Agregar_Producto(int inventario[MAX_PRODUCTO][4], int* num_producto);
void Mostrar_todos_los_productos(int inventario[MAX_PRODUCTO][4], int num_producto);
void Actualizar_Productos(int inventario[MAX_PRODUCTO][4], int num_producto);
void Eliminar_Productos(int inventario[MAX_PRODUCTO][4], int* num_producto);
void Salir_del_Programa(int inventario[MAX_PRODUCTO][4], int num_producto);

int main()
{
    int opcion;
    int num_producto = 0;
    int inventario[MAX_PRODUCTO][4];

    do
    {
        printf("\n\n=== Menu Principal ===\n\n");
        printf("1- Ver Productos\n");
        printf("2- Ingresar Producto\n");
        printf("3- Modificar producto por ID\n");
        printf("4- Eliminar Producto\n");
        printf("5- Salir\n\n");

        printf("Ingrese su eleccion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                Mostrar_todos_los_productos(inventario, num_producto);
                break;
            case 2:
                Agregar_Producto(inventario, &num_producto);
                break;
            case 3:
                Actualizar_Productos(inventario, num_producto);
                break;
            case 4:
                Eliminar_Productos(inventario, &num_producto);
                break;
            case 5:
                Salir_del_Programa(inventario, num_producto);
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

void Agregar_Producto(int inventario[MAX_PRODUCTO][4], int* num_producto)
{
    if (*num_producto < MAX_PRODUCTO)
    {
        printf("\nIngrese el ID del producto: ");
        scanf("%d", &(inventario[*num_producto][0]));
        printf("Ingrese el nombre del producto: ");
        scanf("%s", &(inventario[*num_producto][1]));
        printf("Ingrese la cantidad del producto: ");
        scanf("%d", &(inventario[*num_producto][2]));
        printf("Ingrese el precio del producto: ");
        scanf("%f", (float*)&(inventario[*num_producto][3]));

        (*num_producto)++;

        printf("\n\nEl producto se agrego correctamente.");
    }
    else
    {
        printf("No hay espacio en el inventario");
    }
}

void Mostrar_todos_los_productos(int inventario[MAX_PRODUCTO][4], int num_producto)
{
    if (num_producto > 0)
    {
        printf("\nLista de productos\n");

        for (int i = 0; i < num_producto; i++)
        {
            printf("\nProducto %d: \n", i + 1);
            printf("ID: %d\n", inventario[i][0]);
            printf("Nombre: %s\n", inventario[i] + 1);
            printf("Cantidad: %d\n", inventario[i][2]);
            printf("Precio: %.2f\n", *((float*)(inventario[i] + 3)));
        }
    }
    else
    {
        printf("\nNo hay ningun producto en el inventario.");
    }
}

void Actualizar_Productos(int inventario[MAX_PRODUCTO][4], int num_producto)
{
    int ID;
    int encontrar = -1;

    printf("\nIngrese el ID del producto: ");
    scanf("%d", &ID);

    for (int i = 0; i < num_producto; i++)
    {
        if (inventario[i][0] == ID)
        {
            encontrar = i;
            break;
        }
    }

    if (encontrar != -1)
    {
        printf("\nIngrese el nuevo nombre del producto: ");
        scanf("%s", &(inventario[encontrar][1]));
        printf("Ingrese la nueva cantidad del producto: ");
        scanf("%d", &(inventario[encontrar][2]));
        printf("Ingrese el nuevo precio del producto: ");
        scanf("%f", (float*)&(inventario[encontrar][3]));

        printf("\nProducto actualizado correctamente.");
    }
    else
    {
        printf("\nNo existe un producto con ese ID.");
    }
}

void Eliminar_Productos(int inventario[MAX_PRODUCTO][4], int* num_producto)
{
    int ID;
    int encontrar = -1;

    printf("Ingrese el ID del producto que desea eliminar: ");
    scanf("%d", &ID);

    for (int i = 0; i < *num_producto; i++)
    {
        if (inventario[i][0] == ID)
        {
            encontrar = i;
            break;
        }
    }

    if (encontrar != -1)
    {
        for (int i = encontrar; i < *num_producto - 1; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                inventario[i][j] = inventario[i + 1][j];
            }
        }

        (*num_producto)--;
        printf("\nProducto eliminado correctamente.");
    }
    else
    {
        printf("\nNo existe un producto con ese ID.");
    }
}

void Salir_del_Programa(int inventario[MAX_PRODUCTO][4], int num_producto)
{
    printf("Gracias por usar el sistema de inventario.");
}
