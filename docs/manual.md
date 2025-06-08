# Manual de Usuario - Compilador Valorant

## Introducción
El Compilador Valorant es un lenguaje de programación inspirado en el juego Valorant, donde los elementos del juego se convierten en estructuras y comandos de programación.

## Instalación
1. Clona el repositorio
2. Ejecuta `setup.bat` para instalar las dependencias
3. Usa `make` para compilar el proyecto

## Sintaxis Básica

### 1. Tipos de Datos
- `sage`: Números enteros
- `viper`: Números decimales
- `cypher`: Cadenas de texto

```
sage numero = 42;        // Entero
viper decimal = 3.14;    // Decimal
cypher texto = "Hola";   // Texto
```

### 2. Operadores
- `heal`: Suma (+)
- `damage`: Resta (-)
- `kill`: Multiplicación (*)
- `share`: División (/)
- `win`: Mayor que (>)
- `lose`: Menor que (<)
- `headshot`: Igual a (==)

```
sage resultado = a heal b;    // Suma
sage resta = x damage y;      // Resta
sage producto = m kill n;     // Multiplicación
sage division = p share q;    // División
```

### 3. Estructuras de Control

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

### 4. Entrada/Salida

#### Entrada (Breach)
```
sage numero;
sova "Ingresa un número:";
breach numero;
```

#### Salida (Sova)
```
sova "Mensaje directo";
sova variable;
```

### 5. Funciones

#### Función Principal
Cada programa debe tener una función `spike()`:
```
agent spike() {
    // Código principal aquí
    plant 0;    // Retorna 0
}
```

## Ejemplos Completos

### 1. Calculadora Simple
```
agent spike() {
    sage num1;
    sage num2;
    
    sova "Ingresa primer número:";
    breach num1;
    sova "Ingresa segundo número:";
    breach num2;
    
    sova "Suma:";
    sova num1 heal num2;
    
    sova "Resta:";
    sova num1 damage num2;
    
    sova "Multiplicación:";
    sova num1 kill num2;
    
    sova "División:";
    sova num1 share num2;
    
    plant 0;
}
```

### 2. Concatenación de Strings
```
agent spike() {
    cypher nombre = "Agente";
    cypher apellido = "Valorant";
    cypher nombre_completo = nombre heal apellido;
    
    sova nombre_completo;
    plant 0;
}
```

## Manejo de Errores
- Variables no declaradas
- División por cero
- Errores de sintaxis
- Tipos incompatibles

## Mejores Prácticas
1. Siempre inicializa tus variables
2. Usa nombres descriptivos
3. Comenta tu código usando `//`
4. Verifica la división por cero
5. Maneja los errores apropiadamente

## Limitaciones Actuales
1. No soporta funciones con parámetros
2. No hay soporte para arreglos
3. Las operaciones entre tipos diferentes no están soportadas
4. No hay soporte para operaciones de punto flotante complejas

## Solución de Problemas
Si encuentras errores, verifica:
1. Que todas las variables estén declaradas
2. Que los tipos de datos sean compatibles
3. Que no haya divisiones por cero
4. Que todas las llaves y paréntesis estén balanceados
5. Que cada sentencia termine con punto y coma 