# 

class Estacionamiento:
    def __init__(self):
        self.espacios = {
            'A': None,
            'B': None,
            'C': None,
            'D': None,
            'E': None
        }

    def registrar_entrada(self, matricula):
        for key in self.espacios:
            if self.espacios[key] is None:
                self.espacios[key] = matricula
                return f"Su vehículo ha sido registrado en el estacionamiento {key}."
        return "El estacionamiento está lleno, no hay espacios libres."

    def registrar_salida(self, matricula):
        for key in self.espacios:
            if self.espacios[key] == matricula:
                self.espacios[key] = None
                return f"Su vehículo ha salido del estacionamiento {key}."
        return "Error. Matrícula inválida. Escriba bien la matrícula del vehículo."

    def mostrar_estado(self):
        estado = [
            f"Estacionamiento {key}: {'Ocupado por vehículo con matrícula: ' + value if value else 'Libre'}"
            for key, value in self.espacios.items()
        ]
        return "\n".join(estado)

estacionamiento = Estacionamiento()
opciones = ['1', '2', '3', '4']  # Simulación de opciones predefinidas
datos = ["ABC123", "DEF456", "GHI789"]  # Simulación de matrículas
indice = 0

for opcion in opciones:
    if opcion == '1' and indice < len(datos):
        print(estacionamiento.registrar_entrada(datos[indice]))
        indice += 1
    elif opcion == '2' and indice > 0:
        print(estacionamiento.registrar_salida(datos[indice - 1]))
        indice -= 1
    elif opcion == '3':
        print(estacionamiento.mostrar_estado())
    elif opcion == '4':
        print("Saliendo del sistema...")
        break
