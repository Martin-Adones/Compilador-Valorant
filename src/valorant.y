%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ast.h"

void yyerror(const char *s);
int yylex(void);
extern int yylineno;
%}

%union {
    int int_val;
    float float_val;
    char* string_val;
    ASTNode* node;
    BinaryOp op_val;
}

%token <int_val> SAGE
%token <float_val> VIPER
%token <string_val> CYPHER
%token <string_val> IDENTIFIER
%token <string_val> STRING_LITERAL
%token <int_val> INTEGER_LITERAL
%token <float_val> FLOAT_LITERAL

%token <op_val> HEAL DAMAGE KILL SHARE
%token <op_val> EQUAL NOTEQUAL LESS LESSEQUAL GREATER GREATEREQUAL
%token SMOKE FLASH DEFUSE
%token IF ELSE WHILE FOR RETURN
%token PRINT INPUT OUTPUT
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA
%token ASSIGN

%type <node> program
%type <node> class_declaration
%type <node> method_declaration
%type <node> block
%type <node> statement
%type <node> declaration
%type <node> assignment
%type <node> if_statement
%type <node> while_statement
%type <node> for_statement
%type <node> return_statement
%type <node> print_statement
%type <node> input_statement
%type <node> output_statement
%type <node> expression
%type <node> param_list
%type <node> param
%type <node> arg_list

%%

program
    : class_declaration { $$ = $1; }
    ;

class_declaration
    : SAGE IDENTIFIER LBRACE method_declaration RBRACE { $$ = create_class_node($2, $4); }
    ;

method_declaration
    : SAGE IDENTIFIER LPAREN param_list RPAREN block { $$ = create_method_node($2, $4, $6); }
    | SAGE IDENTIFIER LPAREN RPAREN block { $$ = create_method_node($2, NULL, $5); }
    ;

param_list
    : param { $$ = create_param_list_node($1); }
    | param_list COMMA param { $$ = $1; $1->next = $3; }
    ;

param
    : SAGE IDENTIFIER { $$ = create_param_node($2, TYPE_INT); }
    | VIPER IDENTIFIER { $$ = create_param_node($2, TYPE_FLOAT); }
    | CYPHER IDENTIFIER { $$ = create_param_node($2, TYPE_STRING); }
    ;

block
    : LBRACE statement RBRACE { $$ = create_block_node($2); }
    ;

statement
    : declaration SEMICOLON { $$ = $1; }
    | assignment SEMICOLON { $$ = $1; }
    | if_statement { $$ = $1; }
    | while_statement { $$ = $1; }
    | for_statement { $$ = $1; }
    | return_statement SEMICOLON { $$ = $1; }
    | print_statement SEMICOLON { $$ = $1; }
    | input_statement SEMICOLON { $$ = $1; }
    | output_statement SEMICOLON { $$ = $1; }
    | expression SEMICOLON { $$ = $1; }
    | statement statement { $$ = $1; $1->next = $2; }
    ;

declaration
    : SAGE IDENTIFIER { $$ = create_declaration_node(TYPE_INT, $2, NULL); }
    | VIPER IDENTIFIER { $$ = create_declaration_node(TYPE_FLOAT, $2, NULL); }
    | CYPHER IDENTIFIER { $$ = create_declaration_node(TYPE_STRING, $2, NULL); }
    | SAGE IDENTIFIER ASSIGN expression { 
        ASTNode* decl = create_declaration_node(TYPE_INT, $2, NULL);
        ASTNode* assign = create_assignment_node(create_identifier_node($2), $4);
        assign->next = decl;
        $$ = assign;
    }
    | VIPER IDENTIFIER ASSIGN expression {
        ASTNode* decl = create_declaration_node(TYPE_FLOAT, $2, NULL);
        ASTNode* assign = create_assignment_node(create_identifier_node($2), $4);
        assign->next = decl;
        $$ = assign;
    }
    | CYPHER IDENTIFIER ASSIGN expression {
        ASTNode* decl = create_declaration_node(TYPE_STRING, $2, NULL);
        ASTNode* assign = create_assignment_node(create_identifier_node($2), $4);
        assign->next = decl;
        $$ = assign;
    }
    ;

assignment
    : IDENTIFIER ASSIGN expression { $$ = create_assignment_node(create_identifier_node($1), $3); }
    ;

if_statement
    : SMOKE FLASH LPAREN expression RPAREN block SMOKE block { $$ = create_if_node($4, $6, $8); }
    | SMOKE FLASH LPAREN expression RPAREN block { $$ = create_if_node($4, $6, NULL); }
    ;

while_statement
    : WHILE LPAREN expression RPAREN block { $$ = create_while_node($3, $5); }
    ;

for_statement
    : FOR LPAREN declaration SEMICOLON expression SEMICOLON assignment RPAREN block {
        $$ = create_for_node($3, $5, $7, $9);
    }
    ;

return_statement
    : RETURN expression { $$ = create_return_node($2); }
    ;

print_statement
    : PRINT expression { $$ = create_output_node($2); }
    ;

input_statement
    : INPUT IDENTIFIER { $$ = create_input_node(create_identifier_node($2)); }
    ;

output_statement
    : OUTPUT expression { $$ = create_output_node($2); }
    ;

expression
    : expression HEAL expression { $$ = create_binary_op_node($1, create_operator_node(OP_ADD), $3); }
    | expression DAMAGE expression { $$ = create_binary_op_node($1, create_operator_node(OP_SUB), $3); }
    | expression KILL expression { $$ = create_binary_op_node($1, create_operator_node(OP_MUL), $3); }
    | expression SHARE expression { $$ = create_binary_op_node($1, create_operator_node(OP_DIV), $3); }
    | expression EQUAL expression { $$ = create_binary_op_node($1, create_operator_node(OP_EQ), $3); }
    | expression NOTEQUAL expression { $$ = create_binary_op_node($1, create_operator_node(OP_NEQ), $3); }
    | expression LESS expression { $$ = create_binary_op_node($1, create_operator_node(OP_LT), $3); }
    | expression LESSEQUAL expression { $$ = create_binary_op_node($1, create_operator_node(OP_LE), $3); }
    | expression GREATER expression { $$ = create_binary_op_node($1, create_operator_node(OP_GT), $3); }
    | expression GREATEREQUAL expression { $$ = create_binary_op_node($1, create_operator_node(OP_GE), $3); }
    | LPAREN expression RPAREN { $$ = $2; }
    | INTEGER_LITERAL { $$ = create_number_node($1); }
    | FLOAT_LITERAL { $$ = create_float_node($1); }
    | STRING_LITERAL { $$ = create_string_node($1); }
    | IDENTIFIER { $$ = create_identifier_node($1); }
    | IDENTIFIER LPAREN arg_list RPAREN { $$ = create_function_call_node($1, $3); }
    | IDENTIFIER LPAREN RPAREN { $$ = create_function_call_node($1, NULL); }
    ;

arg_list
    : expression { $$ = create_arg_list_node($1); }
    | arg_list COMMA expression { $$ = $1; $1->next = $3; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error en línea %d: %s\n", yylineno, s);
}
