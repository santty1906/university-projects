#include <stdio.h>

int main() {
    int lavadoras = 0, microondas = 0, refrigeradores = 0;
    float precioLavadora = 300.0, precioMicroondas = 150.0, precioRefrigerador = 500.0;
    float totalLavadoras = 0, totalMicroondas = 0, totalRefrigeradores = 0;
    float totalDinero = 0;
    int producto, cantProducto, desicion;
    
    do {
        printf("***** Ejecución Iniciada. *****\n");
        printf("\n¿Cuantos productos se vendieron el dia de hoy?\n");
        scanf("%d", &cantProducto);
         // Simulación de ventas (250 ventas)
        for (int i = 1; i <= cantProducto; i++) {
            printf("Venta #%d - Ingresa el producto vendido (1 = Lavadora, 2 = Microondas, 3 = Refrigerador): ", i);
            scanf("%d", &producto);

            switch (producto) {
                case 1:
                    lavadoras++;
                    totalLavadoras += precioLavadora;
                    break;
                case 2:
                    microondas++;
                    totalMicroondas += precioMicroondas;
                    break;
                case 3:
                    refrigeradores++;
                    totalRefrigeradores += precioRefrigerador;
                    break;
                default:
                    printf("Producto no válido. Intente de nuevo.\n");
                    i--;  // Repetir esta venta si el producto no es válido
                    break;
        }

    }
        // Cálculo del total de dinero
        totalDinero = totalLavadoras + totalMicroondas + totalRefrigeradores;

        // Resultados finales
        printf("\nTotal de productos vendidos:\n");
        printf("Lavadoras: %d, Total vendido: $%.2f\n", lavadoras, totalLavadoras);
        printf("Microondas: %d, Total vendido: $%.2f\n", microondas, totalMicroondas);
        printf("Refrigeradores: %d, Total vendido: $%.2f\n", refrigeradores, totalRefrigeradores);
        printf("Total dinero recaudado: $%.2f\n", totalDinero);
        
        printf("Elija 1 para volver a usar el programa o 0 para salir");
        scanf("%d", &desicion);

    } while (desicion == 1);

    

    return 0;
}
