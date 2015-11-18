int a = 6;
int b = 5;
int c = 4;
int d = 3;
 
void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
}
 
void loop() {
  output(0,0,0,0);
  output(0,0,0,1);
  output(0,0,1,0);
  output(0,0,1,1);
  output(0,1,0,0);
  output(0,1,0,1);
  output(0,1,1,0);
  output(0,1,1,1);
  output(1,0,0,0);
  output(1,0,0,1);
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
 
  delay(500);
}
