#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>
#include "EuOption.h"
#include "CRRBinomialTree.h"
#include "BinLattice.h"
#include "MonteCarlo.h"
#include <chrono>

using namespace std;

int main(int argc, char **argv)
{
	Type type = call;
	Type type2 = put;
	EuOption eu(0.03, 0.25, 100, 1, 100, 0, type);
	EuOption eu2(0.03, 0.25, 100, 1, 100, 0, type2);
	cout << "Black & Scholes formula : " << endl;
	cout << eu.blackScholesFormula(0.5) << endl;
	cout << eu2.blackScholesFormula(0.5) << endl;
	cout << "-------------------" << endl;
	cout << "delta : " << endl;
	cout << eu.delta(0.5) << endl;
	cout << eu2.delta(0.5) << endl;
	cout << "-------------------" << endl;
	CRRBinomialTree tree(0.03, 0.25, 100, 1, 100, 0, type, 100);
	CRRBinomialTree tree2(0.03, 0.25, 100, 1, 100, 0, type2, 100);
	cout << "Price : " << endl;
	cout << tree.price() << endl;
	cout << tree2.price() << endl;
	cout << "-------------------" << endl;
	cout << "Closed-Form formula : " << endl;
	cout << tree.closedForm() << endl;
	cout << tree2.closedForm() << endl;
	BinLattice binLat;
	binLat.setN(3);
	binLat.setNode(1, 1, 4);
	//cout << binLat.getNode(1, 1) << endl;
	//binLat.display();
	Type2 t = call2;
	MonteCarlo mc(0.03, 0.25, 100, 1, 100, 0, t);
	mc.riskyAsset(3);
	return 0;
}
