//Utiliser 2 boutons pour créer des séquences

int buttonPin1= 2; // Défini l'emplacement du bouton 1 sur la pin 2
int buttonPin2 = 3; // Défini l'emplacement du bouton 2 sur la pin 3
int ledPin1 = 13; // Défini l'emplacement de la led sur la pin 13

void setup() // Initialisation
{
 pinMode(buttonPin1, INPUT); // C'est une pin de bouton : input
 pinMode(buttonPin2, INPUT); // C'est une pin de bouton : input
 pinMode(ledPin1, OUTPUT); // C'est une pin de led donc c'est un output
 delay(0); 
}


void loop(){ // Boucle infinie
 int buttonState1 = digitalRead(buttonPin1); // Définis un alias pour faciliter l'écriture du code (pas obligatoire)
 int buttonState2 = digitalRead(buttonPin2); // Définis un alias pour faciliter l'écriture du code (pas obligatoire)
 
 if (buttonState1 == HIGH){ // Si le bouton 1 est enfoncé
   digitalWrite(ledPin1, HIGH); // Allume la led
   delay(100); // Attend 100 ms
   digitalWrite(ledPin1, LOW); // Éteint la led
   delay(100); // Attend 100 ms
 }
 
 if (buttonState2 == HIGH){ // Si le bouton 2 est enfoncé
   digitalWrite(ledPin1, HIGH); // Allume la led
   delay(700); // Attend 700 ms
   digitalWrite(ledPin1, LOW); // Éteint la led
   delay(700); // Attend 700 ms
 }
 
 }
