#include <stdio.h>
#include <windows.h>
#include "ast.h"
#include "interpreter.h"

extern int yyparse();
extern FILE* yyin;
extern ASTNode* root;

int main(int argc, char** argv) {
    // Configurar codificación para Windows
    SetConsoleOutputCP(CP_UTF8);
    
    printf("Compilador Valorant v1.0\n");
    
    // Configurar entrada
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Error: No se pudo abrir el archivo %s\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }
    
    // Análisis léxico y sintáctico
    if (yyparse() != 0) {
        printf("Error en el análisis sintáctico\n");
        if (argc > 1) fclose(yyin);
        return 1;
    }
    
    printf("Análisis sintáctico completado con éxito.\n");
    
    if (!root) {
        printf("Error: AST vacío\n");
        if (argc > 1) fclose(yyin);
        return 1;
    }
    
    // Imprimir AST para depuración
    printf("\nÁrbol de Sintaxis Abstracta:\n");
    printf("---------------------------\n");
    print_ast(root, 0);
    
    // Crear contexto de ejecución
    ExecutionContext* context = create_context();
    
    // Interpretar el programa
    printf("\nEjecutando el programa:\n");
    printf("----------------------\n");
    Value result = interpret_node(root, context);
    
    // Verificar si hubo errores
    if (context->error_count > 0) {
        printf("\nEl programa terminó con %d error(es)\n", context->error_count);
        printf("Último error: %s\n", context->error_message);
    } else {
        printf("\nPrograma ejecutado exitosamente\n");
        printf("Valor de retorno: %d\n", result.value.sage_val);
    }
    
    // Liberar memoria
    free_context(context);
    free_ast(root);
    if (argc > 1) fclose(yyin);
    
    return 0;
}
