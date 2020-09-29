#include "mylib.h"

void inicio_bfs(void)
{
    FILE *fp;
    fp=fopen("parametros_bfs.txt","wt");//como la maquina de estado se enciende 1 ves sola y se mantiene encerrado para borrar todo antes de volver a entrar
    alta_bfs();
}

void alta_bfs(void)  ///bf=busca_fallas
{
    struct guardado_bfs bf;
    FILE *fp;
    int variable,posicion=0;
    int valor[8]={0,100,20,1,0,0,0,0};
    for(posicion=0;posicion<8;posicion++)
    {
    fflush(stdin);
    if((fp=fopen("parametros_bfs.txt","rb+"))==NULL)
    {
        printf("no se puede abrir el archivo parametros.txt\n");
        system("pause");
        return;
    }
    system("cls");
    fflush(stdin);
    fread(&bf,sizeof(struct guardado_bfs),1,fp);
    while(!feof(fp))  //preguntamos si no es fin de archivo (clase 8)
    {
        if(bf.posicion==posicion)
        {
            fclose(fp);
            return;
        }
        fread(&bf,sizeof(struct guardado_bfs),1,fp);
    }//estoy en el final del archivo
    bf.posicion=posicion;
    bf.variable=valor[posicion];
    fflush(stdin);
    fwrite(&bf,sizeof(struct guardado_bfs),1,fp);//grabo todo lo anterior, solo lo puedo grabar porque tengo el + en rb+. clase 8
    fclose(fp);
    }
}

int recu_bfs(int posicion_dentro_del_archivo)
{
    struct guardado_bfs bf;
    FILE *fp;
    int valor;
    fp=fopen("parametros_bfs.txt","rb+"); //ponerle if y todo eso de validacion
    fread(&bf,sizeof(struct guardado_bfs),1,fp);
    while(!feof(fp))  //preguntamos si no es fin de archivo (clase 8)
    {
        if(bf.posicion==posicion_dentro_del_archivo)
        {
                valor=bf.variable;
        }
        fread(&bf,sizeof(struct guardado_bfs),1,fp);
    }//estoy en el final del archivo
    fclose(fp);
    return valor;
}

int guardar_bfs(int valor,int posicion)  //pasar a void
{
    struct guardado_bfs bf;
    FILE *fp;
    fp=fopen("parametros_bfs.txt","rb+"); //ponerle if y todo eso de validacion
    fread(&bf,sizeof(struct guardado_bfs),1,fp);
    while(!feof(fp))  //preguntamos si no es fin de archivo (clase 8)
    {
        if(bf.posicion==posicion)
        {
            bf.variable=valor;
            fflush(stdin);
            break;
        }
    fread(&bf,sizeof(struct guardado_bfs),1,fp);
    }
    fseek(fp,(-1L)*sizeof(struct guardado_bfs),1);
    fwrite(&bf,(1L)*sizeof(struct guardado_bfs),1,fp);

    fclose(fp);
    return valor;  ///VER si es void
}

