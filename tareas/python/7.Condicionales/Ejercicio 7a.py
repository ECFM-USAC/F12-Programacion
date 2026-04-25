def clasificar_imc(imc):
    if imc<=18:
        return "Bajo peso"
    elif 19<=imc<=25 :
        return "Normal"
    elif 26<=imc<=29:
        return "Sobrepeso"
    elif 30<=imc:
        return "Obesidad"
try:
    imc_usuario = float(input("Ingresa tu IMC: "))
    resultado = clasificar_imc(imc_usuario)
    print(f"Clasificacion: {resultado}")
except ValueError:
    print("Ingresa un número valido.")