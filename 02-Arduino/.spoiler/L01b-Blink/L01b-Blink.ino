/** Lekce 1 - Blikání RGB LED
 */

// definice pinů ESP8266 na které jsou připojeny LED
#define LED_R 16
#define LED_G 12
#define LED_B 14

void setup()
{
  Serial.begin(9600);
  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

int a = 0;

void loop()
{
  analogWrite(LED_R, 1023 - a);
  analogWrite(LED_G, 1023 - a);
  analogWrite(LED_B, 1023 - a);

  a += 10;
  if (a >= 1023) a = 0;

  Serial.println(a);

  delay(100);
}

