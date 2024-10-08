#include <Servo.h>

Servo Claw;
Servo vSlide;


int MotA;
int MotB;

//  Left motors or Motor A
int enbA = 6;
int inp1 = 2; 
int inp2 = 3;

// Right motors or Motor B
int enbB = 5;
int inp3 = 4;
int inp4 = 7;

char data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(enbA,OUTPUT); 
pinMode(enbB, OUTPUT);
pinMode(inp1,OUTPUT);
pinMode(inp2, OUTPUT);
pinMode(inp3, OUTPUT);
pinMode(inp4, OUTPUT);
// Initializing Servo Motor
  Claw.attach(9);
  vSlide.attach(8);
  Claw.write(0);
  vSlide.write(70);

}

void loop() {
  // put your main code here, to run repeatedly:

    
  if (Serial.available()>0){
    
    data = Serial.read();
    int num=int(data);
    if (num<10 and num>-1)
    {
      if(num==0) 
      {
  //    Serial.println(data);
        analogWrite(enbA, 150);
        analogWrite(enbB, 150); 
      
        // Making it move in forward direction
        digitalWrite(inp1, HIGH);
        digitalWrite(inp3 , HIGH);
        digitalWrite(inp2, LOW);
        digitalWrite(inp4 , LOW);
      }
  
  
      else if(num==1) 
      {
  //     move back;
         analogWrite(enbA, 150);
         analogWrite(enbB, 150); 
         digitalWrite(inp2, HIGH);
         digitalWrite(inp4 , HIGH);
         digitalWrite(inp1, LOW);
         digitalWrite(inp3 , LOW);
         delay(500);
      }
  
      else if(num==2) 
      {
  //      move left;
       analogWrite (enbA,150);
       analogWrite( enbB, 150);
       digitalWrite(inp1, HIGH);
       digitalWrite(inp4, HIGH);
       digitalWrite(inp2, LOW);
       digitalWrite(inp3 , LOW);
       delay(500);
      }
    
      else if(num==3)
      {
  //      move right;
        analogWrite (enbA,150);
        analogWrite( enbB, 150);
        digitalWrite(inp3, HIGH);   
        digitalWrite(inp2, HIGH);
        digitalWrite(inp1, LOW);
        digitalWrite(inp4 , LOW);
      }
    
      else if(num==4)
      {
        //Stop
         digitalWrite(inp1, LOW);
         digitalWrite(inp3, LOW);   
         digitalWrite(inp2, LOW);
         digitalWrite(inp4, LOW);
      }
     
    }
    else if(num<0)
    {
      vSlide.write(num+180);
    }
    else
    {
        Claw.write(num-10);
    }
    }
}
   
  
