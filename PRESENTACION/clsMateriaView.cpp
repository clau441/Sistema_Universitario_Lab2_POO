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
        cout<<"\t\t\t\t||     M- Modificacion de Materia                              ||"<<endl;
        cout<<"\t\t\t\t||     L- Listado de Materias               ||"<<endl;
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
                this->Insertar();
            }break;
        case 'B':
        case 'b':
            {
                //this->Eliminar();
            }
            break;
        case 'M':
        case 'm':
            {
                this->Modificar();
            }break;
        case 'L':
        case 'l':
            {
                this->Listar();
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
    clsValidaciones val;

    system("cls");
    cout<<"----------------NUEVA MATERIA-------------"<<endl;
    val.ValidarRequerido("Ingrese el Nombre de la MATERIA a dar de alta: ",nombre,50);
    val.ValidarRequerido("Ingrese el Profesor a cargo de la MATERIA: ",profesor,50);

    ///VALIDACION QUE NO PUEDE INGRESAR NUMERO EN UN NOMBRE NI ESPACIOS VACIOS
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    bl.Insertar(dto);
}

void clsMateriaView::Modificar()
{
    clsMateriaNegocio bl;
    clsValidaciones val;
    clsMateriaView view;
    char id[50];
    system("cls");
    cout<<"-----------MODIFICAR MATERIA-----------"<<endl;
    val.ValidarNumerico("Ingrese el ID de la materia a modificar: ", id, 50);
    int IDint=atoi(id);
    if(bl.BuscarID(IDint))
    {
        cout<<"ID DE MATERIA VALIDO!!!"<<endl;
        cin.ignore();
    }
    else{
        cout<<"ID DE MATERIA INVALIDO!!!"<<endl;
    }
    view.SubModificar(IDint);
}


void clsMateriaView::Listar()
{
    clsMateriaNegocio bl;
    char condicion[50];
    system("cls");
    cout<<"----------LISTADO DE MATERIAS----------"<<endl;
    cout<<"Ingrese la materia: ";
    cin.getline(condicion, 50);
    int c=bl.BuscarSubCount(condicion);
    clsMateriaDTO* lista=(clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*c );
    bl.BuscarSub(lista, condicion);
    char nombre[50];
    char profesor[50];
    for(int x=0; x<c;x++)
    {
        lista[x].GetNombre(nombre);
        lista[x].GetProfesor(profesor);
        cout<<setw(30)<<lista[x].GetID()<<setw(30)<<nombre<<setw(30)<<profesor<<endl;
    }
}

void clsMateriaView::SubModificar(int Id)
{
    clsValidaciones val;
    clsMateriaNegocio neg;
    char materia[50];
    char profesor[50];
    char opChar[50];
    system("cls");
    bool salir=false;
    while(!salir)
    {
    cout<<"------¿QUE DATO DESEA MODIFICAR?-----"<<endl;
    cout<<"|1-Materia                          |"<<endl;
    cout<<"|2-Profesor                         |"<<endl;
    cout<<"|0-salir                            |"<<endl;
    cout<<"-------------------------------------"<<endl;
    val.ValidarNumerico("Ingrese la opcion: ", opChar, 50);
    int opInt=atoi(opChar);
    switch(opInt)
    {
    case 1:
        {
            val.ValidarRequerido("Ingrese el nuevo nombre de materia: ",materia, 50);
            neg.ModificarMateria(Id, materia);
        }break;
    case 2:
        {
            val.ValidarRequerido("Ingrese el nuevo nombre de profesor: ",profesor, 50);
            neg.ModificarProfresor(Id, profesor);
        }break;
    case 0:
        {
            salir=true;
        }break;
    default:
        {
            cout<<"Opcion invalida!!!"<<endl;
        }break;
    }
    }
}
