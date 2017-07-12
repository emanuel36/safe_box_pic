#ifndef PWM_H
#define	PWM_H
    
#include <xc.h>
 
void PWM_Init();
int setPeriodTo(unsigned long FPWM);
void SetDutyCycleTo(float Duty_cycle, int Period);

#define MINTHR              8000
#define RESOLUTION          488

#define InternalOsc_8MHz    8000000
#define InternalOsc_4MHz    4000000
#define InternalOsc_2MHz    2000000
#define InternalOsc_1MHz    1000000
#define InternalOsc_500KHz  500000
#define InternalOsc_250KHz  250000
#define InternalOsc_125KHz  125000
#define InternalOsc_31KHz   31000

#define Timer2Prescale_1    1
#define Timer2Prescale_4    4
#define Timer2Prescale_16   16

int Period;

#endif	/* PWM_H */