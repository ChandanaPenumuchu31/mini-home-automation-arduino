#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); //TX, RX respetively
String command;
  int sensor=A0,
speaker=10,
fan=7,
light=9,
led=8;
void allon(){
     digitalWrite(10, HIGH); 
     digitalWrite(7, HIGH); 
     digitalWrite(9,  HIGH);
     digitalWrite(8,  HIGH);
  }
void alloff(){
     digitalWrite(10, LOW); 
     digitalWrite(7, LOW); 
     digitalWrite(9,  LOW);
     digitalWrite(8,  LOW);
}
void setup() {
 BT.begin(9600);
 Serial.begin(9600);
 pinMode(10, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(9, OUTPUT);
   pinMode(8, OUTPUT);


 
  lcd.begin(16, 2);
 
  lcd.print(" IOT  PROJECTS      ");
}


void loop() {// when characters arrive over the serial port...
  float temp=analogRead (A0);
  float tempc=temp*(50/1023);
  Serial.print("TEMP:");
  Serial.print(tempc);
  Serial.println("degree celcious");
  if (Serial.available()) {
    
    delay(100);
   
    lcd.clear();
    
    while (Serial.available() > 0) {
    
      lcd.write(Serial.read());
      {

    
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  command += c; //Shorthand for voice = voice + c
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  
  } 
   
  if (command.length() > 0) {
    Serial.println(command); 
    lcd.print(command);
 if(command == "all of"){(alloff());}
  else if(command == "all on"){(allon());}
  
  
    else if(command=="speaker of")
  
  {
    digitalWrite(10, LOW);                            
    
  } 
  
  else if(command == "speaker on") 
  {
    digitalWrite(10, HIGH);
    
  }
    else if(command == "fan of")
   {
     digitalWrite(7, LOW);
     
  } 
   else if(command == "fan on")
   {
     digitalWrite(7,HIGH);
     
  }
  
   
    
 else if(command == "light of")
 {
 digitalWrite(9,LOW);
 
 }
   else if(command == "light on") {
     digitalWrite(9,HIGH);}
     else if(command == "led on") {
     digitalWrite(8,HIGH);}
     
     else if(command == "led of")
 {
 digitalWrite(8,LOW);
  }

 

command="";}}}}}//Reset the variable after initiating
