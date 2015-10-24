int buttonPin = 10;  // change to whatever you want
int ledPin = 13; // just using for example

void setup()
{
  pinMode(ledPin, OUTPUT);     // LED as output
  pinMode(buttonPin, INPUT);    // button as input
  digitalWrite(buttonPin, HIGH); // turns on pull-up resistor after input
  Serial.begin(9600);

}

void loop()
{
  unsigned long startTime = millis();
  
  
  while (digitalRead(buttonPin) == LOW)  // when pin goes LOW
  {
    digitalWrite(ledPin, HIGH);           // turn on LED
  }
  
  unsigned long duration = millis() - startTime;

  if (duration > 1000)
  {
    Serial.println("password");  
  }
  else if (duration > 500)
  {
    Serial.println("copy");  
  }
  else if (duration > 50)
  {
    Serial.println("paste");  
  }

  
  digitalWrite(ledPin, LOW);        // well, turns led off!

}
