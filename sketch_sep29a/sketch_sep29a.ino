int LED_BUILTIN_1 = 13;
int LED_BUILTIN_2 = 14;
void setup() {
pinMode(LED_BUILTIN_1, OUTPUT);
pinMode(LED_BUILTIN_2, OUTPUT); // Initialize onboard LED as output
}

void loop() {

digitalWrite(LED_BUILTIN_1, HIGH); // Turn the LED on
delay(1000); // Wait for a second

digitalWrite(LED_BUILTIN_1, LOW); // Turn the LED off
delay(1000); // Wait for a second



digitalWrite(LED_BUILTIN_2, HIGH); // Turn the LED on
delay(1000); // Wait for a second

digitalWrite(LED_BUILTIN_2, LOW); // Turn the LED off
delay(1000); // Wait for a second
}
