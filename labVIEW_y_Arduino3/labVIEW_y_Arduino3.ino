#incluye <SoftwareSerial.h>
#incluye <string.h>
#incluye <stdio.h>
uint8_t recv_en;
char recv_str[20];
int i=0;
SoftwareSerial mySerial(6, 7);
#definir LED 8
configuración de vacío()
{
Serial.begin( 2400 );
Serial.println ( "USB Serial está listo" );
mySerial.begin ( 2400 );
pinMode ( LED, SALIDA );
digitalWrite ( LED, BAJO );
}
bucle vacío ( )
{
si ( mySerial.disponible ( ) )
{
recv_char = mySerial.read ( );
if ( recv_char = = '\ r' ) {
recv_str [ i ] = '\ 0';
si (!strcmp ( recv_str, "ON" ) ) {
digitalWrite ( LED, ALTO );
Serial.println ( "high" );
}
si (!strcmp ( recv_str, "OFF" ) ) {
digitalWrite ( LED, BAJO );
Serial.println ( "bajo" );
}
Serial.println ( recv_str );
i = 0;
memset ( recv_str, 0, tamaño de ( recv_str ) );
}
más {
if ( recv_char = = '\ r' | | recv_char = = '\ n' ) {
}
más {
recv_str[i++] = recv_char;
}
}

}
si (Serial.available() )
{
recv_char = Serial.read();
if ( recv_char = = '\ r' ) {
recv_str [ i ] = '\ 0';
mySerial.println(recv_str);
i = 0;
memset ( recv_str, 0, tamaño de ( recv_str ) );
}
más {
if ( recv_char = = '\ r' | | recv_char = = '\ n' ) {
}
más {
recv_str[i++] = recv_char;
}
}

}
}
 
