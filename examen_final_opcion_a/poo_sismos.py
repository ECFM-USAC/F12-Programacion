"""
Ejercicio 5 — Programación Orientada a Objetos
Examen Final — Programación 1 (F12) — Variante A: Sismos USGS

Instrucciones:
    Implementa todos los métodos marcados con  # TU CÓDIGO AQUÍ
    No modifiques los métodos ya implementados ni los __init__.
    Cuando termines, regresa al notebook y ejecuta el Ejercicio 5.
"""


class EventoSismico:
    """Representa un evento sísmico genérico registrado en algún lugar del mundo."""

    def __init__(self, lugar, fecha):
        # Guarda el lugar del evento sísmico
        self.lugar = lugar

        # Guarda la fecha del evento sísmico
        self.fecha = fecha

    def clasificar(self):
        """
        Clasifica el evento según su intensidad.
        Este método debe ser sobreescrito en la clase hija.

        Retorna:
            str: categoría del evento
        """

        # Método vacío porque será implementado en la clase hija
        pass

    def descripcion(self):
        """
        Retorna una descripción legible del evento.
        Este método debe ser sobreescrito en la clase hija.

        Retorna:
            str: descripción del evento
        """

        # Método vacío porque será implementado en la clase hija
        pass

    def __str__(self):
        # Retorna la descripción del evento o una descripción genérica
        return self.descripcion() or f"EventoSismico en {self.lugar}"

    def __repr__(self):
        # Retorna una representación técnica del objeto
        return f"{self.__class__.__name__}(lugar={self.lugar!r}, fecha={self.fecha!r})"


class Sismo(EventoSismico):
    """
    Representa un sismo con sus atributos medidos.

    Atributos:
        lugar       (str)   : descripción del lugar (columna 'place' del DataFrame)
        fecha       (str)   : fecha y hora UTC del evento (columna 'time')
        magnitud    (float) : magnitud del sismo (columna 'mag')
        profundidad (float) : profundidad del foco en km (columna 'depth')
        tipo_escala (str)   : escala de magnitud usada (columna 'magType')
    """

    def __init__(self, lugar, fecha, magnitud, profundidad, tipo_escala="mww"):
        # Llama al constructor de la clase padre
        super().__init__(lugar, fecha)

        # Guarda la magnitud del sismo
        self.magnitud = magnitud

        # Guarda la profundidad del sismo
        self.profundidad = profundidad

        # Guarda el tipo de escala usada
        self.tipo_escala = tipo_escala

    def clasificar(self):
        """
        Clasifica el sismo según su magnitud.

        Usa la misma escala que aplicaste en el Ejercicio 3:
            5.5 ≤ magnitud < 6.0  →  'Moderado-Fuerte'
            6.0 ≤ magnitud < 7.0  →  'Fuerte'
            7.0 ≤ magnitud < 8.0  →  'Mayor'
            magnitud ≥ 8.0        →  'Gran terremoto'

        Hint: usa if / elif / elif / else sobre self.magnitud

        Retorna:
            str: categoría del sismo
        """

        # Verifica si la magnitud es menor a 6.0
        if self.magnitud < 6.0:

            # Retorna categoría Moderado-Fuerte
            return "Moderado-Fuerte"

        # Verifica si la magnitud es menor a 7.0
        elif self.magnitud < 7.0:

            # Retorna categoría Fuerte
            return "Fuerte"

        # Verifica si la magnitud es menor a 8.0
        elif self.magnitud < 8.0:

            # Retorna categoría Mayor
            return "Mayor"

        # Para magnitudes de 8.0 o superiores
        else:

            # Retorna categoría Gran terremoto
            return "Gran terremoto"

    def clasificar_profundidad(self):
        """
        Clasifica el sismo según la profundidad del foco.

        Escala vista en el enunciado del examen:
            profundidad < 70 km          →  'Superficial'
            70 ≤ profundidad < 300 km    →  'Intermedio'
            profundidad ≥ 300 km         →  'Profundo'

        Hint: usa if / elif / else sobre self.profundidad

        Retorna:
            str: tipo de sismo por profundidad
        """

        # Verifica si la profundidad es menor a 70 km
        if self.profundidad < 70:

            # Retorna clasificación superficial
            return "Superficial"

        # Verifica si la profundidad es menor a 300 km
        elif self.profundidad < 300:

            # Retorna clasificación intermedia
            return "Intermedio"

        # Para profundidades iguales o mayores a 300 km
        else:

            # Retorna clasificación profunda
            return "Profundo"

    def es_peligroso(self):
        """
        Determina si el sismo es potencialmente peligroso en superficie.

        Criterio: magnitud >= 7.0  Y  profundidad < 70 km
        (un sismo Mayor o Gran terremoto que además es superficial)

        Hint: combina dos condiciones con 'and'

        Retorna:
            bool: True si cumple ambos criterios, False en caso contrario
        """

        # Evalúa si cumple ambas condiciones
        return self.magnitud >= 7.0 and self.profundidad < 70

    def descripcion(self):
        """
        Retorna una cadena con el resumen del sismo.

        Formato esperado (usa los métodos clasificar y clasificar_profundidad):
            "Sismo mag=7.10 | Mayor | Superficial | Lugar: Tonga Region | Escala: mww"

        Hint: llama a self.clasificar() y self.clasificar_profundidad() dentro del f-string

        Retorna:
            str: descripción formateada del sismo
        """

        # Construye y retorna la descripción completa
        return (
            f"Sismo mag={self.magnitud:.2f} | "
            f"{self.clasificar()} | "
            f"{self.clasificar_profundidad()} | "
            f"Lugar: {self.lugar} | "
            f"Escala: {self.tipo_escala}"
        )

    def __str__(self):
        # Retorna la descripción del objeto
        return self.descripcion()

    def __repr__(self):
        # Retorna representación técnica del objeto
        return (
            f"Sismo(lugar={self.lugar!r}, magnitud={self.magnitud}, "
            f"profundidad={self.profundidad}, tipo_escala={self.tipo_escala!r})"
        )


class CatalogoSismos:
    """
    Colección de objetos Sismo con métodos de consulta y resumen.

    Atributos:
        nombre  (str)  : nombre descriptivo del catálogo
        _sismos (list) : lista interna de objetos Sismo
    """

    def __init__(self, nombre="Catálogo de Sismos"):

        # Guarda el nombre del catálogo
        self.nombre = nombre

        # Inicializa lista vacía de sismos
        self._sismos = []

    def agregar(self, sismo):
        """Agrega un objeto Sismo al catálogo."""

        # Agrega el objeto sismo a la lista
        self._sismos.append(sismo)

    def __len__(self):
        """Retorna el total de sismos en el catálogo."""

        # Retorna la cantidad total de sismos
        return len(self._sismos)

    def el_mas_intenso(self):
        """
        Encuentra el sismo con la mayor magnitud.

        Usa un ciclo for para iterar sobre self._sismos.
        Guarda el mayor encontrado en una variable auxiliar.
        Compara con sismo.magnitud en cada iteración.

        Retorna:
            Sismo : el objeto con la magnitud más alta
            None  : si el catálogo está vacío
        """

        # Verifica si la lista está vacía
        if not self._sismos:

            # Retorna None si no hay sismos
            return None

        # Guarda inicialmente el primer sismo como el más intenso
        mayor = self._sismos[0]

        # Recorre todos los sismos del catálogo
        for sismo in self._sismos:

            # Verifica si el sismo actual tiene mayor magnitud
            if sismo.magnitud > mayor.magnitud:

                # Actualiza el sismo más intenso
                mayor = sismo

        # Retorna el sismo más intenso encontrado
        return mayor

    def filtrar_por_categoria(self, categoria):
        """
        Retorna una lista con todos los sismos de la categoría dada.

        Parámetro:
            categoria (str): 'Moderado-Fuerte', 'Fuerte', 'Mayor' o 'Gran terremoto'

        Hint: usa un ciclo for y llama a sismo.clasificar() en cada iteración.
              Agrega a una lista auxiliar los que coincidan.

        Retorna:
            list: lista de objetos Sismo filtrada (puede estar vacía)
        """

        # Lista auxiliar para almacenar coincidencias
        filtrados = []

        # Recorre todos los sismos
        for sismo in self._sismos:

            # Verifica si la categoría coincide
            if sismo.clasificar() == categoria:

                # Agrega el sismo a la lista filtrada
                filtrados.append(sismo)

        # Retorna la lista filtrada
        return filtrados

    def resumen(self):
        """
        Imprime un resumen del catálogo.

        Debe mostrar:
            1. Nombre del catálogo y total de sismos  (usa len(self))
            2. El sismo más intenso                   (usa el_mas_intenso())
            3. Cantidad de sismos en cada categoría   (usa filtrar_por_categoria())

        Hint: itera sobre las categorías con un for:
            categorias = ['Moderado-Fuerte', 'Fuerte', 'Mayor', 'Gran terremoto']
        """

        # Imprime el nombre del catálogo
        print(f"Catálogo: {self.nombre}")

        # Imprime la cantidad total de sismos
        print(f"Total de sismos: {len(self)}")

        # Obtiene el sismo más intenso
        mas_intenso = self.el_mas_intenso()

        # Imprime el sismo más intenso
        print(f"Sismo más intenso: {mas_intenso}")

        # Lista de categorías
        categorias = ['Moderado-Fuerte', 'Fuerte', 'Mayor', 'Gran terremoto']

        # Recorre cada categoría
        for categoria in categorias:

            # Obtiene lista filtrada de la categoría actual
            cantidad = len(self.filtrar_por_categoria(categoria))

            # Imprime la cantidad encontrada
            print(f"{categoria}: {cantidad}")
