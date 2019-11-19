#pragma config(Motor,  port1,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393, openLoop)

short movingForward = false;

void moveForward(int waitTime) {
		movingForward = 1;
		wait1Msec(3000);
		motor[rightMotor] = 120;
		motor[leftMotor] = 120;
		wait1Msec(waitTime);
		//movingForward = 0;
}

void uturn(int waitTime) {
	//movingForward = 1;
	wait1Msec(1000);
	motor[rightMotor] = 0;
	motor[leftMotor] = 90;
	wait1Msec(waitTime);
}

void resetMotor() {
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}

task main()
{
		//This robot will go forward at 50 speed for 10 seconds
while(!movingForward) {
if (vexRT[Btn8D] == true && movingForward == 0) {
		moveForward(8500);
		resetMotor();
		uturn(1000);
		resetMotor();
		moveForward(1800);
		resetMotor();
		uturn(1000);
		resetMotor();
		moveForward(8500);
		resetMotor();
		movingForward = 0;
}
}
}
