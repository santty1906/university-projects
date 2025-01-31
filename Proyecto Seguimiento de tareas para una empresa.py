# Ejemplo de proyecto de seguimientos de tareas para una empresa pero en lenguaje Python, trabaje solo las funciones y coloque datos predeterminados para que se viera el ejemplo de como queda en lenguaje Python

PROYECTOS = 3
SEMANAS = 12

# Inicialización de datos
nombres_proyectos = ["Alpha", "Beta", "Gamma"]
tareas_por_proyecto = [[] for _ in range(PROYECTOS)]
estados_tareas = [[] for _ in range(PROYECTOS)]

def ingresar_datos():
    for i in range(PROYECTOS):
        num_tareas = 2  # Valor predefinido para pruebas
        for j in range(num_tareas):
            num_tarea = j + 1
            nombre_tarea = f"Tarea {num_tarea}"
            tareas_por_proyecto[i].append((num_tarea, nombre_tarea))
            estados_tareas[i].append([0] * SEMANAS)

def ingresar_estado_semanal():
    for i in range(PROYECTOS):
        for j in range(len(tareas_por_proyecto[i])):
            completada = False
            for semana in range(SEMANAS):
                if not completada:
                    estado = (semana % 3)  # Alternar entre 0, 1, 2
                    estados_tareas[i][j][semana] = estado
                    if estado == 2:
                        completada = True
                else:
                    estados_tareas[i][j][semana] = 2

def mostrar_tareas_completas():
    for i in range(PROYECTOS):
        completadas = sum(1 for j in range(len(tareas_por_proyecto[i])) if estados_tareas[i][j][-1] == 2)
        print(f"\nProyecto {nombres_proyectos[i]} tiene {completadas} tareas completadas.")

def mostrar_mayor_menor_porcentaje():
    porcentajes = []
    for i in range(PROYECTOS):
        total = len(tareas_por_proyecto[i])
        completadas = sum(1 for j in range(total) if estados_tareas[i][j][-1] == 2)
        porcentaje = (completadas / total * 100) if total > 0 else 0
        porcentajes.append((porcentaje, nombres_proyectos[i]))
    if porcentajes:
        mayor = max(porcentajes)
        menor = min(porcentajes)
        print(f"\nProyecto con mayor porcentaje completado: {mayor[1]} ({mayor[0]:.2f}%)")
        print(f"Proyecto con menor porcentaje completado: {menor[1]} ({menor[0]:.2f}%)")

def mostrar_porcentaje_progreso():
    for i in range(PROYECTOS):
        total = len(tareas_por_proyecto[i])
        completadas = sum(1 for j in range(total) if estados_tareas[i][j][-1] == 2)
        porcentaje = (completadas / total * 100) if total > 0 else 0
        print(f"\nProyecto {nombres_proyectos[i]} tiene un progreso de {porcentaje:.2f}%.")

def main():
    ingresar_datos()
    ingresar_estado_semanal()
    mostrar_tareas_completas()
    mostrar_mayor_menor_porcentaje()
    mostrar_porcentaje_progreso()


