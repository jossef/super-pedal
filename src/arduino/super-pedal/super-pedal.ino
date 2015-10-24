int pedalPin = 10;
int ledPin = 13; 

void setup()
{
  pinMode(ledPin, OUTPUT);     
  pinMode(pedalPin, INPUT);    
  digitalWrite(pedalPin , HIGH);
  Serial.begin(9600);
}

void loop()
{
  unsigned long startTime = millis();
    
  while (digitalRead(pedalPin) == LOW)  
  {
    digitalWrite(ledPin, HIGH);
  }
  
  unsigned long duration = millis() - startTime;

  if (duration > 1000)
  {
    Serial.println("password");  
    Keyboard.print("password");
  }
  else if (duration > 500)
  {
    Serial.println("copy");  
    
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(100);
    Keyboard.releaseAll();
    
  }
  else if (duration > 50)
  {
    Serial.println("paste");  
    
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();
    
  }

  digitalWrite(ledPin, LOW); 

}
