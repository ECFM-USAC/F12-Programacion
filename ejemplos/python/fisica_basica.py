"""
Modulo: fisica_basica
Descripcion: Funciones utiles para calculos de fisica basica.
Uso: import fisica_basica o from fisica_basica import <funcion>
"""

# Constantes fisicas
G = 9.8        # Aceleracion gravitacional (m/s^2)
C = 3e8        # Velocidad de la luz (m/s)
PI = 3.141592653589793

# --- Cinematica ---

def posicion(x0, v0, a, t):
    """Calcula la posicion con aceleracion constante.
    x = x0 + v0*t + 0.5*a*t^2
    """
    return x0 + v0 * t + 0.5 * a * t**2

def velocidad(v0, a, t):
    """Calcula la velocidad con aceleracion constante.
    v = v0 + a*t
    """
    return v0 + a * t

def tiempo_caida(h, g=G):
    """Calcula el tiempo de caida libre desde altura h (m).
    h = 0.5 * g * t^2  =>  t = sqrt(2h/g)
    """
    return (2 * h / g) ** 0.5

# --- Energia ---

def energia_cinetica(m, v):
    """Energia cinetica: K = 0.5 * m * v^2"""
    return 0.5 * m * v**2

def energia_potencial(m, h, g=G):
    """Energia potencial gravitacional: U = m * g * h"""
    return m * g * h

def energia_total(m, v, h, g=G):
    """Energia mecanica total: E = K + U"""
    return energia_cinetica(m, v) + energia_potencial(m, h, g)

# --- Fuerza ---

def segunda_ley_newton(m, a):
    """Fuerza neta: F = m * a"""
    return m * a

def peso(m, g=G):
    """Peso de un objeto: W = m * g"""
    return m * g

# --- Geometria circular ---

def area_circulo(r):
    """Area de un circulo: A = pi * r^2"""
    return PI * r**2

def velocidad_angular(v, r):
    """Velocidad angular: omega = v / r"""
    return v / r

def fuerza_centripeta(m, v, r):
    """Fuerza centripeta: F = m * v^2 / r"""
    return m * v**2 / r
