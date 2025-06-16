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
    NODE_PLANT,       // Return
    NODE_FOR,         // For loop
    NODE_CLASS,       // Clase
    NODE_METHOD,      // Método
    NODE_FUNCTION_CALL, // Llamada a función
    NODE_PARAM,       // Parámetro
    NODE_PARAM_LIST,  // Lista de parámetros
    NODE_ARG_LIST,    // Lista de argumentos
    NODE_OPERATOR     // Operador
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
    OP_ADD,           // +
    OP_SUB,           // -
    OP_MUL,           // *
    OP_DIV,           // /
    OP_WIN,           // win (mayor que)
    OP_LOSE,          // lose (menor que)
    OP_HEADSHOT,      // headshot (igual)
    OP_NOTEQUAL,      // eco (diferente)
    OP_LESSEQUAL,     // save (<=)
    OP_GREATEREQUAL,  // fullbuy (>=)
    OP_SHARE,         // share (asignación)
    OP_EQ,            // ==
    OP_NEQ,           // !=
    OP_LT,            // <
    OP_GT,            // >
    OP_LE,            // <=
    OP_GE             // >=
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
    struct ASTNode* children;
    struct ASTNode* next;  // Para listas de instrucciones
    struct ASTNode* parent; // Referencia al nodo padre
    struct ASTNode* init;  // For loop initialization
    struct ASTNode* increment; // For loop increment
} ASTNode;

// Funciones de creación de nodos
ASTNode* create_node(NodeType type);
ASTNode* create_number_node(int value);
ASTNode* create_float_node(float value);
ASTNode* create_string_node(const char* value);
ASTNode* create_identifier_node(char* name);
ASTNode* create_binary_op_node(ASTNode* left, ASTNode* op, ASTNode* right);
ASTNode* create_assignment_node(ASTNode* left, ASTNode* right);
ASTNode* create_if_node(ASTNode* condition, ASTNode* then_block, ASTNode* else_block);
ASTNode* create_while_node(ASTNode* condition, ASTNode* body);
ASTNode* create_block_node(ASTNode* statements);
ASTNode* create_declaration_node(DataType type, const char* name, ASTNode* initial_value);
ASTNode* create_input_node(ASTNode* variable);
ASTNode* create_output_node(ASTNode* expression);
ASTNode* create_for_node(ASTNode* init, ASTNode* condition, ASTNode* increment, ASTNode* body);
ASTNode* create_class_node(const char* name, ASTNode* methods);
ASTNode* create_method_node(const char* name, ASTNode* params, ASTNode* body);
ASTNode* create_function_call_node(const char* name, ASTNode* args);
ASTNode* create_return_node(ASTNode* expression);
ASTNode* create_param_node(const char* name, DataType type);
ASTNode* create_param_list_node(ASTNode* param);
ASTNode* create_arg_list_node(ASTNode* arg);
ASTNode* create_operator_node(BinaryOp op);

// Funciones de manejo del AST
void free_ast(ASTNode* node);
void print_ast(ASTNode* node, int level);
char* generate_code(ASTNode* node);

#endif // AST_H 