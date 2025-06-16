#include "../include/ast.h"
#include <stdlib.h>
#include <string.h>

// Función auxiliar para crear un nuevo nodo
ASTNode* create_node(NodeType type) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (node == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo\n");
        exit(1);
    }
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    node->children = NULL;
    node->next = NULL;
    node->parent = NULL;
    node->init = NULL;
    node->increment = NULL;
    return node;
}

ASTNode* create_number_node(int value) {
    ASTNode* node = create_node(NODE_NUMBER);
    if (node) {
        node->value.int_value = value;
        node->data_type = TYPE_INT;
    }
    return node;
}

ASTNode* create_float_node(float value) {
    ASTNode* node = create_node(NODE_NUMBER);
    if (node) {
        node->value.float_value = value;
        node->data_type = TYPE_FLOAT;
    }
    return node;
}

ASTNode* create_string_node(const char* value) {
    ASTNode* node = create_node(NODE_STRING);
    if (node) {
        node->value.string_value = strdup(value);
        node->data_type = TYPE_STRING;
    }
    return node;
}

ASTNode* create_identifier_node(const char* name) {
    ASTNode* node = create_node(NODE_IDENTIFIER);
    if (node) {
        node->value.identifier = strdup(name);
    }
    return node;
}

ASTNode* create_operator_node(BinaryOp op) {
    ASTNode* node = create_node(NODE_OPERATOR);
    node->value.op = op;
    return node;
}

ASTNode* create_binary_op_node(ASTNode* left, ASTNode* op, ASTNode* right) {
    ASTNode* node = create_node(NODE_BINARY_OP);
    node->left = left;
    node->right = right;
    node->value.op = op->value.op;
    return node;
}

ASTNode* create_assignment_node(const char* name, ASTNode* value) {
    ASTNode* node = create_node(NODE_ASSIGNMENT);
    if (node) {
        node->value.identifier = strdup(name);
        node->right = value;
    }
    return node;
}

ASTNode* create_if_node(ASTNode* condition, ASTNode* then_branch, ASTNode* else_branch) {
    ASTNode* node = create_node(NODE_IF);
    if (node) {
        node->left = condition;
        node->right = then_branch;
        node->children = else_branch;
    }
    return node;
}

ASTNode* create_while_node(ASTNode* condition, ASTNode* body) {
    ASTNode* node = create_node(NODE_WHILE);
    if (node) {
        node->left = condition;
        node->right = body;
    }
    return node;
}

ASTNode* create_for_node(ASTNode* init, ASTNode* condition, ASTNode* increment, ASTNode* body) {
    ASTNode* node = create_node(NODE_FOR);
    if (node) {
        node->left = condition;
        node->right = body;
        node->children = init;
        node->next = increment;
    }
    return node;
}

ASTNode* create_block_node(ASTNode* statements) {
    ASTNode* node = create_node(NODE_BLOCK);
    if (node) {
        node->children = statements;
    }
    return node;
}

ASTNode* create_declaration_node(const char* name, DataType type) {
    ASTNode* node = create_node(NODE_DECLARATION);
    if (node) {
        node->value.identifier = strdup(name);
        node->data_type = type;
    }
    return node;
}

ASTNode* create_input_node(ASTNode* identifier) {
    ASTNode* node = create_node(NODE_INPUT);
    if (node) {
        node->right = identifier;
    }
    return node;
}

ASTNode* create_output_node(ASTNode* value) {
    ASTNode* node = create_node(NODE_OUTPUT);
    if (node) {
        node->right = value;
    }
    return node;
}

ASTNode* create_class_node(const char* name, ASTNode* methods) {
    ASTNode* node = create_node(NODE_CLASS);
    if (node) {
        node->value.identifier = strdup(name);
        node->children = methods;
    }
    return node;
}

ASTNode* create_method_node(const char* name, ASTNode* params, ASTNode* body) {
    ASTNode* node = create_node(NODE_METHOD);
    if (node) {
        node->value.identifier = strdup(name);
        node->left = params;  // Parámetros
        node->right = body;   // Cuerpo del método
    }
    return node;
}

ASTNode* create_function_call_node(const char* name, ASTNode* args) {
    ASTNode* node = create_node(NODE_FUNCTION_CALL);
    if (node) {
        node->value.identifier = strdup(name);
        node->children = args;
    }
    return node;
}

ASTNode* create_return_node(ASTNode* value) {
    ASTNode* node = create_node(NODE_RETURN);
    if (node) {
        node->right = value;
    }
    return node;
}

ASTNode* create_print_node(ASTNode* value) {
    ASTNode* node = create_node(NODE_PRINT);
    if (node) {
        node->right = value;
    }
    return node;
}

ASTNode* create_param_node(const char* name, DataType type) {
    ASTNode* node = create_node(NODE_PARAM);
    if (node) {
        node->value.identifier = strdup(name);
        node->data_type = type;
    }
    return node;
}

ASTNode* create_param_list_node(ASTNode* param) {
    ASTNode* node = create_node(NODE_PARAM_LIST);
    if (node) {
        node->children = param;
    }
    return node;
}

ASTNode* create_arg_list_node(ASTNode* arg) {
    ASTNode* node = create_node(NODE_ARG_LIST);
    if (node) {
        node->children = arg;
    }
    return node;
}

void free_ast(ASTNode* node) {
    if (!node) return;
    
    free_ast(node->left);
    free_ast(node->right);
    free_ast(node->children);
    free_ast(node->next);
    
    if (node->type == NODE_STRING) {
        free(node->value.string_value);
    } else if (node->type == NODE_IDENTIFIER || 
               node->type == NODE_CLASS || 
               node->type == NODE_METHOD || 
               node->type == NODE_FUNCTION_CALL ||
               node->type == NODE_PARAM) {
        free(node->value.identifier);
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
            printf("Identifier: %s\n", node->value.identifier);
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
            if (node->children) print_ast(node->children, level + 1);
            return;
        case NODE_DECLARATION:
            printf("Declaration: %s (type: %d)\n", node->value.identifier, node->data_type);
            break;
        case NODE_INPUT:
            printf("Input\n");
            break;
        case NODE_OUTPUT:
            printf("Output\n");
            break;
        case NODE_CLASS:
            printf("Class: %s\n", node->value.identifier);
            break;
        case NODE_METHOD:
            printf("Method: %s\n", node->value.identifier);
            break;
        case NODE_FUNCTION_CALL:
            printf("Function Call: %s\n", node->value.identifier);
            break;
        case NODE_RETURN:
            printf("Return\n");
            break;
        case NODE_PRINT:
            printf("Print\n");
            break;
        case NODE_PARAM:
            printf("Param: %s (type: %d)\n", node->value.identifier, node->data_type);
            break;
        case NODE_PARAM_LIST:
            printf("Param List\n");
            if (node->children) print_ast(node->children, level + 1);
            break;
        case NODE_ARG_LIST:
            printf("Arg List\n");
            if (node->children) print_ast(node->children, level + 1);
            break;
    }
    
    if (node->left) print_ast(node->left, level + 1);
    if (node->right) print_ast(node->right, level + 1);
    if (node->children) print_ast(node->children, level + 1);
    if (node->next) print_ast(node->next, level);
}

char* generate_code(ASTNode* node) {
    // Esta función se implementará más adelante
    return NULL;
} 