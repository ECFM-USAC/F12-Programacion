
curso = {
    "nombre": "Programación",
    "codigo": "1505",
    "creditos": 10,
    "activo": True
}

curso["estudiantes"] = 35
print("Creditos:", curso.get("creditos"))
print("Salon:", curso.get("salon", "Sin asignar"))