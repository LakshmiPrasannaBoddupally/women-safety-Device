#include <SoftwareSerial.h>
#include <TinyGPS++.h>
SoftwareSerial mySerial(10,11);
static const int RXPin = 5, TXPin = 6;
static const int32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
int count=0;
float lt=17.42,ln=78.48;
void setup() {
  // put your setup code here, to run once;
Serial.begin(115200);
 mySerial.begin(9600);
  ss.begin(9600);
  pinMode(12,INPUT);
  
  }
void loop() { 
    if(ss.available()) {
    if (gps.encode(ss.read())){ 
       if (gps.location.isValid()){
      
         Serial.println("Location: "); 
         lt=gps.location.lat();
         Serial.println(gps.location.lat());
        delay(1000);
        Serial.println(gps.location.lng());
        ln=gps.location.lng();
        delay(1000);
         }
        else{
          lt=17.42;
          ln=78.48;
          
        }
        
    }
          
   }
        abcd();
}

   void abcd(){ 
  mySerial.println("AT+CMGF=1");
 
  mySerial.println("AT+CMGS=\"+919182664622\"\r");
 
  delay(1000);
  mySerial.println("Woman is in trouble");
  delay(1000);
  mySerial.println("Find me on Google Maps ");
  delay(1000);
  mySerial.print("https://www.google.com/maps/search/?api=1&query=");
 mySerial.print(17.42);
   delay(1000);
  mySerial.print(',');
   delay(1000);
  mySerial.print(78.48); 
   delay(500);
 
  mySerial.println((char)26);
  delay(1000);
  Serial.println("Message sent successfully");
}
