#define motoragitacao   PB4
#define valvulaencher PB3
#define valvulaesvaziar PB2
#define  ENTER PC2
#define  MENOS PC1
#define  MAIS PC0
#define  sensorvazio PC4
#define  sensorcheio PC3


// variaveis
unsigned int tempo=0,pressionado=0;
unsigned char tempoagitacao1=2,tempoagitacao2=3,tempomolho1=3,tempomolho2=5, tempocentrifuga=6;
unsigned char  estado=0;	//declara variável global

volatile  unsigned char conta;

unsigned char digitos[tam_vetor];
volatile unsigned char segundos, minutos, horas;
PROGMEM const char msg_bemvindo[] = "Bem vindo !!!            \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_agitacao1[] = "Primeira Agitacao     \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_molho1[] = "Tempo Molho 1     \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_agitacao2[] = "Segund Agitacao     \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_molho2[] = "Tempo Molho 2       \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_centrifuga[] = "Tempo Centrifuga     \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_inicializando[] = "Em processo....   \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_fim[] = "Fim do processo      \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_enchendo[] = "Enchendo      \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_esvaziando[] = "Esvaziando      \0"; //mensagem armazenada na memória flash
PROGMEM const char msg_reiniciando[] = "Reiniciando....  \0"; //mensagem armazenada na memória flash
