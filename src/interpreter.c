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
            // Liberar memoria si es string
            if (var->value.type == TYPE_CYPHER) {
                free(var->value.value.cypher_val);
            }
            var->value = value;
            return;
        }
        var = var->next;
    }
    
    // Si no existe, crear nueva variable
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

void report_error(ExecutionContext* context, const char* message) {
    context->error_count++;
    strncpy(context->error_message, message, sizeof(context->error_message) - 1);
    context->error_message[sizeof(context->error_message) - 1] = '\0';
    printf("Error: %s\n", message);
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
            result.type = TYPE_SAGE;
            result.value.sage_val = ast_node->value.int_value;
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
            
            if (left.type != right.type) {
                report_error(context, "Error de tipos en operación binaria");
                break;
            }
            
            result.type = left.type;
            switch(ast_node->value.op) {
                case OP_ADD: // heal
                    result.value.sage_val = left.value.sage_val + right.value.sage_val;
                    break;
                case OP_SUB: // damage
                    result.value.sage_val = left.value.sage_val - right.value.sage_val;
                    break;
                case OP_MUL: // kill
                    result.value.sage_val = left.value.sage_val * right.value.sage_val;
                    break;
                case OP_DIV: // share
                    if (right.value.sage_val == 0) {
                        report_error(context, "División por cero");
                        break;
                    }
                    result.value.sage_val = left.value.sage_val % right.value.sage_val;
                    break;
                case OP_WIN: // win (OR lógico)
                    result.value.sage_val = left.value.sage_val || right.value.sage_val;
                    break;
                case OP_LOSE: // lose (<)
                    result.value.sage_val = left.value.sage_val < right.value.sage_val;
                    break;
                case OP_HEADSHOT: // headshot (==)
                    result.value.sage_val = left.value.sage_val == right.value.sage_val;
                    break;
                case OP_SHARE: // share (asignación)
                    result = right;
                    break;
            }
            break;
        }
        case NODE_IF: {
            Value condition = interpret_node(ast_node->left, context);
            if (condition.value.sage_val) {
                result = interpret_node(ast_node->right, context);
            } else if (ast_node->next) {
                result = interpret_node(ast_node->next, context);
            }
            break;
        }
        case NODE_WHILE: {
            while (1) {
                Value condition = interpret_node(ast_node->left, context);
                if (!condition.value.sage_val) break;
                result = interpret_node(ast_node->right, context);
            }
            break;
        }
        case NODE_BLOCK: {
            // Ejecutar cada declaración en el bloque
            ASTNode* current = ast_node->left;
            while (current) {
                result = interpret_node(current, context);
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
            Value output_value = interpret_node(ast_node->left, context);
            switch(output_value.type) {
                case TYPE_SAGE:
                    printf("%d\n", output_value.value.sage_val);
                    break;
                case TYPE_VIPER:
                    printf("%f\n", output_value.value.viper_val);
                    break;
                case TYPE_CYPHER:
                    printf("%s\n", output_value.value.cypher_val);
                    break;
            }
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
            ASTNode* id_node = ast_node->left;
            Value input_value = {0};
            input_value.type = TYPE_SAGE; // Por ahora solo enteros
            printf("Ingrese un valor: ");
            scanf("%d", &input_value.value.sage_val);
            set_variable(context, id_node->value.string_value, input_value);
            result = input_value;
            break;
        }
    }
    
    return result;
} 