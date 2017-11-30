int tIdx = 0;

bool prevSensorValue = true;
bool sensorValue = true;

int buzzerPin = 3;
int sensorPin = 2;
int ledPins[] = {8,9,10,11,12,13};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  for (int i=0; i<6; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = digitalRead(sensorPin);
  
  if (prevSensorValue == true && sensorValue == false)
  {
    for (int i=0; i<6; i++)
    {
      digitalWrite(ledPins[i], LOW);
    }
    
    digitalWrite(ledPins[tIdx], HIGH);
    
    if (tIdx == 0)
    {
      tone(3, 500, 20);
    }
    tIdx = (tIdx + 1) % 3;
  }
  
  prevSensorValue = sensorValue;

}
