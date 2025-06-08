#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "interpreter.h"
#include "ast.h"

ExecutionContext* create_context() {
    ExecutionContext* context = (ExecutionContext*)malloc(sizeof(ExecutionContext));
    context->variables = NULL;
    context->error_count = 0;
    context->error_message[0] = '\0';
    return context;
}

void free_context(ExecutionContext* context) {
    Variable* current = context->variables;
    while (current != NULL) {
        Variable* next = current->next;
        if (current->value.type == TYPE_CYPHER) {
            free(current->value.value.cypher_val);
        }
        free(current->name);
        free(current);
        current = next;
    }
    free(context);
}

void set_variable(ExecutionContext* context, const char* name, Value value) {
    Variable* var = context->variables;
    while (var != NULL) {
        if (strcmp(var->name, name) == 0) {
            if (var->value.type == TYPE_CYPHER) {
                free(var->value.value.cypher_val);
            }
            var->value = value;
            return;
        }
        var = var->next;
    }
    
    Variable* new_var = (Variable*)malloc(sizeof(Variable));
    new_var->name = strdup(name);
    new_var->value = value;
    new_var->next = context->variables;
    context->variables = new_var;
}

Value* get_variable(ExecutionContext* context, const char* name) {
    Variable* var = context->variables;
    while (var != NULL) {
        if (strcmp(var->name, name) == 0) {
            return &var->value;
        }
        var = var->next;
    }
    return NULL;
}

Variable* find_variable(ExecutionContext* context, const char* name) {
    Variable* current = context->variables;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void report_error(ExecutionContext* context, const char* message) {
    context->error_count++;
    strncpy(context->error_message, message, sizeof(context->error_message) - 1);
    context->error_message[sizeof(context->error_message) - 1] = '\0';
    fprintf(stderr, "Error: %s\n", message);
}

void print_value(Value value) {
    switch(value.type) {
        case TYPE_SAGE:
            printf("%d", value.value.sage_val);
            break;
        case TYPE_VIPER:
            printf("%.2f", value.value.viper_val);
            break;
        case TYPE_CYPHER:
            printf("%s", value.value.cypher_val);
            break;
    }
}

char* value_to_string(Value value) {
    char* result;
    switch(value.type) {
        case TYPE_SAGE:
            result = malloc(32);
            sprintf(result, "%d", value.value.sage_val);
            break;
        case TYPE_VIPER: {
            float num = value.value.viper_val;
            if (num == (int)num) {
                result = malloc(32);
                sprintf(result, "%.2f", num);
            } else {
                result = malloc(32);
                sprintf(result, "%g", num);
            }
            break;
        }
        case TYPE_CYPHER:
            result = strdup(value.value.cypher_val);
            break;
        default:
            result = strdup("");
    }
    return result;
}

Value interpret_node(void* node, ExecutionContext* context) {
    if (!node) {
        Value null_value = {0};
        return null_value;
    }

    ASTNode* ast_node = (ASTNode*)node;
    Value result = {0};
    result.type = TYPE_SAGE;
    
    switch(ast_node->type) {
        case NODE_NUMBER: {
            if (ast_node->data_type == TYPE_INT) {
                result.type = TYPE_SAGE;
                result.value.sage_val = ast_node->value.int_value;
                if (ast_node->parent && ast_node->parent->type == NODE_PLANT) {
                    context->error_count = 0;
                    strcpy(context->error_message, "Programa terminado");
                }
            } else if (ast_node->data_type == TYPE_FLOAT) {
                result.type = TYPE_VIPER;
                result.value.viper_val = ast_node->value.float_value;
            }
            break;
        }
        case NODE_STRING: {
            result.type = TYPE_CYPHER;
            result.value.cypher_val = strdup(ast_node->value.string_value);
            break;
        }
        case NODE_IDENTIFIER: {
            Value* var = get_variable(context, ast_node->value.string_value);
            if (!var) {
                report_error(context, "Variable no declarada");
                break;
            }
            result = *var;
            break;
        }
        case NODE_BINARY_OP: {
            Value left = interpret_node(ast_node->left, context);
            Value right = interpret_node(ast_node->right, context);
            float left_val = (left.type == TYPE_VIPER) ? left.value.viper_val : (float)left.value.sage_val;
            float right_val = (right.type == TYPE_VIPER) ? right.value.viper_val : (float)right.value.sage_val;
            
            if (ast_node->value.op == OP_ADD) {
                if (left.type == TYPE_CYPHER || right.type == TYPE_CYPHER) {
                    char* left_str = value_to_string(left);
                    char* right_str = value_to_string(right);
                    size_t total_len = strlen(left_str) + strlen(right_str) + 1;
                    char* concat = malloc(total_len);
                    strcpy(concat, left_str);
                    strcat(concat, right_str);
                    free(left_str);
                    free(right_str);
                    
                    result.type = TYPE_CYPHER;
                    result.value.cypher_val = concat;
                    break;
                }
            }
            
            if (left.type == TYPE_CYPHER || right.type == TYPE_CYPHER) {
                result.type = TYPE_SAGE;
                switch(ast_node->value.op) {
                    case OP_HEADSHOT:
                        if (left.type == TYPE_CYPHER && right.type == TYPE_CYPHER) {
                            result.value.sage_val = strcmp(left.value.cypher_val, right.value.cypher_val) == 0;
                        } else {
                            result.value.sage_val = 0;
                        }
                        break;
                    case OP_NOTEQUAL:
                        if (left.type == TYPE_CYPHER && right.type == TYPE_CYPHER) {
                            result.value.sage_val = strcmp(left.value.cypher_val, right.value.cypher_val) != 0;
                        } else if (left.type == TYPE_VIPER || right.type == TYPE_VIPER) {
                            result.value.sage_val = fabs(left_val - right_val) >= 0.000001;
                        } else {
                            result.value.sage_val = left.value.sage_val != right.value.sage_val;
                        }
                        break;
                    case OP_LESSEQUAL:
                        result.value.sage_val = left_val <= right_val;
                        break;
                    case OP_GREATEREQUAL:
                        result.value.sage_val = left_val >= right_val;
                        break;
                    default:
                        report_error(context, "Operación no soportada con strings");
                        break;
                }
                break;
            }
            
            result.type = (left.type == TYPE_VIPER || right.type == TYPE_VIPER) ? TYPE_VIPER : TYPE_SAGE;
            
            switch(ast_node->value.op) {
                case OP_ADD:
                    if (result.type == TYPE_VIPER) {
                        result.value.viper_val = left_val + right_val;
                    } else {
                        result.value.sage_val = left.value.sage_val + right.value.sage_val;
                    }
                    break;
                case OP_SUB:
                    if (result.type == TYPE_VIPER) {
                        result.value.viper_val = left_val - right_val;
                    } else {
                        result.value.sage_val = left.value.sage_val - right.value.sage_val;
                    }
                    break;
                case OP_MUL:
                    if (result.type == TYPE_VIPER) {
                        result.value.viper_val = left_val * right_val;
                    } else {
                        result.value.sage_val = left.value.sage_val * right.value.sage_val;
                    }
                    break;
                case OP_DIV:
                    if ((result.type == TYPE_VIPER && right_val == 0.0) ||
                        (result.type == TYPE_SAGE && right.value.sage_val == 0)) {
                        report_error(context, "Error: División por cero");
                        break;
                    }
                    if (result.type == TYPE_VIPER) {
                        result.value.viper_val = left_val / right_val;
                    } else {
                        result.value.sage_val = left.value.sage_val / right.value.sage_val;
                    }
                    break;
                case OP_WIN:
                    result.type = TYPE_SAGE;
                    result.value.sage_val = left_val > right_val;
                    break;
                case OP_LOSE:
                    result.type = TYPE_SAGE;
                    result.value.sage_val = left_val < right_val;
                    break;
                case OP_HEADSHOT:
                    result.type = TYPE_SAGE;
                    if (left.type == TYPE_VIPER || right.type == TYPE_VIPER) {
                        result.value.sage_val = fabs(left_val - right_val) < 0.000001;
                    } else {
                        result.value.sage_val = left.value.sage_val == right.value.sage_val;
                    }
                    break;
                case OP_NOTEQUAL:
                    result.type = TYPE_SAGE;
                    result.value.sage_val = left_val != right_val;
                    break;
                case OP_LESSEQUAL:
                    result.type = TYPE_SAGE;
                    result.value.sage_val = left_val <= right_val;
                    break;
                case OP_GREATEREQUAL:
                    result.type = TYPE_SAGE;
                    result.value.sage_val = left_val >= right_val;
                    break;
                case OP_SHARE:
                    report_error(context, "Operación share no implementada");
                    break;
            }
            break;
        }
        case NODE_IF: {
            Value condition = interpret_node(ast_node->left, context);
            if (condition.type == TYPE_SAGE && condition.value.sage_val) {
                result = interpret_node(ast_node->right, context);
            } else if (ast_node->right && ast_node->right->next) {
                ASTNode* next_node = ast_node->right->next;
                result = interpret_node(next_node, context);
            }
            break;
        }
        case NODE_WHILE: {
            while (1) {
                Value condition = interpret_node(ast_node->left, context);
                if (!condition.value.sage_val) break;
                
                ASTNode* current = ast_node->right;
                if (current->type == NODE_BLOCK) {
                    ASTNode* block_stmt = current->left;
                    while (block_stmt) {
                        if (block_stmt->type == NODE_DEFUSE) {
                            return result;
                        }
                        result = interpret_node(block_stmt, context);
                        if (block_stmt->type == NODE_IF) {
                            ASTNode* if_block = block_stmt->right;
                            if (if_block && if_block->type == NODE_BLOCK) {
                                ASTNode* if_stmt = if_block->left;
                                while (if_stmt) {
                                    if (if_stmt->type == NODE_DEFUSE) {
                                        return result;
                                    }
                                    if_stmt = if_stmt->next;
                                }
                            }
                        }
                        block_stmt = block_stmt->next;
                    }
                } else {
                    if (current->type == NODE_DEFUSE) {
                        return result;
                    }
                    result = interpret_node(current, context);
                }
            }
            break;
        }
        case NODE_BLOCK: {
            ASTNode* current = ast_node->left;
            while (current != NULL) {
                result = interpret_node(current, context);
                if (context->error_count > 0 && strcmp(context->error_message, "Programa terminado") != 0) {
                    break;
                }
                current = current->next;
            }
            break;
        }
        case NODE_DECLARATION: {
            Value init_value = interpret_node(ast_node->right, context);
            set_variable(context, ast_node->value.string_value, init_value);
            result = init_value;
            break;
        }
        case NODE_OUTPUT: {
            Value value = interpret_node(ast_node->left, context);
            print_value(value);
            break;
        }
        case NODE_ASSIGNMENT: {
            Value right_value = interpret_node(ast_node->right, context);
            ASTNode* id_node = ast_node->left;
            set_variable(context, id_node->value.string_value, right_value);
            result = right_value;
            break;
        }
        case NODE_INPUT: {
            char buffer[256];
            ASTNode* id_node = ast_node->left;
            Variable* var = find_variable(context, id_node->value.string_value);
            
            if (!var) {
                report_error(context, "Variable no declarada");
                break;
            }
            
            if (!fgets(buffer, sizeof(buffer), stdin)) {
                report_error(context, "Error al leer la entrada");
                break;
            }
            
            buffer[strcspn(buffer, "\n")] = 0;
            
            switch(var->value.type) {
                case TYPE_SAGE:
                    var->value.value.sage_val = atoi(buffer);
                    break;
                case TYPE_VIPER:
                    var->value.value.viper_val = atof(buffer);
                    break;
                case TYPE_CYPHER:
                    if (var->value.value.cypher_val) {
                        free(var->value.value.cypher_val);
                    }
                    var->value.value.cypher_val = strdup(buffer);
                    break;
            }
            result = var->value;
            break;
        }
        case NODE_DEFUSE:
            return result;
        case NODE_FOR: {
            if (ast_node->init) {
                interpret_node(ast_node->init, context);
            }
            
            while (1) {
                Value condition = interpret_node(ast_node->left, context);
                if (!condition.value.sage_val) break;
                
                ASTNode* current = ast_node->right;
                if (current->type == NODE_BLOCK) {
                    ASTNode* block_stmt = current->left;
                    while (block_stmt) {
                        if (block_stmt->type == NODE_DEFUSE) {
                            return result;
                        }
                        result = interpret_node(block_stmt, context);
                        if (block_stmt->type == NODE_IF) {
                            ASTNode* if_block = block_stmt->right;
                            if (if_block && if_block->type == NODE_BLOCK) {
                                ASTNode* if_stmt = if_block->left;
                                while (if_stmt) {
                                    if (if_stmt->type == NODE_DEFUSE) {
                                        return result;
                                    }
                                    if_stmt = if_stmt->next;
                                }
                            }
                        }
                        block_stmt = block_stmt->next;
                    }
                } else {
                    if (current->type == NODE_DEFUSE) {
                        return result;
                    }
                    result = interpret_node(current, context);
                }
                
                if (ast_node->increment) {
                    interpret_node(ast_node->increment, context);
                }
            }
            break;
        }
        case NODE_ELSE:
        case NODE_PLANT:
            // Implementación pendiente
            break;
    }
    
    return result;
}

void interpret_program(ASTNode* program) {
    ExecutionContext* context = create_context();
    Value result = interpret_node(program, context);
    
    if (context->error_count > 0 && strcmp(context->error_message, "Programa terminado") != 0) {
        printf("\nPrograma terminado con errores\n");
    }
    
    free_context(context);
}