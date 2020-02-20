#pragma config(Motor, port1, leftMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor, port5, clawMotor, tmotorVex269, openLoop, reversed)
#pragma config(Motor, port7, armMotor, tmotorVex393, openLoop, reversed)
#pragma config(Motor, port10, rightMotor, tmotorVex393, openLoop)

short movingForward = false; //Should be zero
short holdArm = false; //Should be zero
// double speedMultiplier = 1;

void resetMotor()
{
    motor[rightMotor] = 0;
    motor[leftMotor] = 0;
    if (holdArm == false)
    {
        motor[armMotor] = 0;
    }
}

void moveArmUp(int speed)
{
    motor[armMotor] = speed;
    resetMotor();
}

void freezeArm() {
    holdArm = true;
    motor[armMotor] = 10;
}

void unfreezeArm() {

holdArm = false;
    resetMotor();

}


void holdArmAt(int speed, int waitTime)
{
    holdArm = true;
    moveArmUp(speed);
    wait1Msec(waitTime);
    // motor[armMotor] = 20;
}

void turnLeft(int speed, int waitTime)
{
    //movingForward = 1;
    wait1Msec(1000);
    motor[rightMotor] = speed * -1;
    motor[leftMotor] = speed;
    wait1Msec(waitTime);
    resetMotor();
}

void turnRight(int speed, int waitTime)
{
    //movingForward = 1;
    wait1Msec(1000);
    motor[rightMotor] = speed;
    motor[leftMotor] = speed * -1;
    wait1Msec(waitTime);
    resetMotor();
}

void moveArmDown(int speed,)
{
    motor[armMotor] = -1 * speed;
    resetMotor();
}

void closeClaw()
{

    wait1Msec(1000);
    motor[clawMotor] = 70;
}

void openClaw()
{
    wait1Msec(750);
    motor[clawMotor] = -70;
    wait1Msec(800);
    resetMotor();
}

void moveForward(int speed, int waitTime)
{
    movingForward = 1;
    wait1Msec(3000);
    motor[rightMotor] = speed;
    motor[leftMotor] = speed;
    wait1Msec(waitTime);
    resetMotor();
    //movingForward = 0;
}

void driveControl(int leftMotor, int rightMotor) {

    motor[rightMotor] = rightMotor;
    motor[leftMotor] = leftMotor;

}

task main {
    while() {

        driveControl(vexRT[Ch2],vexRT[Ch3]);


        //Move Arm
        if (vexRT[Btn5D]) {
            moveArmDown(30);
            unfreezeArm();
        } else if (vexRT[Btn5U]) {
            moveArmUp(50);
            unfreezeArm();
        } else {
            freezeArm();
        }

        //Move Claw
        if (vexRT[Btn6D])
        {
            closeClaw();
        }
        else if (vexRT[Btn6U])
        {
            openClaw();
        }
    }
}