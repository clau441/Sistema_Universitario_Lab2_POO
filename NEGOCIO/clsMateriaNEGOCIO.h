#ifndef CLSMATERIANEGOCIO_H
#define CLSMATERIANEGOCIO_H


#include "../DAO/clsMateriaDAO.h"
#include "../DTO/clsMateriaDTO.h"
#include "../HELPERS/clsCadenas.h"


class clsMateriaNegocio{
    public:
        void Insertar(clsMateriaDTO);
        void Eliminar(int);
        void Modificar(clsMateriaDTO);
        void Listar(clsMateriaDTO *);
        int Count();

        void BuscarSub(clsMateriaDTO *, char *);
        int BuscarSubCount(char *);
        int BuscarID(int);

        void ModificarMateria(int, char *);
        void ModificarProfresor(int, char *);
};

#endif // CLSMATERIANEGOCIO_H
