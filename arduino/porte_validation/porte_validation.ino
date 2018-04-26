/* 
 * Code d'exemple pour un capteur à ultrasons HC-SR04.
 */

/* Constantes pour les broches */
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
int LEDMETRO = 4;
int LEDPORTE = 5;
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

int resultat;

/** Fonction setup() */
void setup() {
   pinMode(LEDMETRO, OUTPUT);
   pinMode(LEDPORTE, OUTPUT);
  /* Initialise le port série */
  Serial.begin(115200);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
}
 
/** Fonction loop() */
void loop() {
 
  

  digitalWrite(LEDMETRO, HIGH);
  delay(700);
  digitalWrite(LEDPORTE,HIGH);
  delay(4000);


  
  resultat =  fun1();
  if (resultat / 10.0 <= 18){
   digitalWrite(LEDMETRO, HIGH);
   digitalWrite(LEDPORTE, HIGH);
  } else {
  digitalWrite(LEDPORTE,LOW);
  delay(700);
  digitalWrite(LEDMETRO,LOW);
  }

  


  

  delay(4000);
  
  

}

int fun1(){
     /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;

  return distance_mm;

}


