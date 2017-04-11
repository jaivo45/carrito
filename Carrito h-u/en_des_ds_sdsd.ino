#include <LEANTEC_ControlMotor.h>
#include <NewPing.h>







#define  TRIGGER_PIN 11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define  ECHO_PIN    10  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define  ENA         2
#define   IN1        3
#define   IN2        4
#define  ENB         5
#define   IN3        6
#define   IN4        7   

#define MAX_DISTANCE 400// Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.



NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  
  
  
}

void loop() {
  delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  int distance=uS / US_ROUNDTRIP_CM;

    
 
    
  if (distance>7){ //*SI DISTANCIA MAYOR QUE CUATRO Y MENOR QUE 50 
 
    digitalWrite(ENA,LOW);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);  //*AVANSA 
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    digitalWrite(ENB,LOW);

 analogWrite(ENA, 55);
  delay(30);
  analogWrite(ENA, 105);
  delay(30);
  analogWrite(ENA, 255);
  delay(30);
  analogWrite(ENA, 0);
  delay(30);
 
    
    
     } 
 
  else {

 digitalWrite(ENA,LOW);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW); //*GIRA IzQUIERDA
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    digitalWrite(ENB,HIGH);


                          
    
  analogWrite(ENA, 55);
  delay(140);
  analogWrite(ENA, 105);
  delay(140);
  analogWrite(ENA, 255);
  delay(140);
  analogWrite(ENA, 0);
  delay(140);

  




     
     //** aqui en otro if 
     
      if (distance<5){
     
                                
     digitalWrite(ENA,LOW);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);  //*AVANzA 
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    digitalWrite(ENB,LOW);

 analogWrite(ENA, 55);
  delay(30);
  analogWrite(ENA, 105);
  delay(30);
  analogWrite(ENA, 255);
  delay(30);
  analogWrite(ENA, 0);
  delay(30);
                                  
                                 }  
                                 
                                 
                                 else {
                                  
    digitalWrite(ENA,HIGH);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH); // DERECHA
    digitalWrite(IN4,LOW);
    digitalWrite(ENB,LOW);
    
  analogWrite(ENA, 55);
  delay(280);
  analogWrite(ENA, 105);
  delay(280);
  analogWrite(ENA, 255);
  delay(280);
  analogWrite(ENA, 0);
  delay(280);

   
                                  }

     


                            


                         
}








}



       
  
