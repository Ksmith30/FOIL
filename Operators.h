/*
 * Operators.h
 *
 *  Created on: May 19, 2017
 *      Author: kyle
 */

#ifndef OperatorS_H_
#define OperatorS_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Operators {
public:
	Operators(const char v = 0);
	Operators(const Operators &o);
	~Operators();

	void setVariable(const char Variable);
	bool checkForVariables(const string userInput);
	vector<string> separateTerms(const string userInput);
	vector<string> separateVariableTerms(vector<string> &terms);
	vector<string> separateNonVariableTerms(vector<string> &terms);
	vector<int> getCoefficients(vector<string> &variableTerms);
private:
	vector<string> terms;
	vector<string> variableTerms;
	vector<string> nonVariableTerms;
	vector<int> coefficients;
	char variable;
	string s;
	const static char addition = '+';
	const static char subtraction = '-';
	const static char multiplication = '*';
	const static char division = '/';
	const static char exponential = '^';
};

#endif /* OperatorS_H_ */
