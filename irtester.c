#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"
#include <time.h>
<<<<<<< HEAD

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

    digitalWrite (1, LOW) ;
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
  
    int i = 0;        
    delay(10000);
    
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
	
    int j;
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
        
        for(j = 0; j < 1; j++) {

            ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/dImUb3e_p6ayih5X2iy8RE", "my1", "my 2", "my 33333");

        }

    }

}

=======
>>>>>>> f047075907f1f4c40d75d23d8195814329f3018f
int main(int argc, char *argv[])
{
  int i; 
  printf("wiringPiSetup Start\n"); 
  wiringPiSetup () ;
<<<<<<< HEAD
 
 printf("pinMode 0 start\n");
  pinMode(0, INPUT);	/* motion sensor */

printf("pinMode 01 start\n");

  pinMode(1, OUTPUT);	/* led 1 */

printf("pinMode 02 start\n");

  pinMode(2, OUTPUT);	/* led 2 */
printf("pinMode 03 start\n");

  pinMode(3, INPUT);	/* switch */
printf("pinMode 04 start\n");

  pinMode(4, OUTPUT);	/* buzzer */
printf("pinMode 05 start\n");

  pullUpDnControl(3, PUD_UP) ;
printf("pinMode 06 start\n");

=======
  pinMode(0, INPUT);	// motion sensor
  pinMode(1, OUTPUT);	// led 1
  pinMode(2, OUTPUT);	// led 2
  pinMode(3, INPUT);	// switch
  pinMode(4, OUTPUT);	// buzzer
  pullUpDnControl(3, PUD_UP) ;
>>>>>>> f047075907f1f4c40d75d23d8195814329f3018f
  /*NOTREACHED*/
  return 0 ;
}

<<<<<<< HEAD

=======
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
        digitalWrite (1, LOW ;
        digitalWrite (2, LOW) ;
        delay(2000);
        i++

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
            digitalWrite (1, LOW ;
            digitalWrite (2, LOW) ;
            delay(2000);
           
        for(int j = 0; j < 1; j++) {

            ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/dImUb3e_p6ayih5X2iy8RE", "my1", "my 2", "my 33333");

        }

    }

}
>>>>>>> f047075907f1f4c40d75d23d8195814329f3018f
