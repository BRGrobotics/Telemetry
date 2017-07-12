const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;                  // z-axis (only on 3-axis models)
const int tempPin = A4;
const int ledPin = 13;
int state = (0,1);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  int x = ((((analogRead(xpin)-325))*.0119)*100);
  int y = ((((analogRead(ypin)-325))*.0119)*100);
  int z = ((((analogRead(zpin)-325))*.0119)*100);

  float reading = analogRead(tempPin);
  float voltage = reading * 5.0;
  voltage = voltage / 1024;
  float tempC = (voltage - 0.5) * 100 ;
  int t = (tempC);

  Serial.print("x:");
  Serial.print(x);
  Serial.print("\t");
  Serial.print("y:");
  Serial.print(y);
  Serial.print("\t");
  Serial.print("z:");
  Serial.print(z);
  Serial.print("\t");
  Serial.print(t);
  Serial.print("°C");
  Serial.print("\t");
  Serial.println();


  String t2 = String(abs(t), BIN);
  String x2 = String(abs(x), BIN);
  String y2 = String(abs(y), BIN);
  String z2 = String(abs(z), BIN);


    //establishes an int array with all 3 readings, will be
  //using to input data as well as determine how long the for
  //loop will run for
  int values1[4] = {t, x, y, z};
  String values2[4] = {t2, x2, y2, z2};
  
 

//the 3 is hardcoded, but the loop will call the resetfunction(), 
//use a switch to determine which indicator is used, and then print
//the number in binary preceded by a 1 or 0 determining + or -
for (int j = 0; j<=3; j++){
   while (values2[j].length() < 10){
       values2[j] = "0" + values2[j];
   }
   int length1 = values2[j].length();
   String current = values2[j];
   resetFunction();
   switch(j){
   case 0  :
      digitalWrite(13, LOW);Serial.print(0);
      delay(40);
      digitalWrite(13, LOW);Serial.print(0);
      delay(40);
      break; //optional
   case 1  :
      digitalWrite(13, HIGH);Serial.print(1);
      delay(40);
      digitalWrite(13, LOW);Serial.print(0);
      delay(40);;
      break; //optional
   case 2  :
      digitalWrite(13, LOW);Serial.print(0);
      delay(40);
      digitalWrite(13, HIGH);Serial.print(1);
      delay(40);;
      break; //optional
   case 3:
      digitalWrite(13, HIGH);Serial.print(1);
      delay(40);
      digitalWrite(13, HIGH);Serial.print(1);
      delay(40);
      break;
}
   
  for (int i = 0; i < length1; i++){
    if(current[i] == '0') state = LOW;
    if(current[i] == '1') state = HIGH;
    digitalWrite(13, state); Serial.print(state);
    delay(40);
  }

  
    Serial.println("");
}  

}


//arbitrary 4 states, currenty set to on, off, on, off
void resetFunction(){
  digitalWrite(13, HIGH); Serial.print(1);
  delay(40);
  digitalWrite(13, LOW); Serial.print(0);
  delay(40);
  digitalWrite(13, HIGH); Serial.print(1);
  delay(40);
  digitalWrite(13, LOW); Serial.print(0);
  delay(40);
}

