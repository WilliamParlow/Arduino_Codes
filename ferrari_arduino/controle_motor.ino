void ferrari_control(String option) {

  if (option.charAt(0) == 'w') { // frente
    goAhead = 'w';
    turn = '0';

  } else if (option.charAt(0) == 'd') { // direita
    turn = 'd';

  } else if (option.charAt(0) == 's') { // tras
    goAhead = 's';
    turn = '0';

  } else if (option.charAt(0) == 'a') { // esquerda
    turn = 'a';

  } else if (option.charAt(0) == 'e') { // frente direita
    goAhead = 'w';
    turn = 'd';

  } else if (option.charAt(0) == 'c') { // tras direita
    goAhead = 's';
    turn = 'd';

  } else if (option.charAt(0) == 'z') { // tras esquerda
    goAhead = 's';
    turn = 'a';

  } else if (option.charAt(0) == 'q') { // tras direita
    goAhead = 'w';
    turn = 'a';

  } else if (option.charAt(0) == 'x') { // Aumenta velocidade máxima
    setCarSpeed(10);
    bluetooth.print("Velocidade: ");
    bluetooth.println(SPEED);

  } else if (option.charAt(0) == 'y') { // Diminui velocidade máxima
    setCarSpeed(-10);
    bluetooth.print("Velocidade: ");
    bluetooth.println(SPEED);

  } else { // parado
    goAhead = '0';
    turn = '0';

  }

  engineControl();

}

void engineControl() {

  if (goAhead == 'w') {
    motorControl(SPEED);
  } else if (goAhead == 's') {
    motorControl(-SPEED);
  } else {
    motorControl(0);
  }

  if (turn == 'd') {
    motorTurn(TURN_SPEED);
  } else if (turn == 'a') {
    motorTurn(-TURN_SPEED);
  } else {
    motorTurn(0);
  }

}

void motorControl(int ferrariSpeed) {

  if (ferrariSpeed < 0)   {
    ferrariSpeed *= -1;
    digitalWrite(PININ3, HIGH);
    digitalWrite(PININ4, LOW);
  } else {
    digitalWrite(PININ3, LOW);
    digitalWrite(PININ4, HIGH);
  }

  analogWrite(PINENB, ferrariSpeed);

}

void motorTurn(int ferrariSpeed) {

  if (ferrariSpeed < 0)   {
    ferrariSpeed *= -1;
    digitalWrite(PININ1, HIGH);
    digitalWrite(PININ2, LOW);
  } else {
    digitalWrite(PININ1, LOW);
    digitalWrite(PININ2, HIGH);
  }

  analogWrite(PINENA, ferrariSpeed);

}

void setCarSpeed(int carSpeed) {
  SPEED += carSpeed;

  if (SPEED > 255) {
    SPEED = 255;
  } else if (SPEED < 0) {
    SPEED = 0;
  }

}

