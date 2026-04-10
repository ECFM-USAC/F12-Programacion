"""
Modulo: fisica_poo
Descripcion: Modelado de objetos fisicos usando POO (clases y herencia).

Jerarquia de clases:
    CuerpoFisico          <- clase base
    ├── Particula         <- sin volumen, solo masa y posicion
    └── ObjetoRigido      <- tiene dimensiones fisicas
        ├── Esfera
        └── Cubo
"""

G = 9.8    # m/s^2
PI = 3.141592653589793


# ─── Clase base ───────────────────────────────────────────────────────────────

class CuerpoFisico:
    """Representa cualquier objeto con masa que puede moverse."""

    def __init__(self, nombre, masa):
        self.nombre = nombre
        self.masa = masa        # kg
        self.posicion = 0.0     # m  (una dimension por simplicidad)
        self.velocidad = 0.0    # m/s

    def aplicar_fuerza(self, fuerza, tiempo):
        """Actualiza velocidad y posicion con F=ma durante 'tiempo' segundos."""
        a = fuerza / self.masa
        self.posicion += self.velocidad * tiempo + 0.5 * a * tiempo**2
        self.velocidad += a * tiempo

    def energia_cinetica(self):
        """Retorna la energia cinetica actual: K = 0.5 * m * v^2"""
        return 0.5 * self.masa * self.velocidad**2

    def energia_potencial(self, altura):
        """Retorna la energia potencial: U = m * g * h"""
        return self.masa * G * altura

    def __str__(self):
        return (f"{self.__class__.__name__} '{self.nombre}' | "
                f"masa={self.masa} kg | "
                f"pos={self.posicion:.2f} m | "
                f"vel={self.velocidad:.2f} m/s")


# ─── Subclase: Particula ──────────────────────────────────────────────────────

class Particula(CuerpoFisico):
    """Particula puntual (sin volumen). Hereda todo de CuerpoFisico."""

    def __init__(self, nombre, masa, carga=0.0):
        super().__init__(nombre, masa)
        self.carga = carga      # Coulombs

    def fuerza_electrica(self, campo_e):
        """Fuerza electrica: F = q * E"""
        return self.carga * campo_e

    def __str__(self):
        base = super().__str__()
        return f"{base} | carga={self.carga} C"


# ─── Subclase: ObjetoRigido ───────────────────────────────────────────────────

class ObjetoRigido(CuerpoFisico):
    """Objeto con volumen. Las subclases definen como calcularlo."""

    def __init__(self, nombre, masa, densidad):
        super().__init__(nombre, masa)
        self.densidad = densidad    # kg/m^3

    def volumen(self):
        """Las subclases deben implementar este metodo."""
        raise NotImplementedError("Implementar volumen() en la subclase")

    def volumen_desde_masa(self):
        """Volumen calculado desde masa y densidad: V = m / rho"""
        return self.masa / self.densidad

    def __str__(self):
        base = super().__str__()
        return f"{base} | densidad={self.densidad} kg/m³ | volumen={self.volumen():.4f} m³"


# ─── Subclase: Esfera ─────────────────────────────────────────────────────────

class Esfera(ObjetoRigido):
    """Esfera solida homogenea."""

    def __init__(self, nombre, radio, densidad):
        volumen = (4/3) * PI * radio**3
        masa = densidad * volumen
        super().__init__(nombre, masa, densidad)
        self.radio = radio      # m

    def volumen(self):
        """V = (4/3) * pi * r^3"""
        return (4/3) * PI * self.radio**3

    def area_superficie(self):
        """A = 4 * pi * r^2"""
        return 4 * PI * self.radio**2


# ─── Subclase: Cubo ───────────────────────────────────────────────────────────

class Cubo(ObjetoRigido):
    """Cubo solido homogeneo."""

    def __init__(self, nombre, lado, densidad):
        volumen = lado**3
        masa = densidad * volumen
        super().__init__(nombre, masa, densidad)
        self.lado = lado        # m

    def volumen(self):
        """V = lado^3"""
        return self.lado**3

    def area_superficie(self):
        """A = 6 * lado^2"""
        return 6 * self.lado**2
