#include<Servo.h>
#include<Wire.h>
volatile byte rev = 0;
unsigned long int rpm=0,time=0;
//long prevtime=0; //store idle time

void setup() {
  
  attachInterrupt(0, rpmCounterInterrupt, RISING);  //  ADD A HIGH PRIORITY ACTION ( AN INTERRUPT)  WHEN THE SENSOR GOES FROM LOW TO HIGH
  
  Serial.begin(9600);

}
void rpmCounterInterrupt()
{
  rev++;
}
void loop() {
  long currtime=millis(); //get current time
  //long idletime=currtime-prevtime; //calculate idle time
  if(rev>5)
  {
    rpm= 30*1000/(millis() - time)*rev;       //  CALCULATE  RPM USING REVOLUTIONS AND ELAPSED TIME
    rev=0;
    time=millis();
    //prevtime=currtime;
    }
  Serial.print("rpm=:");
  Serial.println(rpm);
  
  delay(1000);
}
