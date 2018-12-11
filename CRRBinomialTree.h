#ifndef CRRBINOMIALTREE_H
#define CRRBINOMIALTREE_H
#include "EuOption.h"

class CRRBinomialTree : public EuOption
{
private:
	int N;
public:
	CRRBinomialTree(double _r, double _sigma, double _K, double _T, double _S, double _b, Type _type, int _N);
	~CRRBinomialTree();
	double up(int i);
	double down(int i);
	double riskNeutralProbability();
	double stock(int n, int i);
	double price();
	double factorielle(int n); //Mettre int
	double closedForm();
};

#endif // CRRBINOMIALTREE_H
