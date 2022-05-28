
const byte blueLed = 4;
const byte redLed = 6;
const byte purpleLed = 8;

bool blueState = false;
bool redState = false;
bool purpleState = false;

String inputString = "";  // a String CMD from unity
bool stringComplete = false;

void setup() {
  Serial.begin(9600);
  inputString.reserve(200); 
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(purpleLed, OUTPUT);
}

void loop() {
  if (stringComplete) {
    Serial.print("CMD received: ");
    Serial.println(inputString);
    inputString.trim();
    processCmd(inputString);
    inputString = "";
    stringComplete = false;
  }
} // EOF loop()


// ocurre automáticamente cada que finaliza el loop()
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    }
    else {
      inputString += inChar;
    }
  }
} // EOF serialEvent


void processCmd(String cmd){
  if (cmd.equals("azul")){
    blueState = !blueState;
    digitalWrite(blueLed, blueState);
  }
  else if (cmd.equals("rojo")){
    redState = !redState;
    digitalWrite(redLed, redState);
  }
  else if (cmd.equals("morado")){
    purpleState = !purpleState;
    digitalWrite(purpleLed, purpleState);
  }
} // EOF processCmd
