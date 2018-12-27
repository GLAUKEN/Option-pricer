#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>
#include "EuOption.h"
#include "BinLattice.h"
#include "AsianOption.h"
#include "AmericanOption.h"
#include <chrono>

using namespace std;

int main(int argc, char **argv)
{
	Type type = call;
	Type type2 = put;
	EuOption euCall(0.03, 0.25, 100, 1, 100, 100, 0, type);
	EuOption euPut(0.03, 0.25, 100, 1, 100, 100, 0, type2);
	cout << "Black & Scholes formula : " << endl;
	cout << "Call : " << euCall.blackScholesFormula(0.5) << endl;
	cout << "Put  : " << euPut.blackScholesFormula(0.5) << endl;
	cout << "-------------------" << endl;
	cout << "delta : " << endl;
	cout << "Call : " << euCall.delta(0.5) << endl;
	cout << "Put  : " << euPut.delta(0.5) << endl;
	cout << "-------------------" << endl;
	cout << "Price : " << endl;
	cout << "Call : " << euCall.price() << endl;
	cout << "Put  : " << euPut.price() << endl;
	cout << "-------------------" << endl;
	cout << "Closed-Form formula : " << endl;
	cout << "Call : " << euCall.closedForm() << endl;
	cout << "Put  : " << euPut.closedForm() << endl;
	/*
	BinLattice binLat;
	binLat.setN(3);
	binLat.setNode(1, 1, 4);
	cout << binLat.getNode(1, 1) << endl;
	binLat.display();
	 */
	cout << "-------------------" << endl;
	cout << "EuOption Monte Carlo :" << endl;
	cout << "Call : " << euCall.monteCarlo(10000) << endl;
	cout << "Put  : " << euPut.monteCarlo(10000) << endl;
	cout << "-------------------" << endl;
	cout << "AsianOption Monte Carlo :" << endl;
	AsianOption asianOp(0.03, 0.25, 100, 1, 100, type);
	cout << "Call : " << asianOp.monteCarlo(1000000) << endl;
	cout << "-------------------" << endl;
	AmericanOption americanOp(0.03, 0.25, 100, 1, 100, 100, type);
	cout << "American Option B & S :" << endl;
	cout << "Call : " << americanOp.blackScholesFormula(0.5) << endl;
	cout << "-------------------" << endl;
	cout << "American Option binomial :" << endl;
	cout << "Call : " << americanOp.price() << endl;
	return 0;
}
