                                                                                                                                                                                                                                                                                                                                                                                                                                #include <HID-Project.h>
#define inputCLK 1
#define inputDT 2
#define inputSW 3

int currentStateCLK;
int previousStateCLK;

void setup() {

  pinMode (inputCLK, INPUT);
  pinMode (inputDT, INPUT);
  pinMode(inputSW, INPUT_PULLUP);


  Serial.begin (9600);
  Consumer.begin();
  Keyboard.begin();

  
  previousStateCLK = digitalRead(inputCLK);
}

void loop() {
  // Read the current state of inputCLK
  currentStateCLK = digitalRead(inputCLK);

  // If the previous and the current state of the inputCLK are different then a pulse has occured
  if (currentStateCLK != previousStateCLK) {
    // If the inputDT state is different than the inputCLK state then
    // the encoder is rotating counterclockwise
    if (digitalRead(inputDT) != currentStateCLK) {
      rotateRight();
    } else {
      rotateLeft();
    }
  }
  // Update previousStateCLK with the current state
  previousStateCLK = currentStateCLK;
}

void rotateRight() {
  // Increase the volume.
  Consumer.write(MEDIA_VOLUME_UP);
}

void rotateLeft() {
  // Decrease the volume.
  Consumer.write(MEDIA_VOLUME_DOWN);
}
