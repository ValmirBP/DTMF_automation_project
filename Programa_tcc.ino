
#define pinBit01  5 // Q0
#define pinBit02  4 // Q1
#define pinBit03  3 // Q2
#define pinBit04  2 // Q3
#define pinBitStd 1 // STD

int led;
int led6 = 6;
int led7 = 7;
int led8 = 8;
int led9 = 9;
int led10 = 10;
int led11 = 11;
int led12 = 12;
int led13 = 13;

int tecla = 0;

int bit01 = 0;   
int bit02 = 0; 
int bit03 = 0; 
int bit04 = 0; 
int bitStd= 0; 

int LED_STATE;
int LED_STATE6 = LOW; // Estado do Relé LOW (Desligado)
int LED_STATE7 = LOW;
int LED_STATE8 = LOW;
int LED_STATE9 = LOW;
int LED_STATE10 = LOW; // Estado do Relé LOW (Desligado)
int LED_STATE11 = LOW;
int LED_STATE12 = LOW;
int LED_STATE13 = LOW;

void setup() { 
    for(led=6; led<=13; led++){
    pinMode(led, OUTPUT); // Definimos o pino do led como Saída de um em um
  }
  Serial.begin(9600); // Iniciamos a Serial com Baudrate 9600
  Serial.println("Aguardando tecla de comando..."); // Exibimos a mensagem no terminal...
}

void loop(){ 
  bitStd = digitalRead(pinBitStd); //Lê o estado do pino STD e armazena em 'bitStd' 
  if (bitStd == HIGH) {//Se estiver em nível alto fará as leituras 
                       //dos bits dos pinos Q3, Q2, Q1 e Q0
    bit01 = digitalRead(pinBit01);   
    bit02 = digitalRead(pinBit02); 
    bit03 = digitalRead(pinBit03); 
    bit04 = digitalRead(pinBit04); 
    tecla = (bit04 * 8) + (bit03 * 4) + (bit02 * 2) + (bit01 * 1);//Conversão binária para 
                                                                 //decimal (ver Vídeo1)
    Serial.print("Recebido: "); // Exibe a mensagem
    switch (tecla){ // Seleciona a tecla pressionada

    case 1: // Tecla 1
      Serial.println("1");     
      /* COMANDO PARA RELE1 */
      LED_STATE6 = !LED_STATE6; // Guarda o estado INVERTIDO do Relé.     
      break;

    case 2: // Tecla 2
      Serial.println("2");
      LED_STATE7 = !LED_STATE7;      
      break;

    case 3: // Tecla 3
      Serial.println("3");
      LED_STATE8 = !LED_STATE8;
      break;

    case 4: // Tecla 4
      Serial.println("4");
      LED_STATE9 = !LED_STATE9;
      break;

    case 5: // Tecla 5
      Serial.println("5");
      LED_STATE10 = !LED_STATE10;
      break;

    case 6: // Tecla 6
      Serial.println("6");
      LED_STATE11 = !LED_STATE11;
      break;

    case 7: // Tecla 7
      Serial.println("7");
      LED_STATE12 = !LED_STATE12;
      break;

    case 8: // Tecla 8
      Serial.println("8");
      LED_STATE13 = !LED_STATE13;
      break;

    case 9: // Tecla 9
      Serial.println("9");
      break;

    case 10: // Tecla 0
      Serial.println("0");
      break;

    case 11: // Tecla *
      Serial.println("*");
      LED_STATE6 = LOW;
      LED_STATE7 = LOW;
      LED_STATE8 = LOW;
      LED_STATE9 = LOW;
      LED_STATE10 = LOW;
      LED_STATE11 = LOW;
      LED_STATE12 = LOW;
      LED_STATE13 = LOW;
      break;
      
    case 12: // Tecla #
      Serial.println("#");
      LED_STATE6 = HIGH;
      LED_STATE7 = HIGH;
      LED_STATE8 = HIGH;
      LED_STATE9 = HIGH;
      LED_STATE10 = HIGH;
      LED_STATE11 = HIGH;
      LED_STATE12 = HIGH;
      LED_STATE13 = HIGH;
      break;
      
    digitalWrite(led6, LED_STATE6);//Liga ou desliga o Relé1 conforme o estado (HIGH/ LOW)
    digitalWrite(led7, LED_STATE7);
    digitalWrite(led8, LED_STATE8);
    digitalWrite(led9, LED_STATE9);
    digitalWrite(led10, LED_STATE10);
    digitalWrite(led11, LED_STATE11);
    digitalWrite(led12, LED_STATE12);
    digitalWrite(led13, LED_STATE13);

    // Zeram-se todas as variáveis 
    tecla = 0;
    bit01 = 0;   
    bit02 = 0; 
    bit03 = 0; 
    bit04 = 0; 
    bitStd= 0; 
    delay (500); // Aguarda 500 milissegundos
    }
  }
}
