const int buttonPin = 2; // broche du capteur PIR
const int ledPin = 3; // la LED du Arduino

int buttonState = 0; // etat de la sortie du capteur
 
void setup()
{

  pinMode(ledPin, OUTPUT); //la broche de la LED est mise en sortie
  pinMode(buttonPin, INPUT); //la broche du capteur est mise en entree
}
 
void loop()
{
  
  buttonState = digitalRead(buttonPin);//lecture du capteur
  if (buttonState == HIGH) //si quelquechose est detecte
  {
    analogWrite(ledPin, 255); //on allume la LED
  }
  else //sinon
  {
    analogWrite(ledPin, 50); //on eteint la LED
  }
  
}
