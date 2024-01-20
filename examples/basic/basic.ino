#include <gpiobj.h>

gpiobj::DigitalInput button { PIN4 };
gpiobj::DigitalOutput led { LED_BUILTIN, false, gpiobj::SignalMode::Inverted };

void setup() {
}

void loop() {
  // Direct control of the LED from the button with simple debouncing
  led = button && button.hasNotChangedFor(100);

  // Toggling the LED every 10 seconds when not manually changing it for 10 seconds
  led.toggleIfUnchangedFor(10000);
}
