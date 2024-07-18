#include <LoRa.h>

#define SS 15
#define RST 16
#define DIO0 2

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Transmitter Host");
  LoRa.setPins(SS, RST, DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa Error");
    while (1);
  }
}

void loop() {
  Serial.print("Sending Data: ");
  String message = "Hello, LoRa!";
  Serial.println(message);
  
  LoRa.beginPacket();
  LoRa.print(message);
  LoRa.endPacket();

  delay(1000); // Send a message every second
}
