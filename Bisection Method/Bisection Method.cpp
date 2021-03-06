// Bisection Method.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>

#define F(x) ((100.0*(1+((8.0/3.0)*pow(x/100.0,2)) - ((32.0/5.0)*pow(x/100.0,4)) + ((256.0/7.0)*pow(x/100.0,6))))-125);

using namespace std;


//ε = desired precision
float bisection(float &a, float &b, const int nmax, float &ε);

void main()
{
	float a = 40, b = 30, e = 1 * pow(10,-9);
	const int nmax = 115;

	cout << e << endl;

	bisection(a, b, nmax, e);


	cin.ignore();
}

float bisection(float &a, float &b, const int nmax, float &ε)
{
	
	float c = 0, fc = 0, err = b-a;
	float fa = F(a);
	float fb = F(b);

	//Checks that the values provided sits on opposite sides
	//of the x axis otherwise no root can be found
	if((fa * fb) >= 0)
	{

		cout << "Fucntion has same signs at a and b\n\n";
		cout << "a = " << a << "\tb = " << b << "\tf(a) = " << fa << "\tf(b) = " << fb << endl;
		return c;
	}

	//Limits how many times the calculations can be done
	for (int n = 0; n < nmax; ++n)
	{
		err = err / 2;
		c = a + err;
		fc = F(c);

		cout << fixed << setprecision(6) << "n = " << n << "\tc = " << c << "\tf(c) = " << fc;
		cout << scientific << "\terror = " << err << endl;

		//Checks if the value has reached the defined precision
		if (abs(err) < ε)
		{
			cout <<fixed << setprecision(6)<< "\nConvergence at " << c << "\n\nPress any key to continue";
			return c;
		}

		//Signs are not the same
		if ((fa * fc) <= 0)
		{
			b = c;
			fb = fc;
		}
		//Signs are the same
		else
		{
			a = c;
			fa = fc;
		}

	}
	return c;
}
