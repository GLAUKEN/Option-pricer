#include "CRRBinomialTree.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

CRRBinomialTree::CRRBinomialTree(double _r, double _sigma, double _K, double _T, double _S, double _b, Type _type, int _N) :
EuOption(_r, _sigma, _K, _T, _S, _b, _type) {
	N = _N;
}
CRRBinomialTree::~CRRBinomialTree() {
}
double CRRBinomialTree::up(int i) {
	return pow(exp(sigma * sqrt(T / N)), i);
}
double CRRBinomialTree::down(int i) {
	return pow(exp(-sigma * sqrt(T / N)), i);
}
double CRRBinomialTree::riskNeutralProbability() {
	return (exp(r * T / N) - down(1)) / (up(1) - down(1));
}
double CRRBinomialTree::stock(int n, int i) {
	return S * up(i) * down(n - i);
}
double CRRBinomialTree::price() {
	double * arr = new double[N + 1];
	double q = riskNeutralProbability();
	for (int i = 0; i <= N; i++) {
		arr[i] = payOff(stock(N, i));
	}
	for (int n = N - 1; n > 0; n--) {
		for (int i = 0; i <= n; i++) {
			arr[i] = (q * (arr[i + 1]) + (1 - q) * (arr[i])) / exp(r * T / N);
		}
	}
	return arr[0];
}
double CRRBinomialTree::factorielle(int n) {
	return n > 1 ? factorielle(n - 1) * n : 1;
}
double CRRBinomialTree::closedForm() {
	double result = 0;
	double q = riskNeutralProbability();
	for (int i = 0; i < N; i++) {
		result += factorielle(N) / (factorielle(i) * factorielle(N - i)) * pow(q, i) 
		* pow(1 - q, N - i) * payOff(stock(N, i));
	}
	return result / exp(r * T);
}