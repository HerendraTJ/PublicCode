#include <Servo.h> //Import Library Servo.h
#include <NewPing.h> //Import Library NewPing.h
Servo servoku; //Servo Name
#define TRIGGER_PIN_1 11 //Sensor triggered in here 
#define ECHO_PIN_1 12 // Sensor output is measured in here
#define MAX_DISTANCE 500 //Maximum distance = 500cm

NewPing sonar_1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE); //Sonar is define by NewPing Library
// With input Trigger

//Interger is declared in jarak variables
unsigned int jarak;

void setup(){
  Serial.begin(9600); //Program begins after 9600Baud
  servoku.attach(3); //Servo is on pin 3
}

void loop() 
{
  jarak = sonar_1.ping_cm(); //End of the input in cm
  Serial.print("jarak :"); //When sonar detected , Print "jarak:"
  Serial.print(jarak); //Print jarak?? Reference ^ ??
  Serial.println("cm"); //End of the variables print 
  /*If jarak variables >=50
   * Print Tutup
   * servo 0 DEG
   * Delay 1000ms
   */
  if(jarak>=50){
  Serial.println("Tutup"); 
  servoku.write(0);
  delay(1000); //Delay 1000ms
  }
  
//Else of that just

else{
  Serial.println("Buka");
  servoku.write(180);
  delay(5000);
}
}
