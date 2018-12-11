#include "BinLattice.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

BinLattice::BinLattice() {
	N = 0;
}
BinLattice::~BinLattice() {
}
void BinLattice::setN(int _N) {
	N = _N;
	lattice.resize(N + 1);
	for (int i = 0; i < N + 1; i++) {
		lattice[i].resize(2 * i);
	}
}
void BinLattice::setNode(int n, int i, double val) {
	if (i < 0 || i > 2 * N || n > N) {
		cout << "[ERROR] : error parameters setNode() !" << endl;
	} else {
		vector<double> vec = lattice[n];
		vec[i] = val;
		lattice[n] = vec;
	}
}
double BinLattice::getNode(int n, int i) {
	vector<double> vec = lattice[n];
	return vec[i];
}
void BinLattice::display() {
	vector<double> vec;
	for (int i = 0; i < lattice.size() + 1; i++) {
		vec = lattice[i];
		for (int j = 0; j < vec.size(); j++) {
			cout << "Node(" << i - 1 << ", " << j << ")" << endl;
			cout << vec[j] << endl;
		}
	}
}
