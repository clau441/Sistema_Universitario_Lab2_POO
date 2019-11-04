#ifndef CLSMATERIADAO_H
#define CLSMATERIADAO_H

#include <cstdio>
#include "../DTO/clsMateriaDTO.h"
#include "../HELPERS/clsCadenas.h"

char const ARCHIVO_MATERIA[]="ARCHIVOS_MATERIAS.DAT";

class clsMateriaDAO
{
    public:
        void Insertar(clsMateriaDTO);
        void Eliminar(int);
        void Modificar(clsMateriaDTO);
        void Listar(clsMateriaDTO *);
        int Count();

        void BuscarSub(clsMateriaDTO *, char *);
        int BuscarSubCount(char*);
        int BuscarID(int);

        void ModificarMateria(int, char *);
        void ModificarProfesor(int, char *);
};


#endif // CLSMATERIADAO_H
