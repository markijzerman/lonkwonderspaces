#define loops 2
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5};
int delayTime = 2;
int sensitivity = 350; // tried & tested with 350 on macbook & pi with ground
int thisPin = 0;
int checkPin = 0;
int sensorValue = 0; 
int maxPin = 4; // 4 means 5 pins total. also make sure they're available in the analog_pins[] array, and there's enough space in the connectionArray
int connectionCount = 0;
int connectionArray[10];

void setup() {
  Serial.begin(115200);
}

void loop() { 
  if(thisPin > maxPin) {
    thisPin = 0;
    connectionCount = 0;
  }
  
  pinMode(analog_pins[thisPin], INPUT_PULLUP);

  for (int x = thisPin; x < maxPin; x++) {
    for (int k = 0; k < loops; k++) {
//      connectionArray[connectionCount] = 0;
      
      checkPin = x + 1;
      sensorValue = analogRead(analog_pins[checkPin]);

      if((sensorValue > sensitivity) && (connectionArray[connectionCount]!=1)) {
        connectionArray[connectionCount] = 1;
        Serial.print("msg= ");
        Serial.print("connect ");
        Serial.println(connectionCount);
    }


      if((sensorValue < sensitivity) && (connectionArray[connectionCount]!=0)) {
        connectionArray[connectionCount] = 0;
        Serial.print("msg= ");
        Serial.print("disconnect ");
        Serial.println(connectionCount);
      }
       delay(delayTime);        // delay in between reads for stability
    }

//    print full array for debugging
//    for(int i = 0; i < 10; i++)
//      {
//        Serial.print(connectionArray[i]);
//      }
//      Serial.println();


    
      connectionCount++;

  }
  
  digitalWrite(analog_pins[thisPin], 0) ;
  
  for (int k = 0; k < loops; k++) {
    delay(delayTime);        // delay in between reads for stability
  }

  thisPin++;
}
