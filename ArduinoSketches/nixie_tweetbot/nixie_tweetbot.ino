int a = 6;
int b = 5;
int c = 4;
int d = 3;

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
      break;
    case 1:  
      output(0,0,0,1);
      break;
    case 2:
      output(0,0,1,0);
      break;
    case 3:
      output(0,0,1,1);
      break;
    case 4:
      output(0,1,0,0);
      break;
    case 5:
      output(0,1,0,1);
      break;
    case 6:
      output(0,1,1,0);
      break;
    case 7:
      output(0,1,1,1);
      break;
    case 8:
      output(1,0,0,0);
      break;
    case 9:
      output(1,0,0,1);
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
