colores_str = "rojo-verde-azul-amarillo"
x = colores_str.split("-")

print("paso 1: "+ str(x))

y=" | ".join(x)

print("Paso 2: " + str(y))

print("verde" in y)