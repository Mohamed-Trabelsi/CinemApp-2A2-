#define IR_output 2
#define led 8
void setup() {
pinMode(IR_output,INPUT);
pinMode(led,OUTPUT);

attachInterrupt(digitalPinToInterrupt(IR_output),detection_IR,CHANGE); //détecte un changement d'état
                                                                      //sur le signal du capteur
Serial.begin(9600);
}

void loop() {
}

void detection_IR(){
  if(digitalRead(IR_output)==HIGH){  //si le signal est à l'état haut
   Serial.println("mouvement detecte");
   digitalWrite(led,HIGH);
  }
  if(digitalRead(IR_output)==LOW){ //si le signal est à l'état bas
   Serial.println("pas de mouvement detecte");
   digitalWrite(led,LOW);
  }
}
