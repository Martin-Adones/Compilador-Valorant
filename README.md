# Compilador Valorant

Este es un compilador para un lenguaje de programación inspirado en el juego Valorant. El lenguaje utiliza terminología del juego para representar operaciones y estructuras de programación comunes.

## Características del Lenguaje

### Tipos de Datos
- `sage`: Números enteros (equivalente a int)
- `viper`: Números decimales (equivalente a float)
- `cypher`: Cadenas de texto (equivalente a string)

### Operadores
- `heal`: Suma (+)
- `damage`: Resta (-)
- `kill`: Multiplicación (*)
- `share`: División (/)
- `win`: Mayor que (>)
- `lose`: Menor que (<)
- `headshot`: Igual a (==)

### Estructuras de Control
- `flash`: Condicional if
- `smoke`: Condicional else
- `rotate`: Bucle while

### Entrada/Salida
- `breach`: Entrada de datos (input)
- `sova`: Salida de datos (output)

### Funciones
- `agent`: Declaración de función
- `spike`: Función principal (main)
- `plant`: Retorno de función (return)

## Requisitos de Instalación

- GCC (GNU Compiler Collection)
- Flex (Analizador Léxico)
- Bison (Analizador Sintáctico)
- Make (Opcional, para automatizar la compilación)

## Compilación

1. Clonar el repositorio:
```bash
git clone https://github.com/tu-usuario/Compilador-Valorant.git
cd Compilador-Valorant
```

2. Compilar el proyecto:
```bash
gcc -o valorant src/*.c -I src/
```

## Uso

1. Crear un archivo con extensión `.val` con tu código
2. Ejecutar el compilador:
```bash
./valorant < tu_archivo.val
```

## Ejemplo de Código

```
// FizzBuzz en Valorant
agent spike() {
    sage i = 1;
    sage limite = 100;

    rotate (i lose limite) {
        sage mod3 = i share 3;
        sage mod5 = i share 5;
        sage temp3 = mod3 kill 3;
        sage temp5 = mod5 kill 5;

        flash ((temp3 headshot i) win (temp5 headshot i)) {
            sova "FizzBuzz";
        } smoke {
            flash (temp3 headshot i) {
                sova "Fizz";
            } smoke {
                flash (temp5 headshot i) {
                    sova "Buzz";
                } smoke {
                    sova i;
                }
            }
        }
        i = i heal 1;
    }
    plant 0;
}
```

## Estructura del Proyecto

```
Compilador-Valorant/
├── src/
│   ├── valorant.l     # Analizador léxico (Flex)
│   ├── valorant.y     # Analizador sintáctico (Bison)
│   ├── ast.h          # Definiciones del AST
│   ├── ast.c          # Implementación del AST
│   ├── interpreter.h  # Definiciones del intérprete
│   ├── interpreter.c  # Implementación del intérprete
│   └── main.c         # Programa principal
├── examples/          # Ejemplos de programas
│   ├── fizzbuzz.val
│   ├── factorial.val
│   ├── calculadora.val
│   └── mayor_numero.val
└── docs/             # Documentación adicional
    └── manual.md     # Manual de usuario
```

## Manejo de Errores

El compilador detecta y reporta varios tipos de errores:

1. **Errores Léxicos**: Caracteres no reconocidos o tokens inválidos
2. **Errores Sintácticos**: Estructura del programa incorrecta
3. **Errores Semánticos**: 
   - Variables no declaradas
   - Tipos incompatibles en operaciones
   - División por cero 