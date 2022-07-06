#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
 
/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
 
void setup(void) 
{
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif
  Serial.begin(9600);
  Serial.println("Accelerometer Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
 
  /* Set the range to whatever is appropriate for your project */
  accel.setRange(ADXL345_RANGE_16_G);
  // accel.setRange(ADXL345_RANGE_8_G);
  // accel.setRange(ADXL345_RANGE_4_G);
  // accel.setRange(ADXL345_RANGE_2_G);
  
  /* Display some basic information on this sensor */
}
   float temperature;
  float humidity;
  float pressure;
void loop(void) 
{
  /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
  temperature = event.acceleration.x;
  humidity = event.acceleration.y;
  pressure = event.acceleration.z;
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(temperature); Serial.print("  ");
  Serial.print("Y: "); Serial.print(humidity); Serial.print("  ");
  Serial.print("Z: "); Serial.print(pressure); Serial.print("  ");Serial.println("m/s^2 ");
  delay(500);
}
