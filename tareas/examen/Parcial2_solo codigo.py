NOMBRE = "Brandom Rodriguez"   # TU NOMBRE AQUI
CARNET = "202506893"         # TU CARNET AQUI
if NOMBRE == "Nombre Apellido" or CARNET == "202300000":
    raise ValueError("Completa tu nombre y carnet antes de continuar.")
print(f"Estudiante : {NOMBRE}")
print(f"Carnet     : {CARNET}")
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Ejercicio 1 

#Parte a
import requests
URL_BASE = "https://api.nasa.gov/DONKI/GST"
API_KEY = "DEMO_KEY"
# Agrega también los parámetros startDate y endDate:
startDate = "2024-05-01"
endDate   = "2024-05-31"
# Construcción de la URL
url = (
    f"{URL_BASE}"
    f"?startDate={startDate}"
    f"&endDate={endDate}"
    f"&api_key={API_KEY}"
)
# Completa la llamada — usa timeout=15
respuesta = requests.get(url, timeout=15)
# Verifica que la respuesta fue exitosa antes de parsear el JSON
if not respuesta.ok:
    print(f"Error {respuesta.status_code}: {respuesta.text}")
    raise SystemExit("No se pudo obtener la respuesta. Intenta de nuevo.")
tormentas = respuesta.json()
print(f"Solicitud exitosa ✓  — {len(tormentas)} tormentas recibidas")

#Parte b
print(f"Total de tormentas en el período: {len(tormentas)}")
# Recorrer cada tormenta
for tormenta in tormentas:
    gst_id = tormenta.get("gstID", "N/A")
    start_time = tormenta.get("startTime", "N/A")
    print(f"ID: {gst_id} | Inicio: {start_time}")
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Ejercicio 2

#Parte a
for tormenta in tormentas:
    kp_max = 0
# recorrer la lista allKpIndex
    for medicion in tormenta.get("allKpIndex", []):
        kp = medicion.get("kpIndex", 0)
        if kp > kp_max:
            kp_max = kp
    print(f"{tormenta['startTime']} | Kp máx = {kp_max:.2f}")

#Parte b
tormenta_mas_intensa = None
kp_global_max = 0
for tormenta in tormentas:
    kp_max = 0
# calcular kp máximo de esta tormenta
    for medicion in tormenta.get("allKpIndex", []):
        kp = medicion.get("kpIndex", 0)
        if kp > kp_max:
            kp_max = kp
# comparar con el máximo global
    if kp_max > kp_global_max:
        kp_global_max = kp_max
        tormenta_mas_intensa = tormenta
if tormenta_mas_intensa:
    print("\nTormenta más intensa:")
    print(f"Inicio: {tormenta_mas_intensa['startTime']}")
    print(f"Kp máximo global: {kp_global_max:.2f}")
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Ejercicio 3

#Parte a
def clasificar_kp(kp):
    """Clasifica la intensidad de una tormenta según el índice Kp"""
    kp = int(kp)  # redondea hacia abajo
    if kp < 4:
        return "Quieto"
    elif kp == 4:
        return "Activo"
    elif kp == 5:
        return "G1 - Menor"
    elif kp == 6:
        return "G2 - Moderada"
    elif kp == 7:
        return "G3 - Fuerte"
    elif kp == 8:
        return "G4 - Severa"
    else:  # kp >= 9
        return "G5 - Fuerte"
#Prueba tu función con estos valores — verifica que los resultados son correctos:
for kp_prueba in [2.0, 4.0, 5.33, 6.67, 7.0, 8.67, 9.0]:
    print(f"kp={kp_prueba:.2f}  →  {clasificar_kp(kp_prueba)}")

#Parte b
print(f"\n{'Fecha inicio':<22} {'Kp máx':>7}  {'Categoría'}")
print("-" * 50)
for tormenta in tormentas:
    kp_max = 0
# calcular el Kp máximo de la tormenta
    for medicion in tormenta.get("allKpIndex", []):
        kp = medicion.get("kpIndex", 0)
        if kp > kp_max:
            kp_max = kp
    categoria = clasificar_kp(kp_max)
    print(f"{tormenta['startTime']:<22} {kp_max:>7.2f}  {categoria}")
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#Ejercicio 4

def analizar_tormenta(tormenta):
    """
    Analiza un evento de tormenta geomagnética.
    Parámetro:
        tormenta (dict): un elemento de la lista retornada por el endpoint GST.
    Retorna:
        dict con las claves: id, inicio, kp_max, kp_min, kp_promedio,
                             num_mediciones, categoria, eventos_vinculados.
    """
    mediciones = tormenta["allKpIndex"]
# Extraer valores kpIndex
    kp_valores = [m["kpIndex"] for m in mediciones]
    resultado = {
        "id": tormenta["gstID"],
        "inicio": tormenta["startTime"],
        "kp_max": max(kp_valores),
        "kp_min": min(kp_valores),
        "kp_promedio": round(sum(kp_valores) / len(kp_valores), 2),
        "num_mediciones": len(mediciones),
        "categoria": clasificar_kp(max(kp_valores)),
        "eventos_vinculados": len(tormenta["linkedEvents"] or []),
    }
    return resultado
for tormenta in tormentas:
    r = analizar_tormenta(tormenta)
    print(f"ID: {r['id']}")
    print(f"Inicio: {r['inicio']}")
    print(f"Kp Máx: {r['kp_max']}")
    print(f"Kp Mín: {r['kp_min']}")
    print(f"Kp Promedio: {r['kp_promedio']}")
    print(f"Número de mediciones: {r['num_mediciones']}")
    print(f"Categoría: {r['categoria']}")
    print(f"Eventos vinculados: {r['eventos_vinculados']}")
    print("-" * 40)
#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
print("Conculsiones:")

print("1. La tormenta mas intensa fue Inicio:2024-05-10T15:00Z con un Kp maximo de 9.00 y su clasificacion G5-Fuerte. Su kp es el valor maximo posible lo que implica que fue una tormenta geomagnetica extrema") 
print("2. Frecuencia :Se registraron 5 tormentas en un periodo de 15 dias, esto significa una alta activida geomagnetica. Tambien que hay una concentracion clara entre 10 y el 17 de mayor.Intensidad: 4 de las 5 tormantas fueron G2 con kp de 6.00 a 6.67, solo hubo una tormenta intesa de clasificacion G5. Esto implica una actividad moderada. Eventos vinculados: La tormenta mas intensa tiene un mayor numero de mediciones que en total son 13 y  de cantidad de eventos vinculados 6 en total. La tormentas moderadas tienen solamente entr 1 o 2 eventos.")
print("3. Una tormenta nivel G5-Fuerte podria haber causado interrupciones en los sistemas de navegacion (GPS),apagones, Auroras visibles en latitudes inusualmente bajas y fallos en equipos ")

#--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
