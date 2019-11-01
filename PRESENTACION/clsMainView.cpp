#include "clsMainView.h"

void clsMainView::Menu()
{
    char op;
    bool salir=false;
    while(!salir)
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t ================================================="<<endl;
        cout<<"\t\t\t\t||                MENU PRINCIPAL                 ||"<<endl;
        cout<<"\t\t\t\t ================================================="<<endl;
        cout<<"\t\t\t\t||     M- MATERIAS                               ||"<<endl;
        cout<<"\t\t\t\t||     S- Salir                                  ||"<<endl;
        cout<<"\t\t\t\t ================================================="<<endl;
        cout<<"\t\t\t\t Ingrese una opcion: ";
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 'm':
        case 'M':
            {
                clsMateriaView matView;
                matView.Menu();
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

