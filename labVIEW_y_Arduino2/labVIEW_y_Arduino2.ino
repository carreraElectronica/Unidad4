//Inclusion de la libreria PID
#include <PID_v1.h>
// Pin conectado al sensor LM35 (entrada analógica)
const int pinLM35 = A0; 
// Pin conectado al ventilador (salida PWM)     
const int pinVentilador = 9;
// Temperatura de referencia en grados Celsius
double setpoint = 30.0;      
double input, output;
 // Ganancia proporcional
double Kp = 10.0; 
 // Ganancia integral        
double Ki = 0.1;   
 // Ganancia derivativa       
double Kd = 0;            
PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);
void setup() {
  pinMode(pinVentilador, OUTPUT);
  Serial.begin(9600);
  pid.SetMode(AUTOMATIC);
}
void loop() {
  // Lectura de temperatura desde el LM35
  int sensorValue = analogRead(pinLM35);
  // Convertir el valor ADC a temperatura en grados Celsius
  input = sensorValue * 0.48828125; 
  // Actualizar el control PID
  pid.Compute();
  // Ajustar la velocidad del ventilador
  // Mapear la salida del PID al rango del PWM (0-100%)
  int fanSpeed = map(output, 0, 255, 0, 100);
  analogWrite(pinVentilador, fanSpeed);
 // Enviar datos de temperatura y salida del control PID a LabVIEW
  Serial.print("A");
  Serial.print(input);
  Serial.print("B");
  Serial.print(output);
  Serial.println("C");
  // Intervalo de muestreo de 1 segundo
  delay(1000); 
}
