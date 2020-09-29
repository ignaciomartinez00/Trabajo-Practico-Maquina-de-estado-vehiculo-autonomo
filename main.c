#include "mylib.h"


int main()
{
    estado_p (*fms[])(parametros_t)={f_sistema_central,f_camara,f_sist_central_velocidades,f_motor,f_combustible,f_parabrisas,f_bloque_desicion,f_radar,f_bloqueo,f_GPS,f_volante,f_busca_fallas,f_giroscopio,f_semaforo,f_estable,f_inestable,f_suficiente,f_insuficiente,f_activado,f_desactivado};//en el mismo orden que los estados_p
    parametros_t config;
    inicio_bfs();
    inicio();
    config=f_inicio();
    estado_p estado = bloqueo;
    while(1)
   {
        estado=(*fms[estado])(config);

        //system("pause");
        system("cls");

   }
   return 0;
}
