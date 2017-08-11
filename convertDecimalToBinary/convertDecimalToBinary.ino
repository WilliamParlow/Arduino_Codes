/**

  # Convert decimal numbers to binary syntax

  This program blablabla blablabla blablabla blablabla

      ##########
    #             #
  #   #####    #
  #  #      #     #
  #  #      #     #
  #  #     #     #
  #   ####      #
  #             #
  ###############

*/

// Libs para execução da operação matemática
#include <math.h>

// Lib para emular interface serial
#include <SoftwareSerial.h>

// Bibliotecas do LCD Picasso

#include <Picaso_Const4D.h>
#include <Picaso_Serial_4DLib.h>


// Emulação de uma interface serial nos pinos 2 e 3
SoftwareSerial mySerial(2, 3); // RX, TX



// Definindo variável DesplaySerial do tipo da serial emulada criada
#define DisplaySerial mySerial



// Utiliza da mySerial para se comunicar com o display
Picaso_Serial_4DLib Display(&DisplaySerial);



// Definição das variáveis
String binaryString = "";
unsigned int decimalValue;
unsigned int len;





void setup() {

  // Timeout delay para cada comando enviado
  Display.TimeLimit4D = 5000;

  // Inicializando seriais
  DisplaySerial.begin(9600);
  Serial.begin(9600);

  // Tempo para inicialização do display
  delay (5000);

  // Define o modo
  Display.gfx_ScreenMode(LANDSCAPE);

  // Define cor de background
  Display.gfx_BGcolour(BLACK) ;

  // Limpa a tela, pois possui uma inicialização com informações da placa (View estática)
  Display.gfx_Cls();

}





void loop() {
  // put your main code here, to run repeatedly:

  decimalValue = Serial.parseInt();

  if (decimalValue < 0) {
    Serial.println("Valor decimal inválido");
    Serial.println("");
    Serial.println("");
  }

  else if (decimalValue == 0) {
    Display.println("0");
  }

  else {
    binaryString = "";
    len = ceil(log2(decimalValue));
    for (int i = 0; i < len; i++) {
      binaryString.concat("0");
    }

    buildBinString(decimalValue);

    Display.println(binaryString);

    delay(5000);
//    Display.print("\n\n");/
    
  }
Display.gfx_Cls();

}





void buildBinString(unsigned int value) {
  Serial.print("buildBinString called w/ value = "); Serial.println(value);
  
  if (value <= 0) {
    return;

  } else {
    int pot = floor(log2(value));
    binaryString.setCharAt((len - pot - 1) , '1');
    Serial.print("pot = "); Serial.println(pot);
    Serial.print("len = "); Serial.println(len);
    Serial.print("building binaryString = "); Serial.println(binaryString);
    Serial.println();
    buildBinString(value - pow(2, pot));
  }

}





double log2(double valor) {

  return log(valor) / log(2);

}

