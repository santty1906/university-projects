//Proeyecto seguimiento de tareas para una empresa

#include <stdio.h>
// Declaración de constantes.
#define PROYECTOS 3
#define SEMANAS 12
#define MAXTAREAS 100
#define MAXNOMBRE 50

// Declaración de funciones.
// Función para ingresar datos de las tareas.
void ingresarDatos(int numTareas[], int numerosTareas[], char nombresTareas[][MAXNOMBRE], char nombresProyectos[][MAXNOMBRE]) {
	for (int i = 0; i < PROYECTOS; i=i+1) { //Se repetira por cada proyecto que en este caso son 3.
		printf("\nProyecto %s:\n", nombresProyectos[i]); // Se mostrara en pantalla cada proyecto.
		printf("Ingrese el número de tareas para este proyecto: "); // Ingreso del número de tareas.
		scanf("%d", &numTareas[i]);
		
		for (int j = 0; j < numTareas[i]; j=j+1) {
			int indice = i * MAXTAREAS + j; // Índice único para cada tarea
			printf("\nIngrese el número de la tarea %d: ", j + 1);
			scanf("%d", &numerosTareas[indice]);
			
			printf("Ingrese el nombre de la tarea %d: ", j + 1);
			scanf(" %[^\n]", nombresTareas[indice]);
		}
	}
}

// Función que evalúa el estado semanal de las tareas durante 12 semanas.
void ingresarEstadoSemanal(int numTareas[], int estadoTareas[], char nombresTareas[][MAXNOMBRE], char nombresProyectos[][MAXNOMBRE]){
	for (int i = 0; i < PROYECTOS; i++) {
		printf("\nProyecto %s:\n", nombresProyectos[i]);
		if (numTareas[i] == 0) { //Verificar si el proyecto no tiene tareas.
			printf("El Proyecto %s no tiene tareas registradas.\n", nombresProyectos[i]);
		} else {
			for (int j = 0; j < numTareas[i]; j++) {
				printf("\nIngresando estado semanal para la tarea '%s':\n", nombresTareas[i * MAXTAREAS + j]);
				int completada = 0;
				
				for (int semana = 0; semana < SEMANAS; semana++) {
					int indice = i * MAXTAREAS * SEMANAS + j * SEMANAS + semana; // Calcular índice único para el arreglo unidimensional
					
					if (completada == 0) {
						printf("- Semana %d (0 = pendiente, 1 = en progreso, 2 = completada): ", semana + 1);
						int estado;
						scanf("%d", &estado);
						
                        // Validar selección del estado, si el número es incorrecto se repite.
						while (estado < 0 || estado > 2) {
							printf("Estado inválido. Por favor, ingrese un número entre 0 y 2: ");
							scanf("%d", &estado);
						}
						
						estadoTareas[indice] = estado; // Acceder al arreglo unidimensional
						if (estado == 2) {
							completada = 1;
						}
					} else { // Si la tarea ya está completada, marcar automáticamente las semanas restantes.
						estadoTareas[indice] = 2;
						printf("- Semana %d: completada automáticamente para la tarea '%s'.\n",
							   semana + 1, nombresTareas[i * MAXTAREAS + j]);
					}
				}
			}
		}
	}
}

// Función para mostrar las tareas completadas.
void mostrarTareasCompletas(int numTareas[], int estadosTareas[], char nombresProyectos[][MAXNOMBRE]) {
	for (int i = 0; i < PROYECTOS; i++) {
		int completadas = 0;
		
		if (numTareas[i] == 0) { //Verificar si el proyecto no tiene tareas.
			printf("\nProyecto %s no tiene tareas registradas.\n", nombresProyectos[i]);
		} else {
			for (int j = 0; j < numTareas[i]; j++) {
				int indice = i * MAXTAREAS + j;
				if (estadosTareas[indice * SEMANAS + (SEMANAS - 1)] == 2) {
					completadas++;
				}
			}
			printf("\nProyecto %s tiene %d tareas completadas.\n", nombresProyectos[i], completadas);
		}
	}
}

// Función para mostrar proyecto con mayor y menor porcentaje de tareas completadas.
void mostrarMayorMenorPorcentaje(int numTareas[], int estadosTareas[], char nombresProyectos[][MAXNOMBRE]) {
	int mayor = -1, menor = -1;
	float mayorPorcentaje = 0.0, menorPorcentaje = 100.0;
	
	for (int i = 0; i < PROYECTOS; i++) {
		if (numTareas[i] == 0) { //Verificar si el proyecto no tiene tareas.
			printf("\nProyecto %s no tiene tareas registradas.\n", nombresProyectos[i]);
		} else {
			int completadas = 0;
			
			for (int j = 0; j < numTareas[i]; j++) {
				int indice = i * MAXTAREAS + j;
				if (estadosTareas[indice * SEMANAS + (SEMANAS - 1)] == 2) {
					completadas++;
				}
			}
			
			float porcentaje = completadas / numTareas[i] * 100;
			
			if (porcentaje > mayorPorcentaje) {
				mayorPorcentaje = porcentaje;
				mayor = i;
			}
			if (porcentaje < menorPorcentaje) {
				menorPorcentaje = porcentaje;
				menor = i;
			}
		}
	}
	
	if (mayor != -1) {
		printf("\nProyecto con mayor porcentaje completado: %s (%.2f%%)\n", nombresProyectos[mayor], mayorPorcentaje);
	}
	if (menor != -1) {
		printf("Proyecto con menor porcentaje completado: %s (%.2f%%)\n", nombresProyectos[menor], menorPorcentaje);
	}
}


// Función para mostrar porcentaje de progreso de cada proyecto.
void mostrarPorcentajeProgreso(int numTareas[], int estadosTareas[], char nombresProyectos[][MAXNOMBRE]) {
	for (int i = 0; i < PROYECTOS; i++) {
		if (numTareas[i] == 0) { //Verificar si el proyecto no tiene tareas.
			printf("\nProyecto %s no tiene tareas registradas.\n", nombresProyectos[i]);
		} else {
			int completadas = 0;
			
			for (int j = 0; j < numTareas[i]; j++) {
				int indice = i * MAXTAREAS + j;
				if (estadosTareas[indice * SEMANAS + (SEMANAS - 1)] == 2) {
					completadas++;
				}
			}
			
			float porcentaje = completadas / numTareas[i] * 100;
			printf("\nProyecto %s tiene un progreso de %.2f%%.\n", nombresProyectos[i], porcentaje);
		}
	}
}

int main() {
	// Declaración de arreglos.
    int numTareas[PROYECTOS] = {0};
	int numerosTareas[PROYECTOS * MAXTAREAS];
	char nombresTareas[PROYECTOS * MAXTAREAS][MAXNOMBRE];
	char nombresProyectos[PROYECTOS][MAXNOMBRE] = {"Alpha", "Beta", "Gamma"};
	int estadosTareas[PROYECTOS * MAXTAREAS * SEMANAS] = {0};
 
    // Declaración de variable
    int opcion;
    //Menú de opciones
	do {
		printf("\nMenú de opciones: (Ingrese un número como opción)\n");
		printf("1. Ingresar datos de las tareas.\n");
		printf("2. Ingresar estado semanal de cada tarea.\n");
		printf("3. Mostrar total de tareas completadas por proyecto.\n");
		printf("4. Mostrar proyecto con mayor y menor porcentaje de tareas completadas.\n");
		printf("5. Mostrar porcentaje de progreso de cada proyecto.\n");
		printf("6. Salir.\n");
		printf("Seleccione una opción: ");
		scanf("%d", &opcion);
		
		if (opcion < 1 || opcion > 6) {
			printf("Error al escoger la opción, por favor verifique e introduzca el número nuevamente.\n");
		} else {
			switch (opcion) {
			case 1:
				ingresarDatos(numTareas, numerosTareas, nombresTareas, nombresProyectos);
				break;
			case 2:
				ingresarEstadoSemanal(numTareas, estadosTareas, nombresTareas, nombresProyectos);				
				break;
			case 3:
				mostrarTareasCompletas(numTareas, estadosTareas, nombresProyectos);
				break;
			case 4:
				mostrarMayorMenorPorcentaje(numTareas, estadosTareas, nombresProyectos);
				break;
			case 5:
				mostrarPorcentajeProgreso(numTareas, estadosTareas, nombresProyectos);
				break;
			}
		}
	} while (opcion != 6);
	
	return 0;
}
