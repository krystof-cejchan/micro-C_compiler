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
#line 1 "mikroC.y"


#include  "microC.h"

int yylex();
void yyerror(const char *);

extern Uzel *Koren;

bool Konst(const Uzel *);

bool Konst(const Uzel *,const Uzel *);


#line 86 "mikroC.tab.cpp"

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

#include "mikroC.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CISLO = 3,                      /* CISLO  */
  YYSYMBOL_RETEZ = 4,                      /* RETEZ  */
  YYSYMBOL_PROMENNA = 5,                   /* PROMENNA  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_DO = 10,                        /* DO  */
  YYSYMBOL_PRINT = 11,                     /* PRINT  */
  YYSYMBOL_SCAN = 12,                      /* SCAN  */
  YYSYMBOL_13_ = 13,                       /* '='  */
  YYSYMBOL_P_NASOB = 14,                   /* P_NASOB  */
  YYSYMBOL_P_DELEN = 15,                   /* P_DELEN  */
  YYSYMBOL_P_MODUL = 16,                   /* P_MODUL  */
  YYSYMBOL_P_PRICT = 17,                   /* P_PRICT  */
  YYSYMBOL_P_ODECT = 18,                   /* P_ODECT  */
  YYSYMBOL_P_POSUNVLEVO = 19,              /* P_POSUNVLEVO  */
  YYSYMBOL_P_POSUNVPRAVO = 20,             /* P_POSUNVPRAVO  */
  YYSYMBOL_P_AND = 21,                     /* P_AND  */
  YYSYMBOL_P_XOR = 22,                     /* P_XOR  */
  YYSYMBOL_P_OR = 23,                      /* P_OR  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_26_ = 26,                       /* '|'  */
  YYSYMBOL_27_ = 27,                       /* '^'  */
  YYSYMBOL_28_ = 28,                       /* '&'  */
  YYSYMBOL_ROVNO = 29,                     /* ROVNO  */
  YYSYMBOL_NENIROVNO = 30,                 /* NENIROVNO  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_MENSIROVNO = 33,                /* MENSIROVNO  */
  YYSYMBOL_VETSIROVNO = 34,                /* VETSIROVNO  */
  YYSYMBOL_POSUNVLEVO = 35,                /* POSUNVLEVO  */
  YYSYMBOL_POSUNVPRAVO = 36,               /* POSUNVPRAVO  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_41_ = 41,                       /* '%'  */
  YYSYMBOL_INKREM = 42,                    /* INKREM  */
  YYSYMBOL_DEKREM = 43,                    /* DEKREM  */
  YYSYMBOL_44_ = 44,                       /* '!'  */
  YYSYMBOL_45_ = 45,                       /* '~'  */
  YYSYMBOL_NOT = 46,                       /* NOT  */
  YYSYMBOL_MINUS = 47,                     /* MINUS  */
  YYSYMBOL_PLUS = 48,                      /* PLUS  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_program = 56,                   /* program  */
  YYSYMBOL_prikazy = 57,                   /* prikazy  */
  YYSYMBOL_prikaz = 58,                    /* prikaz  */
  YYSYMBOL_vyrazf = 59,                    /* vyrazf  */
  YYSYMBOL_retez = 60,                     /* retez  */
  YYSYMBOL_vyraz = 61,                     /* vyraz  */
  YYSYMBOL_promenna = 62                   /* promenna  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   527

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
       2,     2,     2,    44,     2,     2,     2,    41,    28,     2,
      52,    53,    39,    37,    54,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      31,    13,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    26,    50,    45,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      29,    30,    33,    34,    35,    36,    42,    43,    46,    47,
      48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    42,    43,    45,    47,    49,    51,    53,
      55,    57,    59,    61,    63,    65,    66,    68,    70,    72,
      74,    76,    78,    80,    82,    84,    86,    89,    92,    95,
      98,   103,   108,   111,   114,   117,   120,   123,   126,   129,
     132,   135,   138,   141,   144,   147,   150,   153,   155,   157,
     159,   161,   163,   165,   167,   169,   171,   173,   175,   178,
     180,   182,   184,   186,   188
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CISLO", "RETEZ",
  "PROMENNA", "IF", "ELSE", "FOR", "WHILE", "DO", "PRINT", "SCAN", "'='",
  "P_NASOB", "P_DELEN", "P_MODUL", "P_PRICT", "P_ODECT", "P_POSUNVLEVO",
  "P_POSUNVPRAVO", "P_AND", "P_XOR", "P_OR", "OR", "AND", "'|'", "'^'",
  "'&'", "ROVNO", "NENIROVNO", "'<'", "'>'", "MENSIROVNO", "VETSIROVNO",
  "POSUNVLEVO", "POSUNVPRAVO", "'+'", "'-'", "'*'", "'/'", "'%'", "INKREM",
  "DEKREM", "'!'", "'~'", "NOT", "MINUS", "PLUS", "'{'", "'}'", "';'",
  "'('", "')'", "','", "$accept", "program", "prikazy", "prikaz", "vyrazf",
  "retez", "vyraz", "promenna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-5)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -46,    80,    30,   -23,   -47,   -47,   -20,   -18,    15,    96,
      16,    17,   132,   132,    70,    70,   132,   132,   132,    80,
     -47,    28,    26,    80,   372,   172,   -47,   -47,   132,   132,
     132,    68,   116,    70,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,     3,    25,   192,   -47,   -47,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   -47,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   -47,   -47,   222,    31,
     428,   252,    27,   -47,   -28,   282,    34,    43,   -47,   -47,
     -47,   171,   444,   459,   473,   486,   203,   203,   229,   229,
     229,   229,   -26,   -26,   -17,   -17,   -47,   -47,   -47,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
      96,   132,    96,   132,    33,   132,    44,    45,   -47,    87,
     400,   -47,   312,   -47,   342,   -47,   -47,    96,   132,    47,
      49,   -47,    50,   -47,   -47,    96,   -47
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    62,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,    61,     1,    14,     0,    16,
       0,     0,     0,     0,    59,    58,    22,    23,    26,    28,
      27,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,     0,     0,
      15,     0,     0,    21,     0,     0,     0,     0,     5,    63,
      60,    46,    45,    44,    43,    42,    40,    41,    36,    37,
      38,    39,    34,    35,    32,    33,    29,    30,    31,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     8,
       0,    11,     0,    18,     0,    17,    20,     0,    16,     0,
       0,     9,     0,    12,    19,     0,    10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,    -3,    -9,   -29,   -47,   -11,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    22,    23,    79,    84,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    34,    35,     1,    87,    38,    39,    40,    36,    37,
      43,    59,    60,    61,    62,    63,    41,    78,    80,    81,
      45,    85,    61,    62,    63,   124,   125,    86,    27,    42,
      26,     4,    28,     5,    29,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    88,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,    12,    13,    30,    32,    33,
      14,    15,    16,    17,    18,     5,    44,    82,    89,   123,
      21,     3,   121,     4,   133,     5,     6,   127,     7,     8,
       9,    10,    11,   128,   137,   135,   136,     3,   143,     4,
     144,     5,     6,   145,     7,     8,     9,    10,    11,   142,
     130,   129,   132,   131,   134,     0,     0,    12,    13,     4,
      83,     5,    14,    15,    16,    17,    18,    80,   141,    19,
      -4,    20,    21,    12,    13,     4,   146,     5,    14,    15,
      16,    17,    18,     0,     0,    19,     0,    20,    21,     0,
       0,     0,     0,    12,    13,     0,     0,     0,    14,    15,
      16,    17,    18,     0,     0,     0,     0,     0,    21,    12,
      13,     0,     0,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,    21,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    76,    77,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    90,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    57,    58,    59,    60,    61,    62,
      63,     0,     0,     0,     0,   120,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63
};

static const yytype_int16 yycheck[] =
{
       9,    12,    13,    49,     1,    16,    17,    18,    14,    15,
      21,    37,    38,    39,    40,    41,    19,    28,    29,    30,
      23,    32,    39,    40,    41,    53,    54,    33,    51,     1,
       0,     3,    52,     5,    52,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    50,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    37,    38,    52,    52,    52,
      42,    43,    44,    45,    46,     5,    50,     9,    53,    52,
      52,     1,    51,     3,    51,     5,     6,    53,     8,     9,
      10,    11,    12,    50,     7,    51,    51,     1,    51,     3,
      51,     5,     6,    53,     8,     9,    10,    11,    12,   138,
     121,   120,   123,   122,   125,    -1,    -1,    37,    38,     3,
       4,     5,    42,    43,    44,    45,    46,   138,   137,    49,
      50,    51,    52,    37,    38,     3,   145,     5,    42,    43,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,
      -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    37,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    42,    43,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    53,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    53,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    56,     1,     3,     5,     6,     8,     9,    10,
      11,    12,    37,    38,    42,    43,    44,    45,    46,    49,
      51,    52,    57,    58,    61,    62,     0,    51,    52,    52,
      52,    58,    52,    52,    61,    61,    62,    62,    61,    61,
      61,    57,     1,    61,    50,    57,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    51,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    42,    43,    61,    59,
      61,    61,     9,     4,    60,    61,    62,     1,    50,    53,
      53,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      53,    51,    53,    52,    53,    54,    53,    53,    50,    58,
      61,    58,    61,    51,    61,    51,    51,     7,    51,    53,
      53,    58,    59,    51,    51,    53,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    58,    58,    58,
      58,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     0,     3,     2,     1,     5,     7,
       9,     5,     7,     4,     2,     1,     0,     5,     5,     7,
       5,     1,     2,     2,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     1,     3,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: '{' prikazy '}'  */
#line 40 "mikroC.y"
                              { Koren=(yyvsp[-1].u); return 0; }
#line 1566 "mikroC.tab.cpp"
    break;

  case 3: /* prikazy: prikaz prikazy  */
#line 42 "mikroC.y"
                              { (yyval.u)= (yyvsp[0].u) ? GenUzel(0,(yyvsp[-1].u),(yyvsp[0].u)) : (yyvsp[-1].u); }
#line 1572 "mikroC.tab.cpp"
    break;

  case 4: /* prikazy: %empty  */
#line 43 "mikroC.y"
                              { (yyval.u)=NULL; }
#line 1578 "mikroC.tab.cpp"
    break;

  case 5: /* prikaz: '{' prikazy '}'  */
#line 45 "mikroC.y"
                              { (yyval.u)=(yyvsp[-1].u); }
#line 1584 "mikroC.tab.cpp"
    break;

  case 6: /* prikaz: vyraz ';'  */
#line 47 "mikroC.y"
                              { (yyval.u)=(yyvsp[-1].u); }
#line 1590 "mikroC.tab.cpp"
    break;

  case 7: /* prikaz: ';'  */
#line 49 "mikroC.y"
                              { (yyval.u)=NULL; }
#line 1596 "mikroC.tab.cpp"
    break;

  case 8: /* prikaz: IF '(' vyraz ')' prikaz  */
#line 51 "mikroC.y"
                                   { (yyval.u)=GenUzel(IF,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1602 "mikroC.tab.cpp"
    break;

  case 9: /* prikaz: IF '(' vyraz ')' prikaz ELSE prikaz  */
#line 53 "mikroC.y"
                                               { (yyval.u)=GenUzel(IF,(yyvsp[-4].u),(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1608 "mikroC.tab.cpp"
    break;

  case 10: /* prikaz: FOR '(' vyrazf ';' vyraz ';' vyrazf ')' prikaz  */
#line 55 "mikroC.y"
                                                          { (yyval.u)=GenUzel(FOR,(yyvsp[-6].u),(yyvsp[-4].u),(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1614 "mikroC.tab.cpp"
    break;

  case 11: /* prikaz: WHILE '(' vyraz ')' prikaz  */
#line 57 "mikroC.y"
                                      { (yyval.u)=GenUzel(WHILE,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1620 "mikroC.tab.cpp"
    break;

  case 12: /* prikaz: DO prikaz WHILE '(' vyraz ')' ';'  */
#line 59 "mikroC.y"
                                             { (yyval.u)=GenUzel(DO,(yyvsp[-5].u),(yyvsp[-2].u)); }
#line 1626 "mikroC.tab.cpp"
    break;

  case 13: /* prikaz: '{' prikazy error '}'  */
#line 61 "mikroC.y"
                                 { (yyval.u)=NULL; }
#line 1632 "mikroC.tab.cpp"
    break;

  case 14: /* prikaz: error ';'  */
#line 63 "mikroC.y"
                              { (yyval.u)=NULL; }
#line 1638 "mikroC.tab.cpp"
    break;

  case 15: /* vyrazf: vyraz  */
#line 65 "mikroC.y"
                              { (yyval.u)=(yyvsp[0].u); }
#line 1644 "mikroC.tab.cpp"
    break;

  case 16: /* vyrazf: %empty  */
#line 66 "mikroC.y"
                              { (yyval.u)=NULL; }
#line 1650 "mikroC.tab.cpp"
    break;

  case 17: /* prikaz: PRINT '(' vyraz ')' ';'  */
#line 68 "mikroC.y"
                                   { (yyval.u)=GenUzel(PRINT,(yyvsp[-2].u)); }
#line 1656 "mikroC.tab.cpp"
    break;

  case 18: /* prikaz: PRINT '(' retez ')' ';'  */
#line 70 "mikroC.y"
                                   { (yyval.u)=GenUzel(PRINT,(yyvsp[-2].u)); }
#line 1662 "mikroC.tab.cpp"
    break;

  case 19: /* prikaz: PRINT '(' retez ',' vyraz ')' ';'  */
#line 72 "mikroC.y"
                                             { (yyval.u)=GenUzel(PRINT,(yyvsp[-4].u),(yyvsp[-2].u)); }
#line 1668 "mikroC.tab.cpp"
    break;

  case 20: /* prikaz: SCAN '(' promenna ')' ';'  */
#line 74 "mikroC.y"
                                     { (yyval.u)=GenUzel(SCAN,(yyvsp[-2].u)); }
#line 1674 "mikroC.tab.cpp"
    break;

  case 21: /* retez: RETEZ  */
#line 76 "mikroC.y"
                              { (yyval.u)=GenRetez((yyvsp[0].r)); }
#line 1680 "mikroC.tab.cpp"
    break;

  case 22: /* vyraz: INKREM promenna  */
#line 78 "mikroC.y"
                              { (yyval.u)=GenUzel(INKREM,(yyvsp[0].u)); }
#line 1686 "mikroC.tab.cpp"
    break;

  case 23: /* vyraz: DEKREM promenna  */
#line 80 "mikroC.y"
                              { (yyval.u)=GenUzel(DEKREM,(yyvsp[0].u)); }
#line 1692 "mikroC.tab.cpp"
    break;

  case 24: /* vyraz: promenna INKREM  */
#line 82 "mikroC.y"
                              { (yyval.u)=GenUzel(INKREM,NULL,(yyvsp[-1].u)); }
#line 1698 "mikroC.tab.cpp"
    break;

  case 25: /* vyraz: promenna DEKREM  */
#line 84 "mikroC.y"
                              { (yyval.u)=GenUzel(DEKREM,NULL,(yyvsp[-1].u)); }
#line 1704 "mikroC.tab.cpp"
    break;

  case 26: /* vyraz: '!' vyraz  */
#line 86 "mikroC.y"
                              { if (Konst((yyvsp[0].u))) { (yyvsp[0].u)->z.Cislo=!(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[0].u); }
                                else (yyval.u)=GenUzel('!',(yyvsp[0].u)); }
#line 1711 "mikroC.tab.cpp"
    break;

  case 27: /* vyraz: NOT vyraz  */
#line 89 "mikroC.y"
                              { if (Konst((yyvsp[0].u))) { (yyvsp[0].u)->z.Cislo=!(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[0].u); }
                                else (yyval.u)=GenUzel('!',(yyvsp[0].u)); }
#line 1718 "mikroC.tab.cpp"
    break;

  case 28: /* vyraz: '~' vyraz  */
#line 92 "mikroC.y"
                              { if (Konst((yyvsp[0].u))) { (yyvsp[0].u)->z.Cislo=~(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[0].u); }
                                else (yyval.u)=GenUzel('~',(yyvsp[0].u)); }
#line 1725 "mikroC.tab.cpp"
    break;

  case 29: /* vyraz: vyraz '*' vyraz  */
#line 95 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo*=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('*',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1732 "mikroC.tab.cpp"
    break;

  case 30: /* vyraz: vyraz '/' vyraz  */
#line 98 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { if ((yyvsp[0].u)->z.Cislo!=0) (yyvsp[-2].u)->z.Cislo/=(yyvsp[0].u)->z.Cislo;
                                                    else Chyba("Deleni nulou");
                                                    (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('/',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1741 "mikroC.tab.cpp"
    break;

  case 31: /* vyraz: vyraz '%' vyraz  */
#line 103 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { if ((yyvsp[0].u)->z.Cislo!=0) (yyvsp[-2].u)->z.Cislo%=(yyvsp[0].u)->z.Cislo;
                                                    else Chyba("Deleni nulou");
                                                    (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('%',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1750 "mikroC.tab.cpp"
    break;

  case 32: /* vyraz: vyraz '+' vyraz  */
#line 108 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo+=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('+',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1757 "mikroC.tab.cpp"
    break;

  case 33: /* vyraz: vyraz '-' vyraz  */
#line 111 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo-=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('-',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1764 "mikroC.tab.cpp"
    break;

  case 34: /* vyraz: vyraz POSUNVLEVO vyraz  */
#line 114 "mikroC.y"
                                   { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo<<=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                     else (yyval.u)=GenUzel(POSUNVLEVO,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1771 "mikroC.tab.cpp"
    break;

  case 35: /* vyraz: vyraz POSUNVPRAVO vyraz  */
#line 117 "mikroC.y"
                                   { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo>>=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                     else (yyval.u)=GenUzel(POSUNVPRAVO,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1778 "mikroC.tab.cpp"
    break;

  case 36: /* vyraz: vyraz '<' vyraz  */
#line 120 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo= (yyvsp[-2].u)->z.Cislo<(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('<',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1785 "mikroC.tab.cpp"
    break;

  case 37: /* vyraz: vyraz '>' vyraz  */
#line 123 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo= (yyvsp[-2].u)->z.Cislo>(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('>',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1792 "mikroC.tab.cpp"
    break;

  case 38: /* vyraz: vyraz MENSIROVNO vyraz  */
#line 126 "mikroC.y"
                                  { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo= (yyvsp[-2].u)->z.Cislo<=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                    else (yyval.u)=GenUzel(MENSIROVNO,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1799 "mikroC.tab.cpp"
    break;

  case 39: /* vyraz: vyraz VETSIROVNO vyraz  */
#line 129 "mikroC.y"
                                  { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo= (yyvsp[-2].u)->z.Cislo>=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                    else (yyval.u)=GenUzel(VETSIROVNO,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1806 "mikroC.tab.cpp"
    break;

  case 40: /* vyraz: vyraz ROVNO vyraz  */
#line 132 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo= (yyvsp[-2].u)->z.Cislo==(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel(ROVNO,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1813 "mikroC.tab.cpp"
    break;

  case 41: /* vyraz: vyraz NENIROVNO vyraz  */
#line 135 "mikroC.y"
                                 { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo= (yyvsp[-2].u)->z.Cislo!=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                   else (yyval.u)=GenUzel(NENIROVNO,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1820 "mikroC.tab.cpp"
    break;

  case 42: /* vyraz: vyraz '&' vyraz  */
#line 138 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo&=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('&',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1827 "mikroC.tab.cpp"
    break;

  case 43: /* vyraz: vyraz '^' vyraz  */
#line 141 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo^=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('^',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1834 "mikroC.tab.cpp"
    break;

  case 44: /* vyraz: vyraz '|' vyraz  */
#line 144 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo|=(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel('|',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1841 "mikroC.tab.cpp"
    break;

  case 45: /* vyraz: vyraz AND vyraz  */
#line 147 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo= (yyvsp[-2].u)->z.Cislo && (yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel(AND,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1848 "mikroC.tab.cpp"
    break;

  case 46: /* vyraz: vyraz OR vyraz  */
#line 150 "mikroC.y"
                              { if (Konst((yyvsp[-2].u),(yyvsp[0].u))) { (yyvsp[-2].u)->z.Cislo= (yyvsp[-2].u)->z.Cislo || (yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[-2].u); }
                                else (yyval.u)=GenUzel(OR,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1855 "mikroC.tab.cpp"
    break;

  case 47: /* vyraz: promenna '=' vyraz  */
#line 153 "mikroC.y"
                              { (yyval.u)=GenUzel('=',(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1861 "mikroC.tab.cpp"
    break;

  case 48: /* vyraz: promenna P_NASOB vyraz  */
#line 155 "mikroC.y"
                                  { (yyval.u)=GenUzel(P_NASOB,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1867 "mikroC.tab.cpp"
    break;

  case 49: /* vyraz: promenna P_DELEN vyraz  */
#line 157 "mikroC.y"
                                  { (yyval.u)=GenUzel(P_DELEN,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1873 "mikroC.tab.cpp"
    break;

  case 50: /* vyraz: promenna P_MODUL vyraz  */
#line 159 "mikroC.y"
                                  { (yyval.u)=GenUzel(P_MODUL,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1879 "mikroC.tab.cpp"
    break;

  case 51: /* vyraz: promenna P_PRICT vyraz  */
#line 161 "mikroC.y"
                                  { (yyval.u)=GenUzel(P_PRICT,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1885 "mikroC.tab.cpp"
    break;

  case 52: /* vyraz: promenna P_ODECT vyraz  */
#line 163 "mikroC.y"
                                  { (yyval.u)=GenUzel(P_ODECT,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1891 "mikroC.tab.cpp"
    break;

  case 53: /* vyraz: promenna P_POSUNVLEVO vyraz  */
#line 165 "mikroC.y"
                                        { (yyval.u)=GenUzel(P_POSUNVLEVO,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1897 "mikroC.tab.cpp"
    break;

  case 54: /* vyraz: promenna P_POSUNVPRAVO vyraz  */
#line 167 "mikroC.y"
                                        { (yyval.u)=GenUzel(P_POSUNVPRAVO,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1903 "mikroC.tab.cpp"
    break;

  case 55: /* vyraz: promenna P_AND vyraz  */
#line 169 "mikroC.y"
                                { (yyval.u)=GenUzel(P_AND,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1909 "mikroC.tab.cpp"
    break;

  case 56: /* vyraz: promenna P_XOR vyraz  */
#line 171 "mikroC.y"
                                { (yyval.u)=GenUzel(P_XOR,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1915 "mikroC.tab.cpp"
    break;

  case 57: /* vyraz: promenna P_OR vyraz  */
#line 173 "mikroC.y"
                                { (yyval.u)=GenUzel(P_OR,(yyvsp[-2].u),(yyvsp[0].u)); }
#line 1921 "mikroC.tab.cpp"
    break;

  case 58: /* vyraz: '-' vyraz  */
#line 175 "mikroC.y"
                                 { if (Konst((yyvsp[0].u))) { (yyvsp[0].u)->z.Cislo=-(yyvsp[0].u)->z.Cislo; (yyval.u)=(yyvsp[0].u); }
                                   else (yyval.u)=GenUzel('-',(yyvsp[0].u)); }
#line 1928 "mikroC.tab.cpp"
    break;

  case 59: /* vyraz: '+' vyraz  */
#line 178 "mikroC.y"
                                { (yyval.u)=(yyvsp[0].u); }
#line 1934 "mikroC.tab.cpp"
    break;

  case 60: /* vyraz: '(' vyraz ')'  */
#line 180 "mikroC.y"
                              { (yyval.u)=(yyvsp[-1].u); }
#line 1940 "mikroC.tab.cpp"
    break;

  case 61: /* vyraz: promenna  */
#line 182 "mikroC.y"
                              { (yyval.u)=(yyvsp[0].u); }
#line 1946 "mikroC.tab.cpp"
    break;

  case 62: /* vyraz: CISLO  */
#line 184 "mikroC.y"
                              { (yyval.u)=GenCislo((yyvsp[0].c)); }
#line 1952 "mikroC.tab.cpp"
    break;

  case 63: /* vyraz: '(' error ')'  */
#line 186 "mikroC.y"
                              { (yyval.u)=NULL; }
#line 1958 "mikroC.tab.cpp"
    break;

  case 64: /* promenna: PROMENNA  */
#line 188 "mikroC.y"
                              { (yyval.u)=GenPromen((yyvsp[0].r)); }
#line 1964 "mikroC.tab.cpp"
    break;


#line 1968 "mikroC.tab.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 190 "mikroC.y"


static bool Konst(const Uzel *u)
{ return u && u->Typ==CISLO; }

static bool Konst(const Uzel *u1,const Uzel *u2)
{ return u1 && u1->Typ==CISLO && u2 && u2->Typ==CISLO; }

