#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothConnection.h>

JsonDocument doc;
BluetoothConnection bluetoothConnection;
char txString[500]; // don't know if this size is good

void initializeExampleJson()
{
  doc["timeStamp"] = millis();
  doc["leftFoot"] = true;

  JsonArray sensorData = doc.createNestedArray("sensorData");
  sensorData.add(134524525);
  sensorData.add(1234523452);
  sensorData.add(323452345);
  sensorData.add(4345345);
  sensorData.add(522626);
  sensorData.add(23462466);
  sensorData.add(206436347);
  sensorData.add(8262364);
  sensorData.add(9262346);
  sensorData.add(23634610);
  sensorData.add(13462461);
  sensorData.add(122363246);
  sensorData.add(13262346);
  sensorData.add(1423462346);
  sensorData.add(1234623465);
  sensorData.add(126234636);
}

void initializeExampleMessage()
{
  serializeJson(doc, txString);

  Serial.print("Example message: ");
  Serial.println(txString);
}

void setup()
{
  Serial.begin(115200);
  initializeExampleJson();
  initializeExampleMessage();
  bluetoothConnection.setup();
}

void loop()
{
  bluetoothConnection.notify(txString);
  delay(5000);
}
