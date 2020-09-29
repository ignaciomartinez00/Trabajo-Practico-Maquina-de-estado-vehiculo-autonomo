#include "mylib.h"

void inicio(void)
{
    FILE *fp;
    fp=fopen("parametros.txt","wt");
    alta();
}

void alta(void)
{
    struct guardado bf;
    FILE *fp;
    int variable,posicion=1;
    int valor[8]={0,0,0,1,110,0,1,0};
    for(posicion=1;posicion<8;posicion++)
    {
    fflush(stdin);
    if((fp=fopen("parametros.txt","rb+"))==NULL)
    {
        printf("no se puede abrir el archivo parametros.txt\n");
        system("pause");
        return;
    }
    system("cls");
    fflush(stdin);
    fread(&bf,sizeof(struct guardado),1,fp);
    while(!feof(fp))
    {
        if(bf.posicion==posicion)
        {

            fclose(fp);
            return;
        }
        fread(&bf,sizeof(struct guardado),1,fp);
    }
    bf.posicion=posicion;
    bf.variable=valor[posicion];
    fflush(stdin);
    fwrite(&bf,sizeof(struct guardado),1,fp);
    fclose(fp);
    }
}

int recu(int posicion_dentro_del_archivo)
{
    struct guardado bf;
    FILE *fp;
    int valor;

    fp=fopen("parametros.txt","rb+");
    fread(&bf,sizeof(struct guardado),1,fp);
    while(!feof(fp))
    {
        if(bf.posicion==posicion_dentro_del_archivo)
        {
                valor=bf.variable;
        }
        fread(&bf,sizeof(struct guardado),1,fp);
    }
    fclose(fp);
    return valor;
}

int guardar(int valor,int posicion)
{
    struct guardado bf;
    FILE *fp;
    fp=fopen("parametros.txt","rb+");
    fread(&bf,sizeof(struct guardado),1,fp);
    while(!feof(fp))
    {
        if(bf.posicion==posicion)
        {
            bf.variable=valor;
            //printf("variable:%04d\tposicion:%04d  \n",bf.variable,bf.posicion);
            fflush(stdin);
            break;
        }
    fread(&bf,sizeof(struct guardado),1,fp);
    }
    fseek(fp,(-1L)*sizeof(struct guardado),1);
    fwrite(&bf,(1L)*sizeof(struct guardado),1,fp);

    fclose(fp);
    return valor;
}
