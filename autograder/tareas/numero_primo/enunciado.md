# Tarea 3 — Ejercicio 4: Número Primo

Lee un entero n ≥ 2 e imprime `primo` o `no primo`.

## Entrada

Un entero `n` con 2 ≤ n ≤ 10⁶.

## Salida

`primo` o `no primo` (exactamente así, en minúsculas).

## Ejemplos

```
Entrada: 7    Salida: primo
Entrada: 10   Salida: no primo
Entrada: 2    Salida: primo
Entrada: 97   Salida: primo
```

## Pista

Solo es necesario verificar divisores hasta √n:

```
si n == 2: primo
si n es par: no primo
para d desde 3 hasta sqrt(n) de 2 en 2:
    si n % d == 0: no primo
primo
```

## Prueba

```bash
./autograder/autograder.sh numero_primo numero_primo.cpp
```
