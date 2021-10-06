
class Pila:
    def __init__(self):
        self.lista = list()
        self.tamano = -1

    def push(self,valor):
        self.lista.append(valor)
        self.tamano += 1
    def pop(self):
        if self.tamano != -1:
            valor = self.lista.pop()
            print("El valor eliminado es: ", valor)
            self.tamano -= 1
        else:
            print("La pila esta vacia")
    def top(self):
        if self.tamano != -1:
            print("El ultimo elemento insertado es: ", self.lista[self.tamano])
        else:
            print("La pila esta vacia")
    def imprimir(self):
        if self.tamano != -1:
            print("\nDatos dentro de la pila:\n")
            for datos in self.lista:
                print(datos)
        else:
            print("La pila esta vacia")

print("Se creo la pila")
pila = Pila()

print("\nSe inserto el valor de 100")
pila.push(100)
print("Se inserto el valor de 80")
pila.push(80)
print("Se inserto el valor de 30")
pila.push(30)
print("Se inserto el valor de 2")
pila.push(2)
print("\nSe muestra el ultimo en insertarse")
pila.top()
print("\nSe  sacan 3 datos")
pila.pop()
pila.pop()
pila.pop()
print("\nSe muestra el ultimo en insertarse")
pila.top()
