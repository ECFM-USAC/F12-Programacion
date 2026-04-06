"""
introduccion_python.py — Ejemplos básicos de Python
=====================================================
Este script cubre los fundamentos del lenguaje Python:

    1. Hola Mundo y print()
    2. Variables y tipos de datos
    3. Operaciones aritméticas
    4. Strings y métodos útiles
    5. Listas y sus operaciones
    6. Diccionarios
    7. Condicionales (if / elif / else)
    8. Ciclos (for / while)
    9. Funciones
   10. Manejo de errores (try / except)

Cómo ejecutar:
    python introduccion_python.py
    o
    conda run -n base python introduccion_python.py
"""

# ═══════════════════════════════════════════════════════════════════════════════
# 1. HOLA MUNDO
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("1. HOLA MUNDO")
print("=" * 55)

print("¡Hola, Mundo!")
print("Bienvenidos a Python")

# print() puede recibir varios argumentos separados por comas
print("Nombre:", "Python", "— Versión:", 3)

# end="" cambia el salto de línea al final
print("Sin salto de línea", end=" ")
print("← aquí continúa")
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 2. VARIABLES Y TIPOS DE DATOS
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("2. VARIABLES Y TIPOS DE DATOS")
print("=" * 55)

# Python es de tipado dinámico: no necesitas declarar el tipo
entero   = 42
decimal  = 3.14159
texto    = "Hola Python"
booleano = True
nulo     = None

print("Entero  :", entero,   "→ tipo:", type(entero).__name__)
print("Decimal :", decimal,  "→ tipo:", type(decimal).__name__)
print("Texto   :", texto,    "→ tipo:", type(texto).__name__)
print("Booleano:", booleano, "→ tipo:", type(booleano).__name__)
print("Nulo    :", nulo,     "→ tipo:", type(nulo).__name__)

# Múltiple asignación en una sola línea
a, b, c = 1, 2, 3
print(f"\nMúltiple asignación: a={a}, b={b}, c={c}")
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 3. OPERACIONES ARITMÉTICAS
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("3. OPERACIONES ARITMÉTICAS")
print("=" * 55)

x, y = 17, 5

print(f"{x} + {y}  = {x + y}")      # suma
print(f"{x} - {y}  = {x - y}")      # resta
print(f"{x} * {y}  = {x * y}")      # multiplicación
print(f"{x} / {y}  = {x / y}")      # división real (siempre float)
print(f"{x} // {y} = {x // y}")     # división entera (floor)
print(f"{x} % {y}  = {x % y}")      # módulo (residuo)
print(f"{x} ** {y} = {x ** y}")     # potencia

# Funciones matemáticas con el módulo math
import math
print(f"\nsqrt(16)   = {math.sqrt(16)}")
print(f"pi         = {math.pi:.5f}")
print(f"ceil(3.2)  = {math.ceil(3.2)}")
print(f"floor(3.9) = {math.floor(3.9)}")
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 4. STRINGS Y MÉTODOS ÚTILES
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("4. STRINGS Y MÉTODOS ÚTILES")
print("=" * 55)

nombre = "  Python Básico  "

print(f"Original       : '{nombre}'")
print(f"strip()        : '{nombre.strip()}'")        # quita espacios extremos
print(f"upper()        : '{nombre.strip().upper()}'") # a mayúsculas
print(f"lower()        : '{nombre.strip().lower()}'") # a minúsculas
print(f"replace()      : '{nombre.strip().replace('Básico', 'Avanzado')}'")
print(f"len()          : {len(nombre.strip())}")     # longitud

# f-strings: forma moderna de formatear cadenas
lenguaje = "Python"
version  = 3.12
print(f"\nf-string: Hoy usamos {lenguaje} {version}")

# split y join
frase = "hola,mundo,python,es,genial"
palabras = frase.split(",")
print(f"split(',')     : {palabras}")
print(f"join(' ')      : {' '.join(palabras)}")

# Verificar contenido
print(f"\n'Python' in frase : {'Python' in frase}")
print(f"frase.startswith  : {frase.startswith('hola')}")
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 5. LISTAS
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("5. LISTAS")
print("=" * 55)

# Las listas son mutables y pueden contener tipos mixtos
frutas = ["manzana", "naranja", "uva", "mango"]

print("Lista original :", frutas)
print("Índice 0       :", frutas[0])          # primer elemento
print("Índice -1      :", frutas[-1])         # último elemento
print("Slice [1:3]    :", frutas[1:3])        # sub-lista

# Modificar
frutas.append("pera")                         # agregar al final
frutas.insert(1, "kiwi")                      # insertar en posición
print("\nDespués de append y insert:", frutas)

frutas.remove("uva")                          # eliminar por valor
eliminado = frutas.pop()                      # eliminar y obtener el último
print(f"Después de remove y pop (eliminado='{eliminado}'):", frutas)

# Operaciones útiles
numeros = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3]
print(f"\nNúmeros   : {numeros}")
print(f"len()     : {len(numeros)}")
print(f"min()     : {min(numeros)}")
print(f"max()     : {max(numeros)}")
print(f"sum()     : {sum(numeros)}")
print(f"sorted()  : {sorted(numeros)}")
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 6. DICCIONARIOS
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("6. DICCIONARIOS")
print("=" * 55)

# Clave → Valor (hash map)
estudiante = {
    "nombre": "Ana López",
    "carnet": 202300001,
    "notas": [85, 90, 78],
    "activo": True,
}

print("Diccionario:", estudiante)
print("Nombre     :", estudiante["nombre"])
print("Carnet     :", estudiante.get("carnet"))          # .get() es más seguro
print("Curso      :", estudiante.get("curso", "N/A"))   # valor por defecto

# Modificar y agregar
estudiante["email"] = "ana@universidad.edu"
estudiante["notas"].append(92)
print("\nActualizado:", estudiante)

# Iterar
print("\nClaves y valores:")
for clave, valor in estudiante.items():
    print(f"  {clave:10} : {valor}")
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 7. CONDICIONALES
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("7. CONDICIONALES")
print("=" * 55)

def clasificar_nota(nota):
    """Clasifica una nota según la escala de 0 a 100."""
    if nota >= 90:
        return "Excelente (A)"
    elif nota >= 80:
        return "Muy Bueno (B)"
    elif nota >= 70:
        return "Bueno (C)"
    elif nota >= 60:
        return "Suficiente (D)"
    else:
        return "Reprobado (F)"

for n in [95, 83, 71, 60, 45]:
    print(f"Nota {n:3d} → {clasificar_nota(n)}")

# Condicional en una línea (ternario)
edad = 20
estado = "mayor de edad" if edad >= 18 else "menor de edad"
print(f"\nEdad {edad}: {estado}")
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 8. CICLOS
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("8. CICLOS")
print("=" * 55)

# for — itera sobre cualquier iterable
print("for sobre lista:")
colores = ["rojo", "verde", "azul"]
for color in colores:
    print(f"  {color}")

# range() genera una secuencia de números
print("\nfor con range(1, 6):")
for i in range(1, 6):
    print(f"  i = {i}")

# enumerate() da índice + valor
print("\nenumerate():")
for i, color in enumerate(colores, start=1):
    print(f"  [{i}] {color}")

# while — repite mientras la condición sea verdadera
print("\nwhile (cuenta regresiva):")
cuenta = 5
while cuenta > 0:
    print(f"  {cuenta}...")
    cuenta -= 1
print("  ¡Despegue!")

# List comprehension — forma compacta de crear listas
cuadrados = [x ** 2 for x in range(1, 7)]
print(f"\nList comprehension [x² for x in 1..6]: {cuadrados}")

pares = [x for x in range(1, 11) if x % 2 == 0]
print(f"Solo pares [1..10]: {pares}")
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 9. FUNCIONES
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("9. FUNCIONES")
print("=" * 55)

# Función básica
def saludar(nombre):
    """Imprime un saludo personalizado."""
    print(f"¡Hola, {nombre}!")

saludar("Estudiante")

# Función con valor por defecto
def potencia(base, exponente=2):
    """Calcula base elevada al exponente (por defecto al cuadrado)."""
    return base ** exponente

print(f"\npotencia(3)    = {potencia(3)}")       # usa exponente=2
print(f"potencia(3, 3) = {potencia(3, 3)}")

# Función que retorna múltiples valores (como tupla)
def estadisticas(lista):
    """Retorna (mínimo, máximo, promedio) de una lista de números."""
    return min(lista), max(lista), sum(lista) / len(lista)

datos = [10, 25, 7, 18, 42, 33]
minimo, maximo, promedio = estadisticas(datos)
print(f"\nDatos    : {datos}")
print(f"Mínimo   : {minimo}")
print(f"Máximo   : {maximo}")
print(f"Promedio : {promedio:.2f}")

# Función recursiva
def factorial(n):
    """Calcula n! de forma recursiva."""
    if n <= 1:
        return 1
    return n * factorial(n - 1)

print(f"\nfactorial(5) = {factorial(5)}")   # 120
print(f"factorial(7) = {factorial(7)}")   # 5040
print()


# ═══════════════════════════════════════════════════════════════════════════════
# 10. MANEJO DE ERRORES
# ═══════════════════════════════════════════════════════════════════════════════

print("=" * 55)
print("10. MANEJO DE ERRORES")
print("=" * 55)

def dividir(a, b):
    """Divide a entre b con manejo de errores."""
    try:
        resultado = a / b
        return resultado
    except ZeroDivisionError:
        print(f"  ERROR: No se puede dividir {a} entre 0")
        return None
    except TypeError as e:
        print(f"  ERROR de tipo: {e}")
        return None
    finally:
        # Se ejecuta SIEMPRE, haya error o no
        print(f"  [Intento de dividir {a} / {b}]")

print("División normal:")
r = dividir(10, 2)
print(f"  Resultado: {r}")

print("\nDivisión entre cero:")
r = dividir(10, 0)
print(f"  Resultado: {r}")

print("\nTipo incorrecto:")
r = dividir("diez", 2)
print(f"  Resultado: {r}")

# Lanzar una excepción personalizada
print("\nValidación con raise:")
def raiz_cuadrada(n):
    """Calcula la raíz cuadrada, rechaza negativos."""
    if n < 0:
        raise ValueError(f"No se puede calcular la raíz de un número negativo: {n}")
    return math.sqrt(n)

for val in [25, -4]:
    try:
        print(f"  sqrt({val}) = {raiz_cuadrada(val)}")
    except ValueError as e:
        print(f"  ValueError: {e}")

print()
print("=" * 55)
print("¡Fin del script de introducción a Python!")
print("=" * 55)
