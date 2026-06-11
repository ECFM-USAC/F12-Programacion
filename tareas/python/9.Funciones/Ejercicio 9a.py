def convertir_t(g, e="C"):
    if e == "C":
        return g * 9/5 + 32
    elif e == "F":
        return (g - 32) * 5/9
    else:
        return "Escala no válida"
print("100°C ->", convertir_t(100, "C"), "°F")
print("0°C ->", convertir_t(0, "C"), "°F")
print("32°F ->", convertir_t(32, "F"), "°C")
print("212°F ->", convertir_t(212, "F"), "°C")