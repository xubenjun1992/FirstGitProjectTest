
/*  A Bison parser, made from y.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	SINGLE	257
#define	DOUBLE_T	258
#define	TRIPLE	259
#define	SINGLEANGLE	260
#define	DOUBLEANGLE	261
#define	MEASURE	262
#define	CONTROL	263
#define	ENDCONTROL	264
#define	PMEASURE	265
#define	INT_T	266
#define	FLOAT_T	267
#define	ENDLINE	268
#define	DAGGER	269
#define	QINIT	270
#define	CREG	271
#define	ENDDAGGER	272

#line 1 "y.y"

    #include "parser.h"
    #include "ERROR_INFO.h"
    #include <cstring>
    #include <cmath>
	#include <vector>
	#include "LinkedListController.h"
    
    extern "C" 
    {
        void yyerror(const char *s);
        void yywrap();
        void yyabort(const char *s);
        extern int yylex(void);  
        
	};

    int qNum=0;
    int cNum=0;
	int allyylineno;
	extern int yylineno;
	using std::vector;
    vector<int> vecint_pmeasure_list;
	vector<size_t> controlList_vector;
	vector<size_t> endcontrolList_vector;
    QList _G_qList;
    
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		87
#define	YYFLAG		-32768
#define	YYNTBASE	29

#define YYTRANSLATE(x) ((unsigned)(x) <= 272 ? yytranslate[x] : 43)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    27,     2,    24,     2,     2,     2,    25,
    26,    21,    19,    28,    20,     2,    22,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    23,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     4,     8,    12,    14,    17,    20,    26,    29,    32,
    34,    36,    39,    44,    51,    58,    67,    70,    74,    76,
    80,    82,    86,    88,    90,    92,    96,   100,   102,   106,
   110,   112,   116,   120,   123,   126,   128
};

static const short yyrhs[] = {    30,
    31,    32,     0,    16,    12,    14,     0,    17,    12,    14,
     0,    33,     0,    32,    33,     0,    34,    14,     0,     8,
    12,    28,    24,    12,     0,     9,    36,     0,    10,    37,
     0,    15,     0,    18,     0,     3,    12,     0,     4,    12,
    28,    12,     0,     5,    12,    28,    12,    28,    12,     0,
     6,    12,    28,    27,    38,    27,     0,     7,    12,    28,
    12,    28,    27,    38,    27,     0,    11,    35,     0,    35,
    28,    12,     0,    12,     0,    36,    28,    12,     0,    12,
     0,    37,    28,    12,     0,    12,     0,    39,     0,    40,
     0,    39,    19,    40,     0,    39,    20,    40,     0,    41,
     0,    40,    21,    41,     0,    40,    22,    41,     0,    42,
     0,    41,    23,    42,     0,    25,    39,    26,     0,    20,
    42,     0,    19,    42,     0,    12,     0,    13,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    40,    58,    66,    74,    76,    81,    86,   115,   122,   129,
   137,   149,   164,   179,   194,   209,   224,   234,   247,   261,
   273,   287,   299,   313,   317,   318,   319,   323,   324,   325,
   337,   338,   350,   351,   352,   353,   354
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","SINGLE",
"DOUBLE_T","TRIPLE","SINGLEANGLE","DOUBLEANGLE","MEASURE","CONTROL","ENDCONTROL",
"PMEASURE","INT_T","FLOAT_T","ENDLINE","DAGGER","QINIT","CREG","ENDDAGGER","'+'",
"'-'","'*'","'/'","'^'","'$'","'('","')'","'\\\"'","','","file","qinit","cinit",
"gatelist","gate","gateline","pmeasure_list","controll_list","endcontroll_list",
"angle","additive","multiplicative","exp","primary", NULL
};
#endif

static const short yyr1[] = {     0,
    29,    30,    31,    32,    32,    33,    34,    34,    34,    34,
    34,    34,    34,    34,    34,    34,    34,    35,    35,    36,
    36,    37,    37,    38,    39,    39,    39,    40,    40,    40,
    41,    41,    42,    42,    42,    42,    42
};

static const short yyr2[] = {     0,
     3,     3,     3,     1,     2,     2,     5,     2,     2,     1,
     1,     2,     4,     6,     6,     8,     2,     3,     1,     3,
     1,     3,     1,     1,     1,     3,     3,     1,     3,     3,
     1,     3,     3,     2,     2,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    10,    11,     1,     4,
     0,     3,    12,     0,     0,     0,     0,     0,    21,     8,
    23,     9,    19,    17,     5,     6,     0,     0,     0,     0,
     0,     0,     0,     0,    13,     0,     0,     0,     0,    20,
    22,    18,     0,    36,    37,     0,     0,     0,     0,    24,
    25,    28,    31,     0,     7,    14,    35,    34,     0,    15,
     0,     0,     0,     0,     0,     0,    33,    26,    27,    29,
    30,    32,     0,    16,     0,     0,     0
};

static const short yydefgoto[] = {    85,
     2,     5,    19,    20,    21,    34,    30,    32,    59,    60,
    61,    62,    63
};

static const short yypact[] = {    -3,
    12,    10,    17,    22,    -1,-32768,    21,    24,    25,    26,
    27,    28,    29,    30,    31,    32,-32768,-32768,    -1,-32768,
    33,-32768,-32768,    18,    20,    23,    34,    35,-32768,    36,
-32768,    37,-32768,    38,-32768,-32768,    40,    41,    42,    43,
    44,    45,    46,    47,-32768,    39,     3,    48,    49,-32768,
-32768,-32768,    58,-32768,-32768,     3,     3,     3,    50,     1,
     4,    51,-32768,    52,-32768,-32768,-32768,-32768,    -8,-32768,
     3,     3,     3,     3,     3,     3,-32768,     4,     4,    51,
    51,-32768,    53,-32768,    54,    56,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,    59,-32768,-32768,-32768,-32768,   -31,    -9,
   -42,   -41,   -56
};


#define	YYLAST		80


static const short yytable[] = {    67,
    68,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    71,    72,     1,    17,    54,    55,    18,    77,    82,    71,
    72,    56,    57,     3,    73,    74,     4,    58,    78,    79,
     6,    80,    81,     7,    22,    23,    24,    25,    26,    27,
    28,    29,    31,    33,    83,    37,    36,    38,    69,     0,
    39,    45,    46,    86,    48,    87,    50,    51,    52,     0,
    65,    40,    41,    42,    43,    44,    53,    49,    47,    66,
     0,     0,     0,    75,     0,    64,    70,    35,    76,    84
};

static const short yycheck[] = {    56,
    57,     3,     4,     5,     6,     7,     8,     9,    10,    11,
    19,    20,    16,    15,    12,    13,    18,    26,    75,    19,
    20,    19,    20,    12,    21,    22,    17,    25,    71,    72,
    14,    73,    74,    12,    14,    12,    12,    12,    12,    12,
    12,    12,    12,    12,    76,    28,    14,    28,    58,    -1,
    28,    12,    12,     0,    12,     0,    12,    12,    12,    -1,
    12,    28,    28,    28,    28,    28,    28,    24,    27,    12,
    -1,    -1,    -1,    23,    -1,    28,    27,    19,    27,    27
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(QList &qList)
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 41 "y.y"
{
    //extern int daggerLevel;
    //if (daggerLevel>0)
    //{
    //    yyerror(NO_ENDDAGGER_ERROR);
    //}
    //extern ControllerList controllerList;
    //if (controllerList.size()>0)
    //{
    //    yyerror(NO_ENDCONTROL_ERROR);
    //}
    //extern GateList gateList;
    //gateList.insertEnd();    
;
    break;}
case 2:
#line 59 "y.y"
{
    extern int qNum;
    qNum=yyvsp[-1].iInteger;
	allyylineno++;
    break;}
case 3:
#line 67 "y.y"
{
    extern int cNum;
    cNum=yyvsp[-1].iInteger;
	allyylineno++;
    break;}
case 4:
#line 75 "y.y"
{;
    break;}
case 5:
#line 77 "y.y"
{;
    break;}
case 6:
#line 82 "y.y"
{;
    break;}
case 7:
#line 87 "y.y"
{
	
    yyval.sId="";
    if (yyvsp[-3].iInteger<qNum)
    {
        if (yyvsp[0].iInteger<cNum)
        {
            //extern GateList gateList;
            //extern ControllerList controllerList;
            //extern int daggerLevel;
            //if (controllerList.size()!=0 || daggerLevel!=0 )
            //{
            //    yyerror(MEASURE_IN_CONTROL_ERROR);
            //  }
            //MeasureInsert(gateList,$2,$5);
			_G_qList.measureInsert(yyvsp[-4].iGateName,yyvsp[-3].iInteger,yyvsp[0].iInteger);
			allyylineno++;
        }
        else
        {
            yyerror(CREG_OUT_OF_BOUNDS_ERROR);
        }
    }
    else
    { 
        yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
    }
	
;
    break;}
case 8:
#line 116 "y.y"
{
    yyval.sId="";
	extern vector<size_t> controlList_vector;
	_G_qList.ControlInsert1(controlList_vector);
	controlList_vector.clear();
	allyylineno++;
	
;
    break;}
case 9:
#line 123 "y.y"
{
    yyval.sId="";
	extern vector<size_t> endcontrolList_vector;
	_G_qList.ControlDelete1(endcontrolList_vector);
	endcontrolList_vector.clear();
	allyylineno++;
	
    break;}
case 10:
#line 130 "y.y"
{
    yyval.sId="";
    //extern int daggerLevel;
    //daggerLevel++;  
	_G_qList.daggerInsert();
	allyylineno++;
;
    break;}
case 11:
#line 138 "y.y"
{
    yyval.sId="";
    //extern int daggerLevel;
    //if (daggerLevel<=0)
    //{
    //    yyerror(EXTRA_ENDDAGGER_ERROR);
    //}
    //daggerLevel--;
	_G_qList.daggerDelete();
	allyylineno++;
;
    break;}
case 12:
#line 150 "y.y"
{
    yyval.sId="";
    if (yyvsp[0].iInteger<qNum)
    {    
        //extern GateList gateList;
        //SingleGateInsert(gateList,$1,$2);
		_G_qList.gateInsert(yyvsp[-1].iGateName,yyvsp[0].iInteger);
		allyylineno++;
    }
    else
    {
        yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
    }
	
;
    break;}
case 13:
#line 165 "y.y"
{
    yyval.sId=""; 
    if (yyvsp[-2].iInteger<qNum && yyvsp[0].iInteger<qNum )
    {
        //extern GateList gateList;
        //DoubleGateInsert(gateList,$1,$2,$4);
		_G_qList.gateInsert(yyvsp[-3].iGateName,yyvsp[-2].iInteger,yyvsp[0].iInteger);
		allyylineno++;
    }
    else
    {
        yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
    }
	
;
    break;}
case 14:
#line 180 "y.y"
{
    yyval.sId="";
    if (yyvsp[-4].iInteger<qNum && yyvsp[-2].iInteger<qNum && yyvsp[0].iInteger<qNum )
    {
        //extern GateList gateList;
        //TripleGateInsert(gateList,$1,$2,$4,$6);
		_G_qList.gateInsert(yyvsp[-5].iGateName,yyvsp[-4].iInteger,yyvsp[-2].iInteger,yyvsp[0].iInteger);
		allyylineno++;
    }
    else
    {
        yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
    }
   
;
    break;}
case 15:
#line 195 "y.y"
{
    yyval.sId="";
    if (yyvsp[-4].iInteger<qNum)
    {
        //extern GateList gateList;
        //SingleAngleGateInsert(gateList,$1,$2,$5);
		_G_qList.angleGateInsert(yyvsp[-5].iGateName,yyvsp[-4].iInteger,yyvsp[-1].dDouble);
		allyylineno++;
    }
    else
    {
        yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
    }
	
;
    break;}
case 16:
#line 210 "y.y"
{
    yyval.sId="";
    if (yyvsp[-6].iInteger<qNum && yyvsp[-4].iInteger<qNum)
    {
        //extern GateList gateList;
        //DoubleAngleGateInsert(gateList,$1,$2,$4,$7);
		_G_qList.angleGateInsert(yyvsp[-7].iGateName,yyvsp[-6].iInteger,yyvsp[-4].iInteger,yyvsp[-1].dDouble);
		allyylineno++;
    }
    else
    {
        yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
    }
	
;
    break;}
case 17:
#line 225 "y.y"
{
	extern vector<int> vecint_pmeasure_list;
	_G_qList.pmeasureInsert(vecint_pmeasure_list);
	vecint_pmeasure_list.clear();
;
    break;}
case 18:
#line 235 "y.y"
{
	if(yyvsp[0].iInteger < qNum) 
	{
		extern vector<int> vecint_pmeasure_list;
		vecint_pmeasure_list.push_back(yyvsp[0].iInteger);

	}else 
	{
		yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
	}
    
;
    break;}
case 19:
#line 248 "y.y"
{
	if(yyvsp[0].iInteger < qNum) 
	{
		extern vector<int> vecint_pmeasure_list;
		vecint_pmeasure_list.push_back(yyvsp[0].iInteger);
	}else 
	{
		yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
	}
;
    break;}
case 20:
#line 262 "y.y"
{
	if(yyvsp[0].iInteger < qNum)
	{
		extern vector<size_t> controlList_vector;
		controlList_vector.push_back(yyvsp[0].iInteger);
	}else
	{
		yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
	}

;
    break;}
case 21:
#line 274 "y.y"
{
	if(yyvsp[0].iInteger < qNum)
	{
		extern vector<size_t> controlList_vector;
		controlList_vector.push_back(yyvsp[0].iInteger);
	}else
	{
		yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
	}
;
    break;}
case 22:
#line 288 "y.y"
{
	if(yyvsp[0].iInteger < qNum)
	{
		extern vector<size_t> endcontrolList_vector;
		endcontrolList_vector.push_back(yyvsp[0].iInteger);
	}else
	{
		yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
	}

;
    break;}
case 23:
#line 300 "y.y"
{
	if(yyvsp[0].iInteger < qNum)
	{
		extern vector<size_t> endcontrolList_vector;
		endcontrolList_vector.push_back(yyvsp[0].iInteger);
	}else
	{
		yyerror(QUBIT_OUT_OF_BOUNDS_ERROR);
	}
;
    break;}
case 24:
#line 313 "y.y"
{ yyval.dDouble = yyvsp[0].dDouble; ;
    break;}
case 25:
#line 317 "y.y"
{ yyval.dDouble = yyvsp[0].dDouble; ;
    break;}
case 26:
#line 318 "y.y"
{ yyval.dDouble = yyvsp[-2].dDouble + yyvsp[0].dDouble; ;
    break;}
case 27:
#line 319 "y.y"
{ yyval.dDouble = yyvsp[-2].dDouble + yyvsp[0].dDouble; ;
    break;}
case 28:
#line 323 "y.y"
{ yyval.dDouble = yyvsp[0].dDouble; ;
    break;}
case 29:
#line 324 "y.y"
{ yyval.dDouble = yyvsp[-2].dDouble * yyvsp[0].dDouble; ;
    break;}
case 30:
#line 326 "y.y"
{
    yyval.dDouble= yyvsp[-2].dDouble / yyvsp[0].dDouble;
    using std::isnormal;
    if (!isnormal(yyval.dDouble))
    {
        yyerror(ANGLE_ERROR);
    }
;
    break;}
case 31:
#line 337 "y.y"
{ yyval.dDouble = yyvsp[0].dDouble; ;
    break;}
case 32:
#line 339 "y.y"
{
    yyval.dDouble = pow(yyvsp[-2].dDouble,yyvsp[0].dDouble);
    using std::isnormal;
    if (!isnormal(yyval.dDouble))
    {
        yyerror(ANGLE_ERROR);
    }
;
    break;}
case 33:
#line 350 "y.y"
{ yyval.dDouble = yyvsp[-1].dDouble; ;
    break;}
case 34:
#line 351 "y.y"
{ yyval.dDouble = -yyvsp[0].dDouble; ;
    break;}
case 35:
#line 352 "y.y"
{ yyval.dDouble = yyvsp[0].dDouble; ;
    break;}
case 36:
#line 353 "y.y"
{ yyval.dDouble = yyvsp[0].iInteger; ;
    break;}
case 37:
#line 354 "y.y"
{ yyval.dDouble = yyvsp[0].dDouble; ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 357 "y.y"

bool parserFailure=false;

void yyerror(const char* msg)
{
    parserFailure=true;
    
    std::cout<<"ERROR LINE: "<<yylineno<<std::endl<<"ERROR MESSAGE: ";
    
    if (strcmp(msg,"")==0)
    {
        printf("Unknown Characters!\n");
    }
    else if (strcmp(msg,"syntax error")==0)
    {
        printf("Unknown Characters!\n");
    }
    else
    {
        printf("%s\n",msg);
    }
}

#include <cstdio>

















