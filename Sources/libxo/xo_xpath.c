/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20230201

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0

#ifndef yyparse
#define yyparse    xo_xpath_yyparse
#endif /* yyparse */

#ifndef yylex
#define yylex      xo_xpath_yylex
#endif /* yylex */

#ifndef yyerror
#define yyerror    xo_xpath_yyerror
#endif /* yyerror */

#ifndef yychar
#define yychar     xo_xpath_yychar
#endif /* yychar */

#ifndef yyval
#define yyval      xo_xpath_yyval
#endif /* yyval */

#ifndef yylval
#define yylval     xo_xpath_yylval
#endif /* yylval */

#ifndef yydebug
#define yydebug    xo_xpath_yydebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    xo_xpath_yynerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  xo_xpath_yyerrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      xo_xpath_yylhs
#endif /* yylhs */

#ifndef yylen
#define yylen      xo_xpath_yylen
#endif /* yylen */

#ifndef yydefred
#define yydefred   xo_xpath_yydefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    xo_xpath_yydgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   xo_xpath_yysindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   xo_xpath_yyrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   xo_xpath_yygindex
#endif /* yygindex */

#ifndef yytable
#define yytable    xo_xpath_yytable
#endif /* yytable */

#ifndef yycheck
#define yycheck    xo_xpath_yycheck
#endif /* yycheck */

#ifndef yyname
#define yyname     xo_xpath_yyname
#endif /* yyname */

#ifndef yyrule
#define yyrule     xo_xpath_yyrule
#endif /* yyrule */
#define YYPREFIX "xo_xpath_yy"

#define YYPURE 1

#line 2 "../../libxo/xo_xpath.y"
/*
 * Copyright (c) 2006-2023, Juniper Networks, Inc.
 * All rights reserved.
 * This SOFTWARE is licensed under the LICENSE provided in the
 * ../Copyright file. By downloading, installing, copying, or otherwise
 * using the SOFTWARE, you agree to be bound by the terms of that
 * LICENSE.
 * Phil Shafer, July 2023 (based on libslax's slaxparser.y)
 *
 * This is an implementation of XPath, suitable for filtering libxo nodes.
 * I'm hoping for something small and efficient.....
 */
#line 17 "../../libxo/xo_xpath.y"
#line 144 "../../libxo/xo_xpath.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <wctype.h>
#include <getopt.h>

#include "xo_config.h"
#include "xo.h"
#include "xo_encoder.h"
#include "xo_buf.h"
#include "xo_xpath.tab.h"
#include "xo_xparse.h"

/*
 * This is a pure parser, allowing this library to link with other users
 * of yacc. To allow this, we pass our data structure (xpath_data_t)
 * to yyparse as the argument.
 */
#define yyparse xo_xpath_yyparse
#define YYPARSE_PARAM_TYPE xo_xparse_data_t *
#define YYPARSE_PARAM xparse_data
#define YYLEX_PARAM_TYPE xo_xparse_data_t *
#define YYLEX_PARAM xparse_data

#define YYSTYPE xo_xparse_node_id_t

#define YYERROR_VERBOSE

/*
 * To save space, we use our own YYINT instead of the standard "int"
 * definition.  Sadly, this isn't an easy replacement, so we use
 * "SED_OPTS" in Makefile.am to remove the original typedef.
 */
#define YYINT int16_t

/*
 * With a "pure" parser, these are all local variables so we don't
 * need to have them #defined into "long" version (with the prefix),
 * so we nuke the #defines and use the real/old names.
 */
#undef yyerrflag
#undef yychar
#undef yyval
#undef yylval
#undef yynerrs
#undef yyloc
#undef yylloc

#undef yyerror
#define yyerror(_str) \
    xo_xpath_yyerror(xparse_data, _str, yystate)

#undef yylex
#define yylex(_lvalp, _param) \
    xo_xpath_yylex(_param, _lvalp)

#define yytname xo_xpath_yyname
#define yypact xo_xpath_yydefred
#define yydebug xo_xpath_yydebug

/*
 * Even if we don't want debug printfs, we still need the arrays with
 * names for our own nefarious purposes.
 */
#undef YYDEBUG
#ifdef XO_YYDEBUG
#define YYDEBUG 1		/* Enable debug output */
/* Log via our function */
#define YYFPRINTF(_fp, _fmt...) xo_xparse_yyprintf(xparse_data, _fmt)
#else /* XO_YYDEBUG */
#define YYDEBUG 1		/* Needed for yytname[] */
#define YYFPRINTF xo_dont_bother /* Don't log via our function */
#define fprintf xo_dont_bother
#define getenv(_x) NULL		/* Don't let it fetch "YYDEBUG" */

static inline void UNUSED
xo_dont_bother (FILE *fp UNUSED, const char *fmt UNUSED, ...)
{
    return;
}

#endif /* XO_YYDEBUG */

#line 212 "xo_xpath.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# ifdef YYLEX_PARAM_TYPE
#  define YYLEX_DECL() yylex(YYSTYPE *yylval, YYLEX_PARAM_TYPE YYLEX_PARAM)
# else
#  define YYLEX_DECL() yylex(YYSTYPE *yylval, void * YYLEX_PARAM)
# endif
# define YYLEX yylex(&yylval, YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(YYSTYPE *yylval)
# define YYLEX yylex(&yylval)
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif


#define L_ASSIGN 1
#define L_AT 2
#define L_CBRACE 3
#define L_COMMA 4
#define L_COLON 5
#define L_DAMPER 6
#define L_DCOLON 7
#define L_DEQUALS 8
#define L_DOTDOT 9
#define L_DOTDOTDOT 10
#define L_DSLASH 11
#define L_DVBAR 12
#define L_EOS 13
#define L_EQUALS 14
#define L_GRTR 15
#define L_GRTREQ 16
#define L_LESS 17
#define L_LESSEQ 18
#define L_MINUS 19
#define L_NOT 20
#define L_NOTEQUALS 21
#define L_OBRACE 22
#define L_OBRACK 23
#define L_OPAREN 24
#define L_PLUS 25
#define L_PLUSEQUALS 26
#define L_QUESTION 27
#define L_SLASH 28
#define L_STAR 29
#define L_UNDERSCORE 30
#define L_VBAR 31
#define L_LAST 32
#define K_COMMENT 33
#define K_ID 34
#define K_KEY 35
#define K_NODE 36
#define K_PROCESSING_INSTRUCTION 37
#define K_TEXT 38
#define M_OPERATOR_FIRST 39
#define K_AND 40
#define K_DIV 41
#define K_MOD 42
#define K_OR 43
#define M_OPERATOR_LAST 44
#define M_MULTIPLICATION_TEST_LAST 45
#define L_ASTERISK 46
#define L_CBRACK 47
#define L_CPAREN 48
#define L_DOT 49
#define T_AXIS_NAME 50
#define T_BARE 51
#define T_FUNCTION_NAME 52
#define T_NUMBER 53
#define T_QUOTED 54
#define T_VAR 55
#define M_SEQUENCE 56
#define M_CONCAT 57
#define M_TERNARY 58
#define M_TERNARY_END 59
#define M_ERROR 60
#define M_XPATH 61
#define M_PARSE_FULL 62
#define M_PARSE_SLAX 63
#define M_PARSE_XPATH 64
#define M_PARSE_PARTIAL 65
#define M_JSON 66
#define C_ABSOLUTE 67
#define C_ATTRIBUTE 68
#define C_DESCENDANT 69
#define C_ELEMENT 70
#define C_EXPR 71
#define C_INDEX 72
#define C_NOT 73
#define C_PATH 74
#define C_PREDICATE 75
#define C_TEST 76
#define C_UNION 77
#define C_INT64 78
#define C_UINT64 79
#define C_FLOAT 80
#define C_STRING 81
#define C_BOOLEAN 82
#define YYERRCODE 256
static const YYINT xo_xpath_yylhs[] = {                  -1,
    0,    2,    3,    4,    1,    7,    7,    8,    8,    9,
    9,   10,   10,   12,   12,    5,   15,   15,   15,   17,
   17,   17,   17,   17,    6,    6,   23,   23,   24,   24,
   24,   24,   25,   25,   16,   16,   27,   27,   28,   28,
   28,   30,   30,   31,   31,   31,   32,   32,   32,   32,
   33,   33,   13,   13,   22,   34,   34,   35,   35,   36,
   37,   37,   37,   39,   39,   26,   11,   11,   11,   40,
   40,   14,   41,   20,   44,   44,   21,   19,   42,   42,
   42,   45,   45,   46,   46,   46,   43,   43,   38,   18,
   29,   29,   29,   29,   29,
};
static const YYINT xo_xpath_yylen[] = {                   2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    1,    1,    1,    5,    4,    3,
    1,    1,    1,    1,    1,    3,    1,    2,    1,    1,
    3,    3,    1,    2,    1,    3,    1,    3,    1,    3,
    3,    1,    3,    1,    3,    3,    1,    3,    3,    3,
    1,    2,    0,    1,    4,    0,    1,    1,    3,    1,
    0,    2,    1,    0,    2,    3,    1,    3,    1,    3,
    1,    2,    3,    1,    0,    1,    1,    1,    1,    3,
    4,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    3,    3,    3,    3,
};
static const YYINT xo_xpath_yydefred[] = {                0,
   89,   88,    0,    0,    0,    0,   87,    0,    0,   77,
   74,   78,    0,    1,    0,   29,    0,   13,   15,   33,
   21,   22,   23,   24,   25,   27,    0,    0,   63,   67,
   69,   71,    0,   28,    0,   90,    0,   16,    0,    0,
    0,    0,    0,    0,    0,    0,   47,    0,   14,   62,
    0,    0,    0,    0,    0,    0,    0,   34,   84,   86,
    0,   85,   83,    2,   82,   64,   79,    0,   52,    9,
    0,    8,    0,   20,    7,    6,    0,   11,   10,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   60,    3,    4,    0,    0,   58,   26,   73,   68,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   48,
   49,   50,   55,    0,   66,   76,    0,   65,   80,   19,
    0,   59,   81,   18,
};
static const YYINT xo_xpath_yydgoto[] = {                13,
   14,   65,   92,   93,   94,   37,   77,   73,   81,   16,
   17,   18,   49,   19,   38,   39,   20,   40,   21,   22,
   23,   24,   25,   26,   27,   58,   41,   42,   43,   44,
   45,   46,   47,   95,   96,   97,   28,   29,  105,   30,
   31,   66,   32,  127,   67,   68,
};
static const YYINT xo_xpath_yysindex[] = {               60,
    0,    0,   36,   72,   23,   36,    0,   12,  -17,    0,
    0,    0,    0,    0,   -5,    0,  -10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,  532,    0,    0,
    0,    0,  -10,    0,   23,    0,   -5,    0,   -6,  -25,
   -4,   19,  194,   16,   -8,   76,    0,  -10,    0,    0,
   23,   60,   36,   36,   36,   23,   36,    0,    0,    0,
   20,    0,    0,    0,    0,    0,    0,   26,    0,    0,
   11,    0,   23,    0,    0,    0,   23,    0,    0,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,    0,    0,    0,   10,   66,    0,    0,    0,    0,
  -10,   32,  -10,   28,   64,   42,   23,   -2,   -4,   19,
  194,  194,   16,   16,   16,   16,   -8,   76,   76,    0,
    0,    0,    0,   23,    0,    0,   43,    0,    0,    0,
   23,    0,    0,    0,
};
static const YYINT xo_xpath_yyrindex[] = {              577,
    0,    0,  577,  577,  577,  128,    0,    0,    0,    0,
    0,    0,    0,    0,   95,    0,  222,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  267,    0,    0,    0,
    0,    0,  312,    0,  577,    0,  492,    0,    5,    0,
  969,  963,  906,  762,  672,  537,    0,  357,    0,    0,
   56,  577,  577,  577,  577,  577,  577,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  577,    0,  577,    0,    0,    0,  577,    0,    0,  577,
  577,  577,  577,  577,  577,  577,  577,  577,  577,  577,
  577,    0,    0,    0,    0,   49,    0,    0,    0,    0,
  402,    0,  447,   50,  177,    0,  577,    0,  987,  981,
  918,  936,  780,  825,  843,  888,  717,  582,  627,    0,
    0,    0,    0,  577,    0,    0,    0,    0,    0,    0,
  577,    0,    0,    0,
};
static const YYINT xo_xpath_yygindex[] = {                0,
    0,    0,    0,   45,   94,  103,    0,    0,    0,    0,
    2,    0,    0,    0, -103,   35,    0,    0,    0,    4,
    0,    0,   59,  112,    0,   15,   46,   52,  -66,  131,
   37,  -39,  -35,    0,    0,    6,    0,    0,    0,   14,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1035
static const YYINT xo_xpath_yytable[] = {                69,
   53,   75,  131,  130,   33,   70,   51,   48,   17,   70,
   87,   55,    1,  111,  112,  107,   88,   54,   50,    2,
   71,    3,   74,   56,    1,   52,   78,  134,   57,   35,
    4,    2,   79,    3,    5,   76,   72,    1,    6,   80,
   72,   35,    4,  104,    2,   86,    5,  118,  119,  106,
    6,   17,   17,  120,  121,  122,  101,  123,  103,    7,
    8,    1,    9,   10,   11,   12,   99,  100,    2,  124,
    3,    7,    8,    1,    9,   10,   11,   12,  125,    4,
    2,   11,    3,    5,    7,    8,   56,    6,   61,  129,
  133,   61,   61,   61,    5,    5,   57,   75,   36,    6,
  102,   61,   15,   56,   89,  108,   61,  126,    7,    8,
   98,    9,   10,   11,   12,   34,   90,   91,  109,  128,
    7,    8,  117,    9,   10,   11,   12,   53,  110,  132,
    0,   53,   53,   53,    0,   53,    0,    0,    0,   53,
    0,   53,   53,   53,   53,   53,   53,    0,   53,    0,
    0,    0,   53,    0,   53,    0,   53,   53,   53,    0,
   61,    0,    0,   61,   61,   61,    0,   53,   53,   53,
   53,    0,    0,   61,   53,   53,   70,    0,   61,    0,
   70,   70,   70,    0,   70,    0,    0,   70,   70,    0,
   70,   70,   70,   70,   70,   70,    0,   70,    0,    0,
    0,   70,    0,   70,   70,   70,   70,   70,   82,   83,
   84,   85,  113,  114,  115,  116,   70,   70,   70,   70,
    0,   12,    0,   70,   70,   12,   12,   12,    0,   12,
    0,    0,    0,   12,    0,   12,   12,   12,   12,   12,
   12,    0,   12,    0,    0,    0,   12,    0,   12,    0,
   12,   12,   12,    0,    0,    0,    0,    0,    0,    0,
    0,   12,   12,   12,   12,    0,   30,    0,   12,   12,
   30,   30,   30,    0,   30,    0,    0,    0,   30,    0,
   30,   30,   30,   30,   30,   30,    0,   30,    0,    0,
    0,   30,    0,   30,    0,   30,   30,   30,    0,    0,
    0,    0,    0,    0,    0,    0,   30,   30,   30,   30,
    0,   72,    0,   30,   30,   72,   72,   72,    0,   72,
    0,    0,    0,   72,    0,   72,   72,   72,   72,   72,
   72,    0,   72,    0,    0,    0,   72,    0,   72,    0,
   72,   72,   72,    0,    0,    0,    0,    0,    0,    0,
    0,   72,   72,   72,   72,    0,   54,    0,   72,   72,
   54,   54,   54,    0,   54,    0,    0,    0,   54,    0,
   54,   54,   54,   54,   54,   54,    0,   54,    0,    0,
    0,   54,    0,   54,    0,   54,   54,   54,    0,    0,
    0,    0,    0,    0,    0,    0,   54,   54,   54,   54,
    0,   32,    0,   54,   54,   32,   32,   32,    0,   32,
    0,    0,    0,   32,    0,   32,   32,   32,   32,   32,
   32,    0,   32,    0,    0,    0,   32,    0,   32,    0,
   32,   32,   32,    0,    0,    0,    0,    0,    0,    0,
    0,   32,   32,   32,   32,    0,   31,    0,   32,   32,
   31,   31,   31,    0,   31,    0,    0,    0,   31,    0,
   31,   31,   31,   31,   31,   31,    0,   31,    0,    0,
    0,   31,    0,   31,    0,   31,   31,   31,    0,    0,
    0,    0,    0,    0,    0,    0,   31,   31,   31,   31,
    0,    0,    0,   31,   31,   51,   51,   51,    0,   51,
    0,    0,    0,   51,    0,   51,   51,   51,   51,   51,
   51,    0,   51,    0,    0,    0,   51,    0,   51,    0,
   51,   51,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   51,   51,   51,   51,    0,    0,    0,   51,   51,
   44,   44,   44,    0,   44,    0,    0,    0,   44,    0,
   44,   44,   44,   44,   44,   44,    0,   44,    0,    0,
    0,   44,    0,   44,   59,    0,   44,   60,   61,   62,
    0,    0,    0,    0,    0,    0,   44,   63,    0,   44,
    0,    0,   64,   44,   44,   46,   46,   46,    0,   46,
    0,    0,    0,   46,    0,   46,   46,   46,   46,   46,
   46,    0,   46,    0,    0,    0,   46,    0,   46,   61,
    0,   46,   61,   61,   61,    0,    0,    0,    0,    0,
    0,   46,   61,    0,   46,    0,    0,   61,   46,   46,
   45,   45,   45,    0,   45,    0,    0,    0,   45,    0,
   45,   45,   45,   45,   45,   45,    0,   45,    0,    0,
    0,   45,    0,   45,    0,    0,   45,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   45,    0,    0,   45,
    0,    0,    0,   45,   45,   42,   42,   42,    0,   42,
    0,    0,    0,   42,    0,   42,   42,   42,   42,   42,
    0,    0,   42,    0,    0,    0,    0,    0,   42,    0,
    0,   42,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   42,    0,    0,   42,    0,    0,    0,   42,   42,
   43,   43,   43,    0,   43,    0,    0,    0,   43,    0,
   43,   43,   43,   43,   43,    0,    0,   43,    0,    0,
    0,    0,    0,   43,    0,    0,   43,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   43,    0,    0,   43,
    0,    0,    0,   43,   43,   91,   91,   91,    0,   91,
    0,    0,    0,   91,    0,   91,   91,   91,   91,   91,
    0,    0,   91,   93,   93,   93,    0,   93,   91,    0,
    0,   93,    0,   93,   93,   93,   93,   93,    0,    0,
   93,   91,    0,    0,   91,    0,   93,    0,   91,   91,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   93,
    0,    0,   93,    0,    0,    0,   93,   93,   95,   95,
   95,    0,   95,    0,    0,    0,   95,    0,   95,   95,
   95,   95,   95,    0,    0,   95,   92,   92,   92,    0,
   92,   95,    0,    0,   92,    0,   92,   92,   92,   92,
   92,    0,    0,   92,   95,    0,    0,   95,    0,   92,
    0,   95,   95,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   92,    0,    0,   92,    0,    0,    0,   92,
   92,   94,   94,   94,    0,   94,    0,    0,    0,   94,
    0,   94,   94,   94,   94,   94,    0,    0,   94,   39,
   39,   39,    0,   39,   94,    0,    0,   39,    0,   39,
    0,   41,   41,   41,    0,   41,   39,   94,    0,   41,
   94,   41,   39,    0,   94,   94,    0,    0,   41,   40,
   40,   40,    0,   40,   41,   39,    0,   40,   39,   40,
    0,    0,   39,   39,    0,    0,   40,   41,    0,    0,
   41,    0,   40,    0,   41,   41,   37,   37,   37,    0,
    0,    0,   35,   35,   37,   40,    0,    0,   40,    0,
   35,    0,   40,   40,   38,   38,   38,    0,    0,   37,
   36,   36,   38,    0,    0,   35,    0,    0,   36,    0,
    0,    0,   37,    0,    0,   37,    0,   38,    0,   37,
   37,   35,    0,   36,    0,   35,   35,    0,    0,    0,
   38,    0,    0,   38,    0,    0,    0,   38,   38,   36,
    0,    0,    0,   36,   36,
};
static const YYINT xo_xpath_yycheck[] = {                35,
   11,    6,    5,  107,    3,   12,   24,    6,    4,   12,
   19,   11,    2,   80,   81,    5,   25,   28,    7,    9,
   27,   11,   48,   23,    2,   31,    8,  131,   28,   19,
   20,    9,   14,   11,   24,   40,   43,    2,   28,   21,
   43,   19,   20,   24,    9,   30,   24,   87,   88,   24,
   28,   47,   48,   89,   90,   91,   55,   48,   57,   49,
   50,    2,   52,   53,   54,   55,   53,   54,    9,    4,
   11,   49,   50,    2,   52,   53,   54,   55,   47,   20,
    9,   54,   11,   24,   49,   50,   23,   28,   33,   48,
   48,   36,   37,   38,    0,   24,   48,   48,    5,   28,
   56,   46,    0,   48,   29,   71,   51,  104,   49,   50,
   52,   52,   53,   54,   55,    4,   41,   42,   73,  105,
   49,   50,   86,   52,   53,   54,   55,    0,   77,  124,
   -1,    4,    5,    6,   -1,    8,   -1,   -1,   -1,   12,
   -1,   14,   15,   16,   17,   18,   19,   -1,   21,   -1,
   -1,   -1,   25,   -1,   27,   -1,   29,   30,   31,   -1,
   33,   -1,   -1,   36,   37,   38,   -1,   40,   41,   42,
   43,   -1,   -1,   46,   47,   48,    0,   -1,   51,   -1,
    4,    5,    6,   -1,    8,   -1,   -1,   11,   12,   -1,
   14,   15,   16,   17,   18,   19,   -1,   21,   -1,   -1,
   -1,   25,   -1,   27,   28,   29,   30,   31,   15,   16,
   17,   18,   82,   83,   84,   85,   40,   41,   42,   43,
   -1,    0,   -1,   47,   48,    4,    5,    6,   -1,    8,
   -1,   -1,   -1,   12,   -1,   14,   15,   16,   17,   18,
   19,   -1,   21,   -1,   -1,   -1,   25,   -1,   27,   -1,
   29,   30,   31,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   -1,    0,   -1,   47,   48,
    4,    5,    6,   -1,    8,   -1,   -1,   -1,   12,   -1,
   14,   15,   16,   17,   18,   19,   -1,   21,   -1,   -1,
   -1,   25,   -1,   27,   -1,   29,   30,   31,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   42,   43,
   -1,    0,   -1,   47,   48,    4,    5,    6,   -1,    8,
   -1,   -1,   -1,   12,   -1,   14,   15,   16,   17,   18,
   19,   -1,   21,   -1,   -1,   -1,   25,   -1,   27,   -1,
   29,   30,   31,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   -1,    0,   -1,   47,   48,
    4,    5,    6,   -1,    8,   -1,   -1,   -1,   12,   -1,
   14,   15,   16,   17,   18,   19,   -1,   21,   -1,   -1,
   -1,   25,   -1,   27,   -1,   29,   30,   31,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   42,   43,
   -1,    0,   -1,   47,   48,    4,    5,    6,   -1,    8,
   -1,   -1,   -1,   12,   -1,   14,   15,   16,   17,   18,
   19,   -1,   21,   -1,   -1,   -1,   25,   -1,   27,   -1,
   29,   30,   31,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   -1,    0,   -1,   47,   48,
    4,    5,    6,   -1,    8,   -1,   -1,   -1,   12,   -1,
   14,   15,   16,   17,   18,   19,   -1,   21,   -1,   -1,
   -1,   25,   -1,   27,   -1,   29,   30,   31,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   41,   42,   43,
   -1,   -1,   -1,   47,   48,    4,    5,    6,   -1,    8,
   -1,   -1,   -1,   12,   -1,   14,   15,   16,   17,   18,
   19,   -1,   21,   -1,   -1,   -1,   25,   -1,   27,   -1,
   29,   30,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   41,   42,   43,   -1,   -1,   -1,   47,   48,
    4,    5,    6,   -1,    8,   -1,   -1,   -1,   12,   -1,
   14,   15,   16,   17,   18,   19,   -1,   21,   -1,   -1,
   -1,   25,   -1,   27,   33,   -1,   30,   36,   37,   38,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   46,   -1,   43,
   -1,   -1,   51,   47,   48,    4,    5,    6,   -1,    8,
   -1,   -1,   -1,   12,   -1,   14,   15,   16,   17,   18,
   19,   -1,   21,   -1,   -1,   -1,   25,   -1,   27,   33,
   -1,   30,   36,   37,   38,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   46,   -1,   43,   -1,   -1,   51,   47,   48,
    4,    5,    6,   -1,    8,   -1,   -1,   -1,   12,   -1,
   14,   15,   16,   17,   18,   19,   -1,   21,   -1,   -1,
   -1,   25,   -1,   27,   -1,   -1,   30,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   43,
   -1,   -1,   -1,   47,   48,    4,    5,    6,   -1,    8,
   -1,   -1,   -1,   12,   -1,   14,   15,   16,   17,   18,
   -1,   -1,   21,   -1,   -1,   -1,   -1,   -1,   27,   -1,
   -1,   30,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   40,   -1,   -1,   43,   -1,   -1,   -1,   47,   48,
    4,    5,    6,   -1,    8,   -1,   -1,   -1,   12,   -1,
   14,   15,   16,   17,   18,   -1,   -1,   21,   -1,   -1,
   -1,   -1,   -1,   27,   -1,   -1,   30,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   40,   -1,   -1,   43,
   -1,   -1,   -1,   47,   48,    4,    5,    6,   -1,    8,
   -1,   -1,   -1,   12,   -1,   14,   15,   16,   17,   18,
   -1,   -1,   21,    4,    5,    6,   -1,    8,   27,   -1,
   -1,   12,   -1,   14,   15,   16,   17,   18,   -1,   -1,
   21,   40,   -1,   -1,   43,   -1,   27,   -1,   47,   48,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   43,   -1,   -1,   -1,   47,   48,    4,    5,
    6,   -1,    8,   -1,   -1,   -1,   12,   -1,   14,   15,
   16,   17,   18,   -1,   -1,   21,    4,    5,    6,   -1,
    8,   27,   -1,   -1,   12,   -1,   14,   15,   16,   17,
   18,   -1,   -1,   21,   40,   -1,   -1,   43,   -1,   27,
   -1,   47,   48,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   -1,   -1,   43,   -1,   -1,   -1,   47,
   48,    4,    5,    6,   -1,    8,   -1,   -1,   -1,   12,
   -1,   14,   15,   16,   17,   18,   -1,   -1,   21,    4,
    5,    6,   -1,    8,   27,   -1,   -1,   12,   -1,   14,
   -1,    4,    5,    6,   -1,    8,   21,   40,   -1,   12,
   43,   14,   27,   -1,   47,   48,   -1,   -1,   21,    4,
    5,    6,   -1,    8,   27,   40,   -1,   12,   43,   14,
   -1,   -1,   47,   48,   -1,   -1,   21,   40,   -1,   -1,
   43,   -1,   27,   -1,   47,   48,    4,    5,    6,   -1,
   -1,   -1,    4,    5,   12,   40,   -1,   -1,   43,   -1,
   12,   -1,   47,   48,    4,    5,    6,   -1,   -1,   27,
    4,    5,   12,   -1,   -1,   27,   -1,   -1,   12,   -1,
   -1,   -1,   40,   -1,   -1,   43,   -1,   27,   -1,   47,
   48,   43,   -1,   27,   -1,   47,   48,   -1,   -1,   -1,
   40,   -1,   -1,   43,   -1,   -1,   -1,   47,   48,   43,
   -1,   -1,   -1,   47,   48,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYUNDFTOKEN 327
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const xo_xpath_yyname[] = {

"end-of-file","L_ASSIGN","L_AT","L_CBRACE","L_COMMA","L_COLON","L_DAMPER",
"L_DCOLON","L_DEQUALS","L_DOTDOT","L_DOTDOTDOT","L_DSLASH","L_DVBAR","L_EOS",
"L_EQUALS","L_GRTR","L_GRTREQ","L_LESS","L_LESSEQ","L_MINUS","L_NOT",
"L_NOTEQUALS","L_OBRACE","L_OBRACK","L_OPAREN","L_PLUS","L_PLUSEQUALS",
"L_QUESTION","L_SLASH","L_STAR","L_UNDERSCORE","L_VBAR","L_LAST","'!'","K_ID",
"K_KEY","K_NODE","K_PROCESSING_INSTRUCTION","K_TEXT","M_OPERATOR_FIRST","'('",
"K_DIV","'*'","'+'","','","'-'","L_ASTERISK","'/'","L_CPAREN","L_DOT",
"T_AXIS_NAME","T_BARE","T_FUNCTION_NAME","T_NUMBER","T_QUOTED","T_VAR",
"M_SEQUENCE","M_CONCAT","':'","';'","'<'","'='","'>'","'?'","'@'",
"M_PARSE_PARTIAL","M_JSON","C_ABSOLUTE","C_ATTRIBUTE","C_DESCENDANT",
"C_ELEMENT","C_EXPR","C_INDEX","C_NOT","C_PATH","C_PREDICATE","C_TEST",
"C_UNION","C_INT64","C_UINT64","C_FLOAT","C_STRING","C_BOOLEAN",0,0,0,0,0,0,0,0,
"'['",0,"']'",0,"'_'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"\":=\"","\"&&\"","\"::\"","\"==\"",
"\"..\"","\"...\"","\"//\"","\"||\"","\">=\"","\"<=\"","\"!=\"","\"+=\"",
"\"comment\"","\"id\"","\"key\"","\"node\"","\"processing-instruction\"",
"\"text\"","\"and\"","\"div\"","\"mod\"","\"or\"",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const xo_xpath_yyrule[] = {
"$accept : start",
"start : xpath_union_expression",
"q_name : T_BARE",
"xpath_value : xpath_expression",
"xpath_expression : xp_expr",
"xpath_union_expression : xp_union_expr",
"and_operator : K_AND",
"and_operator : L_DAMPER",
"or_operator : K_OR",
"or_operator : L_DVBAR",
"equals_operator : L_EQUALS",
"equals_operator : L_DEQUALS",
"xp_location_path : xpc_relative_location_path",
"xp_location_path : xp_absolute_location_path",
"xp_absolute_location_path : L_SLASH xp_relative_location_path_optional",
"xp_absolute_location_path : xpc_abbreviated_absolute_location_path",
"xp_expr : xp_ternary_expr",
"xp_ternary_expr : xp_or_expr",
"xp_ternary_expr : xp_or_expr L_QUESTION xp_or_expr L_COLON xp_ternary_expr",
"xp_ternary_expr : xp_or_expr L_QUESTION L_COLON xp_ternary_expr",
"xp_primary_expr : L_OPAREN xpc_expr L_CPAREN",
"xp_primary_expr : xpc_variable_reference",
"xp_primary_expr : xpc_literal",
"xp_primary_expr : xpc_number",
"xp_primary_expr : xpc_function_call",
"xp_union_expr : xp_not_expr",
"xp_union_expr : xp_union_expr L_VBAR xp_not_expr",
"xp_not_expr : xp_path_expr",
"xp_not_expr : L_NOT xp_path_expr",
"xp_path_expr : xp_location_path",
"xp_path_expr : xp_filter_expr",
"xp_path_expr : xp_filter_expr L_SLASH xpc_relative_location_path",
"xp_path_expr : xp_filter_expr L_DSLASH xpc_relative_location_path",
"xp_filter_expr : xp_primary_expr",
"xp_filter_expr : xp_filter_expr xpc_predicate",
"xp_or_expr : xp_and_expr",
"xp_or_expr : xp_or_expr or_operator xp_and_expr",
"xp_and_expr : xp_equality_expr",
"xp_and_expr : xp_and_expr and_operator xp_equality_expr",
"xp_equality_expr : xp_relational_expr",
"xp_equality_expr : xp_equality_expr equals_operator xp_relational_expr",
"xp_equality_expr : xp_equality_expr L_NOTEQUALS xp_relational_expr",
"xp_concative_expr : xp_additive_expr",
"xp_concative_expr : xp_concative_expr L_UNDERSCORE xp_additive_expr",
"xp_additive_expr : xp_multiplicative_expr",
"xp_additive_expr : xp_additive_expr L_PLUS xp_multiplicative_expr",
"xp_additive_expr : xp_additive_expr L_MINUS xp_multiplicative_expr",
"xp_multiplicative_expr : xp_unary_expr",
"xp_multiplicative_expr : xp_multiplicative_expr L_STAR xp_unary_expr",
"xp_multiplicative_expr : xp_multiplicative_expr K_DIV xp_unary_expr",
"xp_multiplicative_expr : xp_multiplicative_expr K_MOD xp_unary_expr",
"xp_unary_expr : xp_union_expr",
"xp_unary_expr : L_MINUS xp_unary_expr",
"xp_relative_location_path_optional :",
"xp_relative_location_path_optional : xpc_relative_location_path",
"xpc_function_call : T_FUNCTION_NAME L_OPAREN xpc_argument_list_optional L_CPAREN",
"xpc_argument_list_optional :",
"xpc_argument_list_optional : xpc_argument_list",
"xpc_argument_list : xpc_argument",
"xpc_argument_list : xpc_argument_list L_COMMA xpc_argument",
"xpc_argument : xpath_value",
"xpc_axis_specifier_optional :",
"xpc_axis_specifier_optional : T_AXIS_NAME L_DCOLON",
"xpc_axis_specifier_optional : xpc_abbreviated_axis_specifier",
"xpc_predicate_list :",
"xpc_predicate_list : xpc_predicate_list xpc_predicate",
"xpc_predicate : L_OBRACK xpath_expression L_CBRACK",
"xpc_relative_location_path : xpc_step",
"xpc_relative_location_path : xpc_relative_location_path L_SLASH xpc_step",
"xpc_relative_location_path : xpc_abbreviated_relative_location_path",
"xpc_step : xpc_axis_specifier_optional xpc_node_test xpc_predicate_list",
"xpc_step : xpc_abbreviated_step",
"xpc_abbreviated_absolute_location_path : L_DSLASH xpc_relative_location_path",
"xpc_abbreviated_relative_location_path : xpc_relative_location_path L_DSLASH xpc_step",
"xpc_literal : T_QUOTED",
"xpc_literal_optional :",
"xpc_literal_optional : xpc_literal",
"xpc_number : T_NUMBER",
"xpc_variable_reference : T_VAR",
"xpc_node_test : xpc_name_test",
"xpc_node_test : xpc_node_type L_OPAREN L_CPAREN",
"xpc_node_test : K_PROCESSING_INSTRUCTION L_OPAREN xpc_literal_optional L_CPAREN",
"xpc_name_test : q_name",
"xpc_name_test : L_ASTERISK",
"xpc_node_type : K_COMMENT",
"xpc_node_type : K_TEXT",
"xpc_node_type : K_NODE",
"xpc_abbreviated_step : L_DOT",
"xpc_abbreviated_step : L_DOTDOT",
"xpc_abbreviated_axis_specifier : L_AT",
"xpc_expr : xp_expr",
"xp_relational_expr : xp_concative_expr",
"xp_relational_expr : xp_relational_expr L_LESS xp_concative_expr",
"xp_relational_expr : xp_relational_expr L_GRTR xp_concative_expr",
"xp_relational_expr : xp_relational_expr L_LESSEQ xp_concative_expr",
"xp_relational_expr : xp_relational_expr L_GRTREQ xp_concative_expr",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
#line 812 "../../libxo/xo_xpath.y"

#ifndef XO_YYDEBUG
#undef yydebug
#define yydebug 0
#endif /* XO_YYDEBUG */

/*
 * These definitions need values and defines that are internal to
 * yacc, so they must be placed here.
 */

#ifndef YYNTOKENS
#ifdef YYMAXTOKEN
#define YYNTOKENS (YYMAXTOKEN+1)
#else
#error unknown value for YYNTOKENS
#endif /* YYMAXTOKEN */
#endif /* YYNTOKENS */

#ifndef YYLAST
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST ((sizeof(yytable) / sizeof(yytable[0])) - 1)
#endif /* YYLAST */

const int xo_xparse_num_tokens = YYNTOKENS;
const char *xo_xparse_keyword_string[YYNTOKENS];
const char *xo_xparse_token_name_fancy[YYNTOKENS];

/*
 * Return a human-readable name for a given token type
 */
const char *
xo_xparse_token_name (xo_xparse_token_t ttype)
{
    if (ttype >= YYNTOKENS)
	return "unknown";

    return yytname[YYTRANSLATE(ttype)];
}

const char *
xo_xparse_fancy_token_name (xo_xparse_token_t ttype)
{
    if (ttype >= YYNTOKENS)
	return "unknown";

    return xo_xparse_token_name_fancy[YYTRANSLATE(ttype)];
}

/*
 * Expose YYTRANSLATE outside the yacc file
 */
xo_xparse_token_t
xo_xparse_token_translate (xo_xparse_token_t ttype)
{
    return YYTRANSLATE(ttype);
}

#ifndef YYTERROR
#define YYTERROR YYSYMBOL_YYerror /* the new enum */
#endif /* YYTERROR */

/*
 * Return a better class of error message, if possible.  But it turns
 * out that this isn't possible in yacc.  bison adds a "lookahead
 * correction" that gives us information that we can use to find the
 * list of possibly-valid next tokens, which we use to build an
 * "expecting ..." message, but lacking that information, we just punt.
 *
 * The original code is in libslax/slaxparser.y, so maybe one day I'll
 * try to make it work.
 */
char *
xo_xparse_expecting_error (const char *token, int yystate UNUSED,
			   int yychar UNUSED)
{
    char buf[BUFSIZ], *cp = buf, *ep = buf + sizeof(buf);

    SNPRINTF(cp, ep, "unexpected input");
    if (token)
	SNPRINTF(cp, ep, ": %s", token);

    return strdup(buf);
}
#line 884 "xo_xpath.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == NULL)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == NULL)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int      yyerrflag;
    int      yychar;
    YYSTYPE  yyval;
    YYSTYPE  yylval;
    int      yynerrs;

    /* variables for the parser stack */
    YYSTACKDATA yystack;
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != NULL)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            do {} while(0);
    }
#endif

    memset(&yyval,  0, sizeof(yyval));
    memset(&yylval, 0, sizeof(yylval));

    /* yym is set below */
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 251 "../../libxo/xo_xpath.y"
	{
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]);
		    xo_xparse_results(xparse_data, yystack.l_mark[0]);
		    xparse_data->xd_errors = yynerrs;
		}
#line 1101 "xo_xpath.tab.c"
break;
case 2:
#line 260 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1106 "xo_xpath.tab.c"
break;
case 3:
#line 265 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1111 "xo_xpath.tab.c"
break;
case 4:
#line 270 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1116 "xo_xpath.tab.c"
break;
case 5:
#line 275 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1121 "xo_xpath.tab.c"
break;
case 6:
#line 282 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1126 "xo_xpath.tab.c"
break;
case 7:
#line 285 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_ok(xparse_data, yyval)->xn_type = K_AND;
		}
#line 1133 "xo_xpath.tab.c"
break;
case 8:
#line 292 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1138 "xo_xpath.tab.c"
break;
case 9:
#line 295 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_ok(xparse_data, yyval)->xn_type = K_OR;
		}
#line 1145 "xo_xpath.tab.c"
break;
case 10:
#line 302 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1150 "xo_xpath.tab.c"
break;
case 11:
#line 305 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_ok(xparse_data, yyval)->xn_type = L_EQUALS;
		}
#line 1157 "xo_xpath.tab.c"
break;
case 12:
#line 312 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1162 "xo_xpath.tab.c"
break;
case 13:
#line 315 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1167 "xo_xpath.tab.c"
break;
case 14:
#line 320 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_type(xparse_data, yystack.l_mark[-1], C_ABSOLUTE);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1176 "xo_xpath.tab.c"
break;
case 15:
#line 327 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1181 "xo_xpath.tab.c"
break;
case 16:
#line 332 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1186 "xo_xpath.tab.c"
break;
case 17:
#line 337 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1191 "xo_xpath.tab.c"
break;
case 18:
#line 340 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_ternary_rewrite(xparse_data, &yyval, &yystack.l_mark[-4], &yystack.l_mark[-3], &yystack.l_mark[-2], &yystack.l_mark[-1], &yystack.l_mark[0]);
		}
#line 1198 "xo_xpath.tab.c"
break;
case 19:
#line 345 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_ternary_rewrite(xparse_data, &yyval, &yystack.l_mark[-3], &yystack.l_mark[-2], NULL, &yystack.l_mark[-1], &yystack.l_mark[0]);
		}
#line 1205 "xo_xpath.tab.c"
break;
case 20:
#line 352 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_type(xparse_data, yystack.l_mark[-2], C_EXPR);
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-2], yystack.l_mark[-1]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2]);
		}
#line 1214 "xo_xpath.tab.c"
break;
case 21:
#line 359 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1219 "xo_xpath.tab.c"
break;
case 22:
#line 362 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1224 "xo_xpath.tab.c"
break;
case 23:
#line 365 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1229 "xo_xpath.tab.c"
break;
case 24:
#line 368 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1234 "xo_xpath.tab.c"
break;
case 25:
#line 373 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1239 "xo_xpath.tab.c"
break;
case 26:
#line 376 "../../libxo/xo_xpath.y"
	{
		    if (xo_xparse_node_type(xparse_data, yystack.l_mark[-2]) == C_UNION) {
			
			xo_xparse_node_set_next(xparse_data,
				xo_xparse_node_contents(xparse_data, yystack.l_mark[-2]),
						yystack.l_mark[0]);
			yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2]);
		    } else {
			xo_xparse_node_set_type(xparse_data, yystack.l_mark[-1], C_UNION);
			xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
			xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
			yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		    }
		}
#line 1257 "xo_xpath.tab.c"
break;
case 27:
#line 394 "../../libxo/xo_xpath.y"
	{ 
		    xo_xparse_node_id_t id = xo_xparse_node_new(xparse_data);
		    xo_xparse_node_t *xnp = xo_xparse_node(xparse_data, yystack.l_mark[0]);
		    if (xnp->xn_type == C_ELEMENT) {
			xnp = xo_xparse_node(xparse_data, id);
			xnp->xn_type = C_PATH;
			xo_xparse_node_set_contents(xparse_data, id, yystack.l_mark[0]);
		    } else {
			id = yystack.l_mark[0];
		    }
		    yyval = xo_xparse_yyval(xparse_data, id);
		}
#line 1273 "xo_xpath.tab.c"
break;
case 28:
#line 408 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_type(xparse_data, yystack.l_mark[-1], C_NOT);
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1282 "xo_xpath.tab.c"
break;
case 29:
#line 417 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1287 "xo_xpath.tab.c"
break;
case 30:
#line 420 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1292 "xo_xpath.tab.c"
break;
case 31:
#line 423 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[-1]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2]);
		}
#line 1301 "xo_xpath.tab.c"
break;
case 32:
#line 430 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[-1]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2]);
		}
#line 1310 "xo_xpath.tab.c"
break;
case 33:
#line 439 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1315 "xo_xpath.tab.c"
break;
case 34:
#line 442 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1323 "xo_xpath.tab.c"
break;
case 35:
#line 450 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1328 "xo_xpath.tab.c"
break;
case 36:
#line 453 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1337 "xo_xpath.tab.c"
break;
case 37:
#line 462 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1342 "xo_xpath.tab.c"
break;
case 38:
#line 465 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1351 "xo_xpath.tab.c"
break;
case 39:
#line 474 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1356 "xo_xpath.tab.c"
break;
case 40:
#line 477 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1365 "xo_xpath.tab.c"
break;
case 41:
#line 484 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1374 "xo_xpath.tab.c"
break;
case 42:
#line 493 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1379 "xo_xpath.tab.c"
break;
case 43:
#line 496 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_concat_rewrite(xparse_data, &yyval, &yystack.l_mark[-2], &yystack.l_mark[-1], &yystack.l_mark[0]);
		}
#line 1386 "xo_xpath.tab.c"
break;
case 44:
#line 503 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1391 "xo_xpath.tab.c"
break;
case 45:
#line 506 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1400 "xo_xpath.tab.c"
break;
case 46:
#line 513 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1409 "xo_xpath.tab.c"
break;
case 47:
#line 522 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1414 "xo_xpath.tab.c"
break;
case 48:
#line 525 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1423 "xo_xpath.tab.c"
break;
case 49:
#line 532 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1432 "xo_xpath.tab.c"
break;
case 50:
#line 539 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1441 "xo_xpath.tab.c"
break;
case 51:
#line 548 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1446 "xo_xpath.tab.c"
break;
case 52:
#line 551 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1454 "xo_xpath.tab.c"
break;
case 53:
#line 561 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, 0); }
#line 1459 "xo_xpath.tab.c"
break;
case 54:
#line 564 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1464 "xo_xpath.tab.c"
break;
case 55:
#line 569 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-3]); }
#line 1469 "xo_xpath.tab.c"
break;
case 56:
#line 574 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, 0); }
#line 1474 "xo_xpath.tab.c"
break;
case 57:
#line 577 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1479 "xo_xpath.tab.c"
break;
case 58:
#line 582 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1484 "xo_xpath.tab.c"
break;
case 59:
#line 585 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[-1]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2]);
		}
#line 1493 "xo_xpath.tab.c"
break;
case 60:
#line 594 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1498 "xo_xpath.tab.c"
break;
case 61:
#line 600 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, 0); }
#line 1503 "xo_xpath.tab.c"
break;
case 62:
#line 603 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_check_axis_name(xparse_data, yystack.l_mark[-1]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1511 "xo_xpath.tab.c"
break;
case 63:
#line 609 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1516 "xo_xpath.tab.c"
break;
case 64:
#line 614 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, 0); }
#line 1521 "xo_xpath.tab.c"
break;
case 65:
#line 617 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1] ?: yystack.l_mark[0]);
		}
#line 1529 "xo_xpath.tab.c"
break;
case 66:
#line 625 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_type(xparse_data, yystack.l_mark[-2], C_PREDICATE);
		    xo_xparse_node_set_str(xparse_data, yystack.l_mark[-2], 0);
		    if (xo_xparse_node_type(xparse_data, yystack.l_mark[-1]) == T_NUMBER)
			xo_xparse_node_set_type(xparse_data, yystack.l_mark[-1], C_INDEX);
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-2], yystack.l_mark[-1]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2]);
		}
#line 1541 "xo_xpath.tab.c"
break;
case 67:
#line 637 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1546 "xo_xpath.tab.c"
break;
case 68:
#line 640 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2]);
		}
#line 1554 "xo_xpath.tab.c"
break;
case 69:
#line 646 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1559 "xo_xpath.tab.c"
break;
case 70:
#line 651 "../../libxo/xo_xpath.y"
	{
		    if (xo_xparse_node_type(xparse_data, yystack.l_mark[-2]) == L_AT
			|| xo_xparse_node_is_attr_axis(xparse_data, yystack.l_mark[-2])) {
			xo_xparse_node_set_type(xparse_data, yystack.l_mark[-1], C_ATTRIBUTE);
		    } else {
			xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    }
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1573 "xo_xpath.tab.c"
break;
case 71:
#line 663 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1578 "xo_xpath.tab.c"
break;
case 72:
#line 668 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_type(xparse_data, yystack.l_mark[-1], C_DESCENDANT);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1587 "xo_xpath.tab.c"
break;
case 73:
#line 677 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_type(xparse_data, yystack.l_mark[-1], C_DESCENDANT);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[-1]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-1], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2] ?: yystack.l_mark[-1]);
		}
#line 1597 "xo_xpath.tab.c"
break;
case 74:
#line 687 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1602 "xo_xpath.tab.c"
break;
case 75:
#line 692 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, 0); }
#line 1607 "xo_xpath.tab.c"
break;
case 76:
#line 695 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1612 "xo_xpath.tab.c"
break;
case 77:
#line 700 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1617 "xo_xpath.tab.c"
break;
case 78:
#line 705 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1622 "xo_xpath.tab.c"
break;
case 79:
#line 710 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1627 "xo_xpath.tab.c"
break;
case 80:
#line 713 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-2]); }
#line 1632 "xo_xpath.tab.c"
break;
case 81:
#line 716 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-3], yystack.l_mark[-1]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-3]);
		}
#line 1640 "xo_xpath.tab.c"
break;
case 82:
#line 724 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_type(xparse_data, yystack.l_mark[0], C_ELEMENT);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]);
		}
#line 1648 "xo_xpath.tab.c"
break;
case 83:
#line 730 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1653 "xo_xpath.tab.c"
break;
case 84:
#line 735 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1658 "xo_xpath.tab.c"
break;
case 85:
#line 738 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1663 "xo_xpath.tab.c"
break;
case 86:
#line 741 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1668 "xo_xpath.tab.c"
break;
case 87:
#line 746 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1673 "xo_xpath.tab.c"
break;
case 88:
#line 749 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1678 "xo_xpath.tab.c"
break;
case 89:
#line 754 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1683 "xo_xpath.tab.c"
break;
case 90:
#line 763 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1688 "xo_xpath.tab.c"
break;
case 91:
#line 780 "../../libxo/xo_xpath.y"
	{ yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[0]); }
#line 1693 "xo_xpath.tab.c"
break;
case 92:
#line 783 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1702 "xo_xpath.tab.c"
break;
case 93:
#line 790 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1711 "xo_xpath.tab.c"
break;
case 94:
#line 797 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1720 "xo_xpath.tab.c"
break;
case 95:
#line 804 "../../libxo/xo_xpath.y"
	{
		    xo_xparse_node_set_contents(xparse_data, yystack.l_mark[-1], yystack.l_mark[-2]);
		    xo_xparse_node_set_next(xparse_data, yystack.l_mark[-2], yystack.l_mark[0]);
		    yyval = xo_xparse_yyval(xparse_data, yystack.l_mark[-1]);
		}
#line 1729 "xo_xpath.tab.c"
break;
#line 1731 "xo_xpath.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
