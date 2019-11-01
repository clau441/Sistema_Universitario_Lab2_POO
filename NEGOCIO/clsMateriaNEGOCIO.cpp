#include "clsMateriaNEGOCIO.h"
void clsMateriaNegocio::Insertar(clsMateriaDTO dto)
{
    clsMateriaDAO dao;
    int id=dao.Count()+1;
    dto.SetID(id);
    dto.SetEliminado(false);
    dao.Insertar(dto);
    ///MOSTRAR SI SE PUDO INSERTAR O NO
}

void clsMateriaNegocio::Eliminar(int id)
{
    clsMateriaDAO dao;
    dao.Eliminar(id);///VER SI ESTA ELIMINADO O NO PRIMERO
}

void clsMateriaNegocio::Modificar(clsMateriaDTO dto)
{
    clsMateriaDAO dao;
    dao.Modificar(dto);
}

void clsMateriaNegocio::Listar(clsMateriaDTO *lista)
{
    clsMateriaDAO dao;
    dao.Listar(lista);
}

int clsMateriaNegocio::Count()
{
    clsMateriaDAO dao;
    return dao.Count();
}
