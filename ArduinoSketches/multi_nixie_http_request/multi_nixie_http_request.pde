import processing.serial.*;
import http.requests.*;

void draw(){
Serial the_port;    

//String portName = Serial.list()[5];
String portName = "/dev/cu.usbmodem1411";
println(Serial.list());
the_port = new Serial( this, portName, 9600 );


GetRequest get = new GetRequest("https://cdn.syndication.twimg.com/widgets/followbutton/info.json?screen_names=Sosolimited");
get.send();

String response_string = get.getContent();
String s = response_string.replaceAll("\\[", "").replaceAll("\\]","");
//response_string = response_string.replaceAll("[]"," ");
//println(response_string);
println(s);

JSONObject response = parseJSONObject(s);
//println(response.getString("formatted_followers_count"));

String followers = response.getString("formatted_followers_count").replaceAll("[^0-9]", "");
int f = Integer.parseInt(followers);


if( f % 10000 < 999){
  char top_digit = (followers.charAt(0));
  char thousands_digit = (followers.charAt(1));
  char hundreds_digit = (followers.charAt(2));
  char tens_digit = (followers.charAt(3));
  char ones_digit = (followers.charAt(4));
}

else {
  int thousands_digit = int(followers.charAt(0))-48;
  int hundreds_digit = int(followers.charAt(1))-48;
  int tens_digit = int(followers.charAt(2))-48;
  int ones_digit = int(followers.charAt(3))-48;
  
  println(f);
  println(thousands_digit);
  println(hundreds_digit);
  println(tens_digit);
  println(ones_digit);
  
  
  delay(2000);
  the_port.write(thousands_digit);
  delay(1200);
  the_port.write(hundreds_digit);
  delay(1200);
  the_port.write(tens_digit);
  delay(1200);
  the_port.write(ones_digit);
  delay(1200);
//  the_port.write(0);
  the_port.stop();
}
}

