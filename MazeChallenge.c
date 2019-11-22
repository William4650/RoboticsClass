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

void turnLeft(int speed, int waitTime) {
	//movingForward = 1;
	wait1Msec(1000);
	motor[rightMotor] = speed*-1;
	motor[leftMotor] = speed;
	wait1Msec(waitTime);
	resetMotor();
}

void turnRight(int speed, int waitTime) {
	//movingForward = 1;
	wait1Msec(1000);
	motor[rightMotor] = speed;
	motor[leftMotor] = speed*-1;
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

//Heading to pickup ball
	openClaw();
	moveArmUp(25, 250);
	moveForward(90,900);
  turnLeft(50, 1750);
	moveForward(90,2300);
	turnRight(50,1750);
	moveForward(50,1500);
	turnRight(50,1800);
	moveForward(70,900);
	closeClaw();
	moveArmUp(50, 250);

	//Picked Up Ball, next step
	moveForward(-70,900);
	turnRight(50,1450);
	moveForward(50,2300);
	turnLeft(50,1800);
	moveForward(90,1000);
	turnLeft(50,1800);
	moveForward(90,1000);
	turnLeft(50,1800);
	moveForward(70,900);
	turnRight(50,1750);
	moveForward(50,1000);
	turnRight(50,1750);
	moveForward(70,800);
	openClaw();









}
