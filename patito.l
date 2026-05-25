%{
#include "patito.tab.h"
#include <stdio.h>

extern int yylineno;
int errores_lexicos = 0;
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

{CTE_FLT} { strncpy(yylval.sval, yytext, 63); yylval.sval[63] = '\0'; return CTE_FLT; }
{CTE_ENT} { strncpy(yylval.sval, yytext, 63); yylval.sval[63] = '\0'; return CTE_ENT; }

{ID}      { strncpy(yylval.sval, yytext, 63); yylval.sval[63] = '\0'; return ID; }

{LETRERO} { strncpy(yylval.sval, yytext, 63); yylval.sval[63] = '\0'; return LETRERO; }

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
  errores_lexicos++;
}

%%

int yywrap(void) { return 1; }
