import string

class codigoCesar:
    def __init__(self):
        self.alfabeto = list(string.ascii_lowercase)

    def codificar(self, desplaz, fileOrigen):
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

        archivo.close()

        return texto_cifrado



conversor = codigoCesar()

print("Buen dia al programa Codigo Cesar\n")
nombreOrigen = input("Ingrese el nombre del archivo a codificar: ")
nombreOrigen += ".txt"
desplazamiento = int(input("Ingresa el numero del desplazamiento: "))

print("----Texto cifrado----")
print(conversor.codificar(desplazamiento, nombreOrigen))
