
#include "config.h"

// set up the 'counter' feed
AdafruitIO_Feed *light = io.feed("light");

// luminosite variable
int luminosity = 0;

void setup() {

  // start the serial connection
  Serial.begin(115200);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  luminosity = analogRead(A2);


  // save count to the 'counter' feed on Adafruit IO
  Serial.print("sending -> ");
  Serial.println(luminosity);
  light->save(luminosity);

  delay(3000);
}
