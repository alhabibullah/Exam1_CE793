#include<stdio.h>
#include<conio.h>


#define dy(t,theta) -g/l*theta0*h
#define dtheta(t,theta) h*y0


int main2()
{
	float theta0, y0, h, yn, thetan, slope_y1, slope_theta1, t, g, l, slope_y2, slope_theta2,k11,k12,k21,k22;

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
		k11 = h*slope_y1;
		k12 = h*slope_theta1;
		slope_y2 = dy(t + h/2, theta + k11 * h / 2);
		slope_theta2 = dtheta(t+h/2, theta+k12*h/2);

		k21 = h*slope_y2;
		k22 = h*slope_theta2;
		yn = y0 + k21;
		thetan = theta0 + k22;
		printf("%f, %f \n", t, thetan);
		y0 = yn;
		theta0 = thetan;
		t = t + h;

	}
	printf("Runge Kutta 2nd Order");
	return 0;
}