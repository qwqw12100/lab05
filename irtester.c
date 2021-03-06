#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"
#include <time.h>
/*  按下去0，不按是1  */
/*  有人是0，没人是1  */
  void ALARM_ARMED();
  void ALARM_ARMING();
  void ALARM_OFF();
  void ALARM_SOUNDING();
  void ALARM_TRIGGERED();

void ALARM_OFF() {

    digitalWrite (1, HIGH) ; /*绿灯亮 */   
    digitalWrite (2, LOW) ;  /*红灯灭 */ 
    digitalWrite (4, LOW) ; /*关喇叭 */ 
    
    while (digitalRead(3) == 1); 
	
    if (digitalRead(3) == 0){
		ALARM_ARMING();
    }
		
}

void ALARM_ARMING() {
	
	int k = 0;
    delay(10000);
    
	while(k<10){
	  
	  digitalWrite (1, HIGH) ; 
	  delay(1000) ;  
	  digitalWrite (1, LOW) ;
	  k++;
	  
	}
	
	digitalWrite (2, HIGH) ;
    ALARM_ARMED();

}

void ALARM_ARMED() {

    digitalWrite (1, LOW) ;
    digitalWrite (2, HIGH) ;
    digitalWrite (4, LOW) ;

    while(digitalRead(3) == 1 && digitalRead(0) == 1);
	 
	if (digitalRead(3) == 0){
		ALARM_OFF();
	}
     
	if (digitalRead(0) == 0){
		ALARM_TRIGGERED();
    }
}

void ALARM_TRIGGERED() {
  
    int i = 0;        
    delay(10000);
    
    while( i<5 && digitalRead(3) == 1) {
		digitalWrite (1, HIGH) ;
		digitalWrite (2, HIGH) ;
		delay(1000);
		digitalWrite (1, LOW) ;
		digitalWrite (2, LOW) ;
		delay(1000);
        i++;
    }
	
    if (digitalRead(3) == 0) { 
        ALARM_OFF();
    } 			
		
    if( i == 5){

        ALARM_SOUNDING();

    }

}

void ALARM_SOUNDING() {
	
    int j;
    while(digitalRead(3) == 1) {

          

            digitalWrite (1, HIGH) ;
            digitalWrite (2, HIGH) ;
			digitalWrite (4, HIGH) ;
            delay(2000);
            digitalWrite (1, LOW) ;
            digitalWrite (2, LOW) ;
			digitalWrite (4, LOW) ;
            delay(2000);
			
        for(j = 0; j < 1; j++) {

            ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/dImUb3e_p6ayih5X2iy8RE", "my1", "my 2", "my 33333");

        }

    }
	
	if (digitalRead(3) == 0) {
           
        ALARM_OFF();
           
    } 

}

int main(int argc, char *argv[])
{ 
  printf("wiringPiSetup Start\n"); 
  wiringPiSetup () ;
 
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
  ALARM_OFF();
}
