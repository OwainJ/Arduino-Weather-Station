void rain() {

  rainSensor = analogRead(A1);

  if (rainSensor > 1000) {
    Serial.print("Rain Sensor = ");
    Serial.println("Not Raining");
    digitalWrite(7, LOW); //Green LED off
    rainNum = 0;
  }

  else if (rainSensor < 300) {
    Serial.print("Rain Sensor = ");
    Serial.println("Heavy Rain");
    rainNum = 2;
    digitalWrite(7, HIGH); //Green LED on
  }

  else if (rainSensor < 1000) {
    Serial.print("Rain Sensor = ");
    Serial.println("Raining");
    rainNum = 1;
    digitalWrite(7, HIGH); //Green LED on
  }

}
