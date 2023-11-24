#include <LiquidCrystal.h>   // Biblioteca para LCD

#define IN1 8 // Definindo o pino 1 do motor
#define IN2 9 // Definindo o pino 2 do motor
#define pinVel 6  // Definindo o pino pwm de velocidade do motor

#define pinBot1 7 // Definindo o pino do botão 1
#define pinBot2 10  // Definindo o pino do botão 2

#define pinPot1 A0  // Definindo o pino do potenciometro

#define pinBuzzer 13  // Definindo o pino do buzzer

#define pinReset A1
  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Definindo os pinos do LCD
int tempo;

// Função para ligar o motor
void ligaMotor(){

  digitalWrite(IN1,HIGH); // Liga o pino 1 do motor 
  digitalWrite(IN2,LOW);  // Desliga o pino 2 do motor
  
}

// Função para parar o motor
void paraMotor(){

  digitalWrite(IN1,LOW); // Desliga o pino 1 do motor
  digitalWrite(IN2,LOW); // Desliga o pino 2 do motor
  
}

// Função para trabalhar com o botão 1
int pinBotao1Retencao() {
  
   #define tempoDebounce 50 //(tempo para eliminar o efeito Bounce EM MILISEGUNDOS)

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static int estadoRet = -1;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(pinBot1);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet++;
          if(estadoRet > 2){
            estadoRet = 0;
          }
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
   
}

// Função para trabalhar com o botão 1
bool pinBotao2Retencao() {
   #define tempoDebounce 50 //tempo para eliminar o efeito Bounce

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = true;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(pinBot2);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}

// Função para trabalhar com o display em relação a velocidade do motor
void displayVel(){
  
  int x = analogRead(pinPot1);
  int y = map(x,0,1023,1,8);
  static int Ant =-1;
  if(y!=Ant){
    lcd.clear();//Limpa o lcd
    lcd.print("Velocidade:");
    lcd.setCursor(0,1);
    lcd.print(y);
    lcd.print("k RPM");
    Ant = y;
    Serial.println("Velocidade:");
    Serial.println(y);
  }  
  
  delay(50);
  
}

// Função para trabalhar com o display em relação ao tempo de execução 
void displayTempo(){
  
  
  int x = analogRead(pinPot1);
  int y = map(x,0,1023,1,5);
  static int Ant =-1;
  if(y!=Ant){
    lcd.clear();//Limpa o lcd
    lcd.print("Tempo:");
    lcd.setCursor(0,1);
    lcd.print(y);
    lcd.print(" minutos");
    Ant = y;
    Serial.println("Tempo:");
    Serial.println(y);
  }  
  delay(50);
  
}

int velocidadeDoMotor(){
      
}


void setup() {
  
  lcd.begin(16, 2); 

  pinMode(IN1,OUTPUT); // Definindo o pino 1 do motor para saída
  pinMode(IN2,OUTPUT);  // Definindo o pino 2 do motor para saída
  pinMode(pinVel,OUTPUT); // Definindo o pino de velocidade do motor para saída
  
  pinMode(pinBuzzer,OUTPUT); // Definindo o pino do buzzer para saída
  
  pinMode(pinBot1,INPUT_PULLUP); // Definindo o pino do botão 1 para entrada no modo Input_PULLUP
  pinMode(pinBot2,INPUT_PULLUP);  // Definindo o pino do botão 2 para entrada no modo Input_PULLUP

  Serial.begin(9600); // Definindo a velocidade de comunicação entre o arduino e o computador 
}

void loop() {
  
  if(pinBotao1Retencao() == 0){
    displayTempo();
    tempo = map(analogRead(pinPot1),0,1023,1,5); 
    paraMotor();
  }
  else if(pinBotao1Retencao() == 1){
    displayVel();
    paraMotor();
    int a = map(analogRead(pinPot1),0,1023,0,255); // Lê o valor analogico do potenciometro e mapea para o valor pwm (0,255);
    analogWrite(pinVel,a);  // Define a velocidade do motor através de uma saida pwm
  }
  else if(pinBotao1Retencao() == 2){
    ligaMotor();
    unsigned long T = millis();
    static unsigned long Tmax = T + (tempo*60000); 
    if(millis()>Tmax){
      paraMotor();
    }
    static int tempos = tempo * 60;
    static unsigned long ant=0;
    if(millis()-ant>1000){
      lcd.clear();
      lcd.print("Tempo Restante:");
      lcd.setCursor(0,1);
      lcd.print(tempos);
      ant=millis();      
      tempos--; 
    }
    if(tempos==0){
      digitalWrite(pinBuzzer,HIGH);
      delay(500);
      digitalWrite(pinBuzzer,LOW);
      //Reseta o arduino. (Pesquisar)
      asm volatile ("jmp 0x0000");
    }
  }
}
