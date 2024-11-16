#include <stdio.h>

    //Bloque declarativo de constante
    #define proyectos 3
    #define semanas 12
    #define maxTareas 100
    #define maxNombre 50

    //Espacio para las funciones

int main (){
    //Declaracion de variables
    int numTareas[i]
    char tareasNombresYEstado[i][j];

    char 
    int opcion = 0, i = 0;
    float

    do{
        //Menu de opciones
        printf("Menú de opciones: (Ingrese un número como opción)\n");
        printf("1. Ingresar datos de las tareas.\n");
        printf("2. Ingresar estado semanal de cada tarea.\n");
        printf("3. Mostrar total de tareas completadas por proyecto.\n");
        printf("4. Mostrar proyecto con mayor y menor porcentaje de tareas completadas.\n");
        printf("5. Mostrar porcentaje de progreso de cada proyecto.\n");
        printf("6. Salir.\n");
        printf("\nSeleccione una opción: ");
        scanf("%d", &opcion);

        //Si el usuario coloca un número distinto del que esta en el menu
        if (opcion < 1 || opcion > 6){
            printf("Error al escoger la opción, por favor verifique e introduzca el número nuevamente");

        //Si el usuario coloca un número coorecto del que esta en el menu
        }else{
            switch(opcion){
                case 1:{
                    
                    break;
                }

                case 2:{

                    break;
                }

                case 3:{

                    break;
                }

                case 4:{

                    break;
                }

                case 5:{

                    break;
                }
            }


        }
    
    //El codigo termine si se escoge la opcion de salir
    }while( opcion != 6);
    
    return 0;
}
