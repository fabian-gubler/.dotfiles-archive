/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gram.y"

#include <stdlib.h>

#include "sc.h"
#include "cmds/cmds.h"
#include "interp.h"
#include "macros.h"
#include "actions/sort.h"
#include "actions/filter.h"
#include "maps.h"
#include "marks.h"
#include "xmalloc.h" // for scxfree
#include "actions/hide_show.h"
#include "cmds/cmds_normal.h"
#include "conf.h"
#include "pipe.h"
#include "main.h"
#include "file.h"
#include "tui.h"
#include "undo.h"
#include "yank.h"
#include "graph.h"
#include "utils/dictionary.h"
#include "trigger.h"
#include "actions/shift.h"
#include "clipboard.h"
#include "actions/plot.h"
#include "actions/subtotal.h"
#include "actions/freeze.h"
#include "sheet.h"
#include "vmtbl.h"
#include "cmds/cmds_command.h"

void yyerror(char *err);               // error routine for yacc (gram.y)
int yylex();
extern struct session * session;

#ifdef USELOCALE
#include <locale.h>
#endif

#ifndef MSDOS
#include <unistd.h>
#endif

#define ENULL (struct enode *) 0

#line 119 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    STRING = 258,                  /* STRING  */
    COL = 259,                     /* COL  */
    NUMBER = 260,                  /* NUMBER  */
    FNUMBER = 261,                 /* FNUMBER  */
    RANGE = 262,                   /* RANGE  */
    VAR = 263,                     /* VAR  */
    WORD = 264,                    /* WORD  */
    MAPWORD = 265,                 /* MAPWORD  */
    PLUGIN = 266,                  /* PLUGIN  */
    S_SHOW = 267,                  /* S_SHOW  */
    S_HIDE = 268,                  /* S_HIDE  */
    S_SHOWROW = 269,               /* S_SHOWROW  */
    S_HIDEROW = 270,               /* S_HIDEROW  */
    S_SHOWCOL = 271,               /* S_SHOWCOL  */
    S_HIDECOL = 272,               /* S_HIDECOL  */
    S_FREEZE = 273,                /* S_FREEZE  */
    S_UNFREEZE = 274,              /* S_UNFREEZE  */
    S_MARK = 275,                  /* S_MARK  */
    S_AUTOFIT = 276,               /* S_AUTOFIT  */
    S_PAD = 277,                   /* S_PAD  */
    S_DELETECOL = 278,             /* S_DELETECOL  */
    S_DATEFMT = 279,               /* S_DATEFMT  */
    S_SUBTOTAL = 280,              /* S_SUBTOTAL  */
    S_RSUBTOTAL = 281,             /* S_RSUBTOTAL  */
    S_FORMAT = 282,                /* S_FORMAT  */
    S_FMT = 283,                   /* S_FMT  */
    S_LET = 284,                   /* S_LET  */
    S_LABEL = 285,                 /* S_LABEL  */
    S_LEFTSTRING = 286,            /* S_LEFTSTRING  */
    S_RIGHTSTRING = 287,           /* S_RIGHTSTRING  */
    S_LEFTJUSTIFY = 288,           /* S_LEFTJUSTIFY  */
    S_RIGHTJUSTIFY = 289,          /* S_RIGHTJUSTIFY  */
    S_CENTER = 290,                /* S_CENTER  */
    S_SORT = 291,                  /* S_SORT  */
    S_FILTERON = 292,              /* S_FILTERON  */
    S_GOTO = 293,                  /* S_GOTO  */
    S_GOTOB = 294,                 /* S_GOTOB  */
    S_CCOPY = 295,                 /* S_CCOPY  */
    S_CPASTE = 296,                /* S_CPASTE  */
    S_PLOT = 297,                  /* S_PLOT  */
    S_LOCK = 298,                  /* S_LOCK  */
    S_UNLOCK = 299,                /* S_UNLOCK  */
    S_DEFINE = 300,                /* S_DEFINE  */
    S_UNDEFINE = 301,              /* S_UNDEFINE  */
    S_DETAIL = 302,                /* S_DETAIL  */
    S_EVAL = 303,                  /* S_EVAL  */
    S_SEVAL = 304,                 /* S_SEVAL  */
    S_ERROR = 305,                 /* S_ERROR  */
    S_FILL = 306,                  /* S_FILL  */
    S_STRTONUM = 307,              /* S_STRTONUM  */
    S_DELETEROW = 308,             /* S_DELETEROW  */
    S_VALUEIZEALL = 309,           /* S_VALUEIZEALL  */
    S_SHIFT = 310,                 /* S_SHIFT  */
    S_GETNUM = 311,                /* S_GETNUM  */
    S_YANKAREA = 312,              /* S_YANKAREA  */
    S_PASTEYANKED = 313,           /* S_PASTEYANKED  */
    S_GETSTRING = 314,             /* S_GETSTRING  */
    S_GETEXP = 315,                /* S_GETEXP  */
    S_GETFMT = 316,                /* S_GETFMT  */
    S_GETFORMAT = 317,             /* S_GETFORMAT  */
    S_RECALC = 318,                /* S_RECALC  */
    S_EXECUTE = 319,               /* S_EXECUTE  */
    S_QUIT = 320,                  /* S_QUIT  */
    S_EXPORT = 321,                /* S_EXPORT  */
    S_REBUILD_GRAPH = 322,         /* S_REBUILD_GRAPH  */
    S_PRINT_GRAPH = 323,           /* S_PRINT_GRAPH  */
    S_SYNCREFS = 324,              /* S_SYNCREFS  */
    S_REDO = 325,                  /* S_REDO  */
    S_UNDO = 326,                  /* S_UNDO  */
    S_IMAP = 327,                  /* S_IMAP  */
    S_CMAP = 328,                  /* S_CMAP  */
    S_NEWSHEET = 329,              /* S_NEWSHEET  */
    S_NEXTSHEET = 330,             /* S_NEXTSHEET  */
    S_PREVSHEET = 331,             /* S_PREVSHEET  */
    S_DELSHEET = 332,              /* S_DELSHEET  */
    S_MOVETOSHEET = 333,           /* S_MOVETOSHEET  */
    S_RENAMESHEET = 334,           /* S_RENAMESHEET  */
    S_NMAP = 335,                  /* S_NMAP  */
    S_VMAP = 336,                  /* S_VMAP  */
    S_INOREMAP = 337,              /* S_INOREMAP  */
    S_CNOREMAP = 338,              /* S_CNOREMAP  */
    S_NNOREMAP = 339,              /* S_NNOREMAP  */
    S_VNOREMAP = 340,              /* S_VNOREMAP  */
    S_NUNMAP = 341,                /* S_NUNMAP  */
    S_IUNMAP = 342,                /* S_IUNMAP  */
    S_CUNMAP = 343,                /* S_CUNMAP  */
    S_VUNMAP = 344,                /* S_VUNMAP  */
    S_COLOR = 345,                 /* S_COLOR  */
    S_CELLCOLOR = 346,             /* S_CELLCOLOR  */
    S_UNFORMAT = 347,              /* S_UNFORMAT  */
    S_REDEFINE_COLOR = 348,        /* S_REDEFINE_COLOR  */
    S_DEFINE_COLOR = 349,          /* S_DEFINE_COLOR  */
    S_SET = 350,                   /* S_SET  */
    S_FCOPY = 351,                 /* S_FCOPY  */
    S_FSUM = 352,                  /* S_FSUM  */
    S_TRIGGER = 353,               /* S_TRIGGER  */
    S_UNTRIGGER = 354,             /* S_UNTRIGGER  */
    K_AUTOBACKUP = 355,            /* K_AUTOBACKUP  */
    K_NOAUTOBACKUP = 356,          /* K_NOAUTOBACKUP  */
    K_AUTOCALC = 357,              /* K_AUTOCALC  */
    K_NOAUTOCALC = 358,            /* K_NOAUTOCALC  */
    K_DEBUG = 359,                 /* K_DEBUG  */
    K_NODEBUG = 360,               /* K_NODEBUG  */
    K_TRG = 361,                   /* K_TRG  */
    K_NOTRG = 362,                 /* K_NOTRG  */
    K_EXTERNAL_FUNCTIONS = 363,    /* K_EXTERNAL_FUNCTIONS  */
    K_NOEXTERNAL_FUNCTIONS = 364,  /* K_NOEXTERNAL_FUNCTIONS  */
    K_EXEC_LUA = 365,              /* K_EXEC_LUA  */
    K_NOEXEC_LUA = 366,            /* K_NOEXEC_LUA  */
    K_HALF_PAGE_SCROLL = 367,      /* K_HALF_PAGE_SCROLL  */
    K_NOHALF_PAGE_SCROLL = 368,    /* K_NOHALF_PAGE_SCROLL  */
    K_NOCURSES = 369,              /* K_NOCURSES  */
    K_CURSES = 370,                /* K_CURSES  */
    K_NUMERIC = 371,               /* K_NUMERIC  */
    K_NONUMERIC = 372,             /* K_NONUMERIC  */
    K_NUMERIC_DECIMAL = 373,       /* K_NUMERIC_DECIMAL  */
    K_NONUMERIC_DECIMAL = 374,     /* K_NONUMERIC_DECIMAL  */
    K_NUMERIC_ZERO = 375,          /* K_NUMERIC_ZERO  */
    K_NONUMERIC_ZERO = 376,        /* K_NONUMERIC_ZERO  */
    K_OVERLAP = 377,               /* K_OVERLAP  */
    K_NOOVERLAP = 378,             /* K_NOOVERLAP  */
    K_INPUT_BAR_BOTTOM = 379,      /* K_INPUT_BAR_BOTTOM  */
    K_UNDERLINE_GRID = 380,        /* K_UNDERLINE_GRID  */
    K_TRUNCATE = 381,              /* K_TRUNCATE  */
    K_NOTRUNCATE = 382,            /* K_NOTRUNCATE  */
    K_AUTOWRAP = 383,              /* K_AUTOWRAP  */
    K_NOAUTOWRAP = 384,            /* K_NOAUTOWRAP  */
    K_QUIET = 385,                 /* K_QUIET  */
    K_NOQUIET = 386,               /* K_NOQUIET  */
    K_QUIT_AFTERLOAD = 387,        /* K_QUIT_AFTERLOAD  */
    K_NOQUIT_AFTERLOAD = 388,      /* K_NOQUIT_AFTERLOAD  */
    K_XLSX_READFORMULAS = 389,     /* K_XLSX_READFORMULAS  */
    K_NOXLSX_READFORMULAS = 390,   /* K_NOXLSX_READFORMULAS  */
    K_DEFAULT_COPY_TO_CLIPBOARD_CMD = 391, /* K_DEFAULT_COPY_TO_CLIPBOARD_CMD  */
    K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD = 392, /* K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD  */
    K_COPY_TO_CLIPBOARD_DELIMITED_TAB = 393, /* K_COPY_TO_CLIPBOARD_DELIMITED_TAB  */
    K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB = 394, /* K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB  */
    K_IGNORECASE = 395,            /* K_IGNORECASE  */
    K_NOIGNORECASE = 396,          /* K_NOIGNORECASE  */
    K_TM_GMTOFF = 397,             /* K_TM_GMTOFF  */
    K_COMMAND_TIMEOUT = 398,       /* K_COMMAND_TIMEOUT  */
    K_MAPPING_TIMEOUT = 399,       /* K_MAPPING_TIMEOUT  */
    K_NEWLINE_ACTION = 400,        /* K_NEWLINE_ACTION  */
    K_SHOW_CURSOR = 401,           /* K_SHOW_CURSOR  */
    K_NOSHOW_CURSOR = 402,         /* K_NOSHOW_CURSOR  */
    K_ERROR = 403,                 /* K_ERROR  */
    K_INVALID = 404,               /* K_INVALID  */
    K_FIXED = 405,                 /* K_FIXED  */
    K_SUM = 406,                   /* K_SUM  */
    K_PROD = 407,                  /* K_PROD  */
    K_AVG = 408,                   /* K_AVG  */
    K_STDDEV = 409,                /* K_STDDEV  */
    K_COUNT = 410,                 /* K_COUNT  */
    K_ROWS = 411,                  /* K_ROWS  */
    K_COLS = 412,                  /* K_COLS  */
    K_ABS = 413,                   /* K_ABS  */
    K_FROW = 414,                  /* K_FROW  */
    K_FCOL = 415,                  /* K_FCOL  */
    K_ACOS = 416,                  /* K_ACOS  */
    K_ASIN = 417,                  /* K_ASIN  */
    K_ATAN = 418,                  /* K_ATAN  */
    K_ATAN2 = 419,                 /* K_ATAN2  */
    K_CEIL = 420,                  /* K_CEIL  */
    K_COS = 421,                   /* K_COS  */
    K_EXP = 422,                   /* K_EXP  */
    K_FABS = 423,                  /* K_FABS  */
    K_FLOOR = 424,                 /* K_FLOOR  */
    K_HYPOT = 425,                 /* K_HYPOT  */
    K_LN = 426,                    /* K_LN  */
    K_LOG = 427,                   /* K_LOG  */
    K_PI = 428,                    /* K_PI  */
    K_POW = 429,                   /* K_POW  */
    K_SIN = 430,                   /* K_SIN  */
    K_SQRT = 431,                  /* K_SQRT  */
    K_TAN = 432,                   /* K_TAN  */
    K_DTR = 433,                   /* K_DTR  */
    K_RTD = 434,                   /* K_RTD  */
    K_MAX = 435,                   /* K_MAX  */
    K_MIN = 436,                   /* K_MIN  */
    K_RND = 437,                   /* K_RND  */
    K_ROUND = 438,                 /* K_ROUND  */
    K_IF = 439,                    /* K_IF  */
    K_PV = 440,                    /* K_PV  */
    K_FV = 441,                    /* K_FV  */
    K_PMT = 442,                   /* K_PMT  */
    K_HOUR = 443,                  /* K_HOUR  */
    K_MINUTE = 444,                /* K_MINUTE  */
    K_SECOND = 445,                /* K_SECOND  */
    K_MONTH = 446,                 /* K_MONTH  */
    K_DAY = 447,                   /* K_DAY  */
    K_YEAR = 448,                  /* K_YEAR  */
    K_NOW = 449,                   /* K_NOW  */
    K_DATE = 450,                  /* K_DATE  */
    K_DTS = 451,                   /* K_DTS  */
    K_TTS = 452,                   /* K_TTS  */
    K_FMT = 453,                   /* K_FMT  */
    K_REPLACE = 454,               /* K_REPLACE  */
    K_SUBSTR = 455,                /* K_SUBSTR  */
    K_UPPER = 456,                 /* K_UPPER  */
    K_LOWER = 457,                 /* K_LOWER  */
    K_CAPITAL = 458,               /* K_CAPITAL  */
    K_STON = 459,                  /* K_STON  */
    K_SLEN = 460,                  /* K_SLEN  */
    K_EQS = 461,                   /* K_EQS  */
    K_EXT = 462,                   /* K_EXT  */
    K_EVALUATE = 463,              /* K_EVALUATE  */
    K_SEVALUATE = 464,             /* K_SEVALUATE  */
    K_LUA = 465,                   /* K_LUA  */
    K_NVAL = 466,                  /* K_NVAL  */
    K_SVAL = 467,                  /* K_SVAL  */
    K_LOOKUP = 468,                /* K_LOOKUP  */
    K_HLOOKUP = 469,               /* K_HLOOKUP  */
    K_VLOOKUP = 470,               /* K_VLOOKUP  */
    K_INDEX = 471,                 /* K_INDEX  */
    K_STINDEX = 472,               /* K_STINDEX  */
    K_GETENT = 473,                /* K_GETENT  */
    K_TBLSTYLE = 474,              /* K_TBLSTYLE  */
    K_TBL = 475,                   /* K_TBL  */
    K_LATEX = 476,                 /* K_LATEX  */
    K_SLATEX = 477,                /* K_SLATEX  */
    K_TEX = 478,                   /* K_TEX  */
    K_FRAME = 479,                 /* K_FRAME  */
    K_RNDTOEVEN = 480,             /* K_RNDTOEVEN  */
    K_FILENAME = 481,              /* K_FILENAME  */
    K_MYROW = 482,                 /* K_MYROW  */
    K_MYCOL = 483,                 /* K_MYCOL  */
    K_LASTROW = 484,               /* K_LASTROW  */
    K_LASTCOL = 485,               /* K_LASTCOL  */
    K_COLTOA = 486,                /* K_COLTOA  */
    K_CRACTION = 487,              /* K_CRACTION  */
    K_CRROW = 488,                 /* K_CRROW  */
    K_CRCOL = 489,                 /* K_CRCOL  */
    K_ROWLIMIT = 490,              /* K_ROWLIMIT  */
    K_COLLIMIT = 491,              /* K_COLLIMIT  */
    K_PAGESIZE = 492,              /* K_PAGESIZE  */
    K_ERR = 493,                   /* K_ERR  */
    K_REF = 494,                   /* K_REF  */
    K_LOCALE = 495,                /* K_LOCALE  */
    K_SET8BIT = 496,               /* K_SET8BIT  */
    K_ASCII = 497,                 /* K_ASCII  */
    K_CHR = 498,                   /* K_CHR  */
    K_FACT = 499                   /* K_FACT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define STRING 258
#define COL 259
#define NUMBER 260
#define FNUMBER 261
#define RANGE 262
#define VAR 263
#define WORD 264
#define MAPWORD 265
#define PLUGIN 266
#define S_SHOW 267
#define S_HIDE 268
#define S_SHOWROW 269
#define S_HIDEROW 270
#define S_SHOWCOL 271
#define S_HIDECOL 272
#define S_FREEZE 273
#define S_UNFREEZE 274
#define S_MARK 275
#define S_AUTOFIT 276
#define S_PAD 277
#define S_DELETECOL 278
#define S_DATEFMT 279
#define S_SUBTOTAL 280
#define S_RSUBTOTAL 281
#define S_FORMAT 282
#define S_FMT 283
#define S_LET 284
#define S_LABEL 285
#define S_LEFTSTRING 286
#define S_RIGHTSTRING 287
#define S_LEFTJUSTIFY 288
#define S_RIGHTJUSTIFY 289
#define S_CENTER 290
#define S_SORT 291
#define S_FILTERON 292
#define S_GOTO 293
#define S_GOTOB 294
#define S_CCOPY 295
#define S_CPASTE 296
#define S_PLOT 297
#define S_LOCK 298
#define S_UNLOCK 299
#define S_DEFINE 300
#define S_UNDEFINE 301
#define S_DETAIL 302
#define S_EVAL 303
#define S_SEVAL 304
#define S_ERROR 305
#define S_FILL 306
#define S_STRTONUM 307
#define S_DELETEROW 308
#define S_VALUEIZEALL 309
#define S_SHIFT 310
#define S_GETNUM 311
#define S_YANKAREA 312
#define S_PASTEYANKED 313
#define S_GETSTRING 314
#define S_GETEXP 315
#define S_GETFMT 316
#define S_GETFORMAT 317
#define S_RECALC 318
#define S_EXECUTE 319
#define S_QUIT 320
#define S_EXPORT 321
#define S_REBUILD_GRAPH 322
#define S_PRINT_GRAPH 323
#define S_SYNCREFS 324
#define S_REDO 325
#define S_UNDO 326
#define S_IMAP 327
#define S_CMAP 328
#define S_NEWSHEET 329
#define S_NEXTSHEET 330
#define S_PREVSHEET 331
#define S_DELSHEET 332
#define S_MOVETOSHEET 333
#define S_RENAMESHEET 334
#define S_NMAP 335
#define S_VMAP 336
#define S_INOREMAP 337
#define S_CNOREMAP 338
#define S_NNOREMAP 339
#define S_VNOREMAP 340
#define S_NUNMAP 341
#define S_IUNMAP 342
#define S_CUNMAP 343
#define S_VUNMAP 344
#define S_COLOR 345
#define S_CELLCOLOR 346
#define S_UNFORMAT 347
#define S_REDEFINE_COLOR 348
#define S_DEFINE_COLOR 349
#define S_SET 350
#define S_FCOPY 351
#define S_FSUM 352
#define S_TRIGGER 353
#define S_UNTRIGGER 354
#define K_AUTOBACKUP 355
#define K_NOAUTOBACKUP 356
#define K_AUTOCALC 357
#define K_NOAUTOCALC 358
#define K_DEBUG 359
#define K_NODEBUG 360
#define K_TRG 361
#define K_NOTRG 362
#define K_EXTERNAL_FUNCTIONS 363
#define K_NOEXTERNAL_FUNCTIONS 364
#define K_EXEC_LUA 365
#define K_NOEXEC_LUA 366
#define K_HALF_PAGE_SCROLL 367
#define K_NOHALF_PAGE_SCROLL 368
#define K_NOCURSES 369
#define K_CURSES 370
#define K_NUMERIC 371
#define K_NONUMERIC 372
#define K_NUMERIC_DECIMAL 373
#define K_NONUMERIC_DECIMAL 374
#define K_NUMERIC_ZERO 375
#define K_NONUMERIC_ZERO 376
#define K_OVERLAP 377
#define K_NOOVERLAP 378
#define K_INPUT_BAR_BOTTOM 379
#define K_UNDERLINE_GRID 380
#define K_TRUNCATE 381
#define K_NOTRUNCATE 382
#define K_AUTOWRAP 383
#define K_NOAUTOWRAP 384
#define K_QUIET 385
#define K_NOQUIET 386
#define K_QUIT_AFTERLOAD 387
#define K_NOQUIT_AFTERLOAD 388
#define K_XLSX_READFORMULAS 389
#define K_NOXLSX_READFORMULAS 390
#define K_DEFAULT_COPY_TO_CLIPBOARD_CMD 391
#define K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD 392
#define K_COPY_TO_CLIPBOARD_DELIMITED_TAB 393
#define K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB 394
#define K_IGNORECASE 395
#define K_NOIGNORECASE 396
#define K_TM_GMTOFF 397
#define K_COMMAND_TIMEOUT 398
#define K_MAPPING_TIMEOUT 399
#define K_NEWLINE_ACTION 400
#define K_SHOW_CURSOR 401
#define K_NOSHOW_CURSOR 402
#define K_ERROR 403
#define K_INVALID 404
#define K_FIXED 405
#define K_SUM 406
#define K_PROD 407
#define K_AVG 408
#define K_STDDEV 409
#define K_COUNT 410
#define K_ROWS 411
#define K_COLS 412
#define K_ABS 413
#define K_FROW 414
#define K_FCOL 415
#define K_ACOS 416
#define K_ASIN 417
#define K_ATAN 418
#define K_ATAN2 419
#define K_CEIL 420
#define K_COS 421
#define K_EXP 422
#define K_FABS 423
#define K_FLOOR 424
#define K_HYPOT 425
#define K_LN 426
#define K_LOG 427
#define K_PI 428
#define K_POW 429
#define K_SIN 430
#define K_SQRT 431
#define K_TAN 432
#define K_DTR 433
#define K_RTD 434
#define K_MAX 435
#define K_MIN 436
#define K_RND 437
#define K_ROUND 438
#define K_IF 439
#define K_PV 440
#define K_FV 441
#define K_PMT 442
#define K_HOUR 443
#define K_MINUTE 444
#define K_SECOND 445
#define K_MONTH 446
#define K_DAY 447
#define K_YEAR 448
#define K_NOW 449
#define K_DATE 450
#define K_DTS 451
#define K_TTS 452
#define K_FMT 453
#define K_REPLACE 454
#define K_SUBSTR 455
#define K_UPPER 456
#define K_LOWER 457
#define K_CAPITAL 458
#define K_STON 459
#define K_SLEN 460
#define K_EQS 461
#define K_EXT 462
#define K_EVALUATE 463
#define K_SEVALUATE 464
#define K_LUA 465
#define K_NVAL 466
#define K_SVAL 467
#define K_LOOKUP 468
#define K_HLOOKUP 469
#define K_VLOOKUP 470
#define K_INDEX 471
#define K_STINDEX 472
#define K_GETENT 473
#define K_TBLSTYLE 474
#define K_TBL 475
#define K_LATEX 476
#define K_SLATEX 477
#define K_TEX 478
#define K_FRAME 479
#define K_RNDTOEVEN 480
#define K_FILENAME 481
#define K_MYROW 482
#define K_MYCOL 483
#define K_LASTROW 484
#define K_LASTCOL 485
#define K_COLTOA 486
#define K_CRACTION 487
#define K_CRROW 488
#define K_CRCOL 489
#define K_ROWLIMIT 490
#define K_COLLIMIT 491
#define K_PAGESIZE 492
#define K_ERR 493
#define K_REF 494
#define K_LOCALE 495
#define K_SET8BIT 496
#define K_ASCII 497
#define K_CHR 498
#define K_FACT 499

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "gram.y"

    int ival;
    double fval;
    struct ent_ptr ent;
    struct enode * enode;
    char * sval;
    struct range_s rval;

#line 669 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_COL = 4,                        /* COL  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_FNUMBER = 6,                    /* FNUMBER  */
  YYSYMBOL_RANGE = 7,                      /* RANGE  */
  YYSYMBOL_VAR = 8,                        /* VAR  */
  YYSYMBOL_WORD = 9,                       /* WORD  */
  YYSYMBOL_MAPWORD = 10,                   /* MAPWORD  */
  YYSYMBOL_PLUGIN = 11,                    /* PLUGIN  */
  YYSYMBOL_S_SHOW = 12,                    /* S_SHOW  */
  YYSYMBOL_S_HIDE = 13,                    /* S_HIDE  */
  YYSYMBOL_S_SHOWROW = 14,                 /* S_SHOWROW  */
  YYSYMBOL_S_HIDEROW = 15,                 /* S_HIDEROW  */
  YYSYMBOL_S_SHOWCOL = 16,                 /* S_SHOWCOL  */
  YYSYMBOL_S_HIDECOL = 17,                 /* S_HIDECOL  */
  YYSYMBOL_S_FREEZE = 18,                  /* S_FREEZE  */
  YYSYMBOL_S_UNFREEZE = 19,                /* S_UNFREEZE  */
  YYSYMBOL_S_MARK = 20,                    /* S_MARK  */
  YYSYMBOL_S_AUTOFIT = 21,                 /* S_AUTOFIT  */
  YYSYMBOL_S_PAD = 22,                     /* S_PAD  */
  YYSYMBOL_S_DELETECOL = 23,               /* S_DELETECOL  */
  YYSYMBOL_S_DATEFMT = 24,                 /* S_DATEFMT  */
  YYSYMBOL_S_SUBTOTAL = 25,                /* S_SUBTOTAL  */
  YYSYMBOL_S_RSUBTOTAL = 26,               /* S_RSUBTOTAL  */
  YYSYMBOL_S_FORMAT = 27,                  /* S_FORMAT  */
  YYSYMBOL_S_FMT = 28,                     /* S_FMT  */
  YYSYMBOL_S_LET = 29,                     /* S_LET  */
  YYSYMBOL_S_LABEL = 30,                   /* S_LABEL  */
  YYSYMBOL_S_LEFTSTRING = 31,              /* S_LEFTSTRING  */
  YYSYMBOL_S_RIGHTSTRING = 32,             /* S_RIGHTSTRING  */
  YYSYMBOL_S_LEFTJUSTIFY = 33,             /* S_LEFTJUSTIFY  */
  YYSYMBOL_S_RIGHTJUSTIFY = 34,            /* S_RIGHTJUSTIFY  */
  YYSYMBOL_S_CENTER = 35,                  /* S_CENTER  */
  YYSYMBOL_S_SORT = 36,                    /* S_SORT  */
  YYSYMBOL_S_FILTERON = 37,                /* S_FILTERON  */
  YYSYMBOL_S_GOTO = 38,                    /* S_GOTO  */
  YYSYMBOL_S_GOTOB = 39,                   /* S_GOTOB  */
  YYSYMBOL_S_CCOPY = 40,                   /* S_CCOPY  */
  YYSYMBOL_S_CPASTE = 41,                  /* S_CPASTE  */
  YYSYMBOL_S_PLOT = 42,                    /* S_PLOT  */
  YYSYMBOL_S_LOCK = 43,                    /* S_LOCK  */
  YYSYMBOL_S_UNLOCK = 44,                  /* S_UNLOCK  */
  YYSYMBOL_S_DEFINE = 45,                  /* S_DEFINE  */
  YYSYMBOL_S_UNDEFINE = 46,                /* S_UNDEFINE  */
  YYSYMBOL_S_DETAIL = 47,                  /* S_DETAIL  */
  YYSYMBOL_S_EVAL = 48,                    /* S_EVAL  */
  YYSYMBOL_S_SEVAL = 49,                   /* S_SEVAL  */
  YYSYMBOL_S_ERROR = 50,                   /* S_ERROR  */
  YYSYMBOL_S_FILL = 51,                    /* S_FILL  */
  YYSYMBOL_S_STRTONUM = 52,                /* S_STRTONUM  */
  YYSYMBOL_S_DELETEROW = 53,               /* S_DELETEROW  */
  YYSYMBOL_S_VALUEIZEALL = 54,             /* S_VALUEIZEALL  */
  YYSYMBOL_S_SHIFT = 55,                   /* S_SHIFT  */
  YYSYMBOL_S_GETNUM = 56,                  /* S_GETNUM  */
  YYSYMBOL_S_YANKAREA = 57,                /* S_YANKAREA  */
  YYSYMBOL_S_PASTEYANKED = 58,             /* S_PASTEYANKED  */
  YYSYMBOL_S_GETSTRING = 59,               /* S_GETSTRING  */
  YYSYMBOL_S_GETEXP = 60,                  /* S_GETEXP  */
  YYSYMBOL_S_GETFMT = 61,                  /* S_GETFMT  */
  YYSYMBOL_S_GETFORMAT = 62,               /* S_GETFORMAT  */
  YYSYMBOL_S_RECALC = 63,                  /* S_RECALC  */
  YYSYMBOL_S_EXECUTE = 64,                 /* S_EXECUTE  */
  YYSYMBOL_S_QUIT = 65,                    /* S_QUIT  */
  YYSYMBOL_S_EXPORT = 66,                  /* S_EXPORT  */
  YYSYMBOL_S_REBUILD_GRAPH = 67,           /* S_REBUILD_GRAPH  */
  YYSYMBOL_S_PRINT_GRAPH = 68,             /* S_PRINT_GRAPH  */
  YYSYMBOL_S_SYNCREFS = 69,                /* S_SYNCREFS  */
  YYSYMBOL_S_REDO = 70,                    /* S_REDO  */
  YYSYMBOL_S_UNDO = 71,                    /* S_UNDO  */
  YYSYMBOL_S_IMAP = 72,                    /* S_IMAP  */
  YYSYMBOL_S_CMAP = 73,                    /* S_CMAP  */
  YYSYMBOL_S_NEWSHEET = 74,                /* S_NEWSHEET  */
  YYSYMBOL_S_NEXTSHEET = 75,               /* S_NEXTSHEET  */
  YYSYMBOL_S_PREVSHEET = 76,               /* S_PREVSHEET  */
  YYSYMBOL_S_DELSHEET = 77,                /* S_DELSHEET  */
  YYSYMBOL_S_MOVETOSHEET = 78,             /* S_MOVETOSHEET  */
  YYSYMBOL_S_RENAMESHEET = 79,             /* S_RENAMESHEET  */
  YYSYMBOL_S_NMAP = 80,                    /* S_NMAP  */
  YYSYMBOL_S_VMAP = 81,                    /* S_VMAP  */
  YYSYMBOL_S_INOREMAP = 82,                /* S_INOREMAP  */
  YYSYMBOL_S_CNOREMAP = 83,                /* S_CNOREMAP  */
  YYSYMBOL_S_NNOREMAP = 84,                /* S_NNOREMAP  */
  YYSYMBOL_S_VNOREMAP = 85,                /* S_VNOREMAP  */
  YYSYMBOL_S_NUNMAP = 86,                  /* S_NUNMAP  */
  YYSYMBOL_S_IUNMAP = 87,                  /* S_IUNMAP  */
  YYSYMBOL_S_CUNMAP = 88,                  /* S_CUNMAP  */
  YYSYMBOL_S_VUNMAP = 89,                  /* S_VUNMAP  */
  YYSYMBOL_S_COLOR = 90,                   /* S_COLOR  */
  YYSYMBOL_S_CELLCOLOR = 91,               /* S_CELLCOLOR  */
  YYSYMBOL_S_UNFORMAT = 92,                /* S_UNFORMAT  */
  YYSYMBOL_S_REDEFINE_COLOR = 93,          /* S_REDEFINE_COLOR  */
  YYSYMBOL_S_DEFINE_COLOR = 94,            /* S_DEFINE_COLOR  */
  YYSYMBOL_S_SET = 95,                     /* S_SET  */
  YYSYMBOL_S_FCOPY = 96,                   /* S_FCOPY  */
  YYSYMBOL_S_FSUM = 97,                    /* S_FSUM  */
  YYSYMBOL_S_TRIGGER = 98,                 /* S_TRIGGER  */
  YYSYMBOL_S_UNTRIGGER = 99,               /* S_UNTRIGGER  */
  YYSYMBOL_K_AUTOBACKUP = 100,             /* K_AUTOBACKUP  */
  YYSYMBOL_K_NOAUTOBACKUP = 101,           /* K_NOAUTOBACKUP  */
  YYSYMBOL_K_AUTOCALC = 102,               /* K_AUTOCALC  */
  YYSYMBOL_K_NOAUTOCALC = 103,             /* K_NOAUTOCALC  */
  YYSYMBOL_K_DEBUG = 104,                  /* K_DEBUG  */
  YYSYMBOL_K_NODEBUG = 105,                /* K_NODEBUG  */
  YYSYMBOL_K_TRG = 106,                    /* K_TRG  */
  YYSYMBOL_K_NOTRG = 107,                  /* K_NOTRG  */
  YYSYMBOL_K_EXTERNAL_FUNCTIONS = 108,     /* K_EXTERNAL_FUNCTIONS  */
  YYSYMBOL_K_NOEXTERNAL_FUNCTIONS = 109,   /* K_NOEXTERNAL_FUNCTIONS  */
  YYSYMBOL_K_EXEC_LUA = 110,               /* K_EXEC_LUA  */
  YYSYMBOL_K_NOEXEC_LUA = 111,             /* K_NOEXEC_LUA  */
  YYSYMBOL_K_HALF_PAGE_SCROLL = 112,       /* K_HALF_PAGE_SCROLL  */
  YYSYMBOL_K_NOHALF_PAGE_SCROLL = 113,     /* K_NOHALF_PAGE_SCROLL  */
  YYSYMBOL_K_NOCURSES = 114,               /* K_NOCURSES  */
  YYSYMBOL_K_CURSES = 115,                 /* K_CURSES  */
  YYSYMBOL_K_NUMERIC = 116,                /* K_NUMERIC  */
  YYSYMBOL_K_NONUMERIC = 117,              /* K_NONUMERIC  */
  YYSYMBOL_K_NUMERIC_DECIMAL = 118,        /* K_NUMERIC_DECIMAL  */
  YYSYMBOL_K_NONUMERIC_DECIMAL = 119,      /* K_NONUMERIC_DECIMAL  */
  YYSYMBOL_K_NUMERIC_ZERO = 120,           /* K_NUMERIC_ZERO  */
  YYSYMBOL_K_NONUMERIC_ZERO = 121,         /* K_NONUMERIC_ZERO  */
  YYSYMBOL_K_OVERLAP = 122,                /* K_OVERLAP  */
  YYSYMBOL_K_NOOVERLAP = 123,              /* K_NOOVERLAP  */
  YYSYMBOL_K_INPUT_BAR_BOTTOM = 124,       /* K_INPUT_BAR_BOTTOM  */
  YYSYMBOL_K_UNDERLINE_GRID = 125,         /* K_UNDERLINE_GRID  */
  YYSYMBOL_K_TRUNCATE = 126,               /* K_TRUNCATE  */
  YYSYMBOL_K_NOTRUNCATE = 127,             /* K_NOTRUNCATE  */
  YYSYMBOL_K_AUTOWRAP = 128,               /* K_AUTOWRAP  */
  YYSYMBOL_K_NOAUTOWRAP = 129,             /* K_NOAUTOWRAP  */
  YYSYMBOL_K_QUIET = 130,                  /* K_QUIET  */
  YYSYMBOL_K_NOQUIET = 131,                /* K_NOQUIET  */
  YYSYMBOL_K_QUIT_AFTERLOAD = 132,         /* K_QUIT_AFTERLOAD  */
  YYSYMBOL_K_NOQUIT_AFTERLOAD = 133,       /* K_NOQUIT_AFTERLOAD  */
  YYSYMBOL_K_XLSX_READFORMULAS = 134,      /* K_XLSX_READFORMULAS  */
  YYSYMBOL_K_NOXLSX_READFORMULAS = 135,    /* K_NOXLSX_READFORMULAS  */
  YYSYMBOL_K_DEFAULT_COPY_TO_CLIPBOARD_CMD = 136, /* K_DEFAULT_COPY_TO_CLIPBOARD_CMD  */
  YYSYMBOL_K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD = 137, /* K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD  */
  YYSYMBOL_K_COPY_TO_CLIPBOARD_DELIMITED_TAB = 138, /* K_COPY_TO_CLIPBOARD_DELIMITED_TAB  */
  YYSYMBOL_K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB = 139, /* K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB  */
  YYSYMBOL_K_IGNORECASE = 140,             /* K_IGNORECASE  */
  YYSYMBOL_K_NOIGNORECASE = 141,           /* K_NOIGNORECASE  */
  YYSYMBOL_K_TM_GMTOFF = 142,              /* K_TM_GMTOFF  */
  YYSYMBOL_K_COMMAND_TIMEOUT = 143,        /* K_COMMAND_TIMEOUT  */
  YYSYMBOL_K_MAPPING_TIMEOUT = 144,        /* K_MAPPING_TIMEOUT  */
  YYSYMBOL_K_NEWLINE_ACTION = 145,         /* K_NEWLINE_ACTION  */
  YYSYMBOL_K_SHOW_CURSOR = 146,            /* K_SHOW_CURSOR  */
  YYSYMBOL_K_NOSHOW_CURSOR = 147,          /* K_NOSHOW_CURSOR  */
  YYSYMBOL_K_ERROR = 148,                  /* K_ERROR  */
  YYSYMBOL_K_INVALID = 149,                /* K_INVALID  */
  YYSYMBOL_K_FIXED = 150,                  /* K_FIXED  */
  YYSYMBOL_K_SUM = 151,                    /* K_SUM  */
  YYSYMBOL_K_PROD = 152,                   /* K_PROD  */
  YYSYMBOL_K_AVG = 153,                    /* K_AVG  */
  YYSYMBOL_K_STDDEV = 154,                 /* K_STDDEV  */
  YYSYMBOL_K_COUNT = 155,                  /* K_COUNT  */
  YYSYMBOL_K_ROWS = 156,                   /* K_ROWS  */
  YYSYMBOL_K_COLS = 157,                   /* K_COLS  */
  YYSYMBOL_K_ABS = 158,                    /* K_ABS  */
  YYSYMBOL_K_FROW = 159,                   /* K_FROW  */
  YYSYMBOL_K_FCOL = 160,                   /* K_FCOL  */
  YYSYMBOL_K_ACOS = 161,                   /* K_ACOS  */
  YYSYMBOL_K_ASIN = 162,                   /* K_ASIN  */
  YYSYMBOL_K_ATAN = 163,                   /* K_ATAN  */
  YYSYMBOL_K_ATAN2 = 164,                  /* K_ATAN2  */
  YYSYMBOL_K_CEIL = 165,                   /* K_CEIL  */
  YYSYMBOL_K_COS = 166,                    /* K_COS  */
  YYSYMBOL_K_EXP = 167,                    /* K_EXP  */
  YYSYMBOL_K_FABS = 168,                   /* K_FABS  */
  YYSYMBOL_K_FLOOR = 169,                  /* K_FLOOR  */
  YYSYMBOL_K_HYPOT = 170,                  /* K_HYPOT  */
  YYSYMBOL_K_LN = 171,                     /* K_LN  */
  YYSYMBOL_K_LOG = 172,                    /* K_LOG  */
  YYSYMBOL_K_PI = 173,                     /* K_PI  */
  YYSYMBOL_K_POW = 174,                    /* K_POW  */
  YYSYMBOL_K_SIN = 175,                    /* K_SIN  */
  YYSYMBOL_K_SQRT = 176,                   /* K_SQRT  */
  YYSYMBOL_K_TAN = 177,                    /* K_TAN  */
  YYSYMBOL_K_DTR = 178,                    /* K_DTR  */
  YYSYMBOL_K_RTD = 179,                    /* K_RTD  */
  YYSYMBOL_K_MAX = 180,                    /* K_MAX  */
  YYSYMBOL_K_MIN = 181,                    /* K_MIN  */
  YYSYMBOL_K_RND = 182,                    /* K_RND  */
  YYSYMBOL_K_ROUND = 183,                  /* K_ROUND  */
  YYSYMBOL_K_IF = 184,                     /* K_IF  */
  YYSYMBOL_K_PV = 185,                     /* K_PV  */
  YYSYMBOL_K_FV = 186,                     /* K_FV  */
  YYSYMBOL_K_PMT = 187,                    /* K_PMT  */
  YYSYMBOL_K_HOUR = 188,                   /* K_HOUR  */
  YYSYMBOL_K_MINUTE = 189,                 /* K_MINUTE  */
  YYSYMBOL_K_SECOND = 190,                 /* K_SECOND  */
  YYSYMBOL_K_MONTH = 191,                  /* K_MONTH  */
  YYSYMBOL_K_DAY = 192,                    /* K_DAY  */
  YYSYMBOL_K_YEAR = 193,                   /* K_YEAR  */
  YYSYMBOL_K_NOW = 194,                    /* K_NOW  */
  YYSYMBOL_K_DATE = 195,                   /* K_DATE  */
  YYSYMBOL_K_DTS = 196,                    /* K_DTS  */
  YYSYMBOL_K_TTS = 197,                    /* K_TTS  */
  YYSYMBOL_K_FMT = 198,                    /* K_FMT  */
  YYSYMBOL_K_REPLACE = 199,                /* K_REPLACE  */
  YYSYMBOL_K_SUBSTR = 200,                 /* K_SUBSTR  */
  YYSYMBOL_K_UPPER = 201,                  /* K_UPPER  */
  YYSYMBOL_K_LOWER = 202,                  /* K_LOWER  */
  YYSYMBOL_K_CAPITAL = 203,                /* K_CAPITAL  */
  YYSYMBOL_K_STON = 204,                   /* K_STON  */
  YYSYMBOL_K_SLEN = 205,                   /* K_SLEN  */
  YYSYMBOL_K_EQS = 206,                    /* K_EQS  */
  YYSYMBOL_K_EXT = 207,                    /* K_EXT  */
  YYSYMBOL_K_EVALUATE = 208,               /* K_EVALUATE  */
  YYSYMBOL_K_SEVALUATE = 209,              /* K_SEVALUATE  */
  YYSYMBOL_K_LUA = 210,                    /* K_LUA  */
  YYSYMBOL_K_NVAL = 211,                   /* K_NVAL  */
  YYSYMBOL_K_SVAL = 212,                   /* K_SVAL  */
  YYSYMBOL_K_LOOKUP = 213,                 /* K_LOOKUP  */
  YYSYMBOL_K_HLOOKUP = 214,                /* K_HLOOKUP  */
  YYSYMBOL_K_VLOOKUP = 215,                /* K_VLOOKUP  */
  YYSYMBOL_K_INDEX = 216,                  /* K_INDEX  */
  YYSYMBOL_K_STINDEX = 217,                /* K_STINDEX  */
  YYSYMBOL_K_GETENT = 218,                 /* K_GETENT  */
  YYSYMBOL_K_TBLSTYLE = 219,               /* K_TBLSTYLE  */
  YYSYMBOL_K_TBL = 220,                    /* K_TBL  */
  YYSYMBOL_K_LATEX = 221,                  /* K_LATEX  */
  YYSYMBOL_K_SLATEX = 222,                 /* K_SLATEX  */
  YYSYMBOL_K_TEX = 223,                    /* K_TEX  */
  YYSYMBOL_K_FRAME = 224,                  /* K_FRAME  */
  YYSYMBOL_K_RNDTOEVEN = 225,              /* K_RNDTOEVEN  */
  YYSYMBOL_K_FILENAME = 226,               /* K_FILENAME  */
  YYSYMBOL_K_MYROW = 227,                  /* K_MYROW  */
  YYSYMBOL_K_MYCOL = 228,                  /* K_MYCOL  */
  YYSYMBOL_K_LASTROW = 229,                /* K_LASTROW  */
  YYSYMBOL_K_LASTCOL = 230,                /* K_LASTCOL  */
  YYSYMBOL_K_COLTOA = 231,                 /* K_COLTOA  */
  YYSYMBOL_K_CRACTION = 232,               /* K_CRACTION  */
  YYSYMBOL_K_CRROW = 233,                  /* K_CRROW  */
  YYSYMBOL_K_CRCOL = 234,                  /* K_CRCOL  */
  YYSYMBOL_K_ROWLIMIT = 235,               /* K_ROWLIMIT  */
  YYSYMBOL_K_COLLIMIT = 236,               /* K_COLLIMIT  */
  YYSYMBOL_K_PAGESIZE = 237,               /* K_PAGESIZE  */
  YYSYMBOL_K_ERR = 238,                    /* K_ERR  */
  YYSYMBOL_K_REF = 239,                    /* K_REF  */
  YYSYMBOL_K_LOCALE = 240,                 /* K_LOCALE  */
  YYSYMBOL_K_SET8BIT = 241,                /* K_SET8BIT  */
  YYSYMBOL_K_ASCII = 242,                  /* K_ASCII  */
  YYSYMBOL_K_CHR = 243,                    /* K_CHR  */
  YYSYMBOL_K_FACT = 244,                   /* K_FACT  */
  YYSYMBOL_245_ = 245,                     /* ';'  */
  YYSYMBOL_246_ = 246,                     /* '?'  */
  YYSYMBOL_247_ = 247,                     /* ':'  */
  YYSYMBOL_248_ = 248,                     /* '|'  */
  YYSYMBOL_249_ = 249,                     /* '&'  */
  YYSYMBOL_250_ = 250,                     /* '<'  */
  YYSYMBOL_251_ = 251,                     /* '='  */
  YYSYMBOL_252_ = 252,                     /* '>'  */
  YYSYMBOL_253_ = 253,                     /* '!'  */
  YYSYMBOL_254_ = 254,                     /* '+'  */
  YYSYMBOL_255_ = 255,                     /* '-'  */
  YYSYMBOL_256_ = 256,                     /* '#'  */
  YYSYMBOL_257_ = 257,                     /* '*'  */
  YYSYMBOL_258_ = 258,                     /* '/'  */
  YYSYMBOL_259_ = 259,                     /* '%'  */
  YYSYMBOL_260_ = 260,                     /* '^'  */
  YYSYMBOL_261_ = 261,                     /* '{'  */
  YYSYMBOL_262_ = 262,                     /* '}'  */
  YYSYMBOL_263_ = 263,                     /* '@'  */
  YYSYMBOL_264_ = 264,                     /* '('  */
  YYSYMBOL_265_ = 265,                     /* ')'  */
  YYSYMBOL_266_ = 266,                     /* ','  */
  YYSYMBOL_267_ = 267,                     /* '.'  */
  YYSYMBOL_268_ = 268,                     /* '~'  */
  YYSYMBOL_269_ = 269,                     /* '$'  */
  YYSYMBOL_YYACCEPT = 270,                 /* $accept  */
  YYSYMBOL_command = 271,                  /* command  */
  YYSYMBOL_term = 272,                     /* term  */
  YYSYMBOL_e = 273,                        /* e  */
  YYSYMBOL_expr_list = 274,                /* expr_list  */
  YYSYMBOL_range = 275,                    /* range  */
  YYSYMBOL_var = 276,                      /* var  */
  YYSYMBOL_var_or_range = 277,             /* var_or_range  */
  YYSYMBOL_num = 278,                      /* num  */
  YYSYMBOL_strarg = 279,                   /* strarg  */
  YYSYMBOL_setlist = 280,                  /* setlist  */
  YYSYMBOL_setitem = 281                   /* setitem  */
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
typedef yytype_int16 yy_state_t;

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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  211
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  270
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  350
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  913

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   499


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   253,     2,   256,   269,   259,   249,     2,
     264,   265,   257,   254,   266,   255,   267,   258,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   247,   245,
     250,   251,   252,   246,   263,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   260,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   261,   248,   262,   268,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   418,   418,   424,   465,   471,   476,   481,   485,   490,
     494,   501,   507,   513,   514,   515,   516,   519,   524,   531,
     533,   535,   537,   539,   541,   543,   557,   572,   577,   590,
     596,   604,   613,   623,   629,   631,   635,   639,   643,   647,
     651,   655,   659,   664,   668,   673,   687,   688,   690,   692,
     696,   700,   701,   706,   712,   714,   719,   724,   728,   733,
     738,   744,   749,   754,   759,   766,   767,   768,   769,   774,
     779,   817,   839,   856,   870,   885,   891,   900,   906,   911,
     916,   921,   927,   932,   937,   943,   948,   952,   957,   961,
     968,   988,   999,  1004,  1008,  1018,  1026,  1034,  1038,  1042,
    1043,  1044,  1046,  1054,  1070,  1071,  1073,  1075,  1081,  1105,
    1112,  1116,  1121,  1122,  1124,  1133,  1143,  1148,  1154,  1162,
    1164,  1167,  1169,  1178,  1187,  1193,  1197,  1198,  1208,  1219,
    1238,  1240,  1243,  1245,  1247,  1249,  1251,  1253,  1255,  1257,
    1259,  1261,  1263,  1265,  1267,  1269,  1271,  1273,  1275,  1277,
    1279,  1280,  1281,  1282,  1283,  1284,  1285,  1287,  1288,  1289,
    1290,  1291,  1292,  1294,  1295,  1296,  1298,  1299,  1300,  1301,
    1302,  1303,  1304,  1306,  1308,  1310,  1312,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1323,  1327,  1329,  1330,  1331,
    1333,  1334,  1336,  1338,  1339,  1340,  1341,  1343,  1345,  1347,
    1349,  1351,  1353,  1355,  1357,  1359,  1361,  1363,  1365,  1367,
    1373,  1374,  1375,  1376,  1377,  1379,  1381,  1384,  1385,  1386,
    1388,  1389,  1391,  1392,  1393,  1394,  1395,  1396,  1397,  1399,
    1400,  1401,  1402,  1403,  1404,  1405,  1406,  1407,  1411,  1412,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1426,  1428,  1429,  1430,  1433,  1434,  1437,
    1441,  1446,  1451,  1456,  1461,  1468,  1477,  1483,  1484,  1487,
    1488,  1489,  1490,  1493,  1494,  1506,  1507,  1512,  1514,  1515,
    1518,  1522,  1524,  1527,  1529,  1531,  1532,  1534,  1536,  1537,
    1539,  1543,  1544,  1545,  1547,  1548,  1549,  1551,  1552,  1553,
    1555,  1556,  1557,  1560,  1561,  1562,  1565,  1566,  1567,  1570,
    1571,  1574,  1575,  1576,  1577,  1580,  1581,  1582,  1585,  1586,
    1587,  1589,  1590,  1591,  1593,  1594,  1595,  1597,  1598,  1599,
    1602,  1603,  1604,  1607,  1608,  1609,  1615,  1622,  1630,  1632,
    1635,  1637,  1639,  1640,  1646,  1647,  1653,  1654,  1660,  1662,
    1663
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
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "COL",
  "NUMBER", "FNUMBER", "RANGE", "VAR", "WORD", "MAPWORD", "PLUGIN",
  "S_SHOW", "S_HIDE", "S_SHOWROW", "S_HIDEROW", "S_SHOWCOL", "S_HIDECOL",
  "S_FREEZE", "S_UNFREEZE", "S_MARK", "S_AUTOFIT", "S_PAD", "S_DELETECOL",
  "S_DATEFMT", "S_SUBTOTAL", "S_RSUBTOTAL", "S_FORMAT", "S_FMT", "S_LET",
  "S_LABEL", "S_LEFTSTRING", "S_RIGHTSTRING", "S_LEFTJUSTIFY",
  "S_RIGHTJUSTIFY", "S_CENTER", "S_SORT", "S_FILTERON", "S_GOTO",
  "S_GOTOB", "S_CCOPY", "S_CPASTE", "S_PLOT", "S_LOCK", "S_UNLOCK",
  "S_DEFINE", "S_UNDEFINE", "S_DETAIL", "S_EVAL", "S_SEVAL", "S_ERROR",
  "S_FILL", "S_STRTONUM", "S_DELETEROW", "S_VALUEIZEALL", "S_SHIFT",
  "S_GETNUM", "S_YANKAREA", "S_PASTEYANKED", "S_GETSTRING", "S_GETEXP",
  "S_GETFMT", "S_GETFORMAT", "S_RECALC", "S_EXECUTE", "S_QUIT", "S_EXPORT",
  "S_REBUILD_GRAPH", "S_PRINT_GRAPH", "S_SYNCREFS", "S_REDO", "S_UNDO",
  "S_IMAP", "S_CMAP", "S_NEWSHEET", "S_NEXTSHEET", "S_PREVSHEET",
  "S_DELSHEET", "S_MOVETOSHEET", "S_RENAMESHEET", "S_NMAP", "S_VMAP",
  "S_INOREMAP", "S_CNOREMAP", "S_NNOREMAP", "S_VNOREMAP", "S_NUNMAP",
  "S_IUNMAP", "S_CUNMAP", "S_VUNMAP", "S_COLOR", "S_CELLCOLOR",
  "S_UNFORMAT", "S_REDEFINE_COLOR", "S_DEFINE_COLOR", "S_SET", "S_FCOPY",
  "S_FSUM", "S_TRIGGER", "S_UNTRIGGER", "K_AUTOBACKUP", "K_NOAUTOBACKUP",
  "K_AUTOCALC", "K_NOAUTOCALC", "K_DEBUG", "K_NODEBUG", "K_TRG", "K_NOTRG",
  "K_EXTERNAL_FUNCTIONS", "K_NOEXTERNAL_FUNCTIONS", "K_EXEC_LUA",
  "K_NOEXEC_LUA", "K_HALF_PAGE_SCROLL", "K_NOHALF_PAGE_SCROLL",
  "K_NOCURSES", "K_CURSES", "K_NUMERIC", "K_NONUMERIC",
  "K_NUMERIC_DECIMAL", "K_NONUMERIC_DECIMAL", "K_NUMERIC_ZERO",
  "K_NONUMERIC_ZERO", "K_OVERLAP", "K_NOOVERLAP", "K_INPUT_BAR_BOTTOM",
  "K_UNDERLINE_GRID", "K_TRUNCATE", "K_NOTRUNCATE", "K_AUTOWRAP",
  "K_NOAUTOWRAP", "K_QUIET", "K_NOQUIET", "K_QUIT_AFTERLOAD",
  "K_NOQUIT_AFTERLOAD", "K_XLSX_READFORMULAS", "K_NOXLSX_READFORMULAS",
  "K_DEFAULT_COPY_TO_CLIPBOARD_CMD", "K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD",
  "K_COPY_TO_CLIPBOARD_DELIMITED_TAB",
  "K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB", "K_IGNORECASE", "K_NOIGNORECASE",
  "K_TM_GMTOFF", "K_COMMAND_TIMEOUT", "K_MAPPING_TIMEOUT",
  "K_NEWLINE_ACTION", "K_SHOW_CURSOR", "K_NOSHOW_CURSOR", "K_ERROR",
  "K_INVALID", "K_FIXED", "K_SUM", "K_PROD", "K_AVG", "K_STDDEV",
  "K_COUNT", "K_ROWS", "K_COLS", "K_ABS", "K_FROW", "K_FCOL", "K_ACOS",
  "K_ASIN", "K_ATAN", "K_ATAN2", "K_CEIL", "K_COS", "K_EXP", "K_FABS",
  "K_FLOOR", "K_HYPOT", "K_LN", "K_LOG", "K_PI", "K_POW", "K_SIN",
  "K_SQRT", "K_TAN", "K_DTR", "K_RTD", "K_MAX", "K_MIN", "K_RND",
  "K_ROUND", "K_IF", "K_PV", "K_FV", "K_PMT", "K_HOUR", "K_MINUTE",
  "K_SECOND", "K_MONTH", "K_DAY", "K_YEAR", "K_NOW", "K_DATE", "K_DTS",
  "K_TTS", "K_FMT", "K_REPLACE", "K_SUBSTR", "K_UPPER", "K_LOWER",
  "K_CAPITAL", "K_STON", "K_SLEN", "K_EQS", "K_EXT", "K_EVALUATE",
  "K_SEVALUATE", "K_LUA", "K_NVAL", "K_SVAL", "K_LOOKUP", "K_HLOOKUP",
  "K_VLOOKUP", "K_INDEX", "K_STINDEX", "K_GETENT", "K_TBLSTYLE", "K_TBL",
  "K_LATEX", "K_SLATEX", "K_TEX", "K_FRAME", "K_RNDTOEVEN", "K_FILENAME",
  "K_MYROW", "K_MYCOL", "K_LASTROW", "K_LASTCOL", "K_COLTOA", "K_CRACTION",
  "K_CRROW", "K_CRCOL", "K_ROWLIMIT", "K_COLLIMIT", "K_PAGESIZE", "K_ERR",
  "K_REF", "K_LOCALE", "K_SET8BIT", "K_ASCII", "K_CHR", "K_FACT", "';'",
  "'?'", "':'", "'|'", "'&'", "'<'", "'='", "'>'", "'!'", "'+'", "'-'",
  "'#'", "'*'", "'/'", "'%'", "'^'", "'{'", "'}'", "'@'", "'('", "')'",
  "','", "'.'", "'~'", "'$'", "$accept", "command", "term", "e",
  "expr_list", "range", "var", "var_or_range", "num", "strarg", "setlist",
  "setitem", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,    59,    63,    58,   124,    38,
      60,    61,    62,    33,    43,    45,    35,    42,    47,    37,
      94,   123,   125,    64,    40,    41,    44,    46,   126,    36
};
#endif

#define YYPACT_NINF (-228)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-269)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     895,  -228,    54,    56,     0,    14,    21,    23,    58,    70,
      40,    60,    66,    77,    25,   116,   116,    98,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,    62,    90,
     116,  -228,   118,   116,   116,    -1,   116,   100,   396,   396,
     123,   229,   116,   131,  -228,   116,   147,  -123,  -122,   116,
     116,   116,   136,  -228,   139,  -228,   141,  -228,  -228,  -228,
    -228,  -228,   146,   161,   162,  -228,  -228,   165,   167,   170,
     172,   173,   174,   175,   177,   178,   179,   182,   183,   187,
     188,    27,   116,   189,   190,  -228,    -1,  -228,   116,   116,
     194,  -228,  -228,  -228,  -228,  -106,   -52,   -51,   -50,   -44,
     -43,   -42,   -41,    69,   -40,   238,  -228,  -228,     8,  -228,
    -228,   -10,   206,  -228,   -36,   209,   211,   -36,   212,   208,
     213,   214,   -30,   -29,   -28,   -27,  -228,  -228,  -228,   222,
    -228,  -228,  -228,  -228,    11,    11,   225,   226,   116,  -228,
    -228,   227,   228,  -228,  -228,   116,  -228,  -228,  -228,  -228,
     116,  -228,  -228,  -228,   -35,  -228,  -228,  -228,   637,   637,
     396,   235,   845,   517,   637,  -228,  3027,  -228,  3027,  -228,
      11,    11,  -228,  -228,   236,   237,  -228,   241,   244,  -228,
    -228,  -228,  -228,  -228,   245,   246,   247,  -228,  -228,  -228,
    -228,   249,   251,   252,   255,   256,   257,  -228,  -228,  -228,
    -228,  -228,  -228,   258,  -228,   259,   262,  1085,  -228,   260,
    -228,  -228,   269,   275,   285,   287,   288,   290,   293,   294,
     116,   116,   296,     6,  -228,  -228,   310,    34,     9,   100,
    -228,   316,   317,   318,  -228,  -228,   396,   396,   396,   396,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
     -36,   319,  -228,  -228,  -205,    65,   637,    71,    72,    73,
      75,    76,    78,    79,    83,    84,    86,    87,    88,    89,
      91,    92,    93,    96,    97,   102,   107,   114,   117,  -228,
     122,   124,   125,   127,   130,   142,   143,   145,   148,   149,
     150,   151,   221,   230,   231,   232,   233,   239,   240,   242,
    -228,   263,   264,   265,   266,   267,   272,   274,   278,   279,
     283,   284,   295,   304,   305,   307,   315,   320,   321,   333,
     341,   342,   352,   353,   354,  -228,  -228,  -228,  -228,   355,
    -228,  -228,   356,   357,   361,   362,   940,  1694,  -228,   396,
     396,   396,   396,    18,   396,   129,   396,   396,   396,   396,
     396,   396,   396,    11,  -228,  -228,    67,   103,   133,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,   323,
     328,   111,  -228,   113,  -228,   152,  -228,   154,  -228,   160,
    -228,   248,  -228,   254,  -228,   273,  -228,   329,  -228,   330,
    -228,   331,  -228,   332,  -228,   378,   385,   388,  -228,   395,
    -228,   397,  -228,   401,  -228,   402,  -228,   403,   404,   405,
    -228,   407,  -228,   410,   411,   412,   415,   416,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,   116,
    -228,  -228,   322,  -228,   396,  -228,   336,  -228,   350,   383,
     481,  3027,  3027,  3027,  3027,    55,    81,  -228,   116,   116,
     116,   116,   116,   116,   116,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   369,   369,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   369,   369,
     369,   369,   369,   396,   396,   396,   396,   396,   396,   529,
    -228,  3027,  3011,   344,   549,   396,   396,  3038,  3038,   396,
    3038,  -205,  -205,  -205,   250,   250,   250,  -228,  -228,   286,
     394,   484,   485,   495,   497,   503,   504,   506,   521,   565,
     663,   665,   666,   668,   670,   672,   674,   676,   677,   678,
     679,   680,   681,    -1,    -1,   682,   683,    11,    11,    11,
       3,   684,  -228,  -228,  1010,  -228,  -228,  -228,  -228,   686,
     100,   426,   428,   429,   432,   434,   433,   435,   437,   438,
     440,   442,   443,  1712,  1730,  1748,  1766,  1784,  1802,  1029,
    1820,  1838,  1856,  1874,  1892,  1048,  1910,  1928,  1067,  1946,
    1964,  1982,  2000,  2018,  1086,   444,  -227,   446,  1105,   451,
     453,  2036,  1124,  1143,  1162,  1181,  1200,  2054,  2072,  2090,
    2108,  2126,  2144,  -209,  1219,  1238,  1257,  1276,  1295,  2162,
    2180,  2198,  2216,  2234,  1314,  1333,  2252,  2270,  1352,  1371,
    1390,  1409,   454,   -36,  1428,   455,  1447,   456,  1466,   457,
    1485,   464,  2288,  2306,  2324,  2342,  2360,  2378,   637,   396,
    3038,  3038,  3038,   116,   116,   691,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,   396,  -228,  -228,
     396,  -228,   396,  -228,   396,  -228,   396,  -228,   396,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,   396,  -228,
    -228,  -228,  -228,  -228,   396,  -228,  -228,   396,  -228,  -228,
    -228,  -228,  -228,   396,   396,  -228,   396,   396,  -228,  -228,
     396,   396,   396,   396,   396,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,   396,   396,   396,   396,   396,   396,  -228,  -228,
    -228,  -228,  -228,   396,   396,  -228,  -228,   396,   396,   396,
     116,   396,   116,   396,   116,   396,   116,   396,   116,   396,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,   306,  -228,   700,
    -228,  2396,  2414,  2432,  2450,  2468,  2486,  2504,  2522,  2540,
    3027,  -147,  2558,  -136,  2576,  2594,  1504,  1523,  1542,  1561,
    2612,  1580,  1599,  2630,  1618,  1637,  2648,  2666,  2684,  2702,
    2720,   466,  2738,   467,  1656,   468,  1675,   477,   608,   479,
     988,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,   396,  -228,  -228,  -228,  -228,   396,   396,   396,
     396,  -228,   396,   396,  -228,   396,   396,  -228,  -228,  -228,
    -228,  -228,  -228,  -228,   396,   396,   396,   396,  -228,  -228,
     396,  -228,  -228,   396,  3027,  2756,  2774,  2792,  2810,  2828,
    2846,  2864,  2882,  2900,  2918,  2936,  2954,  2972,  2990,  -228,
    -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,  -228,
    -228,  -228,  -228
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,   110,     0,   111,   112,   113,
     115,   114,     0,     0,     0,    73,    74,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,   275,    99,   101,     0,     0,
       0,    15,    16,    13,    14,    22,    21,    20,    19,    38,
      36,    42,    40,     0,    47,     0,    17,    12,     0,   260,
     266,     0,     0,   267,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
      54,    58,   269,   270,     0,     0,     0,     0,    56,    57,
      62,     0,     0,    61,    65,     0,    68,    69,   273,   274,
       0,   106,    90,   225,   222,   223,   234,   236,     0,     0,
       0,     0,     0,     0,     0,   245,   107,   128,   124,   125,
       0,     0,    66,    18,     0,     0,   117,     0,     0,   119,
     120,   121,    51,   108,     0,     0,     0,    70,    71,    75,
      76,     0,     0,     0,     0,     0,     0,    85,    86,    88,
      87,    89,    94,     0,    95,     0,     0,   103,   100,     0,
      93,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,    49,    50,   261,     0,     0,     0,     0,
      11,     0,     0,     0,    53,    10,     3,     0,     0,     0,
      43,   272,   271,    59,    60,    55,    63,    64,   102,   104,
     105,     0,   227,   221,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   210,   211,   212,   213,     0,
     233,   235,     0,     0,     0,     0,     0,     0,   226,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    28,     0,     0,     0,   109,
      78,    80,    77,    79,    82,    84,    81,    83,    91,     0,
       0,     0,   291,   292,   294,   295,   297,   298,   300,   301,
     303,   304,   306,   307,   309,   319,   321,   322,   324,   328,
     330,   331,   333,   278,   283,   280,   282,   285,   286,   288,
     289,   311,   312,   313,   315,   316,   318,     0,     0,   338,
     340,   325,   327,   346,   342,   344,   334,   349,   350,   276,
      92,    24,    26,    23,    25,    37,    35,    41,    39,    31,
      30,    46,     0,   263,     0,   262,     0,   259,     0,     0,
       0,     2,     4,     5,     6,     0,     0,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   247,     0,   252,   251,     0,     0,   248,   249,     0,
     250,   238,   239,   256,   240,   241,   242,   244,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    48,     0,   264,    44,    45,    52,     0,
       0,   267,     0,   267,     0,   267,     0,   267,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   267,   128,     0,     0,   267,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,   255,     0,     0,     0,    97,    98,   290,   293,
     296,   299,   302,   305,   308,   320,   323,   329,   332,   277,
     279,   281,   284,   287,   310,   314,   317,   336,   337,   339,
     326,   347,   343,   345,   341,   335,   348,     0,   185,   129,
       0,   132,     0,   134,     0,   136,     0,   138,     0,   140,
     148,   149,   150,   151,   152,   153,   154,   155,     0,   157,
     158,   159,   160,   161,     0,   163,   164,     0,   166,   167,
     168,   169,   170,     0,     0,   142,     0,     0,   145,   171,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   190,     0,     0,     0,     0,     0,     0,   193,   194,
     195,   187,   188,     0,     0,   217,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     228,   229,   231,   230,   232,   237,   131,   246,   118,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   265,   133,   135,   137,   139,   141,   156,   162,
     165,   144,     0,   143,   147,   146,   172,     0,     0,     0,
       0,   191,     0,     0,   192,     0,     0,   189,   208,   209,
     214,   215,   200,   199,     0,     0,     0,     0,   197,   196,
       0,   206,   205,     0,   258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,   184,   186,   216,   219,   202,   201,   204,
     203,   198,   207
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -228,  -228,  -149,   -38,   -14,   101,    64,   138,   -23,   -82,
    -228,  -228
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    90,   165,   810,   811,   113,   167,   115,   139,   150,
     207,   419
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     166,   168,   148,   108,   208,    95,   143,   110,   704,   252,
     253,   225,   705,   225,   435,   338,   132,   133,   171,    96,
     229,   153,   108,   154,   155,    97,   110,    98,   107,   108,
     202,   108,   109,   110,   109,   110,   339,   340,  -268,   341,
     342,   343,   344,   345,   103,   346,   347,   348,   349,   350,
     351,   352,   349,   350,   351,   352,   761,   762,    91,    92,
      93,    94,    99,   100,   104,   131,   108,   132,   133,   109,
     110,   105,   220,   108,   101,   102,   109,   110,   114,   117,
     117,   106,   114,   114,   114,   114,   114,   114,   114,   114,
     117,   117,   114,   140,   117,   132,   133,   114,   114,   149,
     114,   152,   119,   120,   108,   114,   117,   447,   110,   114,
     114,   241,   242,   114,   114,   114,   116,   118,   851,   852,
     108,   145,   254,   109,   110,   337,   169,   129,   130,   854,
     852,   144,   153,   108,   154,   155,   173,   110,   177,   178,
     182,   212,   183,   172,   184,   114,   114,   353,   354,   185,
     149,   108,   114,   114,   109,   110,   121,   122,   123,   124,
     125,   126,   127,   128,   186,   187,   138,   114,   188,   114,
     189,   146,   147,   190,   151,   191,   192,   193,   194,   170,
     195,   196,   197,   174,   176,   198,   199,   179,   180,   181,
     200,   201,   205,   206,   211,   213,   214,   215,   441,   442,
     443,   444,   114,   216,   217,   218,   219,   222,   227,   114,
     228,   229,   230,   233,   250,   231,   232,   235,   234,   203,
     204,   236,   237,   238,   239,   240,   209,   210,   243,   244,
     246,   247,   251,   108,   132,   133,   109,   110,   255,   355,
     356,   221,   223,   224,   357,   109,   110,   358,   359,   360,
     361,   249,   362,   432,   363,   364,   156,   157,   365,   366,
     367,   368,   111,   420,   369,   134,   135,   370,   112,   525,
     526,   158,   159,   160,   421,   226,   245,   226,   436,   161,
     422,   162,   163,   248,   114,   114,   164,   112,   111,   423,
     111,   424,   425,   437,   112,   426,   112,   427,   434,   428,
     431,   521,   522,   523,   524,   527,   528,   530,   531,   532,
     533,   534,   535,   536,   537,   433,   134,   135,   136,   438,
     439,   137,   579,   440,   445,   111,   573,   446,   542,   539,
     538,   112,   111,   543,   580,   448,   449,   450,   112,   451,
     452,   575,   453,   454,   134,   135,   141,   455,   456,   142,
     457,   458,   459,   460,   576,   461,   462,   463,   429,   430,
     464,   465,   544,   111,   545,   540,   466,   156,   157,   112,
     447,   467,   153,   108,   154,   155,   109,   110,   468,   111,
     529,   469,   158,   159,   160,   112,   470,   577,   471,   472,
     161,   473,   162,   163,   474,   541,   574,   164,   112,   153,
     108,   154,   155,   546,   110,   547,   475,   476,   175,   477,
     111,   548,   478,   479,   480,   481,   112,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   618,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   654,   656,   658,   660,   662,   663,   664,   665,   666,
     667,   697,   698,   134,   135,   482,   578,   670,   671,   675,
     676,   672,   111,   114,   483,   484,   485,   486,   112,   549,
     677,   111,   678,   487,   488,   550,   489,   112,   679,   680,
     352,   681,   114,   114,   114,   114,   114,   114,   114,   796,
     153,   108,   154,   155,   551,   110,   682,   490,   491,   492,
     493,   494,   153,   108,   154,   155,   495,   110,   496,   673,
     616,   616,   497,   498,   701,   702,   703,   499,   500,   581,
     583,   585,   587,   589,   341,   342,   343,   344,   345,   501,
     346,   347,   348,   349,   350,   351,   352,   572,   502,   503,
     683,   504,   653,   653,   653,   653,   653,   615,   619,   505,
     552,   553,   554,   555,   506,   507,   582,   584,   586,   588,
     590,   591,   592,   342,   343,   344,   345,   508,   346,   347,
     348,   349,   350,   351,   352,   509,   510,   156,   157,   652,
     655,   657,   659,   661,   617,   620,   511,   512,   513,   514,
     515,   516,   158,   159,   160,   517,   518,   149,   149,   556,
     161,   797,   162,   163,   156,   157,   557,   164,   112,   558,
     153,   108,   154,   155,   709,   110,   559,   674,   560,   158,
     159,   160,   561,   562,   563,   564,   565,   161,   566,   162,
     163,   567,   568,   569,   164,   112,   570,   571,   684,   801,
     685,   686,   802,   687,   803,   688,   804,   689,   805,   690,
     806,   691,   692,   693,   694,   695,   696,   699,   700,   706,
     807,   708,   710,   711,   800,   712,   808,   713,   715,   809,
     714,   716,   717,   841,   718,   719,   812,   720,   721,   814,
     744,   745,   815,   816,   817,   818,   819,   747,   748,     0,
     781,   783,   785,   787,   820,   821,   822,   823,   824,   825,
     789,   872,   813,   874,   876,   826,   827,   114,   114,   828,
     829,   830,   878,   832,   881,   834,     0,   836,     0,   838,
       0,   840,     0,     0,     0,   156,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   156,   157,     0,
     158,   159,   160,     0,     0,     0,     0,     0,   161,     0,
     336,   163,   158,   159,     0,   164,   112,     0,     0,     0,
     161,     0,   162,   163,   668,     0,     0,   164,   112,   343,
     344,   345,     0,   346,   347,   348,   349,   350,   351,   352,
       0,   798,   799,     0,   884,     0,     0,     0,     0,   885,
     886,   887,   888,     0,   889,   890,     0,   891,   892,     0,
       0,     0,     0,     0,     0,     0,   893,   894,   895,   896,
       0,     0,   897,     0,   117,   898,   117,     0,   117,     0,
     117,     0,   117,   339,   340,     0,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,     0,   879,   880,   156,   157,     0,     0,     0,
       0,   831,     0,   833,     0,   835,     0,   837,     0,   839,
     158,   159,     0,     0,     0,  -126,     1,     0,   161,     0,
     162,   163,     0,     0,     0,   164,   112,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   227,     0,     0,     0,     0,     0,     0,
       0,   324,   325,   326,   327,   328,   329,     0,     0,     0,
       0,     0,     0,   330,   331,     0,   332,   333,   334,   335,
     519,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   227,     0,
       0,     0,     0,     0,     0,     0,   324,   325,   326,   327,
     328,   329,     0,     0,     0,     0,     0,     0,   330,   331,
       0,   332,   333,   334,   335,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   339,   340,     0,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,     0,   882,   883,   339,   340,     0,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,     0,   339,   340,   707,   341,   342,   343,
     344,   345,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,   339,   340,   728,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,   339,   340,   734,   341,   342,   343,   344,   345,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,   339,   340,   737,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
     339,   340,   743,   341,   342,   343,   344,   345,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,   339,
     340,   746,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,   339,   340,
     750,   341,   342,   343,   344,   345,     0,   346,   347,   348,
     349,   350,   351,   352,     0,     0,     0,   339,   340,   751,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,     0,   339,   340,   752,   341,
     342,   343,   344,   345,     0,   346,   347,   348,   349,   350,
     351,   352,     0,     0,     0,   339,   340,   753,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,     0,   339,   340,   754,   341,   342,   343,
     344,   345,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,   339,   340,   763,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,   339,   340,   764,   341,   342,   343,   344,   345,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,   339,   340,   765,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
     339,   340,   766,   341,   342,   343,   344,   345,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,   339,
     340,   767,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,   339,   340,
     773,   341,   342,   343,   344,   345,     0,   346,   347,   348,
     349,   350,   351,   352,     0,     0,     0,   339,   340,   774,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,     0,   339,   340,   777,   341,
     342,   343,   344,   345,     0,   346,   347,   348,   349,   350,
     351,   352,     0,     0,     0,   339,   340,   778,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,     0,   339,   340,   779,   341,   342,   343,
     344,   345,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,   339,   340,   780,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,   339,   340,   782,   341,   342,   343,   344,   345,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,   339,   340,   784,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
     339,   340,   786,   341,   342,   343,   344,   345,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,   339,
     340,   788,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,     0,   339,   340,
     857,   341,   342,   343,   344,   345,     0,   346,   347,   348,
     349,   350,   351,   352,     0,     0,     0,   339,   340,   858,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,     0,   339,   340,   859,   341,
     342,   343,   344,   345,     0,   346,   347,   348,   349,   350,
     351,   352,     0,     0,     0,   339,   340,   860,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,     0,   339,   340,   862,   341,   342,   343,
     344,   345,     0,   346,   347,   348,   349,   350,   351,   352,
       0,     0,     0,   339,   340,   863,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,     0,   339,   340,   865,   341,   342,   343,   344,   345,
       0,   346,   347,   348,   349,   350,   351,   352,     0,     0,
       0,   339,   340,   866,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,     0,
     339,   340,   875,   341,   342,   343,   344,   345,     0,   346,
     347,   348,   349,   350,   351,   352,     0,     0,     0,   339,
     340,   877,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   520,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   722,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   723,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   724,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   725,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   726,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   727,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   729,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   730,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   731,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   732,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   733,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   735,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   736,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   738,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   739,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   740,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   741,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   742,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   749,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   755,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   756,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   757,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   758,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   759,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   760,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   768,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   769,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   770,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   771,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   772,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   775,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   776,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   790,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   791,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   792,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   793,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   794,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   795,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   842,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   843,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   844,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   845,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   846,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   847,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   848,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   849,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   850,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   853,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   855,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   856,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   861,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   864,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   867,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   868,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   869,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   870,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   871,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   873,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   899,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   900,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   901,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   902,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   903,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   904,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   905,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   906,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,   339,   340,   907,   341,   342,   343,   344,
     345,     0,   346,   347,   348,   349,   350,   351,   352,     0,
       0,   339,   340,   908,   341,   342,   343,   344,   345,     0,
     346,   347,   348,   349,   350,   351,   352,     0,     0,   339,
     340,   909,   341,   342,   343,   344,   345,     0,   346,   347,
     348,   349,   350,   351,   352,     0,     0,   339,   340,   910,
     341,   342,   343,   344,   345,     0,   346,   347,   348,   349,
     350,   351,   352,     0,     0,   339,   340,   911,   341,   342,
     343,   344,   345,     0,   346,   347,   348,   349,   350,   351,
     352,     0,     0,     0,     0,   912,   339,   340,   669,   341,
     342,   343,   344,   345,     0,   346,   347,   348,   349,   350,
     351,   352,   339,   340,     0,   341,   342,   343,   344,   345,
       0,   346,   347,   348,   349,   350,   351,   352,  -269,  -269,
    -269,     0,   346,   347,   348,   349,   350,   351,   352
};

static const yytype_int16 yycheck[] =
{
      38,    39,     3,     4,    86,     5,    29,     8,     5,   158,
     159,     5,     9,     5,     5,   164,     5,     6,    41,     5,
     247,     3,     4,     5,     6,     4,     8,     4,     3,     4,
       3,     4,     7,     8,     7,     8,   245,   246,   265,   248,
     249,   250,   251,   252,     4,   254,   255,   256,   257,   258,
     259,   260,   257,   258,   259,   260,   265,   266,     4,     5,
       4,     5,     4,     5,     4,     3,     4,     5,     6,     7,
       8,     5,     3,     4,     4,     5,     7,     8,    14,    15,
      16,     4,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     3,    30,     5,     6,    33,    34,    35,
      36,    37,     4,     5,     4,    41,    42,   256,     8,    45,
      46,   134,   135,    49,    50,    51,    15,    16,   265,   266,
       4,     3,   160,     7,     8,   163,     3,    26,    27,   265,
     266,    30,     3,     4,     5,     6,     5,     8,   261,   261,
       4,   247,     3,    42,     3,    81,    82,   170,   171,     3,
      86,     4,    88,    89,     7,     8,    18,    19,    20,    21,
      22,    23,    24,    25,     3,     3,    28,   103,     3,   105,
       3,    33,    34,     3,    36,     3,     3,     3,     3,    41,
       3,     3,     3,    45,    46,     3,     3,    49,    50,    51,
       3,     3,     3,     3,     0,   247,   247,   247,   236,   237,
     238,   239,   138,   247,   247,   247,   247,   247,   218,   145,
       4,   247,     3,     5,   150,     4,     4,     3,     5,    81,
      82,   251,   251,   251,   251,     3,    88,    89,     3,     3,
       3,     3,   267,     4,     5,     6,     7,     8,     3,     3,
       3,   103,     4,   105,     3,     7,     8,     3,     3,     3,
       3,   150,     3,   247,     3,     3,   238,   239,     3,     3,
       3,     3,   263,     3,     5,   254,   255,     5,   269,   251,
     252,   253,   254,   255,     5,   269,   138,   269,   269,   261,
       5,   263,   264,   145,   220,   221,   268,   269,   263,     4,
     263,     4,     4,   229,   269,     5,   269,     4,   264,     5,
       4,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,     5,   254,   255,   256,     3,
       3,   259,   267,     5,     5,   263,     4,   262,     5,   262,
     353,   269,   263,     5,   253,   264,   264,   264,   269,   264,
     264,     5,   264,   264,   254,   255,   256,   264,   264,   259,
     264,   264,   264,   264,     4,   264,   264,   264,   220,   221,
     264,   264,   251,   263,   251,   262,   264,   238,   239,   269,
     519,   264,     3,     4,     5,     6,     7,     8,   264,   263,
     251,   264,   253,   254,   255,   269,   264,     4,   264,   264,
     261,   264,   263,   264,   264,   262,   434,   268,   269,     3,
       4,     5,     6,   251,     8,   251,   264,   264,   261,   264,
     263,   251,   264,   264,   264,   264,   269,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   563,   564,   254,   255,   264,     5,   525,   526,     5,
       5,   529,   263,   429,   264,   264,   264,   264,   269,   251,
       5,   263,     5,   264,   264,   251,   264,   269,     5,     5,
     260,     5,   448,   449,   450,   451,   452,   453,   454,   668,
       3,     4,     5,     6,   251,     8,     5,   264,   264,   264,
     264,   264,     3,     4,     5,     6,   264,     8,   264,   253,
     476,   477,   264,   264,   567,   568,   569,   264,   264,   448,
     449,   450,   451,   452,   248,   249,   250,   251,   252,   264,
     254,   255,   256,   257,   258,   259,   260,   429,   264,   264,
       5,   264,   508,   509,   510,   511,   512,   476,   477,   264,
     251,   251,   251,   251,   264,   264,   448,   449,   450,   451,
     452,   453,   454,   249,   250,   251,   252,   264,   254,   255,
     256,   257,   258,   259,   260,   264,   264,   238,   239,   508,
     509,   510,   511,   512,   476,   477,   264,   264,   264,   264,
     264,   264,   253,   254,   255,   264,   264,   563,   564,   251,
     261,   669,   263,   264,   238,   239,   251,   268,   269,   251,
       3,     4,     5,     6,   580,     8,   251,   253,   251,   253,
     254,   255,   251,   251,   251,   251,   251,   261,   251,   263,
     264,   251,   251,   251,   268,   269,   251,   251,     5,   707,
       5,     5,   710,     5,   712,     5,   714,     5,   716,     5,
     718,     5,     5,     5,     5,     5,     5,     5,     5,     5,
     728,     5,   266,   265,     3,   266,   734,   265,   265,   737,
     266,   266,   265,     3,   266,   265,   744,   265,   265,   747,
     266,   265,   750,   751,   752,   753,   754,   266,   265,    -1,
     266,   266,   266,   266,   762,   763,   764,   765,   766,   767,
     266,   265,   746,   266,   266,   773,   774,   673,   674,   777,
     778,   779,   265,   781,   265,   783,    -1,   785,    -1,   787,
      -1,   789,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,
     253,   254,   255,    -1,    -1,    -1,    -1,    -1,   261,    -1,
     263,   264,   253,   254,    -1,   268,   269,    -1,    -1,    -1,
     261,    -1,   263,   264,   265,    -1,    -1,   268,   269,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
      -1,   673,   674,    -1,   852,    -1,    -1,    -1,    -1,   857,
     858,   859,   860,    -1,   862,   863,    -1,   865,   866,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   874,   875,   876,   877,
      -1,    -1,   880,    -1,   780,   883,   782,    -1,   784,    -1,
     786,    -1,   788,   245,   246,    -1,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,   266,   238,   239,    -1,    -1,    -1,
      -1,   780,    -1,   782,    -1,   784,    -1,   786,    -1,   788,
     253,   254,    -1,    -1,    -1,     0,     1,    -1,   261,    -1,
     263,   264,    -1,    -1,    -1,   268,   269,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,   228,   229,   230,   231,    -1,    -1,    -1,
      -1,    -1,    -1,   238,   239,    -1,   241,   242,   243,   244,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
      -1,   241,   242,   243,   244,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   245,   246,    -1,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,   266,   245,   246,    -1,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,   245,   246,   266,   248,   249,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,   245,   246,   266,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,   245,   246,   266,   248,   249,   250,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,   245,   246,   266,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
     245,   246,   266,   248,   249,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,   245,
     246,   266,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,   245,   246,
     266,   248,   249,   250,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,   245,   246,   266,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,   245,   246,   266,   248,
     249,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,   245,   246,   266,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,   245,   246,   266,   248,   249,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,   245,   246,   266,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,   245,   246,   266,   248,   249,   250,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,   245,   246,   266,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
     245,   246,   266,   248,   249,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,   245,
     246,   266,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,   245,   246,
     266,   248,   249,   250,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,   245,   246,   266,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,   245,   246,   266,   248,
     249,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,   245,   246,   266,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,   245,   246,   266,   248,   249,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,   245,   246,   266,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,   245,   246,   266,   248,   249,   250,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,   245,   246,   266,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
     245,   246,   266,   248,   249,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,   245,
     246,   266,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,    -1,   245,   246,
     266,   248,   249,   250,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,    -1,    -1,    -1,   245,   246,   266,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,    -1,   245,   246,   266,   248,
     249,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,    -1,    -1,    -1,   245,   246,   266,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,   245,   246,   266,   248,   249,   250,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
      -1,    -1,    -1,   245,   246,   266,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,   245,   246,   266,   248,   249,   250,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,    -1,    -1,
      -1,   245,   246,   266,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,    -1,
     245,   246,   266,   248,   249,   250,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,    -1,    -1,    -1,   245,
     246,   266,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,   245,   246,   265,   248,   249,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,   245,   246,   265,   248,   249,   250,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,    -1,    -1,   245,
     246,   265,   248,   249,   250,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,    -1,    -1,   245,   246,   265,
     248,   249,   250,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,    -1,    -1,   245,   246,   265,   248,   249,
     250,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,   245,   246,   247,   248,
     249,   250,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   245,   246,    -1,   248,   249,   250,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   250,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     271,     4,     5,     4,     5,     5,     5,     4,     4,     4,
       5,     4,     5,     4,     4,     5,     4,     3,     4,     7,
       8,   263,   269,   275,   276,   277,   275,   276,   275,     4,
       5,   277,   277,   277,   277,   277,   277,   277,   277,   275,
     275,     3,     5,     6,   254,   255,   256,   259,   277,   278,
       3,   256,   259,   278,   275,     3,   277,   277,     3,   276,
     279,   277,   276,     3,     5,     6,   238,   239,   253,   254,
     255,   261,   263,   264,   268,   272,   273,   276,   273,     3,
     277,   278,   275,     5,   277,   261,   277,   261,   261,   277,
     277,   277,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,   277,   277,     3,     3,   280,   279,   277,
     277,     0,   247,   247,   247,   247,   247,   247,   247,   247,
       3,   277,   247,     4,   277,     5,   269,   218,     4,   247,
       3,     4,     4,     5,     5,     3,   251,   251,   251,   251,
       3,   278,   278,     3,     3,   277,     3,     3,   277,   275,
     276,   267,   272,   272,   273,     3,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   226,   227,   228,   229,   230,   231,
     238,   239,   241,   242,   243,   244,   263,   273,   272,   245,
     246,   248,   249,   250,   251,   252,   254,   255,   256,   257,
     258,   259,   260,   278,   278,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       5,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   281,
       3,     5,     5,     4,     4,     4,     5,     4,     5,   277,
     277,     4,   247,     5,   264,     5,   269,   276,     3,     3,
       5,   273,   273,   273,   273,     5,   262,   272,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   150,
     265,   273,   273,   273,   273,   251,   252,   273,   273,   251,
     273,   273,   273,   273,   273,   273,   273,   273,   278,   262,
     262,   262,     5,     5,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   277,     4,   273,     5,     4,     4,     5,   267,
     253,   275,   277,   275,   277,   275,   277,   275,   277,   275,
     277,   277,   277,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   275,   276,   277,   273,   275,
     277,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   275,   276,   273,   275,   273,   275,   273,   275,
     273,   275,   273,   273,   273,   273,   273,   273,   265,   247,
     273,   273,   273,   253,   253,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,   279,   279,     5,
       5,   278,   278,   278,     5,     9,     5,   266,     5,   276,
     266,   265,   266,   265,   266,   265,   266,   265,   266,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   266,   265,
     265,   265,   265,   265,   266,   265,   265,   266,   265,   265,
     265,   265,   265,   266,   266,   265,   266,   266,   265,   265,
     266,   266,   266,   266,   266,   265,   265,   265,   265,   265,
     265,   265,   266,   266,   266,   266,   266,   266,   265,   265,
     265,   265,   265,   266,   266,   265,   265,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     265,   265,   265,   265,   265,   265,   272,   273,   277,   277,
       3,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   274,   273,   274,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   275,   273,   275,   273,   275,   273,   275,   273,   275,
     273,     3,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   266,   265,   265,   265,   265,   266,   266,   266,
     266,   265,   266,   266,   265,   266,   266,   265,   265,   265,
     265,   265,   265,   265,   266,   266,   266,   266,   265,   265,
     266,   265,   265,   266,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   270,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   274,   274,   275,
     275,   276,   276,   276,   276,   276,   276,   277,   277,   278,
     278,   278,   278,   279,   279,   280,   280,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     4,     4,     4,     2,     2,     2,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     4,     4,     4,     1,     3,     3,
       4,     4,     5,     4,     3,     4,     2,     4,     2,     4,
       2,     4,     2,     3,     5,     5,     4,     2,     5,     3,
       3,     2,     5,     3,     2,     3,     2,     2,     2,     3,
       3,     2,     2,     3,     3,     2,     2,     1,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     3,     3,     2,     2,     2,     1,     5,     5,     1,
       2,     1,     3,     2,     3,     3,     2,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     6,     2,
       2,     2,     7,     6,     2,     2,     0,     1,     1,     5,
       3,     5,     5,     7,     5,     7,     5,     7,     5,     7,
       5,     7,     5,     7,     7,     5,     7,     7,     5,     5,
       5,     5,     5,     5,     5,     5,     7,     5,     5,     5,
       5,     5,     7,     5,     5,     7,     5,     5,     5,     5,
       5,     5,     7,     9,     9,     9,     9,     5,     5,     5,
       5,     5,     5,     2,     9,     5,     9,     5,     5,     7,
       5,     7,     7,     5,     5,     5,     7,     7,     9,     7,
       7,     9,     9,     9,     9,     7,     7,     9,     7,     7,
       2,     2,     2,     2,     7,     7,     9,     5,     5,     9,
       3,     2,     1,     1,     2,     1,     2,     2,     5,     5,
       5,     5,     5,     2,     1,     2,     1,     5,     3,     3,
       3,     3,     3,     2,     3,     1,     5,     3,     3,     3,
       3,     3,     3,     4,     4,     4,     3,     1,     3,     3,
       1,     2,     3,     3,     4,     7,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     0,     2,     3,     1,     3,
       1,     3,     1,     1,     3,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     1,
       3,     1,     1,     1,     3,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     1,     1,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     3,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* command: S_LET var_or_range '=' e  */
#line 418 "gram.y"
                                  {
                                  struct roman * roman = session->cur_doc;
                                  struct sheet * sh = roman->cur_sh;
                                  let(roman, sh, (yyvsp[-2].rval).left.vp, (yyvsp[0].enode));
                                  }
#line 3063 "y.tab.c"
    break;

  case 3: /* command: S_LET var_or_range '='  */
#line 425 "gram.y"
                                  {
                                  // TODO get this code out of gram.y - reeval cells that depends on $2
                                  extern graphADT graph;
                                  struct roman * roman = session->cur_doc;
                                  struct sheet * sh = roman->cur_sh;
#ifdef UNDO
                                  // here we save in undostruct, all the ents that depends on the deleted one (before change)
                                  ents_that_depends_on_range(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col);
                                  create_undo_action();
                                  copy_to_undostruct(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, UNDO_DEL, HANDLE_DEPS, NULL);
#endif

                                  if (getVertex(graph, sh, lookat(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col), 0) != NULL) destroy_vertex(sh, lookat(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col));

                                  (yyvsp[-1].rval).left.vp->v = (double) 0.0;
                                  if ((yyvsp[-1].rval).left.vp->expr && !((yyvsp[-1].rval).left.vp->flags & is_strexpr)) {
                                      efree((yyvsp[-1].rval).left.vp->expr);
                                      (yyvsp[-1].rval).left.vp->expr = NULL;
                                  }
                                  (yyvsp[-1].rval).left.vp->cellerror = CELLOK;
                                  (yyvsp[-1].rval).left.vp->flags &= ~is_valid;
                                  (yyvsp[-1].rval).left.vp->flags |= is_changed;
                                  roman->modflg++;

                                  // clearing the value counts as a write, so run write triggers
                                  if (( (yyvsp[-1].rval).left.vp->trigger  ) && (((yyvsp[-1].rval).left.vp->trigger->flag & TRG_WRITE) == TRG_WRITE))
                                      do_trigger((yyvsp[-1].rval).left.vp, TRG_WRITE);

#ifdef UNDO
                                  // here we save in undostruct, all the ents that depends on the deleted one (after change)
                                  copy_to_undostruct(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, UNDO_ADD, HANDLE_DEPS, NULL);
                                  extern struct ent_ptr * deps;
                                  if (deps != NULL) {
                                      free(deps);
                                      deps = NULL;
                                  }
                                  end_undo_action();
#endif
                                  }
#line 3107 "y.tab.c"
    break;

  case 4: /* command: S_LABEL var_or_range '=' e  */
#line 465 "gram.y"
                                          {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            slet(roman, sh, (yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 0);
                                          }
#line 3117 "y.tab.c"
    break;

  case 5: /* command: S_LEFTSTRING var_or_range '=' e  */
#line 471 "gram.y"
                                          {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            slet(roman, sh, (yyvsp[-2].rval).left.vp, (yyvsp[0].enode), -1);
                                          }
#line 3127 "y.tab.c"
    break;

  case 6: /* command: S_RIGHTSTRING var_or_range '=' e  */
#line 476 "gram.y"
                                          {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            slet(roman, sh, (yyvsp[-2].rval).left.vp, (yyvsp[0].enode), 1);
                                          }
#line 3137 "y.tab.c"
    break;

  case 7: /* command: S_LEFTJUSTIFY var_or_range  */
#line 481 "gram.y"
                                     {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            ljustify(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3146 "y.tab.c"
    break;

  case 8: /* command: S_RIGHTJUSTIFY var_or_range  */
#line 485 "gram.y"
                                     {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            rjustify(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3155 "y.tab.c"
    break;

  case 9: /* command: S_CENTER var_or_range  */
#line 490 "gram.y"
                                     {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            center(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3164 "y.tab.c"
    break;

  case 10: /* command: S_FMT var_or_range STRING  */
#line 494 "gram.y"
                                     {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            format_cell(sh, (yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp, (yyvsp[0].sval));
                                            scxfree((yyvsp[0].sval));
                                     }
#line 3175 "y.tab.c"
    break;

  case 11: /* command: S_DATEFMT var_or_range STRING  */
#line 501 "gram.y"
                                       {
                                            struct roman * roman = session->cur_doc;
                                            struct sheet * sh = roman->cur_sh;
                                            dateformat(sh, (yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp, (yyvsp[0].sval));
                                            scxfree((yyvsp[0].sval));
                                       }
#line 3186 "y.tab.c"
    break;

  case 12: /* command: S_DATEFMT STRING  */
#line 507 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       dateformat(sh, lookat(sh, sh->currow, sh->curcol), lookat(sh, sh->currow, sh->curcol), (yyvsp[0].sval));
                                       scxfree((yyvsp[0].sval)); }
#line 3196 "y.tab.c"
    break;

  case 13: /* command: S_HIDE COL  */
#line 513 "gram.y"
                                     { hide_col((yyvsp[0].ival), 1); }
#line 3202 "y.tab.c"
    break;

  case 14: /* command: S_HIDE NUMBER  */
#line 514 "gram.y"
                                     { hide_row((yyvsp[0].ival), 1); }
#line 3208 "y.tab.c"
    break;

  case 15: /* command: S_SHOW COL  */
#line 515 "gram.y"
                                     { show_col((yyvsp[0].ival), 1); }
#line 3214 "y.tab.c"
    break;

  case 16: /* command: S_SHOW NUMBER  */
#line 516 "gram.y"
                                     { show_row((yyvsp[0].ival), 1); }
#line 3220 "y.tab.c"
    break;

  case 17: /* command: S_DELETECOL COL  */
#line 519 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       deletecol(sh, (yyvsp[0].ival), 1);
                                     }
#line 3230 "y.tab.c"
    break;

  case 18: /* command: S_DELETEROW NUMBER  */
#line 524 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       deleterow(sh, (yyvsp[0].ival), 1);
                                     }
#line 3240 "y.tab.c"
    break;

  case 19: /* command: S_HIDECOL COL  */
#line 531 "gram.y"
                                     {
                                       hide_col((yyvsp[0].ival), 1); }
#line 3247 "y.tab.c"
    break;

  case 20: /* command: S_SHOWCOL COL  */
#line 533 "gram.y"
                                     {
                                       show_col((yyvsp[0].ival), 1); }
#line 3254 "y.tab.c"
    break;

  case 21: /* command: S_HIDEROW NUMBER  */
#line 535 "gram.y"
                                     {
                                       hide_row((yyvsp[0].ival), 1); }
#line 3261 "y.tab.c"
    break;

  case 22: /* command: S_SHOWROW NUMBER  */
#line 537 "gram.y"
                                     {
                                       show_row((yyvsp[0].ival), 1); }
#line 3268 "y.tab.c"
    break;

  case 23: /* command: S_SHOWCOL COL ':' COL  */
#line 539 "gram.y"
                                     {
                                       show_col((yyvsp[-2].ival), (yyvsp[0].ival)-(yyvsp[-2].ival)+1); }
#line 3275 "y.tab.c"
    break;

  case 24: /* command: S_SHOWROW NUMBER ':' NUMBER  */
#line 541 "gram.y"
                                     {
                                       show_row((yyvsp[-2].ival), (yyvsp[0].ival)-(yyvsp[-2].ival)+1); }
#line 3282 "y.tab.c"
    break;

  case 25: /* command: S_HIDECOL COL ':' COL  */
#line 543 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       int c = sh->curcol, arg;
                                       if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
                                            sh->curcol = (yyvsp[-2].ival);
                                            arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
                                       } else {
                                            sh->curcol = (yyvsp[0].ival);
                                            arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
                                       }
                                       hide_col((yyvsp[-2].ival), arg);        // hide de un rango de columnas
                                       sh->curcol = c < sh->curcol ? c : c < sh->curcol + arg ? sh->curcol : c - arg;
                                     }
#line 3301 "y.tab.c"
    break;

  case 26: /* command: S_HIDEROW NUMBER ':' NUMBER  */
#line 557 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       int r = sh->currow, arg;      // hide de un rango de filas
                                       if ((yyvsp[-2].ival) < (yyvsp[0].ival)) {
                                           sh->currow = (yyvsp[-2].ival);
                                           arg = (yyvsp[0].ival) - (yyvsp[-2].ival) + 1;
                                       } else {
                                           sh->currow = (yyvsp[0].ival);
                                           arg = (yyvsp[-2].ival) - (yyvsp[0].ival) + 1;
                                       }
                                       hide_row((yyvsp[-2].ival), arg);
                                       sh->currow = r < sh->currow ? r : r < sh->currow + arg ? sh->currow : r - arg;
                                     }
#line 3320 "y.tab.c"
    break;

  case 27: /* command: S_VALUEIZEALL  */
#line 572 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       valueize_area(sh, 0, 0, sh->maxrow, sh->maxcol); }
#line 3329 "y.tab.c"
    break;

  case 28: /* command: S_SHIFT var_or_range STRING  */
#line 577 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       if (strlen((yyvsp[0].sval)) != 1 || ((yyvsp[0].sval)[0] != 'h' && (yyvsp[0].sval)[0] != 'j' && (yyvsp[0].sval)[0] != 'k' && (yyvsp[0].sval)[0] != 'l')) {
                                           sc_error("wrong parameter for shift command");
                                       } else {
                                           wchar_t wstr[2] = L"";
                                           swprintf(wstr, BUFFERSIZE, L"%c", (yyvsp[0].sval)[0]);
                                           shift(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, wstr[0]);
                                       }
                                       scxfree((yyvsp[0].sval));
                                     }
#line 3346 "y.tab.c"
    break;

  case 29: /* command: S_MARK COL var_or_range  */
#line 590 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       set_cell_mark((yyvsp[-1].ival) + 97, sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col);
                                     }
#line 3356 "y.tab.c"
    break;

  case 30: /* command: S_MARK COL var_or_range var_or_range  */
#line 596 "gram.y"
                                              {
                                          struct roman * roman = session->cur_doc;
                                          struct sheet * sh = roman->cur_sh;
                                          srange * sr = create_range('\0', '\0', (yyvsp[-1].rval).left.vp, (yyvsp[0].rval).left.vp);
                                          unselect_ranges();
                                          set_range_mark((yyvsp[-2].ival) + 97, sh, sr);
                                     }
#line 3368 "y.tab.c"
    break;

  case 31: /* command: S_MARK COL STRING var_or_range  */
#line 604 "gram.y"
                                            {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh;
                                       if ((sh = search_sheet(roman, (yyvsp[-1].sval))) != NULL ) {
                                           set_cell_mark((yyvsp[-2].ival) + 97, sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col);
                                       }
                                       scxfree((yyvsp[-1].sval));
                                     }
#line 3381 "y.tab.c"
    break;

  case 32: /* command: S_MARK COL STRING var_or_range var_or_range  */
#line 613 "gram.y"
                                                     {
                                          struct roman * roman = session->cur_doc;
                                          struct sheet * sh;
                                          if ((sh = search_sheet(roman, (yyvsp[-2].sval))) != NULL ) {
                                              srange * sr = create_range('\0', '\0', (yyvsp[-1].rval).left.vp, (yyvsp[0].rval).left.vp);
                                              unselect_ranges();
                                              set_range_mark((yyvsp[-3].ival) + 97, sh, sr);
                                          }
                                          scxfree((yyvsp[-2].sval));
                                     }
#line 3396 "y.tab.c"
    break;

  case 33: /* command: S_FILL var_or_range num num  */
#line 623 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       fill(sh, (yyvsp[-2].rval).left.vp, (yyvsp[-2].rval).right.vp, (yyvsp[-1].fval), (yyvsp[0].fval));
                                     }
#line 3406 "y.tab.c"
    break;

  case 34: /* command: S_FILL num num  */
#line 629 "gram.y"
                                     { sc_error("Not enough parameters for fill command"); }
#line 3412 "y.tab.c"
    break;

  case 35: /* command: S_FREEZE NUMBER ':' NUMBER  */
#line 631 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, (yyvsp[-2].ival), 0), lookat(sh, (yyvsp[0].ival), 0), 1, 'r'); }
#line 3421 "y.tab.c"
    break;

  case 36: /* command: S_FREEZE NUMBER  */
#line 635 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, (yyvsp[0].ival), 0), lookat(sh, (yyvsp[0].ival), 0), 1, 'r'); }
#line 3430 "y.tab.c"
    break;

  case 37: /* command: S_FREEZE COL ':' COL  */
#line 639 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, 0, (yyvsp[-2].ival)), lookat(sh, 0, (yyvsp[0].ival)), 1, 'c'); }
#line 3439 "y.tab.c"
    break;

  case 38: /* command: S_FREEZE COL  */
#line 643 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, 0, (yyvsp[0].ival)), lookat(sh, 0, (yyvsp[0].ival)), 1, 'c'); }
#line 3448 "y.tab.c"
    break;

  case 39: /* command: S_UNFREEZE NUMBER ':' NUMBER  */
#line 647 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, (yyvsp[-2].ival), 0), lookat(sh, (yyvsp[0].ival), 0), 0, 'r'); }
#line 3457 "y.tab.c"
    break;

  case 40: /* command: S_UNFREEZE NUMBER  */
#line 651 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, (yyvsp[0].ival), 0), lookat(sh, (yyvsp[0].ival), 0), 0, 'r'); }
#line 3466 "y.tab.c"
    break;

  case 41: /* command: S_UNFREEZE COL ':' COL  */
#line 655 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, 0, (yyvsp[-2].ival)), lookat(sh, 0, (yyvsp[0].ival)), 0, 'c'); }
#line 3475 "y.tab.c"
    break;

  case 42: /* command: S_UNFREEZE COL  */
#line 659 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       handle_freeze(sh, lookat(sh, 0, (yyvsp[0].ival)), lookat(sh, 0, (yyvsp[0].ival)), 0, 'c'); }
#line 3484 "y.tab.c"
    break;

  case 43: /* command: S_SORT range STRING  */
#line 664 "gram.y"
                                     { sortrange(session->cur_doc->cur_sh, (yyvsp[-1].rval).left.vp, (yyvsp[-1].rval).right.vp, (yyvsp[0].sval));
                                       //scxfree($3);
                                       //do not free here
                                     }
#line 3493 "y.tab.c"
    break;

  case 44: /* command: S_SUBTOTAL range COL STRING COL  */
#line 668 "gram.y"
                                         {
                                       subtotal((yyvsp[-3].rval).left.vp->row, (yyvsp[-3].rval).left.vp->col, (yyvsp[-3].rval).right.vp->row,
                                                (yyvsp[-3].rval).right.vp->col, (yyvsp[-2].ival), (yyvsp[-1].sval), (yyvsp[0].ival), 0);
                                       scxfree((yyvsp[-1].sval));
                                     }
#line 3503 "y.tab.c"
    break;

  case 45: /* command: S_RSUBTOTAL range COL STRING COL  */
#line 673 "gram.y"
                                          {
                                       subtotal((yyvsp[-3].rval).left.vp->row, (yyvsp[-3].rval).left.vp->col, (yyvsp[-3].rval).right.vp->row,
                                                 (yyvsp[-3].rval).right.vp->col, (yyvsp[-2].ival), (yyvsp[-1].sval), (yyvsp[0].ival), 1);
                                       scxfree((yyvsp[-1].sval));
                                     }
#line 3513 "y.tab.c"
    break;

  case 46: /* command: S_AUTOFIT COL ':' COL  */
#line 687 "gram.y"
                                     { auto_fit(session->cur_doc->cur_sh, (yyvsp[-2].ival), (yyvsp[0].ival), DEFWIDTH); }
#line 3519 "y.tab.c"
    break;

  case 47: /* command: S_AUTOFIT COL  */
#line 688 "gram.y"
                                     { auto_fit(session->cur_doc->cur_sh, (yyvsp[0].ival), (yyvsp[0].ival), DEFWIDTH); }
#line 3525 "y.tab.c"
    break;

  case 48: /* command: S_PAD NUMBER COL ':' COL  */
#line 690 "gram.y"
                                   {
                                       pad(session->cur_doc->cur_sh, (yyvsp[-3].ival), 0, (yyvsp[-2].ival), session->cur_doc->cur_sh->maxrow, (yyvsp[0].ival)); }
#line 3532 "y.tab.c"
    break;

  case 49: /* command: S_PAD NUMBER COL  */
#line 692 "gram.y"
                                   {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       pad(sh, (yyvsp[-1].ival), 0, (yyvsp[0].ival), sh->maxrow, (yyvsp[0].ival)); }
#line 3541 "y.tab.c"
    break;

  case 50: /* command: S_PAD NUMBER var_or_range  */
#line 696 "gram.y"
                                   {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       pad(sh, (yyvsp[-1].ival), (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3550 "y.tab.c"
    break;

  case 51: /* command: S_GETFORMAT COL  */
#line 700 "gram.y"
                                   {   getformat((yyvsp[0].ival), fdoutput); }
#line 3556 "y.tab.c"
    break;

  case 52: /* command: S_FORMAT COL NUMBER NUMBER NUMBER  */
#line 701 "gram.y"
                                           {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       doformat(sh, (yyvsp[-3].ival),(yyvsp[-3].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival));
                                       }
#line 3566 "y.tab.c"
    break;

  case 53: /* command: S_FORMAT NUMBER NUMBER  */
#line 706 "gram.y"
                                     {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       dorowformat(sh, (yyvsp[-1].ival), (yyvsp[0].ival));
                                     }
#line 3576 "y.tab.c"
    break;

  case 54: /* command: S_FILTERON range  */
#line 712 "gram.y"
                                     { enable_filters((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp);
                                     }
#line 3583 "y.tab.c"
    break;

  case 55: /* command: S_GOTO var_or_range var_or_range  */
#line 714 "gram.y"
                                          {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       moveto(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col);
                                     }
#line 3593 "y.tab.c"
    break;

  case 56: /* command: S_GOTO var_or_range  */
#line 719 "gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       moveto(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, -1, -1);
                                 }
#line 3603 "y.tab.c"
    break;

  case 57: /* command: S_GOTO num  */
#line 724 "gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       num_search(sh, (yyvsp[0].fval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 0, 1); }
#line 3612 "y.tab.c"
    break;

  case 58: /* command: S_GOTO STRING  */
#line 728 "gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 0, 1); }
#line 3621 "y.tab.c"
    break;

  case 59: /* command: S_GOTO '#' STRING  */
#line 733 "gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 1, 1); }
#line 3630 "y.tab.c"
    break;

  case 60: /* command: S_GOTO '%' STRING  */
#line 738 "gram.y"
                                 {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 2, 1); }
#line 3639 "y.tab.c"
    break;

  case 61: /* command: S_GOTOB num  */
#line 744 "gram.y"
                                  {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       num_search(sh, (yyvsp[0].fval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 0, 0); }
#line 3648 "y.tab.c"
    break;

  case 62: /* command: S_GOTOB STRING  */
#line 749 "gram.y"
                                  {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 0, 0); }
#line 3657 "y.tab.c"
    break;

  case 63: /* command: S_GOTOB '#' STRING  */
#line 754 "gram.y"
                                  {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 1, 0); }
#line 3666 "y.tab.c"
    break;

  case 64: /* command: S_GOTOB '%' STRING  */
#line 759 "gram.y"
                                  {
                                       struct roman * roman = session->cur_doc;
                                       struct sheet * sh = roman->cur_sh;
                                       str_search(sh, (yyvsp[0].sval), 0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol, 2, 0); }
#line 3675 "y.tab.c"
    break;

  case 65: /* command: S_CCOPY range  */
#line 766 "gram.y"
                                 { copy_to_clipboard((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3681 "y.tab.c"
    break;

  case 66: /* command: S_STRTONUM range  */
#line 767 "gram.y"
                                 { convert_string_to_number((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col); }
#line 3687 "y.tab.c"
    break;

  case 67: /* command: S_CPASTE  */
#line 768 "gram.y"
                                 { paste_from_clipboard(); }
#line 3693 "y.tab.c"
    break;

  case 68: /* command: S_LOCK var_or_range  */
#line 769 "gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   lock_cells(sh, (yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp);
                                 }
#line 3703 "y.tab.c"
    break;

  case 69: /* command: S_UNLOCK var_or_range  */
#line 774 "gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   unlock_cells(sh, (yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp);
                                 }
#line 3713 "y.tab.c"
    break;

  case 70: /* command: S_NEWSHEET STRING  */
#line 779 "gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh;

                                   // do not need to alloc a new 'Sheet1'
                                   // just reuse the just allocated 'Sheet1' in load_file();
                                   if (! strcmp((yyvsp[0].sval), "Sheet1") && (sh = search_sheet(roman, (yyvsp[0].sval))) != NULL && sh->flags & is_allocated) {
                                       sh->flags &= ~is_allocated;
                                       sh->flags |= is_empty;
                                       scxfree((yyvsp[0].sval));
                                       chg_mode('.');

                                   // if a sheet already exists with the name we are trying to create
                                   } else if ((sh = search_sheet(roman, (yyvsp[0].sval))) != NULL ) {
                                       sc_info("sheet already exist with that name");
                                       scxfree((yyvsp[0].sval));
                                       chg_mode('.');

                                   // if a just allocated 'Sheet1' exists, reuse it and do not malloc a new one.
                                   } else if ((sh = search_sheet(roman, "Sheet1")) != NULL && sh->flags & is_allocated) {
                                       sh->flags &= ~is_allocated;
                                       sh->flags |= is_empty;
                                       free(sh->name);
                                       sh->name = (yyvsp[0].sval);
                                       chg_mode('.');
                                       ui_update(TRUE);

                                   // if reached here, now yes malloc a new one
                                   } else {
                                       roman->cur_sh = new_sheet(roman, (yyvsp[0].sval));
                                       growtbl(roman->cur_sh, GROWNEW, 0, 0);
                                       erasedb(roman->cur_sh, 0);
                                       scxfree((yyvsp[0].sval));
                                       roman->modflg++;
                                       chg_mode('.');
                                       ui_update(TRUE);
                                   }
                                 }
#line 3756 "y.tab.c"
    break;

  case 71: /* command: S_DELSHEET STRING  */
#line 817 "gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh;
                                   if ((sh = search_sheet(roman, (yyvsp[0].sval))) == NULL ) {
                                       sc_info("No sheet exists with that name");
                                       scxfree((yyvsp[0].sval));
                                   } else if (roman->cur_sh == sh && sh->next == NULL && sh->prev == NULL) {
                                       sc_info("Cannot delete the only sheet of document");
                                       scxfree((yyvsp[0].sval));
                                   } else {
                                       if (roman->cur_sh == sh && sh->next != NULL)
                                           roman->cur_sh = sh->next;
                                       else if (roman->cur_sh == sh)
                                           roman->cur_sh = sh->prev;
                                       delete_sheet(roman, sh, 0);
                                       sh = NULL;
                                       roman->modflg++;
                                       scxfree((yyvsp[0].sval));
                                       chg_mode('.');
                                       ui_update(TRUE);
                                   }
                                 }
#line 3783 "y.tab.c"
    break;

  case 72: /* command: S_DELSHEET  */
#line 839 "gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   if (sh->next == NULL && sh->prev == NULL) {
                                       sc_info("Cannot delete the only sheet of document");
                                   } else {
                                       if (roman->cur_sh == sh && sh->next != NULL)
                                           roman->cur_sh = sh->next;
                                       else if (roman->cur_sh == sh)
                                           roman->cur_sh = sh->prev;
                                       delete_sheet(roman, sh, 0);
                                       sh = NULL;
                                       roman->modflg++;
                                       chg_mode('.');
                                       ui_update(TRUE);
                                   }
                                 }
#line 3805 "y.tab.c"
    break;

  case 73: /* command: S_NEXTSHEET  */
#line 856 "gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   if (roman->cur_sh->next != NULL) {
                                       roman->cur_sh = roman->cur_sh->next;
                                   } else if (roman->next != NULL) {
                                       session->cur_doc = roman->next;
                                       session->cur_doc->cur_sh = session->cur_doc->first_sh;
                                   } else {
                                       session->cur_doc = session->first_doc;
                                       session->cur_doc->cur_sh = session->cur_doc->first_sh;
                                   }
                                   chg_mode('.');
                                   ui_update(TRUE);
                                 }
#line 3824 "y.tab.c"
    break;

  case 74: /* command: S_PREVSHEET  */
#line 870 "gram.y"
                                 {
                                   struct roman * roman = session->cur_doc;
                                   if (roman->cur_sh->prev != NULL) {
                                       roman->cur_sh = roman->cur_sh->prev;
                                   } else if (roman->prev != NULL) {
                                       session->cur_doc = roman->prev;
                                       session->cur_doc->cur_sh = session->cur_doc->last_sh;
                                   } else {
                                       session->cur_doc = session->last_doc;
                                       session->cur_doc->cur_sh = session->cur_doc->last_sh;
                                   }
                                   chg_mode('.');
                                   ui_update(TRUE);
                                 }
#line 3843 "y.tab.c"
    break;

  case 75: /* command: S_MOVETOSHEET STRING  */
#line 885 "gram.y"
                                 {
                                   struct sheet * sh;
                                   if ((sh = search_sheet(session->cur_doc, (yyvsp[0].sval))) != NULL )
                                       session->cur_doc->cur_sh = sh;
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3854 "y.tab.c"
    break;

  case 76: /* command: S_RENAMESHEET STRING  */
#line 891 "gram.y"
                                 {
                                   struct sheet * sh = session->cur_doc->cur_sh;
                                   if (sh->name != NULL) free(sh->name);
                                   session->cur_doc->modflg++;
                                   sh->name = (yyvsp[0].sval);
                                   chg_mode('.');
                                   ui_show_header();
                                 }
#line 3867 "y.tab.c"
    break;

  case 77: /* command: S_NMAP STRING STRING  */
#line 900 "gram.y"
                                 {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), NORMAL_MODE, 1);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3877 "y.tab.c"
    break;

  case 78: /* command: S_IMAP STRING STRING  */
#line 906 "gram.y"
                                 {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), INSERT_MODE, 1);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3887 "y.tab.c"
    break;

  case 79: /* command: S_VMAP STRING STRING  */
#line 911 "gram.y"
                                 {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), VISUAL_MODE, 1);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3897 "y.tab.c"
    break;

  case 80: /* command: S_CMAP STRING STRING  */
#line 916 "gram.y"
                                 {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), COMMAND_MODE, 1);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                 }
#line 3907 "y.tab.c"
    break;

  case 81: /* command: S_NNOREMAP STRING STRING  */
#line 921 "gram.y"
                                   {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), NORMAL_MODE, 0);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3917 "y.tab.c"
    break;

  case 82: /* command: S_INOREMAP STRING STRING  */
#line 927 "gram.y"
                                   {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), INSERT_MODE, 0);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3927 "y.tab.c"
    break;

  case 83: /* command: S_VNOREMAP STRING STRING  */
#line 932 "gram.y"
                                   {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), VISUAL_MODE, 0);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3937 "y.tab.c"
    break;

  case 84: /* command: S_CNOREMAP STRING STRING  */
#line 937 "gram.y"
                                   {
                                   add_map((yyvsp[-1].sval), (yyvsp[0].sval), COMMAND_MODE, 0);
                                   scxfree((yyvsp[-1].sval));
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3947 "y.tab.c"
    break;

  case 85: /* command: S_NUNMAP STRING  */
#line 943 "gram.y"
                                   {
                                   del_map((yyvsp[0].sval), NORMAL_MODE);
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3956 "y.tab.c"
    break;

  case 86: /* command: S_IUNMAP STRING  */
#line 948 "gram.y"
                                   {
                                   del_map((yyvsp[0].sval), INSERT_MODE);
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3965 "y.tab.c"
    break;

  case 87: /* command: S_VUNMAP STRING  */
#line 952 "gram.y"
                                   {
                                   del_map((yyvsp[0].sval), VISUAL_MODE);
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3974 "y.tab.c"
    break;

  case 88: /* command: S_CUNMAP STRING  */
#line 957 "gram.y"
                                   {
                                   del_map((yyvsp[0].sval), COMMAND_MODE);
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3983 "y.tab.c"
    break;

  case 89: /* command: S_COLOR STRING  */
#line 961 "gram.y"
                                   {
#ifdef USECOLORS
                                   chg_color((yyvsp[0].sval));
#endif
                                   scxfree((yyvsp[0].sval));
                                   }
#line 3994 "y.tab.c"
    break;

  case 90: /* command: S_DETAIL var  */
#line 968 "gram.y"
                                   {
                                   char det[BUFFERSIZE] = "";
                                   struct ent * e = (yyvsp[0].ent).vp;

                                   sprintf(det + strlen(det), "row: %d\n", e->row);
                                   sprintf(det + strlen(det), "col: %d\n", e->col);
                                   sprintf(det + strlen(det), "cellerror: %d\n"   , e->cellerror);
                                   sprintf(det + strlen(det), "flags:\n");
                                   sprintf(det + strlen(det), "is_valid: %d\n"    , e->flags & is_valid );
                                   sprintf(det + strlen(det), "is_deleted: %d\n"  , e->flags & is_deleted);
                                   sprintf(det + strlen(det), "is_changed: %d\n"  , e->flags & is_changed);
                                   sprintf(det + strlen(det), "is_strexpr: %d\n"  , e->flags & is_strexpr);
                                   sprintf(det + strlen(det), "is_leftflush: %d\n", e->flags & is_leftflush);
                                   sprintf(det + strlen(det), "is_locked: %d\n"   , e->flags & is_locked);
                                   sprintf(det + strlen(det), "is_label: %d\n"    , e->flags & is_label);
                                   sprintf(det + strlen(det), "iscleared: %d\n"   , e->flags & iscleared);
                                   sprintf(det + strlen(det), "may_sync: %d\n"    , e->flags & may_sync);
                                   ui_show_text((char *) &det);
                                   }
#line 4018 "y.tab.c"
    break;

  case 91: /* command: S_CELLCOLOR var_or_range STRING  */
#line 989 "gram.y"
                                   {
#ifdef USECOLORS
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
                                   if ( ! get_conf_int("nocurses"))
                                       color_cell(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, (yyvsp[0].sval));
#endif
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4032 "y.tab.c"
    break;

  case 92: /* command: S_TRIGGER var_or_range STRING  */
#line 999 "gram.y"
                                        {
                                          set_trigger(session->cur_doc->cur_sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, (yyvsp[0].sval));
                                          scxfree((yyvsp[0].sval));
                                        }
#line 4041 "y.tab.c"
    break;

  case 93: /* command: S_UNTRIGGER var_or_range  */
#line 1004 "gram.y"
                                   {
                                   del_trigger(session->cur_doc->cur_sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col);
                                   }
#line 4049 "y.tab.c"
    break;

  case 94: /* command: S_CELLCOLOR STRING  */
#line 1008 "gram.y"
                                   {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
#ifdef USECOLORS
                                   if ( ! get_conf_int("nocurses"))
                                       color_cell(sh, sh->currow, sh->curcol, sh->currow, sh->curcol, (yyvsp[0].sval));
#endif
                                   scxfree((yyvsp[0].sval));
                                   }
#line 4063 "y.tab.c"
    break;

  case 95: /* command: S_UNFORMAT var_or_range  */
#line 1018 "gram.y"
                                   {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
#ifdef USECOLORS
                                   if ( ! get_conf_int("nocurses")) unformat(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col);
#endif
                                   }
#line 4075 "y.tab.c"
    break;

  case 96: /* command: S_UNFORMAT  */
#line 1026 "gram.y"
                                   {
                                   struct roman * roman = session->cur_doc;
                                   struct sheet * sh = roman->cur_sh;
#ifdef USECOLORS
                                   if ( ! get_conf_int("nocurses")) unformat(sh, sh->currow, sh->curcol, sh->currow, sh->curcol);
#endif
                                   }
#line 4087 "y.tab.c"
    break;

  case 97: /* command: S_REDEFINE_COLOR STRING NUMBER NUMBER NUMBER  */
#line 1034 "gram.y"
                                                      {
                                         redefine_color((yyvsp[-3].sval), (yyvsp[-2].ival), (yyvsp[-1].ival), (yyvsp[0].ival));
                                         scxfree((yyvsp[-3].sval)); }
#line 4095 "y.tab.c"
    break;

  case 98: /* command: S_DEFINE_COLOR STRING NUMBER NUMBER NUMBER  */
#line 1038 "gram.y"
                                                    {
                                         define_color((yyvsp[-3].sval), (yyvsp[-2].ival), (yyvsp[-1].ival), (yyvsp[0].ival));
                                         scxfree((yyvsp[-3].sval)); }
#line 4103 "y.tab.c"
    break;

  case 99: /* command: S_FCOPY  */
#line 1042 "gram.y"
                                   { fcopy(session->cur_doc->cur_sh, ""); }
#line 4109 "y.tab.c"
    break;

  case 100: /* command: S_FCOPY strarg  */
#line 1043 "gram.y"
                                   { fcopy(session->cur_doc->cur_sh, (yyvsp[0].sval)); }
#line 4115 "y.tab.c"
    break;

  case 101: /* command: S_FSUM  */
#line 1044 "gram.y"
                                   { fsum(session->cur_doc->cur_sh);  }
#line 4121 "y.tab.c"
    break;

  case 102: /* command: S_PLOT STRING var_or_range  */
#line 1046 "gram.y"
                                          {
                                     plot((yyvsp[-1].sval), (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col);
                                     scxfree((yyvsp[-1].sval));
                                   }
#line 4130 "y.tab.c"
    break;

  case 103: /* command: S_SET setlist  */
#line 1054 "gram.y"
                                   { //if (! loading) sc_debug("INT: Config value changed");
                                   }
#line 4137 "y.tab.c"
    break;

  case 104: /* command: S_DEFINE strarg range  */
#line 1070 "gram.y"
                                   { add_range((yyvsp[-1].sval), (yyvsp[0].rval).left, (yyvsp[0].rval).right, 1); }
#line 4143 "y.tab.c"
    break;

  case 105: /* command: S_DEFINE strarg var  */
#line 1071 "gram.y"
                                   { add_range((yyvsp[-1].sval), (yyvsp[0].ent), (yyvsp[0].ent), 0); }
#line 4149 "y.tab.c"
    break;

  case 106: /* command: S_UNDEFINE var_or_range  */
#line 1073 "gram.y"
                                   { del_range((yyvsp[0].rval).left.vp, (yyvsp[0].rval).right.vp); }
#line 4155 "y.tab.c"
    break;

  case 107: /* command: S_EVAL e  */
#line 1075 "gram.y"
                                   {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh = roman->cur_sh;
                                     eval_result = eval(sh, NULL, (yyvsp[0].enode));
                                     efree((yyvsp[0].enode));
                                   }
#line 4166 "y.tab.c"
    break;

  case 108: /* command: S_EXECUTE STRING  */
#line 1081 "gram.y"
                                   {

                                     inputline[0]=L'\0';

                                     #ifdef HISTORY_FILE
                                            commandline_history = (struct history *) create_history(':');
                                            load_history(commandline_history, ':'); // load the command history file
                                     #endif
                                     #ifdef INS_HISTORY_FILE
                                            insert_history = (struct history *) create_history('=');
                                            load_history(insert_history, '='); // load the insert history file
                                     #endif

                                     (void) swprintf(inputline, BUFFERSIZE, L"%s", (yyvsp[0].sval));

                                     struct block * auxb = (struct block *) create_buf();
                                     addto_buf(auxb, OKEY_ENTER);
                                     do_commandmode(auxb);
                                     flush_buf(auxb);
                                     erase_buf(auxb);
                                     auxb = NULL;
                                     inputline[0]=L'\0';
                                     scxfree((yyvsp[0].sval));
                                   }
#line 4195 "y.tab.c"
    break;

  case 109: /* command: S_EXPORT STRING STRING  */
#line 1105 "gram.y"
                                   {
                                     struct roman * roman = session->cur_doc;
                                     swprintf(inputline, BUFFERSIZE, L"e! %s %s", (yyvsp[-1].sval), (yyvsp[0].sval));
                                     do_export(0, 0, roman->cur_sh->maxrow, roman->cur_sh->maxcol);
                                     scxfree((yyvsp[-1].sval));
                                     scxfree((yyvsp[0].sval));
                                   }
#line 4207 "y.tab.c"
    break;

  case 110: /* command: S_QUIT  */
#line 1112 "gram.y"
                                   {
                                     printf("quitting. unsaved changes will be lost.\n");
                                     shall_quit = 2; // unsaved changes are lost!
                                   }
#line 4216 "y.tab.c"
    break;

  case 111: /* command: S_REBUILD_GRAPH  */
#line 1116 "gram.y"
                                   {
                                     rebuild_graph();
                                     ui_update(FALSE);
                                   }
#line 4225 "y.tab.c"
    break;

  case 112: /* command: S_PRINT_GRAPH  */
#line 1121 "gram.y"
                                   { print_vertexs(); }
#line 4231 "y.tab.c"
    break;

  case 113: /* command: S_SYNCREFS  */
#line 1122 "gram.y"
                                   { sync_refs(session->cur_doc->cur_sh); }
#line 4237 "y.tab.c"
    break;

  case 114: /* command: S_UNDO  */
#line 1124 "gram.y"
                                   {
#ifdef UNDO
                                     do_undo();
                                     // sync_refs(session->cur_doc->cur_sh);
                                     EvalAll();
                                     ui_update(TRUE);
#endif
                                   }
#line 4250 "y.tab.c"
    break;

  case 115: /* command: S_REDO  */
#line 1133 "gram.y"
                                   {
#ifdef UNDO
                                     do_redo();
                                     // sync_refs(session->cur_doc->cur_sh);
                                     EvalAll();
                                     ui_update(TRUE);
#endif
                                   }
#line 4263 "y.tab.c"
    break;

  case 116: /* command: S_RECALC  */
#line 1143 "gram.y"
                                   {
                                     EvalAll();
                                     //ui_update(1);
                                     //changed = 0;
                                   }
#line 4273 "y.tab.c"
    break;

  case 117: /* command: S_GETNUM var_or_range  */
#line 1148 "gram.y"
                                   {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh = roman->cur_sh;
                                     getnum(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput);
                                   }
#line 4283 "y.tab.c"
    break;

  case 118: /* command: S_GETNUM '{' STRING '}' '!' var_or_range  */
#line 1154 "gram.y"
                                                  {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh;
                                     if ((sh = search_sheet(roman, (yyvsp[-3].sval))) == NULL )
                                         sh = roman->cur_sh;
                                     getnum(sh, (yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput);
                                     scxfree((yyvsp[-3].sval));
                                   }
#line 4296 "y.tab.c"
    break;

  case 119: /* command: S_GETSTRING var_or_range  */
#line 1162 "gram.y"
                                   { getstring((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput); }
#line 4302 "y.tab.c"
    break;

  case 120: /* command: S_GETEXP var_or_range  */
#line 1164 "gram.y"
                                   { getexp((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput); }
#line 4308 "y.tab.c"
    break;

  case 121: /* command: S_GETFMT var_or_range  */
#line 1167 "gram.y"
                                   { getfmt((yyvsp[0].rval).left.vp->row, (yyvsp[0].rval).left.vp->col, (yyvsp[0].rval).right.vp->row, (yyvsp[0].rval).right.vp->col, fdoutput); }
#line 4314 "y.tab.c"
    break;

  case 122: /* command: S_YANKAREA '{' STRING '}' '!' var_or_range STRING  */
#line 1169 "gram.y"
                                                           {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh;
                                     if ((sh = search_sheet(roman, (yyvsp[-4].sval))) == NULL )
                                         sh = roman->cur_sh;
                                     yank_area(sh, (yyvsp[-1].rval).left.vp->row, (yyvsp[-1].rval).left.vp->col, (yyvsp[-1].rval).right.vp->row, (yyvsp[-1].rval).right.vp->col, (yyvsp[0].sval)[0], 1);
                                     scxfree((yyvsp[-4].sval));
                                     scxfree((yyvsp[0].sval));
                                   }
#line 4328 "y.tab.c"
    break;

  case 123: /* command: S_PASTEYANKED '{' STRING '}' NUMBER STRING  */
#line 1178 "gram.y"
                                                    {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh;
                                     if ((sh = search_sheet(roman, (yyvsp[-3].sval))) == NULL )
                                         sh = roman->cur_sh;
                                     paste_yanked_ents(sh, (yyvsp[-1].ival), (yyvsp[0].sval)[0]);
                                     scxfree((yyvsp[-3].sval));
                                     scxfree((yyvsp[0].sval));
                                   }
#line 4342 "y.tab.c"
    break;

  case 124: /* command: S_SEVAL e  */
#line 1187 "gram.y"
                                   {
                                     struct roman * roman = session->cur_doc;
                                     struct sheet * sh = roman->cur_sh;
                                     seval_result = seval(sh, NULL, (yyvsp[0].enode)); // always make sure this seval_result is always freed afterwards
                                     efree((yyvsp[0].enode));
                                   }
#line 4353 "y.tab.c"
    break;

  case 125: /* command: S_ERROR STRING  */
#line 1193 "gram.y"
                                   { sc_error((yyvsp[0].sval));
                                     //free $2
                                   }
#line 4361 "y.tab.c"
    break;

  case 127: /* command: error  */
#line 1198 "gram.y"
                 {
                     sc_error("syntax error");
                     line[0]='\0';
                     //linelim = 0;
                     //yyparse();
                     linelim = -1;
                     yyclearin;
                     yyerrok;
                 }
#line 4375 "y.tab.c"
    break;

  case 128: /* term: var  */
#line 1208 "gram.y"
                                  {
                                    if ((yyvsp[0].ent).vf & GETENT)
                                        (yyval.enode) = (yyvsp[0].ent).expr;
                                    else {
                                       (yyvsp[0].ent).sheet = NULL;
                                       (yyval.enode) = new_var(O_VAR, (yyvsp[0].ent));
                                       (yyval.enode)->e.r.left.expr = NULL;
                                       (yyval.enode)->e.r.right.expr = NULL;
                                       }
                                  }
#line 4390 "y.tab.c"
    break;

  case 129: /* term: '{' STRING '}' '!' var  */
#line 1219 "gram.y"
                                  {
                                    struct roman * roman = session->cur_doc;
                                    struct sheet * sh;
                                    if ((sh = search_sheet(roman, (yyvsp[-3].sval))) != NULL) {
                                        struct ent_ptr ep;
                                        ep.vf = (yyvsp[0].ent).vf;
                                        ep.vp = lookat(sh, (yyvsp[0].ent).vp->row, (yyvsp[0].ent).vp->col);
                                        ep.sheet = sh;
                                        (yyval.enode) = new_var(O_VAR, ep);
                                        (yyval.enode)->e.r.left.expr = NULL;
                                        (yyval.enode)->e.r.right.expr = NULL;
                                        scxfree((yyvsp[-3].sval));
                                    } else {
                                        //sc_debug("not sheet found");
                                        (yyval.enode) = NULL;
                                        scxfree((yyvsp[-3].sval));
                                    }
                                  }
#line 4413 "y.tab.c"
    break;

  case 130: /* term: '@' K_FIXED term  */
#line 1238 "gram.y"
                                  { (yyval.enode) = new('f', (yyvsp[0].enode), ENULL); }
#line 4419 "y.tab.c"
    break;

  case 131: /* term: '(' '@' K_FIXED ')' term  */
#line 1241 "gram.y"
                                  { (yyval.enode) = new('F', (yyvsp[0].enode), ENULL); }
#line 4425 "y.tab.c"
    break;

  case 132: /* term: '@' K_SUM '(' var_or_range ')'  */
#line 1244 "gram.y"
                                  { (yyval.enode) = new(SUM, new_range(REDUCE | SUM, (yyvsp[-1].rval)), ENULL); }
#line 4431 "y.tab.c"
    break;

  case 133: /* term: '@' K_SUM '(' range ',' e ')'  */
#line 1246 "gram.y"
                                  { (yyval.enode) = new(SUM, new_range(REDUCE | SUM, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4437 "y.tab.c"
    break;

  case 134: /* term: '@' K_PROD '(' var_or_range ')'  */
#line 1248 "gram.y"
                                  { (yyval.enode) = new(PROD, new_range(REDUCE | PROD, (yyvsp[-1].rval)), ENULL); }
#line 4443 "y.tab.c"
    break;

  case 135: /* term: '@' K_PROD '(' range ',' e ')'  */
#line 1250 "gram.y"
                                  { (yyval.enode) = new(PROD, new_range(REDUCE | PROD, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4449 "y.tab.c"
    break;

  case 136: /* term: '@' K_AVG '(' var_or_range ')'  */
#line 1252 "gram.y"
                                  { (yyval.enode) = new(AVG, new_range(REDUCE | AVG, (yyvsp[-1].rval)), ENULL); }
#line 4455 "y.tab.c"
    break;

  case 137: /* term: '@' K_AVG '(' range ',' e ')'  */
#line 1254 "gram.y"
                                  { (yyval.enode) = new(AVG, new_range(REDUCE | AVG, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4461 "y.tab.c"
    break;

  case 138: /* term: '@' K_STDDEV '(' var_or_range ')'  */
#line 1256 "gram.y"
                                  { (yyval.enode) = new(STDDEV, new_range(REDUCE | STDDEV, (yyvsp[-1].rval)), ENULL); }
#line 4467 "y.tab.c"
    break;

  case 139: /* term: '@' K_STDDEV '(' range ',' e ')'  */
#line 1258 "gram.y"
                                  { (yyval.enode) = new(STDDEV, new_range(REDUCE | STDDEV, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4473 "y.tab.c"
    break;

  case 140: /* term: '@' K_COUNT '(' var_or_range ')'  */
#line 1260 "gram.y"
                                  { (yyval.enode) = new(COUNT, new_range(REDUCE | COUNT, (yyvsp[-1].rval)), ENULL); }
#line 4479 "y.tab.c"
    break;

  case 141: /* term: '@' K_COUNT '(' range ',' e ')'  */
#line 1262 "gram.y"
                                  { (yyval.enode) = new(COUNT, new_range(REDUCE | COUNT, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4485 "y.tab.c"
    break;

  case 142: /* term: '@' K_MAX '(' var_or_range ')'  */
#line 1264 "gram.y"
                                  { (yyval.enode) = new(MAX, new_range(REDUCE | MAX, (yyvsp[-1].rval)), ENULL); }
#line 4491 "y.tab.c"
    break;

  case 143: /* term: '@' K_MAX '(' range ',' e ')'  */
#line 1266 "gram.y"
                                  { (yyval.enode) = new(MAX, new_range(REDUCE | MAX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4497 "y.tab.c"
    break;

  case 144: /* term: '@' K_MAX '(' e ',' expr_list ')'  */
#line 1268 "gram.y"
                                  { (yyval.enode) = new(LMAX, (yyvsp[-1].enode), (yyvsp[-3].enode)); }
#line 4503 "y.tab.c"
    break;

  case 145: /* term: '@' K_MIN '(' var_or_range ')'  */
#line 1270 "gram.y"
                                  { (yyval.enode) = new(MIN, new_range(REDUCE | MIN, (yyvsp[-1].rval)), ENULL); }
#line 4509 "y.tab.c"
    break;

  case 146: /* term: '@' K_MIN '(' range ',' e ')'  */
#line 1272 "gram.y"
                                  { (yyval.enode) = new(MIN, new_range(REDUCE | MIN, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4515 "y.tab.c"
    break;

  case 147: /* term: '@' K_MIN '(' e ',' expr_list ')'  */
#line 1274 "gram.y"
                                  { (yyval.enode) = new(LMIN, (yyvsp[-1].enode), (yyvsp[-3].enode)); }
#line 4521 "y.tab.c"
    break;

  case 148: /* term: '@' K_ROWS '(' var_or_range ')'  */
#line 1276 "gram.y"
                                  { (yyval.enode) = new_range(REDUCE | 'R', (yyvsp[-1].rval)); }
#line 4527 "y.tab.c"
    break;

  case 149: /* term: '@' K_COLS '(' var_or_range ')'  */
#line 1278 "gram.y"
                                  { (yyval.enode) = new_range(REDUCE | 'C', (yyvsp[-1].rval)); }
#line 4533 "y.tab.c"
    break;

  case 150: /* term: '@' K_ABS '(' e ')'  */
#line 1279 "gram.y"
                                  { (yyval.enode) = new(ABS, (yyvsp[-1].enode), ENULL); }
#line 4539 "y.tab.c"
    break;

  case 151: /* term: '@' K_FROW '(' e ')'  */
#line 1280 "gram.y"
                                  { (yyval.enode) = new(FROW, (yyvsp[-1].enode), ENULL); }
#line 4545 "y.tab.c"
    break;

  case 152: /* term: '@' K_FCOL '(' e ')'  */
#line 1281 "gram.y"
                                  { (yyval.enode) = new(FCOL, (yyvsp[-1].enode), ENULL); }
#line 4551 "y.tab.c"
    break;

  case 153: /* term: '@' K_ACOS '(' e ')'  */
#line 1282 "gram.y"
                                  { (yyval.enode) = new(ACOS, (yyvsp[-1].enode), ENULL); }
#line 4557 "y.tab.c"
    break;

  case 154: /* term: '@' K_ASIN '(' e ')'  */
#line 1283 "gram.y"
                                  { (yyval.enode) = new(ASIN, (yyvsp[-1].enode), ENULL); }
#line 4563 "y.tab.c"
    break;

  case 155: /* term: '@' K_ATAN '(' e ')'  */
#line 1284 "gram.y"
                                  { (yyval.enode) = new(ATAN, (yyvsp[-1].enode), ENULL); }
#line 4569 "y.tab.c"
    break;

  case 156: /* term: '@' K_ATAN2 '(' e ',' e ')'  */
#line 1286 "gram.y"
                                  { (yyval.enode) = new(ATAN2, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4575 "y.tab.c"
    break;

  case 157: /* term: '@' K_CEIL '(' e ')'  */
#line 1287 "gram.y"
                                  { (yyval.enode) = new(CEIL, (yyvsp[-1].enode), ENULL); }
#line 4581 "y.tab.c"
    break;

  case 158: /* term: '@' K_COS '(' e ')'  */
#line 1288 "gram.y"
                                  { (yyval.enode) = new(COS, (yyvsp[-1].enode), ENULL); }
#line 4587 "y.tab.c"
    break;

  case 159: /* term: '@' K_EXP '(' e ')'  */
#line 1289 "gram.y"
                                  { (yyval.enode) = new(EXP, (yyvsp[-1].enode), ENULL); }
#line 4593 "y.tab.c"
    break;

  case 160: /* term: '@' K_FABS '(' e ')'  */
#line 1290 "gram.y"
                                  { (yyval.enode) = new(FABS, (yyvsp[-1].enode), ENULL); }
#line 4599 "y.tab.c"
    break;

  case 161: /* term: '@' K_FLOOR '(' e ')'  */
#line 1291 "gram.y"
                                  { (yyval.enode) = new(FLOOR, (yyvsp[-1].enode), ENULL); }
#line 4605 "y.tab.c"
    break;

  case 162: /* term: '@' K_HYPOT '(' e ',' e ')'  */
#line 1293 "gram.y"
                                  { (yyval.enode) = new(HYPOT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4611 "y.tab.c"
    break;

  case 163: /* term: '@' K_LN '(' e ')'  */
#line 1294 "gram.y"
                                  { (yyval.enode) = new(LOG, (yyvsp[-1].enode), ENULL); }
#line 4617 "y.tab.c"
    break;

  case 164: /* term: '@' K_LOG '(' e ')'  */
#line 1295 "gram.y"
                                  { (yyval.enode) = new(LOG10, (yyvsp[-1].enode), ENULL); }
#line 4623 "y.tab.c"
    break;

  case 165: /* term: '@' K_POW '(' e ',' e ')'  */
#line 1297 "gram.y"
                                  { (yyval.enode) = new(POW, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4629 "y.tab.c"
    break;

  case 166: /* term: '@' K_SIN '(' e ')'  */
#line 1298 "gram.y"
                                  { (yyval.enode) = new(SIN, (yyvsp[-1].enode), ENULL); }
#line 4635 "y.tab.c"
    break;

  case 167: /* term: '@' K_SQRT '(' e ')'  */
#line 1299 "gram.y"
                                  { (yyval.enode) = new(SQRT, (yyvsp[-1].enode), ENULL); }
#line 4641 "y.tab.c"
    break;

  case 168: /* term: '@' K_TAN '(' e ')'  */
#line 1300 "gram.y"
                                  { (yyval.enode) = new(TAN, (yyvsp[-1].enode), ENULL); }
#line 4647 "y.tab.c"
    break;

  case 169: /* term: '@' K_DTR '(' e ')'  */
#line 1301 "gram.y"
                                  { (yyval.enode) = new(DTR, (yyvsp[-1].enode), ENULL); }
#line 4653 "y.tab.c"
    break;

  case 170: /* term: '@' K_RTD '(' e ')'  */
#line 1302 "gram.y"
                                  { (yyval.enode) = new(RTD, (yyvsp[-1].enode), ENULL); }
#line 4659 "y.tab.c"
    break;

  case 171: /* term: '@' K_RND '(' e ')'  */
#line 1303 "gram.y"
                                  { (yyval.enode) = new(RND, (yyvsp[-1].enode), ENULL); }
#line 4665 "y.tab.c"
    break;

  case 172: /* term: '@' K_ROUND '(' e ',' e ')'  */
#line 1305 "gram.y"
                                  { (yyval.enode) = new(ROUND, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4671 "y.tab.c"
    break;

  case 173: /* term: '@' K_IF '(' e ',' e ',' e ')'  */
#line 1307 "gram.y"
                                  { (yyval.enode) = new(IF,  (yyvsp[-5].enode),new(',',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4677 "y.tab.c"
    break;

  case 174: /* term: '@' K_PV '(' e ',' e ',' e ')'  */
#line 1309 "gram.y"
                                  { (yyval.enode) = new(PV,  (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4683 "y.tab.c"
    break;

  case 175: /* term: '@' K_FV '(' e ',' e ',' e ')'  */
#line 1311 "gram.y"
                                  { (yyval.enode) = new(FV,  (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4689 "y.tab.c"
    break;

  case 176: /* term: '@' K_PMT '(' e ',' e ',' e ')'  */
#line 1313 "gram.y"
                                  { (yyval.enode) = new(PMT, (yyvsp[-5].enode),new(':',(yyvsp[-3].enode),(yyvsp[-1].enode))); }
#line 4695 "y.tab.c"
    break;

  case 177: /* term: '@' K_HOUR '(' e ')'  */
#line 1314 "gram.y"
                                  { (yyval.enode) = new(HOUR, (yyvsp[-1].enode), ENULL); }
#line 4701 "y.tab.c"
    break;

  case 178: /* term: '@' K_MINUTE '(' e ')'  */
#line 1315 "gram.y"
                                  { (yyval.enode) = new(MINUTE, (yyvsp[-1].enode), ENULL); }
#line 4707 "y.tab.c"
    break;

  case 179: /* term: '@' K_SECOND '(' e ')'  */
#line 1316 "gram.y"
                                  { (yyval.enode) = new(SECOND, (yyvsp[-1].enode), ENULL); }
#line 4713 "y.tab.c"
    break;

  case 180: /* term: '@' K_MONTH '(' e ')'  */
#line 1317 "gram.y"
                                  { (yyval.enode) = new(MONTH, (yyvsp[-1].enode), ENULL); }
#line 4719 "y.tab.c"
    break;

  case 181: /* term: '@' K_DAY '(' e ')'  */
#line 1318 "gram.y"
                                  { (yyval.enode) = new(DAY, (yyvsp[-1].enode), ENULL); }
#line 4725 "y.tab.c"
    break;

  case 182: /* term: '@' K_YEAR '(' e ')'  */
#line 1319 "gram.y"
                                  { (yyval.enode) = new(YEAR, (yyvsp[-1].enode), ENULL); }
#line 4731 "y.tab.c"
    break;

  case 183: /* term: '@' K_NOW  */
#line 1320 "gram.y"
                                  { (yyval.enode) = new(NOW, ENULL, ENULL);}
#line 4737 "y.tab.c"
    break;

  case 184: /* term: '@' K_DTS '(' e ',' e ',' e ')'  */
#line 1322 "gram.y"
                                  { (yyval.enode) = new(DTS, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode)));}
#line 4743 "y.tab.c"
    break;

  case 185: /* term: NUMBER '.' NUMBER '.' NUMBER  */
#line 1324 "gram.y"
                                  { (yyval.enode) = new(DTS, new_const(O_CONST, (double) (yyvsp[-4].ival)),
                                         new(',', new_const(O_CONST, (double) (yyvsp[-2].ival)),
                                         new_const(O_CONST, (double) (yyvsp[0].ival))));}
#line 4751 "y.tab.c"
    break;

  case 186: /* term: '@' K_TTS '(' e ',' e ',' e ')'  */
#line 1328 "gram.y"
                                  { (yyval.enode) = new(TTS, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode)));}
#line 4757 "y.tab.c"
    break;

  case 187: /* term: '@' K_STON '(' e ')'  */
#line 1329 "gram.y"
                                  { (yyval.enode) = new(STON, (yyvsp[-1].enode), ENULL); }
#line 4763 "y.tab.c"
    break;

  case 188: /* term: '@' K_SLEN '(' e ')'  */
#line 1330 "gram.y"
                                  { (yyval.enode) = new(SLEN, (yyvsp[-1].enode), ENULL); }
#line 4769 "y.tab.c"
    break;

  case 189: /* term: '@' K_EQS '(' e ',' e ')'  */
#line 1332 "gram.y"
                                  { (yyval.enode) = new(EQS, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4775 "y.tab.c"
    break;

  case 190: /* term: '@' K_DATE '(' e ')'  */
#line 1333 "gram.y"
                                  { (yyval.enode) = new(DATE, (yyvsp[-1].enode), ENULL); }
#line 4781 "y.tab.c"
    break;

  case 191: /* term: '@' K_DATE '(' e ',' e ')'  */
#line 1335 "gram.y"
                                  { (yyval.enode) = new(DATE, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4787 "y.tab.c"
    break;

  case 192: /* term: '@' K_FMT '(' e ',' e ')'  */
#line 1337 "gram.y"
                                  { (yyval.enode) = new(FMT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4793 "y.tab.c"
    break;

  case 193: /* term: '@' K_UPPER '(' e ')'  */
#line 1338 "gram.y"
                                  { (yyval.enode) = new(UPPER, (yyvsp[-1].enode), ENULL); }
#line 4799 "y.tab.c"
    break;

  case 194: /* term: '@' K_LOWER '(' e ')'  */
#line 1339 "gram.y"
                                  { (yyval.enode) = new(LOWER, (yyvsp[-1].enode), ENULL); }
#line 4805 "y.tab.c"
    break;

  case 195: /* term: '@' K_CAPITAL '(' e ')'  */
#line 1340 "gram.y"
                                  { (yyval.enode) = new(CAPITAL, (yyvsp[-1].enode), ENULL); }
#line 4811 "y.tab.c"
    break;

  case 196: /* term: '@' K_INDEX '(' range ',' e ')'  */
#line 1342 "gram.y"
                                  { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4817 "y.tab.c"
    break;

  case 197: /* term: '@' K_INDEX '(' e ',' range ')'  */
#line 1344 "gram.y"
                                  { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4823 "y.tab.c"
    break;

  case 198: /* term: '@' K_INDEX '(' range ',' e ',' e ')'  */
#line 1346 "gram.y"
                                  { (yyval.enode) = new(INDEX, new_range(REDUCE | INDEX, (yyvsp[-5].rval)), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4829 "y.tab.c"
    break;

  case 199: /* term: '@' K_LOOKUP '(' range ',' e ')'  */
#line 1348 "gram.y"
                                  { (yyval.enode) = new(LOOKUP, new_range(REDUCE | LOOKUP, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4835 "y.tab.c"
    break;

  case 200: /* term: '@' K_LOOKUP '(' e ',' range ')'  */
#line 1350 "gram.y"
                                  { (yyval.enode) = new(LOOKUP, new_range(REDUCE | LOOKUP, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4841 "y.tab.c"
    break;

  case 201: /* term: '@' K_HLOOKUP '(' range ',' e ',' e ')'  */
#line 1352 "gram.y"
                                  { (yyval.enode) = new(HLOOKUP, new_range(REDUCE | HLOOKUP, (yyvsp[-5].rval)), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4847 "y.tab.c"
    break;

  case 202: /* term: '@' K_HLOOKUP '(' e ',' range ',' e ')'  */
#line 1354 "gram.y"
                                  { (yyval.enode) = new(HLOOKUP, new_range(REDUCE | HLOOKUP, (yyvsp[-3].rval)), new(',', (yyvsp[-5].enode), (yyvsp[-1].enode))); }
#line 4853 "y.tab.c"
    break;

  case 203: /* term: '@' K_VLOOKUP '(' range ',' e ',' e ')'  */
#line 1356 "gram.y"
                                  { (yyval.enode) = new(VLOOKUP, new_range(REDUCE | VLOOKUP, (yyvsp[-5].rval)), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4859 "y.tab.c"
    break;

  case 204: /* term: '@' K_VLOOKUP '(' e ',' range ',' e ')'  */
#line 1358 "gram.y"
                                  { (yyval.enode) = new(VLOOKUP, new_range(REDUCE | VLOOKUP, (yyvsp[-3].rval)), new(',', (yyvsp[-5].enode), (yyvsp[-1].enode))); }
#line 4865 "y.tab.c"
    break;

  case 205: /* term: '@' K_STINDEX '(' range ',' e ')'  */
#line 1360 "gram.y"
                                  { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-3].rval)), (yyvsp[-1].enode)); }
#line 4871 "y.tab.c"
    break;

  case 206: /* term: '@' K_STINDEX '(' e ',' range ')'  */
#line 1362 "gram.y"
                                  { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-1].rval)), (yyvsp[-3].enode)); }
#line 4877 "y.tab.c"
    break;

  case 207: /* term: '@' K_STINDEX '(' range ',' e ',' e ')'  */
#line 1364 "gram.y"
                                  { (yyval.enode) = new(STINDEX, new_range(REDUCE | STINDEX, (yyvsp[-5].rval)), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4883 "y.tab.c"
    break;

  case 208: /* term: '@' K_EXT '(' e ',' e ')'  */
#line 1366 "gram.y"
                                  { (yyval.enode) = new(EXT, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4889 "y.tab.c"
    break;

  case 209: /* term: '@' K_LUA '(' e ',' e ')'  */
#line 1368 "gram.y"
                                  {
                                  #ifdef XLUA
                                  (yyval.enode) = new(LUA, (yyvsp[-3].enode), (yyvsp[-1].enode));
                                  #endif
                                  }
#line 4899 "y.tab.c"
    break;

  case 210: /* term: '@' K_MYROW  */
#line 1373 "gram.y"
                                  { (yyval.enode) = new(MYROW, ENULL, ENULL);}
#line 4905 "y.tab.c"
    break;

  case 211: /* term: '@' K_MYCOL  */
#line 1374 "gram.y"
                                  { (yyval.enode) = new(MYCOL, ENULL, ENULL);}
#line 4911 "y.tab.c"
    break;

  case 212: /* term: '@' K_LASTROW  */
#line 1375 "gram.y"
                                  { (yyval.enode) = new(LASTROW, ENULL, ENULL);}
#line 4917 "y.tab.c"
    break;

  case 213: /* term: '@' K_LASTCOL  */
#line 1376 "gram.y"
                                  { (yyval.enode) = new(LASTCOL, ENULL, ENULL);}
#line 4923 "y.tab.c"
    break;

  case 214: /* term: '@' K_NVAL '(' e ',' e ')'  */
#line 1378 "gram.y"
                                  { (yyval.enode) = new(NVAL, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4929 "y.tab.c"
    break;

  case 215: /* term: '@' K_SVAL '(' e ',' e ')'  */
#line 1380 "gram.y"
                                  { (yyval.enode) = new(SVAL, (yyvsp[-3].enode), (yyvsp[-1].enode)); }
#line 4935 "y.tab.c"
    break;

  case 216: /* term: '@' K_REPLACE '(' e ',' e ',' e ')'  */
#line 1382 "gram.y"
                                  { (yyval.enode) = new(REPLACE, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4941 "y.tab.c"
    break;

  case 217: /* term: '@' K_EVALUATE '(' e ')'  */
#line 1384 "gram.y"
                                    { (yyval.enode) = new(EVALUATE, (yyvsp[-1].enode), ENULL); }
#line 4947 "y.tab.c"
    break;

  case 218: /* term: '@' K_SEVALUATE '(' e ')'  */
#line 1385 "gram.y"
                                    { (yyval.enode) = new(SEVALUATE, (yyvsp[-1].enode), ENULL); }
#line 4953 "y.tab.c"
    break;

  case 219: /* term: '@' K_SUBSTR '(' e ',' e ',' e ')'  */
#line 1387 "gram.y"
                                  { (yyval.enode) = new(SUBSTR, (yyvsp[-5].enode), new(',', (yyvsp[-3].enode), (yyvsp[-1].enode))); }
#line 4959 "y.tab.c"
    break;

  case 220: /* term: '(' e ')'  */
#line 1388 "gram.y"
                                  { (yyval.enode) = (yyvsp[-1].enode); }
#line 4965 "y.tab.c"
    break;

  case 221: /* term: '+' term  */
#line 1389 "gram.y"
                                  { (yyval.enode) = (yyvsp[0].enode); }
#line 4971 "y.tab.c"
    break;

  case 222: /* term: NUMBER  */
#line 1391 "gram.y"
                                  { (yyval.enode) = new_const(O_CONST, (double) (yyvsp[0].ival)); }
#line 4977 "y.tab.c"
    break;

  case 223: /* term: FNUMBER  */
#line 1392 "gram.y"
                                  { (yyval.enode) = new_const(O_CONST, (yyvsp[0].fval)); }
#line 4983 "y.tab.c"
    break;

  case 224: /* term: '@' K_PI  */
#line 1393 "gram.y"
                                  { (yyval.enode) = new(PI_, ENULL, ENULL); }
#line 4989 "y.tab.c"
    break;

  case 225: /* term: STRING  */
#line 1394 "gram.y"
                                  { (yyval.enode) = new_str((yyvsp[0].sval)); }
#line 4995 "y.tab.c"
    break;

  case 226: /* term: '~' term  */
#line 1395 "gram.y"
                                  { (yyval.enode) = new('!', (yyvsp[0].enode), ENULL); }
#line 5001 "y.tab.c"
    break;

  case 227: /* term: '!' term  */
#line 1396 "gram.y"
                                  { (yyval.enode) = new('!', (yyvsp[0].enode), ENULL); }
#line 5007 "y.tab.c"
    break;

  case 228: /* term: '@' K_FILENAME '(' e ')'  */
#line 1398 "gram.y"
                                  { (yyval.enode) = new(FILENAME, (yyvsp[-1].enode), ENULL); }
#line 5013 "y.tab.c"
    break;

  case 229: /* term: '@' K_COLTOA '(' e ')'  */
#line 1399 "gram.y"
                                  { (yyval.enode) = new(COLTOA, (yyvsp[-1].enode), ENULL);}
#line 5019 "y.tab.c"
    break;

  case 230: /* term: '@' K_ASCII '(' e ')'  */
#line 1400 "gram.y"
                                  { (yyval.enode) = new(ASCII, (yyvsp[-1].enode), ENULL); }
#line 5025 "y.tab.c"
    break;

  case 231: /* term: '@' K_SET8BIT '(' e ')'  */
#line 1401 "gram.y"
                                  { (yyval.enode) = new(SET8BIT, (yyvsp[-1].enode), ENULL); }
#line 5031 "y.tab.c"
    break;

  case 232: /* term: '@' K_CHR '(' e ')'  */
#line 1402 "gram.y"
                                  { (yyval.enode) = new(CHR, (yyvsp[-1].enode), ENULL);}
#line 5037 "y.tab.c"
    break;

  case 233: /* term: '@' K_ERR  */
#line 1403 "gram.y"
                                  { (yyval.enode) = new(ERR_, ENULL, ENULL); }
#line 5043 "y.tab.c"
    break;

  case 234: /* term: K_ERR  */
#line 1404 "gram.y"
                                  { (yyval.enode) = new(ERR_, ENULL, ENULL); }
#line 5049 "y.tab.c"
    break;

  case 235: /* term: '@' K_REF  */
#line 1405 "gram.y"
                                  { (yyval.enode) = new(REF_, ENULL, ENULL); }
#line 5055 "y.tab.c"
    break;

  case 236: /* term: K_REF  */
#line 1406 "gram.y"
                                  { (yyval.enode) = new(REF_, ENULL, ENULL); }
#line 5061 "y.tab.c"
    break;

  case 237: /* term: '@' K_FACT '(' e ')'  */
#line 1407 "gram.y"
                                  { (yyval.enode) = new(FACT, (yyvsp[-1].enode), ENULL); }
#line 5067 "y.tab.c"
    break;

  case 238: /* e: e '+' e  */
#line 1411 "gram.y"
                                  { (yyval.enode) = new('+', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5073 "y.tab.c"
    break;

  case 239: /* e: e '-' e  */
#line 1412 "gram.y"
                                  { (yyval.enode) = new('-', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5079 "y.tab.c"
    break;

  case 240: /* e: e '*' e  */
#line 1413 "gram.y"
                                  { (yyval.enode) = new('*', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5085 "y.tab.c"
    break;

  case 241: /* e: e '/' e  */
#line 1414 "gram.y"
                                  { (yyval.enode) = new('/', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5091 "y.tab.c"
    break;

  case 242: /* e: e '%' e  */
#line 1415 "gram.y"
                                  { (yyval.enode) = new('%', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5097 "y.tab.c"
    break;

  case 243: /* e: '-' e  */
#line 1416 "gram.y"
                                  { (yyval.enode) = new('m', (yyvsp[0].enode), ENULL); }
#line 5103 "y.tab.c"
    break;

  case 244: /* e: e '^' e  */
#line 1417 "gram.y"
                                  { (yyval.enode) = new('^', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5109 "y.tab.c"
    break;

  case 246: /* e: e '?' e ':' e  */
#line 1419 "gram.y"
                                  { (yyval.enode) = new('?', (yyvsp[-4].enode), new(':', (yyvsp[-2].enode), (yyvsp[0].enode))); }
#line 5115 "y.tab.c"
    break;

  case 247: /* e: e ';' e  */
#line 1420 "gram.y"
                                  { (yyval.enode) = new(';', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5121 "y.tab.c"
    break;

  case 248: /* e: e '<' e  */
#line 1421 "gram.y"
                                  { (yyval.enode) = new('<', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5127 "y.tab.c"
    break;

  case 249: /* e: e '=' e  */
#line 1422 "gram.y"
                                  { (yyval.enode) = new('=', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5133 "y.tab.c"
    break;

  case 250: /* e: e '>' e  */
#line 1423 "gram.y"
                                  { (yyval.enode) = new('>', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5139 "y.tab.c"
    break;

  case 251: /* e: e '&' e  */
#line 1424 "gram.y"
                                  { (yyval.enode) = new('&', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5145 "y.tab.c"
    break;

  case 252: /* e: e '|' e  */
#line 1425 "gram.y"
                                  { (yyval.enode) = new('|', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5151 "y.tab.c"
    break;

  case 253: /* e: e '<' '=' e  */
#line 1426 "gram.y"
                                  { (yyval.enode) = new('!', new('>', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5157 "y.tab.c"
    break;

  case 254: /* e: e '<' '>' e  */
#line 1428 "gram.y"
                                  { (yyval.enode) = new('!', new('=', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5163 "y.tab.c"
    break;

  case 255: /* e: e '>' '=' e  */
#line 1429 "gram.y"
                                  { (yyval.enode) = new('!', new('<', (yyvsp[-3].enode), (yyvsp[0].enode)), ENULL); }
#line 5169 "y.tab.c"
    break;

  case 256: /* e: e '#' e  */
#line 1430 "gram.y"
                                  { (yyval.enode) = new('#', (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5175 "y.tab.c"
    break;

  case 257: /* expr_list: e  */
#line 1433 "gram.y"
                                  { (yyval.enode) = new(ELIST, ENULL, (yyvsp[0].enode)); }
#line 5181 "y.tab.c"
    break;

  case 258: /* expr_list: expr_list ',' e  */
#line 1434 "gram.y"
                                  { (yyval.enode) = new(ELIST, (yyvsp[-2].enode), (yyvsp[0].enode)); }
#line 5187 "y.tab.c"
    break;

  case 259: /* range: var ':' var  */
#line 1437 "gram.y"
                                  {
                                    (yyval.rval).left = (yyvsp[-2].ent);
                                    (yyval.rval).right = (yyvsp[0].ent);
                                  }
#line 5196 "y.tab.c"
    break;

  case 260: /* range: RANGE  */
#line 1441 "gram.y"
                                  { (yyval.rval) = (yyvsp[0].rval); }
#line 5202 "y.tab.c"
    break;

  case 261: /* var: COL NUMBER  */
#line 1446 "gram.y"
                                   {
                                    struct roman * roman = session->cur_doc;
                                    (yyval.ent).vp = lookat(roman->cur_sh, (yyvsp[0].ival), (yyvsp[-1].ival));
                                    (yyval.ent).vf = 0;
                                  }
#line 5212 "y.tab.c"
    break;

  case 262: /* var: '$' COL NUMBER  */
#line 1451 "gram.y"
                                  {
                                    struct roman * roman = session->cur_doc;
                                    (yyval.ent).vp = lookat(roman->cur_sh, (yyvsp[0].ival), (yyvsp[-1].ival));
                                    (yyval.ent).vf = FIX_COL;
                                  }
#line 5222 "y.tab.c"
    break;

  case 263: /* var: COL '$' NUMBER  */
#line 1456 "gram.y"
                                  {
                                    struct roman * roman = session->cur_doc;
                                    (yyval.ent).vp = lookat(roman->cur_sh, (yyvsp[0].ival), (yyvsp[-2].ival));
                                    (yyval.ent).vf = FIX_ROW;
                                  }
#line 5232 "y.tab.c"
    break;

  case 264: /* var: '$' COL '$' NUMBER  */
#line 1461 "gram.y"
                                  {
                                    struct roman * roman = session->cur_doc;
                                    (yyval.ent).vp = lookat(roman->cur_sh, (yyvsp[0].ival), (yyvsp[-2].ival));
                                    (yyval.ent).vf = FIX_ROW | FIX_COL;
                                  }
#line 5242 "y.tab.c"
    break;

  case 265: /* var: '@' K_GETENT '(' e ',' e ')'  */
#line 1468 "gram.y"
                                   {
                                    struct roman * roman = session->cur_doc;
                                    struct sheet * sh = roman->cur_sh;
                                    (yyval.ent).vp = lookat(sh, eval(sh, NULL, (yyvsp[-3].enode)), eval(sh, NULL, (yyvsp[-1].enode)));
                                    (yyval.ent).vf = GETENT;
                                    if ((yyval.ent).expr != NULL) efree((yyval.ent).expr);
                                    (yyval.ent).expr = new(GETENT, (yyvsp[-3].enode), (yyvsp[-1].enode));
                                  }
#line 5255 "y.tab.c"
    break;

  case 266: /* var: VAR  */
#line 1477 "gram.y"
                                  {
                                    (yyval.ent) = (yyvsp[0].rval).left;
                                  }
#line 5263 "y.tab.c"
    break;

  case 267: /* var_or_range: range  */
#line 1483 "gram.y"
                                  { (yyval.rval) = (yyvsp[0].rval); }
#line 5269 "y.tab.c"
    break;

  case 268: /* var_or_range: var  */
#line 1484 "gram.y"
                                  { (yyval.rval).left = (yyvsp[0].ent); (yyval.rval).right = (yyvsp[0].ent); }
#line 5275 "y.tab.c"
    break;

  case 269: /* num: NUMBER  */
#line 1487 "gram.y"
                                  { (yyval.fval) = (double) (yyvsp[0].ival); }
#line 5281 "y.tab.c"
    break;

  case 270: /* num: FNUMBER  */
#line 1488 "gram.y"
                                  { (yyval.fval) = (yyvsp[0].fval); }
#line 5287 "y.tab.c"
    break;

  case 271: /* num: '-' num  */
#line 1489 "gram.y"
                                  { (yyval.fval) = -(yyvsp[0].fval); }
#line 5293 "y.tab.c"
    break;

  case 272: /* num: '+' num  */
#line 1490 "gram.y"
                                  { (yyval.fval) = (yyvsp[0].fval); }
#line 5299 "y.tab.c"
    break;

  case 273: /* strarg: STRING  */
#line 1493 "gram.y"
                                  { (yyval.sval) = (yyvsp[0].sval); }
#line 5305 "y.tab.c"
    break;

  case 274: /* strarg: var  */
#line 1494 "gram.y"
                                  {
                                    char *s, *s1;
                                    s1 = (yyvsp[0].ent).vp->label;
                                    if (!s1)
                                    s1 = "NULL_STRING";
                                    s = scxmalloc((unsigned)strlen(s1)+1);
                                    (void) strcpy(s, s1);
                                    (yyval.sval) = s;
                                  }
#line 5319 "y.tab.c"
    break;

  case 277: /* setitem: K_OVERLAP '=' NUMBER  */
#line 1512 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "overlap=0", TRUE);
                                     else         parse_str(user_conf_d, "overlap=1", TRUE); }
#line 5326 "y.tab.c"
    break;

  case 278: /* setitem: K_OVERLAP  */
#line 1514 "gram.y"
                                  {               parse_str(user_conf_d, "overlap=1", TRUE); }
#line 5332 "y.tab.c"
    break;

  case 279: /* setitem: K_INPUT_BAR_BOTTOM '=' NUMBER  */
#line 1515 "gram.y"
                                         {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "input_bar_bottom=0", TRUE);
                                     else         parse_str(user_conf_d, "input_bar_bottom=1", TRUE);
                                                  ui_mv_bottom_bar(); }
#line 5340 "y.tab.c"
    break;

  case 280: /* setitem: K_INPUT_BAR_BOTTOM  */
#line 1518 "gram.y"
                                  {               parse_str(user_conf_d, "input_bar_bottom=1", TRUE);
                                                  ui_mv_bottom_bar();
                                  }
#line 5348 "y.tab.c"
    break;

  case 281: /* setitem: K_UNDERLINE_GRID '=' NUMBER  */
#line 1522 "gram.y"
                                     {            if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "underline_grid=0", TRUE);
                                                  else parse_str(user_conf_d, "underline_grid=1", TRUE); }
#line 5355 "y.tab.c"
    break;

  case 282: /* setitem: K_UNDERLINE_GRID  */
#line 1524 "gram.y"
                                  {               parse_str(user_conf_d, "underline_grid=1", TRUE);
                                  }
#line 5362 "y.tab.c"
    break;

  case 283: /* setitem: K_NOOVERLAP  */
#line 1527 "gram.y"
                                  {               parse_str(user_conf_d, "overlap=0", TRUE); }
#line 5368 "y.tab.c"
    break;

  case 284: /* setitem: K_TRUNCATE '=' NUMBER  */
#line 1529 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "truncate=0", TRUE);
                                     else         parse_str(user_conf_d, "truncate=1", TRUE); }
#line 5375 "y.tab.c"
    break;

  case 285: /* setitem: K_TRUNCATE  */
#line 1531 "gram.y"
                                  {               parse_str(user_conf_d, "truncate=1", TRUE); }
#line 5381 "y.tab.c"
    break;

  case 286: /* setitem: K_NOTRUNCATE  */
#line 1532 "gram.y"
                                  {               parse_str(user_conf_d, "truncate=0", TRUE); }
#line 5387 "y.tab.c"
    break;

  case 287: /* setitem: K_AUTOWRAP '=' NUMBER  */
#line 1534 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "autowrap=0", TRUE);
                                     else         parse_str(user_conf_d, "autowrap=1", TRUE); }
#line 5394 "y.tab.c"
    break;

  case 288: /* setitem: K_AUTOWRAP  */
#line 1536 "gram.y"
                                  {               parse_str(user_conf_d, "autowrap=1", TRUE); }
#line 5400 "y.tab.c"
    break;

  case 289: /* setitem: K_NOAUTOWRAP  */
#line 1537 "gram.y"
                                  {               parse_str(user_conf_d, "autowrap=0", TRUE); }
#line 5406 "y.tab.c"
    break;

  case 290: /* setitem: K_AUTOBACKUP '=' NUMBER  */
#line 1539 "gram.y"
                                  {
                                                  char cmd[MAXCMD];
                                                  sprintf(cmd, "autobackup=%d", (yyvsp[0].ival));
                                                  parse_str(user_conf_d, cmd, TRUE); }
#line 5415 "y.tab.c"
    break;

  case 291: /* setitem: K_NOAUTOBACKUP  */
#line 1543 "gram.y"
                                  {               parse_str(user_conf_d, "autobackup=0", TRUE); }
#line 5421 "y.tab.c"
    break;

  case 292: /* setitem: K_AUTOCALC  */
#line 1544 "gram.y"
                                  {               parse_str(user_conf_d, "autocalc=1", TRUE); }
#line 5427 "y.tab.c"
    break;

  case 293: /* setitem: K_AUTOCALC '=' NUMBER  */
#line 1545 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "autocalc=0", TRUE);
                                     else         parse_str(user_conf_d, "autocalc=1", TRUE); }
#line 5434 "y.tab.c"
    break;

  case 294: /* setitem: K_NOAUTOCALC  */
#line 1547 "gram.y"
                                  {               parse_str(user_conf_d, "autocalc=0", TRUE); }
#line 5440 "y.tab.c"
    break;

  case 295: /* setitem: K_DEBUG  */
#line 1548 "gram.y"
                                  {               parse_str(user_conf_d, "debug=1", TRUE); }
#line 5446 "y.tab.c"
    break;

  case 296: /* setitem: K_DEBUG '=' NUMBER  */
#line 1549 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "debug=0", TRUE);
                                     else         parse_str(user_conf_d, "debug=1", TRUE); }
#line 5453 "y.tab.c"
    break;

  case 297: /* setitem: K_NODEBUG  */
#line 1551 "gram.y"
                                  {               parse_str(user_conf_d, "debug=0", TRUE); }
#line 5459 "y.tab.c"
    break;

  case 298: /* setitem: K_TRG  */
#line 1552 "gram.y"
                                  {               parse_str(user_conf_d, "trigger=1", TRUE); }
#line 5465 "y.tab.c"
    break;

  case 299: /* setitem: K_TRG '=' NUMBER  */
#line 1553 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "trigger=0", TRUE);
                                     else         parse_str(user_conf_d, "trigger=1", TRUE); }
#line 5472 "y.tab.c"
    break;

  case 300: /* setitem: K_NOTRG  */
#line 1555 "gram.y"
                                  {               parse_str(user_conf_d, "trigger=0", TRUE); }
#line 5478 "y.tab.c"
    break;

  case 301: /* setitem: K_EXTERNAL_FUNCTIONS  */
#line 1556 "gram.y"
                                  {               parse_str(user_conf_d, "external_functions=1", TRUE); }
#line 5484 "y.tab.c"
    break;

  case 302: /* setitem: K_EXTERNAL_FUNCTIONS '=' NUMBER  */
#line 1557 "gram.y"
                                         {
                                     if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "external_functions=0", TRUE);
                                     else         parse_str(user_conf_d, "external_functions=1", TRUE); }
#line 5492 "y.tab.c"
    break;

  case 303: /* setitem: K_NOEXTERNAL_FUNCTIONS  */
#line 1560 "gram.y"
                                  {               parse_str(user_conf_d, "external_functions=0", TRUE); }
#line 5498 "y.tab.c"
    break;

  case 304: /* setitem: K_EXEC_LUA  */
#line 1561 "gram.y"
                                  {               parse_str(user_conf_d, "exec_lua=1", TRUE); }
#line 5504 "y.tab.c"
    break;

  case 305: /* setitem: K_EXEC_LUA '=' NUMBER  */
#line 1562 "gram.y"
                                  {
                                     if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "exec_lua=0", TRUE);
                                     else         parse_str(user_conf_d, "exec_lua=1", TRUE); }
#line 5512 "y.tab.c"
    break;

  case 306: /* setitem: K_NOEXEC_LUA  */
#line 1565 "gram.y"
                                  {               parse_str(user_conf_d, "exec_lua=0", TRUE); }
#line 5518 "y.tab.c"
    break;

  case 307: /* setitem: K_HALF_PAGE_SCROLL  */
#line 1566 "gram.y"
                                  {               parse_str(user_conf_d, "half_page_scroll=1", TRUE); }
#line 5524 "y.tab.c"
    break;

  case 308: /* setitem: K_HALF_PAGE_SCROLL '=' NUMBER  */
#line 1568 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "half_page_scroll=0", TRUE);
                                     else         parse_str(user_conf_d, "half_page_scroll=1", TRUE); }
#line 5531 "y.tab.c"
    break;

  case 309: /* setitem: K_NOHALF_PAGE_SCROLL  */
#line 1570 "gram.y"
                                  {               parse_str(user_conf_d, "half_page_scroll=0", TRUE); }
#line 5537 "y.tab.c"
    break;

  case 310: /* setitem: K_QUIET '=' NUMBER  */
#line 1571 "gram.y"
                                  {
                                     if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "quiet=0", TRUE);
                                     else         parse_str(user_conf_d, "quiet=1", TRUE); }
#line 5545 "y.tab.c"
    break;

  case 311: /* setitem: K_QUIET  */
#line 1574 "gram.y"
                                  {               parse_str(user_conf_d, "quiet=1", TRUE); }
#line 5551 "y.tab.c"
    break;

  case 312: /* setitem: K_NOQUIET  */
#line 1575 "gram.y"
                                  {               parse_str(user_conf_d, "quiet=0", TRUE); }
#line 5557 "y.tab.c"
    break;

  case 313: /* setitem: K_QUIT_AFTERLOAD  */
#line 1576 "gram.y"
                                  {               parse_str(user_conf_d, "quit_afterload=1", TRUE); }
#line 5563 "y.tab.c"
    break;

  case 314: /* setitem: K_QUIT_AFTERLOAD '=' NUMBER  */
#line 1578 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "quit_afterload=0", TRUE);
                                     else         parse_str(user_conf_d, "quit_afterload=1", TRUE); }
#line 5570 "y.tab.c"
    break;

  case 315: /* setitem: K_NOQUIT_AFTERLOAD  */
#line 1580 "gram.y"
                                  {               parse_str(user_conf_d, "quit_afterload=0", TRUE); }
#line 5576 "y.tab.c"
    break;

  case 316: /* setitem: K_XLSX_READFORMULAS  */
#line 1581 "gram.y"
                                  {               parse_str(user_conf_d, "xlsx_readformulas=1", TRUE); }
#line 5582 "y.tab.c"
    break;

  case 317: /* setitem: K_XLSX_READFORMULAS '=' NUMBER  */
#line 1583 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "xlsx_readformulas=0", TRUE);
                                     else         parse_str(user_conf_d, "xlsx_readformulas=1", TRUE); }
#line 5589 "y.tab.c"
    break;

  case 318: /* setitem: K_NOXLSX_READFORMULAS  */
#line 1585 "gram.y"
                                  {               parse_str(user_conf_d, "xlsx_readformulas=0", TRUE); }
#line 5595 "y.tab.c"
    break;

  case 319: /* setitem: K_NOCURSES  */
#line 1586 "gram.y"
                                  {               parse_str(user_conf_d, "nocurses=1", TRUE); }
#line 5601 "y.tab.c"
    break;

  case 320: /* setitem: K_NOCURSES '=' NUMBER  */
#line 1587 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "nocurses=0", TRUE);
                                     else         parse_str(user_conf_d, "nocurses=1", TRUE); }
#line 5608 "y.tab.c"
    break;

  case 321: /* setitem: K_CURSES  */
#line 1589 "gram.y"
                                  {               parse_str(user_conf_d, "nocurses=0", TRUE); }
#line 5614 "y.tab.c"
    break;

  case 322: /* setitem: K_NUMERIC  */
#line 1590 "gram.y"
                                  {               parse_str(user_conf_d, "numeric=1", TRUE); }
#line 5620 "y.tab.c"
    break;

  case 323: /* setitem: K_NUMERIC '=' NUMBER  */
#line 1591 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "numeric=0", TRUE);
                                     else         parse_str(user_conf_d, "numeric=1", TRUE); }
#line 5627 "y.tab.c"
    break;

  case 324: /* setitem: K_NONUMERIC  */
#line 1593 "gram.y"
                                  {               parse_str(user_conf_d, "numeric=0", TRUE); }
#line 5633 "y.tab.c"
    break;

  case 325: /* setitem: K_IGNORECASE  */
#line 1594 "gram.y"
                                  {               parse_str(user_conf_d, "ignorecase=1", TRUE); }
#line 5639 "y.tab.c"
    break;

  case 326: /* setitem: K_IGNORECASE '=' NUMBER  */
#line 1595 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "ignorecase=0", TRUE);
                                     else         parse_str(user_conf_d, "ignorecase=1", TRUE); }
#line 5646 "y.tab.c"
    break;

  case 327: /* setitem: K_NOIGNORECASE  */
#line 1597 "gram.y"
                                  {               parse_str(user_conf_d, "ignorecase=0", TRUE); }
#line 5652 "y.tab.c"
    break;

  case 328: /* setitem: K_NUMERIC_DECIMAL  */
#line 1598 "gram.y"
                                  {               parse_str(user_conf_d, "numeric_decimal=1", TRUE); }
#line 5658 "y.tab.c"
    break;

  case 329: /* setitem: K_NUMERIC_DECIMAL '=' NUMBER  */
#line 1600 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "numeric_decimal=0", TRUE);
                                     else         parse_str(user_conf_d, "numeric_decimal=1", TRUE); }
#line 5665 "y.tab.c"
    break;

  case 330: /* setitem: K_NONUMERIC_DECIMAL  */
#line 1602 "gram.y"
                                  {               parse_str(user_conf_d, "numeric_decimal=0", TRUE); }
#line 5671 "y.tab.c"
    break;

  case 331: /* setitem: K_NUMERIC_ZERO  */
#line 1603 "gram.y"
                                  {               parse_str(user_conf_d, "numeric_zero=1", TRUE); }
#line 5677 "y.tab.c"
    break;

  case 332: /* setitem: K_NUMERIC_ZERO '=' NUMBER  */
#line 1605 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "numeric_zero=0", TRUE);
                                     else         parse_str(user_conf_d, "numeric_zero=1", TRUE); }
#line 5684 "y.tab.c"
    break;

  case 333: /* setitem: K_NONUMERIC_ZERO  */
#line 1607 "gram.y"
                                  {               parse_str(user_conf_d, "numeric_zero=0", TRUE); }
#line 5690 "y.tab.c"
    break;

  case 334: /* setitem: K_NEWLINE_ACTION  */
#line 1608 "gram.y"
                                  {               parse_str(user_conf_d, "newline_action=0", TRUE); }
#line 5696 "y.tab.c"
    break;

  case 335: /* setitem: K_NEWLINE_ACTION '=' WORD  */
#line 1609 "gram.y"
                                   {
                                  char * s = (char *) (yyvsp[0].sval);
                                  if (s[0] =='j') parse_str(user_conf_d, "newline_action=j", TRUE);
                                  else if (s[0] =='l')
                                  parse_str(user_conf_d, "newline_action=l", TRUE);
                                  }
#line 5707 "y.tab.c"
    break;

  case 336: /* setitem: K_DEFAULT_COPY_TO_CLIPBOARD_CMD '=' strarg  */
#line 1615 "gram.y"
                                                    {
                                  char cmd[MAXCMD];
                                  char * s = (char *) (yyvsp[0].sval);
                                  sprintf(cmd, "default_copy_to_clipboard_cmd=%s", s);
                                  parse_str(user_conf_d, cmd, FALSE);
                                  scxfree(s);
                                  }
#line 5719 "y.tab.c"
    break;

  case 337: /* setitem: K_DEFAULT_PASTE_FROM_CLIPBOARD_CMD '=' strarg  */
#line 1622 "gram.y"
                                                       {
                                  char cmd[MAXCMD];
                                  char * s = (char *) (yyvsp[0].sval);
                                  sprintf(cmd, "default_paste_from_clipboard_cmd=%s", s);
                                  parse_str(user_conf_d, cmd, FALSE);
                                  scxfree(s);
                                  }
#line 5731 "y.tab.c"
    break;

  case 338: /* setitem: K_COPY_TO_CLIPBOARD_DELIMITED_TAB  */
#line 1630 "gram.y"
                                           {      parse_str(user_conf_d, "copy_to_clipboard_delimited_tab=1", TRUE); }
#line 5737 "y.tab.c"
    break;

  case 339: /* setitem: K_COPY_TO_CLIPBOARD_DELIMITED_TAB '=' NUMBER  */
#line 1633 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "copy_to_clipboard_delimited_tab=0", TRUE);
                                     else         parse_str(user_conf_d, "copy_to_clipboard_delimited_tab=1", TRUE); }
#line 5744 "y.tab.c"
    break;

  case 340: /* setitem: K_NOCOPY_TO_CLIPBOARD_DELIMITED_TAB  */
#line 1635 "gram.y"
                                             {    parse_str(user_conf_d, "copy_to_clipboard_delimited_tab=0", TRUE); }
#line 5750 "y.tab.c"
    break;

  case 341: /* setitem: K_NEWLINE_ACTION '=' NUMBER  */
#line 1637 "gram.y"
                                     {
                                     if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "newline_action=0", TRUE); }
#line 5757 "y.tab.c"
    break;

  case 342: /* setitem: K_COMMAND_TIMEOUT  */
#line 1639 "gram.y"
                                  {               parse_str(user_conf_d, "command_timeout=3000", TRUE); }
#line 5763 "y.tab.c"
    break;

  case 343: /* setitem: K_COMMAND_TIMEOUT '=' num  */
#line 1640 "gram.y"
                                     {
                                     char * s = scxmalloc((unsigned) BUFFERSIZE);
                                     sprintf(s, "command_timeout=%d", (int) (yyvsp[0].fval));
                                     parse_str(user_conf_d, s, TRUE);
                                     scxfree(s);
                                     }
#line 5774 "y.tab.c"
    break;

  case 344: /* setitem: K_MAPPING_TIMEOUT  */
#line 1646 "gram.y"
                                  {               parse_str(user_conf_d, "mapping_timeout=1500", TRUE); }
#line 5780 "y.tab.c"
    break;

  case 345: /* setitem: K_MAPPING_TIMEOUT '=' num  */
#line 1647 "gram.y"
                                     {
                                     char * s = scxmalloc((unsigned) BUFFERSIZE);
                                     sprintf(s, "mapping_timeout=%d", (int) (yyvsp[0].fval));
                                     parse_str(user_conf_d, s, TRUE);
                                     scxfree(s);
                                     }
#line 5791 "y.tab.c"
    break;

  case 346: /* setitem: K_TM_GMTOFF  */
#line 1653 "gram.y"
                                  {               parse_str(user_conf_d, "tm_gmtoff=-10800", TRUE); }
#line 5797 "y.tab.c"
    break;

  case 347: /* setitem: K_TM_GMTOFF '=' num  */
#line 1654 "gram.y"
                                  {
                                     char * s = scxmalloc((unsigned) BUFFERSIZE);
                                     sprintf(s, "tm_gmtoff=%d", (int) (yyvsp[0].fval));
                                     parse_str(user_conf_d, s, TRUE);
                                     scxfree(s);
                                  }
#line 5808 "y.tab.c"
    break;

  case 348: /* setitem: K_SHOW_CURSOR '=' NUMBER  */
#line 1660 "gram.y"
                                  {  if ((yyvsp[0].ival) == 0) parse_str(user_conf_d, "show_cursor=0", TRUE);
                                     else         parse_str(user_conf_d, "show_cursor=1", TRUE); }
#line 5815 "y.tab.c"
    break;

  case 349: /* setitem: K_SHOW_CURSOR  */
#line 1662 "gram.y"
                                  {               parse_str(user_conf_d, "show_cursor=1", TRUE); }
#line 5821 "y.tab.c"
    break;

  case 350: /* setitem: K_NOSHOW_CURSOR  */
#line 1663 "gram.y"
                                  {               parse_str(user_conf_d, "show_cursor=0", TRUE); }
#line 5827 "y.tab.c"
    break;


#line 5831 "y.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

