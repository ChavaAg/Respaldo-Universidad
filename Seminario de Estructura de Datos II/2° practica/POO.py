class Numero:
    def __init__(self, vr1, vi1, vr2, vi2):
        self.vr1 = vr1
        self.vi1 = vi1
        self.vr2 = vr2
        self.vi2 = vi2
        self.resultR = 0
        self.resultI = 0

    def imprimir(self):

        if self.resultI == 0 and self.resultR == 0:
            print("0")

        elif self.resultI == -1:
            if self.resultR == 0:
                print("-i")
            else:
                print(self.resultR, "-i")
        elif self.resultI == 0:
            print(self.resultR)

        else:
            if self.resultI >= 1:
                print(self.resultR,"+", self.resultI, "i")
            else:
                self.resultI = self.resultI * -1
                print(self.resultR, "-", self.resultI, "i")

    def suma(self):
        self.resultR = self.vr1 + self.vr2
        self.resultI = self.vi1 + self.vi2

    def resta(self):
        self.resultR = self.vr1 - self.vr2
        self.resultI = self.vi1 - self.vi2

    def multiplicacion(self):
        self.resultR = (self.vr1 * self.vr2) + ((self.vi1*self.vi2)*-1)
        self.resultI = (self.vr1*self.vi2) + (self.vi1*self.vr2)


print("Bienvenido a la calculadora casera")
print("Primera operacion")
v1 = int(input("Por favor ingrese el numero real: "))
v2 = int(input("Por favor ingrese el numero imaginario: "))
print("Segunda operacion")
v3 = int(input("Por favor ingrese el numero real: "))
v4 = int(input("Por favor ingrese el numero imaginario: "))

calculadora = Numero(v1, v2, v3, v4)
calculadora.suma()
print("Suma")
calculadora.imprimir()
calculadora.resta()
print("Resta")
calculadora.imprimir()
calculadora.multiplicacion()
print("Multiplicacion")
calculadora.imprimir()