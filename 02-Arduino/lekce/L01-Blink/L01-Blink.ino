/** Lekce 1 - Blikání RGB LED
 * 
 */

// definice pinů ESP8266 na které jsou připojeny LED
#define LED_R 16
#define LED_G 12
#define LED_B 14

void setup()
{
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, HIGH);
}

void loop()
{
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(LED_R, HIGH);
  delay(1000);
}

