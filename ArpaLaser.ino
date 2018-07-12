//VARIABLES

//pines
const int speaker = 8;               //pin de minijack
const int laserPin = 13;             //pin del laser
const int pulsPin3 = 3;              //pin pulsador
const int pulsPin2 = 2;              //pin pulsador
int duration = 100;
int ldrPin [] = {0, 1, 2, 3, 4, 5};  //array con los 6 pines de entrada analógicas

//valores o estados
int pulsState3 = 0;           // estado del pulsador(high o low)
int pulsState2 = 0;           // estado del pulsador(high o low)
boolean laserState;           // estado del laser (high o low)
int ldrValue[6];              //valor ldr normal (la lee en el loop)
int ldrValueSin[6];           //para autodeterminacion (se lee en el setup sin el laser)
int ldrValueLaser[6];         //para autodeterminacion (se lee en el setup con el laser)

//escala 1
#define NOTE_C4  262 //do
#define NOTE_D4  294 //re
#define NOTE_E4  330 //mi
#define NOTE_F4  349 //fa
#define NOTE_G4  392 //sol
#define NOTE_A4  440 //la
//escala 2
#define NOTE_C5  523 //do
#define NOTE_D5  587 //re
#define NOTE_E5  659 //mi
#define NOTE_F5  698 //fa
#define NOTE_G5  784 //sol
#define NOTE_A5  880 //la


//cambio de escala
int melody = 1;




void setup() {
  pinMode(laserPin, OUTPUT);
  pinMode(speaker, OUTPUT);
  Serial.begin(9600);

  //autodeterminacion de valores.
  //leer valores LDR NORMAL
  digitalWrite(laserPin, LOW);
  for (int i = 0; i < 6; i++) {
    ldrValueSin[i] = analogRead(ldrPin[i]);
    Serial.println(i);
    Serial.print("ldrValueSin");
    Serial.print(ldrValueSin[i]);
    delay(25);
  }

  //leer valores LDR CON LASER
  digitalWrite(laserPin, HIGH);
  delay(100);
  for (int i = 0; i < 6; i++) {
    ldrValueLaser[i] = analogRead(ldrPin[i]);
    Serial.println(i);
    Serial.print("ldrValueLaser");
    Serial.print(ldrValueLaser[i]);
    delay(25);
  }

}

void loop () {

  //leer valores LDR NORMAL (en todo momento)
  for (int i = 0; i < 6; i++) {
    ldrValue[i] = analogRead(ldrPin[i]);
    Serial.println(i);
    Serial.print("ldrValue");
    Serial.print(ldrValue[i]);

  }



  //MEMORIA DE LOS PULSADORES

  //Pulsador 2
  //lectura
  pulsState2 = digitalRead(pulsPin2);
  //cuando el pulsador se pulse cambiar la variable a melody 2
  //inicialmente se pone en la escala 1
  if (pulsState2 == HIGH) {
    if (melody == 1) {
      melody = 2;
    }
    else {
      melody = 1;
    }
    delay (200);
  }
  //manda la señal de que void utilizar dependiendo de la variable melody
  if (melody == 1) {
    sonido1();
  }
  else {
    sonido2();
  }

  //Pulsador 3
  pulsState3 = digitalRead(pulsPin3);
  if (pulsState3 == HIGH) {
    if (laserState == LOW) {
      digitalWrite(laserPin, HIGH);
      laserState = HIGH;
    }
    else {
      digitalWrite(laserPin, LOW);
      laserState = LOW;
    }
    delay (200);
  }
}

//TOCAR NOTAS: VOIDS

//escala 1
void sonido1() {
//que suene solo si los laser estan encendidos
  if (laserState == HIGH) {
    //si el valor de la ldr es menor que la media de los valores predeterminados no suena
    //do
    if (ldrValue[0] < (ldrValueSin[0] + ldrValueLaser[0]) / 2) {
      tone(speaker, NOTE_C4, duration);

    }
    else {
      noTone;
    }
    //re
    if (ldrValue[1] < (ldrValueSin[1] + ldrValueLaser[1]) / 2) {
      tone(speaker, NOTE_D4, duration);

    }
    else {
      noTone;
    }
    //mi
    if (ldrValue[2] < (ldrValueSin[2] + ldrValueLaser[2]) / 2) {
      tone(speaker, NOTE_E4, duration);

    }
    else {
      noTone;
    }
    //fa
    if (ldrValue[3] < (ldrValueSin[3] + ldrValueLaser[3]) / 2) {
      tone(speaker, NOTE_F4, duration);

    }
    else {
      noTone;
    }
    //sol
    if (ldrValue[4] < (ldrValueSin[4] + ldrValueLaser[4]) / 2) {
      tone(speaker, NOTE_G4, duration);

    }
    else {
      noTone;
    }
    //la
    if (ldrValue[5] < (ldrValueSin[5] + ldrValueLaser[5]) / 2) {
      tone(speaker, NOTE_A4, duration);

    }
    else {
      noTone;
    }
  }
}




//escala 2
void sonido2() {
//que suene solo si los laser estan encendidos
  if (laserState == HIGH) {
    //si el valor de la ldr es menor que la media de los valores predeterminados no suena
    //do
    if (ldrValue[0] < (ldrValueSin[0] + ldrValueLaser[0]) / 2) {
      tone(speaker, NOTE_C5, duration);

    }
    else {
      noTone;
    }
    //re
    if (ldrValue[1] < (ldrValueSin[1] + ldrValueLaser[1]) / 2) {
      tone(speaker, NOTE_D5, duration);

    }
    else {
      noTone;
    }
    //mi
    if (ldrValue[2] < (ldrValueSin[2] + ldrValueLaser[2]) / 2) {
      tone(speaker, NOTE_E5, duration);

    }
    else {
      noTone;
    }
    //fa
    if (ldrValue[3] < (ldrValueSin[3] + ldrValueLaser[3]) / 2) {
      tone(speaker, NOTE_F5, duration);

    }
    else {
      noTone;
    }
    //sol
    if (ldrValue[4] < (ldrValueSin[4] + ldrValueLaser[4]) / 2) {
      tone(speaker, NOTE_G5, duration);

    }
    else {
      noTone;
    }
    //la
    if (ldrValue[5] < (ldrValueSin[5] + ldrValueLaser[5]) / 2) {
      tone(speaker, NOTE_A5, duration);

    }
    else {
      noTone;
    }
  }
}