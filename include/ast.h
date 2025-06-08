#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipos de nodos del AST
typedef enum {
    NODE_NUMBER,      // Números literales
    NODE_STRING,      // Cadenas literales
    NODE_IDENTIFIER,  // Identificadores
    NODE_BINARY_OP,   // Operaciones binarias
    NODE_ASSIGNMENT,  // Asignaciones
    NODE_IF,          // Estructura if
    NODE_ELSE,        // Estructura else
    NODE_WHILE,       // Estructura while
    NODE_BLOCK,       // Bloque de código
    NODE_DECLARATION, // Declaración de variables
    NODE_INPUT,       // Entrada (scanf)
    NODE_OUTPUT,      // Salida (printf)
    NODE_DEFUSE,      // Break
    NODE_PLANT        // Return
} NodeType;

// Tipos de datos
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_VOID
} DataType;

// Operadores binarios
typedef enum {
    OP_ADD,      // +
    OP_SUB,      // -
    OP_MUL,      // *
    OP_DIV,      // /
    OP_WIN,      // win (mayor que)
    OP_LOSE,     // lose (menor que)
    OP_HEADSHOT, // headshot (igual)
    OP_SHARE     // share (asignación)
} BinaryOp;

typedef union {
    int int_value;
    float float_value;
    char* string_value;
    char* identifier;
    BinaryOp op;
    DataType type;
} NodeValue;

// Estructura base para un nodo del AST
typedef struct ASTNode {
    NodeType type;
    DataType data_type;
    NodeValue value;
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* next;  // Para listas de instrucciones
    struct ASTNode* parent; // Referencia al nodo padre
} ASTNode;

// Funciones de creación de nodos
ASTNode* create_node(NodeType type);
ASTNode* create_number_node(int value);
ASTNode* create_float_node(float value);
ASTNode* create_string_node(const char* value);
ASTNode* create_identifier_node(char* name);
ASTNode* create_binary_op_node(BinaryOp op, ASTNode* left, ASTNode* right);
ASTNode* create_assignment_node(ASTNode* left, ASTNode* right);
ASTNode* create_if_node(ASTNode* condition, ASTNode* then_block, ASTNode* else_block);
ASTNode* create_while_node(ASTNode* condition, ASTNode* body);
ASTNode* create_block_node(ASTNode* statements);
ASTNode* create_declaration_node(DataType type, const char* name, ASTNode* initial_value);
ASTNode* create_input_node(ASTNode* variable);
ASTNode* create_output_node(ASTNode* expression);

// Funciones de manejo del AST
void free_ast(ASTNode* node);
void print_ast(ASTNode* node, int level);
char* generate_code(ASTNode* node);

#endif // AST_H 