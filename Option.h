#ifndef OPTION_H
#define OPTION_H

enum Type {call, put};

class Option
{
protected:
	double S;
	double K;
	double r;
	double T;
	double sigma;
	Type type;
public:
	Option(double _S, double _K, double _r, double _T, double _sigma, Type _type);
	~Option();
	virtual double payOff(double S)=0;
};

#endif // OPTION_H
