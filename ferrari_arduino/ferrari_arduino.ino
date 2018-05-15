#include <SoftwareSerial.h>

#define PININ1 7
#define PININ2 5
#define PININ3 4
#define PININ4 2
#define PINENA 6
#define PINENB 3

#define PINTX 9
#define PINRX 8

#define TURN_SPEED 255
int SPEED;

char goAhead;
char turn;

SoftwareSerial bluetooth(PINRX, PINTX);

void setup() {

  initPins();
  setCarSpeed(150);
  bluetooth.print("Velocidade: ");
  bluetooth.println(SPEED);
  
}

void loop() {
  
  if (bluetooth.available()) {
    
    String option = bluetooth.readStringUntil(';');
    ferrari_control(option);

  }

}
