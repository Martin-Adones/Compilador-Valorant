%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ast.h"
#include "valorant.tab.h"

int line_num = 1;
%}

%option noyywrap
%option yylineno

%%

[ \t]+          ; /* Ignorar espacios y tabulaciones */
[\n]            { line_num++; }
"//".*          ; /* Ignorar comentarios de una línea */

"agent"         { return AGENT; }      /* Palabra clave para función */
"plant"         { return PLANT; }      /* Palabra clave para return */
"win"           { return WIN; }        /* Mayor que */
"lose"          { return LOSE; }       /* Menor que */
"headshot"      { return HEADSHOT; }   /* Igual */
"share"         { return SHARE; }      /* División */
"heal"          { return HEAL; }       /* Suma */
"damage"        { return DAMAGE; }     /* Resta */
"kill"          { return KILL; }       /* Multiplicación */
"defuse"        { return DEFUSE; }     /* Break */
"rotate"        { return ROTATE; }     /* While */
"flash"         { return FLASH; }      /* If */
"smoke"         { return SMOKE; }      /* Else */
"sage"          { return SAGE; }       /* Int */
"viper"         { return VIPER; }      /* Float */
"cypher"        { return CYPHER; }     /* String */
"breach"        { return BREACH; }     /* Input */
"sova"          { return SOVA; }       /* Output */

[0-9]+          { 
    yylval.int_val = atoi(yytext); 
    return INT_LITERAL;
}

[0-9]+\.[0-9]+  { 
    yylval.float_val = atof(yytext); 
    return FLOAT_LITERAL;
}

\"[^\"]*\"      {
    yylval.string_val = strdup(yytext + 1);
    yylval.string_val[strlen(yylval.string_val) - 1] = '\0';
    return STRING_LITERAL;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.string_val = strdup(yytext);
    return IDENTIFIER;
}

"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
";"             { return ';'; }
","             { return ','; }
"="             { return '='; }

.               { printf("Error léxico: caracter no reconocido '%s' en línea %d\n", yytext, line_num); }

%%
