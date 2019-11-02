#include "clsValidaciones.h"

bool clsValidaciones::IsNumber(char*cad){
    bool result=true;
    int i=0;
    while(cad[i]!='\0'){
        if(cad[i]<'0' || cad[i]>'9'){
            result=false;
        }
        i++;
    }
    return result;
}

void clsValidaciones::ValidarRequerido(char *texto,char *out,int tam){
    bool reintentar;
    do{
        int i=0;
        reintentar=true;
        cout << texto;
        cin.getline(out,tam);
        while(out[i]!='\0'){
            if( (out[i]>='a' && out[i]<'z') ||  (out[i]>='A' && out[i]<'Z') ){
                reintentar=false;
            }
            i++;
        }
    }while(reintentar);
}

void clsValidaciones::ValidarNumerico(char *texto,char *out,int tam){
    bool reintentar=true;
    while(reintentar){
        int i=0;
        reintentar=true;
        cout << texto;
        cin.getline(out, tam);

        reintentar = !IsNumber(out);
    }
}
