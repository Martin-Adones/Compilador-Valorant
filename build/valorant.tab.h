/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_VALORANT_TAB_H_INCLUDED
# define YY_YY_BUILD_VALORANT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SAGE = 258,                    /* SAGE  */
    VIPER = 259,                   /* VIPER  */
    CYPHER = 260,                  /* CYPHER  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    INTEGER_LITERAL = 263,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 264,           /* FLOAT_LITERAL  */
    HEAL = 265,                    /* HEAL  */
    DAMAGE = 266,                  /* DAMAGE  */
    KILL = 267,                    /* KILL  */
    SHARE = 268,                   /* SHARE  */
    EQUAL = 269,                   /* EQUAL  */
    NOTEQUAL = 270,                /* NOTEQUAL  */
    LESS = 271,                    /* LESS  */
    LESSEQUAL = 272,               /* LESSEQUAL  */
    GREATER = 273,                 /* GREATER  */
    GREATEREQUAL = 274,            /* GREATEREQUAL  */
    SMOKE = 275,                   /* SMOKE  */
    FLASH = 276,                   /* FLASH  */
    DEFUSE = 277,                  /* DEFUSE  */
    IF = 278,                      /* IF  */
    ELSE = 279,                    /* ELSE  */
    WHILE = 280,                   /* WHILE  */
    FOR = 281,                     /* FOR  */
    RETURN = 282,                  /* RETURN  */
    PRINT = 283,                   /* PRINT  */
    INPUT = 284,                   /* INPUT  */
    OUTPUT = 285,                  /* OUTPUT  */
    LPAREN = 286,                  /* LPAREN  */
    RPAREN = 287,                  /* RPAREN  */
    LBRACE = 288,                  /* LBRACE  */
    RBRACE = 289,                  /* RBRACE  */
    SEMICOLON = 290,               /* SEMICOLON  */
    COMMA = 291,                   /* COMMA  */
    ASSIGN = 292                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "src/valorant.y"

    int int_val;
    float float_val;
    char* string_val;
    ASTNode* node;
    Operator op_val;

#line 109 "build/valorant.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_VALORANT_TAB_H_INCLUDED  */
