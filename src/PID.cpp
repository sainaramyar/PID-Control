
#include <random>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <math.h> 
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp1, double Ki1, double Kd1) {
	
	Kp = Kp1;
	Ki = Ki1;
	Kd = Kd1;
	
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
}

void PID::UpdateError(double cte) {
	
	d_error = cte - p_error;
	i_error += cte;
	p_error = cte;
	
	
}

double PID::TotalError() {
	double re = (-Kp * p_error) - (Ki * i_error) - (Kd * d_error);
	return re;
}

