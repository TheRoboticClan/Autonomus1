Gestión de movilidad

En esta carpeta está cómo conectamos los motores a nuestra placa. Usamos un Arduino UNO y lo conectamos al L298P motor driver. Consideramos usar este motor driver porque lo vemos más sencillo de usar y tiene la entrada para los dos motores que necesitamos. Tanto la placa como el motor driver son componentes de otro kit (KS0428) que habíamos usado con anterioridad.

Para mover el robot utilizamos, de un eje de conducción de un auto a control remoto que teníamos, un motor y lo conectamos al motor driver al pin 2 y 1 que está fijado al pin digital 3 y al pin digital 12 de arduino UNO. Decidimos utilizar este motor y poner el eje de conducción en la parte trasera del robot para facilitar el avance nuestro robot.

Para diridir el motor decidimos armar un eje de conducción nosotros mismos utilizando unas llantas del kit Obstacle Avoidance Smart Car, un alambre dulce, palitos de paleta y un par de grapas para cable. Para poder dirigir el eje de conducción utilizamos un servo motor que está conectado al Sensor Shield.


Gestión de energía y sensores

Utilizamos dos baterías de litio recargables. La celda con las dos baterías está conectada al motor drvier que dirige la energía al motor, al arduino UNO y al sensor shield.

Usamos los siguientes componentes:

Dos servomotores

Un sensor de color

Dos sensores ultrasónicos
