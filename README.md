# Compilador Valorant (`.val`)

Este proyecto es un compilador personalizado inspirado en el lenguaje C++, pero tematizado con el universo de **Valorant**. Está desarrollado con **Flex**, **Bison** y **C**. El lenguaje tiene su propia sintaxis, tipos de datos únicos, estructuras de control y un sistema de interpretación basado en un Árbol de Sintaxis Abstracta (AST).

## 🧠 Estructura General

El compilador realiza las siguientes etapas:

1. **Análisis Léxico:** Definido en `valorant.l` usando Flex.
2. **Análisis Sintáctico:** Definido en `valorant.y` usando Bison.
3. **Construcción de AST:** Cada instrucción y expresión se representa como un nodo.
4. **Interpretación:** Recorre el AST e interpreta el programa en tiempo de ejecución.

---

## 🧾 Extensión del archivo fuente

Todos los archivos fuente del lenguaje deben tener la extensión:

.val

---

## 🧩 Tipos de datos

Los tipos están inspirados en agentes de Valorant:

| Tipo Valorant | Equivalente en C | Descripción               |
| ------------- | ---------------- | ------------------------- |
| `SAGE`        | `int`            | Números enteros           |
| `VIPER`       | `float`          | Números con punto decimal |
| `CYPHER`      | `char*`          | Cadenas de texto          |

---

## 🔑 Palabras clave y operadores

| Palabra clave Valorant | Función                        |
| ---------------------- | ------------------------------ |
| `plantar`              | Declarar variables             |
| `one tap`              | Asignar valor a una variable   |
| `prime`                | Imprimir en consola (`printf`) |
| `spike planted`        | Marca el inicio del programa   |
| `spike defused`        | Marca el final del programa    |
| `clutch`               | Entrada por teclado (`scanf`)  |
| `if`, `else`           | Condicionales                  |
| `while`, `for`         | Bucles                         |
| `break`, `continue`    | Control de bucles              |

### Operadores personalizados

| Operador Valorant                | Descripción          |
| -------------------------------- | -------------------- |
| `win`                            | Suma (`+`)           |
| `lose`                           | Resta (`-`)          |
| `spray`                          | Multiplicación (`*`) |
| `eco`                            | División (`/`)       |
| `peek`                           | Módulo (`%`)         |
| `==`, `!=`, `<`, `>`, `<=`, `>=` | Comparación          |

---

## 🌲 Estructura del AST

Cada nodo tiene una estructura común:

```c
typedef struct ASTNode {
    NodeType type;         // Tipo de nodo (ej. PLANT, ASSIGN, PRINT)
    DataType data_type;    // Tipo de dato (SAGE, VIPER, CYPHER)
    char* name;            // Nombre de variable (si aplica)
    union {                // Valor si es constante
        int int_val;
        float float_val;
        char* str_val;
    };
    struct ASTNode* left;  // Hijo izquierdo
    struct ASTNode* right; // Hijo derecho
    struct ASTNode* extra; // Nodo adicional (ej. cuerpo de bucle)
} ASTNode;
```
