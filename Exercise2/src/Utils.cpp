#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void readData(const char* filename, double& S, int& n, double weights[], double returns[]) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open " << filename << endl;
        exit(1);
    }

    string line, label;

    // Read S
    getline(file, line);
    stringstream ss1(line);
    getline(ss1, label, ';');
    ss1 >> S;

    // Read n
    getline(file, line);
    stringstream ss2(line);
    getline(ss2, label, ';');
    ss2 >> n;

    // Skip header line
    getline(file, line);

    for (int i = 0; i < n; ++i) {
        getline(file, line);
        stringstream ss(line);
        string w_str, r_str;
        getline(ss, w_str, ';');
        getline(ss, r_str, ';');
        weights[i] = stod(w_str);
        returns[i] = stod(r_str);
    }

    file.close();
}

double computePortfolioReturn(const double weights[], const double returns[], int n) {
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += weights[i] * returns[i];
    }
    return result;
}

double computeFinalValue(double S, double portfolioReturn) {
    return S * (1 + portfolioReturn);
}

void printResults(double S, int n, const double weights[], const double returns[], double portfolioReturn, double finalValue, const char* outputFile) {
    ofstream out(outputFile);
    if (!out) {
        cerr << "Error: Cannot open output file." << endl;
        exit(1);
    }

    cout << fixed << setprecision(2);
    out << fixed << setprecision(2);

    cout << "S = " << S << ", n = " << n << endl;
    out << "S = " << S << ", n = " << n << endl;

    cout << "w = [ ";
    out << "w = [ ";
    for (int i = 0; i < n; ++i) {
        cout << weights[i] << " ";
        out << weights[i] << " ";
    }
    cout << "]" << endl;
    out << "]" << endl;

    cout << "r = [ ";
    out << "r = [ ";
    for (int i = 0; i < n; ++i) {
        cout << returns[i] << " ";
        out << returns[i] << " ";
    }
    cout << "]" << endl;
    out << "]" << endl;

    cout << "Rate of return of the portfolio: " << setprecision(4) << portfolioReturn << endl;
    cout << "V: " << setprecision(2) << finalValue << endl;

    out << "Rate of return of the portfolio: " << setprecision(4) << portfolioReturn << endl;
    out << "V: " << setprecision(2) << finalValue << endl;

    out.close();
}