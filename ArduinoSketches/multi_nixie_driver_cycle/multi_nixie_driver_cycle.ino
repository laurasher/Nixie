int pin_0_d = 18;                
int pin_0_c = 19;
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



void SetSN74141Chips( int num0, int num1, int num2, int num3)
{
  int a,b,c,d;
  a=0;b=0;c=0;d=0; 
 
  // Load the a,b,c,d to send to the SN74141 IC (0)
  switch( num0 )
  {
    case 0: a=0;b=0;c=0;d=0;break;
    case 1: a=1;b=0;c=0;d=0;break;
    case 2: a=0;b=1;c=0;d=0;break;
    case 3: a=1;b=1;c=0;d=0;break;
    case 4: a=0;b=0;c=1;d=0;break;
    case 5: a=1;b=0;c=1;d=0;break;
    case 6: a=0;b=1;c=1;d=0;break;
    case 7: a=1;b=1;c=1;d=0;break;
    case 8: a=0;b=0;c=0;d=1;break;
    case 9: a=1;b=0;c=0;d=1;break;
    default: a=1;b=1;c=1;d=1;
    break;
  }  
  
  // Write to output pins.
  digitalWrite(pin_0_d, d);
  digitalWrite(pin_0_c, c);
  digitalWrite(pin_0_b, b);
  digitalWrite(pin_0_a, a);

  // Load the a,b,c,d to send to the SN74141 IC (1)
  switch( num1 )
  {
    case 0: a=0;b=0;c=0;d=0;break;
    case 1: a=1;b=0;c=0;d=0;break;
    case 2: a=0;b=1;c=0;d=0;break;
    case 3: a=1;b=1;c=0;d=0;break;
    case 4: a=0;b=0;c=1;d=0;break;
    case 5: a=1;b=0;c=1;d=0;break;
    case 6: a=0;b=1;c=1;d=0;break;
    case 7: a=1;b=1;c=1;d=0;break;
    case 8: a=0;b=0;c=0;d=1;break;
    case 9: a=1;b=0;c=0;d=1;break;
    default: a=1;b=1;c=1;d=1;
    break;
  }
  
  // Write to output pins
  digitalWrite(pin_1_d, d);
  digitalWrite(pin_1_c, c);
  digitalWrite(pin_1_b, b);
  digitalWrite(pin_1_a, a);

  // Load the a,b,c,d to send to the SN74141 IC (2)
  switch( num2 )
  {
    case 0: a=0;b=0;c=0;d=0;break;
    case 1: a=1;b=0;c=0;d=0;break;
    case 2: a=0;b=1;c=0;d=0;break;
    case 3: a=1;b=1;c=0;d=0;break;
    case 4: a=0;b=0;c=1;d=0;break;
    case 5: a=1;b=0;c=1;d=0;break;
    case 6: a=0;b=1;c=1;d=0;break;
    case 7: a=1;b=1;c=1;d=0;break;
    case 8: a=0;b=0;c=0;d=1;break;
    case 9: a=1;b=0;c=0;d=1;break;
    default: a=1;b=1;c=1;d=1;
    break;
  }  
  
  // Write to output pins.
  digitalWrite(pin_2_d, d);
  digitalWrite(pin_2_c, c);
  digitalWrite(pin_2_b, b);
  digitalWrite(pin_2_a, a);

  // Load the a,b,c,d to send to the SN74141 IC (3)
  switch( num3 )
  {
    case 0: a=0;b=0;c=0;d=0;break;
    case 1: a=1;b=0;c=0;d=0;break;
    case 2: a=0;b=1;c=0;d=0;break;
    case 3: a=1;b=1;c=0;d=0;break;
    case 4: a=0;b=0;c=1;d=0;break;
    case 5: a=1;b=0;c=1;d=0;break;
    case 6: a=0;b=1;c=1;d=0;break;
    case 7: a=1;b=1;c=1;d=0;break;
    case 8: a=0;b=0;c=0;d=1;break;
    case 9: a=1;b=0;c=0;d=1;break;
    default: a=1;b=1;c=1;d=1;
    break;
  }
  
  // Write to output pins
  digitalWrite(pin_3_d, d);
  digitalWrite(pin_3_c, c);
  digitalWrite(pin_3_b, b);
  digitalWrite(pin_3_a, a);
}


float fadeIn = 0.0f;
float fadeOut = 8.0f;
float fadeMax = 8.0f;
float fadeStep = 1.0f;
int NumberArray[4]={0,0,0,0};
int currNumberArray[4]={1,2,3,4};
float NumberArrayFadeInValue[4]={18.0f,18.0f,18.0f,18.0f};
float NumberArrayFadeOutValue[4]={18.0f,18.0f,18.0f,18.0f};

void DisplayFadeNumberString()
{

  SetSN74141Chips(currNumberArray[0],currNumberArray[1], currNumberArray[2], currNumberArray[3]);   
  delay(2000);
    
}

 
void loop() {
  NumberArray[3] = 3;
  NumberArray[2] = 2;
  NumberArray[1] = 1;
  NumberArray[0] = 0;

  // Display.
//  DisplayFadeNumberString();
  SetSN74141Chips(NumberArray[0],NumberArray[1], NumberArray[2], NumberArray[3]);   
  delay(1500);
  SetSN74141Chips(NumberArray[0],NumberArray[1], NumberArray[2], NumberArray[3]);  
  delay(1500); 
}
 

