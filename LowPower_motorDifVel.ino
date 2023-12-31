
 #include <LowPower.h> // https://github.com/rocketscream/Low-Power

#define motorPin 10
#define ledPin 9
#define buttonPin 2

long interval=5000;
unsigned long debounceTime = 50;
unsigned long lastDebounceTime = 0;  // the last time the button was pushed
int value=0;
unsigned long timer=0;
uint8_t sequence=0;
int pattern=0;
unsigned long timePattern=0;
int x=0;

//==Setting parameters
int valuePattern1[6]={25,75,50,250,25,250}; 
int delayPattern1[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern1[6]={500,250,100,500,500,500};

int valuePattern2[6]={100,125,250,250,25,250}; 
int delayPattern2[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern2[6]={500,250,100,500,500,500};

int valuePattern3[6]={100,125,250,250,25,250}; 
int delayPattern3[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern3[6]={500,250,100,500,500,500};

int valuePattern4[6]={100,125,250,250,25,250}; 
int delayPattern4[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern4[6]={500,250,100,500,500,500};

int valuePattern5[6]={100,125,250,250,25,250}; 
int delayPattern5[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern5[6]={500,250,100,500,500,500};

int valuePattern6[6]={100,125,250,250,25,250}; 
int delayPattern6[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern6[6]={500,250,100,500,500,500};

int valuePattern7[6]={100,125,250,250,25,250}; 
int delayPattern7[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern7[6]={500,250,100,500,500,500};

int valuePattern8[6]={100,125,250,250,25,250}; 
int delayPattern8[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern8[6]={500,250,100,500,500,500};

int valuePattern9[6]={100,125,250,250,25,250}; 
int delayPattern9[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern9[6]={500,250,100,500,500,500};

int valuePattern10[6]={100,125,250,250,25,250}; 
int delayPattern10[6]={5000,2500,1000,5000,5000,5000};
//int delayPattern10[6]={500,250,100,500,500,500};

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);
  pinMode(motorPin,OUTPUT);
  
  Serial.begin(9600);
  
  analogWrite(motorPin,0);
  analogWrite(ledPin,0);

  //goToSleep();
}



void loop(){
  
   
    if(!digitalRead(buttonPin)){ 
    lastDebounceTime = millis();
      
      while(!digitalRead(buttonPin)){}

     if ((millis() - lastDebounceTime) >interval) {
            pattern=0;
            analogWrite(motorPin,0);
          analogWrite(ledPin,0);
            Serial.println(" ");
            Serial.println("Go to sleep zzz...");
        delay(500);
        goToSleep();

       }
     else if ((millis() - lastDebounceTime) > debounceTime) {
            
      pattern++;

            if(pattern>10) pattern=1;
            Serial.println(" ");
      Serial.print("Pattern= ");
      Serial.println(pattern);
      x=0;
       }
       
     }
     

  if(pattern==1){
    pattern1();
  }
  else if(pattern==2){
    pattern2();
  }
  else if(pattern==3){
    pattern3();
  }
  else if(pattern==4){
    pattern4();
  }
  else if(pattern==5){
    pattern5();
  }
  else if(pattern==6){
    pattern6();
  }
  else if(pattern==7){
    pattern7();
  }
  else if(pattern==8){
    pattern8();
  }
  else if(pattern==9){
    pattern9();
  }
  else if(pattern==10){
    pattern10();
  }
   
  

}



void goToSleep(){
  // Allow wake up pin to trigger interrupt on low.
    attachInterrupt(digitalPinToInterrupt(buttonPin), wakeUp, LOW);
    
    // Enter power down state with ADC and BOD module disabled.
    // Wake up when wake up pin is low.

    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
    
    Serial.println("Wake up!");
    
    // Disable external pin interrupt on wake up pin.
    detachInterrupt(digitalPinToInterrupt(buttonPin));
    
       
}

void wakeUp(){

  // Just a handler for the pin interrupt.  
}

void pattern1(){
  if(millis()-timePattern>delayPattern1[x]){
      Serial.print(valuePattern1[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern1[x]);
      analogWrite(ledPin,valuePattern1[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern2(){
  if(millis()-timePattern>delayPattern2[x]){
      Serial.print(valuePattern2[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern2[x]);
      analogWrite(ledPin,valuePattern2[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern3(){
  if(millis()-timePattern>delayPattern3[x]){
      Serial.print(valuePattern3[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern3[x]);
      analogWrite(ledPin,valuePattern3[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern4(){
  if(millis()-timePattern>delayPattern4[x]){
      Serial.print(valuePattern4[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern4[x]);
      analogWrite(ledPin,valuePattern4[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern5(){
  if(millis()-timePattern>delayPattern5[x]){
      Serial.print(valuePattern5[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern5[x]);
      analogWrite(ledPin,valuePattern5[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern6(){
  if(millis()-timePattern>delayPattern6[x]){
      Serial.print(valuePattern6[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern6[x]);
      analogWrite(ledPin,valuePattern6[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern7(){
  if(millis()-timePattern>delayPattern7[x]){
      Serial.print(valuePattern7[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern7[x]);
      analogWrite(ledPin,valuePattern7[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern8(){
  if(millis()-timePattern>delayPattern8[x]){
      Serial.print(valuePattern8[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern8[x]);
      analogWrite(ledPin,valuePattern8[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern9(){
  if(millis()-timePattern>delayPattern9[x]){
      Serial.print(valuePattern9[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern9[x]);
      analogWrite(ledPin,valuePattern9[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}

void pattern10(){
  if(millis()-timePattern>delayPattern10[x]){
      Serial.print(valuePattern10[x]);
      Serial.print(" ");
      analogWrite(motorPin,valuePattern10[x]);
      analogWrite(ledPin,valuePattern10[x]);
      x++;
      if(x>=6){
        x=0;
        Serial.println(" ");
      }
      timePattern=millis();
  }

}
