# Controle de qualidade de ambiente - Vinheria Agnello
Este projeto utiliza um Arduino para analisar a luminosidade, umidade e temperatura do ambiente e fornecer feedback visual e sonoro com base nos níveis detectados no ambiente.


## 🎞 Link para o video apresentação
https://youtu.be/Rav6Fh_S70s?si=kCGdZI0JyIL8xG_h

## 💎 Link do Tinkercad
https://www.tinkercad.com/things/fKGiNdFgFVz-cp-2-edge-computing/editel?sharecode=LyKbskernQdqQkDC5pe_rcEi3F8IRImHuWMPRVCaP0w

## 🔨 Montagem
### Componentes necessários
1. Arduino Uno
2. Sensor LDR (Light Dependent Resistor)
3. Buzzer
4. 3 LEDs (vermelho, verde, amarelo)
5. 4 resistores de 1kohm
6. 1 resistor de 10kohm
7. Display LCD 16x2


### Sensor LDR
1. Conecte uma ponta do sensor LDR a corrente 5 volts.
2. Conecte a outra ponta do sensor a um resistor de 1kohm, e conecte o outro terminal do resistor ao GND (terra).
3. Conecte um fio do sensor LDR a entrada analógica A4 do Arduino.
   
### Buzzer
1. Conecte a perna positiva do buzzer a uma porta digital 6 do arduino.
2. Conecte a perna negativa do buzzer ao GND (terra) do Arduino.
   
### LEDs
1. Conecte cada perna positiva dos LEDs a um resistor de 1kohm.
2. Conecte as pernas negativas a ccorrente GND
3. Conecte as pernas positiva dos LEDs verde, amarelo e vermelho as portas "9", "8" e "7", respectivamente.

### Display lcd
1. Conecte a porta "GND" e "V0" ao terra e a porta "VCC" a corrente 5 volts
2. Concte as portas "RS", "RW" e "E" respectivamente as portas digitais "12", "10" e "11" do arduino
3. mantenha as portas "DB0", "DB1", "DB2" e "DB3" desconectadas
4. Conecte as portas "DB4", "DB5", "DB6" e "DB7" respectivamente as portas digitais "5", "4", "3", "2"
5. Por fim, conecte a porta "LED ANODO" a corrente 5 volts e a "LED CATÓTICO" ao GND

### Potenciomentro (simular umidade)
1. Conecte uma das pernas das extremidades a corrente GND e outra a 5 volts (Atenção para não conecta-las invertidas)
2. Conecte o seu pino central a porta analogica "A2" do arduino

### Sensor de temperatura
1. Conecte uma das pernas das extremidades a corrente GND e outra a 5 volts (Atenção para não conecta-las invertidas)
2. Conecte o seu pino central a porta analogica "A3" do arduino



## ⚙ Funcionamento

![arduino](https://github.com/Pedro-Camacho/cp-edge-computing/assets/112903512/ec617ea0-9721-43fe-a7f4-c6d29c7d125c)

## Instalação de dependecias
Para a execução da aplicação será necessária a instalção da biblioteca Liquid Crystal

O sistema é divido entre as três principais grandezas analisadas:

> Os valores de luminosidade e umidade foram convertidos em uma escalas de 0 a 100 com base na amplitude dos seus respectivos sensores para facilitar a analise

### Luminosidade

#### Luminosidade menor que 30
- Enquanto a luminosidade for menor do que 30 o led verde se manterá acesso
- o ambiente está na luminosidade ideal
  
#### Luminosidade maior que 30 e menor que 50
- Enquanto a luminosidade estiver nessa faixa o led amarelo se manterá acesso
- O ambiente está a meia luz
- Manter vigilancia

#### Luminosidade maior 50
- Enquanto a luminosidade estiver nessa faixa o led vermelho se manterá acesso
- O ambiente está com muita luminosidade
- Agir imediatamente
- Alerta sonoro
  

  
### Umidade
#### umidade menor que 50
- Enquanto a umidade estiver nessa faixa, nenhum led se manterá acesso
- Display mostrará a mensagem "umidade baixa"
  
#### umidade maior que 50 e menor que 70
- Enquanto a umidade estiver nessa faixa, o led amarelo se manterá acesso
- Display mostrará a mensagem "umidade OK"
- Alerta sonoro
- Manter vigilancia

#### umidade maior que 70
- Enquanto a umidade estiver nessa faixa, o led vermelho se manterá acesso
- Display mostrará a mensagem "umidade ALTA"
- Alerta sonoro
- Agir imediatamente


  
### Temperatura 
#### temperatura menor que 10
- Enquanto a umidade estiver nessa faixa, nenhum led se manterá acesso
- Display mostrará a mensagem "temperatura baixa"
  
#### temperatura maior que 10 e menor que 15
- Enquanto a umidade estiver nessa faixa, o led amarelo se manterá acesso
- Display mostrará a mensagem "temperatura OK"
- Alerta sonoro
- Manter vigilancia

#### temperatura maior que 15
- Enquanto a umidade estiver nessa faixa, o led vermelho se manterá acesso
- Display mostrará a mensagem "temperatura ALTA"
- Alerta sonoro
- Agir imediatamente


## 🙎‍♂️🙎‍♀️ INTEGRANTES

- Pedro Almeida Camacho rm: 556831
- Camila Pedroza da Cunha rm: 558768
- Isabelle Dallabeneta rm: 554592
- Nicoli Amy Kassa rm: 559104
- Diógenes Henrique do Santos Costa rm: 559127
