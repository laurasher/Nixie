int tube_0_d = 8;
int tube_0_c = 9;
int tube_0_b = 10;
int tube_0_a = 11;

int tube_1_d = 4;
int tube_1_c = 5;
int tube_1_b = 6;
int tube_1_a = 7;

void setup() {
  pinMode(tube_0_d, OUTPUT);
  pinMode(tube_0_c, OUTPUT);
  pinMode(tube_0_b, OUTPUT);
  pinMode(tube_0_a, OUTPUT);
  pinMode(tube_1_d, OUTPUT);
  pinMode(tube_1_c, OUTPUT);
  pinMode(tube_1_b, OUTPUT);
  pinMode(tube_1_a, OUTPUT);

}


void twoTubeWrite( int num0, int num1 ){
  int a,b,c,d; a=0;b=0;c=0;d=0;
  switch( num0 ){
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
  digitalWrite(tube_0_d, d);
  digitalWrite(tube_0_c, c);
  digitalWrite(tube_0_b, b);
  digitalWrite(tube_0_a, a);
  int a1,b1,c1,d1; a1=0;b1=0;c1=0;d1=0;
  switch( num1 ){
    case 0: d1=0;c1=0;b1=0;a1=0;break;
    case 1: d1=0;c1=0;b1=0;a1=1;break;
    case 2: d1=0;c1=0;b1=1;a1=0;break;
    case 3: d1=0;c1=0;b1=1;a1=1;break;
    case 4: d1=0;c1=1;b1=0;a1=0;break;
    case 5: d1=0;c1=1;b1=0;a1=1;break;
    case 6: d1=0;c1=1;b1=1;a1=0;break;
    case 7: d1=0;c1=1;b1=1;a1=1;break;
    case 8: d1=1;c1=0;b1=0;a1=0;break;
    case 9: d1=1;c1=0;b1=0;a1=1;break;
    default: a1=0;b1=0;c1=0;d1=0;
    break;
  }
  digitalWrite(tube_1_d, d1);
  digitalWrite(tube_1_c, c1);
  digitalWrite(tube_1_b, b1);
  digitalWrite(tube_1_a, a1);
}

void loop() {
  
  twoTubeWrite(0,2);
  delay(1200);
  twoTubeWrite(4,6);
  delay(1200);


}
