# Easy-C

transpiler source-to-source minimalista disena ado para transformar un dialecto simplificado y sin deelimitadores hacia codigo fuente en C estandar (C99/C11), utilizando el motor de analisis sintactico **Gram**. `../Gram`

---

## arquitectura del pipelin

el ciclo de transformacion de easy-C sigue un pipeline lineal sin runtime intermedio:

```
[ fuente/source .ec / .txt ]
         │
         ▼ (gram Lexer: tokens, cometarios, palabras clave)
[ flujo de tokens ]
         │
         ▼ (Gram Parser: combinadores declarativos y backtracking)
[ AST tipado:ASTProgram,ASTNode ]
         │
         ▼ (core.processor: normalizacion semantica y emision de C)
[ code C estandar (output.c) ]
         │
         ▼ (cmpilador del sistema:GCC,Clang ,MSVC)
[ binario final (.exe,ELF,lib) ]
```

1. **frontend sintatico (`core.initiator`, `core.grammar`):** Define el catálogo léxico y las reglas gramaticales mediante combinadores declarativos (`Seq`, `Alt`, `Opt`, `Many`, `MatchGroup`).
2. **backend Emiter (`core.processor`):** Recorre el AST generado, normaliza literales (ej. envoltura estricta de caracteres), inyecta los delimitadores formales de C (`;`) y genera automáticamente las cabeceras estándar necesarias (`<stdint.h>`, `<stdbool.h>`, `<stddef.h>`).

---

## 2. Especificación Sintáctica Actual

### declaracion de variables
El motor soporta declaraciones con inicialización obligatoria u opcional, prescindiendo del punto y coma al final de cada sentencia:

```c
<tipo> <identificador> [= <valor>] [; <comentario>]
```

#### ejemplo:
```c
int    edad    = 10
char   b       = "b"
double decimal = 1.0
float  radio
uint32_t mascara = 255
```

### tipos soportados:
* **Primitivos estándar:** `int`, `char`, `float`, `double`, `void`, `short`, `long`, `unsigned`, `signed`, `bool`.
* **Enteros de ancho fijo (`stdint.h` / `stddef.h`):** `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`, `int8_t`, `int16_t`, `int32_t`, `int64_t`, `size_t`.

### Comentarios
Los comentarios se introducen mediante el token `;` y se ignoran o preservan según la configuración del lexer, sin interferir en la lista de valores del AST.

---

## 3. Estructura del Repositorio

```
Easy-C/
├── core/
│   ├── initiator/
│   │   ├── rules/
│   │   │   ├── value.py        # Regla EC_VALUE (NUMBER, IDENT, STRING)
│   │   │   ├── var_decl.py     # Regla EC_VAR_DECL (tipos, ident, inicializador opcional)
│   │   │   └── __init__.py
│   │   ├── keywords.py         # Registro de grupos y tipos en Gram
│   │   └── __init__.py
│   ├── processor/
│   │   ├── processar_ast.py    # Emitter de C estandar y gestion de cabeceras
│   │   └── __init__.py
│   ├── grammar.py              # Punto de entrada de la gramatica (PROGRAM)
│   └── __init__.py
├── log/                        # Directorio para telemetria del parser (autolimpiable)
├── example.txt                 # Archivo de entrada de prueba
├── example.py                  # Script de ejecucion y transpilacion
├── output.c                    # Archivo C generado tras la ejecucion
├── .gitignore
└── README.md
```

---

## 4. Uso y Compilación

### Ejecución de la Transpilación
El script principal resuelve automáticamente la dependencia local de `Gram` si se encuentra en un directorio hermano:

```bash
python example.py
```

### Salida Generada (`output.c`)
```c
#include <stdint.h>
#include <stddef.h>

int edad = 10;
char b = 'b';
double decimal = 1.0;
float radio;
uint32_t mascara = 255;
```

### Compilación a Binario Nativo
El código emitido no posee dependencias externas y compila directamente con cualquier compilador de C estándar:

```bash
# Compilacion con GCC
gcc -std=c11 -O3 output.c -o programa.exe

# Compilacion con Clang
clang -std=c11 -O3 output.c -o programa.exe
```

---

## 5. Mantenimiento y Autolimpieza

* **Gestión de Logs:** `example.py` implementa la rutina `autolimpieza()`, purgando los logs acumulados en `log/` antes de cada corrida para evitar saturación de disco.
* **Control de Versiones:** El archivo `.gitignore` excluye artefactos temporales de build (`output.c`, `.o`, `.obj`, `.exe`), cachés de Python (`__pycache__`, `*.pyc`) y registros de diagnóstico (`log/*.log`).

---

## 6. Hoja de Ruta Técnica

1. **Punteros y Modificadores de Acceso:** Soporte sintáctico para indirección (`*`, `&`) en tipos y expresiones.
2. **Árbol de Expresiones Binarias:** Integración de combinadores asociativos para operaciones aritméticas y relacionales con precedencia formal.
3. **Definición de Funciones:** Soporte para signaturas de función, parámetros formales y bloques delimitados.
4. **Directivas `#line`:** Emisión de metadatos de depuración para mapear símbolos directamente a las líneas del código fuente de Easy-C en depuradores nativos (`gdb`, `lldb`, `x64dbg`).
