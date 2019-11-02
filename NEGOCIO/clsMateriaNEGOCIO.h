#ifndef CLSMATERIANEGOCIO_H
#define CLSMATERIANEGOCIO_H


#include "../DAO/clsMateriaDAO.h"
#include "../DTO/clsMateriaDTO.h"


class clsMateriaNegocio
{
    public:
        void Insertar(clsMateriaDTO);
        void Eliminar(int);
        void Modificar(clsMateriaDTO);
        void Listar(clsMateriaDTO *);
        int Count();
};

#endif // CLSMATERIANEGOCIO_H
