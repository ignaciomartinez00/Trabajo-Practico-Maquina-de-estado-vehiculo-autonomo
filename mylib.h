#ifndef mylib
#define mylib
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#define g 9.8
#define pi 3.14159265359



typedef enum
{
    sistema_central,
    camara,
    sist_central_velocidades,
    motor,
    combustible,
    parabrisas,
    bloque_desicion,
    radar,
    bloqueo,
    GPS,
    volante,
    busca_fallas,
    giroscopio,
    semaforo,
    estable,
    inestable,
    suficiente,
    insuficiente,
    activado,
    desactivado,

}estado_p;

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
        int bloqueado;
        char accion[30];
    }parametros_t;



    typedef struct
    {
        int velocidad_actual;
        int velocidad_esperada;
    }variables_t;



typedef enum
{
    RPMmax,
    RPMmin,
    cambioMax,
    cambioMin,
    porc_combustible,
    lluvia,
    angulo_volante,
    estadosemaforo,
    estadobloqueado,
    torque,
    autopista,
    calle,
    carretera,
    avenida,
    tempconf,
}parametros_p;



estado_p f_sistema_central(void);
estado_p f_camara (void);
estado_p f_sist_central_velocidades(parametros_t);
estado_p f_motor (parametros_t);
estado_p f_combustible(parametros_t);
estado_p f_parabrisas (parametros_t);
estado_p f_bloque_desicion(void);
estado_p f_radar (void);
estado_p f_bloqueo (parametros_t);
estado_p f_GPS(parametros_t);
estado_p f_luces (void);
estado_p f_volante(parametros_t);
estado_p f_busca_fallas (parametros_t);
estado_p f_giroscopio(parametros_t);
estado_p f_semaforo(void);
estado_p f_estable(void);
estado_p f_inestable(void);
estado_p f_suficiente(parametros_t);
estado_p f_insuficiente(parametros_t);
estado_p f_activado(parametros_t);
estado_p f_desactivado(parametros_t);

parametros_t f_inicio(void);


char *getkey(char *key);

parametros_t archivo(char *);


estado_p (*fms[21])(parametros_t);
estado_p f_lectura (void);

void verificacion(void);
char lectura(void);

int velocimetro(int,int);
int caja_de_cambios(int,int,int,int);
int medidor_RPM(int,int,int);

int conf_ve(int*);//cofiguracion velocidad esperada por via
int conf_via(int*);




struct guardado
{
    int posicion;
    int variable;
};


void alta(void);


void consulta(void);
void modifica(void);
void inicio(void);



struct guardado_bfs  ///guardado busca fallas
{
    int posicion;
    int variable;
};
void alta_bfs(void);
void inicio_bfs(void);
int recu_bfs(int );
int guardar_bfs(int ,int ) ;




int estacionar(void);
int esquivar(void);
void registro(parametros_t);

int torque_velocidad(int);

int recu(int);  //recupera info del archivo
int guardar(int,int);



void tablero(int ,int ,int ,int );


void menu(void);


#endif
