int pin_0_d = 12;                
int pin_0_c = 13;
int pin_0_b = 2;
int pin_0_a = 3;
               
int pin_1_d = 4;
int pin_1_c = 5;
int pin_1_b = 6;
int pin_1_a = 7;

int pin_2_d = 8;
int pin_2_c = 9;
int pin_2_b = 10;
int pin_2_a = 11;

int pin_3_d = 14;
int pin_3_c = 15;
int pin_3_b = 16;
int pin_3_a = 17;
 
void setup() {
  pinMode(pin_0_a, OUTPUT);      
  pinMode(pin_0_b, OUTPUT);      
  pinMode(pin_0_c, OUTPUT);      
  pinMode(pin_0_d, OUTPUT);    
  
  pinMode(pin_1_a, OUTPUT);      
  pinMode(pin_1_b, OUTPUT);      
  pinMode(pin_1_c, OUTPUT);      
  pinMode(pin_1_d, OUTPUT); 

  pinMode(pin_2_a, OUTPUT);      
  pinMode(pin_2_b, OUTPUT);      
  pinMode(pin_2_c, OUTPUT);      
  pinMode(pin_2_d, OUTPUT);    
  
  pinMode(pin_3_a, OUTPUT);      
  pinMode(pin_3_b, OUTPUT);      
  pinMode(pin_3_c, OUTPUT);      
  pinMode(pin_3_d, OUTPUT); 
}

 
void loop() {
  int del = 700;
  output(0);
  delay(del);
  output(1);
  delay(del);
  output(2);
  delay(del);
  output(3);
  delay(del);
  output(4);
  delay(del);
   output(5);
  delay(del);
  output(6);
  delay(del);
  output(7);
  delay(del);
  output(8);
  delay(del);
  output(9);
  delay(del);
}

void output(int num1){
  int a = 0; int b = 0; int c = 0; int d = 0;
  switch( num1 )
  {
    case 0: d=0;c=0;b=0;a=0;break;
    case 1: d=0;c=0;b=0;a=1;break;
    case 2: d=0;c=0;b=1;a=0;break;
    case 3: d=0;c=0;b=1;a=1;break;
    case 4: d=0;c=1;b=0;a=0;break;
    case 5: d=0;c=1;b=0;a=1;break;
    case 6: d=0;c=1;b=1;a=0;break;
    case 7: d=0;c=1;b=1;a=1;break;
    case 8: d=1;c=0;b=0;a=0;break;
    case 9: d=1;c=0;b=0;a=1;break;
    default: a=0;b=0;c=0;d=0;
    break;
  }

  digitalWrite(pin_2_d, d);
  digitalWrite(pin_2_c, c);
  digitalWrite(pin_2_b, b);
  digitalWrite(pin_2_a, a);
}

