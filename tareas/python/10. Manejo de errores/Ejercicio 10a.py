def entero(n):
    try:
        resultado = int(n)
        return resultado
    except ValueError:
        print("Error: No se puede convertir a entero")
        return None
    finally:
        print(f"[intento con: {n}]")
print(entero("42"))
print(entero("3.14"))
print(entero("hola"))
print(entero(100))