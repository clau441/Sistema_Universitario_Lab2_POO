#ifndef CLSMATERIAVIEW_H
#define CLSMATERIAVIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsMateriaDTO.h"
#include "../NEGOCIO/clsMateriaNEGOCIO.h"
#include "../HELPERS/clsValidaciones.h"

using namespace std;

class clsMateriaView
{
    public:
        void Menu();
        void Insertar();
        void Listar();
        //void Eliminar();
        void Modificar();
        void SubModificar(int);
};

#endif // CLSMATERIAVIEW_H
