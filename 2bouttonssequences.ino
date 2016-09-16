//Utiliser 2 boutons pour créer des séquences

int buttonPin1= 2; // Défini que le bouton 1 est sur la pin 2
int buttonPin2 = 3; // Défini que le bouton 2 est sur la pin 3
int ledPin1 = 13; // Défini que la led est sur la pin 13

void setup()
{
 pinMode(buttonPin1, INPUT); // C'est une pin de boutton donc c'est un input
 pinMode(buttonPin2, INPUT); // C'est une pin de boutton donc c'est un input
 pinMode(ledPin1, OUTPUT); // C'est une pin de led donc c'est un output
 delay(0); 
}


void loop(){
 int buttonState1 = digitalRead(buttonPin1); // écris l'état des bouttons dans des variables
 int buttonState2 = digitalRead(buttonPin2); // écris l'état des bouttons dans des variables
 
 if (buttonState1 == HIGH){
   digitalWrite(ledPin1, HIGH);
   delay(100);
   digitalWrite(ledPin1, LOW);
   delay(100);
 }
 
 if (buttonState2 == HIGH){
   digitalWrite(ledPin1, HIGH);
   delay(700);
   digitalWrite(ledPin1, LOW);
   delay(700);
 }
 
 }
