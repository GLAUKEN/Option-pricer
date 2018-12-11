#ifndef EUOPTION_H
#define EUOPTION_H
#include "Option.h"

class EuOption : public Option
{
private:
	double b; //cost of carry
public:
	EuOption(double _r, double _sigma, double _K, double _T, double _S, double _b, Type _type);
	~EuOption();
	void display();
	double approxN(const double& x);
	double blackScholesFormula(double t);
	double delta(double t);
	double payOff(double S);
};

#endif // EUOPTION_H
