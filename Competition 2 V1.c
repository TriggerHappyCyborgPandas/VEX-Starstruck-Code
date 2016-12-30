#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, dgtl2,  lift,           sensorTouch)
#pragma config(Sensor, dgtl12, shoot,          sensorTouch)
#pragma config(Motor,  port1,           int_1,         tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           BLR_Rightside, tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           BR,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           BL,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           BLL,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           TLL,           tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           FR,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           FL,            tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           TLR_Middle,    tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          int_2,         tmotorVex393HighSpeed_HBridge, openLoop, reversed)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define C1LX vexRT[Ch4]
#define C1LY vexRT[Ch3]
#define C1RX vexRT[Ch1]

task main() {

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
	  motor(int_1) = 127;
	  motor(int_2) = 127;
	  }
	  else if(vexRT[Btn6U] == 1)
	  {
	  motor(int_1) = -127;
	  motor(int_2) = -127;
	  }
	  else if(vexRT[Btn8U] == 1)
	  {
	  motor(int_1) = 30;
	  motor(int_2) = 30;
	  }
	  else
	  {
	    motor(int_1) = 0;
	    motor(int_2) = 0;
	  }
	}

}
