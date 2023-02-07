int ch1;
int ch2;
int ch3;
int s;

int sped;
int cntrr = 6;
int dirr = 8;
int brkr = 10;
int cntrl = 5;
int dirl = 7;
int brkl = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);


  Serial.begin(9600);
  pinMode(cntrr, OUTPUT);
  pinMode(dirr, OUTPUT);
  pinMode(brkr, OUTPUT);
  pinMode(cntrl, OUTPUT);
  pinMode(dirl, OUTPUT);
  pinMode(brkl, OUTPUT);
  digitalWrite(brkr, LOW);
  digitalWrite(brkl, LOW);
}

void loop () {
  ch1 = pulseIn(6, HIGH, 25000); // Read the pulse width of

  ch2 = pulseIn(7, HIGH, 25000); // each channel

  ch3 = pulseIn(8, HIGH, 25000);
  
  forword(s);
  delay(3000);
  backward(s);
  delay(3000);
  turnright(s);
  delay(3000);
  turnleft(s);
  delay(3000);
  Stop();
  delay(5000);
}




void forword(int s) {

  // CHANNEL 2

  if (ch2 > 1620) {
    //up

    delay(100);
  }
  else if (ch2 < 1420) {
    // down

    delay(100);
  }
  else if (ch2 < 1590 && ch2 > 1320) {
    //center

    delay(100);
  }

  digitalWrite(brkr, LOW);
  digitalWrite(brkl, LOW);
  analogWrite(cntrr, s);
  analogWrite(cntrl, s);
  digitalWrite(dirr, HIGH);
  digitalWrite(dirl, HIGH);
  Serial.println("forward ever");
}

void backward(int s) {
  // CHANNEL 2

  if (ch2 > 1620) {
    //up

    delay(100);
  }
  else if (ch2 < 1420) {
    // down

    delay(100);
  }
  else if (ch2 < 1590 && ch2 > 1320) {
    //center

    delay(100);
    digitalWrite(brkr, LOW);
    digitalWrite(brkl, LOW);
    analogWrite(cntrr, s);
    analogWrite(cntrl, s);
    digitalWrite(dirr, LOW);
    digitalWrite(dirl, LOW);
    Serial.println("backward never");
  }
  //######
}

void turnright(int s) {
  // CHANNEL 1

  if (ch1 > 1670) {
    //turn left
    delay(100);
  }
  else if (ch1 < 1350) {
    //turn right
    delay(100);
  }
  else if (ch1 < 1600 && ch1 > 1400) {
    //re-center
    delay(100);
  }
  //#############################
  digitalWrite(brkr, LOW);
  digitalWrite(brkl, LOW);
  analogWrite(cntrr, 0);
  analogWrite(cntrl, s);
  digitalWrite(dirr, HIGH);
  digitalWrite(dirl, HIGH);
  Serial.println("the right way");
}

void turnleft(int s) {
  // CHANNEL 1

  if (ch1 > 1670) {
    //turn left
    delay(100);
  }
  else if (ch1 < 1350) {
    //turn right
    delay(100);
  }
  else if (ch1 < 1600 && ch1 > 1400) {
    //re-center
    delay(100);
  }
  //#############################
  digitalWrite(brkr, LOW);
  digitalWrite(brkl, LOW);
  analogWrite(cntrr, s);
  analogWrite(cntrl, 0);
  digitalWrite(dirr, HIGH);
  digitalWrite(dirl, HIGH);
  Serial.println("we have left that position");
}

void Stop() {
  digitalWrite(brkr, HIGH);
  digitalWrite(brkl, HIGH);
  analogWrite(cntrr, 0);
  analogWrite(cntrl, 0);
}
