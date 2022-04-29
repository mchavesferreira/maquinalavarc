//------------------------------------------------------------------------------------- //
//		AVR e Arduino: Técnicas de Projeto, 2a ed. - 2012.								//	
//------------------------------------------------------------------------------------- //
//=====================================================================================	//
//		ACIONANDO UM DISPLAY DE CRISTAL LIQUIDO DE 16x2									//
//			programa maquina de lavar utilizando timer 0																			//
//				, maquina de estados e funcoes											//
//=====================================================================================	//
#include <avr/interrupt.h>
#include "def_principais.h"			//inclusão do arquivo com as principais definições 
#include "LCD.h"
#include "variaveis.h"
#include "funcoes_maquina_lavar.h"

ISR(TIMER0_OVF_vect)					//interrupção do TC0
{   TCNT0=100; // 156 contagens equivalem a 10ms em 16mhz
	if(tempo) {   tempo--; 
  		          if(estado>6 && estado <14)
			         {
			          cmd_LCD(0x8D,0);     
		              ident_num(tempo/100,digitos);
		              cmd_LCD(digitos[2],1);
		              cmd_LCD(digitos[1],1);
		              cmd_LCD(digitos[0],1);
				     }
	          }
}

int main()
{		//declaração da variável para armazenagem dos digitos
	DDRB = 0b11111111;			//PB0 como pino de entrada, os demais pinos como saída
	PORTB= 0b11000011;				//habilita o pull-up do PB0		 
	DDRD = 0xFF;				//PORTD como saída (display)
	PORTD= 0xFF;				//desliga o display
	UCSR0B = 0x00;				//PD0 e PD1 como I/O genérico, para uso no Arduino
    DDRC= 0b00000000;  // saidas motor e valvulas
    PORTC= 0b11111111;
	inic_LCD_4bits();				//inicializa o LCD
	cmd_LCD(0x01,0); 				//desloca cursor para a segunda linha
	configura_temporizacao();
    tempo=150;  // tempo aguardar
while(1) 					//laço infinito
 { 
   switch(estado) 
   {
   case 0:   cmd_LCD(0x80,0);	escreve_LCD_Flash(msg_bemvindo); pressionado=0;	
             if(!tempo) {  estado++; cmd_LCD(0x01,0);  }   break;  //
   case 1:  configura_agitacao1();       break; //	 
   case 2:   configura_molho1();         break; // 
   case 3:   configura_agitacao2();       break; //  	 
   case 4:   configura_molho2(); break; //  
   case 5:   configura_centrifuga();   break; //  
   case 6:  inicializando();  break;
   case 7:  enchendo();  break;  // enchendo
   case 8:  agitacao1(); break; //agitacao 1
   case 9:  molho1();  break; // molho 1	   
   case 10: agitacao2(); break; //agitacao 2
   case 11: molho2();  break; // molho2	
   case 12: esvaziando(); break;  // esvaziando
   case 13: centrifuga();  break; // centrifuga	  
   case 14: reinicializando(); break; // reinicializando	  
   }   // fim switch
        
   if(estado>5) { if(!tst_bit(PINC,2))
	                { pressionado++; 
	                  if(pressionado>3000)
					    { estado=14; tempo=500; pressionado=0; }   
					} else {pressionado=0;} 
				} // botao emergencia			
  }//fim while
} // fim main
