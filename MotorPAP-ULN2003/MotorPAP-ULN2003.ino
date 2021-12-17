//https://www.luisllamas.es/motor-paso-paso-28byj-48-arduino-driver-uln2003/

//definicion de pines
const int pinMotor1 = 2;    // 28BYJ48 - In1
const int pinMotor2 = 3;    // 28BYJ48 - In2
const int pinMotor3 = 4;   // 28BYJ48 - In3
const int pinMotor4 = 5;   // 28BYJ48 - In4
 
//definicion variables
int velocidadMotor = 1000;  // variable para determinar la velocidad 
// 800 maxima - minima 1000 o mas
int contadorPasos = 0;      // contador para los pasos
int pasosPorVuelta = 4076;  // pasos para una vuelta completa
 
// Tablas con la secuencia de encendido 
// quitar signo de comentar a la necesaria)
 
//secuencia 1-fase usar velocidadMotor = 2000
//const int cantidadPasos = 4;
//const int tablaPasos[4] = { B1000, B0100, B0010, B0001 };
 
//secuencia 2-fases usar velocidadMotor = 2000
//const int cantidadPasos = 4;
//const int tablaPasos[4] = { B1001, B1100, B0110, B0011 };
 
//secuencia media fase usar velocidadMotor = 1000
const int cantidadPasos = 8;
const int tablaPasos[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };
 
 
void setup(){
  //declarar pines como salida
  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
  pinMode(pinMotor3, OUTPUT);
  pinMode(pinMotor4, OUTPUT);
}
 
void loop(){
  for (int i = 0; i < pasosPorVuelta * 2; i++){
    sentidoHorario();
    delayMicroseconds(velocidadMotor);
  }
  delay(200);
  for (int i = 0; i < pasosPorVuelta * 2; i++){
    sentidoAntihorario();
    delayMicroseconds(velocidadMotor);
  }
  delay(200);
}
 
void sentidoHorario(){ // en dirección de las agujas del reloj
  contadorPasos++;
  if (contadorPasos >= cantidadPasos) 
    contadorPasos = 0;
  escribirSalidas(contadorPasos);
}
 
void sentidoAntihorario(){// en dirección contraria a las agujas del reloj
  contadorPasos--;
  if (contadorPasos < 0) 
    contadorPasos = cantidadPasos - 1;
  escribirSalidas(contadorPasos);
}

void escribirSalidas(int paso){
  digitalWrite(pinMotor1, bitRead(tablaPasos[paso], 0));
  digitalWrite(pinMotor2, bitRead(tablaPasos[paso], 1));
  digitalWrite(pinMotor3, bitRead(tablaPasos[paso], 2));
  digitalWrite(pinMotor4, bitRead(tablaPasos[paso], 3));
}
