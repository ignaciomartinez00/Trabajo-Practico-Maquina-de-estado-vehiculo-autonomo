#include "mylib.h"

void inicio(void)
{
    FILE *fp;
    fp=fopen("parametros.txt","wt");//como la maquina de estado se enciende 1 ves sola y se mantiene encerrado para borrar todo antes de volver a entrar
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
    while(!feof(fp))  //preguntamos si no es fin de archivo (clase 8)
    {
        if(bf.posicion==posicion)
        {

            fclose(fp);
            return;
        }
        fread(&bf,sizeof(struct guardado),1,fp);
    }//estoy en el final del archivo
    bf.posicion=posicion;
    bf.variable=valor[posicion];
    fflush(stdin);
    fwrite(&bf,sizeof(struct guardado),1,fp);//grabo todo lo anterior, solo lo puedo grabar porque tengo el + en rb+. clase 8
    fclose(fp);
    }
}

int recu(int posicion_dentro_del_archivo)
{
    struct guardado bf;
    FILE *fp;
    int valor;

    fp=fopen("parametros.txt","rb+"); //ponerle if y todo eso de validacion
    fread(&bf,sizeof(struct guardado),1,fp);
    while(!feof(fp))  //preguntamos si no es fin de archivo (clase 8)
    {
        if(bf.posicion==posicion_dentro_del_archivo)
        {
                valor=bf.variable;
        }
        fread(&bf,sizeof(struct guardado),1,fp);
    }//estoy en el final del archivo
    fclose(fp);
    return valor;
}

int guardar(int valor,int posicion)  //pasar a void
{
    struct guardado bf;
    FILE *fp;
    fp=fopen("parametros.txt","rb+"); //ponerle if y todo eso de validacion
    fread(&bf,sizeof(struct guardado),1,fp);
    while(!feof(fp))  //preguntamos si no es fin de archivo (clase 8)
    {
        if(bf.posicion==posicion)
        {
            bf.variable=valor;
            //printf("variable:%04d\tposicion:%04d  \n",bf.variable,bf.posicion); //muestro los datos del legajo a modificar
            fflush(stdin);
            break;
        }
    fread(&bf,sizeof(struct guardado),1,fp);
    }
    fseek(fp,(-1L)*sizeof(struct guardado),1);
    fwrite(&bf,(1L)*sizeof(struct guardado),1,fp);

    fclose(fp);
    return valor;  ///VER si es void
}
