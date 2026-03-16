#!/bin/bash
# Autograder — Programacion 1, ECFM
# Evalua tareas de C++ y Python contra casos de prueba

set -euo pipefail

# ── Banner ────────────────────────────────────────────────────────────────────
banner() {
  echo "  .:#@@@@+.  _____ ____ _____ __  __ "
  echo " :%@@@@@@%: | ____/ ___|  ___|  \\/  |"
  echo " *@@@@@@@@* |  _|| |   | |_  | |\\/| |"
  echo " :%@@@@@@%: | |__| |___|  _| | |  | |"
  echo "  '-#@@@@-' |_____\\____|_|   |_|  |_|"
  echo "   Autograder — Programacion 1 F12"
  echo ""
}

# ── Colores ───────────────────────────────────────────────────────────────────
GREEN='\033[0;32m'; RED='\033[0;31m'; YELLOW='\033[1;33m'; RESET='\033[0m'
pass() { echo -e "  ${GREEN}[PASS]${RESET} $1"; }
fail() { echo -e "  ${RED}[FAIL]${RESET} $1"; }
info() { echo -e "  ${YELLOW}[INFO]${RESET} $1"; }

# ── Configuracion ─────────────────────────────────────────────────────────────
TIMEOUT=5          # segundos maximos por caso de prueba
TEMP_DIR=$(mktemp -d)
trap "rm -rf $TEMP_DIR" EXIT

TOTAL=0; PASSED=0

# ── Compilar C++ ──────────────────────────────────────────────────────────────
compile_cpp() {
  local src="$1"
  local bin="$TEMP_DIR/programa"
  if g++ -std=c++17 -O2 -Wall -o "$bin" "$src" 2>"$TEMP_DIR/compile_err"; then
    echo "$bin"
  else
    echo ""
    cat "$TEMP_DIR/compile_err" >&2
  fi
}

# ── Ejecutar un caso de prueba ────────────────────────────────────────────────
# run_test <cmd> <input_file> <expected_output_file> <nombre_caso>
run_test() {
  local cmd="$1"
  local input="$2"
  local expected="$3"
  local name="$4"

  TOTAL=$((TOTAL + 1))

  local actual
  local t_start t_end elapsed_ms
  t_start=$(date +%s%3N)
  actual=$(timeout "$TIMEOUT" bash -c "$cmd" < "$input" 2>/dev/null) || true
  t_end=$(date +%s%3N)
  elapsed_ms=$(( t_end - t_start ))

  if diff -q <(echo "$actual" | tr -s ' ' | sed 's/[[:space:]]*$//') \
             <(cat "$expected" | tr -s ' ' | sed 's/[[:space:]]*$//') > /dev/null 2>&1; then
    pass "$name  (${elapsed_ms} ms)"
    PASSED=$((PASSED + 1))
  else
    fail "$name  (${elapsed_ms} ms)"
    echo "    Esperado:"
    cat "$expected" | sed 's/^/      /'
    echo "    Obtenido:"
    echo "$actual" | sed 's/^/      /'
  fi
}

# ── Evaluar tarea ─────────────────────────────────────────────────────────────
grade() {
  local tarea="$1"         # ej: tareas/tarea1
  local archivo="$2"       # archivo del estudiante (.cpp o .py)

  local ext="${archivo##*.}"
  local cmd=""

  echo ""
  echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
  echo " Tarea : $(basename $tarea)"
  echo " Archivo: $archivo"
  echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"

  if [[ "$ext" != "cpp" ]]; then
    fail "Solo se aceptan archivos .cpp (recibido: .$ext)"
    return
  fi

  local bin
  bin=$(compile_cpp "$archivo")
  if [[ -z "$bin" ]]; then
    fail "Error de compilacion"
    return
  fi
  cmd="$bin"
  info "Compilacion exitosa"

  # Correr cada caso de prueba definido en tests/<tarea>/
  local test_dir="tests/$(basename $tarea)"
  if [[ ! -d "$test_dir" ]]; then
    fail "No se encontraron tests en $test_dir"
    return
  fi

  for input_file in "$test_dir"/*.in; do
    [[ -f "$input_file" ]] || continue
    local base="${input_file%.in}"
    local expected_file="${base}.out"
    local case_name=$(basename "$base")

    if [[ ! -f "$expected_file" ]]; then
      info "Sin archivo .out para $case_name — omitido"
      continue
    fi

    run_test "$cmd" "$input_file" "$expected_file" "$case_name"
  done

  echo ""
  echo " Resultado: $PASSED / $TOTAL casos pasados"
  echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
}

# ── Main ──────────────────────────────────────────────────────────────────────
banner

if [[ $# -lt 2 ]]; then
  echo "Uso: $0 <directorio_tarea> <archivo_estudiante.cpp|.py>"
  echo ""
  echo "Ejemplo:"
  echo "  $0 tareas/ordenamiento solucion.cpp"
  echo "  $0 tareas/busqueda     solucion.py"
  exit 1
fi

TAREA="$1"
ARCHIVO="$(realpath "$2")"   # convertir a path absoluto antes del cd
cd "$(dirname "$0")"         # siempre ejecutar desde autograder/
grade "$TAREA" "$ARCHIVO"
