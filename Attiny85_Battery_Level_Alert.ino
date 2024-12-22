//Attiny 85 기준으로 설정함. 
//                  ┍━━━━━┑
//            RESET ┥1   8┝ 5V
//            A3/D3 ┥2   7┝ D2/A1/SCK/SCL
//            A2/D4 ┥3   6┝ D1/PWM/MISO
//              GND ┥4   5┝ D0/PWM/MOSI/SDA/Aref
//                  ┕━━━━━┙
//                  ATTINY85
//이하 Attiny85용 핀아웃

#define VoltageLevel A2
#define Bat25 3
#define Bat50 2
#define Bat75 1
#define Bat100 0

int BatLevel;

void setup() {

	pinMode(Bat25, OUTPUT);
	pinMode(Bat50, OUTPUT);
	pinMode(Bat75, OUTPUT);
	pinMode(Bat100, OUTPUT);
	pinMode(VoltageLevel, INPUT);
}

void loop() {


	BatLevel = map(analogRead(VoltageLevel), 0, 1023, 0, 3);

	for(int i=0; i<BatLevel; i++){
		digitalWrite(Bat25, HIGH);
		delay(20);
		digitalWrite(Bat25, LOW);
		delay(20);
	}
	delay(100);
	/*
	switch (BatLevel) {
		case 0: //배터리 레벨 25% 이하
			digitalWrite(Bat25, HIGH);
			digitalWrite(Bat50, LOW);
			digitalWrite(Bat75, LOW);
			digitalWrite(Bat100, LOW);
	    break;

	    case 1:	//배터리 레벨 50% 이하
			digitalWrite(Bat25, HIGH);
			digitalWrite(Bat50, HIGH);
			digitalWrite(Bat75, LOW);
			digitalWrite(Bat100, LOW);
	    break;
	    case 2:	//배터리 레벨 75% 이하
			digitalWrite(Bat25, HIGH);
			digitalWrite(Bat50, HIGH);
			digitalWrite(Bat75, HIGH);
			digitalWrite(Bat100, LOW);
	    break;
	    case 3:	//배터리 레벨 100% 이하
			digitalWrite(Bat25, HIGH);
			digitalWrite(Bat50, HIGH);
			digitalWrite(Bat75, HIGH);
			digitalWrite(Bat100, HIGH);
	    break;

	}
	*/
}
