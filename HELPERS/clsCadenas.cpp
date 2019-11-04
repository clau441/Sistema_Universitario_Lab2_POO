#include "clsCadenas.h"
#include <iostream>
#include <cstdio>

using namespace std;

///PEGAR LA FUNCION DE STRSUB
int clsCadenas::strSub(char *c, char *s)
{
    char cad[100];
    char sub[100];
    strcpy(cad, c);
    strcpy(sub, s);
    strToUpper(cad);
    strToUpper(sub);
    int ic=0, is, tamSub;

    tamSub=strlen(sub);
    while(cad[ic]!='\0')
    {
        int icAux=ic;
        is=0;
        while(sub[is]==cad[icAux] && sub[is]!='\0')
        {
            icAux++;
            is++;
        }
        if(tamSub==is)
        {
            return ic;
        }
        ic++;
    }
    return -1;
}

void clsCadenas::strToUpper(char *cad)
{
    int i=0;
    while(cad[i]!='\0')
    {
        if(cad[i]>='a' && cad[i]<='z')
        {
            cad[i]=cad[i]-32;
        }
        i++;
    }
}
