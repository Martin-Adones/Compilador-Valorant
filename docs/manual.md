# Manual de Usuario - Lenguaje Valorant

## Introducción

Bienvenido al manual de usuario del lenguaje de programación Valorant. Este lenguaje está diseñado para ser intuitivo y divertido, utilizando terminología del juego Valorant para representar conceptos de programación comunes.

## Primeros Pasos

### Instalación

1. Asegúrate de tener instalados los requisitos:
   - GCC (GNU Compiler Collection)
   - Flex
   - Bison

2. Compila el compilador:
```bash
gcc -o valorant src/*.c -I src/
```

### Tu Primer Programa

Crea un archivo `hola_mundo.val`:

```
agent spike() {
    sova "¡Hola, Agente!";
    plant 0;
}
```

Ejecútalo:
```bash
./valorant < hola_mundo.val
```

## Guía del Lenguaje

### 1. Tipos de Datos

#### sage (enteros)
```
sage numero = 42;
sage contador = 0;
sage negativo = -10;
```

#### viper (decimales)
```
viper pi = 3.14159;
viper temperatura = -2.5;
```

#### cypher (texto)
```
cypher mensaje = "Spike plantado!";
cypher nombre = "Sage";
```

### 2. Operadores

#### Aritméticos
- `heal`: Suma
  ```
  sage total = 5 heal 3;  // total = 8
  ```
- `damage`: Resta
  ```
  sage diferencia = 10 damage 4;  // diferencia = 6
  ```
- `kill`: Multiplicación
  ```
  sage producto = 6 kill 7;  // producto = 42
  ```
- `share`: División
  ```
  sage cociente = 15 share 3;  // cociente = 5
  ```

#### Comparación
- `win`: Mayor que
  ```
  flash (10 win 5) {
      sova "10 es mayor que 5";
  }
  ```
- `lose`: Menor que
  ```
  flash (3 lose 7) {
      sova "3 es menor que 7";
  }
  ```
- `headshot`: Igual a
  ```
  flash (score headshot 100) {
      sova "¡Puntuación perfecta!";
  }
  ```

### 3. Estructuras de Control

#### Condicionales (flash/smoke)
```
flash (energia win 50) {
    sova "Energía alta";
} smoke {
    sova "Energía baja";
}
```

#### Bucles (rotate)
```
sage contador = 0;
rotate (contador lose 5) {
    sova contador;
    contador = contador heal 1;
}
```

### 4. Entrada/Salida

#### Salida (sova)
```
sova "Mensaje directo";
sage numero = 42;
sova numero;
```

#### Entrada (breach)
```
sage valor;
sova "Ingresa un número:";
breach valor;
```

### 5. Funciones

#### Definición de Funciones
```
agent calcular_suma(sage a, sage b) {
    sage resultado = a heal b;
    plant resultado;
}
```

#### Función Principal
```
agent spike() {
    // Código principal aquí
    plant 0;
}
```

## Ejemplos Prácticos

### 1. Calculadora Simple
```
agent spike() {
    sage num1;
    sage num2;
    sage opcion;
    
    sova "Calculadora Valorant";
    sova "1. Heal (Suma)";
    sova "2. Damage (Resta)";
    sova "3. Kill (Multiplicación)";
    sova "4. Share (División)";
    
    sova "Elige una opción:";
    breach opcion;
    
    sova "Ingresa primer número:";
    breach num1;
    sova "Ingresa segundo número:";
    breach num2;
    
    flash (opcion headshot 1) {
        sova num1 heal num2;
    } smoke flash (opcion headshot 2) {
        sova num1 damage num2;
    } smoke flash (opcion headshot 3) {
        sova num1 kill num2;
    } smoke flash (opcion headshot 4) {
        flash (num2 headshot 0) {
            sova "Error: División por cero";
        } smoke {
            sova num1 share num2;
        }
    }
    
    plant 0;
}
```

### 2. Factorial
```
agent factorial(sage n) {
    flash (n lose 2) {
        plant 1;
    }
    plant n kill factorial(n damage 1);
}

agent spike() {
    sage numero;
    sova "Ingresa un número para calcular su factorial:";
    breach numero;
    sova factorial(numero);
    plant 0;
}
```

## Manejo de Errores Comunes

### 1. Errores Sintácticos
```
// Incorrecto
agent spike() {
    sage x = 5
    sova x;  // Falta punto y coma
}

// Correcto
agent spike() {
    sage x = 5;
    sova x;
}
```

### 2. Errores de Tipos
```
// Incorrecto
sage numero = "42";  // No se puede asignar texto a un sage

// Correcto
sage numero = 42;
cypher texto = "42";
```

### 3. Variables No Declaradas
```
// Incorrecto
sova x;  // x no está declarada

// Correcto
sage x = 0;
sova x;
```

## Consejos y Buenas Prácticas

1. **Nombres Descriptivos**: Usa nombres de variables que indiquen su propósito
2. **Indentación**: Mantén una indentación consistente para mejorar la legibilidad
3. **Comentarios**: Documenta tu código con comentarios explicativos
4. **Modularización**: Divide problemas grandes en funciones más pequeñas
5. **Manejo de Errores**: Siempre verifica casos especiales (como división por cero)

## Solución de Problemas

### El programa no compila
- Verifica que todos los puntos y comas estén en su lugar
- Asegúrate de que todas las llaves estén correctamente balanceadas
- Comprueba que las variables estén declaradas antes de usarlas

### Errores en tiempo de ejecución
- Verifica divisiones por cero
- Comprueba que los tipos de datos sean compatibles en las operaciones
- Asegúrate de que las variables tengan valores válidos

## Recursos Adicionales

- Código fuente: [GitHub Repository](https://github.com/tu-usuario/Compilador-Valorant)
- Ejemplos adicionales: Carpeta `examples/` en el repositorio
- Reportar problemas: Sección de Issues en GitHub 