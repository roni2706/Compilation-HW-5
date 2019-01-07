%{
	/* Declarations section */
	#include "parser.hpp"
	#include "output.hpp"
	#include "parser.tab.hpp"
%}

%option yylineno
%option noyywrap

relation  			((<)|(>)|(<=)|(>=))
equalizer			((==)|(!=))
multiplication		([*/])
addition			([+-])
string				(\"([^\n\r\"\\]|\\[rnt"\\])+\")
comment				(\/\/[^\r\n]*[\r|\n|\r\n]?)
whitespace			([\t ])
newLine				([\n\r]|\r\n)


%%
void					{
							yylval.str = new string(yytext);  
							return VOID;
						}
int						{
							yylval.str = new string(yytext);  
							return INT;
						}
byte					{
							yylval.str = new string(yytext);  
							return BYTE;
						}
b 						return B;
bool					{
							yylval.str = new string(yytext);  
							return BOOL;
						}
struct					return STRUCT;
and						return AND;
or						return OR;
not						return NOT;
true					return TRUE;
false					return FALSE;
return					return RETURN;
if						return IF;
else					return ELSE;
while					return WHILE;
break					return BREAK;
continue				return CONTINUE;
;						return SC;
,						return COMMA;
\.						return PERIOD;
\(						return LPAREN;
\)						return RPAREN;
\{						return LBRACE;
\}						return RBRACE;
\=						return ASSIGN;
{equalizer}				return EQ;
{relation}				return REL;
{multiplication}		return MUL;
{addition}				return ADD;
[a-zA-Z][a-zA-Z0-9]*	{
							yylval.str = new string(yytext);  
							return ID;
						}
0|[1-9][0-9]*			{
							char* endptr;
							yylval.num = (int)(strtol(yytext,&endptr,10));
							return NUM;
						}
{string}				{
							yylval.str = new string(yytext);  
							return STRING;
						}
{comment}				;
{whitespace}			;
{newLine}				;
<<EOF>>					return EF;
.						{
							output::errorLex(yylineno); 
							exit(1);
						}
%%
