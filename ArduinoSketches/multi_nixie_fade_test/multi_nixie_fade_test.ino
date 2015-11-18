// SN74141 : Truth Table
//D C B A #
//L,L,L,L 0
//L,L,L,H 1
//L,L,H,L 2
//L,L,H,H 3
//L,H,L,L 4
//L,H,L,H 5
//L,H,H,L 6
//L,H,H,H 7
//H,L,L,L 8
//H,L,L,H 9

int ledPin_0_d = 11;                
int ledPin_0_c = 10;
int ledPin_0_b = 9;
int ledPin_0_a = 8;
               
int ledPin_1_d = 7;
int ledPin_1_c = 6;
int ledPin_1_b = 5;
int ledPin_1_a = 4;

// anode pins
//int ledPin_a_1 = 10;
//int ledPin_a_2 = 11;
//int ledPin_a_3 = 12;



void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin_0_a, OUTPUT);      
  pinMode(ledPin_0_b, OUTPUT);      
  pinMode(ledPin_0_c, OUTPUT);      
  pinMode(ledPin_0_d, OUTPUT);    
  
  pinMode(ledPin_1_a, OUTPUT);      
  pinMode(ledPin_1_b, OUTPUT);      
  pinMode(ledPin_1_c, OUTPUT);      
  pinMode(ledPin_1_d, OUTPUT);      
  

}

void SetSN74141Chips( int num2, int num1 )
{
  int a,b,c,d;
  
  // set defaults.
  a=0;b=0;c=0;d=0; // will display a zero.
  
  // Load the a,b,c,d.. to send to the SN74141 IC (1)
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
  
  // Write to output pins.
  digitalWrite(ledPin_0_d, d);
  digitalWrite(ledPin_0_c, c);
  digitalWrite(ledPin_0_b, b);
  digitalWrite(ledPin_0_a, a);

  // Load the a,b,c,d.. to send to the SN74141 IC (2)
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
  
  // Write to output pins
  digitalWrite(ledPin_1_d, d);
  digitalWrite(ledPin_1_c, c);
  digitalWrite(ledPin_1_b, b);
  digitalWrite(ledPin_1_a, a);
}



float fadeMax = 6.0f;
float fadeStep = 0.3f; 
int NumberArray[6]={0,0,0,0};
int currNumberArray[6]={0,0,0,0};
float NumberArrayFadeInValue[6]={18.0f,18.0f,18.0f,18.0f};
float NumberArrayFadeOutValue[6]={18.0f,18.0f,18.0f,18.0f};



void DisplayFadeNumberString()
{
  // Anode channel 1 - numerals 0,3
  SetSN74141Chips(currNumberArray[0],currNumberArray[3]);   
  delay(NumberArrayFadeOutValue[2]);
  SetSN74141Chips(NumberArray[0],NumberArray[3]);   
  delay(NumberArrayFadeInValue[2]);
  
  // Anode channel 2 - numerals 1,4
  SetSN74141Chips(currNumberArray[1],currNumberArray[4]);   
  delay(NumberArrayFadeOutValue[2]);
  SetSN74141Chips(NumberArray[1],NumberArray[4]);   
  delay(NumberArrayFadeInValue[2]);
  
//  // Anode channel 3 - numerals 2,5
//  SetSN74141Chips(currNumberArray[2],currNumberArray[5]);   
////  digitalWrite(ledPin_a_3, HIGH);   
//  delay(NumberArrayFadeOutValue[2]);
//  SetSN74141Chips(NumberArray[2],NumberArray[5]);   
//  delay(NumberArrayFadeInValue[2]);
////  digitalWrite(ledPin_a_3, LOW);
//  
  // Loop thru and update all the arrays, and fades.
  for( int i = 0 ; i < 4 ; i ++ )
  {
    if( NumberArray[i] != currNumberArray[i] )
    {
      NumberArrayFadeInValue[i] += fadeStep;
      NumberArrayFadeOutValue[i] -= fadeStep;
  
     for( int i = 0 ; i < 4 ; i ++ )
  {
    if( NumberArray[i] != currNumberArray[i] )
    {
      NumberArrayFadeInValue[i] += fadeStep;
      NumberArrayFadeOutValue[i] -= fadeStep;
  
      if( NumberArrayFadeInValue[i] >= fadeMax )
      {
        NumberArrayFadeInValue[i] = 0.0f;
        NumberArrayFadeOutValue[i] = fadeMax;
        currNumberArray[i] = NumberArray[i];
      }
    }
  }
 }
  }
}
void loop()     
{
        NumberArray[3] = 3; 
        NumberArray[1] = 0;
        NumberArray[0] = 1;
        NumberArray[2] = 2;
        DisplayFadeNumberString();    // Display numbers for a while.
         
}
