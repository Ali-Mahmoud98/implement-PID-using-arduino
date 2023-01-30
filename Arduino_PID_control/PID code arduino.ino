double output, ref, controlSignal;
double kp, ki, kd;
// should enter the values of kp, ki and kd
// enter according to your system

int T;//sampling time vary according to your system
// practically should be 20 times faster than rising time(tr)
unsigned long lastTime;
double totalError, lastError;

int FeedBackPin = A1;
int feedBackV;
double temperature;
int outPin =4;

void setup(){
	pinMode(outPin, OUTPUT);
}

void loop(){
	feedBackV = analogRead(FeedBackPin);
	temperature = feedBackV * 0.488;
	ref = 25; //reference point
	
	PID_Control();

	analogWrite(Outpin, controlSignal);
}

void PID_Control(){
	unsigned long currentTime = millis();
	int deltaTime = currentTime - lastTime;

	if(deltaTime >= T){
		error = ref - output;
		totalError +=error;
		double deltaError = error - lastError;

		double controlSignal = kp * error + (ki/T) * totalError + (kp/T) * deltaError;
		lastError = error;
		lastTime = currentTime;

	}
}
