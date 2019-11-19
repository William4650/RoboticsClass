#pragma config(Motor,  port1,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop)

short movingForward = false;

void resetMotor() {
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	motor[armMotor] = 0;
}

void turnRight(int speed, int waitTime) {
	//movingForward = 1;
	wait1Msec(1000);
	motor[rightMotor] = 0;
	motor[leftMotor] = speed;
	wait1Msec(waitTime);
	resetMotor();
}

void turnLeft(int speed, int waitTime) {
	//movingForward = 1;
	wait1Msec(1000);
	motor[rightMotor] = speed;
	motor[leftMotor] = 0;
	wait1Msec(waitTime);
	resetMotor();
}

void moveArmUp(int speed, int waitTime) {
	wait1Msec(1000);
	motor[armMotor] = speed;
	wait1Msec(waitTime);
	resetMotor();
}

void moveArmDown(int speed, int waitTime) {
	wait1Msec(1000);
	motor[armMotor] = -1 * speed;
	wait1Msec(waitTime);
	resetMotor();
}

void closeClaw() {

wait1Msec(1000);
	motor[clawMotor] = 70;

}

void openClaw() {
wait1Msec(750);
	motor[clawMotor] = -70;
	wait1Msec(800);
	resetMotor();

}

void moveForward(int speed, int waitTime) {
		movingForward = 1;
		wait1Msec(3000);
		motor[rightMotor] = speed;
		motor[leftMotor] = speed;
		wait1Msec(waitTime);
		resetMotor();
		//movingForward = 0;
}


task main()
{



}
