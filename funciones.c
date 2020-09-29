#include "mylib.h"

estado_p f_lectura (void)  // usar para aquellas funciones que involucran palabras en ves de numeros, son mas de una opcion a la ves
{
    int i;
    char op[30];
    char opciones[14][100]={"sistema_central","camara","sistema_central_de_velocidades","motor","combustible","parabrisas","bloque_desicion","radar","bloqueo","GPS","volante","busca_fallas","giroscopio"};//mismo orden que struct

    menu();
    printf("escriba la tecnologia a controlar:\t");
    fflush(stdin);
    gets(op);
    for(i=0;i<13;i++)
    {
        if((strcmp(op,opciones[i]))==0)
        {
            return i;
        }
    }
    printf("se desconoce tecnologia vuelva a ejecutar la accion:\n");
    system("pause");
    return sistema_central;
}

estado_p f_sistema_central (void)
{
    system("cls");
   printf("sistema central:\n");
   tablero(recu(2),recu(4),0,recu(3));
   return f_lectura();
}

estado_p f_camara (void)
{
    tablero(recu(2),recu(4),0,recu(3));
   printf("camara:\nTipos de obstaculos:reductor de velocidad(escribir: reductor)- desconocido - semaforo - cruce - ninguno \nobstaculo detectado:");
   char op[20];
   fflush(stdin);
   gets(op);
   int posicion=6;
   guardar_bfs(0,6);
   if((strcmp(op,"semaforo"))==0)return semaforo;
   if((strcmp(op,"alerta"))==0||(strcmp(op,"ninguno"))==0)return sistema_central;
   if((strcmp(op,"reductor"))==0)
   {
       guardar(20,1);
       guardar_bfs(1,6);
       printf("se debe reducir la velocidad a 20Km/h por el reductor\n");
       system("pause");
       return sist_central_velocidades;
   }
   if((strcmp(op,"cruce"))==0||(strcmp(op,"desconocido"))==0)
   {


    guardar(1,6);

    return radar;
   }
   if((strcmp(op,"cruce"))!=0&&(strcmp(op,"desconocido"))!=0&&(strcmp(op,"reductor"))!=0&&(strcmp(op,"alerta"))!=0&&(strcmp(op,"vacio"))!=0)
   {
       printf("error\nvuelva a detectar:\n");
       return camara;
   }
   return sistema_central;
}

estado_p f_sist_central_velocidades(parametros_t config)
{
   int velocidad_actual,cambio,velocidad_esperada,RPM;
   char op[20];
   FILE *fps;


  /////////////////////////////////////////////////////////////////////////////////
    int variables[5],posicion;
    struct guardado bf;
    FILE *fp;


    velocidad_esperada=recu(1);
    velocidad_actual=recu(2);
    cambio=recu(3);
    RPM=recu(4);

    if((recu_bfs(1)<config.porc_combustible||recu_bfs(2)>config.tempconf||recu_bfs(3)==0||recu_bfs(5)==1||recu_bfs(6)==1)&&velocidad_actual==0)
    {
        tablero(velocidad_actual,RPM,velocimetro(velocidad_actual,velocidad_esperada),cambio);
        printf("hay fallas o restriciones no se puede desplazar, verifique en el busca fallas el problema y luego vaya a la tecnologia a verificar si la recepcion de datos cambio para asi poder continuar\n");
        system("pause");
        return sistema_central;
    }


  /////////////////////////////////////////////////////////////////////////////////////////////////

while(velocidad_actual!=velocidad_esperada)
    {
        cambio=caja_de_cambios(RPM,cambio,config.RPMmax,config.RPMmin);
        RPM=medidor_RPM(RPM,config.RPMmax,config.RPMmin)+100*(velocimetro(velocidad_actual,velocidad_esperada));
        velocidad_actual=velocidad_actual+(velocimetro(velocidad_actual,velocidad_esperada));
        tablero(velocidad_actual,RPM,velocimetro(velocidad_actual,velocidad_esperada),cambio);///IMPRESION
        printf("sistema_central_de_velocidades (para modificar la velocidad oprimir seguidas veces enter o calquier tecla)\n");
        fflush(stdin);
        gets(op);
        system("cls");
    }
            tablero(velocidad_actual,RPM,velocimetro(velocidad_actual,velocidad_esperada),cambio);///IMPRESION


    guardar(velocidad_esperada,1);
    guardar(velocidad_actual,2);
    guardar(cambio,3);
    guardar(RPM,4);
    return sistema_central;
}

estado_p f_bloque_desicion(void)
{

   tablero(recu(2),recu(4),0,recu(3));
   int paso;
   char op[20];
   int accion,estado;
   estado_p estacionar[]={radar,sist_central_velocidades,volante,sist_central_velocidades,sist_central_velocidades,sist_central_velocidades};
paso=recu(7);
guardar_bfs(paso,0);


       while(strcmp(op,"si")!=0&&paso==0)
       {
           printf("¿desea estacionar?");
        fflush(stdin);
        gets(op);
        if(strcmp(op,"alerta")==0)return sistema_central;
        if(strcmp(op,"alerta")!=0&&strcmp(op,"si"))printf("repertir:");
       }

    if(paso==0)guardar(2,6);   ///guardo a la accion del radar (=2), para analizar el espacio de estacionamiento
    if(paso==1)guardar(20,1);
    if(paso==2)guardar(45,5);
    if(paso==3) guardar(-20,1);
    if(paso==4)guardar(0,1);
    if(paso==5)
    {
       paso=0;
       guardar_bfs(paso,0);
       guardar(paso,7);

    printf("\nestacionamiento exitosos\n");
    system("pause");
    return sistema_central;
    }

        estado=estacionar[paso];
        guardar_bfs(paso,0);
        paso++;
        printf("estacionando\n");
        guardar(paso,7);
        return estado;
       }

estado_p f_radar(void)
{
    int accion,i,j,mapa[20][20];
    estado_p estado=sist_central_velocidades;
    printf("radar\n");
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
    printf("Se esta visualizando el mapa que representa la informacion que recibe el radar, el 1 representa al origen de coordenadas del mapa (y el vehiculo autonomo en el) y tiene eje X y Y tal como los ejes cartesianos. El eje x es el horizontal y tiene sentido hacia la derecha y el eje Y es vertical y tiene sentido hacia arriba");
    printf("\n");
    system("pause");
    accion=recu(6);
    if(accion==1)
    {
        printf("\n\nesquivar:\n");
        estado=esquivar();
    }
    else
    {
        printf("estacionar");
        estado=estacionar();
    }
    return estado;
}

estado_p f_bloqueo(parametros_t config)
{
   printf("bloqueo\n");
   int contrasena=0;
   char op[20]="1234";
   fflush(stdin);
   printf("ingrese CONTRASE%cA para encender al vehiculo autonomo (pista 1234) o escriba apagar, para apagar el vehiculo:\nCONTRASE%cA:",165,165);

   while(contrasena!=config.bloqueado||strcmp(op,"apagar")!=0)
   {
       char op[20];
       fflush(stdin);
       gets(op);
       system("cls");
        contrasena=atoi(op);
       if(contrasena==config.bloqueado)
       {
       printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tBienvenido al Ford GT40 autonomo\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
       printf("encendiendo\ncargando...\n");
       system("pause");
       system("cls");
       printf("puertas desbloqueadas\ncargando...\n");
       system("pause");
       system("cls");
       printf("motor encendido\ncargando...\n");
       system("pause");
       system("cls");
       printf("luces encendidas\ncargando...\n");
       system("pause");
       system("cls");
       printf("encendiendo tablero\ncargando...\n");
       system("pause");
       system("cls");
       tablero(recu(2),recu(4),0,recu(3));
       return sistema_central;
       }
       if(strcmp(op,"apagar")==0)
       {
           tablero(recu(2),recu(4),0,recu(3));
           inicio();
       printf("apagando tablero\ncargando\n");
       system("pause");
       system("cls");
       printf("apagando motor \ncargando\n");
       system("pause");
       system("cls");
       printf("apagando luces \ncargando\n");
       system("pause");
       system("cls");
       printf("puertas bloqueadas\ncargando\n");
       system("pause");
       system("cls");
       printf("vehiculo apagado\n");
       return bloqueo;
       }
       system("cls");
       printf("error:\nvuelva a escribir accion(contrase%ca8(pista:1234) - apagar):",164);
   }
}

estado_p f_GPS(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
    int velocidad;
    char op[40];
    printf("GPS:\nvia de transporte (calle - autopista - avenida - carretera):");
            fflush(stdin);
            gets(op);
    while(strcmp(op,"alerta")!=0)
    {
            if(strcmp(op,"avenida")==0)
            {
                velocidad=config.avenida;
                break;
            }
            if(strcmp(op,"calle")==0)
            {
                velocidad=config.calle;
                break;
            }
            if(strcmp(op,"autopista")==0)
            {
                velocidad=config.autopista;
                break;
            }
            if(strcmp(op,"carretera")==0)
            {
                velocidad=config.carretera;
            break;
            }
            if(strcmp(op,"autopista")!=0&&strcmp(op,"carretera")!=0&&strcmp(op,"calle")!=0&&strcmp(op,"avenida")!=0)
            {
                printf("se desconoce la via , vuelva a indicarla");
                return GPS;
            }
            fflush(stdin);
            gets(op);
    }
    guardar(velocidad,1);
    return sist_central_velocidades;
}

estado_p f_volante(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   printf("volante:\n");
    int volante=config.angulo_volante;
    int angulo_esperado;

    angulo_esperado=recu(5);
    while(volante!=angulo_esperado)
    {
        printf("angulo a girar a %d \t",angulo_esperado);
        printf("angulo: ");
        scanf("%d",&volante);
        system("cls");
        tablero(recu(2),recu(4),0,recu(3));
        printf("volante:\n");
    }
    printf("volver a acomodar el volante para continuar:\n");
    system("pause");
    system("cls");
    tablero(recu(2),recu(4),0,recu(3));
        printf("volante:\n");
    while(volante!=config.angulo_volante)
    {
        printf("angulo a girar 0\t");
        printf("angulo: ");
        scanf("%d",&volante);
        system("cls");
        tablero(recu(2),recu(4),0,recu(3));
        printf("volante:\n");
    }
   return sistema_central;
}

estado_p f_busca_fallas(parametros_t config)
{
   printf("busca fallas:\n");


   char variables[20][30]={"pasos de la memoria: ","combustible: ","temperatura del motor: ","semaforo: ","lluvia: ","giroscopio: ","reductor"};
   int posicion,falla=0,condicion=0;

   for(posicion=0;posicion<7;posicion++)
   {

       if(posicion==0)
       {
           printf("%-30s",variables[posicion]);
           printf("%d ",recu_bfs(posicion));
           if(recu_bfs(posicion)==0||recu_bfs(posicion)==5)printf("\t, no se esta utilando");///FALTA VOLVER A INICIALIZAR A LA MEMORIA y EN EL CASO QUE EL RADAR NO DETECTE ESPACIO SE DEBE PONER EL PASO EN 0
           else
           {
               printf("\t, proceso en curso dentro del bloque de desicion");
               condicion++;
           }
       }
       if(posicion==1)
       {
           printf("%-30s",variables[posicion]);
           printf("%.3d % ",recu_bfs(posicion));
           printf("\t valores normales de esta variable:mayores a %.4d ",config.porc_combustible);
           if(recu_bfs(posicion)<config.porc_combustible)
           {
               printf("FALLA");
               falla++;
           }
       }
       if(posicion==2)
       {
           printf("%-30s",variables[posicion]);
           printf("%.5d ",recu_bfs(posicion));
           printf("\t valores normales de esta variable:menoreas a %.4d ",config.tempconf);
           if(recu_bfs(posicion)>config.tempconf)
           {
               printf("FALLA");
               falla++;
           }
       }
       if(posicion==3)
       {
           printf("%-30s",variables[posicion]);

           printf("estado de semaforo:");
           if(recu_bfs(posicion)==0)
           {
               printf("\trojo, reduccion de velocidad a 0");
               condicion++;
           }
           else printf("verde");
       }
       if(posicion==4)
       {
           printf("%-30s",variables[posicion]);
           printf("%d Volt",recu_bfs(posicion));
           printf(" tension menor a %d ",config.lluvia);
           if(recu_bfs(posicion)>config.lluvia)
           {
               printf("\tlluvia intensa, reduccion de velocidad");
               condicion++;
           }
       }
       if(posicion==5)
       {
           printf("%-30s",variables[posicion]);
           printf("el vehiculo ");
           if(recu_bfs(posicion)==1)
           {
               falla++;
               printf("\tno puede subir el angulo es muy pronunciado");
           }
           else printf("esta en un angulo permitido para desplazarse");
       }
       if(posicion==6)
       {
           printf("%-30s",variables[posicion]);

           if(recu_bfs(posicion)==1)
           {
               printf("    presencia de reductor, reduccion de velocidad");
               condicion++;
           }
           else printf("    no hay reductor");

       }
       printf("\n");
   }
       printf("\n\n");
       if(falla==0)printf("no hay fallas y");
       if(falla==1)printf("se detecto 1 falla y");
       if(falla>1)printf("se detectaron multiples fallas = %d y",falla);
        printf(" se detectaron %d condiciones que reducen la velocidad del vehiculo\n", condicion);
        system("pause");
   return sistema_central;
}

estado_p f_giroscopio(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   printf("giroscopio\n");
   int angulo,cambio,cambio_actual,fuerzaMotor,masa=784,i,menor=7,fuerzaMotorMax;
   float fuerzaG;
   int valor;
   printf("%cngulo respecto al piso:",181);
   scanf("%d",&angulo);
   fuerzaG=g*sin(angulo*pi/180)*masa;
   cambio_actual=recu(3);
   printf("cambio=%d\n",cambio);
   printf("Fuerza de la gravedad %.2f\n",fuerzaG);

   for(i=1;i<7;i++)
   {
       fuerzaMotor=config.torque/i*20;
       if(fuerzaMotor>fuerzaG)
       {
          cambio=i;
       }
   }
   fuerzaMotor=config.torque/cambio*10;
   printf("el cambio debe ser menor o igual a %d\n",cambio);
   printf("Fuerza del motor %d\n",fuerzaMotor);

    if(cambio==1)valor=11;//aproximaciones
    if(cambio==2)valor=33;
    if(cambio==3)valor=55;
    if(cambio==4)valor=77;
    if(cambio==5)valor=99;
    if(cambio==6)valor=121;

    fuerzaMotorMax=config.torque*10;
    if(fuerzaMotorMax>fuerzaG)
    {
        if(cambio_actual>cambio)
        {
        printf("el cambio debe ser menor o igual a %d\n",cambio);
        printf("Fuerza del motor %d\n",fuerzaMotor);
        cambio_actual=cambio;
        guardar(valor,1);
        guardar_bfs(0,5);
        }
    }
    if(fuerzaMotorMax<=fuerzaG)
    {
        //printf("velocidad=0");
        //valor=0;
        printf("La fuerza de gravedad en horizontal al vehiculo es mayor que la del motor, velocidad=0\n");
        guardar(0,1);
        guardar_bfs(1,5);
    }
 system("pause");
   return sist_central_velocidades;
}

estado_p f_semaforo(void)
{
    tablero(recu(2),recu(4),0,recu(3));
   char op[40];
   printf("estado del semaforo (rojo-verde)\nestado: ");
   fflush(stdin);
   gets(op);

   if(strcmp(op,"rojo")==0)
   {
    guardar_bfs(0,3);
    guardar(0,1);
    return sist_central_velocidades;
   }
   if((strcmp(op,"verde"))==0)
   {
       guardar_bfs(1,3);
       return sistema_central;
   }

   if((strcmp(op,"verde"))!=0&&(strcmp(op,"rojo"))!=0)
   {
       printf("volver a analizar");
       system("cls");
       return semaforo;
   }
}

estado_p f_motor(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   int temperatura;
   printf("motor\ntemperatura:");
   scanf("%d",&temperatura);
   guardar_bfs(temperatura,2);
   if(temperatura<config.tempconf)
   {
       printf("estable:\n");
       return estable;
   }
   else
   {
       printf("inestable:\n");
       return inestable;
   }
}

estado_p f_combustible(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   int combustible;
   printf("combustible\ningrese porcentaje de combustible:");
   scanf("%d",&combustible);
   guardar_bfs(combustible,1);
   if(combustible<config.porc_combustible)
   {
       return insuficiente;
   }
   else
   {
       return suficiente;
   }
   return sistema_central;
}

estado_p f_parabrisas(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   int lluvia;
   printf("parabrisas\nlectura(0-5)Volt. del sensor:");
   char op[30];

   while((strcmp(op,"alerta"))!=0)
   {
       fflush(stdin);
       gets(op);
       lluvia=atoi(op);
           if(lluvia>config.lluvia)
           {
               return activado;
           }
           else
           {
               return desactivado;
           }
   }
   return sistema_central;
}

estado_p f_estable(void)
{
    tablero(recu(2),recu(4),0,recu(3));
    char op[30];
    int temperatura;
   printf("estable:\n");
   while((strcmp(op,"alerta"))!=0)
   {
       printf("temperatura:");
       fflush(stdin);
       gets(op);
       temperatura=atoi(op);
       if(temperatura>0)
       {
           if(temperatura<1000)
           {
               return estable;
           }
           else
           {
               return inestable;
           }
       }
   }
   return sistema_central;
}

estado_p f_inestable(void)
{
    tablero(recu(2),recu(4),0,recu(3));
   char op[30];
   int temperatura;
   printf("inestable:\n");
   while((strcmp(op,"alerta"))!=0)
   {
       printf("temperatura:");
       fflush(stdin);
       gets(op);
       temperatura=atoi(op);
       if(temperatura>0)
       {
           if(temperatura<1000)
           {
               return estable;
           }
           else
           {
               return inestable;
           }
       }
   }
   printf("la velocidad se reducira a 0 por la alta temperatura del motor\n");
   guardar(0,1);
   return sist_central_velocidades;
}

estado_p f_suficiente(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   printf("suficiente:\n");
   char op[30];
    int combustible;
   while((strcmp(op,"alerta"))!=0)
   {
       printf("porcentaje de combustible:");
       fflush(stdin);
       gets(op);
       if((strcmp(op,"alerta"))==0)return sistema_central;
       combustible=atoi(op);
       if(combustible>0)
       {
            guardar_bfs(combustible,1);
           if(combustible<config.porc_combustible)
           {
               return insuficiente;
           }
           else
           {
               return suficiente;
           }

       }
    printf("\n%d\n",recu_bfs(1));
   }
   return sistema_central;
}

estado_p f_insuficiente(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   char op[30];
   int combustible;
   printf("insuficiente:\n");
   while((strcmp(op,"alerta"))!=0)
   {
           printf("porcentaje de conbustible:");
           fflush(stdin);
           gets(op);
           combustible=atoi(op);
           if(combustible>0)
           {
           if(combustible<config.porc_combustible)
           {
               return insuficiente;
           }
           else
           {
               return suficiente;
           }
           }
   }
      printf("la velocidad se reducira por la baja cantidad de combustible\n");

   guardar_bfs(0,1);
   guardar(0,1);

   return sist_central_velocidades;
}

estado_p f_activado(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   printf("activado\n");
    int lluvia,velocidad;
   printf("parabrisas\nlectura(0-5)Volt. del sensor:");
   char op[30]="alert";

   while((strcmp(op,"alerta"))!=0)
   {
       fflush(stdin);
       gets(op);
       lluvia=atoi(op);
       if(lluvia>0)
       {
           if(lluvia<config.lluvia)
           {
               return desactivado;
           }
           else
           {
               return activado;
           }
       }
   }
   velocidad=recu(1);
   velocidad=velocidad*6/7;
   guardar(velocidad,1);

    return sist_central_velocidades;
}

estado_p f_desactivado(parametros_t config)
{
    tablero(recu(2),recu(4),0,recu(3));
   printf("desactivado\n");
   int lluvia;
   printf("parabrisas\nlectura(0-5)Volt. del sensor:");
   char op[30];

   while((strcmp(op,"alerta"))!=0)
   {
       fflush(stdin);
       gets(op);
       lluvia=atoi(op);

        if(lluvia>0)
       {
           if(lluvia<config.lluvia)
           {
               return desactivado;
           }
           else
           {
               return activado;
           }
       }
   }
         printf("la velocidad se reducira por la intensa lluvia\n");

   return sistema_central;
}

parametros_t f_inicio(void)
{
    printf("Maximixar la ventana para mas comodidad la hora de ver los datos, muchas gracias!!\n");
    system("pause");
    system("cls");
    parametros_t config;
    config = archivo("config.conf");
    return config;
}
