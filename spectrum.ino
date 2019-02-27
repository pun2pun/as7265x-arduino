
#include "SparkFun_AS7265X.h"
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

AS7265X sensor;
File myFile;

const int chipSelect = 10;
int counter_SW =0 ;
int A,B,C,D,E,F,G,H,I,J,K,L,R,S,T,U,V,W ;
uint8_t button = 2;
uint8_t sampling_rate = 20;
bool Status_SW;
int LED = 53;
int status = false;
//---------------------------------------------------------------------------------------------------  GET DATA

void GET_DATA(){

      sensor.takeMeasurementsWithBulb(); 
    
      A = sensor.getA();
      B = sensor.getB();
      C = sensor.getC();
      D = sensor.getD();
      E = sensor.getE();
      F = sensor.getF();
      G = sensor.getG();
      H = sensor.getH();
      I = sensor.getI();
      J = sensor.getJ();
      K = sensor.getK();
      L = sensor.getL();
      R = sensor.getR();
      S = sensor.getS();
      T = sensor.getT();
      U = sensor.getU();
      V = sensor.getV();
      W = sensor.getW();
    
      String string_value_1 = String(A)+","+String(B)+","+String(C)+","+String(D)+","+String(E)+","+String(F)+","+String(G)+","+String(H)+","+String(I)+"'" ;
      String string_value_2 = String(J)+","+String(K)+","+String(L)+","+String(R)+","+String(S)+","+String(T)+","+String(U)+","+String(V)+","+String(W) ;
      
      String str_val =  string_value_1 + string_value_2;
      
      Serial.println(str_val);
         
   
 }
//--------------------------------------------------------------------------------------------------- DATA LOGGER

void DATA_LOGGER_SAVE(String date){
  
  myFile = SD.open("database.csv", FILE_WRITE);

  for(int number_value = 0;10;number_value++){      
       myFile.print(String(number_value)); myFile.print(",");myFile.print(date);myFile.print(",");   
    }
  
  }

//--------------------------------------------------------------------------------------------------- SETUP
void setup() {
  Serial.begin(9600);

  pinMode(SS,OUTPUT); pinMode(button,INPUT_PULLUP);   pinMode(LED,OUTPUT);
  

  if(sensor.begin() == false)
  {
    Serial.println("Please check wiring and restart device !");
    while(1);
  }


  Wire.setClock(400000);
  sensor.disableIndicator();

  
}

void loop() {

  if(digitalRead(button) == 0 && counter_SW == 0 ){counter_SW = 1; }
  if(digitalRead(button) == 0 && counter_SW != 0 ){counter_SW = 0; }
  
 if(counter_SW == 1 ){GET_DATA();digitalWrite(LED,1);}
 
 
 if(counter_SW == 0 ){digitalWrite(LED,0);}
 //delay(50);
}
  
