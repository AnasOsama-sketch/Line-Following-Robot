#define leftSensor 13
#define rightSensor 12

#define speedPin1 3
#define speedPin2 5

#define dirForward1 8
#define dirBackward1 7
#define dirForward2 2
#define dirBackward2 4

bool left, right;
//int carSpeed = 225;

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(speedPin1, OUTPUT);
  pinMode(speedPin2, OUTPUT);
  pinMode(dirForward1, OUTPUT);
  pinMode(dirBackward1, OUTPUT);
  pinMode(dirForward2, OUTPUT);
  pinMode(dirBackward2, OUTPUT);
  
  Stop();  
  Serial.begin(9600);
  MoveForward();

}

void loop() {
  left = digitalRead(leftSensor);
  right = digitalRead(rightSensor);

  Serial.print(left);
  Serial.print(", ");
  Serial.println(right);
  
  if(!left && !right)
  {
    MoveForward();
  }
  else if(left && !right)
  {
    TurnLeft();
  }
  else if(!left && right)
  {
    TurnRight();
  }
  else if(left && right)
  {
    Stop();
  }

}


void MoveForward()
{
  digitalWrite(dirForward1, HIGH);
  digitalWrite(dirBackward1, LOW);
  digitalWrite(speedPin1, HIGH);
  
  digitalWrite(dirForward2, HIGH);
  digitalWrite(dirBackward2, LOW);
  digitalWrite(speedPin2, HIGH);
}

void TurnRight()
{
  digitalWrite(dirForward1, LOW);
  digitalWrite(dirBackward1, HIGH);
  digitalWrite(speedPin1, HIGH);
  
  digitalWrite(dirForward2, HIGH);
  digitalWrite(dirBackward2, LOW);
  digitalWrite(speedPin2, HIGH);
}

void TurnLeft()
{
  digitalWrite(dirForward1, HIGH);
  digitalWrite(dirBackward1, LOW);
  digitalWrite(speedPin1, HIGH);
  
  digitalWrite(dirForward2, LOW);
  digitalWrite(dirBackward2, HIGH);
  digitalWrite(speedPin2, HIGH);
}

void Stop()
{
  digitalWrite(dirForward1, LOW);
  digitalWrite(dirBackward1, LOW);
  digitalWrite(speedPin1, LOW);
  
  digitalWrite(dirForward2, LOW);
  digitalWrite(dirBackward2, LOW);
  digitalWrite(speedPin2, LOW);
}
