#include <math.h>

int ir_pin = 8;
int led = 3;

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int temp = A0;     // Grove - Temperature Sensor connect to A0

int sensor_state = 0;

void setup()
{
  pinMode(ir_pin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  pinMode(temp, INPUT);

}

void loop()
{
  // read the state of the pushbutton value:
  //
  sensor_state = digitalRead(ir_pin);
  int a = analogRead(temp);
  float R = 1023.0/a-1.0;
  R = R0*R;

  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet

  //Serial.print("temperature = ");
  //Serial.println(temperature);
  //Serial.println(sensor_state);

  if(sensor_state == LOW) {
      digitalWrite(led, LOW);
      //Serial.println(sensor_state);

    }
  else if ((sensor_state == HIGH) && (temperature > 40)) {
    digitalWrite(led, HIGH);
    Serial.print("temperature = ");
    Serial.println(temperature);
    }
 
  Serial.print("jfkld;f\n");

}
