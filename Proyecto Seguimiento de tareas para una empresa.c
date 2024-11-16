#include <stdio.h>




int main (){
    char 
    int opcion = 0, i = 0;
    float

    do{

        printf("Menú de opciones: (Ingrese un número como opción)\n");
        printf("1. Ingresar datos de las tareas.\n");
        printf("2. Ingresar estado semanal de cada tarea.\n");
        printf("3. Mostrar total de tareas completadas por proyecto.\n");
        printf("4. Mostrar proyecto con mayor y menor porcentaje de tareas completadas.\n");
        printf("5. Mostrar porcentaje de progreso de cada proyecto.\n");
        printf("6. Salir.\n");
        printf("\nSeleccione una opción: ");
        scanf("%d", &opcion);
        
        if (opcion < 1 || opcion > 6){
            printf("Error al escoger la opción, por favor verifique e introduzca el número nuevamente");
        
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
    
    
    }while( opcion != 6);
    
    return 0;
}
