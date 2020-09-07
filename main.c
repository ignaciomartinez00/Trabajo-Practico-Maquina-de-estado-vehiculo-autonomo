#include "mylib.h"

int main()
{
    archivo();
    estado_p estado=0;
    while(1)
   {
        parametros_t config;
        estado_p (*fms[])(parametros_t)={f_sistema_central,f_camara,f_sist_central_velocidades,f_motor,f_combustible,f_parabrisas,f_bloque_desicion,f_radar,f_bloqueo,f_GPS,f_luces,f_volante,f_busca_fallas,f_giroscopio,f_semaforo,f_estable,f_inestable,f_suficiente,f_insuficiente,f_activado,f_desactivado};//en el mismo orden que los estados_p
        estado=(*fms[estado])(config);
        system("pause");
        system("cls");
   }
   return 0;
}
