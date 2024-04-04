void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}
String dato;
int valorPot;
void loop() {
  if (Serial.available() > 0) {
    // Lee la cadena hasta que se recibe un salto de línea
    dato = Serial.readStringUntil('\n'); 
    // Convierte la cadena a un número entero
    valorPot = dato.toInt();
    // Configura el PWM en el pin 2 con el valor recibido
    analogWrite(2, valorPot); 
  // Imprime el valor de la potencia en el puerto serial
    Serial.println(valorPot); 
  }
}
 
