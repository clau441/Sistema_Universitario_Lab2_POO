#ifndef CLSMATERIADTO_H
#define CLSMATERIADTO_H

#include <cstring>

class clsMateriaDTO
{
    private:
        int ID;
        char Nombre[50];
        char Profesor[50];
        bool Eliminado;
    public:
        ///CONSTRUCTOR
        clsMateriaDTO();
        ///SETS
        void SetID(int val) { ID = val; }
        void SetNombre(char* val) { strcpy(Nombre, val); }
        void SetProfesor(char* val) { strcpy(Profesor, val); }
        void SetEliminado(bool val) { Eliminado = val; }
        ///GETS
        int GetID() { return ID; }
        void GetNombre(char* val) { strcpy(val, Nombre); }
        void GetProfesor(char* val) { strcpy(val, Profesor); }
        bool GetEliminado() { return Eliminado; }
        ///UNA COPIA DE UNA ENTIDAD DEL MISMO TIPO POR PARAMETRO
        void Copy(clsMateriaDTO);
};

#endif // CLSMATERIADTO_H
