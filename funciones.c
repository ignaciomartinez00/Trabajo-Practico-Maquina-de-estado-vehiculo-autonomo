
#include "mylib.h"

estado_p f_lectura (void)
{
    int i;
    char op[30];
    char opciones[14][100]={"sistema_central","camara","sistema_central_de_velocidades","motor","combustible","parabrisas","bloque_desicion","radar","bloqueo","GPS","luces","volante","busca_fallas","giroscopio"};
    fflush(stdin);
    gets(op);
    for(i=0;i<14;i++)
    {
        if((strcmp(op,opciones[i]))==0)
        {
            return i;
        }
    }
    printf("se desconoce tecnologia vuelva a ejecutar la accion:\n");
    return sistema_central;
}

estado_p f_sistema_central (void)
{
   printf("sistema central:\n");
   return f_lectura();
}

estado_p f_camara (void)
{
   printf("camara:\nobstaculo detectado:");
   char op[20];
   fflush(stdin);
   gets(op);
     if((strcmp(op,"semaforo"))==0)
   {
       return semaforo;
   }
     if((strcmp(op,"reductor"))==0||(strcmp(op,"alerta"))==0||(strcmp(op,"vacio"))==0)
   {
       return sistema_central;
   }
   if((strcmp(op,"cruce"))==0||(strcmp(op,"desconocido"))==0)
   {
       return radar;
   }

   if((strcmp(op,"cruce"))!=0&&(strcmp(op,"desconocido"))!=0&&(strcmp(op,"reductor"))!=0&&(strcmp(op,"alerta"))!=0&&(strcmp(op,"vacio"))!=0)
   {
       printf("error\nvuelva a detectar:\n");
       return camara;
   }
   return sistema_central;
}


estado_p f_sist_central_velocidades(void)
{
   printf("sistema_central_de_velocidades\n");
   return sistema_central;
}


estado_p f_bloque_desicion(void)
{
   printf("bloque de desicion:\n");
   return sistema_central;
}

estado_p f_radar(void)
{
   printf("radar\n");
   return sistema_central;
}

estado_p f_bloqueo(void)
{
   printf("bloqueo\n");
   return sistema_central;
}

estado_p f_GPS(void)
{
   printf("GPS:\n");
   return sistema_central;
}

estado_p f_luces(void)
{
   printf("luces:\n");
   return sistema_central;
}

estado_p f_volante(void)
{
   printf("volante:\n");
   return sistema_central;
}

estado_p f_busca_fallas(void)
{
   printf("busca fallas:\n");
   return sistema_central;
}

estado_p f_giroscopio(void)
{
   printf("giroscopio\n");
   scanf("%d",&angulo);
   return sistema_central;
}

estado_p f_semaforo(void)
{
   printf("semaforo\n");
   return sistema_central;
}


estado_p f_motor(void)
{
   int temperatura;
   printf("motor\ningrese temperatura:");
   scanf("%d",&temperatura);
   if(temperatura<1000)
   {
       return estable;
   }
   else
   {
       return inestable;
   }
}

estado_p f_combustible(void)
{
   printf("combustible\n");
   return sistema_central;
}

estado_p f_parabrisas(void)
{
   printf("parabrisas\n");
   return sistema_central;
}

estado_p f_estable(void)
{
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
   return sistema_central;
}

estado_p f_suficiente(void)
{
   printf("suficiente:\n");
   return sistema_central;
}

estado_p f_insuficiente(void)
{
   printf("insuficiente:\n");
   return sistema_central;
}

estado_p f_activado(void)
{
   printf("activado\n");
   return sistema_central;
}

estado_p f_desactivado(void)
{
   printf("desactivado\n");
   return sistema_central;
}

