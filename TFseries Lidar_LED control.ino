/*
  DigitalReadSerial_LEDshows
  Reads a digital input on pin 2, prints the result to the Serial Monitor.
  And Display the status of distance via LED.
  If Distance ≤ 2m, LED is on.
  If Distance > 2m, LED is off.
  This example code is in the public domain.
*/

// digital pin 2 has a TFseries Lidar_GPIO wire attached to it. Give it a name:
int DetectPIN = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(DetectPIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int TF_IO_State = digitalRead(DetectPIN);
  // print out the state of the TFseries IO :
  Serial.println(TF_IO_State);
 //delay(100);        // delay in between reads for stability
  if(TF_IO_State == 1){
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.println("The distance is less than 2m");
  }
 if(TF_IO_State == 0){
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      Serial.println("The distance is more than 2m");  
  }
}
 
