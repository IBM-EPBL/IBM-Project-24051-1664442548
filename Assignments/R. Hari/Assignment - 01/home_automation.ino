char degree = 176;
int trigger_pin = 2; //ultrasonic trigger pin
int echo_pin = 3;    //ultrasonic echo pin
int buzzer_pin = 10; //buzzer connection pin
int time;
int distance;
int pinTemp = A0; //temperature pin
int motor = 13;  //motor connection pin
int motorspeed = 17550;
void setup()
{
	Serial.begin (9600);
	pinMode (trigger_pin, OUTPUT);//ultrasonic part
	pinMode (echo_pin, INPUT);
	pinMode (buzzer_pin, OUTPUT);
  	pinMode (motor, OUTPUT);//temperature part
  	pinMode (pinTemp, INPUT);
  	pinMode	(11, OUTPUT);
  	pinMode	(9,	OUTPUT);
  	digitalWrite(motor, HIGH);
}
void loop()
{
	digitalWrite (trigger_pin, HIGH);  //ultrasonic part start
	delayMicroseconds (10);
	digitalWrite (trigger_pin, LOW);
	time = pulseIn (echo_pin, HIGH);
	distance = (time * 0.034) / 2;
	if (distance <= 10)
		{
			Serial.println(" Door Open");
			Serial.print (" Distance = ");
			Serial.println(distance);
			digitalWrite(buzzer_pin, HIGH);
			delay(500);
		}
	else
		{
			Serial.println(" Door Close ");
			Serial.print (" Distance= ");
			Serial.println(distance);
			digitalWrite (buzzer_pin, LOW);
			delay (500);
		}  //ultrasonic part ends
  	float tmp = analogRead(A0);
  float voltage = (tmp * 5.0)/1024;
  float milliVolt = voltage * 1000;
  float tmpCel =  (milliVolt-500)/10;
  if(tmpCel > 20){
    digitalWrite(11, HIGH);
  	digitalWrite(9, LOW);
    Serial.print(" Temperature: ");
    Serial.print(tmpCel);
    Serial.println(degree);
    Serial.println(" Fan is ON now"); 
    delay(500);
  }else{
    digitalWrite(11, LOW);
  	digitalWrite(9, LOW);
    Serial.print(" Temperature: ");
    Serial.print(tmpCel);
    Serial.println(degree);
    Serial.println(" Fan is Off now"); 
    delay(500);
  }
}




