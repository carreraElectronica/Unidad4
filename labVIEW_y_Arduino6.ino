int dato;
void setup() {
  DDRC = 0;
  PORTC = 255;
  DDRA = 0;
  PORTA = 255;
  Serial.begin(9600);
}
void loop() {
  int dato = PINA;
  int w = analogRead(0);
  int w1 = analogRead(1);
  int ds = PINC & 0b00001111;
  Serial.print("A");
  Serial.print(dato);
  Serial.println("B");
}