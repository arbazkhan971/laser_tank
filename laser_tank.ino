#include <SoftwareSerial.h>
SoftwareSerial EEBlue(13,12);
const int laspin=4;
char state;
//char laser;
int i=0;
#define l A1
long int t;
int currentmillis,premillis;

#define ldrpin A0

const int val=400;

#define led1 5
#define led2 4
#define led3 3


#define m1 9
#define m2 8
#define m3 7
#define m4 6
#define pwm1 10
#define pwm2 11


void setup(){

 pinMode(ldrpin,OUTPUT);
  pinMode(l,OUTPUT);

 pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);

pinMode(A1,HIGH);
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);

pinMode(pwm1,OUTPUT);
pinMode(pwm2,OUTPUT);

analogWrite(pwm1,225);
analogWrite(pwm2,225);

Serial.begin(38400);

EEBlue.begin(38400) ; 
  }

void loop() {
  currentmillis=millis();
  //laser='1';0
   if(EEBlue.available())
  {

   state = EEBlue.read();
   /*if(state=='x')
   {laser=state;}*/
   
      //Serial.print(laser);
      
    
  delay(10);}

 
 if(Serial.available()){
  
   state = Serial.read();
  Serial.println(state);
  
    delay(10);
 } 


 int a=map(3.3,0,5,0,255);
 
 if(i<3) {
  
 
 if(state=='f')
{
  Serial.println("Motor started:)");
  digitalWrite(m4,LOW);
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
  digitalWrite (m3,HIGH);
  
}

  if(state=='l')//turn left
{
   digitalWrite(m4,HIGH);
    Serial.println("Motor started:)");
  digitalWrite(m1,HIGH);
  digitalWrite(m2,LOW);
  digitalWrite (m3,LOW);
  
}

 if(state=='r')//right turn
  {
     digitalWrite(m4,LOW);
    Serial.println("Motor started:)");
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite (m3,HIGH);
 
  }
  
  
 if (state=='b')
 {
  digitalWrite(m4,HIGH);
  Serial.println("Motor :)");
  digitalWrite(m1,LOW);
  digitalWrite(m2,HIGH);
  digitalWrite (m3,LOW);
 
 }


 
if(state=='h'|| i==3) {
    
    Serial.println("Motor stopped!");
    digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
   analogWrite(A1,0); 
}
if(state=='x')
 {
  Serial.println(currentmillis);
  if (currentmillis-premillis>1000)
{
  analogWrite(A1,0);  
}
  premillis=currentmillis;
  analogWrite(A1,a);
 //delay(4000);
//  if(t>2000) 
//  analogWrite(A1,0);
Serial.println(premillis);

 } 





  


 if(EEBlue.available())
  {

   state = EEBlue.read();
   Serial.print(state);
      
      
    
  delay(10);}


 }
 
 


  int ldr=analogRead(ldrpin);
 //Serial.println(ldr);
  
  for(i=0;ldr>=val;i++)
  {
   
   if(i==1)
   {
    Serial.println("Enter loop1");
      digitalWrite(led1,HIGH);
   delay(1000);
   }
   
   else if(i==2)
   {
    Serial.println("Enter loop2");
      digitalWrite(led2,HIGH);
      delay(2000);
   }
   else if(i==3)
   {
    Serial.println("Enter loop3");
      digitalWrite(led3,HIGH);
      delay(2000);
   }
     if(i==3)
     {
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(1000);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      delay(1000);
      Serial.println("Motor stopped!");
    digitalWrite(m1,LOW);
  digitalWrite(m2,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
     
     }  
     
     
   }
   

  
}

 



