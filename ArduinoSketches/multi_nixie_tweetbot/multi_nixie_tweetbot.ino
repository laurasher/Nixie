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

int ledPin_0_a = 2;                
int ledPin_0_b = 3;
int ledPin_0_c = 4;
int ledPin_0_d = 5;

int ledPin_1_a = 6;                
int ledPin_1_b = 7;
int ledPin_1_c = 8;
int ledPin_1_d = 9;

int rx_byte;    
 
void setup() {
  Serial.begin( 9600 ); 
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
}
 
void loop() {
  if( Serial.available() > 0 ) {      
    rx_byte = Serial.read();  
//    Serial.println(rx_byte);
  }
  
  switch(rx_byte) {
    case 0:
      output(0,0,0,0);
//      output_two(0,0,0,0);
      break;
    case 1:  
      output(0,0,0,1);
//      output_two(0,0,0,1);
      break;
    case 2:
      output(0,0,1,0);
//      output_two(0,0,1,0);
      break;
    case 3:
      output(0,0,1,1);
//      output_two(0,0,1,1);
      break;
    case 4:
      output(0,1,0,0);
//      output_two(0,1,0,0);
      break;
    case 5:
      output(0,1,0,1);
//      output_two(0,1,0,1);
      break;
    case 6:
      output(0,1,1,0);
//      output_two(0,1,1,0);
      break;
    case 7:
      output(0,1,1,1);
//      output_two(0,1,1,1);
      break;
    case 8:
      output(1,0,0,0);
//      output_two(1,0,0,0);
      break;
    case 9:
      output(1,0,0,1);
//      output_two(1,0,0,1);
      break;
    default:
    break;
  }
}
 
void output(int d, int c, int b, int a) {
  if (a == 1) digitalWrite(6, HIGH);
  else if (a == 0) digitalWrite(6, LOW); 
  if (b == 1) digitalWrite(5, HIGH);
  else if (b == 0) digitalWrite(5, LOW);
  if (c == 1) digitalWrite(4, HIGH);
  else if (c == 0) digitalWrite(4, LOW);
  if (d == 1) digitalWrite(3, HIGH);
  else if (d == 0) digitalWrite(3, LOW);
 
//  delay(500);
}
void output_two(int d, int c, int b, int a) {
  if (a == 1) digitalWrite(11, HIGH);
  else if (a == 0) digitalWrite(11, LOW); 
  if (b == 1) digitalWrite(10, HIGH);
  else if (b == 0) digitalWrite(10, LOW);
  if (c == 1) digitalWrite(9, HIGH);
  else if (c == 0) digitalWrite(9, LOW);
  if (d == 1) digitalWrite(8, HIGH);
  else if (d == 0) digitalWrite(8, LOW);
 
//  delay(500);
}
