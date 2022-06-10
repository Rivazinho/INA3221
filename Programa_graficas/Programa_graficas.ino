#include <Wire.h>
#include "SDL_Arduino_INA3221.h"

SDL_Arduino_INA3221 ina3221;

#define CHANNEL1 1
#define CHANNEL2 2
#define CHANNEL3 3

void setup(void) {   
  Serial.begin(115200);
  Serial.println("Vbat,Ibat");
  ina3221.begin();
}

void loop(void) {
  float busvoltage1 = 0;
  float current_mA1 = 0;
  float potencia1 = 0;

  busvoltage1 = ina3221.getBusVoltage_V(CHANNEL1);
  current_mA1 = -ina3221.getCurrent_mA(CHANNEL1);  // Menos significa que la batería carga, más significa que se descarga
  potencia1 = busvoltage1*current_mA1/1000;
  /*Serial.print("Tensión entrada:    "); Serial.print(busvoltage1); Serial.println(" V");
  Serial.print("Intensidad entrada: "); Serial.print(current_mA1); Serial.println(" mA");
  Serial.print("Potencia entrada:   "); Serial.print(potencia1); Serial.println(" W");
  Serial.println("");*/

  float busvoltage2 = 0;
  float current_mA2 = 0;
  float potencia2 = 0;
  
  busvoltage2 = ina3221.getBusVoltage_V(CHANNEL2);
  current_mA2 = ina3221.getCurrent_mA(CHANNEL2);
  potencia2 = busvoltage2*current_mA2/1000;
  Serial.print(busvoltage2);
  Serial.print(",");
  Serial.println(current_mA2/100);
  /*Serial.print("Tensión batería:    "); Serial.print(busvoltage2); Serial.println(" V");
  Serial.print("Intensidad batería: "); Serial.print(current_mA2); Serial.println(" mA");
  Serial.print("Potencia batería:   "); Serial.print(potencia2); Serial.println(" W");
  Serial.println("");*/
  float busvoltage3 = 0;
  float current_mA3 = 0;
  float potencia3 = 0;
  
  busvoltage3 = ina3221.getBusVoltage_V(CHANNEL3);
  current_mA3 = ina3221.getCurrent_mA(CHANNEL3);
  potencia3 = busvoltage3*current_mA3/1000;  
  /*Serial.print("Tensión consumo:    "); Serial.print(busvoltage3); Serial.println(" V");
  Serial.print("Intensidad consumo: "); Serial.print(current_mA3); Serial.println(" mA");
  Serial.print("Potencia consumo:   "); Serial.print(potencia3); Serial.println(" W");
  Serial.println("");*/

  delay(100);
}
