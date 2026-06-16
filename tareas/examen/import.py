import os
import requests
import json
import time

# Cargar la API key desde la variable de entorno.
# Si no está configurada, usa DEMO_KEY como respaldo (30 req/hora).
API_KEY = os.getenv("NASA_API_KEY", "").strip() or "DEMO_KEY"

if API_KEY == "DEMO_KEY":
    print("  Usando DEMO_KEY - limite: 30 solicitudes/hora")
    print("   Configura NASA_API_KEY para mayor limite (ver instrucciones arriba).")
else:
    print(f"  API key cargada: {API_KEY[:4]}{'*' * (len(API_KEY) - 4)}")

print("\nLibrerias importadas correctamente ")
