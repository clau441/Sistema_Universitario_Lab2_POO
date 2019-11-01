#ifndef CLSMATERIADAO_H
#define CLSMATERIADAO_H

#include <cstdio>
#include "../DTO/clsMateriaDTO.h"

char const ARCHIVO_MATERIA[]="ARCHIVOS_MATERIAS.DAT";

class clsMateriaDAO
{
    public:
        void Insertar(clsMateriaDTO);
        void Eliminar(int);
        void Modificar(clsMateriaDTO);
        void Listar(clsMateriaDTO *);
        int Count();
};


#endif // CLSMATERIADAO_H
