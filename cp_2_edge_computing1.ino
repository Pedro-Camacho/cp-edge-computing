#include <LiquidCrystal.h>
#include <stdio.h>
#include <string.h>
//Definições global e inicialização de parametros-----
int delayTime=1000;

//leds e buzzer
int pinVerde=9;
int pinAmarelo=8;
int pinVermelho=7;
int buzzerPin=6;

//definição dos sensores:
//-Sensor de luminosidade LDR
int sensorLDR=A4;
int lightVal;


//-Sensor de temperatura DH11
int pinTemp=A3;
int valorCru;
double voltagem;
double tempC=0;

//potenciometro para simular umidade
int pinPotenciometro=A2;
int umidade;


//LCD iniciando
LiquidCrystal lcd(12,11,5,4,3,2);
//fim das definições---------------------------------

void setup()
{
  //iniciando algumas coisas
  //monitor serial
  Serial.begin(9600);
  
  //iniciando os pins de led e buzzer
  pinMode(pinVerde,OUTPUT);
  pinMode(pinAmarelo,OUTPUT);
  pinMode(pinVermelho,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  
  //sensor LDR
  pinMode(sensorLDR, INPUT);
  
  //potenciometro SIMULADO
  pinMode(pinPotenciometro,INPUT);
  
  //LCD display
  lcd.begin(16,2);
}

void loop()
{
  //PARTE DE LEITURAS-------------
  
  //leitura do ldr e conversão de 0 a 100
  lightVal=analogRead(sensorLDR);
  lightVal=map(lightVal,0,1023,0,100);
   
  //leitura e mapeamento do valor de temperatura
  valorCru=analogRead(pinTemp);
  voltagem=(valorCru/1023.0)*5000;
  tempC=(voltagem-500)*0.1;
  Serial.println(tempC);
    
  //ponteciometro simulando a umidade
  umidade = analogRead(pinPotenciometro);
  umidade=map(umidade,0,1023,20,90);
  
  //FIM DAS LEITURAS----------------
  
  //Lógica--------------------------
  
  //LOGICA DA LUMINOSIDADE
  
  
  //Serial.println(lightValOutput);
  //Serial.println(lightValMaped);
  
  if(lightVal > 50){
	
    //led vermelho liga e apita   	
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,HIGH);
    tone(buzzerPin,440);
    delay(500);
    noTone(buzzerPin);
    delay(200);
    
    //display ambiente muito claro
    lcd.clear();
    lcd.setCursor(0,0);
	lcd.print("Ambiente muito");
 	lcd.setCursor(0,1);
  	lcd.print("CLARO");
    delay(delayTime);
    
  }else if(lightVal > 30 && lightVal < 50){
  	
    //led amarelo liga sem apito
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,HIGH);
    digitalWrite(pinVermelho,LOW);
    noTone(buzzerPin);
    
    //display ambiente meia luz
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Ambiente a meia");
  	lcd.setCursor(0,1);
  	lcd.print("luz");
    delay(delayTime);
    
  }else{
  	
    //led verde sem apito
    digitalWrite(pinVerde,HIGH);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,LOW);
    noTone(buzzerPin);
    
  }
  
  
  //LOGICA TEMPERATURA
 
  if(tempC >= 10 && tempC <= 15){
    
	//leds desligados
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,LOW);
    noTone(buzzerPin);
    
    //display "temperatura ok"
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Temperatura Ok");
  	lcd.setCursor(0,1);
  	lcd.print("Temp. = ");
    lcd.setCursor(7,1);
    lcd.print(tempC);
    delay(delayTime);
    
  }else if(tempC > 15){
  	
    //display "Temp Alta +temp"
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,HIGH);
    digitalWrite(pinVermelho,LOW);
    
    //toca apito
    tone(buzzerPin,440);
    delay(500);
    noTone(buzzerPin);
    delay(200);
    
    //diplay temperatura Alta
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Temperatura ALTA");
  	lcd.setCursor(0,1);
  	lcd.print("Temp. = ");
    lcd.setCursor(7,1);
    lcd.print(tempC);
    delay(delayTime);
    
  }else if(tempC < 10){
  	
    //temp baixa led amarelo ligado
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,HIGH);
    digitalWrite(pinVermelho,LOW);
    
    //toca o apito
    tone(buzzerPin,440);
    delay(500);
    noTone(buzzerPin);
    delay(200);
    
    //display temp baixa
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Temperatura BAIXA");
  	lcd.setCursor(0,1);
  	lcd.print("Temp. = ");
    lcd.setCursor(7,1);
    lcd.print(tempC);
    delay(delayTime);
  
  }
  
  //LOGICA UMIDADE
  //umidade deve estar entre os valores de 50 a 70 
  if(umidade > 70){
  	
    //led Vermelho
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,HIGH);
    
    //toca apito
    tone(buzzerPin,440);
    delay(500);
    noTone(buzzerPin);
    delay(200);
    
    //display umidade Alta
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Umidade ALTA");
  	lcd.setCursor(0,1);
  	lcd.print("Umidade = ");
    lcd.setCursor(10,1);
    lcd.print(umidade);
    delay(delayTime);
    
  }else if(umidade < 50){
  	
    //led Vermelho liga
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,HIGH);
    
    //toca apito
    tone(buzzerPin,440);
    delay(500);
    noTone(buzzerPin);
    delay(200);
    
    //display umidade baixa
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Umidade BAIXA");
  	lcd.setCursor(0,1);
  	lcd.print("Umidade = ");
    lcd.setCursor(10,1);
    lcd.print(umidade);
    delay(delayTime);
    
  }else{  
    
    //leds desligados
    digitalWrite(pinVerde,LOW);
    digitalWrite(pinAmarelo,LOW);
    digitalWrite(pinVermelho,LOW);
    
    //sem buzina
    noTone(buzzerPin);
    
    //display umidade OK
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Umidade OK");
  	lcd.setCursor(0,1);
  	lcd.print("Umidade = ");
    lcd.setCursor(10,1);
    lcd.print(umidade);
    delay(delayTime);
    
  }
    
  delay(delayTime);
  

}