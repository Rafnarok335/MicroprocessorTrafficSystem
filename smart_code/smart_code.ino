//P10 - Smart Traffic System
//Done by:

int red = 6;
int yellow = 7;
int green = 8;

int button13 = 13;
int button12 = 12;
int button11 = 11;


void setup() {
  // put your setup code here, to run once:

  //pin 6,7,8 will be output pins
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  //setup pin 13,12,11 as input pin
  pinMode(button13, INPUT_PULLUP);
  //pinMode(button12, INPUT_PULLUP);
  //pinMode(button11, INPUT_PULLUP);

  //default
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
}



void loop() {
  if (digitalRead(button13) == LOW) {
    delay(15); // software debounce
    if (digitalRead(button13) == LOW) {
      // if the switch is HIGH, ie. pushed down - change the lights!
      changeLights();
    }
  }
  else {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
  }
}


void changeLights() {
  // green off, yellow on for 2 seconds
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  // this is to check if button is still pressed while delaying
  for (long int i = 0; i < 200000; i++) {
    // if button is released
    if (digitalRead(button13) == HIGH) {
      return;
    }
  }

  // turn off yellow, then turn red on for 6 seconds
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  for (long int i = 0; i < 600000; i++) {
    // if button is released
    if (digitalRead(button13) == HIGH) {
      return;
    }
  }

  // red and yellow on for 2 seconds (red is already on though)
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, HIGH);
  for (long int i = 0; i < 200000; i++) {
    // if button is released
    if (digitalRead(button13) == HIGH) {
      return;
    }
  }

  // turn off red and yellow, then turn on green
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  for (long int i = 0; i < 600000; i++) {
    // if button is released
    if (digitalRead(button13) == HIGH) {
      return;
    }
  }
}
