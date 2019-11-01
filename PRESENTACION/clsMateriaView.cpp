#include "clsMateriaView.h"


void clsMateriaView::Menu()
{
    char op;
    bool salir=false;
    while(!salir)
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t ================================================="<<endl;
        cout<<"\t\t\t\t||                MENU MATERIAS                 ||"<<endl;
        cout<<"\t\t\t\t ================================================="<<endl;
        cout<<"\t\t\t\t||     N- Alta de Materia                               ||"<<endl;
        cout<<"\t\t\t\t||     N- Baja de Materia                               ||"<<endl;
        cout<<"\t\t\t\t||     N- Modificacion de Materia                              ||"<<endl;
        cout<<"\t\t\t\t||     N- Listado de Materias               ||"<<endl;
        cout<<"\t\t\t\t||     S- Salir                                  ||"<<endl;
        cout<<"\t\t\t\t ================================================="<<endl;
        cout<<"\t\t\t\t Ingrese una opcion: ";
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 'N':
        case 'n':
            {

            }break;
        case 's':
        case 'S':
            {
                salir=true;
            }break;
        default:
            {
                cout<<"OPCION INCORRECTA!!!";
            }break;
        }
        cin.get();
    }
}

void clsMateriaView::Insertar()
{
    char nombre[50];
    char profesor[50];
    clsMateriaDTO dto;
    clsMateriaNegocio bl;

    system("cls");
    cout<<"----------------NUEVA MATERIA-------------"<<endl;
    cout<<"Ingrese un nombre: ";
    cin.getline(nombre, 50);
    cout<<endl;
    cout<<"Ingrese un profesor: ";
    cin.getline(profesor, 50);
    ///VALIDACION QUE NO PUEDE INGRESAR NUMERO EN UN NOMBRE NI ESPACIOS VACIOS
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    bl.Insertar(dto);
}
