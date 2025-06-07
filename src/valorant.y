%{
#include <stdio.h>
#include <stdlib.h>
#include "../include/ast.h"

extern int yylex();
extern int line_num;
extern char* yytext;
extern FILE* yyin;
void yyerror(const char* s);

ASTNode* root = NULL;

// Para depuración
#define YYDEBUG 1
%}

%union {
    int int_val;
    float float_val;
    char* string_val;
    ASTNode* ast_node;
}

/* Tokens */
%token AGENT PLANT
%token WIN LOSE HEADSHOT SHARE
%token HEAL DAMAGE KILL
%token DEFUSE ROTATE FLASH SMOKE
%token SAGE VIPER CYPHER
%token BREACH SOVA

%token <int_val> INT_LITERAL
%token <float_val> FLOAT_LITERAL
%token <string_val> STRING_LITERAL
%token <string_val> IDENTIFIER

/* Tipos de no terminales */
%type <ast_node> program function_list function
%type <ast_node> statement_list statement
%type <ast_node> expression declaration
%type <ast_node> if_statement while_statement
%type <ast_node> input_statement output_statement
%type <ast_node> block return_statement
%type <ast_node> assignment

/* Precedencia y asociatividad */
%right '='
%left WIN LOSE HEADSHOT
%left HEAL DAMAGE
%left KILL SHARE

%%

program
    : function_list                    { root = $1; }
    ;

function_list
    : function                        { $$ = $1; }
    | function_list function          { 
        ASTNode* temp = $1;
        while (temp->next) temp = temp->next;
        temp->next = $2;
        $$ = $1;
    }
    ;

function
    : AGENT IDENTIFIER '(' ')' block  { 
        if (strcmp($2, "spike") == 0) {
            $$ = $5; // Para la función spike, solo retornamos el bloque
        } else {
            $$ = create_declaration_node(TYPE_VOID, $2, $5);
        }
        free($2);
    }
    ;

block
    : '{' statement_list '}'          { $$ = create_block_node($2); }
    | '{' '}'                         { $$ = create_block_node(NULL); }
    ;

statement_list
    : statement                       { $$ = $1; }
    | statement_list statement        {
        if ($1 == NULL) {
            $$ = $2;
        } else {
            ASTNode* temp = $1;
            while (temp->next) temp = temp->next;
            temp->next = $2;
            $$ = $1;
        }
    }
    ;

statement
    : declaration ';'                 { $$ = $1; }
    | IDENTIFIER '=' expression ';'   {
        ASTNode* node = create_node(NODE_ASSIGNMENT);
        node->left = create_identifier_node($1);
        node->right = $3;
        $$ = node;
    }
    | if_statement                    { $$ = $1; }
    | while_statement                 { $$ = $1; }
    | input_statement ';'             { $$ = $1; }
    | output_statement ';'            { $$ = $1; }
    | return_statement ';'            { $$ = $1; }
    | DEFUSE ';'                      { 
        ASTNode* node = create_node(NODE_DEFUSE);
        $$ = node;
    }
    ;

declaration
    : SAGE IDENTIFIER '=' expression  { $$ = create_declaration_node(TYPE_INT, $2, $4); free($2); }
    | VIPER IDENTIFIER '=' expression { $$ = create_declaration_node(TYPE_FLOAT, $2, $4); free($2); }
    | CYPHER IDENTIFIER '=' expression { $$ = create_declaration_node(TYPE_STRING, $2, $4); free($2); }
    ;

expression
    : INT_LITERAL                     { $$ = create_number_node($1); }
    | FLOAT_LITERAL                   { $$ = create_float_node($1); }
    | STRING_LITERAL                  { $$ = create_string_node($1); free($1); }
    | IDENTIFIER                      { $$ = create_identifier_node($1); free($1); }
    | IDENTIFIER '=' expression       { 
        $$ = create_assignment_node(create_identifier_node($1), $3);
        free($1);
    }
    | expression HEAL expression      { $$ = create_binary_op_node(OP_ADD, $1, $3); }
    | expression DAMAGE expression    { $$ = create_binary_op_node(OP_SUB, $1, $3); }
    | expression KILL expression      { $$ = create_binary_op_node(OP_MUL, $1, $3); }
    | expression SHARE expression     { $$ = create_binary_op_node(OP_DIV, $1, $3); }
    | expression WIN expression       { $$ = create_binary_op_node(OP_WIN, $1, $3); }
    | expression LOSE expression      { $$ = create_binary_op_node(OP_LOSE, $1, $3); }
    | expression HEADSHOT expression  { $$ = create_binary_op_node(OP_HEADSHOT, $1, $3); }
    | '(' expression ')'             { $$ = $2; }
    ;

if_statement
    : FLASH '(' expression ')' block              { $$ = create_if_node($3, $5, NULL); }
    | FLASH '(' expression ')' block SMOKE block  { $$ = create_if_node($3, $5, $7); }
    ;

while_statement
    : ROTATE '(' expression ')' block { $$ = create_while_node($3, $5); }
    ;

input_statement
    : BREACH IDENTIFIER              { 
        $$ = create_input_node(create_identifier_node($2));
        free($2);
    }
    ;

output_statement
    : SOVA expression               { $$ = create_output_node($2); }
    ;

return_statement
    : PLANT expression              { $$ = $2; }
    ;

assignment
    : IDENTIFIER '=' expression {
        ASTNode* node = create_node(NODE_ASSIGNMENT);
        node->left = create_identifier_node($1);
        node->right = $3;
        $$ = node;
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error de sintaxis en línea %d cerca de '%s': %s\n", 
            line_num, yytext, s);
}
