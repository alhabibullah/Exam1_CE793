#include<stdio.h>
#include<conio.h>


#define dy(t,theta) -g/l*theta0*h
#define dtheta(t,theta) h*y0


int main()
{
	float theta0, y0, h, yn, thetan, slope_y1, slope_theta1, t, g, l, slope_y2, slope_theta2, slope_y3, slope_theta3, slope_y4, slope_theta4, k11, k12, k21, k22, k31, k32, k41, k42;

	int i, n;
	h = 0.15;
	t = 0;
	n = 40;
	theta0 = 0.349;
	y0 = 0;
	g = 9.81;
	l = 0.6;

	for (i = 0; i < n; i++)
	{
		slope_y1 = dy(t, theta);
		slope_theta1 = dtheta(t, theta);
		k11 =  slope_y1;
		k12 =  slope_theta1;

		slope_y2 = dy(t + h / 2, theta + k11 * h / 2);
		slope_theta2 = dtheta(t + h / 2, theta + k12 * h / 2);
		k21 =  slope_y2;
		k22 =  slope_theta2;

		slope_y3 = dy(t + h / 2, theta + k21 * h / 2);
		slope_theta3 = dtheta(t + h / 2, theta + k22 * h / 2);
		k31 = slope_y3;
		k32 =slope_theta3;

		slope_y4 = dy(t + h , theta + k31 * h );
		slope_theta4 = dtheta(t + h , theta + k32 * h );
		k41 = slope_y4;
		k42 = slope_theta4;


		yn = y0 + h*(k11+2*k21+2*k31+k41)/6;
		thetan = theta0 + h*(k12+2*k22+2*k32+k42)/6;
		printf("%f, %f \n", t, thetan);
		y0 = yn;
		theta0 = thetan;
		t = t + h;

	}
	printf("Runge Kutta 4th Order");
	return 0;
}