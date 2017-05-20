/*
 * Operators.cpp
 *
 *  Created on: May 19, 2017
 *      Author: kyle
 */

#include "Operators.h"

Operators::Operators(const char v) {
	variable = v;
}

Operators::Operators(const Operators &o) {
	variable = o.variable;
}

Operators::~Operators() {
}

void Operators::setVariable(const char Variable) {
	variable = Variable;
	stringstream ss;
	ss << variable;
	ss >> s;
}

bool Operators::checkForVariables(const string userInput) {
	if (userInput.find(variable, 0) != string::npos)
		return true;
	else
		return false;
}

vector<string> Operators::separateTerms(const string userInput) {
	char checkString;
	string subString;
	int position1 = 0;
	for (int i = 0; i < userInput.length(); i++) {
		checkString = userInput[i];
		if (checkString == addition || checkString == subtraction
				|| checkString == multiplication || checkString == division) {
			subString = userInput.substr(position1, i - position1);
			terms.push_back(subString);
			position1 = i + 1;
		} else if (i == userInput.length() - 1) {
			subString = userInput.substr(position1, i - position1 + 1);
			terms.push_back(subString);
			position1 = i + 1;
		}
	}
	for (auto &i : terms)
		cout << i << ' ';
	cout << endl;
	return terms;
}

vector<string> Operators::separateVariableTerms(vector<string> &terms) {
	string temp;
	for (int i = 0; i < terms.size(); i++) {
		temp = terms[i];
		if (temp.find(s, 0) != string::npos) {
			variableTerms.push_back(terms[i]);
		}
	}

	for (auto &i : variableTerms)
		cout << i << ' ';
	cout << endl;
	return variableTerms;
}

vector<string> Operators::separateNonVariableTerms(vector<string> &terms) {
	string temp;
	vector<string> nonVariableTerms;
	for (int i = 0; i < terms.size(); i++) {
		temp = terms[i];
		if (temp.find(s, 0) == string::npos) {
			nonVariableTerms.push_back(terms[i]);
		}
	}

	for (auto &i : nonVariableTerms)
		cout << i << ' ';
	cout << endl;
	return nonVariableTerms;
}

vector<int> Operators::getCoefficients(vector<string> &variableTerms) {
	string Coefficient;
	double coefficient = 0;
	vector<int> coefficients;
	string temp;
	bool done = true;
	for (int i = 0; i < variableTerms.size(); i++) {
		temp = variableTerms[i];
		for (int j = 0; j < temp.length(); j++) {
			if (temp[j] == variable || temp[j] == exponential) {
				done = false;
				break;
			} else {
				Coefficient += temp;
			}
		}
		if (done) {
			continue;
		}
		coefficient = atoi(Coefficient.c_str());
		if (coefficient == 0) {
			coefficient = 1;
		}
		coefficients.push_back(coefficient);
	}

	for (auto &i : coefficients)
		cout << i << ' ';
	cout << endl;

	return coefficients;
}

int main() {
	string userInput1, userInput2;
	vector<string> terms, variableTerms, nonVariableTerms;
	vector<int> coefficients;
	char Variable;
	cout << "\nThis program is designed to do the basic foil method\n"
			<< "You begin by inputting a string of characters and the\n"
			<< "program will output the result.\n";

	cout << "What variable will you use: ";
	//cin >> Variable;
	Variable = 'x';
	Operators op;
	op.setVariable(Variable);
	userInput1 = "x^2+222x+3";
	cout << "Input 1: " << userInput1 << endl;
	//cin >> userInput1;
	userInput2 = "x";
	cout << "Input 2: " << userInput2 << endl;
	//cin >> userInput2;
	if (op.checkForVariables(userInput1)) {
		terms = op.separateTerms(userInput1);
		variableTerms = op.separateVariableTerms(terms);
		nonVariableTerms = op.separateNonVariableTerms(terms);
		coefficients = op.getCoefficients(variableTerms);
	}
	return 0;
}
