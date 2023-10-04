#include <Servo.h>//include the servo library
#include <Wire.h>
#include <Liquidcrystal_r2c.h>
Liquidcrystal_I2c 1cd(ox27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

Servo myservo;

#define ir_enter 2
#define ir_back 4

#define ir_car1 5
#define ir_car2 6
#define ir_car3 7
#define ir_car4 8
#define ir_car5 9
#define ir_car6 10

int S1=o, S2=O, S3=O, S4=O, S5=O, S6=O;
int flag1=D,  flag2=o;
int slot = 6;

void setup(){
  Serial.begin(9600);

  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);
  pinMode(ir_car5, INPUT);
  pinMode(ir_car6, INPUT);

  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);

  myservo.attach(3);
  myservo.write(90);

  lcd.begin(20, 4);
  lcd.setcursor(0,1);
  lcd.print("  car parking ");
  lcd.setCursor(0,2);
  lcd.print(" system ");
  delay(2000);
  lcd.clear();

  Read_Sensor();

  int total = S1+S2+S3+S4+S5+S6;
  slot = slot-total;



}

void loop(){
  Read_Sensor();

  lcd.setCursor(0,0);
  lcd.print(" Have slot: ");
  lcd.print(slot);
  lcd.print(" ");
  lcd.setCursor(0,1);
  if(S1==1){lcd.print("S1 :Fill ");}
  else{lcd.print("S1:Empty");}

  lcd.setCursor(10,1);
  if(S2==1){lcd.print("S2:Fill");}
  else{lcd.print("S2:Empty");}

  lcd.setCursor(0,2);
  if(S3==1){lcd.print("S3:Fill ");}
  else{lcd.print("S3:Empty");}

  lcd.setCursor (10,2);
  if(S4==1){lcd.print("S4:Fill");}
  else{lcd.print("S4:Empty");}

  lcd.setCursor(0,3);
  if(S5==1){lcd.print("S5:Fill");}
  else{lcd.print("S5:Empty");}

  lcd.setCursor (10,3);
  if(S6==1){lcd.print("S6:Fill");}
  else{lcd.print("S6:Empty");} 

  if(digitalRead(ir_enter)== 0 && flag1==0){
    if(slot>0){flag1=1;
    if(flag2==0)(myservo.write(180); slot = slot-1;)
    }else{
      lcd.setCursor (0, 0);
      lcd.print(" Sorry Parking Full ");
      delay(1500);


    }
  } 
  if(digitalRead(ir_back)==0 && flag2==0){flag2=1;
  if(flag1==0)(myservo.write(180); slot = slot+1;)
  }
  if(flag1==1 && flag2==1){
    delay(1000);
    myservo.write(50);
    flag1=0, flag2=0;
  }

  delay(1);
    }

    void Read_Sensor(){
      S1=0, S2=0, S3=0, S4=0, S5=0, S6=0;
    
    if(digitalRead(ir_car1) == 0){S1=1;}
    if(digitalRead(ir_car2) == 0){S2=1;}
    if(digitalRead(ir_car3) == 0){S3=1;}
    if(digitalRead(ir_car4) == 0){S4=1;}
    if(digitalRead(ir_car5) == 0){S5=1;}
    if(digitalRead(ir_car6) == 0){S6=1;}


    }
