
#include <iostream>
using namespace std;

// Dichiarazioni delle funzioni definite in utils.cpp
void readData(const char* filename, double& S, int& n, double weights[], double returns[]);
double computePortfolioReturn(const double weights[], const double returns[], int n);
double computeFinalValue(double S, double portfolioReturn);
void printResults(double S, int n, const double weights[], const double returns[], double portfolioReturn, double finalValue, const char* outputFile);


int main()
{const int MAX_ASSETS = 100;
    double weights[MAX_ASSETS];
    double returns[MAX_ASSETS];
    double S;
    int n;

    readData("data.txt", S, n, weights, returns);

    double portfolioReturn = computePortfolioReturn(weights, returns, n);
    double finalValue = computeFinalValue(S, portfolioReturn);
	printResults(S, n, weights, returns, portfolioReturn, finalValue, "result.txt");

    return 0;
}

