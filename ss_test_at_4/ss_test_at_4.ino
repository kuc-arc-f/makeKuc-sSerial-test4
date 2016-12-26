/* SoftwareSerial  receive sample. (Atmega328P) 
*/

/* SoftwareSerial-Atmega328 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(5, 6); /* RX:D5, TX:D6 */

//
void setup() {
  Serial.begin( 9600 );
  mySerial.begin( 9600 );
  Serial.println("#Start-setup-SS");
}

//
boolean Is_validHead(String sHd){
  boolean ret=false;
  if(sHd=="d1"){
    ret= true;
  }else if(sHd=="d2"){
    ret= true;
  }
  return ret;
}
String mBuff="";
//
void loop() {
//  if(mySerial.available())
//  Serial.write(mySerial.read());

    while( mySerial.available() ){
      char c= mySerial.read();
      mBuff.concat(c );
      if(  mBuff.length() >= 10 ){
        String sHead= mBuff.substring(0,2);
        boolean bChkHd= Is_validHead( sHead );
        if(bChkHd== true){
          Serial.println( "Hd="+ sHead );
          Serial.println( "mBuff="+ mBuff );
        }        
        mBuff="";
      }
    }
/*
   char cD1[8+1];
   char cD2[8+1];   
   int iD1=12;
   int iD2=43;
   sprintf(cD1 , "d1%06d", iD1);
mySerial.print( cD1 );
Serial.print("cD1=");
Serial.println(cD1  );
    delay( 500);
*/
}



