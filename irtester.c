#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"
#include <time.h>

  void ALARM_ARMED();
  void ALARM_ARMING();
  void ALARM_OFF();
  void ALARM_SOUNDING();
  void ALARM_TRIGGERED();

void ALARM_OFF() {

    digitalWrite (1, LOW) ;    
    digitalWrite (2, LOW) ;  
    digitalWrite (4, LOW) ;
    
    if (digitalRead(3) == 0) {

        ALARM_ARMING();

    }

}

void ALARM_ARMING() {

    delay(10000);
    digitalWrite (1, HIGH) ; delay(1000) ;  
    digitalWrite (1,  LOW) ;
    digitalWrite (2, HIGH) ;
    ALARM_ARMED();

}

void ALARM_ARMED() {

    digitalWrite (1,  LOW) ;
    digitalWrite (2, HIGH) ;
    digitalWrite (4, LOW) ;

    if (digitalRead(3) == 0) {

        ALARM_OFF();

    }

     if (digitalRead(0) == 0) {

        ALARM_TRIGGERED();

    }

}

void ALARM_TRIGGERED() {
        
    delay(10000);
    int i = 0;
    
    while(i<5) {

        if (digitalRead(3) == 0) {
     
            ALARM_OFF();
            break;

        }   

        digitalWrite (1, HIGH) ;
        digitalWrite (2, HIGH) ;
        delay(2000);
        digitalWrite (1, LOW) ;
        digitalWrite (2, LOW) ;
        delay(2000);
        i++;

    }
    
    if( i == 5){

        ALARM_SOUNDING();

    }

}

void ALARM_SOUNDING() {

    while(1) {

        if (digitalRead(3) == 0) {
            
            ALARM_OFF();
            break;
           

        }   

            digitalWrite (1, HIGH) ;
            digitalWrite (2, HIGH) ;
            delay(2000);
            digitalWrite (1, LOW);
            digitalWrite (2, LOW) ;
            delay(2000);
           
        for(int j = 0; j < 1; j++) {

            ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/dImUb3e_p6ayih5X2iy8RE", "my1", "my 2", "my 33333");

        }

    }

}

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);	// motion sensor
  pinMode(1, OUTPUT);	// led 1
  pinMode(2, OUTPUT);	// led 2
  pinMode(3, INPUT);	// switch
  pinMode(4, OUTPUT);	// buzzer
  pullUpDnControl(3, PUD_UP) ;

  /*NOTREACHED*/
  return 0 ;
}


