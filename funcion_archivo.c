#include "mylib.h"

char *getKey(char *key)
{
char i = 0;
while(*(key+i) != ' '){//espacio entre variable y su valor dentro del archivo
	i++;
}
*(key+i) = 0;
return key+i+1;
}

parametros_t archivo(char *filename)
{
FILE *conf;
char cadena[40], *key, *val;
char variables[23][20] = {"RPMmax", "RPMmin","cambioMax","cambioMin","porc_combustible","lluvia","angulo_volante","estado_semaforo","bloqueado","torque","autopista","calle","carretera","avenida","tempconf"};
char estado_semaforo[30],bloqueado[30],accion[30];
parametros_t config;
//inicio validacion
if( (conf = fopen(filename,"rb")) == NULL ){
	printf("No se encontro archivo de configuracion.\n");
	return config;
}
//fin validacion
fgets(cadena, 40, conf);
do{
	key = cadena;
	if( (*key) != '#' && strlen(key) >= 0){		//caracter que indica comentario
		val = getKey(key); 						//modifica a key para que solo tenga la clave, retorna.
		//printf("%s: %s\n", key, val);			//imprime la clave y el valor levantdo del archvio
		int j;
		for( j = 0; j < 15; j++){
			if( !strcmp( key , variables[j] ) ){

				switch(j){
					case RPMmax:	config.RPMmax = atoi(val);
						break;
					case RPMmin:	config.RPMmin = atoi(val);
						break;
                    case cambioMax:	config.cambioMax = atoi(val);
						break;
					case cambioMin:	config.cambioMin=atoi(val);
						break;
                    case porc_combustible:	config.porc_combustible = atoi(val);
						break;
					case lluvia: config.lluvia=atoi(val);
						break;
                    case angulo_volante: config.angulo_volante=atoi(val);
						break;
                    case estadobloqueado: config.bloqueado=atoi(val);
						break;
                    case torque: config.torque=atoi(val);
						break;
                    case autopista: config.autopista=atoi(val);
						break;
                    case calle: config.calle=atoi(val);
						break;
                    case carretera: config.carretera=atoi(val);
						break;
                    case avenida: config.avenida=atoi(val);
						break;
                    case tempconf: config.tempconf=atoi(val);
						break;
				}
			}
		}
	}
	fgets(cadena, 40, conf);
}while( !feof(conf) );
/*
printf("RPMmax: %d\n",config.RPMmax);
printf("RPMmin: %d\n\n",config.RPMmin);
printf("maximo cambio: %d\n",config.cambioMax);
printf("minimo cambio: %d\n\n",config.cambioMin);
printf("porcentaje de combustible: %d\n",config.porc_combustible);
printf("lluvia: %d\n",config.lluvia);
printf("angulo_volante: %d\n\n",config.angulo_volante);
printf("bloqueo: %d\n",config.bloqueado);
printf("autopista: %d\n",config.autopista);
printf("calle: %d\n",config.calle);
printf("carretera: %d\n",config.carretera);
printf("avenida: %d\n\n",config.avenida);
printf("torque: %d\n",config.torque);
///printf("variacion: %d\n\n",config.variacion);
printf("temperatura de transicion: %d\n\n",config.tempconf);
printf("todas las variables estan inicializadas\n\n");
system("pause");
system("cls");
*/
return config;
}


