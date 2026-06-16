def r_l(l):
    minimo = min(l)
    maximo = max(l)
    promedio = sum(l) / len(l)
    return minimo, maximo, promedio
n = [12, 45, 7, 89, 34, 56, 23]
minimo, maximo, promedio = r_l(n)
print("Minimo:", minimo)
print("Maximo:", maximo)
print("Promedio:", promedio)