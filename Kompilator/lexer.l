%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int stepen16(int a)
{
  int pom = 1, t = a;
  while(a > 0)
    {
      pom *= 16;
      t--;
    }

  return pom;
}

int broj(char c)
{
  switch (c)
    {
    case 'A':
      return 10;
    case 'B':
      return 11;
    case 'C':
      return 12;
    case 'D' :
      return 13;
    case 'E':
      return 14;
    case 'F':
      return 15;
    default:
      return  c - '0';
    }
}

int pretvori(char* s)
{
  int i = strlen(s)-1, j = 0;
  int pom = 0;

  while(i > 1)
    {
      pom += stepen16(j) * broj(s[i]);
      j++;
      i--;
    }
  return pom;
}

#include "naredba.hpp"
#include "funkcije.hpp"
#include "parser.tab.hpp"

%}
%%
pocetak                  return pocetak_token;
kraj                     return kraj_token;
ispisi                   return ispisi_token;
unesi                    return unesi_token;
mod                      return mod_token;
ako_je                   return ako_token;
onda                     return onda_token;
inace                    return inace_token;
dok_je                   return dok_token;
radi_sledece             return radi_token;
ponavljaj                return ponavljaj_token;
za                       return za_token;
funkcija                 return funkcija_token;
vrati                    return vrati_token;
==                       return jednako_token;
\<=                      return manjeJednako_token;
>=                       return veceJednako_token;
!=                       return razlicito_token;
[+/*.,;()":=><-]         return *yytext;
[A-Z][A-Za-z0-9_-]+      yylval.s = new string(yytext); return imeFunkcije_token; 
[a-z]                    yylval.c = *yytext; return id_token;
[0-9]+                   yylval.broj = atoi(yytext); return num_token;
0x[0-9A-E]+              yylval.broj = pretvori(yytext); return num_token;
\"[^"]*\"                yylval.s = new string(strndup(yytext+1, strlen(yytext)-2)); return tekst_token;
[\n \t]                  {}
.                        {
                            cout << "Leksicka greska : " << *yytext << endl;
                            exit(1);
			 }

%%
