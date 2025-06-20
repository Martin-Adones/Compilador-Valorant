/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/valorant.y"

#include <stdio.h>
#include <stdlib.h>
#include "../include/ast.h"

extern int yylex();
extern int line_num;
extern char* yytext;
extern FILE* yyin;
void yyerror(const char* s);

ASTNode* root = NULL;

// Para debug, si queres ver que pasa
#define YYDEBUG 1

#line 88 "build/valorant.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "valorant.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AGENT = 3,                      /* AGENT  */
  YYSYMBOL_PLANT = 4,                      /* PLANT  */
  YYSYMBOL_WIN = 5,                        /* WIN  */
  YYSYMBOL_LOSE = 6,                       /* LOSE  */
  YYSYMBOL_HEADSHOT = 7,                   /* HEADSHOT  */
  YYSYMBOL_SHARE = 8,                      /* SHARE  */
  YYSYMBOL_HEAL = 9,                       /* HEAL  */
  YYSYMBOL_DAMAGE = 10,                    /* DAMAGE  */
  YYSYMBOL_KILL = 11,                      /* KILL  */
  YYSYMBOL_DEFUSE = 12,                    /* DEFUSE  */
  YYSYMBOL_ROTATE = 13,                    /* ROTATE  */
  YYSYMBOL_FLASH = 14,                     /* FLASH  */
  YYSYMBOL_SMOKE = 15,                     /* SMOKE  */
  YYSYMBOL_RUSH = 16,                      /* RUSH  */
  YYSYMBOL_SAGE = 17,                      /* SAGE  */
  YYSYMBOL_VIPER = 18,                     /* VIPER  */
  YYSYMBOL_CYPHER = 19,                    /* CYPHER  */
  YYSYMBOL_BREACH = 20,                    /* BREACH  */
  YYSYMBOL_SOVA = 21,                      /* SOVA  */
  YYSYMBOL_INT_LITERAL = 22,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 23,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 24,            /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 25,                /* IDENTIFIER  */
  YYSYMBOL_NOTEQUAL = 26,                  /* NOTEQUAL  */
  YYSYMBOL_LESSEQUAL = 27,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 28,              /* GREATEREQUAL  */
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_class_definition = 38,          /* class_definition  */
  YYSYMBOL_method_list = 39,               /* method_list  */
  YYSYMBOL_method = 40,                    /* method  */
  YYSYMBOL_parameter_list_opt = 41,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 42,            /* parameter_list  */
  YYSYMBOL_parameter = 43,                 /* parameter  */
  YYSYMBOL_block = 44,                     /* block  */
  YYSYMBOL_statement_list = 45,            /* statement_list  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_for_init = 47,                  /* for_init  */
  YYSYMBOL_for_condition = 48,             /* for_condition  */
  YYSYMBOL_for_increment = 49,             /* for_increment  */
  YYSYMBOL_for_statement = 50,             /* for_statement  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_expression = 52,                /* expression  */
  YYSYMBOL_if_statement = 53,              /* if_statement  */
  YYSYMBOL_else_if_chain = 54,             /* else_if_chain  */
  YYSYMBOL_while_statement = 55,           /* while_statement  */
  YYSYMBOL_input_statement = 56,           /* input_statement  */
  YYSYMBOL_output_statement = 57,          /* output_statement  */
  YYSYMBOL_return_statement = 58,          /* return_statement  */
  YYSYMBOL_assignment = 59,                /* assignment  */
  YYSYMBOL_function_call = 60,             /* function_call  */
  YYSYMBOL_argument_list_opt = 61,         /* argument_list_opt  */
  YYSYMBOL_argument_list = 62              /* argument_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    64,    71,    72,    81,    86,    91,    99,
     100,   104,   105,   114,   115,   116,   120,   121,   125,   126,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     154,   155,   159,   163,   164,   174,   186,   187,   188,   189,
     190,   191,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   214,   217,
     223,   224,   225,   226,   230,   234,   241,   245,   246,   250,
     260,   267,   268,   272,   273
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AGENT", "PLANT",
  "WIN", "LOSE", "HEADSHOT", "SHARE", "HEAL", "DAMAGE", "KILL", "DEFUSE",
  "ROTATE", "FLASH", "SMOKE", "RUSH", "SAGE", "VIPER", "CYPHER", "BREACH",
  "SOVA", "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "NOTEQUAL", "LESSEQUAL", "GREATEREQUAL", "'='", "'{'", "'}'", "'('",
  "')'", "','", "';'", "$accept", "program", "class_definition",
  "method_list", "method", "parameter_list_opt", "parameter_list",
  "parameter", "block", "statement_list", "statement", "for_init",
  "for_condition", "for_increment", "for_statement", "declaration",
  "expression", "if_statement", "else_if_chain", "while_statement",
  "input_statement", "output_statement", "return_statement", "assignment",
  "function_call", "argument_list_opt", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -12,    15,   -71,    12,   -71,    68,     6,    39,    41,
      36,   -71,    38,    51,    57,   -71,   -71,    84,    84,    84,
      65,    71,    72,    79,    81,   -71,    80,    83,   -71,   -71,
     -71,    87,    84,    87,    87,   118,   -71,   -71,   -71,   -71,
      -6,    86,    91,    92,    93,    94,   104,   115,   116,    -6,
      33,   -71,   138,   -71,   -71,   113,   -71,   -71,   125,   126,
     127,   129,   130,   -71,   -71,   -71,   121,    -6,   165,   -71,
     -71,    -6,    -6,    63,   137,   139,   148,   -71,   165,    -6,
      -6,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     1,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      30,    67,   149,   132,   -71,   -71,    -6,    -6,    -6,   165,
     165,   146,   147,   -71,   136,   136,   136,   -71,    60,    60,
     -71,   136,   136,   136,    87,    87,    -6,   165,   165,   165,
     -71,    -6,   -71,   167,   145,   165,   165,     0,   -71,   158,
     152,   -71,   156,   153,   -71,    -6,    -6,    87,   100,   165,
     -71,    87,   172,     0,   -71,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     3,     5,     9,     9,     9,
       0,     0,     0,     0,    10,    11,     0,     0,    13,    14,
      15,     0,     0,     0,     0,     0,     6,    12,     7,     8,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,    18,    24,     0,    22,    23,     0,     0,
       0,     0,     0,    42,    43,    44,    45,     0,    67,    46,
      29,     0,     0,     0,    39,    40,    41,    65,    66,     0,
      71,    16,    19,    20,    25,    26,    27,    21,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    31,     0,     0,     0,    69,
      73,     0,    72,    54,    51,    52,    53,    50,    47,    48,
      49,    55,    56,    57,     0,     0,     0,    36,    37,    38,
      70,     0,    64,    58,     0,    32,    74,     0,    59,     0,
       0,    60,     0,     0,    33,     0,     0,     0,     0,    34,
      35,     0,    61,     0,    63,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   -71,   178,     4,   -71,   157,   -33,   -71,
     142,   -71,   -71,   -71,   -71,   117,   -47,   -71,    43,   -71,
     -71,   -71,   -71,   -70,   -31,   -71,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    10,    11,    23,    24,    25,    36,    52,
      53,   103,   134,   143,    54,    55,    68,    56,   138,    57,
      58,    59,    60,    61,    69,   111,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    39,    78,   105,    62,     1,    90,    91,    92,    93,
      94,    95,    96,     4,   140,     5,    63,    64,    65,    66,
      89,    62,    26,    27,   100,   101,    67,    97,    98,    99,
      35,    12,   109,   110,   113,    90,    91,    92,    93,    94,
      95,    96,     6,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,     7,     8,     9,    97,    98,    99,   127,
     128,   129,    79,   124,    13,    80,    14,    15,    93,   144,
      17,    96,    90,    91,    92,    93,    94,    95,    96,   135,
      45,    46,    47,    18,   136,     7,     8,     9,   102,    19,
      28,   132,   133,    97,    98,    99,    29,    30,   148,   149,
     125,    20,    21,    22,   141,    90,    91,    92,    93,    94,
      95,    96,    31,    33,   150,    32,    34,    35,   152,    74,
     155,    70,    40,    71,    72,    73,    97,    98,    99,    75,
      41,    42,    43,   151,    44,    45,    46,    47,    48,    49,
      76,    77,    40,    50,    93,    94,    95,    96,    83,    51,
      41,    42,    43,    80,    44,    45,    46,    47,    48,    49,
      84,    85,    86,    50,    87,    88,   106,   126,   107,    81,
      90,    91,    92,    93,    94,    95,    96,   108,    79,   130,
     139,   131,   137,   142,   145,   146,   147,   153,    16,    37,
     104,    97,    98,    99,    82,   154
};

static const yytype_uint8 yycheck[] =
{
      33,    34,    49,    73,    35,     3,     5,     6,     7,     8,
       9,    10,    11,    25,    14,     0,    22,    23,    24,    25,
      67,    52,    18,    19,    71,    72,    32,    26,    27,    28,
      30,    25,    79,    80,    33,     5,     6,     7,     8,     9,
      10,    11,    30,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    17,    18,    19,    26,    27,    28,   106,
     107,   108,    29,    33,    25,    32,    25,    31,     8,   139,
      32,    11,     5,     6,     7,     8,     9,    10,    11,   126,
      17,    18,    19,    32,   131,    17,    18,    19,    25,    32,
      25,   124,   125,    26,    27,    28,    25,    25,   145,   146,
      33,    17,    18,    19,   137,     5,     6,     7,     8,     9,
      10,    11,    33,    33,   147,    34,    33,    30,   151,    25,
     153,    35,     4,    32,    32,    32,    26,    27,    28,    25,
      12,    13,    14,    33,    16,    17,    18,    19,    20,    21,
      25,    25,     4,    25,     8,     9,    10,    11,    35,    31,
      12,    13,    14,    32,    16,    17,    18,    19,    20,    21,
      35,    35,    35,    25,    35,    35,    29,    35,    29,    31,
       5,     6,     7,     8,     9,    10,    11,    29,    29,    33,
      35,    34,    15,    25,    32,    29,    33,    15,    10,    32,
      73,    26,    27,    28,    52,   152
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    37,    38,    25,     0,    30,    17,    18,    19,
      39,    40,    25,    25,    25,    31,    40,    32,    32,    32,
      17,    18,    19,    41,    42,    43,    41,    41,    25,    25,
      25,    33,    34,    33,    33,    30,    44,    43,    44,    44,
       4,    12,    13,    14,    16,    17,    18,    19,    20,    21,
      25,    31,    45,    46,    50,    51,    53,    55,    56,    57,
      58,    59,    60,    22,    23,    24,    25,    32,    52,    60,
      35,    32,    32,    32,    25,    25,    25,    25,    52,    29,
      32,    31,    46,    35,    35,    35,    35,    35,    35,    52,
       5,     6,     7,     8,     9,    10,    11,    26,    27,    28,
      52,    52,    25,    47,    51,    59,    29,    29,    29,    52,
      52,    61,    62,    33,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    33,    33,    35,    52,    52,    52,
      33,    34,    44,    44,    48,    52,    52,    15,    54,    35,
      14,    44,    25,    49,    59,    32,    29,    33,    52,    52,
      44,    33,    44,    15,    54,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    39,    39,    40,    40,    40,    41,
      41,    42,    42,    43,    43,    43,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    48,    49,    49,    50,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    54,    55,    56,    57,    58,    58,    59,
      60,    61,    61,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     1,     2,     6,     6,     6,     0,
       1,     1,     3,     2,     2,     2,     3,     2,     1,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     3,     9,     4,     4,     4,     2,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     6,
       2,     6,     8,     7,     5,     2,     2,     2,     1,     3,
       4,     0,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: class_definition  */
#line 60 "src/valorant.y"
                                      { root = (yyvsp[0].ast_node); }
#line 1244 "build/valorant.tab.c"
    break;

  case 3: /* class_definition: AGENT IDENTIFIER '{' method_list '}'  */
#line 64 "src/valorant.y"
                                            { 
        (yyval.ast_node) = create_class_node((yyvsp[-3].string_val), (yyvsp[-1].ast_node));
        free((yyvsp[-3].string_val));
    }
#line 1253 "build/valorant.tab.c"
    break;

  case 4: /* method_list: method  */
#line 71 "src/valorant.y"
                                     { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1259 "build/valorant.tab.c"
    break;

  case 5: /* method_list: method_list method  */
#line 72 "src/valorant.y"
                                    {
        ASTNode* temp = (yyvsp[-1].ast_node);
        while (temp->next) temp = temp->next;
        temp->next = (yyvsp[0].ast_node);
        (yyval.ast_node) = (yyvsp[-1].ast_node);
    }
#line 1270 "build/valorant.tab.c"
    break;

  case 6: /* method: SAGE IDENTIFIER '(' parameter_list_opt ')' block  */
#line 81 "src/valorant.y"
                                                        { 
        (yyval.ast_node) = create_method_node_with_params((yyvsp[-4].string_val), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
        (yyval.ast_node)->data_type = TYPE_INT;
        free((yyvsp[-4].string_val));
    }
#line 1280 "build/valorant.tab.c"
    break;

  case 7: /* method: VIPER IDENTIFIER '(' parameter_list_opt ')' block  */
#line 86 "src/valorant.y"
                                                         {
        (yyval.ast_node) = create_method_node_with_params((yyvsp[-4].string_val), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
        (yyval.ast_node)->data_type = TYPE_FLOAT;
        free((yyvsp[-4].string_val));
    }
#line 1290 "build/valorant.tab.c"
    break;

  case 8: /* method: CYPHER IDENTIFIER '(' parameter_list_opt ')' block  */
#line 91 "src/valorant.y"
                                                          {
        (yyval.ast_node) = create_method_node_with_params((yyvsp[-4].string_val), (yyvsp[-2].ast_node), (yyvsp[0].ast_node));
        (yyval.ast_node)->data_type = TYPE_STRING;
        free((yyvsp[-4].string_val));
    }
#line 1300 "build/valorant.tab.c"
    break;

  case 9: /* parameter_list_opt: %empty  */
#line 99 "src/valorant.y"
                   { (yyval.ast_node) = NULL; }
#line 1306 "build/valorant.tab.c"
    break;

  case 10: /* parameter_list_opt: parameter_list  */
#line 100 "src/valorant.y"
                     { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1312 "build/valorant.tab.c"
    break;

  case 11: /* parameter_list: parameter  */
#line 104 "src/valorant.y"
                { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1318 "build/valorant.tab.c"
    break;

  case 12: /* parameter_list: parameter_list ',' parameter  */
#line 105 "src/valorant.y"
                                   { 
        ASTNode* temp = (yyvsp[-2].ast_node);
        while (temp->next) temp = temp->next;
        temp->next = (yyvsp[0].ast_node);
        (yyval.ast_node) = (yyvsp[-2].ast_node);
    }
#line 1329 "build/valorant.tab.c"
    break;

  case 13: /* parameter: SAGE IDENTIFIER  */
#line 114 "src/valorant.y"
                      { (yyval.ast_node) = create_declaration_node(TYPE_INT, (yyvsp[0].string_val), NULL); free((yyvsp[0].string_val)); }
#line 1335 "build/valorant.tab.c"
    break;

  case 14: /* parameter: VIPER IDENTIFIER  */
#line 115 "src/valorant.y"
                       { (yyval.ast_node) = create_declaration_node(TYPE_FLOAT, (yyvsp[0].string_val), NULL); free((yyvsp[0].string_val)); }
#line 1341 "build/valorant.tab.c"
    break;

  case 15: /* parameter: CYPHER IDENTIFIER  */
#line 116 "src/valorant.y"
                        { (yyval.ast_node) = create_declaration_node(TYPE_STRING, (yyvsp[0].string_val), NULL); free((yyvsp[0].string_val)); }
#line 1347 "build/valorant.tab.c"
    break;

  case 16: /* block: '{' statement_list '}'  */
#line 120 "src/valorant.y"
                                     { (yyval.ast_node) = create_block_node((yyvsp[-1].ast_node)); }
#line 1353 "build/valorant.tab.c"
    break;

  case 17: /* block: '{' '}'  */
#line 121 "src/valorant.y"
                                     { (yyval.ast_node) = create_block_node(NULL); }
#line 1359 "build/valorant.tab.c"
    break;

  case 18: /* statement_list: statement  */
#line 125 "src/valorant.y"
                                     { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1365 "build/valorant.tab.c"
    break;

  case 19: /* statement_list: statement_list statement  */
#line 126 "src/valorant.y"
                                     {
        if ((yyvsp[-1].ast_node) == NULL) {
            (yyval.ast_node) = (yyvsp[0].ast_node);
        } else {
            ASTNode* temp = (yyvsp[-1].ast_node);
            while (temp->next) temp = temp->next;
            temp->next = (yyvsp[0].ast_node);
            (yyval.ast_node) = (yyvsp[-1].ast_node);
        }
    }
#line 1380 "build/valorant.tab.c"
    break;

  case 20: /* statement: declaration ';'  */
#line 139 "src/valorant.y"
                                     { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1386 "build/valorant.tab.c"
    break;

  case 21: /* statement: assignment ';'  */
#line 140 "src/valorant.y"
                                     { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1392 "build/valorant.tab.c"
    break;

  case 22: /* statement: if_statement  */
#line 141 "src/valorant.y"
                                     { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1398 "build/valorant.tab.c"
    break;

  case 23: /* statement: while_statement  */
#line 142 "src/valorant.y"
                                    { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1404 "build/valorant.tab.c"
    break;

  case 24: /* statement: for_statement  */
#line 143 "src/valorant.y"
                                    { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1410 "build/valorant.tab.c"
    break;

  case 25: /* statement: input_statement ';'  */
#line 144 "src/valorant.y"
                                    { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1416 "build/valorant.tab.c"
    break;

  case 26: /* statement: output_statement ';'  */
#line 145 "src/valorant.y"
                                    { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1422 "build/valorant.tab.c"
    break;

  case 27: /* statement: return_statement ';'  */
#line 146 "src/valorant.y"
                                    { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1428 "build/valorant.tab.c"
    break;

  case 28: /* statement: function_call ';'  */
#line 147 "src/valorant.y"
                                    { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1434 "build/valorant.tab.c"
    break;

  case 29: /* statement: DEFUSE ';'  */
#line 148 "src/valorant.y"
                                    { 
        (yyval.ast_node) = create_node(NODE_DEFUSE);
    }
#line 1442 "build/valorant.tab.c"
    break;

  case 30: /* for_init: declaration  */
#line 154 "src/valorant.y"
                                      { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1448 "build/valorant.tab.c"
    break;

  case 31: /* for_init: assignment  */
#line 155 "src/valorant.y"
                                      { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1454 "build/valorant.tab.c"
    break;

  case 32: /* for_condition: expression  */
#line 159 "src/valorant.y"
                                      { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1460 "build/valorant.tab.c"
    break;

  case 33: /* for_increment: assignment  */
#line 163 "src/valorant.y"
                                      { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1466 "build/valorant.tab.c"
    break;

  case 34: /* for_increment: IDENTIFIER '=' expression  */
#line 164 "src/valorant.y"
                                      {
        ASTNode* node = create_node(NODE_ASSIGNMENT);
        node->left = create_identifier_node((yyvsp[-2].string_val));
        node->right = (yyvsp[0].ast_node);
        (yyval.ast_node) = node;
        free((yyvsp[-2].string_val));
    }
#line 1478 "build/valorant.tab.c"
    break;

  case 35: /* for_statement: RUSH '(' for_init ';' for_condition ';' for_increment ')' block  */
#line 174 "src/valorant.y"
                                                                      {
        // Creamos un nodo especial para el bucle for
        ASTNode* node = create_node(NODE_FOR);
        node->init = (yyvsp[-6].ast_node);      // Inicialización
        node->left = (yyvsp[-4].ast_node);      // Condición
        node->increment = (yyvsp[-2].ast_node); // Incremento
        node->right = (yyvsp[0].ast_node);     // Cuerpo del bucle
        (yyval.ast_node) = node;
    }
#line 1492 "build/valorant.tab.c"
    break;

  case 36: /* declaration: SAGE IDENTIFIER '=' expression  */
#line 186 "src/valorant.y"
                                      { (yyval.ast_node) = create_declaration_node(TYPE_INT, (yyvsp[-2].string_val), (yyvsp[0].ast_node)); free((yyvsp[-2].string_val)); }
#line 1498 "build/valorant.tab.c"
    break;

  case 37: /* declaration: VIPER IDENTIFIER '=' expression  */
#line 187 "src/valorant.y"
                                      { (yyval.ast_node) = create_declaration_node(TYPE_FLOAT, (yyvsp[-2].string_val), (yyvsp[0].ast_node)); free((yyvsp[-2].string_val)); }
#line 1504 "build/valorant.tab.c"
    break;

  case 38: /* declaration: CYPHER IDENTIFIER '=' expression  */
#line 188 "src/valorant.y"
                                       { (yyval.ast_node) = create_declaration_node(TYPE_STRING, (yyvsp[-2].string_val), (yyvsp[0].ast_node)); free((yyvsp[-2].string_val)); }
#line 1510 "build/valorant.tab.c"
    break;

  case 39: /* declaration: SAGE IDENTIFIER  */
#line 189 "src/valorant.y"
                                      { (yyval.ast_node) = create_declaration_node(TYPE_INT, (yyvsp[0].string_val), NULL); free((yyvsp[0].string_val)); }
#line 1516 "build/valorant.tab.c"
    break;

  case 40: /* declaration: VIPER IDENTIFIER  */
#line 190 "src/valorant.y"
                                     { (yyval.ast_node) = create_declaration_node(TYPE_FLOAT, (yyvsp[0].string_val), NULL); free((yyvsp[0].string_val)); }
#line 1522 "build/valorant.tab.c"
    break;

  case 41: /* declaration: CYPHER IDENTIFIER  */
#line 191 "src/valorant.y"
                                     { (yyval.ast_node) = create_declaration_node(TYPE_STRING, (yyvsp[0].string_val), NULL); free((yyvsp[0].string_val)); }
#line 1528 "build/valorant.tab.c"
    break;

  case 42: /* expression: INT_LITERAL  */
#line 195 "src/valorant.y"
                                      { (yyval.ast_node) = create_number_node((yyvsp[0].int_val)); }
#line 1534 "build/valorant.tab.c"
    break;

  case 43: /* expression: FLOAT_LITERAL  */
#line 196 "src/valorant.y"
                                      { (yyval.ast_node) = create_float_node((yyvsp[0].float_val)); }
#line 1540 "build/valorant.tab.c"
    break;

  case 44: /* expression: STRING_LITERAL  */
#line 197 "src/valorant.y"
                                      { (yyval.ast_node) = create_string_node((yyvsp[0].string_val)); free((yyvsp[0].string_val)); }
#line 1546 "build/valorant.tab.c"
    break;

  case 45: /* expression: IDENTIFIER  */
#line 198 "src/valorant.y"
                                      { (yyval.ast_node) = create_identifier_node((yyvsp[0].string_val)); free((yyvsp[0].string_val)); }
#line 1552 "build/valorant.tab.c"
    break;

  case 46: /* expression: function_call  */
#line 199 "src/valorant.y"
                                      { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1558 "build/valorant.tab.c"
    break;

  case 47: /* expression: expression HEAL expression  */
#line 200 "src/valorant.y"
                                      { (yyval.ast_node) = create_binary_op_node(OP_ADD, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1564 "build/valorant.tab.c"
    break;

  case 48: /* expression: expression DAMAGE expression  */
#line 201 "src/valorant.y"
                                      { (yyval.ast_node) = create_binary_op_node(OP_SUB, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1570 "build/valorant.tab.c"
    break;

  case 49: /* expression: expression KILL expression  */
#line 202 "src/valorant.y"
                                      { (yyval.ast_node) = create_binary_op_node(OP_MUL, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1576 "build/valorant.tab.c"
    break;

  case 50: /* expression: expression SHARE expression  */
#line 203 "src/valorant.y"
                                      { (yyval.ast_node) = create_binary_op_node(OP_DIV, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1582 "build/valorant.tab.c"
    break;

  case 51: /* expression: expression WIN expression  */
#line 204 "src/valorant.y"
                                      { (yyval.ast_node) = create_binary_op_node(OP_WIN, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1588 "build/valorant.tab.c"
    break;

  case 52: /* expression: expression LOSE expression  */
#line 205 "src/valorant.y"
                                      { (yyval.ast_node) = create_binary_op_node(OP_LOSE, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1594 "build/valorant.tab.c"
    break;

  case 53: /* expression: expression HEADSHOT expression  */
#line 206 "src/valorant.y"
                                      { (yyval.ast_node) = create_binary_op_node(OP_HEADSHOT, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1600 "build/valorant.tab.c"
    break;

  case 54: /* expression: '(' expression ')'  */
#line 207 "src/valorant.y"
                                     { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1606 "build/valorant.tab.c"
    break;

  case 55: /* expression: expression NOTEQUAL expression  */
#line 208 "src/valorant.y"
                                           { (yyval.ast_node) = create_binary_op_node(OP_NOTEQUAL, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1612 "build/valorant.tab.c"
    break;

  case 56: /* expression: expression LESSEQUAL expression  */
#line 209 "src/valorant.y"
                                           { (yyval.ast_node) = create_binary_op_node(OP_LESSEQUAL, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1618 "build/valorant.tab.c"
    break;

  case 57: /* expression: expression GREATEREQUAL expression  */
#line 210 "src/valorant.y"
                                           { (yyval.ast_node) = create_binary_op_node(OP_GREATEREQUAL, (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1624 "build/valorant.tab.c"
    break;

  case 58: /* if_statement: FLASH '(' expression ')' block  */
#line 214 "src/valorant.y"
                                                      { 
        (yyval.ast_node) = create_if_node((yyvsp[-2].ast_node), (yyvsp[0].ast_node), NULL); 
    }
#line 1632 "build/valorant.tab.c"
    break;

  case 59: /* if_statement: FLASH '(' expression ')' block else_if_chain  */
#line 217 "src/valorant.y"
                                                      { 
        (yyval.ast_node) = create_if_node((yyvsp[-3].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
    }
#line 1640 "build/valorant.tab.c"
    break;

  case 60: /* else_if_chain: SMOKE block  */
#line 223 "src/valorant.y"
                                                      { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1646 "build/valorant.tab.c"
    break;

  case 61: /* else_if_chain: SMOKE FLASH '(' expression ')' block  */
#line 224 "src/valorant.y"
                                                      { (yyval.ast_node) = create_if_node((yyvsp[-2].ast_node), (yyvsp[0].ast_node), NULL); }
#line 1652 "build/valorant.tab.c"
    break;

  case 62: /* else_if_chain: SMOKE FLASH '(' expression ')' block SMOKE block  */
#line 225 "src/valorant.y"
                                                       { (yyval.ast_node) = create_if_node((yyvsp[-4].ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1658 "build/valorant.tab.c"
    break;

  case 63: /* else_if_chain: SMOKE FLASH '(' expression ')' block else_if_chain  */
#line 226 "src/valorant.y"
                                                         { (yyval.ast_node) = create_if_node((yyvsp[-3].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node)); }
#line 1664 "build/valorant.tab.c"
    break;

  case 64: /* while_statement: ROTATE '(' expression ')' block  */
#line 230 "src/valorant.y"
                                      { (yyval.ast_node) = create_while_node((yyvsp[-2].ast_node), (yyvsp[0].ast_node)); }
#line 1670 "build/valorant.tab.c"
    break;

  case 65: /* input_statement: BREACH IDENTIFIER  */
#line 234 "src/valorant.y"
                                     { 
        (yyval.ast_node) = create_input_node(create_identifier_node((yyvsp[0].string_val)));
        free((yyvsp[0].string_val));
    }
#line 1679 "build/valorant.tab.c"
    break;

  case 66: /* output_statement: SOVA expression  */
#line 241 "src/valorant.y"
                                    { (yyval.ast_node) = create_output_node((yyvsp[0].ast_node)); }
#line 1685 "build/valorant.tab.c"
    break;

  case 67: /* return_statement: PLANT expression  */
#line 245 "src/valorant.y"
                                     { (yyval.ast_node) = create_return_node((yyvsp[0].ast_node)); }
#line 1691 "build/valorant.tab.c"
    break;

  case 68: /* return_statement: PLANT  */
#line 246 "src/valorant.y"
                                    { (yyval.ast_node) = create_return_node(NULL); }
#line 1697 "build/valorant.tab.c"
    break;

  case 69: /* assignment: IDENTIFIER '=' expression  */
#line 250 "src/valorant.y"
                                     {
        ASTNode* node = create_node(NODE_ASSIGNMENT);
        node->left = create_identifier_node((yyvsp[-2].string_val));
        node->right = (yyvsp[0].ast_node);
        (yyval.ast_node) = node;
        free((yyvsp[-2].string_val));
    }
#line 1709 "build/valorant.tab.c"
    break;

  case 70: /* function_call: IDENTIFIER '(' argument_list_opt ')'  */
#line 260 "src/valorant.y"
                                                       {
        (yyval.ast_node) = create_function_call_node_with_args((yyvsp[-3].string_val), (yyvsp[-1].ast_node));
        free((yyvsp[-3].string_val));
    }
#line 1718 "build/valorant.tab.c"
    break;

  case 71: /* argument_list_opt: %empty  */
#line 267 "src/valorant.y"
                   { (yyval.ast_node) = NULL; }
#line 1724 "build/valorant.tab.c"
    break;

  case 72: /* argument_list_opt: argument_list  */
#line 268 "src/valorant.y"
                    { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1730 "build/valorant.tab.c"
    break;

  case 73: /* argument_list: expression  */
#line 272 "src/valorant.y"
                 { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1736 "build/valorant.tab.c"
    break;

  case 74: /* argument_list: argument_list ',' expression  */
#line 273 "src/valorant.y"
                                   { 
        ASTNode* temp = (yyvsp[-2].ast_node);
        while (temp->next) temp = temp->next;
        temp->next = (yyvsp[0].ast_node);
        (yyval.ast_node) = (yyvsp[-2].ast_node);
    }
#line 1747 "build/valorant.tab.c"
    break;


#line 1751 "build/valorant.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 281 "src/valorant.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error de sintaxis en línea %d cerca de '%s': %s\n", 
            line_num, yytext, s);
}
