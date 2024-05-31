#include <smoles.h>
#include <BluetoothConnection.h>

JsonDocument doc;
BluetoothConnection bluetoothConnection;
char txString[500]; // don't know if this size is good
int val = 0;

void initializeExampleJson()
{
  doc["timeStamp"] = millis();
  doc["leftFoot"] = true;

  val = analogRead(36);
  Serial.println(val);
  JsonArray sensorData = doc.createNestedArray("sensorData");
  sensorData.add(val);
  sensorData.add(2.545454222);
  sensorData.add(3.54545);
  sensorData.add(4.54545);
  sensorData.add(1.54511145);
  sensorData.add(2.545454222);
  sensorData.add(3.54545);
  sensorData.add(4.54545);
  sensorData.add(1.54511145);
  sensorData.add(2.545454222);
  sensorData.add(3.54545);
  sensorData.add(4.54545);
  sensorData.add(1.54511145);
  sensorData.add(2.545454222);
  sensorData.add(3.54545);
  sensorData.add(val);
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
  initializeExampleJson();
  initializeExampleMessage();
  bluetoothConnection.notify(txString);
  delay(1000);
}
