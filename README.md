# Trabajo-Practico-Maquina-de-estado-vehiculo-autonomo
maquina hola
Mi sistema representa el funcionamiento de un veh�culo aut�nomo. Tiene un estado central que dirige la transici�n de la mayor�a de los estados y tambi�n la mayor�a de los estados, adem�s de su respectiva funci�n, modifican el valor de velocidad del veh�culo.
El veh�culo fue dise�ado con las siguientes tecnolog�as:
�	Bloqueo de inicio/apagado: es un teclado digital donde si se ingresa la clave (�1234�) se enciende el veh�culo y si se elige la opci�n �apagar� se apaga el veh�culo.

�	El volante: tiene un sensor que mide el �ngulo y sentido en que se est� girando y un mecanismo que lo hace girar en funci�n de esa se�al del sensor.

�	Sensores de temperatura del motor: dependiendo la temperatura, van a definir si el motor se encuentra en un estado estable o inestable. En caso de que sea inestable se va a modificar la velocidad a cero.

Mi sistema representa el funcionamiento de un veh�culo aut�nomo. Tiene un estado central que dirige la transici�n de la mayor�a de los estados y tambi�n la mayor�a de los estados, adem�s de su respectiva funci�n, modifican el valor de velocidad del veh�culo.
El veh�culo fue dise�ado con las siguientes tecnolog�as:
�	Bloqueo de inicio/apagado: es un teclado digital donde si se ingresa la clave (�1234�) se enciende el veh�culo y si se elige la opci�n �apagar� se apaga el veh�culo.
�	El volante: tiene un sensor que mide el �ngulo y sentido en que se est� girando y un mecanismo que lo hace girar en funci�n de esa se�al del sensor.
�	Sensores de temperatura del motor: dependiendo la temperatura, van a definir si el motor se encuentra en un estado estable o inestable. En caso de que sea inestable se va a modificar la velocidad a cero.
�	Luces: se encienden con un sensor de luz, dependiendo la intensidad de luz (en Lumen), detectado por el sensor, se encienden o no.
�	tanque de combustible: tiene un sensor que indica la cantidad de combustible y en funci�n de este se va a modificar el valor de la velocidad del auto a cero.
�	El parabrisas: se activa con un sensor de agua, si el valor detectado (en volts) es superior a un determinado valor se activa y en caso contrario no.
�	GPS: direcciona al auto (girar o seguir derecho), indica la distancia a recorrer y cu�l es la v�a de transporte a transitar (ruta, calle, peatonal, etc) y ese dato ajusta la velocidad del auto al transitarla.
�	Giroscopio: define el �ngulo en que se est� elevando el auto (por ejemplo, en un paso nivel) y en funci�n de �l se va a modificar la velocidad del auto, para que pueda transitar esa v�a.
�	C�mara: define si el objeto, por medio de inteligencia artificial, observado es un sem�foro, lomo de burro, cruce o desconocido. En caso que sea sem�foro, se va a detectar el estado del sem�foro: VERDE-ROJO, si el estado es ROJO se va a modificar la velocidad del auto a cero. SI se detecta un reductor de velocidad, se reduce la velocidad y de no ser desconocido/cruce, se activa el radar.
�	El radar, permite reconocer la distancia a de los objetos alrededor del veh�culo mediante puntos. Va recoger dos tomas del entorno en distinto tiempo, por ejemplo, si detecta un punto en ciertas coordenadas y en la segunda toma, se encuentra en otras coordenadas, puede determinar la velocidad y el �ngulo en que se mueve en funci�n del veh�culo aut�nomo, lo que le va a permitir al auto tomar una decisi�n si es un peligro o no y en el caso que lo sea tomar acci�n: girar-frenar-acelerar, trabajando en conjunto con el bloque de decisi�n. La otra funci�n del radar es detectar alg�n espacio vac�o para estacionar.
�	El bloque de decisi�n: va a definir qu� acci�n va a tomar el veh�culo, se compone de una memoria y un procesador, apunta a los distintos elementos del veh�culo en un determinado orden, junto con determinado valor para cada uno. Por ejemplo, si el radar detecta un obst�culo en reposo que est� enfrente del veh�culo (por ejemplo, un veh�culo que se detuvo), el bloque de decisi�n va a tener las instrucciones en el siguiente orden: bajar la velocidad a 50 Km/h (apuntando al bloque de cambios de velocidad) y despu�s de que se cumpla lo anterior, girar 30 grados (apuntando al volante). Estas instrucciones ya est�n definidas con anterioridad, guardadas en la memoria.
�	Busca fallas, es un archivo donde se guardan todos los par�metros recogidos por los sensores y va a detectar cuales (revisando uno por uno), modificaron la velocidad que inicialmente era la definida por el GPS.
�	El bloque de cambios de velocidad: se compone de la caja de cambios, un veloc�metro, un medidor de RPM y un sistema central propio de este bloque.
El sistema central de este bloque compara la velocidad a la que se quiere llegar y la del veloc�metro. Si es menor la velocidad del veloc�metro, el veh�culo acelera, en caso contrario desacelera y si las velocidades son iguales se mantiene la velocidad constante.
El bloque de cambios de velocidad por otro lado, maneja los cambios de la caja de cambios, si los RPM indicados en el medidor de RPM son diferentes a al rango est�ndar de RPM (Max-Min) se pasa a su respectivo cambio.
�	El sistema central: se encarga de apuntar o llamar a todas las partes del sistema antes mencionadas, unificando as� a todo el sistema, para que apunte a cada elemento se debe mencionar por su nombre ejemplo, �GPS� y el sistema recoge los datos obtenidos por el GPS y para volver al sistema central, se debe apuntar a �l mencionando �alerta�.
(BORRADOR)
