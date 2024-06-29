  #include <Servo.h>
  #define MD_Ctrl 12  //pin 12 que controla la dirección del motor
  #define MD_PWM 3   //pin 3 que controla la potencia del motor
  #define ML_Ctrl 13
  #define ML_PWM 11
  #define TRIG_PIN A1 //pin trig esta conectado al pin A1 pin del ultrasonico
  #define ECHO_PIN A0 //pin echo esta conectado al pin A0 pin del ultrasonico
  #define S0 4 
  #define S1 5
  #define S2 6
  #define S3 7
  #define sensorOut 8 //pines del sensor de color
  Servo servo1;  // servo motor conectado al sensor ultrasonico y el sensor de color
  int pos = 90;    // variable de la posicion del servo
  int vueltas = 0;

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

int color() //codigo de deteccion del color por el sensor de color
{
  digitalWrite(S2,LOW); //rojo
  digitalWrite(S3,LOW);
  int R = pulseIn(sensorOut, LOW);
  delay(10);
  
  digitalWrite(S2,HIGH); //verde
  digitalWrite(S3,HIGH);
  int G = pulseIn(sensorOut, LOW);
  delay(10);

  if(R<G) {
    int color = 1; // rojo
    delay(10);
    return color;
  } else {
    int color = 2; // verde
    delay(10);
    return color;
  }
}

void setup(){
Serial.begin(9600); //para la lectura de los sensores
  pinMode(TRIG_PIN, OUTPUT); //trig puesto como salida
  pinMode(ECHO_PIN, INPUT);//echo puesto como entrada
  servo1.attach(A2); //servo motor que controla la direccion de los sensores ultrasonico y de color
  pinMode(MD_Ctrl, OUTPUT);//define direction control pin of right motor as output.
  pinMode(MD_PWM, OUTPUT);//define the PWM control pin of right motor as output.
  pinMode(ML_Ctrl, OUTPUT);
  pinMode(ML_PWM, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);
}

void loop()
{
 int distancia = checkdistance();
 int valor = color();
 Serial.println(valor);
 Serial.println(distancia);
 if(distancia < 80) {
  vueltas = vueltas + 1;
  go_left();
  delay(10);
 } else if(vueltas == 12) {
  stop();
 } else {
  go_fordward();
  delay(10);
 }
}

void go_fordward() //codigo 
{
  digitalWrite(MD_Ctrl, HIGH);
  analogWrite(MD_PWM, 75);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 0);
}

void go_backward() 
{
  digitalWrite(MD_Ctrl, LOW);
  analogWrite(MD_PWM, 75);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 0);
}

void go_right() 
{
  digitalWrite(MD_Ctrl, HIGH);
  analogWrite(MD_PWM, 75);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 200);
}

void go_left() 
{
  digitalWrite(MD_Ctrl, HIGH);
  analogWrite(MD_PWM, 75);
  digitalWrite(ML_Ctrl, HIGH);
  analogWrite(ML_PWM, 200);
}

void stop() 
{
  digitalWrite(MD_Ctrl, LOW);
  analogWrite(MD_PWM, 0);
  digitalWrite(ML_Ctrl, LOW);
  analogWrite(ML_PWM, 0);
  delay(99999);
}