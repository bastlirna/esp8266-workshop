/** Lekce 2 - Tlačítka
 * 
 */

// definice pinů ESP8266 na které jsou připojeny tlačítka
#define SW1 4
#define SW2 5
#define LED_G 12

bool led = HIGH;

void setup()
{
  pinMode(SW1, INPUT);
  pinMode(LED_G, OUTPUT);

  digitalWrite(LED_G, HIGH);
}

void loop()
{
  if (digitalRead(SW1) == LOW) 
  {
    led = !led;
    digitalWrite(LED_G, led);
  }
}

