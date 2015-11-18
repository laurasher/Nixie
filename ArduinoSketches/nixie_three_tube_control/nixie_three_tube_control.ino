int tube_0_d = 43;
int tube_0_c = 42;
int tube_0_b = 41;
int tube_0_a = 40;

int tube_1_d = 37;
int tube_1_c = 36;
int tube_1_b = 35;
int tube_1_a = 34;

int tube_2_d = 31;
int tube_2_c = 30;
int tube_2_b = 29;
int tube_2_a = 28;

int tube_3_d = 25;
int tube_3_c = 24;
int tube_3_b = 23;
int tube_3_a = 22;

void setup() {
  pinMode(tube_0_d, OUTPUT);
  pinMode(tube_0_c, OUTPUT);
  pinMode(tube_0_b, OUTPUT);
  pinMode(tube_0_a, OUTPUT);
  pinMode(tube_1_d, OUTPUT);
  pinMode(tube_1_c, OUTPUT);
  pinMode(tube_1_b, OUTPUT);
  pinMode(tube_1_a, OUTPUT);  
  pinMode(tube_2_d, OUTPUT);
  pinMode(tube_2_c, OUTPUT);
  pinMode(tube_2_b, OUTPUT);
  pinMode(tube_2_a, OUTPUT);
  pinMode(tube_3_d, OUTPUT);
  pinMode(tube_3_c, OUTPUT);
  pinMode(tube_3_b, OUTPUT);
  pinMode(tube_3_a, OUTPUT);

}


void writeTube_0(int num){
  int a,b,c,d; a=0;b=0;c=0;d=0;
  switch( num ){
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
}

void writeTube_1(int num){
  int a,b,c,d; a=0;b=0;c=0;d=0;
  switch( num ){
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
  digitalWrite(tube_1_d, d);
  digitalWrite(tube_1_c, c);
  digitalWrite(tube_1_b, b);
  digitalWrite(tube_1_a, a);
}

void writeTube_2(int num){
  int a,b,c,d; a=0;b=0;c=0;d=0;
  switch( num ){
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
  digitalWrite(tube_2_d, d);
  digitalWrite(tube_2_c, c);
  digitalWrite(tube_2_b, b);
  digitalWrite(tube_2_a, a);
}

void writeTube_3(int num){
  int a,b,c,d; a=0;b=0;c=0;d=0;
  switch( num ){
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
  digitalWrite(tube_3_d, d);
  digitalWrite(tube_3_c, c);
  digitalWrite(tube_3_b, b);
  digitalWrite(tube_3_a, a);
}

void loop() {
  
  writeTube_3(5); 
  writeTube_2(123); 
  writeTube_1(123); 
  writeTube_0(123);
  delay(1200);
  writeTube_3(123); 
  writeTube_2(5); 
  writeTube_1(123); 
  writeTube_0(123);
  delay(1200);
  writeTube_3(123); 
  writeTube_2(123); 
  writeTube_1(5); 
  writeTube_0(123);
  delay(1200);
  writeTube_3(123); 
  writeTube_2(123); 
  writeTube_1(123); 
  writeTube_0(5);
  delay(1200);


}
