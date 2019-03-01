#define loops 10
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5};
int delayTime = 2;
int sensitivity = 350; // tried & tested with 350 on macbook & pi with ground
int thisPin = 0;
int checkPin = 0;
int sensorValue = 0;
int maxPin = 4;

void setup() {
  Serial.begin(115200);
  
  
}

void loop() { 
  if(thisPin > maxPin) {
    thisPin = 0;
  }
  
  pinMode(analog_pins[thisPin], INPUT_PULLUP);

  for (int x = thisPin; x < maxPin; x++) {
    for (int k = 0; k < loops; k++) {
      
      checkPin = x + 1;
      sensorValue = analogRead(analog_pins[checkPin]);

      if(sensorValue > sensitivity) {
        //Serial.print("CONNECTION ");
        Serial.print(thisPin);
        Serial.print(" ");
        Serial.println(checkPin);
    }
    
      delay(delayTime);        // delay in between reads for stability
    }

  }
  
  digitalWrite(analog_pins[thisPin], 0) ;
  
  for (int k = 0; k < loops; k++) {
    delay(delayTime);        // delay in between reads for stability
  }

  thisPin++;
}
