/* SoftwareSerial send, esp8266 */

//
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(4, 5); /* RX:D4, TX:D5 */

unsigned long mTimeWait= 5000; 
unsigned long mTimer=0;
int mNextHttp= 60000;

//
void setup() {
  Serial.begin( 9600 );
  mySerial.begin( 9600 );
  Serial.println("#Start-setup-ssEsp");
}

String mBuff="";
//
void loop() {
   char cD1[10+1];
   char cD2[10+1];   
   int iD1=12;
   int iD2=43;
   sprintf(cD1 , "d1%08d", iD1);
mySerial.print( cD1 );
Serial.print("cD1=");
Serial.println(cD1  );
    delay( 500);
    //d2
    sprintf(cD2 , "d2%08d", iD2);
mySerial.print( cD2 );
Serial.print("cD2=");
Serial.println(cD2  );
    delay( 500); 
}

