//Declaración de variables
int pot;
int lm35;
int dips1;
int nivel;
void setup() {
Serial.begin(9600);
 //Puerto para sensar los dipswitch
DDRA=0; PORTA=255;
 //Puetos para sensar el nivel
DDRC=0; PORTC=255;
}
void loop() {
  //Lectura de los sensores del Arduino
  pot=analogRead(A0);
  lm35=analogRead(A1);
  dips1= PINA & 0B00001111;
  nivel= PINC;
  //Envio de la informacion a LabView
  Serial.print("A");
  Serial.print(pot);
  Serial.print("B");
  Serial.print(lm35);
  Serial.print("C");
  Serial.print(dips1);
  Serial.print("D");
  Serial.print(nivel);
  Serial.println("E");
  delay(100);
}
