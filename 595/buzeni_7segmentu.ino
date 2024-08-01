    //Pin connected to ST_CP of 74HC595
    int latchPin = 12;
    //Pin connected to SH_CP of 74HC595
    int clockPin = 8;
    ////Pin connected to DS of 74HC595
    int dataPin = 11;

    void setup() {
      //set pins to output because they are addressed in the main loop
      pinMode(latchPin, OUTPUT);
      pinMode(clockPin, OUTPUT);
      pinMode(dataPin, OUTPUT);
      Serial.begin(9600);
    }

    void loop() {
      //count up routine
      for (uint8_t j = 0; j < 256; j++) {
        //ground latchPin and hold low for as long as you are transmitting
        digitalWrite(latchPin, LOW);
        fillShiftReg(j);
        digitalWrite(latchPin, HIGH);
        Serial.println("Current iteration: " + String(j));
      }
    }

    void fillShiftReg(uint8_t value){
      uint8_t tmp;
      for(uint8_t i = 0; i < 8; i++){
        tmp = (value >> i) & 1;
        digitalWrite(clockPin, LOW);
        digitalWrite(dataPin, tmp);
        Serial.println("bit: " + String(i) + " value: " + String(tmp));
        digitalWrite(clockPin, HIGH);
        delay(50);
      }
    }

