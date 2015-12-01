#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

#define PI 3.14159f

using namespace std;

void exeuler(double *y, const double dt);
void impeuler(double *y,const double dt);


int main(void)
{
	const double dt = PI/100.0;
	//const double dt = PI/10.0;
	
	double f[2];
	int i;
	
	ofstream ex("ex.dat");
	ofstream imp("imp.dat");
	
	/// Explicit Euler:
	f[0] = 1;
	f[1] = 0;

	for(i = 0; i*dt <= 20.0*PI; i++)
	{
		ex << i*dt << "\t" << f[0] << endl;
		exeuler(f,dt);
	}
	
	
	/// Implicit Euler:
	f[0] = 1;
	f[1] = 0;

	for(i = 0; i*dt <= 20.0*PI; i++)
	{
		imp << i*dt << "\t" << f[0] << endl;
		impeuler(f,dt);
	}
	
	ex.close();
	imp.close();
	
	exit(0);
}



void exeuler(double *y, const double dt)
{ 
	double temp = y[0];
	y[0] += dt*y[1];	
	y[1] += -dt*temp;
	return;
}

void impeuler(double *y,const double dt)
{
	double temp = y[0];
	const double einsdurchdet = 1.0/(1.0+dt*dt);
	y[0] = (y[0]+dt*y[1])*einsdurchdet;
	y[1] = (-dt*temp+y[1])*einsdurchdet;
	return;
}


	
