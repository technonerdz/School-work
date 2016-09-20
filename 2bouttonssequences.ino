//Utiliser 2 boutons pour créer des séquences

int buttonPin1= 2; // Défini que le bouton 1 est sur la pin 2
int buttonPin2 = 3; // Défini que le bouton 2 est sur la pin 3
int ledPin1 = 13; // Défini que la led est sur la pin 13

void setup() // initialisation
{
 pinMode(buttonPin1, INPUT); // C'est une pin de boutton donc c'est un input
 pinMode(buttonPin2, INPUT); // C'est une pin de boutton donc c'est un input
 pinMode(ledPin1, OUTPUT); // C'est une pin de led donc c'est un output
 delay(0); 
}


void loop(){ // Boucle infini
 int buttonState1 = digitalRead(buttonPin1); // écris l'état des bouttons dans des variables
 int buttonState2 = digitalRead(buttonPin2); // écris l'état des bouttons dans des variables
 
 if (buttonState1 == HIGH){ // Si on appuie sur le boutton 1
   digitalWrite(ledPin1, HIGH); // allume la led
   delay(100); // attend 100 ms
   digitalWrite(ledPin1, LOW); // éteint la led
   delay(100); // attend 100 ms
 }
 
 if (buttonState2 == HIGH){ // Si on appuie sur le boutton 2
   digitalWrite(ledPin1, HIGH); // allume la led
   delay(700); // attend 700 ms
   digitalWrite(ledPin1, LOW); // éteint la led
   delay(700); // attend 700 ms
 }
 
 }
