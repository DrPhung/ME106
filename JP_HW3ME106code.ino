#define PIN_SW10 10	//define switch 10 & 11
#define PIN_SW11 11
#define PIN_LED0 0	//define all LEDs from 0 - 7
#define PIN_LED0 0
#define PIN_LED1 1
#define PIN_LED2 2
#define PIN_LED3 3
#define PIN_LED4 4
#define PIN_LED5 5
#define PIN_LED6 6
#define PIN_LED6 7
#define SW_PR LOW	//define when buttons are pressed
#define LED_ON HIGH	//define LED output ON/OFF
#define LED_OFF LOW

void setup()
{
	pinMode(PIN_SW10, INPUT_PULLUP);	// Sets pin 10 to input
	pinMode(PIN_SW11, INPUT_PULLUP);	// Sets pin 11 to input
	pinMode(PIN_LED0, OUTPUT);	// Set the pin 0 - 7 to output
	pinMode(PIN_LED1, OUTPUT); 
	pinMode(PIN_LED2, OUTPUT); 
	pinMode(PIN_LED3, OUTPUT); 
	pinMode(PIN_LED4, OUTPUT); 
	pinMode(PIN_LED5, OUTPUT); 
	pinMode(PIN_LED6, OUTPUT); 
	pinMode(PIN_LED7, OUTPUT); 
}

void loop()
{
	int SW10_state = digitialRead(PIN_SW10);	//Read PIN 10 & 11
	int SW11_state = digitalRead(PIN_SW11);

		if (SW10_state == SW_PR)	//if SW10 signal LOW
		{
			digitalWrite(PIN_LED0, LED_ON);		//Output HIGH (ON) on LED 0 - 3 
			digitalWrite(PIN_LED1, LED_ON);
			digitalWrite(PIN_LED2, LED_ON);
			digitalWrite(PIN_LED3, LED_ON);
		}
		else
		{
			digitalWrite(PIN_LED0, LED_OFF);	//Out LOW (OFF) on LED 0 - 2
			digitalWrite(PIN_LED1, LED_OFF);
			digitalWrite(PIN_LED2, LED_OFF);
			digitalWrite(PIN_LED3, LED_OFF);
		}
  		if (SW11_state == SW_PR)		//if SW11 signal LOW
		{
			digitalWrite(PIN_LED4, LED_ON);		//Output HIGH (ON) on LED 4 - 7 
			digitalWrite(PIN_LED5, LED_ON); 
			digitalWrite(PIN_LED6, LED_ON); 
			digitalWrite(PIN_LED7, LED_ON); 
		}
		else 
		{
			digitalWrite(PIN_LED4, LED_OFF);	//Out LOW (OFF) on LED 4 - 7
			digitalWrite(PIN_LED5, LED_OFF);
			digitalWrite(PIN_LED6, LED_OFF);
			digitalWrite(PIN_LED7, LED_OFF);
		]
}
--------------------------------------
#6_PortStyle

#define PIN_SW10 PB2	//define switch 10 & 11 @ PortB PIN 2 & 3 
#define PIN_SW11 PB3
#define PIN_LED0 PD0	//define all LEDs from 0 - 7
#define PIN_LED1 PD1
#define PIN_LED2 PD2
#define PIN_LED3 PD3
#define PIN_LED4 PD4
#define PIN_LED5 PD5
#define PIN_LED6 PD6
#define PIN_LED7 PD7
#define SW_PR LOW	//define when buttons are pressed
#define LED_ON HIGH	//define LED output ON/OFF
#define LED_OFF LOW
#define BIT_MASK(bit) (1<<(bit))	//same as _BV(bit)

void setup()
{
	PORTD = 0;	//clears pins on PortD
	DDRD = BIT_MASK(PIN_LED0)|BIT_MASK(PIN_LED1)|BIT_MASK(PIN_LED2)|BIT_MASK(PIN_LED3)|BIT_MASK(PIN_LED4)|BIT_MASK(PIN_LED5)|BIT_MASK(PIN_LED6)|BIT_MASK(PIN_LED7);	//assigns LED 0 - 7 OUTPUT
	PORTB |= BIT_MASK(SW_10) | BIT_MASK(SW_11);	// PULLUP SWITCH_10 and SWITCH_11         
}

void loop()
{
	uint8_t current_PORTB, SW10_STATE, SW11_STATE;	//Read variables
	current_PORTB_state = PINB;	//PORTB Read/snapshot
	SW10_STATE = current_PORTB_state & BIT_MASK(SW10);	//PULLUP SW10 & SW11
	SW11_STATE = current_PORTB_State & BIT_MASK(SW11);
	if ( SW10_STATE == SW_PR )	//switch 10 pressed LOW
	{	
		PORTD |=(BIT_MASK(PIN_LED0)|BIT_MASK(PIN_LED1)|BIT_MASK(PIN_LED2)|BIT_MASK(PIN_LED3));	//Set Port D PIN 0-4 to 1 ON
  	}
	else
	{
		PORTD&=~(BIT_MASK(PIN_LED0)|BIT_MASK(PIN_LED1)|BIT_MASK(PIN_LED2)|BIT_MASK(PIN_LED3));	//Invert PIN 0-4 to 0 OFF
	}
	if (SW11_STATE == SW_PR )	//switch 11 pressed LOW
  	{
    		PORTD |=(BIT_MASK(PIN_LED4)|BIT_MASK(PIN_LED5)|BIT_MASK(PIN_LED6)|BIT_MASK(PIN_LED7));	//Set Port D PIN 4 - 7 to 1 ON
  	}
	else 
	{	
		PORTD&=~(BIT_MASK(PIN_LED4)|BIT_MASK(PIN_LED5)|BIT_MASK(PIN_LED6)|BIT_MASK(PIN_LED7));	//Invert PIN 4 - 7 to 0 OFF
	}

}
----------------------------------
#7 Arduino Style

#define PIN_SW10 10                   // defines button switches 
#define PIN_SW11 11
#define PIN_0 0                        //define PIN 0 & 9
#define PIN_9 9
#define LED_ON HIGH                    // LED ON/OFF
#define LED_OFF LOW
#define SW_PR LOW              //define when buttons are pressed
#define SW_unPR HIGH



void setup() 
{
 pinMode(PIN_0, OUTPUT);	//assigns LED segments 0 through 7 as OUTPUTs
 pinMode(PIN_9, OUTPUT);      
 pinMode(SW10, INPUT_PULLUP);	//assign SW10 & SW11 PULLUP
 pinMode(SWITCH_11, INPUT_PULLUP);                 
}

void loop() {
  SW10_state = digitalRead(SW10);	//reads SW10 and SW11 
  SW11_state = digitalRead(SW11);
  
  if(SW10_state == SW_PR )	//if SW10 is pressed 
{
    digitalWrite(PIN_0, LED_ON);	//HIGH LED 0
    delay(250);	//250 ms
    digitalWrite(PIN_0, LED_OFF);	//LOW LED 0 
    delay(250);	//off for 250 ms  
  }
  
  if( SW11_state == SW_PR )		//if SW11 is pressed
{
    digitalWrite(PIN_9, LED_ON);       //HIGH blink LED 9 at 2 Hz
    delay(250);
    digitalWrite(PIN_9, LED_OFF);		//LOW for 250 ms
    delay(250);		//blink LED 0 at 2 Hz	
  }
  
   if( SW10_state && SW11_state == SW_PR)	//When both SW10 & SW11 pressed
{
    digitalWrite(PIN_0, LED_ON);	//blink both LEDs 0 and 9 at 2 Hz
    digitalWrite(PIN_9, LED_ON);
    delay(250);
    digitalWrite(PIN_0, LED_OFF);
    digitalWrite(PIN_9, LED_OFF);
    delay(250);
  }
  
  else
  {
   digitalWrite(LED_0, LED_OFF);	//LEDs 0 and 9 OFF
   digitalWrite(LED_9, LED_OFF);
  }

}
-------------------------
#define PIN_SW10 PB2                   // Define switches in PortB
#define PIN_SW11 PB3
#define PIN_0 PD0                       //define LED 0 & 9 PORT D & B
#define PIN_9 PB1
#define LED_ON HIGH                    // LED ON/OFF
#define LED_OFF LOW
#define SW_PR LOW              //define when buttons are pressed
#define SW_unPR HIGH
#define BIT_MASK(bit) (1<<(bit))       //same as _BV(bit)


void setup() {
 PORTD = 0;                                             //clears pins on PORT D
 DDRD = BIT_MASK(PIN_0);                                // assigns LED 0 as output
 PORTB = 0;                                             //clears pins on PORT B
 DDRB = BIT_MASK(PIN_9);                                // assigns LED 9 as output 
 PORTB |= BIT_MASK(SW10) | BIT_MASK(SW11);    // assigns the pullups for button switches      
}

void loop() {                                    
  uint8_t current_PORTB_state, SW10_state, SW11_state;	//declares variables reading SW10 & 11
  current_PORTB_state = PIN B;	/PORTB snapshot taken
  SW_10_state = current_PORTB_state & BIT_MASK(SW_10);        //digitalRead
  SW11_state = current_PORTB_state & BIT_MASK(SW_11);
  
if(SW10_state == SW_PR) {      //SW_10 is pressed,
   PORTD = BIT_MASK(PIN_0);	//turns LED 0
   delay(250);	//on for 250 ms
   PORTD = ~(BIT_MASK(PIN_0));	//turns off LED 0
   delay(250);	//off for 250 ms  
 }                                                                              
 
if(SW11_state == SW_PR ){	//SW_11 is pressed,    
   PORTB = BIT_MASK(PIN_9);	//blink LED 9 at 2 Hz
   delay(250);                                              
   PORTB = ~(BIT_MASK(PIN_9));                          
   delay(250);                                            
  }
  
if(SW10_state && SW11_state == SW_PR ){       //both buttons pressed,
   PORTD = BIT_MASK(PIN_0);	 //blink LED 9 at 2 Hz
   PORTB = BIT_MASK(PIN_9);                             
   delay(250);                                            
   PORTD = ~(BIT_MASK(PIN_0));                          
   PORTB = ~(BIT_MASK(PIN_9));                        
   delay(250);                                               
}

else
  {
   PORTD = ~(BIT_MASK(PIN_0));	//LEDs 0 and 9  remain off
   PORTB = ~(BIT_MASK(PIN_9)); 
  }

}

