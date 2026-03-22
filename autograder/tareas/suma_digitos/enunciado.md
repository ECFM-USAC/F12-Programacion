# Tarea 3 — Ejercicio 2: Suma de Dígitos

Lee un número entero positivo e imprime la suma de todos sus dígitos.

## Entrada

Un número entero positivo `n` (1 ≤ n ≤ 10⁹).

## Salida

La suma de los dígitos de `n`.

## Ejemplos

```
Entrada: 123    Salida: 6    (1+2+3)
Entrada: 9999   Salida: 36   (9+9+9+9)
Entrada: 100    Salida: 1    (1+0+0)
```

## Pista

```
suma = 0
mientras n > 0:
    suma += n % 10    // último dígito
    n = n / 10        // eliminar último dígito
imprimir suma
```

## Prueba

```bash
./autograder/autograder.sh suma_digitos suma_digitos.cpp
```
