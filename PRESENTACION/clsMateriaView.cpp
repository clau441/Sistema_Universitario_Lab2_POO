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
        cout<<"\t\t\t\t||     A- Alta de Materia                               ||"<<endl;
        cout<<"\t\t\t\t||     B- Baja de Materia                               ||"<<endl;
        cout<<"\t\t\t\t||     C- Modificacion de Materia                              ||"<<endl;
        cout<<"\t\t\t\t||     D- Listado de Materias               ||"<<endl;
        cout<<"\t\t\t\t||     S- Salir                                  ||"<<endl;
        cout<<"\t\t\t\t ================================================="<<endl;
        cout<<"\t\t\t\t Ingrese una opcion: ";
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 'A':
        case 'a':
            {

            }break;
        case 'B':
        case 'b':
            {

            }
            break;
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
    clsValidaciones val;

    system("cls");
    cout<<"----------------NUEVA MATERIA-------------"<<endl;
    val.ValidarRequerido("Ingrese el Nombre de la MATERIA a dar de alta: ",nombre,50);



    cout<<"Ingrese el Profesor a cargo de la MATERIA: ";
    cin.getline(profesor, 50);
    ///VALIDACION QUE NO PUEDE INGRESAR NUMERO EN UN NOMBRE NI ESPACIOS VACIOS
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    bl.Insertar(dto);
}
