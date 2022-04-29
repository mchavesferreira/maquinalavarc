
void enchendo();
void agitacao1();
void agitacao2();
void molho1();
void molho2();
void esvaziando();
void centrifuga();
void reinicializando();
void configura_temporizacao();
void imprime_relogio();

void configura_agitacao1()
 { cmd_LCD(0x80,0); 	escreve_LCD_Flash(msg_agitacao1);
	 ident_num(tempoagitacao1,digitos);
	 cmd_LCD(0xC5,0);			//desloca o cursor para que os 3 digitos fiquem a direita do LCD
	 cmd_LCD(digitos[2],1);
	 cmd_LCD(digitos[1],1);
	 cmd_LCD(digitos[0],1);
	 cmd_LCD(0xC9,0);
	 cmd_LCD('<',1);
	 cmd_LCD('E',1);
	 cmd_LCD('N',1);
	 cmd_LCD('T',1);
	 cmd_LCD('E',1);
	 cmd_LCD('R',1);
	 cmd_LCD('>',1);
	 if(!tst_bit(PINC,0)) { tempoagitacao1++; _delay_ms(100);}
	 if(!tst_bit(PINC,1)) { tempoagitacao1--; _delay_ms(100); }
	 if(!tst_bit(PINC,2)) { estado++;  _delay_ms(300); cmd_LCD(0x01,0); }
 }
 
 void configura_molho1()
   {    cmd_LCD(0x80,0); 	escreve_LCD_Flash(msg_molho1);
	   ident_num(tempomolho1,digitos);
	   cmd_LCD(0xC5,0);			//desloca o cursor para que os 3 digitos fiquem a direita do LCD
	   cmd_LCD(digitos[2],1);
	   cmd_LCD(digitos[1],1);
	   cmd_LCD(digitos[0],1);
	   cmd_LCD(0xC9,0);
	   cmd_LCD('<',1);
	   cmd_LCD('E',1);
	   cmd_LCD('N',1);
	   cmd_LCD('T',1);
	   cmd_LCD('E',1);
	   cmd_LCD('R',1);
	   cmd_LCD('>',1);
	   if(!tst_bit(PINC,0)) { tempomolho1++; _delay_ms(100);}
	   if(!tst_bit(PINC,1)) { tempomolho1--; _delay_ms(100); }
	   if(!tst_bit(PINC,2)) { estado++;  _delay_ms(300); cmd_LCD(0x01,0); }
   }

void configura_agitacao2() 
{  cmd_LCD(0x80,0); 	escreve_LCD_Flash(msg_agitacao2);
	ident_num(tempoagitacao2,digitos);
	cmd_LCD(0xC5,0);			//desloca o cursor para que os 3 digitos fiquem a direita do LCD
	cmd_LCD(digitos[2],1);
	cmd_LCD(digitos[1],1);
	cmd_LCD(digitos[0],1);
	cmd_LCD(0xC9,0);
	cmd_LCD('<',1);
	cmd_LCD('E',1);
	cmd_LCD('N',1);
	cmd_LCD('T',1);
	cmd_LCD('E',1);
	cmd_LCD('R',1);
	cmd_LCD('>',1);
	if(!tst_bit(PINC,0)) { tempoagitacao2++; _delay_ms(100);}
	if(!tst_bit(PINC,1)) { tempoagitacao2--; _delay_ms(100); }
	if(!tst_bit(PINC,2)) { estado++;  _delay_ms(300); cmd_LCD(0x01,0); }
}


void configura_centrifuga()
{ cmd_LCD(0x80,0); 	escreve_LCD_Flash(msg_centrifuga);
	ident_num(tempocentrifuga,digitos);
	cmd_LCD(0xC5,0);			//desloca o cursor para que os 3 digitos fiquem a direita do LCD
	cmd_LCD(digitos[2],1);
	cmd_LCD(digitos[1],1);
	cmd_LCD(digitos[0],1);
	cmd_LCD(0xC9,0);
	cmd_LCD('<',1);
	cmd_LCD('E',1);
	cmd_LCD('N',1);
	cmd_LCD('T',1);
	cmd_LCD('E',1);
	cmd_LCD('R',1);
	cmd_LCD('>',1);
	if(!tst_bit(PINC,0)) { tempocentrifuga++; _delay_ms(100);}
	if(!tst_bit(PINC,1)) {tempocentrifuga--; _delay_ms(100); }
	if(!tst_bit(PINC,2)) { estado++;  _delay_ms(300); cmd_LCD(0x01,0); tempo=150; }
}

void inicializando()
  { cmd_LCD(0x80,0); 	escreve_LCD_Flash(msg_inicializando);
	  ident_num(tempo/10,digitos);
	  cmd_LCD(0xC5,0);
	  cmd_LCD(digitos[2],1);
	  cmd_LCD(digitos[1],1);
	  cmd_LCD(digitos[0],1);
	  if(!tempo) {  estado++;  cmd_LCD(0xC0,0);	escreve_LCD_Flash(msg_enchendo); }
  }

void configura_molho2()
  {cmd_LCD(0x80,0); 	escreve_LCD_Flash(msg_molho2);
	  ident_num(tempomolho2,digitos);
	  cmd_LCD(0xC5,0);			//desloca o cursor para que os 3 digitos fiquem a direita do LCD
	  cmd_LCD(digitos[2],1);
	  cmd_LCD(digitos[1],1);
	  cmd_LCD(digitos[0],1);
	  cmd_LCD(0xC9,0);
	  cmd_LCD('<',1);
	  cmd_LCD('E',1);
	  cmd_LCD('N',1);
	  cmd_LCD('T',1);
	  cmd_LCD('E',1);
	  cmd_LCD('R',1);
	  cmd_LCD('>',1);
	  
	  if(!tst_bit(PINC,0)) { tempomolho2++; _delay_ms(100);}
	  if(!tst_bit(PINC,1)) { tempomolho2--; _delay_ms(100); }
	  if(!tst_bit(PINC,2)) { estado++;  _delay_ms(300); cmd_LCD(0x01,0); }
	  
  }

void enchendo(){
	
	set_bit(PORTB,valvulaencher); 
    if(!tst_bit(PINC,sensorcheio))
	    { clr_bit(PORTB,valvulaencher); 
           estado++; 
          tempo=tempoagitacao1*100; 
          cmd_LCD(0xC0,0);	
          escreve_LCD_Flash(msg_agitacao1); 
		}
	
}


void agitacao1() {

  set_bit(PORTB,motoragitacao); 
  if(!tempo) {
             clr_bit(PORTB,motoragitacao); 
             estado++;
			 tempo=tempomolho1*100;
             cmd_LCD(0xC0,0);	
	         escreve_LCD_Flash(msg_molho1); 
	         }
    }	  
  
  void molho1()
      { if(!tempo) 
         { estado++; cmd_LCD(0xC0,0);	
           escreve_LCD_Flash(msg_agitacao2); 
           tempo=tempoagitacao2*100; 
		 }
    }	  
  
void agitacao2()  
   { 
	set_bit(PORTB,motoragitacao); 
	if(!tempo) 
	       { clr_bit(PORTB,motoragitacao); 
			   estado++; 
			   tempo=tempomolho2*100; 
			   cmd_LCD(0xC0,0);	
			   escreve_LCD_Flash(msg_molho2); 
			 }  
   } 
	  
void molho2()  
    {  if(!tempo) 
		 {   estado++; 
			 cmd_LCD(0xC0,0);	
			 escreve_LCD_Flash(msg_esvaziando);  
		 }  
	} 


void esvaziando() 
     { set_bit(PORTB,valvulaesvaziar);  
		if(!tst_bit(PINC,sensorvazio)) 
      		{ clr_bit(PORTB,valvulaesvaziar); 
			  estado++;
			  tempo=tempocentrifuga*100; 
			  cmd_LCD(0xC0,0);	
			  escreve_LCD_Flash(msg_centrifuga); 
			} 
	 }
	
void centrifuga() 
    { set_bit(PORTB,motoragitacao); 
		  if(!tempo) 
		       { clr_bit(PORTB,motoragitacao); 
				    estado++; 
					cmd_LCD(0xC0,0);	
					escreve_LCD_Flash(msg_fim); 
				    tempo=500;	
				 } 
  } 

void reinicializando() 
   {  clr_bit(PORTB,motoragitacao);  
	  clr_bit(PORTB,valvulaencher); 
	  clr_bit(PORTB,valvulaesvaziar);
	  cmd_LCD(0x01,0);
      escreve_LCD_Flash(msg_reiniciando);
 	  if(!tempo)
	       { estado=0; }	
	}
	
void imprime_relogio() {
	 	 cmd_LCD(0xC0,0);				
    	 ident_num(minutos,digitos);
		 cmd_LCD(digitos[1],1);
			 cmd_LCD(digitos[0],1);
			 cmd_LCD(':',1);
			 ident_num(segundos,digitos);
			cmd_LCD(digitos[1],1);
			cmd_LCD(digitos[0],1);
	  }

void configura_temporizacao() {
	
	/* TCCR0A  Registrador de controle A do TC0
	COM0A1 COM0A0 COM0B1 COM0B0  -     -     WGM01 WGM00
	 7        6     5      4     3     2       1     0

	 COM0A1 COM0A0 controlam o comportamento do pino 0C0A (modos normal, CTC, pwm rapido)
	   0      0  - pino 0C0A desconectado
	   0      1  - mudanca de estado na igualdade
	   1      0  - aterrado na igualdade
	   1      1  - Ativo  na igualdade

	   COM0B1 COM0B0  controlam o comportamento do pino 0C0B
	   0      0  - pino 0C0B desconectado
	   0      1  - mudanca de estado na igualdade
	   1      0  - aterrado na igualdade
	   1      1  - Ativo  na igualdade

	   WGM02 WGM01 WGM00 bits do modo de controle, fonte do valor maximo e forma de onda
	   0     0     0  - normal     TOP em FF
	   0     0     1  - pwm fase corrigida top em FF
	   0     1     0  - CTC        TOP em 0CR0A
	   0     1     1  - pwm rapido  TOP em FF
	   1     0     0  - 
	   1     0     1  - pwm fase corrigida top em 0CR0A
	   1     1     0   -
	   1     1     1  - pwm rapido TOP em 0CR0A
	*/
	
	TCCR0B = (1<<CS02) | (1<<CS00);		//TC0 com prescaler de 1024, a 16 MHz gera uma interrupção a cada 16,384 ms
	/* TCCR0B  Registrador de controle B do TC0
	F0C0A  FOC0B   -    -   WGM02  CS02  CS01  CS00
	7        6     5    4     3      2    1      0

	CS02  CS01  CS00  bits de selecao do prescaler
	   0     0     0  - sem fonte de clock tc0 parado
	   0     0     1  - prescaler =1
	   0     1     0  - prescaler = 8
	   0     1     1  - prescaler = 64
	   1     0     0  - prescaler = 256
	   1     0     1  - prescaler = 1024
	   1     1     0  - clock externo pino T0 (pd4) contagem borda descida
	   1     1     1  - clock externo pino T0 (pd4) contagem borda subida     
	*/

	TIMSK0 = 1<<TOIE0;					//habilita a interrupção do TC0
	/* TIMSK0 Interruptor de mascara do contador TC0
	- - - - - 0CIE0B 0CIE0A TOIE0
	7 6 5 4 3   2      1      0
	0CIE0B ativa a interrupção na igualdade de comparação 0CR0B
	0CIE0A ativa a interrupção na igualdade de comparação 0CR0A
	TOIE0  ativa a interrupção de estouro em TOP=FF

	*/
  TCNT0=100;
	
	sei();								//habilita interrupções globais

   conta=100;
	
}