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
	void separateTerms(const string userInput);
	void separateVariableTerms(const string userInput);
	void separateNonVariableTerms(const string userInput);
	void getCoefficients(const string userInput);
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
};

#endif /* OperatorS_H_ */
