  #include <Servo.h>
  #define Motor_D 12  //pin 12 que controla la dirección del motor (haci delante y hacia atrás)
  #define Motor_P 3   //pin 3 que controla la potencia del motor
  #define Eje_D 13 //pin 13 que controla la dirección del eje (izquierda y derecha)
  #define Eje_P 11 //pin 11 que controla la 
  #define TRIG_PIN A1 //pin trig esta conectado al pin A1 pin del ultrasonico
  #define ECHO_PIN A0 //pin echo esta conectado al pin A0 pin del ultrasonico
  Servo servo1;  // servo motor
  int pos = 90;    // variable de la posicion del servo
  int vueltas = 0; //variable del número de vueltas
  int velocity = 70; //variable de la velocidad del auto

float checkdistance() //codigo de funcionamiento del ultrasonico
{
  Serial.begin(9600);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  float distance = pulseIn(ECHO_PIN, HIGH) / 58.00;
  delay(10);
  return distance;
}

void setup(){
  pinMode(TRIG_PIN, OUTPUT); //trig puesto como salida
  pinMode(ECHO_PIN, INPUT);//echo puesto como entrada
  servo1.attach(A2); //servo motor que controla la direccion de los sensores ultrasonico y de color
  pinMode(Motor_D, OUTPUT);//define motor direction pin as output.
  pinMode(Motor_P, OUTPUT);//define motor speed as output.
  pinMode(Eje_D, OUTPUT); //define steering wheel pin as output
  pinMode(Eje_P, OUTPUT); //define steering wheel pin as output
}

void loop()
{
 int distancia = checkdistance(); //medir las distancia cn el sensor ultrasónico
 if(vueltas == 12) // si el numero de vueltas es de doce
 {
  stop(); //para el auto
  delay(10000); //durante 10 seconds
 } 
 else if(distancia > 100)  //si la distancia es menor que 100
{
  forward(); // avanza
  delay(10); // durante 0.01 s
 } else { // sino 
  right(); // gira hacia la derecha
  delay(10); //durante 0.01 s
 }
}

//código para el movimiento del auto

void forward() //codigo para que se mueva hacia delante
{
  digitalWrite(Motor_D, HIGH);
  analogWrite(Motor_P, velocity);
  digitalWrite(Eje_D, HIGH);
  analogWrite(Eje_P, 0);
}

void backward() //codigo para que se mueva hacia atrás
{
  digitalWrite(Motor_D, LOW);
  analogWrite(Motor_P, velocity);
  digitalWrite(Eje_D, HIGH);
  analogWrite(Eje_P, 0);
}

void left() //codigo para que se mueve hacia la izquierda
{
  digitalWrite(Motor_D, HIGH);
  analogWrite(Motor_P, velocity);
  digitalWrite(Eje_D, LOW);
  analogWrite(Eje_P, 255);
}

void right() //codigo para que se mueva hacia la derecha
{
  digitalWrite(Motor_D, HIGH);
  analogWrite(Motor_P, velocity);
  digitalWrite(Eje_D, HIGH);
  analogWrite(Eje_P, 255);
}

void stop() //codigo para que pare
{
  digitalWrite(Motor_D, LOW);
  analogWrite(Motor_P, 0);
  digitalWrite(Eje_D, LOW);
  analogWrite(Eje_P, 0);
  delay(99999);
}