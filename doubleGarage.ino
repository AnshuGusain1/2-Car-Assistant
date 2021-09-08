
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include<avr/power.h>
#endif


int trig = 9;
int echo = 8;
long lecture_echo;
long cm;

int ltrig = 4;
int lecho = 6;
long lecture_lecho;
long lcm;

int x = 0;


#define PIN 3
#define NUMPIXELS 30
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  pinMode(trig, OUTPUT);
  pinMode(ltrig, OUTPUT);
  digitalWrite(trig, LOW);
  digitalWrite(ltrig, LOW);
  pinMode(echo, INPUT);
  pinMode(lecho, INPUT);
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
}

void loop() {

  lread();
  read();

  delay(2000);
  

  lread();
  read();


  while (lcm < 71) {
    rightCar();
  }
  while (cm < 71) {
    leftCar();
  }

}


void read() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  lecture_echo = pulseIn(echo, HIGH);
  cm = lecture_echo / 58;

}



void lread() {
  digitalWrite(ltrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ltrig, LOW);
  lecture_lecho = pulseIn(lecho, HIGH);
  lcm = lecture_lecho / 58;

}






void rightCar() {
  read();
  while (cm < 71 && cm > 29) {

    int mapped = map(cm, 30, 70, 0, 30);
    pixels.clear();
    for (x = 0; x <= 30 - mapped; x++) {
      pixels.setPixelColor(x, pixels.Color(0, 255, 255));
      read();
    }
    pixels.show();
    read();
    

  }


  while (cm < 30) {
    for (x = 0; x < 30; x++) {
      pixels.setPixelColor(x, pixels.Color(255, 0, 0));
      read();
     
    }
    pixels.show();
  }
  while (cm > 70 && cm < 200) {
    for (x = 0; x < 30; x++) {
      pixels.setPixelColor(x, pixels.Color(0, 255, 0));
      read();
     
    }
    pixels.show();
  }
  while (cm >= 200) {
    for (x = 0; x < 30; x++) {
      pixels.setPixelColor(x, pixels.Color(0, 0 , 0));
      read();
      
    }
    pixels.show();
  }
}



void leftCar() {
  lread();
  while (lcm < 71 && lcm > 29) {

    int mapped = map(lcm, 30, 70, 0, 30);
    pixels.clear();
    for (x = 0; x <= 30 - mapped; x++) {
      pixels.setPixelColor(x, pixels.Color(0, 255, 255));
      lread();
      
    }
    pixels.show();
    lread();
    


  }


  while (lcm < 30) {
    for (x = 0; x < 30; x++) {
      pixels.setPixelColor(x, pixels.Color(255, 0, 0));
      lread();
      
    }
    pixels.show();
  }
  while (lcm > 70 && lcm < 200) {
    for (x = 0; x < 30; x++) {
      pixels.setPixelColor(x, pixels.Color(0, 255, 0));
      lread();
      
    }
    pixels.show();
  }
  while (cm >= 200) {
    for (x = 0; x < 30; x++) {
      pixels.setPixelColor(x, pixels.Color(0, 0 , 0));
      lread();
      

    }
    pixels.show();
  }
}
