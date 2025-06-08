# ⚔️ Valorant Compiler

Un compilador personalizado creado con **Flex**, **Bison** y **C** que implementa un lenguaje inspirado en **Valorant**, utilizando palabras clave relacionadas con el juego para representar tipos de datos, operaciones y estructuras de control típicas en programación.

---

## 📋 Descripción General

Este lenguaje de programación es una mezcla entre la sintaxis tradicional y palabras clave temáticas de Valorant. Permite declarar variables, realizar operaciones aritméticas, controlar flujo de ejecución, manejar funciones, y hacer entrada/salida de datos.

---

## 🧠 Estructura del Lenguaje

### Tipos de Datos

| Palabra Clave | Tipo de Dato | Descripción           |
| ------------- | ------------ | --------------------- |
| sage          | int          | Enteros               |
| viper         | float        | Números con decimales |
| cypher        | string       | Cadenas de texto      |

---

### Operadores Aritméticos

| Palabra Clave | Operador | Descripción    |
| ------------- | -------- | -------------- |
| heal          | +        | Suma           |
| damage        | -        | Resta          |
| kill          | \*       | Multiplicación |
| share         | /        | División       |

---

### Operadores Relacionales

| Palabra Clave | Operador | Descripción   |
| ------------- | -------- | ------------- |
| win           | >        | Mayor que     |
| lose          | <        | Menor que     |
| headshot      | ==       | Igualdad      |
| eco           | !=       | Diferente     |
| save          | <=       | Menor o igual |
| fullbuy       | >=       | Mayor o igual |

---

### Control de Flujo

| Palabra Clave | Equivalente en C/C++ | Descripción             |
| ------------- | -------------------- | ----------------------- |
| flash         | if                   | Condicional             |
| smoke         | else                 | Condicional alternativa |
| rush          | for                  | Bucle for               |
| rotate        | while                | Bucle while             |
| defuse        | break                | Romper bucle            |

---

### Funciones y Otros

| Palabra Clave | Descripción              |
| ------------- | ------------------------ |
| agent         | Declarar función         |
| plant         | Palabra reservada return |
| breach        | Entrada (input)          |
| sova          | Salida (output)          |

---

## 💡 Variables y Declaración

- Las variables se declaran con los tipos `sage`, `viper` o `cypher`.
- Ejemplo:

```
sage kills = 10;
viper accuracy = 95.5;
cypher playerName = "Sova";
```

---

## 📥 Entrada y Salida

- Para recibir entrada de usuario se usa la palabra clave `breach`.
- Para imprimir en pantalla se usa `sova`.

---

## 🛠️ Operadores y Sintaxis

- Las operaciones aritméticas y lógicas utilizan las palabras clave en lugar de símbolos.
- Ejemplo de suma:

```
sage a = 10;
sage b = 20;
sage c = a heal b;  // c = 30
```

---

## ⚙️ Ejemplo Básico

```valorant
agent main() {
    sage kills = 5;
    viper accuracy = 99.9;
    cypher name = "Phoenix";
    sova("Player: ", name);
    sova("Kills: ", kills);
    sova("Accuracy: ", accuracy);
    if (kills win 3) {
        sova("Good job!");
    } else {
        sova("Keep trying.");
    }
}
```

---

## 🧩 Comentarios

- Comentarios de una sola línea con `//`
- Se ignoran espacios y tabulaciones

---

## 🔧 Notas Técnicas

- El compilador está basado en Flex (análisis léxico), Bison (análisis sintáctico) y código C para la semántica.
- Soporta control de flujo completo con condicionales y ciclos.
- Incluye manejo de funciones y retorno.

---

## 📚 Referencias

- Flex: https://github.com/westes/flex
- Bison: https://www.gnu.org/software/bison/

---

¡Gracias por usar el compilador Valorant! 🎮
