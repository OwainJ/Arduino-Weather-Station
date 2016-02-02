void temperature() {

  tempSensor = DHT.temperature;
  humidSensor = DHT.humidity;

  DHT.read11(dht_dpin);
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.println("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C  ");

  delay(100);
  //Don't try to access too frequently... in theory
  //should be once per two seconds, fastest,
  //but seems to work after 0.8 second.
}// end loop()
