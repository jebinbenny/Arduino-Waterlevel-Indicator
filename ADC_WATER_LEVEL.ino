
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int led9 = 5;
int led10 = 4;
int led11 = 3;
int led12 = 2;

int motorOnStatusPin = 15;
int waterStatusPin = 16;
int buzzerPin = 17;

int check = 0;
int counter = 0;
int isMotorOn = 0;
int isWaterThere = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorOnStatusPin, INPUT);
  pinMode(waterStatusPin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (12.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  Serial.println(sensorValue);

  // Read status of motor on pin
  isMotorOn = digitalRead(motorOnStatusPin); 
  
  if(isMotorOn == HIGH) {
    // Read status of  water pin
    isWaterThere = digitalRead(waterStatusPin);
    if(isWaterThere == HIGH) {
      // No problem there
    } else {
      delay(10000);
      // Read status of  water pin
      isWaterThere = digitalRead(waterStatusPin);
      if(isWaterThere == LOW) {
        //ERROR IN WATER FLOW
        // Blow false alarm!!!
        falseAlarm();
      }
    }
  }

  if(check == 0) {
    // Shows all level indicator LED up and down!
    switch (counter) {
      case 0:
         displayLevel1();
        break;
      case 1:
         displayLevel2();
        break;
      case 2:
         displayLevel3();
        break;
      case 3:
         displayLevel4();
        break;
      case 4:
         displayLevel5();
        break;
      case 5:
         displayLevel6();
        break;
      case 6:
         displayLevel7();
        break;
      case 7:
         displayLevel8();
        break;
      case 8:
         displayLevel9();
        break;
      case 9:
         displayLevel10();
        break;
      case 10:
         displayLevel11();
        break;
      case 11:
        displayLevel12();
        digitalWrite(buzzerPin, HIGH);
        delay(1000);
        break;
      case 12:
        displayLevel11();
        digitalWrite(buzzerPin, LOW);
        break;
      case 13:
        displayLevel10();
        break;
      case 14:
        displayLevel9();
        break;
      case 15:
        displayLevel8();
        break;
      case 16:
        displayLevel7();
        break;
      case 17:
        displayLevel6();
        break;
      case 18:
        displayLevel5();
        break;
      case 19:
        displayLevel4();
        break;
      case 20:
        displayLevel3();
        break;
      case 21:
        displayLevel2();
        break;
      case 22:
        displayLevel1();
        break;
      case 23:
        displayLevel0();
        delay(1000);
        break;
    }
    
    delay(100);
    counter = counter+1;
    if(counter == 23) {
      check = 1;
    }
  } else {
    digitalWrite(buzzerPin, LOW);
    if(sensorValue >= 900) {
      displayLevel12();
      if(isMotorOn == HIGH) {
        digitalWrite(buzzerPin, HIGH);
      }
      delay(500);
      digitalWrite(led1, LOW);
      digitalWrite(buzzerPin, LOW);
    } else if(sensorValue < 900 && sensorValue >= 825) {
      displayLevel11();
    } else if(sensorValue < 825 && sensorValue >= 750) {
      displayLevel10();
    } else if(sensorValue < 750 && sensorValue >= 675) {
      displayLevel9();
    } else if(sensorValue < 675 && sensorValue >= 600) {
      displayLevel8();
    } else if(sensorValue < 600 && sensorValue >= 525) {
      displayLevel7();
    } else if(sensorValue < 525 && sensorValue >= 450) {
      displayLevel6();
    } else if(sensorValue < 450 && sensorValue >= 375) {
      displayLevel5();
    } else if(sensorValue < 375 && sensorValue >= 300) {
      displayLevel4();
    } else if(sensorValue < 300 && sensorValue >= 220) {
      displayLevel3();
    } else if(sensorValue < 220 && sensorValue >= 140) {
      displayLevel2();
    } else if(sensorValue < 140 && sensorValue >= 100) {
      displayLevel1();
    } else if(sensorValue < 100){
      displayLevel0();
      digitalWrite(buzzerPin, LOW);
      delay(500);
      digitalWrite(led12, HIGH);
      digitalWrite(buzzerPin, HIGH);
    }
    delay(500);
  }
}

//Level 0 (Empty)
void displayLevel0() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  digitalWrite(led12, LOW);
}

//Level 1
void displayLevel1() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW);
  digitalWrite(led12, HIGH);
}

//Level 2
void displayLevel2() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 3
void displayLevel3() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 4
void displayLevel4() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 5
void displayLevel5() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 6
void displayLevel6() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 7
void displayLevel7() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 8
void displayLevel8() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 9
void displayLevel9() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 10
void displayLevel10() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 11
void displayLevel11() {
  digitalWrite(led1, LOW); 
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

//Level 12(Full)
void displayLevel12() {
  digitalWrite(led1, HIGH); 
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);
  digitalWrite(led12, HIGH);
}

void falseAlarm() {
//  for(int i = 0; i<20; i++) {
//    displayLevel0();
//    digitalWrite(buzzerPin, LOW);
//    delay(500);
//    displayLevel12();
//    digitalWrite(buzzerPin, HIGH);
//    delay(500);
//    digitalWrite(buzzerPin, LOW);
//  }
//  digitalWrite(buzzerPin, LOW);


  int showError = 1;
  while(showError != 0) {
    isMotorOn = digitalRead(motorOnStatusPin); 
    if(isMotorOn == HIGH) {
        isWaterThere = digitalRead(waterStatusPin);
        if(isWaterThere == HIGH) {
          // No problem there
          showError = 0;
        } else {
          digitalWrite(buzzerPin, HIGH);
          displayLevel12();
          delay(400);
          digitalWrite(buzzerPin, LOW);
          displayLevel0();
          delay(400);
        }
    } else {
      showError = 0;
    }
  }
  
}

/*
MAX: -  906 (900)
MIN: -  20 (80)
*/
