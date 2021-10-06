import string


class codigoCesar:
    def __init__(self):
        self.alfabeto = list(string.ascii_lowercase)

    def codificar(self, desplaz, fileOrigen, fileDestino):
        texto_cifrado = ""
        archivo = open(fileOrigen, 'r')
        caracter = archivo.read(1)

        while caracter != "":
            if caracter in self.alfabeto:
                indice_actual = self.alfabeto.index(caracter)
                indice_cesar = indice_actual + desplaz

                if indice_cesar > 25:
                    indice_cesar -= 26

                texto_cifrado += self.alfabeto[indice_cesar]
            else:
                texto_cifrado += caracter
            caracter = archivo.read(1)
        self.escritura(fileDestino, texto_cifrado)
        archivo.close()

    def decodificar(self, desplaz, fileOrigen, fileDestino):
        texto_decodificado = ""
        archivo = open(fileOrigen, 'r')
        caracter = archivo.read(1)

        while caracter != "":
            if caracter in self.alfabeto:
                indice_cesar = self.alfabeto.index(caracter)
                indice_original = indice_cesar - desplaz

                if indice_original < 0:
                    indice_original += 26
                texto_decodificado += self.alfabeto[indice_original]
            else:
                texto_decodificado += caracter
            caracter = archivo.read(1)

        self.escritura(fileDestino, texto_decodificado)
        archivo.close()

    def escritura(self, file, texto):
        archivo = open(file, 'w')
        archivo.write(texto)
        archivo.close()


conversor = codigoCesar()
finish = True

while finish:
    print("Buen dia al programa Codigo Cesar\n")
    print("Por favor escoge una de las opciones:")
    print("1. Codificar\n2. Descodificar\n3. Salir")
    opcion = int(input("Opcion: "))

    if opcion == 1:
        nombreOrigen = input("Ingrese el nombre del archivo a codificar: ")
        nombreDestino = input("Ingrese el nombre del archivo a escribir: ")
        nombreOrigen += ".txt"
        nombreDestino += ".txt"
        desplazamiento = int(input("De cuanto sera el desplazamiento?"))

        conversor.codificar(desplazamiento, nombreOrigen, nombreDestino)
    elif opcion == 2:
        nombreOrigen = input("Ingrese el nombre del archivo a descodificar: ")
        nombreDestino = input("Ingrese el nombre del archivo a escribir: ")
        nombreOrigen += ".txt"
        nombreDestino += ".txt"
        desplazamiento = int(input("De cuanto sera el desplazamiento?"))

        conversor.decodificar(desplazamiento, nombreOrigen, nombreDestino)
    elif opcion == 3:
        print("Gracias por usar el programa")
        finish = False
    else:
        print("No es una opcion valida")
