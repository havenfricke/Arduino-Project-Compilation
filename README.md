
### Ana_Digi_IO

Reads temperature data from an analog sensor, converts the signal into both Celsius and Fahrenheit, and displays the results over the serial monitor. Based on how much the temperature exceeds a defined baseline, the system activates up to three LEDs as a visual temperature indicator, with additional LEDs turning on as the temperature rises.

### Analog_Joystick

Reads input from a two-axis joystick with an integrated push-button. It continuously captures the joystick’s X and Y analog positions along with the digital state of the button and outputs these values to the serial monitor, allowing real-time monitoring and debugging of directional input and button presses.

### Arduino_Basic_IO

Monitors a push-button input and controls three LEDs in response. When the button is not pressed, a single green LED remains on. When the button is pressed, the green LED turns off and two red LEDs alternate in a blinking pattern, providing a clear visual indication of the button’s active state while also outputting the button status to the serial monitor.

### Basic_Servo_Motor

Uses a potentiometer to control the position of a servo motor. The potentiometer’s analog input is read, mapped to a rotational angle, and sent to the servo in real time, allowing smooth, proportional control of the servo’s movement while displaying the input and calculated angle in the serial monitor.

### capacitive_sensor

Uses a capacitive touch sensor to detect proximity or touch intensity and translate it into visual and audio feedback. As the sensed capacitance increases across defined thresholds, different LED color combinations are activated, and a buzzer is triggered at the highest level, providing an intuitive multi-level indication of user interaction strength.

### DC_Motor

Demonstrates bidirectional DC motor control using an L293D motor driver. It shows how to enable and disable the motor, reverse its direction, and vary its speed using PWM, providing clear examples of motor direction control, braking behavior, and gradual speed changes while reporting each test sequence to the serial monitor.

### Digi_Hourglass

Uses non-blocking timing with millis() to create a sequential LED pattern across multiple outputs. The LEDs illuminate one at a time at a fixed interval, and a push-button input allows the sequence to be reset instantly without stopping program execution, demonstrating responsive input handling and time-based control without delays.

### joystick_input

Reads a joystick’s X and Y analog axes along with its push-button click, normalizes the button logic for consistent use, and streams the input values over the serial connection. The formatted serial output is designed for real-time consumption by an external application, such as a Unity project, enabling the joystick to function as a custom input device.

### joystick_RotEnc_combo

Combines two input devices—a joystick and a rotary encoder—and streams their states over serial for external use (such as a Unity project). It reads the joystick’s X/Y analog movement and push-button click, then monitors the rotary encoder signals to infer left/right rotation and detect button input, providing a unified hardware control interface through a single serial output.

### magic_8-ball

Creates an interactive “Magic 8-Ball” style device using an LCD and a push button. Each button press selects a non-repeating random response from a predefined set and displays it on the screen, simulating a crystal ball that delivers varied answers while ensuring the same message is not shown twice in a row.

### MIDI_Control

Turns physical controls into a simple USB-MIDI drum/sequencer controller. It reads button inputs and a potentiometer, uses an 8-step counter to decide when different drum hits should fire, adds variation with randomized velocities and note choices, and sends the resulting MIDI note messages over USB to trigger drum sounds and a basic melodic sequence in a DAW or synth.

### Stepper_Motor_With_Remote

Uses an IR remote to control a stepper motor. When specific remote buttons are pressed, the sketch decodes the IR signal and rotates the motor one full revolution clockwise or counterclockwise at a set speed, then releases the motor coils to prevent holding torque and reduce power draw.

### Theramin_Tone_noTone

Calibrates an analog sensor for the first five seconds after startup by recording its highest and lowest readings. After calibration, it continuously reads the sensor and uses the live value to control the duration of tones played on a buzzer, creating an interactive sound response that adapts to the sensor’s measured range.

### two_motor

Lets an IR remote control two different motors through a single interface. Remote number buttons select which motor is currently active (stepper vs. DC motor), and the volume buttons then drive the selected motor forward or reverse—either stepping a full rotation for the stepper motor or switching direction on the DC motor via an H-bridge.

### UNO_WiFi_R2_Sensor_Data_HTTP_Post

Connects a WiFi-enabled board to a wireless network and periodically sends sensor data to a remote HTTPS server. It formats the data as a JSON payload, posts it to a cloud endpoint over a secure SSL connection, and logs the server’s response to the serial monitor, demonstrating basic IoT data reporting and cloud integration.

