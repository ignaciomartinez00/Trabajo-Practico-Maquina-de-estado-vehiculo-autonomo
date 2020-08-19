# Trabajo-Practico-Maquina-de-estado-vehiculo-autonomo
maquina hola
Mi sistema representa el funcionamiento de un vehículo autónomo. Tiene un estado central que dirige la transición de la mayoría de los estados y también la mayoría de los estados, además de su respectiva función, modifican el valor de velocidad del vehículo.
El vehículo fue diseñado con las siguientes tecnologías:
•	Bloqueo de inicio/apagado: es un teclado digital donde si se ingresa la clave (“1234”) se enciende el vehículo y si se elige la opción “apagar” se apaga el vehículo.

•	El volante: tiene un sensor que mide el ángulo y sentido en que se está girando y un mecanismo que lo hace girar en función de esa señal del sensor.

•	Sensores de temperatura del motor: dependiendo la temperatura, van a definir si el motor se encuentra en un estado estable o inestable. En caso de que sea inestable se va a modificar la velocidad a cero.

Mi sistema representa el funcionamiento de un vehículo autónomo. Tiene un estado central que dirige la transición de la mayoría de los estados y también la mayoría de los estados, además de su respectiva función, modifican el valor de velocidad del vehículo.
El vehículo fue diseñado con las siguientes tecnologías:
•	Bloqueo de inicio/apagado: es un teclado digital donde si se ingresa la clave (“1234”) se enciende el vehículo y si se elige la opción “apagar” se apaga el vehículo.
•	El volante: tiene un sensor que mide el ángulo y sentido en que se está girando y un mecanismo que lo hace girar en función de esa señal del sensor.
•	Sensores de temperatura del motor: dependiendo la temperatura, van a definir si el motor se encuentra en un estado estable o inestable. En caso de que sea inestable se va a modificar la velocidad a cero.
•	Luces: se encienden con un sensor de luz, dependiendo la intensidad de luz (en Lumen), detectado por el sensor, se encienden o no.
•	tanque de combustible: tiene un sensor que indica la cantidad de combustible y en función de este se va a modificar el valor de la velocidad del auto a cero.
•	El parabrisas: se activa con un sensor de agua, si el valor detectado (en volts) es superior a un determinado valor se activa y en caso contrario no.
•	GPS: direcciona al auto (girar o seguir derecho), indica la distancia a recorrer y cuál es la vía de transporte a transitar (ruta, calle, peatonal, etc) y ese dato ajusta la velocidad del auto al transitarla.
•	Giroscopio: define el ángulo en que se está elevando el auto (por ejemplo, en un paso nivel) y en función de él se va a modificar la velocidad del auto, para que pueda transitar esa vía.
•	Cámara: define si el objeto, por medio de inteligencia artificial, observado es un semáforo, lomo de burro, cruce o desconocido. En caso que sea semáforo, se va a detectar el estado del semáforo: VERDE-ROJO, si el estado es ROJO se va a modificar la velocidad del auto a cero. SI se detecta un reductor de velocidad, se reduce la velocidad y de no ser desconocido/cruce, se activa el radar.
•	El radar, permite reconocer la distancia a de los objetos alrededor del vehículo mediante puntos. Va recoger dos tomas del entorno en distinto tiempo, por ejemplo, si detecta un punto en ciertas coordenadas y en la segunda toma, se encuentra en otras coordenadas, puede determinar la velocidad y el ángulo en que se mueve en función del vehículo autónomo, lo que le va a permitir al auto tomar una decisión si es un peligro o no y en el caso que lo sea tomar acción: girar-frenar-acelerar, trabajando en conjunto con el bloque de decisión. La otra función del radar es detectar algún espacio vacío para estacionar.
•	El bloque de decisión: va a definir qué acción va a tomar el vehículo, se compone de una memoria y un procesador, apunta a los distintos elementos del vehículo en un determinado orden, junto con determinado valor para cada uno. Por ejemplo, si el radar detecta un obstáculo en reposo que está enfrente del vehículo (por ejemplo, un vehículo que se detuvo), el bloque de decisión va a tener las instrucciones en el siguiente orden: bajar la velocidad a 50 Km/h (apuntando al bloque de cambios de velocidad) y después de que se cumpla lo anterior, girar 30 grados (apuntando al volante). Estas instrucciones ya están definidas con anterioridad, guardadas en la memoria.
•	Busca fallas, es un archivo donde se guardan todos los parámetros recogidos por los sensores y va a detectar cuales (revisando uno por uno), modificaron la velocidad que inicialmente era la definida por el GPS.
•	El bloque de cambios de velocidad: se compone de la caja de cambios, un velocímetro, un medidor de RPM y un sistema central propio de este bloque.
El sistema central de este bloque compara la velocidad a la que se quiere llegar y la del velocímetro. Si es menor la velocidad del velocímetro, el vehículo acelera, en caso contrario desacelera y si las velocidades son iguales se mantiene la velocidad constante.
El bloque de cambios de velocidad por otro lado, maneja los cambios de la caja de cambios, si los RPM indicados en el medidor de RPM son diferentes a al rango estándar de RPM (Max-Min) se pasa a su respectivo cambio.
•	El sistema central: se encarga de apuntar o llamar a todas las partes del sistema antes mencionadas, unificando así a todo el sistema, para que apunte a cada elemento se debe mencionar por su nombre ejemplo, “GPS” y el sistema recoge los datos obtenidos por el GPS y para volver al sistema central, se debe apuntar a él mencionando “alerta”.
(BORRADOR)
