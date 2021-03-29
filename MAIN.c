#include "RoboCAR.h"


unsigned int psd_dist = 0;
unsigned char lineValue;



int main(void)
{ 
   unsigned char rcv_data;
   int e;

   UART_Init();
   BUZZER_Init();
   LED_Init();
   Timer1_PWM_Init();
   Timer0_Init();
   MOTOR_Init();
   PSD_Init();
   LineSensor_Init();
   


   Front_LED_on();   
   Forward();


   while(1)
   {
     UART_getch();
     rcv_data = RingBuff_Get(&ring);
     psd_dist = Get_dist_cm();
     lineValue = PINC;
     Hex2Bin_UART_OUT(lineValue);
     void send_dist_msg(psd_dist);



    if(psd_dist < 20) { 


    Stop(); 
    _delay_ms(10);

    Buzzer_on();
    _delay_ms(50);

    Buzzer_off();
    _delay_ms(50);

    Backward();
    _delay_ms(200);

    Left_turn();
    _delay_ms(400);

    Forward();
    _delay_ms(700);

    Right_turn();
    _delay_ms(400);
  
    Forward();
    _delay_ms(1000);

    Right_turn();
    _delay_ms(390);
  
    Forward(); //soso
    _delay_ms(670);
  
    Left_turn();
    _delay_ms(350);
    
    }    




	switch(lineValue)
    {

    	case 0b11100111:
  		case 0b11110111:
 	  	case 0b11101111:
    	case 0b11000011:
    	case 0b10000001:
 	  	case 0b11100110:
    	case 0b11110110:
    	case 0b11101110:
	  	case 0b11001111:
  		case 0b11110011:

      		Forward();
      		break;


    	case 0b11000111:
    	case 0b10011111:
    	case 0b11011111:
    	case 0b10111111:
    	case 0b00111111:
    	case 0b00001111:
    	case 0b10001111:
    	case 0b10000111:
    	case 0b10000011:
    	case 0b11000110:
    	case 0b11001110:
    	case 0b00001110:
    	case 0b10000110:
    	case 0b11011110:
    	case 0b10001110:
    	case 0b10011110:
    	case 0b10111110:
  	
		
			Speed_down();               
      		Forward_right(); 
	    	Speed_up();	
      		break;


 

    	case 0b11100011:
    	case 0b11111001:
    	case 0b11111101:
    	case 0b11111011:
  		case 0b11100001:
  		case 0b11110001:
  		case 0b11100010:
  		case 0b11110010:
  		case 0b11111010:
  		case 0b11100000:
  		case 0b11110000:
    	case 0b11111000:
    	case 0b11111100:
		case 0b10111000:
		case 0b10111001:
		case 0b10110001:
		


		case 0b10110011:
		case 0b10111100:

      		Speed_down();
			Forward_left();
			Speed_up();
      		break;



		case 0b01111111:                   
      
      		Right_turn();	
      		break;




    	case 0b11111110:                    

     		Left_turn();
   			break;
    


      
		default:

	    	Forward();
	    	break;
    }



   }
   return 0;
}
