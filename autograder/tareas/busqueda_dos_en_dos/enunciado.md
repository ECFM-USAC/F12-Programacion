# Tarea 3 — Ejercicio 1: Búsqueda de 2 en 2 con Retroceso

Implementa la búsqueda de 2 en 2 con retroceso sobre una lista **ordenada ascendentemente**.

## Algoritmo

1. Avanzar de 2 en 2 mientras `lista[i] < objetivo`
2. Retroceder 1 posición (`i -= 1`)
3. Revisar las posiciones `i` e `i+1` (con protección de límites)
4. Retornar el índice si se encontró, o `-1` si no

## Entrada

```
N
a0 a1 ... a(N-1)   ← lista ordenada ascendentemente
objetivo
```

## Salida

Índice (base 0) donde se encontró el objetivo, o `-1` si no existe.

## Ejemplos

**Encontrado:**
```
Entrada:         Salida:
7                3
2 5 8 11 14 17 20
11
```

**No encontrado:**
```
Entrada:         Salida:
7                -1
2 5 8 11 14 17 20
15
```

## Prueba

```bash
./autograder/autograder.sh busqueda_dos_en_dos busqueda_dos_en_dos.cpp
```

## Casos de prueba

| Caso   | N      | Descripción                          | Resultado |
|--------|--------|--------------------------------------|-----------|
| caso1  | 7      | Objetivo en posición impar (centro)  | 3         |
| caso2  | 7      | Objetivo no existe                   | -1        |
| caso3  | 5      | Primer elemento (mejor caso)         | 0         |
| caso4  | 5      | Último elemento                      | 4         |
| caso5  | 6      | Objetivo en índice par (salto directo)| 2        |
| caso6  | 10 000 | Lista grande — encontrado (idx 7776) | 7776      |
| caso7  | 10 000 | Lista grande — no encontrado         | -1        |
