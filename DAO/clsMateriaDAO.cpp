#include "clsMateriaDAO.h"

void clsMateriaDAO::Insertar(clsMateriaDTO dto)
{
    FILE *p;
    p=fopen(ARCHIVO_MATERIA, "ab");
    if(p!=NULL)
    {
        fwrite(&dto,sizeof(clsMateriaDTO),1,p);
        fclose(p);
    }
}
void clsMateriaDAO::Eliminar(int id)
{
    FILE *p;
    clsMateriaDTO dto;
    int pos=0;
    p=fopen(ARCHIVO_MATERIA, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            if(dto.GetID()==id && !dto.GetEliminado())
            {
                dto.SetEliminado(true);
                fseek(p,sizeof(clsMateriaDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMateriaDTO),1,p);
                break;
            }
            pos++;
        }
        fclose(p);
    }

}
void clsMateriaDAO::Modificar(clsMateriaDTO dto)
{
    FILE *p;
    clsMateriaDTO dto_arch;
    int pos=0;
    p=fopen(ARCHIVO_MATERIA, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            if(dto_arch.GetID()==dto.GetID() && !dto_arch.GetEliminado())
            {
                fseek(p,sizeof(clsMateriaDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMateriaDTO),1,p);
                break;
            }
            pos++;
        }
        fclose(p);
    }
}
void clsMateriaDAO::Listar(clsMateriaDTO *dto)
{
    FILE *p;
    int pos=0;
    clsMateriaDTO dto_arch;
    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {

        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            if(!dto_arch.GetEliminado())
            {
                dto[pos].Copy(dto_arch);
                pos++;
            }
        }
        fclose(p);
    }
}
int clsMateriaDAO::Count()
{
    FILE *p;
    int cant=0;
    clsMateriaDTO dto;
    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            if(!dto.GetEliminado())
            {
                cant++;
            }
        }
        fclose(p);
    }
    return cant;
}

void clsMateriaDAO::BuscarSub(clsMateriaDTO *dto, char *cond)
{
    FILE *p;
    int pos=0;
    char nombre[50];
    clsMateriaDTO dto_arch;
    clsCadenas cadenas;
    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {

        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            dto_arch.GetNombre(nombre);
            if(!dto_arch.GetEliminado() && cadenas.strSub(nombre, cond)>=0)///-1 si no lo encontro o positivo si lo encontro
            {
                dto[pos].Copy(dto_arch);
                pos++;
            }
        }
        fclose(p);
    }
}
int clsMateriaDAO::BuscarSubCount(char *cond)
{
    FILE *p;
    int cant=0;
    char nombre[50];
    clsMateriaDTO dto;
    clsCadenas cadenas;
    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            dto.GetNombre(nombre);
            if(!dto.GetEliminado() && cadenas.strSub(nombre, cond)>=0)
            {
                cant++;
            }
        }
        fclose(p);
    }
    return cant;

}

int clsMateriaDAO::BuscarID(int id)
{
    FILE *p;
    bool encontrado=false;
    clsMateriaDTO dto;
    p=fopen(ARCHIVO_MATERIA, "rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            if(!dto.GetEliminado() && id==dto.GetID())
            {
                encontrado=true;
            }
        }
        fclose(p);
    }
    return encontrado;
}

void clsMateriaDAO::ModificarMateria(int Id, char *materia)
{
    FILE *p;
    clsMateriaDTO dto_arch;
    int pos=0;
    p=fopen(ARCHIVO_MATERIA, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            if(dto_arch.GetID()==Id && !dto_arch.GetEliminado())
            {
                fseek(p, sizeof(clsMateriaDTO)*pos,SEEK_SET);
                dto_arch.SetNombre(materia);
                fwrite(&dto_arch,sizeof(clsMateriaDTO),1,p);
                break;
            }
            pos++;
        }
        fclose(p);
    }
}

void clsMateriaDAO::ModificarProfesor(int Id, char *profesor)
{
    FILE *p;
    clsMateriaDTO dto_arch;
    int pos=0;
    p=fopen(ARCHIVO_MATERIA, "rb+");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            if(dto_arch.GetID()==Id && !dto_arch.GetEliminado())
            {
                fseek(p, sizeof(clsMateriaDTO)*pos,SEEK_SET);
                dto_arch.SetProfesor(profesor);
                fwrite(&dto_arch,sizeof(clsMateriaDTO),1,p);
                break;
            }
            pos++;
        }
        fclose(p);
    }
}
