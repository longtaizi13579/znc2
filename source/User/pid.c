#include "pid.h"
#include "include.h"
//int begin_speed = 3000;//��ʼ�ٶ�
int lasterror = 0;//�ϴ����
int accerror = 0;//�ۻ����
//����pid
float direction_p = 3;
float direction_i = 0;
float direction_d = 0;
//���򻷿���,����������еĲ���ֵ������������ӵ�PWM��
//750���ң� -1020����
void direction_control(int leftvalue , int rightvalue)
{
   int leftspeed,rightspeed;
   int duty = 885;
   int error = leftvalue - rightvalue ;
   accerror = accerror + error;
   float pid = (float)(direction_p * error + direction_i * accerror + direction_d *(error - lasterror));
   lasterror = error;
   ftm_pwm_duty(FTM3, FTM_CH1,duty + pid);
}

//�ٶȻ�PID
pid_t pid_create(pid_t pid, float* in, float* out, float* set, float kp, float ki, float kd, float omin, float omax)
{
	pid->input = in;
	pid->output = out;
	pid->setpoint = set;
        pid->Kp = kp;
        pid->Ki = ki;
        pid->Kd = kd;
        pid->omin = omin;
        pid->omax = omax;

	// Set default sample time to 100 ms

	return pid;
}

void pid_compute(pid_t pid)
{
	float in = *(pid->input);
	// Compute error
	float error = (*(pid->setpoint)) - in;
	// Compute integral
	pid->iterm += error;
	if (pid->iterm > pid->omax)
		pid->iterm = pid->omax;
	else if (pid->iterm < pid->omin)
		pid->iterm = pid->omin;
	// Compute differential on input
	float dinput = in - pid->lastin;
	// Compute PID output
	float out = pid->Kp * error + pid->Ki *  pid->iterm - pid->Kd * dinput;
	// Apply limit to output value
	if (out > pid->omax)
		out = pid->omax;
	else if (out < pid->omin)
		out = pid->omin;
	// Output to pointed variable
	(*pid->output) = out;
	// Keep track of some variables for next execution
	pid->lastin = in;
}
