#include<stdio.h>
#include<conio.h>

#define dy(t,theta) -g/l*theta0*h
#define dtheta(t,theta) h*y0

int main5()
{
	float theta0, y0, h, yn, thetan, slope_y, slope_theta, t, g, l;

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
		slope_y = dy(t, theta);
			slope_theta = dtheta(t, theta);
			yn = y0 + h * slope_y;
		thetan = theta0 + h * slope_theta;
		printf("%f, %f \n", t, thetan);
		y0 = yn;
		theta0 = thetan;
		t = t + h;

	}

	return 0;



}