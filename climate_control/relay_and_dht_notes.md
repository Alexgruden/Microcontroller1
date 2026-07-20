### Relay Module:

Control Side:
- VCC: Connects to the positive power supply pin (usually +5V or +3.3V) to power the module's internal electronics.
- GND: Connects to the ground or negative terminal of your microcontroller's power supply to complete the control circuit.
- IN (or IN1, IN2, etc.): Receives the digital trigger signal from your microcontroller pin to turn the relay on or off.

Load Side:
- COM (Common): The main terminal where you connect the incoming live wire or primary power source for your appliance.
- NO (Normally Open): The terminal that is disconnected from COM by default; it connects and turns your device on only when a control signal is sent.
- NC (Normally Closed): The terminal that is connected to COM by default; it keeps your device on initially and disconnects to turn it off when a control signal is sent.

### DHT-22 Module
- Pin 1 — VCC: Connects to the positive power supply pin, supporting a voltage range of 3.3V to 5V.
- Pin 2 — DATA: Transmits the digital temperature and humidity data to your microcontroller pin.
- Pin 3 — NC (Not Connected): Serving no electrical function, this pin is left empty and unconnected.
- Pin 4 — GND: Connects to the ground or negative terminal of your power supply to complete the circuit.

### Substitutions made
- The red LED represents the fan motor activating
- The green LED on the relay output represents the solenoid valve opening