#include "mbed.h"

#include "uLCD_4DGL.h"

PwmOut PWM1(D6);
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
AnalogOut Aout(D7);
Serial pc( USBTX, USBRX );
int sample = 128;
int i,j;
float ADCdata[128];
int main()

{   
    uLCD.printf("\n107061217\n"); //Default Green on black text
    uLCD.line( 50,  50 ,  50,  100,  RED);
    uLCD.line( 50,  100 ,  100,  100,  RED);
    uLCD.line( 100,  100 ,  100,  50,  RED);
    uLCD.line( 100,  50 ,  50,  50,  RED);

    PWM1.period(0.001);
    PWM1 = 0.1;
    while(1){
        for(i=0;i<10;i++){
            PWM1=PWM1+0.1;
            wait(0.1);
        }
        for(j=0;j<10;j++){
            PWM1=PWM1-0.1;
            wait(0.1);
        }
    }

    for (i = 0; i < sample; i++){

    
        Aout = PWM1;
        ADCdata[i] = PWM1;

        wait(0.1);

    }

    for (i = 0; i < sample; i++){

        pc.printf("%1.3f\r\n", ADCdata[i]);

        wait(0.1);

    }

}
    
    

    
}
