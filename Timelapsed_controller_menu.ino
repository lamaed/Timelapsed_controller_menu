/*
El programa: este programa controla un Dolly para la realizacion de TimeLapsed
*/


/*
 The circuit:
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 * Servo  movimiento en eje x to digital pin 11
 
*/
 
// include the library code:
 #include <LiquidCrystal.h>


 
// initialize the library with the numbers of the interface pins
 LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 int servo_x = 11; //Pin servo eje X


 int ButtonVoltage = 0;
 int ButtonPressed = 0;
 int Backlight = 10;
 int fadeValue = 255;
 int retardo = 0;
 int repetir;
 int avances;
 int giro;
// parametros pre cargados.
 int time_lapse_s = 3;
 int time_lapse_m = 0;
 int avance_x = 1;
 int pos_x;
 int disparos = 300;
 int menu_num = 0;
  
 int pulso;
 int vueltas_x;
 /*
 byte abajo[8] = {
	B00100,	B00100,	B00100,	B00100,	B00100,	B11111,	B01110,	B00100
 };

 byte arriba[8] = {
	B00100,	B01110,	B11111,	B00100,	B00100,	B00100,	B00100,	B00100
 };*/
 
#define BUTTON_SELECT 5
 #define BUTTON_LEFT 4
 #define BUTTON_DOWN 3
 #define BUTTON_UP 2
 #define BUTTON_RIGHT 1
 #define BUTTON_NONE 0
 

void setup() {
  lcd.begin(16, 2);
  pinMode(servo_x, OUTPUT);
  lcd.setCursor (0,0);
  lcd.print("TL control - ELM");  
  lcd.setCursor (0,1);
  lcd.print("ServoX = Pin 11");
  delay(2000);
  lcd.clear();
}


void loop(){

ButtonVoltage = analogRead(0);
  
if (ButtonVoltage > 800) ButtonPressed = BUTTON_NONE; // No button pressed should be 1023
else if (ButtonVoltage > 650) ButtonPressed = BUTTON_SELECT;
else if (ButtonVoltage > 400) ButtonPressed = BUTTON_LEFT;
else if (ButtonVoltage > 290) ButtonPressed = BUTTON_DOWN;
else if (ButtonVoltage > 100) ButtonPressed = BUTTON_UP;
else ButtonPressed = BUTTON_RIGHT;


menu (menu_num);

  
switch (ButtonPressed)
{
   case BUTTON_LEFT:
  {
    if (menu_num > 0)
    {menu_num --;}
    delay (300);
    lcd.clear();
    break;
  }
   case BUTTON_RIGHT:
  {
    if (menu_num < 25)  // numero maximo de menu = 6, cambiar segun menus
    {menu_num ++;}
    delay (300);
    lcd.clear();
    break;
  }

   case BUTTON_UP:     // Sube el parametro visualizado en menu
  {
  
    if (menu_num == 0)         {delay (300); time_lapse_m ++;}
    else if (menu_num == 1)    {delay (300); time_lapse_s ++;}
    else if (menu_num == 2)    {delay (300); avance_x ++;}
    else if (menu_num == 3)    {delay (300); disparos = disparos + 100;}
    else if (menu_num == 4)    {delay (300); disparos =disparos + 10;}
    else if (menu_num == 5)    {delay (300); disparos ++;}
    else if (menu_num == 6)    {delay (300); giro ++;}
    
    
    else if (menu_num == 7)    {delay (300); menu_num = 11;}
    else if (menu_num == 11)
    {
     digitalWrite(servo_x, HIGH); // activamos el pin de salida
     delayMicroseconds(2000); // esperamos el tiempo que dura el pulso en microsegundos
     digitalWrite(servo_x, LOW); // desactivamos el pin de salida
     delay(20); // PAUSA de 20 milisegundos
    }
    else if (menu_num == 14)
    {delay (300); 
    if (fadeValue <=245) {fadeValue = fadeValue + 10;}
    }

    break;
  }
   case BUTTON_DOWN:    // baja el parametro visualizado en menu
  {
    if (menu_num == 0)         {delay (300);time_lapse_m --;}
    else if (menu_num == 1)    {delay (300);time_lapse_s --;}
    else if (menu_num == 2)    {delay (300); avance_x --;}
    else if (menu_num == 3)    {delay (300); disparos =disparos - 100;}
    else if (menu_num == 4)    {delay (300); disparos = disparos - 10;}
    else if (menu_num == 5)    {delay (300); disparos --;}
    else if (menu_num == 6)    {delay (300); giro --;}
    else if (menu_num == 7)    {delay (300); menu_num --;}

    else if (menu_num == 11)
    {
     digitalWrite(servo_x, HIGH); // activamos el pin de salida
     delayMicroseconds(1000); // esperamos el tiempo que dura el pulso en microsegundos
     digitalWrite(servo_x, LOW); // desactivamos el pin de salida
     delay(20); // PAUSA de 20 milisegundos
    }
    else if (menu_num == 14)
    {delay (300);
     if (fadeValue >=15) {fadeValue = fadeValue - 10;}
    }
    break;
  }

   case BUTTON_SELECT: 
   {
     lcd.clear();
     lcd.setCursor (0,0);
     lcd.print("Tiempo|Foto|Av");
     if (avance_x < 10)
     {lcd.print (" ");
     }
     lcd.print(avance_x);
     lcd.setCursor (0,1);
     repetir = disparos;
     for (disparos; disparos >= 0; disparos --)
    {
     for (retardo=time_lapse_m*60 + time_lapse_s  ; retardo >= 0; retardo--)
     {
        analogWrite (Backlight, fadeValue);
        lcd.setCursor (0,1);
        if (retardo/60 < 10){lcd.print (" ");}
        lcd.print (retardo/60);
        lcd.print ("m ");

        lcd.setCursor (3,1);
        if (retardo%60 < 10){lcd.print (" ");}
        lcd.print (retardo%60);
        lcd.print ("s ");

        lcd.setCursor (6,1);
        lcd.print ("|");

        lcd.setCursor (7,1);
        if (disparos < 1000) {lcd.print (" ");}
        lcd.print (disparos);        
        lcd.print ("   ");
        lcd.setCursor (11,1);

        lcd.print ("|");     
        lcd.print ("Gr");
        if (giro < 10){lcd.print (" ");}
        lcd.print (giro);       
        
        if (analogRead(0) < 100)      {break;}
       
        delay (1000);
       // aqui va la orden de disparo para la camara 
    }


     if (avance_x > 0)
     {pulso = 2000;
     avances = avance_x;
     } // 1000 el servo retrocede. 2000 el servo avanza
     else if (avance_x < 0)
     {pulso = 1000;
      avances = avance_x *(-1);}
     
     vueltas_x = avances *64;
     for(pos_x=0; pos_x < vueltas_x; pos_x ++)
     {
     digitalWrite(servo_x, HIGH); // activamos el pin de salida
     delayMicroseconds(pulso); // esperamos el tiempo que dura el pulso en microsegundos
     digitalWrite(servo_x, LOW); // desactivamos el pin de salida
     delay(20); // PAUSA de 20 milisegundos
     
     }
      if (analogRead(0) < 100)      {break;}
     
    }
//     lcd.setCursor (10,0);
     analogWrite (Backlight, 255);
  } 
     disparos = repetir; 
     delay (1000);
     lcd.clear();
     break;
  }


} // ciere del void loop()

