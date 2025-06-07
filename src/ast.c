#include "../include/ast.h"

// Función auxiliar para crear un nuevo nodo
ASTNode* create_node(NodeType type) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo AST\n");
        exit(1);
    }
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

ASTNode* create_number_node(int value) {
    ASTNode* node = create_node(NODE_NUMBER);
    node->data_type = TYPE_INT;
    node->value.int_value = value;
    return node;
}

ASTNode* create_float_node(float value) {
    ASTNode* node = create_node(NODE_NUMBER);
    node->data_type = TYPE_FLOAT;
    node->value.float_value = value;
    return node;
}

ASTNode* create_string_node(const char* value) {
    ASTNode* node = create_node(NODE_STRING);
    node->data_type = TYPE_STRING;
    node->value.string_value = strdup(value);
    return node;
}

ASTNode* create_identifier_node(char* name) {
    ASTNode* node = create_node(NODE_IDENTIFIER);
    node->value.identifier = strdup(name);
    return node;
}

ASTNode* create_binary_op_node(BinaryOp op, ASTNode* left, ASTNode* right) {
    ASTNode* node = create_node(NODE_BINARY_OP);
    node->value.op = op;
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* create_assignment_node(ASTNode* left, ASTNode* right) {
    ASTNode* node = create_node(NODE_ASSIGNMENT);
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* create_if_node(ASTNode* condition, ASTNode* then_block, ASTNode* else_block) {
    ASTNode* node = create_node(NODE_IF);
    node->left = condition;
    node->right = then_block;
    node->next = else_block;
    return node;
}

ASTNode* create_while_node(ASTNode* condition, ASTNode* body) {
    ASTNode* node = create_node(NODE_WHILE);
    node->left = condition;
    node->right = body;
    return node;
}

ASTNode* create_block_node(ASTNode* statements) {
    ASTNode* node = create_node(NODE_BLOCK);
    node->left = statements;
    return node;
}

ASTNode* create_declaration_node(DataType type, const char* name, ASTNode* initial_value) {
    ASTNode* node = create_node(NODE_DECLARATION);
    node->data_type = type;
    node->value.string_value = strdup(name);
    node->right = initial_value;
    return node;
}

ASTNode* create_input_node(ASTNode* variable) {
    ASTNode* node = create_node(NODE_INPUT);
    node->left = variable;
    return node;
}

ASTNode* create_output_node(ASTNode* expression) {
    ASTNode* node = create_node(NODE_OUTPUT);
    node->left = expression;
    return node;
}

void free_ast(ASTNode* node) {
    if (!node) return;
    
    free_ast(node->left);
    free_ast(node->right);
    free_ast(node->next);
    
    if (node->type == NODE_STRING || node->type == NODE_IDENTIFIER || 
        node->type == NODE_DECLARATION) {
        free(node->value.string_value);
    }
    
    free(node);
}

void print_ast(ASTNode* node, int level) {
    if (!node) return;
    
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    
    switch (node->type) {
        case NODE_NUMBER:
            if (node->data_type == TYPE_INT)
                printf("Number(int): %d\n", node->value.int_value);
            else
                printf("Number(float): %f\n", node->value.float_value);
            break;
        case NODE_STRING:
            printf("String: %s\n", node->value.string_value);
            break;
        case NODE_IDENTIFIER:
            printf("Identifier: %s\n", node->value.string_value);
            break;
        case NODE_BINARY_OP:
            printf("BinaryOp: %d\n", node->value.op);
            break;
        case NODE_ASSIGNMENT:
            printf("Assignment\n");
            break;
        case NODE_IF:
            printf("If\n");
            break;
        case NODE_WHILE:
            printf("While\n");
            break;
        case NODE_BLOCK:
            printf("Block\n");
            if (node->left) print_ast(node->left, level + 1);
            if (node->next) print_ast(node->next, level);
            return;
        case NODE_DECLARATION:
            printf("Declaration: %s (type: %d)\n", node->value.string_value, node->data_type);
            break;
        case NODE_INPUT:
            printf("Input\n");
            break;
        case NODE_OUTPUT:
            printf("Output\n");
            break;
    }
    
    if (node->left) print_ast(node->left, level + 1);
    if (node->right) print_ast(node->right, level + 1);
    if (node->next) print_ast(node->next, level);
}

char* generate_code(ASTNode* node) {
    // Esta función se implementará más adelante
    return NULL;
} 