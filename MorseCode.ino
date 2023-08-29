// code by lovleen kala
const int LED_PIN = LED_BUILTIN; // Define the pin for the built-in LED
const int BUTTON_PIN = 2;        // Push button pin for resetting the name

bool isButtonPressed = false; // Flag to track button press

void setup() {
  pinMode(LED_PIN, OUTPUT);        // Set LED pin as output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin as input with pull-up resistor
  Serial.begin(9600); // Start serial communication
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), resetName, FALLING); // Attach interrupt to button pin
}

void loop() {
  if (isButtonPressed) { // Check if the button has been pressed
    isButtonPressed = false; // Reset the button press flag
  }

  String inputName = readName(); // Read the name from serial input
  blinkMorseCode(inputName); // Blink Morse code for the input name

  delay(2000); // Gap between words
}

String readName() {
  String name = "";
  while (Serial.available()) { // Loop while serial data is available
    char c = Serial.read(); // Read a character from serial input
    if (c != '\n') { // If the character is not a newline
      name += c; // Append the character to the name string
    } else { // If the character is a newline
      break; // Exit the loop
    }
  }
  return name; // Return the read name
}

void resetName() {
  // Reset the name display here
  digitalWrite(LED_PIN, LOW); // Turn off the LED
  delay(1000); // Delay for 1 second
  digitalWrite(LED_PIN, HIGH); // Turn on the LED
  delay(1000); // Delay for 1 second
  digitalWrite(LED_PIN, LOW); // Turn off the LED
  delay(1000); // Delay for 1 second
}

void blinkDot() {
  digitalWrite(LED_PIN, HIGH); // Turn on the LED for a dot
  delay(200); // Keep the LED on for 200 milliseconds
  digitalWrite(LED_PIN, LOW); // Turn off the LED
  delay(200); // Keep the LED off for 200 milliseconds (dot duration)
}

void blinkDash() {
  digitalWrite(LED_PIN, HIGH); // Turn on the LED for a dash
  delay(600); // Keep the LED on for 600 milliseconds (dash duration)
  digitalWrite(LED_PIN, LOW); // Turn off the LED
  delay(200); // Keep the LED off for 200 milliseconds (gap between dots and dashes)
}

void blinkMorseCode(String text) {
  // Loop through each character in the input text
  for (size_t i = 0; i < text.length(); i++) {
    char c = toLowerCase(text[i]); // Convert the character to lowercase
    switch (c) {
      case 'a':
        blinkDot(); delay(500);
        blinkDash(); delay(1000);
        break;
      case 'b':
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        break;
       case 'c':
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'd':
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'e':
        blinkDot(); delay(500);
        break;
      case 'f':
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'g':
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'h':
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'i':
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'j':
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'k':
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'l':
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'm':
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'n':
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'o':
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'p':
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        break;
      case 'q':
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'r':
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        break;
      case 's':
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        break;
      case 't':
        blinkDash(); delay(500);
        break;
      case 'u':
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'v':
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'w':
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'x':
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'y':
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        break;
      case 'z':
        blinkDash(); delay(500);
        blinkDash(); delay(500);
        blinkDot(); delay(500);
        blinkDot(); delay(500);
        break;
      default:
        // Handle unsupported characters
        break;
    }
  }
}