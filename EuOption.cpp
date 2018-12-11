#include "EuOption.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

EuOption::EuOption(double _r, double _sigma, double _K, double _T, double _S, double _b, Type _type) :
Option(_S, _K, _r, _T, _sigma, _type) {
	b = _b;
}
EuOption::~EuOption() {
}
void EuOption::display() {
	cout << "------------------------------" << endl;
	cout << "Current price (S)   : " << S << endl;
	cout << "Strike (K)          : " << K << endl;
	cout << "Risk-free rate (r)  : " << r << endl;
	cout << "Maturity (T)        : " << T << endl;
	cout << "Volatility (sigma)  : " << sigma << endl;
	cout << "Cost of carry (b)   : " << b << endl;
	if (type == call) {
		cout << "Type                : Call" << endl; 
	} else {
		cout << "Type                : Put" << endl;
	}
	cout << "------------------------------" << endl;
}
double EuOption::approxN(const double& x) {
	double k = 1.0/(1.0 + 0.2316419*x);
	double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));
	if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - approxN(-x);
    }
}
double EuOption::blackScholesFormula(double t) {
	double price = 0;
	double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * (T - t)) / (sigma * sqrt(T - t));
	double d2 = d1 - sigma * sqrt(T - t);
	if (type == call) {
		price = S * approxN(d1) - K * exp(r * (t - T)) * approxN(d2);
	} else {
		price = K * exp(r * (t - T)) * approxN(-d2) - S * approxN(-d1);
	}
	return price;
}
double EuOption::delta(double t) {
	double delt = 0;
	double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * (T - t)) / (sigma * sqrt(T - t));
	if (type == call) {
		delt = approxN(d1);
	} else {
		delt = approxN(d1) - 1;
	}
	return delt;
}
double EuOption::payOff(double S) {
	if (S > 0) {
		if (type == call) {
			return (S > K) ? (S - K) : 0;
		} else {
			return (S < K) ? (K - S) : 0;
		}
	} else {
		cout << "[ERROR] : Parameter negative in PayOff !" << endl;
		return -1;
	}
}