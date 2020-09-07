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

void archivo(void)
{
FILE *conf;
char cadena[40], *key, *val;
char variables[23][20] = {"RPM", "RPMmax", "RPMmin","velocidad_actual","velocidad_esperada","cambio","cambioMax","cambioMin","temperatura","porc_combustible","lluvia","angulo_giroscopio","angulo_volante","estado_semaforo","bloqueado","accion","torque","autopista","calle","carretera","avenida","variacion","tempconf"};
int i;
int RPMmax,RPMmin,RPM,velocidad_actual,velocidad_esperada,cambio,cambioMax,cambioMin,temperatura,porc_combustible,lluvia,angulo_giroscopio,angulo_volante,torque,autopista,calle,carretera,avenida,variacion,tempconf;
char estado_semaforo[30],bloqueado[30],accion[30];

//inicio validacion
if( (conf = fopen("config.conf","rb")) == NULL ){
	printf("No se encontro archivo de configuracion.\n");
	return 1;
}
//fin validacion
fgets(cadena, 40, conf);
do{
	key = cadena;
	if( (*key) != '#' && strlen(key) >= 0){		//caracter que indica comentario
		val = getKey(key); 						//modifica a key para que solo tenga la clave, retorna.
		//printf("%s: %s\n", key, val);			//imprime la clave y el valor levantdo del archvio
		for( i = 0; i < 23; i++){
			if( !strcmp( key , variables[i] ) ){

				switch(i){
					case 0: RPM = atoi(val);
						break;
					case 1:	RPMmax = atoi(val);
						break;
					case 2:	RPMmin = atoi(val);
						break;
                    case 3:	velocidad_actual = atoi(val);
						break;
					case 4:	velocidad_esperada=atoi(val);
						break;
                    case 5:	cambio=atoi(val);
						break;
                    case 6:	cambioMax = atoi(val);
						break;
					case 7:	cambioMin=atoi(val);
						break;
                    case 8:	temperatura=atoi(val);
						break;
                    case 9:	porc_combustible = atoi(val);
						break;
					case 10: lluvia=atoi(val);
						break;
                    case 11: angulo_giroscopio=atoi(val);
						break;
                    case 12: angulo_volante=atoi(val);
						break;
                    case 13: strcpy(estado_semaforo,val);
						break;
                    case 14: strcpy(bloqueado,val);
						break;
                    case 15: strcpy(accion,val);
						break;
                    case 16: torque=atoi(val);
						break;
                    case 17: autopista=atoi(val);
						break;
                    case 18: calle=atoi(val);
						break;
                    case 19: carretera=atoi(val);
						break;
                    case 20: avenida=atoi(val);
						break;
                    case 21: variacion=atoi(val);
						break;
                    case 22: tempconf=atoi(val);
						break;
				}
			}
		}
	}
	fgets(cadena, 40, conf);
}while( !feof(conf) );
printf("RPM : %d\n",RPM);
printf("RPMmax: %d\n",RPMmax);
printf("RPMmin: %d\n\n",RPMmin);





printf("velocidad actual: %d\n",velocidad_actual);
printf("velocidad esperada: %d\n\n",velocidad_esperada);
printf("cambio: %d\n",cambio);
printf("maximo cambio: %d\n",cambioMax);
printf("minimo cambio: %d\n\n",cambioMin);
printf("temperatura: %d\n",temperatura);
printf("porcentaje de combustible: %d\n",porc_combustible);
printf("lluvia: %d\n",lluvia);
printf("giroscopio: %d\n",angulo_giroscopio);
printf("torque: %d\n",torque);
printf("angulo_volante: %d\n\n",angulo_volante);
printf("semaforo: %s",estado_semaforo);
printf("bloqueo: %s",bloqueado);
printf("accion: %s\n",accion);
printf("autopista: %d\n",autopista);
printf("calle: %d\n",calle);
printf("carretera: %d\n",carretera);
printf("avenida: %d\n\n",avenida);
printf("variacion: %d\n\n",variacion);
printf("temperatura de transicion: %d\n\n",tempconf);
printf("todas las variables estan inicializadas\n\n");
system("pause");
system("cls");

return 0;
}

