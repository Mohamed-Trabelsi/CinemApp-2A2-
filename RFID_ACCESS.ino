#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//Define variables 

#define I2C_ADDR          0x27        //Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN      3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7

//Initialise the LCD

#define SS_PIN 10
#define RST_PIN 9
#define LED_G 5 //define green LED pin
#define LED_R 4 //define red LED
#define BUZZER 2 //buzzer pin
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);  
void setup() 
{
    lcd.begin (16,2);
    lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(3); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);

  

}

void loop() 
{
  char data ;

 lcd.setCursor(0,0);
  lcd.print("Put Card..");
      if(Serial.available())
{
  data=Serial.read();
  if(data=='3')
  {
       lcd.setCursor(0,0);
  lcd.print("  ADMIN ACTION");
    lcd.setCursor(0,1);
    lcd.print("   Door Open ");
    myServo.write(90);
    delay(5000);
      lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("                ");

  }
  else if(data=='4')
  {
    lcd.setCursor(0,0);
  lcd.print("  ADMIN ACTION");
    lcd.setCursor(0,1);
    lcd.print("   Door Close ");
    myServo.write(0);
    delay(5000);
      lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("                ");
  }
}
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  
  lcd.setCursor(0,0);
  lcd.print("                ");
  //lcd.print("UID tag :");


  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //lcd.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  lcd.setCursor(0,0);
  lcd.print("Message : ");
  content.toUpperCase();
  if ((content.substring(1) == "EA 46 57 1A")) //change here the UID of the card/cards that you want to give access
  {
    Serial.print("1");
    lcd.setCursor(0,1);
    lcd.print("  Welcome Yosri");
    data=2;
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    
    delay(300);
    digitalWrite(LED_G, LOW);
    noTone(BUZZER);
    myServo.write(90);
    delay(1000);
    myServo.write(0);
    digitalWrite(LED_G, LOW);
  }
 
 else   { if ((content.substring(1) == "27 17 4C 34"))
 {
  Serial.print("2");
    lcd.setCursor(0,1);
    lcd.print(" Welcome Mohamed");
    data=1;
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 500);
    delay(300);
    
    digitalWrite(LED_R, LOW);
    noTone(BUZZER); 
    myServo.write(90);
    delay(1000);
    myServo.write(0);
    delay(300);
    }
    
    else   { 
    lcd.setCursor(0,1);
    lcd.print(" Access Denied!");
    digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
    noTone(BUZZER); 
  }
  }
delay(100);
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("                ");
  

  
 
}
