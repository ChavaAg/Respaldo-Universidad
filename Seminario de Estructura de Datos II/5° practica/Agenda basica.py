



def ingresarContacto():
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

    texto = ""
    texto += input("Ingresa el nombre: ") + "\n"
    texto += input("Ingresa el carrera: ") + "\n"
    texto += input("Ingresa el codigo: ") + "\n"
    texto += input("Ingresa el telefono: ") + "\n"

    archivo.write(texto)

    archivo.close()
    respaldo.close()

repeticion = True
while repeticion:
    print("Bienvenido al Directorio UdG\n")
    ingresarContacto()

    print("\nQuieres ingresar otro contcto?: 1: Si 2: No")
    texto = int(input("Opcion: "))
    if(texto == 2):
        repeticion = False

