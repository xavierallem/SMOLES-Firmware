#include <BluetoothConnection.h>
#include <Constants.h>

class CharacteristicCallbacks: public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *characteristic)
  {
    std::string rxValue = characteristic->getValue(); 
    if (rxValue.length() > 0)
    {
      for (int i = 0; i < rxValue.length(); i++)
      {
        Serial.print(rxValue[i]);
      }
      Serial.println();

      if (rxValue.find("feedback") != -1)
      { 
        // ToDo: give haptic feedback
      }
    }
  }
};

class ServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer)
  {
    bluetoothDeviceConnected = true;
  };
 
  void onDisconnect(BLEServer* pServer)
  {
    bluetoothDeviceConnected = false;
  }
};

void BluetoothConnection::setup()
{
  // Serial.begin(115200); <-- Probably not necessary here

  BLEDevice::init("ESP32-BLE-test-server");

  // https://github.com/nkolban/esp32-snippets/issues/945
  BLEDevice::setMTU(517);

  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());

  BLEService *service = server->createService(SERVICE_UUID);
  characteristicTX = service->createCharacteristic(
                      CHARACTERISTIC_UUID_TX,
                      BLECharacteristic::PROPERTY_NOTIFY
                    );

  characteristicTX->addDescriptor(new BLE2902());

  BLECharacteristic *characteristic = service->createCharacteristic(
                                                    CHARACTERISTIC_UUID_RX,
                                                    BLECharacteristic::PROPERTY_WRITE
                                                  );

  characteristic->setCallbacks(new CharacteristicCallbacks());

  service->start();
  server->getAdvertising()->start();
}

void BluetoothConnection::notify(const char *message)
{
  if (bluetoothDeviceConnected)
  {
    characteristicTX->setValue(message);
    characteristicTX->notify();
    Serial.println("message sent");
  }
}
