#include "LinkedListController.h"
#define	SINGLE	257
#define	DOUBLE	258
#define	TRIPLE	259
#define	SINGLEANGLE	260
#define	DOUBLEANGLE	261
#define	MEASURE	262
#define	CONTROL	263
#define	ENDCONTROL	264
#define	PMEASURE	265
#define	INT	266
#define	FLOAT	267
#define	ENDLINE	268
#define	DAGGER	269
#define	QINIT	270
#define	CREG	271
#define	ENDDAGGER	272


extern YYSTYPE yylval;
int yyparse(QList & qList);