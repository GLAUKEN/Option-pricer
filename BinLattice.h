#ifndef BINLATTICE_H
#define BINLATTICE_H
#include <vector>

using namespace std;

class BinLattice
{
private:
	int N;
	vector<vector<double>> lattice;
public:
	BinLattice();
	~BinLattice();
	void setN(int _N);
	void setNode(int n, int i, double val);
	double getNode(int n, int i);
	void display();
};

#endif // BINLATTICE_H
