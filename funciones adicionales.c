#include "mylib.h"

int velocimetro(int velocidad_actual,int velocidad_esperada)
{
    if(velocidad_actual<velocidad_esperada)return 1;
    if(velocidad_actual==velocidad_esperada)return 0;
    if(velocidad_actual>velocidad_esperada)return -1;
}

int caja_de_cambios(int RPM,int cambio,int max, int min)
{
   if(RPM>max) return cambio=cambio+1;
   if(RPM<min) return cambio=cambio-1;
   return cambio;
}

int medidor_RPM(int RPM,int max, int min)
{
    if(RPM>max)  return RPM=min;
    if(RPM<min)  return RPM=max;
    return RPM;
}


int estacionar(void)
{
int mapa[15][15],i=0,j=0,x,y,coord[2][2],toma,dx,dy,tx,ty,x2,y2,contador=0,espacio=0;
char op[10]="hola";
float velocidad;
int distancia;

int tramos[2][2];
int tramo;
int punto;

    //inicializo
    printf("\n");

    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(i==7&&j==7)
            {
                mapa[i][j]=1;
            }
            else
            {
                mapa[i][j]=0;
            }

            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }
    printf("Para la funcion estacionar se deben seguir varios pasos para eso cada ves que se vuelve al sistema central se debe volver al bloque de desicion hasta que el bloque de desicion declare: Estacionamiento exitoso o bien no haya lugar para estacionar\n");


    printf("\npara poder estacionar primero se debe averiguar si hay algun espacio libre para ubicar al vehiculo, para eso es necesario dibujar, con rectas el contorno del estacionamiento, para poder dibujar cada linea se debe marcar sus puntos origen y extremo(por ejemplo extremo=(x=-2,y=0) y origen=(x=-2,y=5),no importa el sentido, el contorno de la linea se representa con 1. Para poder marca el/los lugares vacios , solamente se debe dejar esa parte del contorno sin dibujar y solamente puede haber lugares vacios en los laterales del auto, es decir a izquierda y derecha.Por ejemplo si se marcan las lineas:\n");
     printf("L1,(-2,5)y(2,5)\n");
     printf("L2,(2,5)y(2,-5)\n");
     printf("L3,(-2,5)y(-2,-5)\n");
     printf("la linea horizontal que estaria por debajo del vehiculo no hay que diagramarla");
     printf("se diagramo el estacionamiento pero no hay ningun lugar vacio\n en cambio si diagramamos las mismas lineas pero modificamos la L1,por ejemplo, (la del ejemplo anterior) y la dividimos en dos:");
     printf("L1.1,(-2,-5)y(-2,1)\n");
     printf("L1.2,(-2,4)y(-2,5)\n");
     printf("los puntos (-2,2) y (-2,3) van a valer 0, por lo tanto y porque estan a la izquierda del vehiculo, el mismo los considera espacios vacios para poder estacionar\n");
     printf("El grosor del contorno debe ser de un punto ,es decir , no se puede dibujar una linea y al lado otra, ya que puede no llegar a detectarse bien los espacios");
     printf("Una ves finalizado el diagrama, contestar si a la pregunta terminado\n");
     printf("si se va a usar el ejemplo anote las coordenadas porque se van a borrar en el proceso de diagramas las lineas ya se volveria mas incomodo");
    printf("\nDETECTANDO ENTORNO\n");
    system("pause");
    system("cls");
    while(strcmp(op,"si")!=0)
    {
        for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }

     printf("origen:\nx=");
     scanf("%d",&x);
     printf("y=");
     scanf("%d",&y);
     mapa[7-y][x+7]=1;

     printf("extremo:\nx=");
     scanf("%d",&x2);
     printf("y=");
     scanf("%d",&y2);
     mapa[7-y][x+7]=1;
     system("cls");

     for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }
         if(y2>y) dy=1;
         else dy=-1;
         if(y2==y)dy=0;

         if(x2>x)dx=1;
         else dx=-1;
         if(x2==x)dx=0;

         //printf("dx=%d,dy=%d\n",dx,dy);

         while(x2!=x||y2!=y)
         {
             y=y+dy;
             x=x+dx;
             mapa[7-y][x+7]=1;
         }

    system("pause");
    system("cls");

    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }
    printf("\nterminado?");
    fflush(stdin);
    gets(op);

    }

    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {

           if(mapa[i][j]==1)
           {
               contador++;
           }
           if(i==7&&j==7)
           {
               contador=contador-1;

           }
        }
        if(contador==1)
        {
            espacio=espacio+1;
        }
        contador=0;

    }

    if(espacio>=1)
    {
        printf("hay lugar\n");

        system("pause");
        return bloque_desicion;
    }
    else
    {
        printf("no hay lugar\nEstacionamiento fallido\n");
        guardar(0,7);
        guardar_bfs(0,0);
        system("pause");
        return sistema_central;
    }

}

int esquivar(void)
{
int mapa[15][15],i=0,j=0,x,y,coord[2][2],toma,dx,dy,tx,ty,x2,y2,tipo;
char opcion[10]="hola";
float velocidad;
int distancia,velocidad_esperada;
int estado=sistema_central;



    //inicializo
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(i==7&&j==7)
            {
                mapa[i][j]=1;
            }
            else
            {
                mapa[i][j]=0;
            }

            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }





//movimiento

printf("deteccion de obstaculos en movimiento relativo al vehiculo:\n");
printf("Por medio de dos tomas se va a analizar el movimiento de un objeto desconocido en relacion al vehiculo autonomo, es un movimiento relativo ya que no se esta midiendo desde un punto fijo ,ya que el centro de coordenadas es el mismo auto autonomo por lo tanto puede estar en movimiento \n");
printf("estos dos tomas , son las distintas posiciones que tiene el auto en funcion de la posicion del vehiculo autonomo y del tiempo. Con estas dos tomas es suficiente para calcular su movimiento relativo\n");
system("pause");
system("cls");
for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }
 for(toma=0;toma<2;toma++)
 {
        printf("X=");
        scanf("%d",&x);
        printf("Y=");
        scanf("%d",&y);
        coord[toma][0]=x;
        coord[toma][1]=y;

        //para visualizar
        x=x+7;
        y=7-y;
        mapa[y][x]=1;
        printf("siguiente toma");
        //impresion
        system("cls");
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }
 }

    int x0=coord[0][0],x1=coord[1][0],y0=coord[0][1],y1=coord[1][1];
    dx=x1-x0;
    dy=y1-y0;
    //printf("dx:%d,  dy:%d\n",dx,dy);
    //CHOQUES
        if(dx==0)
        {
            if(dy<0&&y0>0&&x1==0||dy>0&&y0<0&&x1==0)
            {
                tipo=1;
                printf("choque tipo:%d\n",tipo);
                system("pause");
                estado=volante;
                guardar(45,5);
            }
        }
        if(dy==0)
        {
            if(dx<0&&x0>0&&y1==0||dx>0&&x0<0&&y1==0)
            {
                tipo=2;
                printf("choque tipo:%d\n",tipo);
                system("pause");
                estado=sist_central_velocidades;
            }
        }
        if(dy!=0&&dx!=0)
        {
            if((x0/dx)==(y0/dy))
            {
                tipo=2;
                printf("choque tipo:%d\n",tipo);
                system("pause");
                estado=sist_central_velocidades;
            }
        }
        printf("\n");
        if(tipo==2)
        {
            velocidad_esperada=recu(1);
            guardar(velocidad_esperada*4/5,1);
        }

        velocidad=3.6*sqrt(pow(7*dx,2)+pow(7*dy,2));
        distancia=sqrt(pow(x1,2)+pow(y1,2));
    printf("velocidad relativa del objeto:%.1fkm/hs,  %.1fm/s,   distancia al objeto:%dm\n",velocidad,velocidad/3.6,distancia);
    system("pause");
    system("cls");
printf("calculando estrategia:\n");
printf("En esta instancia se va a detectar si hay algun obstaculo por ejemplo el cordon de una vereda o otros autos estacionados, esto va a pemitir que el vehiculo , en caso que deba doblar, no se choque con lo antes mencionado al tratar de esquivar el objeto en movimiento. Este tipo de obstaculo de diagrama como una linea vertical al lado del vehiculo. Para diagramar la linea solo se debe ubicar el extremo y origen de la misma, no importa el sentido, al igual que en el estacionamiento\n");
printf("por ejemplo:linea:((-1,5),(-1,-5))\n");
printf("DETECCION: OBJETOS DEL ENTORNO:\n");
system("pause");
system("cls");

for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }
     printf("extremo:\nx=");
     scanf("%d",&x);
     printf("y=");
     scanf("%d",&y);
     mapa[7-y][x+7]=1;

     system("cls");
     for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }


     printf("origen:\nx=");
     scanf("%d",&x2);
     printf("y=");
     scanf("%d",&y2);
     mapa[7-y][x+7]=1;
     system("pause");
    system("cls");




     for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }
    system("pause");
    system("cls");
         if(y2>y) dy=1;
         else dy=-1;
         if(y2==y)dy=0;

         if(x2>x)dx=1;
         else dx=-1;
         if(x2==x)dx=0;

         //printf("dx=%d,dy=%d\n",dx,dy);

         while(x2!=x||y2!=y)
         {
             y=y+dy;
             x=x+dx;
             mapa[7-y][x+7]=1;
         }

     for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %d ",mapa[i][j]);
        }
        printf("\n");
    }
    system("pause");
    system("cls");


    int sentido;
    if(mapa[7][8]!=0||mapa[7][6]!=0)
    {

    if(mapa[7][8]==1)sentido=1;
    if(mapa[7][6]==1)sentido=-1;

    int giro;
    giro=recu(5);
    giro=sentido*giro;
    guardar(giro,5);
}
   //imprimida
if(tipo==1)
    {
        printf("se debe doblar para esquivar al objetivo y pasar al otro carril,caso contrario choque asegurado\n");
        system("pause");
    }
    if(tipo==2)
    {
        printf("se debe reducir la velocidad para esquivar al objetivo y pasar al otro carril,caso contrario choque asegurado\n");
        system("pause");
    }

    return estado;
}





void tablero(int velocidad,int RPM,int velocimetro,int cambio)
{
    printf("**********************************************************************************************************************************************************************\n\n\n");
    printf("\n\n\n\n\n\n\t\t\t\tvelocidad:%.3dKm/h\t\t\t\t\t\t\t\t\tRPM:%.4d\n\n\n\n\n\n\n",velocidad,RPM);
    if(velocimetro==-1)
    {
        printf("\t\t\t\t\tfrenos:activo\t\t\t\tacelerador:desactivo\n\n\n\n");
    }
    if(velocimetro==1)
    {
        printf("\t\t\t\t\t\tfrenos:desactivo\t\t\t\tacelerador:activo\n\n\n\n");

    }
    if(velocimetro==0)
    {
        printf("\t\t\t\t\tfrenos:desactivo\t\t\t\tacelerador:desactivo\n\n\n\n");
    }
    printf("\t\t\t\t\t\t\t\tcaja de cambios:%d\n\n\n",cambio),
    printf("**********************************************************************************************************************************************************************\n\n\n");
}

void menu(void)
{

    printf("*** Menu: tecnologias ***\n");
    printf("camara\n");
    printf("motor\n");
    printf("parabrisas\n");
    printf("bloque_desicion\n");
    //printf("radar\n");
    printf("bloqueo\n");
    printf("GPS\n");
    printf("motor\n");
    printf("busca_fallas\n");
    printf("giroscopio\n\n");

}


