#include <LiquidCrystal_I2C.h>

  
int prgmSelect=0;
int bp1 = 8;
int bp2 = 9;
int bp3 = 10;
int bp4 = 11;
int bp5 = 12;
int bp6 = 13;
int Ebp1;
int Ebp2;
int Ebp3;
int Ebp4;
int Ebp5;
int Ebp6;
int mic = 1;
int casque = 1;
int rec = 0 ;
int stream = 0 ;

LiquidCrystal_I2C LCD(0x27, 16, 2); 

void setup() {
  LCD.init();
  LCD.backlight();
  pinMode (bp1,INPUT);
  pinMode (bp2,INPUT);
  pinMode (bp3,INPUT);
  pinMode (bp4,INPUT);
  pinMode (bp5,INPUT);
  pinMode (bp6,INPUT);

  Serial.begin(9600);
}

void loop() {
  Ebp1=digitalRead(bp1);
  Ebp2=digitalRead(bp2); 
  Ebp3=digitalRead(bp3); 
  Ebp4=digitalRead(bp4); 
  Ebp5=digitalRead(bp5); 
  Ebp6=digitalRead(bp6);
     
  if (Ebp1 == 1){
    prgmSelect=prgmSelect+1;
    LCD.clear();
    delay(500);
    if (prgmSelect>=8){
      prgmSelect=8;
    }
  }
  if (Ebp2 == 1){
    prgmSelect=prgmSelect-1;
    LCD.clear();
    delay(500);
    if (prgmSelect<=0){
      prgmSelect=0;
    }
  }

  if (prgmSelect == 1){
    LCDInit("League Of Legends");
    if ( Ebp3 == 1) {
      Slin("     Ouvrir     ");
      Serial.println("OLoL");
      delay(500);
    }
    if (Ebp4 == 1 ) {
      Slin("     fermer     ");
      Serial.println("CLoL");
      delay(500);
    }
  }

  if (prgmSelect == 2){
    LCDInit("Google Chrome");
    if ( Ebp3 == 1){
      Slin("     Google"       );
      Serial.println("GLE");
      delay(500);
    }
    if ( Ebp4 == 1) {
      Slin("    YouTube     ");
      Serial.println("YTB");
      delay(500);
    }
    if ( Ebp5 == 1){
      Slin("  Ecole Directe    ");
      Serial.println("eDir");
      delay(500);
    }
    if ( Ebp6 == 1){
      Slin("     amazon     ");
      Serial.println("AZ");
      delay(500);
    }
    
  }

  if (prgmSelect == 3){
    LCDInit("Spotify");
    if ( Ebp3 == 1) {
      Slin("     Ouvrir     ");
      Serial.println("OSpot");
      delay(500);
    }
    if (Ebp4 == 1 ) {
      Slin("     fermer      ");
      Serial.println("CSpot");
      delay(500);
    }
  }

  if (prgmSelect == 4){
    LCDInit("Discord");
    if ( Ebp3 == 1) {
      Slin("     Ouvrir     ");
      Serial.println("ODisc");
      delay(500);
    }
    if (Ebp4 == 1 ) {
      Slin("     fermer      ");
      Serial.println("CDisc");
      delay(500);
    }
    if (Ebp5 == 1 ){
      if (mic == 1){
        Slin("    micro ON       ");
        Serial.println("Mic");
        mic = 0;
      }
      else{
        Slin("    micro OFF      ");
        Serial.println("Mic");
        mic = 1;
      }
      delay(500);
    }
    if (Ebp6 == 1){
      if (casque == 0){
        Slin("    casque ON     ");
        Serial.println("Cas");
        casque = 1;
      }
      else{
        Slin("    casque OFF     ");
        Serial.println("Cas");
        casque = 0;
      }
    delay(500);
    }
  }

  if (prgmSelect == 5){
    LCDInit("Epic Games");
    if (Ebp3 == 1){
      Slin("     ouvrir       ");
      Serial.println("OEpic");
      delay(500);
    }
    if (Ebp4 == 1){
      Slin("     fermer      ");
      Serial.println("CEpic");
      delay(500);
    }
  }

  if (prgmSelect == 6){
    LCDInit("Steam");
    if (Ebp3 == 1){
      Slin("     ouvrir       ");
      Serial.println("OSteam");
      delay(500);
    } 
    if (Ebp4 == 1)
    {
      Slin("     fermer      ");
      Serial.println("CSteam");
      delay(500);
    }
    
  }

  if (prgmSelect == 7){
    LCDInit("OBS Studio");
    if (Ebp3 == 1){
      Slin("     ouvrir   ");
      Serial.println("OOBS");
      delay(500);
    }
    if (Ebp4 == 1){
      Slin("     fermer    ");
      Serial.println("COBS");
      delay(500);
    }
    if (Ebp5 == 1){
      if (rec == 0){
        Slin("     rec ON        ");
        Serial.println("RecON");
        rec = 1;
      }
      else {
        Slin("     rec OFF       ");
        Serial.println("RecOFF");
        rec = 0;
      }
      delay(500);
    }
    if (Ebp6 == 1){
      if (stream == 0){
        Slin("   stream ON      ");
        Serial.println("Stream");
        stream = 1;
      }
      else {
        Slin("   stream OFF       ");
        Serial.println("Stream");
        stream = 0;
      }
      delay(500);
    }
    
  }

  if (prgmSelect == 8){
    LCDInit(" Calculatrice     ");
    if (Ebp3 == 1){
      Slin("     ouvrir     ");
      Serial.println("OCalc");
      delay(500);
    }
    if (Ebp4 == 1){
      Slin("     fermer     ");
      Serial.println("CCalc");
      delay(500);
    }
    
  }

}

int LCDInit( const char* txt){
  LCD.setCursor(0,0);
  LCD.print(txt);
}

int Slin(const char* txt){
  LCD.setCursor(0,1);
  LCD.print(txt);
}
