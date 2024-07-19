#include <DShot.h>

// Define the DShot ESC object with DSHOT600 mode
DShot esc1(DShot::Mode::DSHOT600);

void setup() {
  Serial.begin(9600);

  // Attach the ESC to digital pin 7
  esc1.attach(7);
  esc1.setThrottle(0);
}

void loop() {
  // Read the analog value from pin A7
  int analogValue = analogRead(A7);
  
  // Map the analog value (0 to 1023) to the DShot throttle range (0 to 2047)
  uint16_t throttle = map(analogValue, 0, 1023, 0, 2047);
 
  // Ensure throttle value is within the valid range
  if (throttle < 48) {
    throttle = 48;  // Minimum throttle value
  }
  Serial.println(throttle);

  // Send the mapped throttle value to the ESC
  esc1.setThrottle(throttle);
  
  // Small delay to avoid overloading the loop
  delay(10);
}