

#ifndef mylib
#define mylib
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>

//prototipo de ARCHIVO


char *getkey(char *key);
void archivo(void);



typedef enum //en el mismo orden que las f_
{
    sistema_central,
    camara,//funciones inicialiazadoras T2
    sist_central_velocidades,//funcion inicializadora tipo 3
    motor,//funciones inicialiazadoras
    combustible,//funciones inicialiazadoras
    parabrisas,//funciones inicialiazadoras
    bloque_desicion,
    radar,
    bloqueo,
    GPS,
    luces,
    volante,
    busca_fallas,
    giroscopio,// hasta aca apuntan son apuntados desde el sistema central
    semaforo,
    estable,
    inestable,
    suficiente,
    insuficiente,
    activado,
    desactivado,
}estado_p;//es la posicion de los estados

//funciones de cada estado
estado_p f_sistema_central(void);
estado_p f_camara (void);

estado_p f_sist_central_velocidades(void);
estado_p f_motor (void);
estado_p f_combustible(void);
estado_p f_parabrisas (void);
estado_p f_bloque_desicion(void);
estado_p f_radar (void);
estado_p f_bloqueo (void);
estado_p f_GPS(void);
estado_p f_luces (void);
estado_p f_volante(void);
estado_p f_busca_fallas (void);
estado_p f_giroscopio(void);
estado_p f_semaforo(void);

estado_p f_estable(void);
estado_p f_inestable(void);
estado_p f_suficiente(void);
estado_p f_insuficiente(void);
estado_p f_activado(void);
estado_p f_desactivado(void);

int angulo;

    typedef struct
    {
        int RPMmax;
        int RPMmin;
        int RPM;
        int velocidad_actual;
        int velocidad_esperada;
        int cambio;
        int cambioMax;
        int cambioMin;
        int temperatura;
        int porc_combustible;
        int lluvia;
        int angulo_giroscopio;
        int angulo_volante;
        int torque;
        int autopista;
        int calle;
        int carretera;
        int avenida;
        int variacion;
        int tempconf;
        char estado_semaforo[30];
        char bloqueado[30];
        char accion[30];
    }parametros_t;


estado_p (*fms[21])(parametros_t);
estado_p f_lectura (void);




#endif
