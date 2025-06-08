# Compilador Valorant

Este es un compilador para un lenguaje de programación inspirado en el juego Valorant. El lenguaje utiliza terminología del juego para representar operaciones y estructuras de programación comunes.

## Instalación
1. Clona el repositorio
2. Ejecuta `setup.bat` para instalar las dependencias
3. Usa `make` para compilar el proyecto

## Características del Lenguaje

### Tipos de Datos
- `sage`: Números enteros (equivalente a int)
- `viper`: Números decimales (equivalente a float)
- `cypher`: Cadenas de texto (equivalente a string)

Ejemplo:
```
sage numero = 42;        // Entero
viper decimal = 3.14;    // Decimal
cypher texto = "Hola";   // Texto
```

### Operadores
#### Operadores Aritméticos
- `heal`: Suma (+)
- `damage`: Resta (-)
- `kill`: Multiplicación (*)
- `share`: División (/)

#### Operadores de Comparación
- `win`: Mayor que (>)
- `lose`: Menor que (<)
- `headshot`: Igual a (==)

Ejemplo:
```
// Operaciones aritméticas
viper resultado = a heal b;    // Suma
viper resta = x damage y;      // Resta
viper producto = m kill n;     // Multiplicación
viper division = p share q;    // División

// Comparaciones
flash (puntuacion win 90) {    // Mayor que
    sova "Excelente!";
}
```

### Estructuras de Control

#### If-Else (Flash-Smoke)
```
flash (puntuacion win 90) {
    sova "Excelente!";
} smoke flash (puntuacion win 80) {
    sova "Muy bien!";
} smoke {
    sova "Sigue intentando";
}
```

#### While (Rotate)
```
rotate (contador lose 5) {
    sova contador;
    contador = contador heal 1;
}
```

#### Break (Defuse)
```
rotate (i lose 10) {
    flash (i headshot 5) {
        defuse;    // Sale del bucle
    }
}
```

### Entrada/Salida
- `breach`: Entrada de datos (input)
- `sova`: Salida de datos (output)

### Funciones
- `agent`: Declaración de función
- `spike`: Función principal (main)
- `plant`: Retorno de función (return)

## Ejemplos Completos

### 1. Calculadora Básica
```
agent spike() {
    // Variables para los números
    viper num1;
    viper num2;
    
    sova "Ingresa primer numero: ";
    breach num1;
    sova "Ingresa segundo numero: ";
    breach num2;

    sova "\nSuma: ";
    sova num1 heal num2;
    
    sova "\nResta: ";
    sova num1 damage num2;
    
    sova "\nMultiplicacion: ";
    sova num1 kill num2;
    
    sova "\nDivision: ";
    sova num1 share num2;

    plant 0;
}
```

### 2. Calculadora Avanzada
```
agent spike() {
    viper num1;
    viper num2;
    viper resultado;
    sage opcion;
    cypher continuar = "si";

    rotate (continuar headshot "si") {
        sova "\n=== Calculadora Avanzada ===\n";
        sova "1. Suma (heal)\n";
        sova "2. Resta (damage)\n";
        sova "3. Multiplicacion (kill)\n";
        sova "4. Division (share)\n";
        sova "Elige una opcion (1-4): ";
        breach opcion;

        sova "\nIngresa primer numero: ";
        breach num1;
        sova "Ingresa segundo numero: ";
        breach num2;

        flash (opcion headshot 1) {
            resultado = num1 heal num2;
        } smoke flash (opcion headshot 2) {
            resultado = num1 damage num2;
        } smoke flash (opcion headshot 3) {
            resultado = num1 kill num2;
        } smoke flash (opcion headshot 4) {
            flash (num2 headshot 0) {
                sova "Error: No se puede dividir por cero";
            } smoke {
                resultado = num1 share num2;
            }
        }

        sova "\nResultado: ";
        sova resultado;
        sova "\n";

        sova "Deseas realizar otra operacion? (si/no): ";
        breach continuar;
    }

    plant 0;
}
```

### 3. FizzBuzz
```
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
├── docs/             # Documentación adicional
└── Makefile          # Script de compilación
```

## Manejo de Errores

El compilador detecta y reporta varios tipos de errores:

1. **Errores Léxicos**: Caracteres no reconocidos o tokens inválidos
2. **Errores Sintácticos**: Estructura del programa incorrecta
3. **Errores Semánticos**: 
   - Variables no declaradas
   - Tipos incompatibles en operaciones
   - División por cero
   - Operaciones no válidas con strings

## Mejores Prácticas
1. Usa `viper` para números que puedan ser decimales
2. Usa `sage` solo cuando estés seguro de que necesitas enteros
3. Verifica la división por cero
4. Usa saltos de línea (\n) para mejor formato
5. Evita caracteres especiales en los mensajes
6. Valida las entradas del usuario
7. Usa comentarios para documentar tu código

## Limitaciones Actuales
1. No soporta funciones con parámetros
2. No hay soporte para arreglos
3. No hay soporte para operaciones de punto flotante complejas
4. No hay soporte para entrada/salida de archivos

## Solución de Problemas
Si encuentras errores, verifica:
1. Que todas las variables estén declaradas
2. Que los tipos de datos sean compatibles
3. Que no haya divisiones por cero
4. Que todas las llaves y paréntesis estén balanceados
5. Que cada sentencia termine con punto y coma
6. Que no uses caracteres especiales en los mensajes 