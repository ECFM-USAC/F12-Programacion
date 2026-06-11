def v_n(n):
    if not isinstance(n, int):
        raise TypeError("La edad debe ser un entero")
    if n < 0 or n > 150:
        raise ValueError("La edad debe estar entre 0 y 150")
    return True
x = [25, -5, 200, "veinte"]
for v in x:
    try:
        y = v_n(v)
        print(f"{v} -> Edad valida:", y)
    except TypeError as te:
        print(f"{v} -> TypeError:", te)
    except ValueError as ve:
        print(f"{v} -> ValueError:", ve)