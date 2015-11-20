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

int rx_byte=0; 
int last_rx_byte;   
String rx_string;

int tube_3_int = 0; 
int tube_2_int = 0; 
int tube_1_int = 0;
int tube_0_int = 0;

int last_tube_3_int = 0; 
int last_tube_2_int = 0; 
int last_tube_1_int = 0;
int last_tube_0_int = 0;

int timeout;

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

  Serial.begin( 9600 ); 

}

void loop() {
  if( Serial.available() > 0 ) {
      timeout = millis();
      rx_string = Serial.readStringUntil('g');
      int backup_last_rxbyte = 
      last_rx_byte = rx_byte;
      rx_byte = atoi(rx_string.c_str());
      
      if (rx_byte > 1000){   
        last_tube_3_int = floor( last_rx_byte/1000 ); 
        last_tube_2_int = floor( (last_rx_byte-1000) /100); 
        last_tube_1_int = floor( (last_rx_byte-last_tube_3_int*1000-last_tube_2_int*100)/10 );
        last_tube_0_int = last_rx_byte-last_tube_3_int*1000-last_tube_2_int*100-last_tube_1_int*10;
           
        tube_3_int = floor( rx_byte/1000 ); 
        tube_2_int = floor( (rx_byte-1000) /100); 
        tube_1_int = floor( (rx_byte-tube_3_int*1000-tube_2_int*100)/10 );
        tube_0_int = rx_byte-tube_3_int*1000-tube_2_int*100-tube_1_int*10;

        int anim = checkUpDown(last_rx_byte, rx_byte); //if 2, animate down. if 1, animate up. if 0, do nothing
        switch( anim ){
          case 0: { break; }//do nothing
          case 1: animUp(last_tube_3_int,last_tube_2_int,last_tube_1_int,last_tube_0_int,tube_3_int,tube_2_int,tube_1_int,tube_0_int, rx_byte-last_rx_byte); break;
          case 2: animDown(last_tube_3_int,last_tube_2_int,last_tube_1_int,last_tube_0_int,tube_3_int,tube_2_int,tube_1_int,tube_0_int, rx_byte-last_rx_byte); break;
          default: break;
        }
        
        int i = 400; 
        int del = 5;
        while(i>0){
            writeTube_3(tube_3_int); 
            delay(del);
            writeTube_2(tube_2_int);
            delay(del);
            writeTube_1(tube_1_int);
            delay(del); 
            writeTube_0(tube_0_int);
            delay(del);
            i--;
        }
      }  
      else {
//              int i = 800; 
//              int del = 5;
//              while(i>0){
//                  writeTube_3(tube_3_int); 
//                  delay(del);
//                  writeTube_2(tube_2_int);
//                  delay(del);
//                  writeTube_1(tube_1_int);
//                  delay(del); 
//                  writeTube_0(tube_0_int);
//                  delay(del);
//                  i--;
//               }
              int i = 10000; 
              int del = 5;
              while(i>0){
                if( Serial.available() > 0 ) {
                  break;
                }
                  writeTube_3(tube_3_int); 
                  delay(del);
                  writeTube_2(tube_2_int);
                  delay(del);
                  writeTube_1(tube_1_int);
                  delay(del); 
                  writeTube_0(tube_0_int);
                  delay(del);
                  i--;
               }
      }
      
    }
//    else if (timeout > 3000){
//      int i = 10000; 
//              int del = 5;
//              while(i>0){
//                if( Serial.available() > 0 ) {
//                  break;
//                }
//                  writeTube_3(tube_3_int); 
//                  delay(del);
//                  writeTube_2(tube_2_int);
//                  delay(del);
//                  writeTube_1(tube_1_int);
//                  delay(del); 
//                  writeTube_0(tube_0_int);
//                  delay(del);
//                  i--;
//               }
//    }
}


int checkUpDown(int last, int current){
  if (last == current){
    return 0;
  }
  if (current - last == 1){ //gone up
    return 1;
  }
  if (last - current == 1){ //gone down
    return 2;
  }
  else { return 0; }
}


void animUp(int last_t_3, int last_t_2, int last_t_1, int last_t_0, int t_3, int t_2, int t_1, int t_0, int diff){
        int j = 0; int del = 110;
        while(j<5){
          writeTube_3(diff); 
          delay(del-j*20);
          writeTube_2(diff);
          delay(del-j*20);
          writeTube_1(diff);
          delay(del-j*20); 
          writeTube_0(diff);
          delay(del-j*20);
          j++;
        }
        int i = 200; 
        del = 150;
//        while(i>0){
            writeTube_3(last_t_3); 
            delay(del);
            writeTube_2(last_t_2);
            delay(del);
            writeTube_1(last_t_1);
            delay(del); 
            writeTube_0(last_t_0);
            delay(del);
//            i--;
//        }
        i=200;
//        while(i>0){
            writeTube_3(t_3); 
            delay(del);
            writeTube_2(t_2);
            delay(del);
            writeTube_1(t_1);
            delay(del); 
            writeTube_0(t_0);
            delay(del);
//            i--;
//        }
            writeTube_0(t_0); 
            delay(del);
            writeTube_1(t_1);
            delay(del);
            writeTube_2(t_2);
            delay(del); 
            writeTube_3(t_3);
            delay(del);
//        int i = 200; int j = 2;
//        int del = 5;
//      while(j>0){ 
//        while(i>0){
//            writeTube_3(diff); 
//            delay(del);
//            writeTube_2(diff);
//            delay(del);
//            writeTube_1(diff);
//            delay(del); 
//            writeTube_0(diff);
//            delay(del);
//            i--;
//        }
//          writeTube_3(t_3); 
//          writeTube_2(t_2); 
//          writeTube_1(t_1); 
//          writeTube_0(t_0);
//          delay(200);
//      j--;
//      }
        
}

void animDown(int last_t_3, int last_t_2, int last_t_1, int last_t_0, int t_3, int t_2, int t_1, int t_0, int diff){
      diff = 1;
      
      int j = 0; int del = 10;
        while(j<5){
          writeTube_3(diff); 
          delay(del+j*20);
          writeTube_2(diff);
          delay(del+j*20);
          writeTube_1(diff);
          delay(del+j*20); 
          writeTube_0(diff);
          delay(del+j*20);
          j++;
        }
        int i = 200; 
        del = 150;
//        while(i>0){
            writeTube_3(last_t_3); 
            delay(del);
            writeTube_2(last_t_2);
            delay(del);
            writeTube_1(last_t_1);
            delay(del); 
            writeTube_0(last_t_0);
            delay(del);
//            i--;
//        }
        i=200;
//        while(i>0){
            writeTube_3(t_3); 
            delay(del);
            writeTube_2(t_2);
            delay(del);
            writeTube_1(t_1);
            delay(del); 
            writeTube_0(t_0);
            delay(del);
//            i--;
//        }
            writeTube_0(t_0); 
            delay(del);
            writeTube_1(t_1);
            delay(del);
            writeTube_2(t_2);
            delay(del); 
            writeTube_3(t_3);
            delay(del);
//        int i = 200; int j = 2;
//        int del = 5;
//      while(j>0){ 
//        while(i>0){
//            writeTube_3(diff); 
//            delay(del);
//            writeTube_2(diff);
//            delay(del);
//            writeTube_1(diff);
//            delay(del); 
//            writeTube_0(diff);
//            delay(del);
//            i--;
//        }
//          writeTube_3(t_3); 
//          writeTube_2(t_2); 
//          writeTube_1(t_1); 
//          writeTube_0(t_0);
//          delay(200);
//      j--;
//      }
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
  digitalWrite(tube_3_d, 15);
  digitalWrite(tube_3_c, 15);
  digitalWrite(tube_3_b, 15);
  digitalWrite(tube_3_a, 15);
  digitalWrite(tube_2_d, 15);
  digitalWrite(tube_2_c, 15);
  digitalWrite(tube_2_b, 15);
  digitalWrite(tube_2_a, 15);
  digitalWrite(tube_1_d, 15);
  digitalWrite(tube_1_c, 15);
  digitalWrite(tube_1_b, 15);
  digitalWrite(tube_1_a, 15);
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
  digitalWrite(tube_2_d, 15);
  digitalWrite(tube_2_c, 15);
  digitalWrite(tube_2_b, 15);
  digitalWrite(tube_2_a, 15);
  digitalWrite(tube_3_d, 15);
  digitalWrite(tube_3_c, 15);
  digitalWrite(tube_3_b, 15);
  digitalWrite(tube_3_a, 15);
  digitalWrite(tube_0_d, 15);
  digitalWrite(tube_0_c, 15);
  digitalWrite(tube_0_b, 15);
  digitalWrite(tube_0_a, 15);
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
  digitalWrite(tube_3_d, 15);
  digitalWrite(tube_3_c, 15);
  digitalWrite(tube_3_b, 15);
  digitalWrite(tube_3_a, 15);
  digitalWrite(tube_1_d, 15);
  digitalWrite(tube_1_c, 15);
  digitalWrite(tube_1_b, 15);
  digitalWrite(tube_1_a, 15);
  digitalWrite(tube_0_d, 15);
  digitalWrite(tube_0_c, 15);
  digitalWrite(tube_0_b, 15);
  digitalWrite(tube_0_a, 15);
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
  digitalWrite(tube_2_d, 15);
  digitalWrite(tube_2_c, 15);
  digitalWrite(tube_2_b, 15);
  digitalWrite(tube_2_a, 15);
  digitalWrite(tube_1_d, 15);
  digitalWrite(tube_1_c, 15);
  digitalWrite(tube_1_b, 15);
  digitalWrite(tube_1_a, 15);
  digitalWrite(tube_0_d, 15);
  digitalWrite(tube_0_c, 15);
  digitalWrite(tube_0_b, 15);
  digitalWrite(tube_0_a, 15);
}

void writeFourNixies(int num3, int num2, int num1, int num0){
        
  int d_3=15; int c_3=15; int b_3=15; int a_3=15;
  int d_2=15; int c_2=15; int b_2=15; int a_2=15;
  int d_1=15; int c_1=15; int b_1=15; int a_1=15;
  int d_0=15; int c_0=15; int b_0=15; int a_0=15;
   
  switch( num0 ){
    case 0: d_0=0;c_0=0;b_0=0;a_0=0;break;
    case 1: d_0=0;c_0=0;b_0=0;a_0=1;break;
    case 2: d_0=0;c_0=0;b_0=1;a_0=0;break;
    case 3: d_0=0;c_0=0;b_0=1;a_0=1;break;
    case 4: d_0=0;c_0=1;b_0=0;a_0=0;break;
    case 5: d_0=0;c_0=1;b_0=0;a_0=1;break;
    case 6: d_0=0;c_0=1;b_0=1;a_0=0;break;
    case 7: d_0=0;c_0=1;b_0=1;a_0=1;break;
    case 8: d_0=1;c_0=0;b_0=0;a_0=0;break;
    case 9: d_0=1;c_0=0;b_0=0;a_0=1;break;
    default: a_0=0;b_0=0;c_0=0;d_0=0;
    break;
  }
   switch( num1 ){
    case 0: d_1=0;c_1=0;b_1=0;a_1=0;break;
    case 1: d_1=0;c_1=0;b_1=0;a_1=1;break;
    case 2: d_1=0;c_1=0;b_1=1;a_1=0;break;
    case 3: d_1=0;c_1=0;b_1=1;a_1=1;break;
    case 4: d_1=0;c_1=1;b_1=0;a_1=0;break;
    case 5: d_1=0;c_1=1;b_1=0;a_1=1;break;
    case 6: d_1=0;c_1=1;b_1=1;a_1=0;break;
    case 7: d_1=0;c_1=1;b_1=1;a_1=1;break;
    case 8: d_1=1;c_1=0;b_1=1;a_1=0;break;
    case 9: d_1=1;c_1=0;b_1=0;a_1=1;break;
    default: a_1=0;b_1=0;c_1=0;d_1=0;
    break;
  }
   switch( num2 ){
    case 0: d_2=0;c_2=0;b_2=0;a_2=0;break;
    case 1: d_2=0;c_2=0;b_2=0;a_2=1;break;
    case 2: d_2=0;c_2=0;b_2=1;a_2=0;break;
    case 3: d_2=0;c_2=0;b_2=1;a_2=1;break;
    case 4: d_2=0;c_2=1;b_2=0;a_2=0;break;
    case 5: d_2=0;c_2=1;b_2=0;a_2=1;break;
    case 6: d_2=0;c_2=1;b_2=1;a_2=0;break;
    case 7: d_2=0;c_2=1;b_2=1;a_2=1;break;
    case 8: d_2=1;c_2=0;b_2=1;a_2=0;break;
    case 9: d_2=1;c_2=0;b_2=0;a_2=1;break;
    default: a_2=0;b_2=0;c_2=0;d_2=0;
    break;
  }

  switch( num3 ){
    case 0: d_3=0;c_3=0;b_3=0;a_3=0;break;
    case 1: d_3=0;c_3=0;b_3=0;a_3=1;break;
    case 2: d_3=0;c_3=0;b_3=1;a_3=0;break;
    case 3: d_3=0;c_3=0;b_3=1;a_3=1;break;
    case 4: d_3=0;c_3=1;b_3=0;a_3=0;break;
    case 5: d_3=0;c_3=1;b_3=0;a_3=1;break;
    case 6: d_3=0;c_3=1;b_3=1;a_3=0;break;
    case 7: d_3=0;c_3=1;b_3=1;a_3=1;break;
    case 8: d_3=1;c_3=0;b_3=1;a_3=0;break;
    case 9: d_3=1;c_3=0;b_3=0;a_3=1;break;
    default: a_3=0;b_3=0;c_3=0;d_3=0;
    break;
  }
  
  digitalWrite(tube_3_d, d_3);
  digitalWrite(tube_3_c, c_3);
  digitalWrite(tube_3_b, b_3);
  digitalWrite(tube_3_a, a_3);
  digitalWrite(tube_2_d, d_2);
  digitalWrite(tube_2_c, c_2);
  digitalWrite(tube_2_b, c_1);
  digitalWrite(tube_2_a, c_0);
  digitalWrite(tube_1_d, d_1);
  digitalWrite(tube_1_c, c_1);
  digitalWrite(tube_1_b, b_1);
  digitalWrite(tube_1_a, a_1);
  digitalWrite(tube_0_d, d_0);
  digitalWrite(tube_0_c, c_0);
  digitalWrite(tube_0_b, b_0);
  digitalWrite(tube_0_a, a_0);
}


void cycle_all_tubes(){
  int del = 200;
  writeTube_3(9); 
  delay(del);
  writeTube_3(8);
  delay(del);
  writeTube_3(7);
  delay(del);
  writeTube_3(6);
  delay(del);
  writeTube_3(5);
  delay(del);
  writeTube_3(4);
  delay(del);
  writeTube_3(3);
  delay(del);
  writeTube_3(2);
  delay(del);
  writeTube_3(1);
  delay(del);
  writeTube_3(0);
  delay(del);
  writeTube_2(9); 
  delay(del);
  writeTube_2(8);
  delay(del);
  writeTube_2(7);
  delay(del);
  writeTube_2(6);
  delay(del);
  writeTube_2(5);
  delay(del);
  writeTube_2(4);
  delay(del);
  writeTube_2(3);
  delay(del);
  writeTube_2(2);
  delay(del);
  writeTube_2(1);
  delay(del);
  writeTube_2(0);
  delay(del);
  writeTube_1(9); 
  delay(del);
  writeTube_1(8);
  delay(del);
  writeTube_1(7);
  delay(del);
  writeTube_1(6);
  delay(del);
  writeTube_1(5);
  delay(del);
  writeTube_1(4);
  delay(del);
  writeTube_1(3);
  delay(del);
  writeTube_1(2);
  delay(del);
  writeTube_1(1);
  delay(del);
  writeTube_1(0);
  delay(del);
  writeTube_0(9); 
  delay(del);
  writeTube_0(8);
  delay(del);
  writeTube_0(7);
  delay(del);
  writeTube_0(6);
  delay(del);
  writeTube_0(5);
  delay(del);
  writeTube_0(4);
  delay(del);
  writeTube_0(3);
  delay(del);
  writeTube_0(2);
  delay(del);
  writeTube_0(1);
  delay(del);
  writeTube_0(0);
  delay(1000);
}

