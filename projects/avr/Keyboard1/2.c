/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
� Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 15.09.2023
Author  : 
Company : 
Comments: 


Chip type               : ATmega8535
Program type            : Application
AVR Core Clock frequency: 16,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 128
*****************************************************/

#include <mega8535.h>
  void init(void)
  {
     PORTB = PORTB | 0x18; 
    PORTD = PORTD | 0x0C; 
  }
 char getKeyPressed(void)
 {          
    
    char pattern = 0xF0; // 11110000
    char sample; 
    // state: kbrd0-kbrd4 - 1    
    init();
    PORTB =  PORTB & 0xF7; //11110111 -> �������� � ���� � �� 4�� ���� 0 (= PBD3 = KBRD0)
    sample = PIND & pattern; //���� ����� � ������ �� ���������, �� sampe === pattern
    if (sample != pattern) { // key pressed
       return 0x08 | (sample ^ pattern); //returns 1000 as we're checking KBRD0 and a bit that corresponds KBRD4-KBRD7
    }
    //KBRD0 is checked - non of the keys is pressed    

    init();    
    PORTB = PORTB & 0xEF; //11101111 -> PB4 - KBRD1
    sample = PIND & pattern;
    if (sample != pattern) { // key pressed
       return 0x04 | (sample ^ pattern); //returns 0100 as we're checking KBRD1 and a bit that corresponds KBRD4-KBRD7
    }
    //KBRD1 is checked - non of the keys is pressed   
                         
    init();
    PORTD = PORTD & 0xFB; //11111011 -> PD2 - KBRD2
    sample = PIND & pattern;
    if (sample != pattern) { // key pressed
       return 0x02 | (sample ^ pattern); //returns 0010 as we're checking KBRD2 and a bit that corresponds KBRD4-KBRD7
    }
    //KBRD2 is checked - non of the keys is pressed          
    
    init();
    PORTD = PORTD & 0xF7; //11110111 -> PD3 - KBRD3
    sample = PIND & pattern;
    if (sample != pattern) { // key pressed
       return 0x01 | (sample ^ pattern); //returns 0001 as we're checking KBRD3 and a bit that corresponds KBRD4-KBRD7
    }            
    //KBRD0 is checked - non of the keys is pressed
    
    return 0; //none of the keys pressed 
 }
// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Reinitialize Timer 0 value
TCNT0=0x64;
// Place your code here.
 // outs
 //  KBRD0 - PB3
 //  KBRD1 - PB4  //00011000
 //  KBRD2 - PD2
 //  KBRD3 - PD3  //00001100
 // ins
 //  KBRD4 - PD4
 //  KBRD5 - PD5
 //  KBRD6 - PD6
 //  KBRD7 - PD7
 
 PORTC = getKeyPressed();
}

// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=Out Func3=Out Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=0 State3=0 State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x18;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0x00;
DDRC=0xFF;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=Out Func2=Out Func1=In Func0=In 
// State7=P State6=P State5=P State4=P State3=0 State2=0 State1=T State0=T 
PORTD=0xF0;
DDRD=0x0C;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 15,625 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x05;
TCNT0=0x64;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 62,500 kHz
// Mode: CTC top=OCR1A
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x0C;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x01;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here

      }
}
