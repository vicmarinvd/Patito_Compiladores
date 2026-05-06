%{
#include "patito.tab.h"
#include <stdio.h>

extern int yylineno;
int errlexicos = 0;
%}

%option yylineno

/* Digitos y letras */
digito      [0-9]
letra       [a-zA-Z]
guion [_]

/* Constantes, id y string */
ID          ({letra}|{guion})({letra}|{digito}|{guion})*
CTE_ENT     {digito}+
CTE_FLT     {digito}+\.{digito}+
LETRERO     \"[^\"\n]*\"
BLANCOS     [ \t\n\r]+

%%

"programa"   { return PROGRAM;  }
"vars"       { return VARS;     }
"inicio"     { return INICIO;   }
"fin"        { return FIN;      }
"si"         { return SI;       }
"sino"       { return SINO;     }
"mientras"   { return MIENTRAS; }
"haz"        { return HAZ;      }
"escribe"    { return ESCRIBE;  }
"entero"     { return ENTERO;   }
"flotante"   { return FLOTANTE; }
"nula"       { return NULA;     }

{CTE_FLT}   { return CTE_FLT; }
{CTE_ENT}   { return CTE_ENT; }

{ID}        { return ID; }

{LETRERO}   { return LETRERO; }

"=="        { return OPEQ;  }
"!="        { return OPNEQ; }
">"         { return OPGT;  }
"<"         { return OPLT;  }
"+"         { return '+';   }
"-"         { return '-';   }
"*"         { return '*';   }
"/"         { return '/';   }
"="         { return '=';   }
";"         { return ';';   }
","         { return ',';   }
"("         { return '(';   }
")"         { return ')';   }
"{"         { return '{';   }
"}"         { return '}';   }
":"         { return ':';   }

{BLANCOS}   { }

. {
  fprintf(stderr,
    "[Error Lexico] Linea %d: caracter no reconocido '%s'\n",
    yylineno, yytext);
  errlexicos++;
}

%%

int yywrap(void) { return 1; }
