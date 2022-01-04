const int motor1 = 8;
const int motor2 = 7;
const int motor3 = 5;
const int motor4 = 4;
const int speed1 = 9;
const int speed2 = 3;

const int switch1 = 13;
const int switch2 = 12;
const int switch3 = 11;
const int switch4 = 10;

int speed = 0;

void setup()
{
  pinMode(motor1, OUTPUT); 
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);

  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);
  pinMode(switch3, INPUT_PULLUP);
  pinMode(switch4, INPUT_PULLUP);
  pinMode(A0, INPUT); // potentiometer
}

void forward() { // both motors move forward
  analogWrite(speed1, speed);
  analogWrite(speed2, speed);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}

void backward() { // both motors move backward
  analogWrite(speed1, speed);
  analogWrite(speed2, speed);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
}

void left() { // left motor moves backward right motor moves forward
  analogWrite(speed1, speed);
  analogWrite(speed2, speed);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
}

void right() { // left motor moves forward right motor moves backward
  analogWrite(speed1, speed);
  analogWrite(speed2, speed);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
}

void stop() { // stop both motors
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}

void loop()
{
  int potValue = analogRead(A0);
  speed = map(potValue, 0, 1023, 0, 255);

  int state1 = digitalRead(switch1);
  int state2 = digitalRead(switch2);
  int state3 = digitalRead(switch3);
  int state4 = digitalRead(switch4);

  if (state1 == HIGH) {
    forward();
  }
  else if (state2 == HIGH) {
    backward();
  }
  else if (state3 == HIGH) {
    left();
  }
  else if (state4 == HIGH) {
    right();
  }
  else {
    stop();
  }
}