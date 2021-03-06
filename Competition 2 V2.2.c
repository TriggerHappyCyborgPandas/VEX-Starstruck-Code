#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, dgtl2,  lift,           sensorTouch)
#pragma config(Sensor, dgtl12, shoot,          sensorTouch)
#pragma config(Motor,  port1,           int_1,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           BLR_Rightside, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           BR,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           BL,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           BLL,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           TLL,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           FR,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           FL,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           TLR_Middle,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          int_2,         tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(0)
#pragma userControlDuration(60)
#pragma systemFile            	// eliminates warning for "unreferenced" functions

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define C1LX vexRT[Ch4]
#define C1LY vexRT[Ch3]
#define C1RX vexRT[Ch1]
void pre_auton () {

}



task autonomous () {

motor(TLL) = -127;
motor(TLR_Middle) = -127;
motor(BLL) = -127;
motor(BLR_Rightside) = -127;
wait1Msec(1000);
motor(TLL) = -0;
motor(TLR_Middle) = -0;
motor(BLL) = -0;
motor(BLR_Rightside) = -0;
wait1Msec(200);
motor(TLL) = 127;
motor(TLR_Middle) = 127;
motor(BLL) = 127;
motor(BLR_Rightside) = 127;
wait1Msec(140);
motor(TLL) = -0;
motor(TLR_Middle) = -0;
motor(BLL) = -0;
motor(BLR_Rightside) = -0;
motor(int_1) = 125;
motor(int_2) = 125;
wait1Msec(270);
motor(int_1) = -0;
motor(int_2) = -0;
motor [FL] = 127;
motor [FR] = -127;
motor [BR] = -127;
motor [BL] = 127;
wait1Msec(1500);
motor [FL] = 0;
motor [FR] = -0;
motor [BR] = -0;
motor [BL] = 0;
motor(int_1) = -125;
motor(int_2) = -125;
wait1Msec(1000);
motor(int_1) = -40;
motor(int_2) = -40;
motor [FL] = -127;
motor [FR] = -127;
motor [BR] = -127;
motor [BL] = -127;
wait1Msec(570);
motor [FL] = -127;
motor [FR] = 127;
motor [BR] = 127;
motor [BL] = -127;
wait1Msec(1300);
motor [FL] = -0;
motor [FR] = 0;
motor [BR] = 0;
motor [BL] = -0;
wait1Msec(50);
motor(TLL) = -127;
motor(TLR_Middle) = -127;
motor(BLL) = -127;
motor(BLR_Rightside) = -127;
wait1Msec(1960);
motor(TLL) = -0;
motor(TLR_Middle) = -0;
motor(BLL) = -0;
motor(BLR_Rightside) = -0;
motor [FL] = -0;
motor [FR] = 0;
motor [BR] = 0;
motor [BL] = -0;
wait1Msec(100);
motor(int_1) = 125;
motor(int_2) = 125;
wait1Msec(400);
motor(int_1) = 0;
motor(int_2) = 0;
motor(TLL) = 127;
motor(TLR_Middle) = 127;
motor(BLL) = 127;
motor(BLR_Rightside) = 127;
wait1Msec(700);
motor(TLL) = 0;
motor(TLR_Middle) = 0;
motor(BLL) = 0;
motor(BLR_Rightside) = 0;
motor [FL] = 127;
motor [FR] = -127;
motor [BR] = -127;
motor [BL] = 127;
wait1Msec(1350);
motor [FL] = 0;
motor [FR] = -0;
motor [BR] = -0;
motor [BL] = 0;
motor(int_1) = -125;
motor(int_2) = -125;
wait1Msec(1000);
motor(int_1) = -40;
motor(int_2) = -40;
motor [FL] = -127;
motor [FR] = 127;
motor [BR] = 127;
motor [BL] = -127;
wait1Msec(1300);
motor(TLL) = -127;
motor(TLR_Middle) = -127;
motor(BLL) = -127;
motor(BLR_Rightside) = -127;
wait1Msec(2200);
motor(TLL) = -0;
motor(TLR_Middle) = -0;
motor(BLL) = -0;
motor(BLR_Rightside) = -0;
motor(int_1) = 125;
motor(int_2) = 125;
wait1Msec(400);
motor(int_1) = 0;
motor(int_2) = 0;
motor [FL] = -0;
motor [FR] = 0;
motor [BR] = 0;
motor [BL] = -0;
motor(TLL) = -0;
motor(TLR_Middle) = -0;
motor(BLL) = -0;
motor(BLR_Rightside) = -0;
}



task usercontrol() {

	while(true) {

		// Y component, X component, Rotation
		motor[FL] =   C1LY + C1LX + C1RX/2;
		motor[FR] =  -C1LY + C1LX + C1RX/2;
		motor[BR] =  -C1LY - C1LX + C1RX/2;
		motor[BL] =   C1LY - C1LX + C1RX/2;

		// Motor values can only be updated every 20ms
		wait10Msec(2);
		if(vexRT[Btn5D] == 1)
		{
			motor(TLL) = 127;
			motor(BLL) = 127;
			motor(TLR_Middle) = 127;
			motor(BLR_Rightside) = 127;
	  }
	  else if(vexRT[Btn5U] == 1)
	  {
	  	motor(TLL) = -127;
			motor(TLR_Middle) = -127;
			motor(BLL) = -127;
			motor(BLR_Rightside) = -127;

	  }
	   else
	  {
	  	motor(TLL) = 0;
			motor(TLR_Middle) = 0;
			motor(BLL) = 0;
      motor(BLR_Rightside) = 0;
	  }

	  if(vexRT[Btn6D] == 1)
	  {
	  motor(int_1) = 125;
	  motor(int_2) = 125;
	  }
	  else if(vexRT[Btn6U] == 1)
	  {
	  motor(int_1) = -125;
	  motor(int_2) = -125;
	  }
	  else if(vexRT[Btn8U] == 1)
	  {
	  motor(int_1) = -50;
	  motor(int_2) = -50;
	  }
	  else
	  {
	    motor(int_1) = 0;
	    motor(int_2) = 0;
	  }
	}

}
