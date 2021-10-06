class Entrada:
    def __init__(self):
        self.nombre = ""
        self.apellido = ""
        self.codigo = ""
        self.carrera = ""

    def leer_entrada(self):
        self.nombre = input("Ingresa el nombre: ")
        self.apellido = input("Ingresa el apellido: ")
        self.codigo = input("Ingresa el codigo: ")
        self.carrera = input("Ingresa el carrera: ")

class Menu:
    def __init__(self):
        self.agenda = Agenda()

    def inicio(self, op):
        terminar = True
        if op == 1:
            self.agenda.anadirRegistro()
        elif op == 2:
            self.agenda.borrarRegistro()
        elif op == 3:
            self.agenda.buscarCodigo()
        elif op == 4:
            self.agenda.buscarNombre()
        elif op == 5:
            self.agenda.guardarAgenda()
        elif op == 6:
            self.agenda.cargarAgenda()
        elif op == 7:
            terminar = False
        return terminar

class Agenda:
    def anadirRegistro(self):
        registro = Entrada()
        registro.leer_entrada()

        archivo = open("Agendario.txt", 'a')

        archivo.write(registro.nombre + "\n" + registro.apellido + "\n" + registro.codigo + "\n"
                      + registro.carrera + "\n")

        archivo.close()

    def borrarRegistro(self):
        alumnoBorrar = input("Ingresa el codigo del alumno a borrar: ")

        archivo = open("Agendario.txt", 'r')
        respaldo = open("Respaldo.txt", 'w')

        texto = archivo.read()
        respaldo.write(texto)

        archivo.close()
        respaldo.close()

        respaldo = open("Respaldo.txt", 'r')
        archivo = open("Agendario.txt", 'w')
        indice = 1

        for alumnos in respaldo:
            if indice == 1:
                nombre = alumnos.strip('\n')
                indice = 2

            elif indice == 2:
                apellido = alumnos.strip('\n')
                indice = 3

            elif indice == 3:
                codigo = alumnos.strip('\n')
                indice = 4

            elif indice == 4:
                carrera = alumnos.strip('\n')
                indice = 1
                if codigo != alumnoBorrar:
                    archivo.write(nombre + "\n" + apellido + "\n" + codigo + "\n" + carrera + "\n")
        archivo.close()
        respaldo.close()

    def buscarCodigo(self):
        registro = Entrada()
        codigoBuscar = input("ingresa el codigo  buscar: ")
        indice = 1

        archivo = open("Agendario.txt", 'r')
        for alumnos in archivo:
            if indice == 1:
                registro.nombre = alumnos.strip('\n')
                indice = 2

            elif indice == 2:
                registro.apellido = alumnos.strip('\n')
                indice = 3

            elif indice == 3:
                registro.codigo = alumnos.strip('\n')
                indice = 4

            elif indice == 4:
                registro.carrera = alumnos.strip('\n')

                if registro.codigo == codigoBuscar:
                    print("\n##############################")
                    print("Nombre: ", registro.nombre)
                    print("Apellido: ", registro.apellido)
                    print("Codigo: ", registro.codigo)
                    print("Carrera: ", registro.carrera)
                indice = 1
        archivo.close()

    def buscarNombre(self):
        registro = Entrada()
        nombre = input("ingresa el nombre buscar: ")
        apellido = input("ingresa el apellido buscar: ")
        indice = 1

        archivo = open("Agendario.txt", 'r')
        for alumnos in archivo:
            if indice == 1:
                registro.nombre = alumnos.strip('\n')
                indice = 2

            elif indice == 2:
                registro.apellido = alumnos.strip('\n')
                indice = 3

            elif indice == 3:
                registro.codigo = alumnos.strip('\n')
                indice = 4

            elif indice == 4:
                registro.carrera = alumnos.strip('\n')

                if registro.nombre == nombre and registro.apellido == apellido:
                    print("\n##############################")
                    print("Nombre: ", registro.nombre)
                    print("Apellido: ", registro.apellido)
                    print("Codigo: ", registro.codigo)
                    print("Carrera: ", registro.carrera)
                indice = 1
        archivo.close()

    def guardarAgenda(self):
        archivo = open("Agendario.txt", 'r')
        respaldo = open("Respaldo.txt", 'w')

        texto = archivo.read()
        respaldo.write(texto)

        archivo.close()
        respaldo.close()

        respaldo = open("Respaldo.txt", 'r')
        archivo = open("Agendario.txt", 'w')

        texto = respaldo.read()

        archivo.write(texto)

        archivo.close()
        respaldo.close()

    def cargarAgenda(self):
        registro = Entrada()
        indice = 1

        archivo = open("Agendario.txt", 'r')
        for alumnos in archivo:
            if indice == 1:
                registro.nombre = alumnos.strip('\n')
                indice = 2

            elif indice == 2:
                registro.apellido = alumnos.strip('\n')
                indice = 3

            elif indice == 3:
                registro.codigo = alumnos.strip('\n')
                indice = 4

            elif indice == 4:
                registro.carrera = alumnos.strip('\n')
                indice = 1
                print("\n##############################")
                print("Nombre: ", registro.nombre)
                print("Apellido: ", registro.apellido)
                print("Codigo: ", registro.codigo)
                print("Carrera: ", registro.carrera)
        archivo.close()


menus = Menu()
finish = True
while(finish):
    print("Bienvenido a la agenda UdG\n")
    print("Elige la opcion que desea realizar:")
    print("1. Insertar alumno")
    print("2. Borrar alumno")
    print("3. Buscar alumno por codigo")
    print("4. Buscar alumno por nombre")
    print("5. Guardar agenda")
    print("6. Cargar agenda")
    print("7. Salir")
    op = int(input("Opcion: "))
    finish = menus.inicio(op)