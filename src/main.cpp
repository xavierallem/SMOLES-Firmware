#include <smoles.h>
#include <BluetoothConnection.h>

JsonDocument doc;
BluetoothConnection bluetoothConnection;
char txString[500]; // don't know if this size is good
int val = 0;
int analog[15] = {36,39,34,35,32,33,25,26,27,14,12,13,4,2,15};//Actuals Pins for the sensors in esp32

void initializeExampleJson()
{
  doc["timeStamp"] = millis();
  doc["leftFoot"] = true;

 
  JsonArray sensorData = doc.createNestedArray("sensorData");

  for(int i = 0;i<15;i++){
    
    val = analogRead(analog[i]);
    
    sensorData.add(val);
  }
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
