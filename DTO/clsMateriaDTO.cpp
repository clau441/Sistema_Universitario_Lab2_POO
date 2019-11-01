#include "clsMateriaDTO.h"

///CONSTRUCTOR
clsMateriaDTO::clsMateriaDTO()
{
    this->Eliminado=false;
}

void clsMateriaDTO::Copy(clsMateriaDTO dto)
{
    char nombre[50];
    char profesor[50];
    this->ID=dto.GetID();
    dto.GetNombre(nombre);
    strcpy(this->Nombre,nombre);
    dto.GetProfesor(profesor);
    strcpy(this->Profesor, profesor);
}
