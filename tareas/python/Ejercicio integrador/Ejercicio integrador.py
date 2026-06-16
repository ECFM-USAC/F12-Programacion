def a(e):
    aprobados = 0
    reprobados = 0
    print(f"{'Nombre':<15} {'Promedio':<10} {'Estado'}")
    for alumno in e:
        nombre = alumno["nombre"]
        n = alumno["notas"]
        if n:
            p = sum(n) / len(n)
        else:
            p = None
        if p is None:
            estado = "Sin notas"
        elif p >= 61:
            estado = "Aprobado"
            aprobados += 1
        else:
            estado = "Reprobado"
            reprobados += 1
        p_str = f"{p:.2f}" if p is not None else "N/A"
        print(f"{nombre:<15} {p_str:<10} {estado}")
    print(f"Aprobados: {aprobados}")
    print(f"Reprobados: {reprobados}")
c = [
    {"nombre": "Ana Lopez",    "notas": [85, 90, 78, 92]},
    {"nombre": "Carlos Ruiz",  "notas": [55, 48, 60, 52]},
    {"nombre": "Maria Paz",    "notas": [70, 75, 68, 80]},
    {"nombre": "Luis Gomez",   "notas": [95, 98, 100, 92]},
    {"nombre": "Sara Diaz",    "notas": [40, 55, 50, 45]},
    {"nombre": "Pedro Alva",   "notas": []},
]
a(c)