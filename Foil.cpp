#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class operators
{
    public:
        operators();
        ~operators();
        
        void setVariable(const char Variable);
        bool checkForVariables(const string userInput);
        void separateTerms(const string userInput);
        void separateVariableTerms( const string userInput);
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

operators::operators()
{
}

operators::~operators()
{
}

void operators::setVariable(const char Variable)
{
    variable = Variable;
    stringstream ss;
    ss << variable;
    ss >> s;
}

bool operators::checkForVariables(const string userInput)
{
    if (userInput.find(variable, 0) != string::npos) return true;
    else return false;
}

void operators::separateTerms(const string userInput)
{
    char checkString;
    string subString;
    int position1 = 0;
    for (int i = 0; i < userInput.length(); i++)
    {
        checkString = userInput[i];
        if (checkString == addition || checkString == subtraction
                || checkString == multiplication || checkString == division)
        {
            subString = userInput.substr(position1, i - position1);
            terms.push_back(subString);
            position1 = i + 1;
        }
        else if (i == userInput.length() - 1)
        {
            subString = userInput.substr(position1, i - position1 + 1);
            terms.push_back(subString);
            position1 = i + 1;
        }
    }
    for (auto &i : terms) 
        cout << i << ' ';
    cout << endl;
}

void operators::separateVariableTerms(const string userInput)
{
    for (int r = 0; r < terms.size(); r++)
        for (int c = 0; c < terms.size(); c++)
            if (terms[r][c] == variable)
                variableTerms.push_back(terms[r]);
          
    for (auto &i : variableTerms)
        cout << i << ' ';
    cout << endl;
}

void operators::separateNonVariableTerms(const string userInput)
{
    for (int r = 0; r < terms.size(); r++)
    {
        for (int c = 0; c < terms.size(); c++)
        {
            if (terms[r][c] == variable)
                break;
            else if ((terms[r][c] != variable) && (c == terms.size() - 1))
                nonVariableTerms.push_back(terms[r]);    
        }
    }

    for (auto &i : nonVariableTerms)
        cout << i << ' ';
    cout << endl;
}

void operators::getCoefficients(const string userInput)
{
    string Coefficient;
    double coefficient = 0;
    for (int r = 0; r < variableTerms.size(); r++)
    {
        for (int c = 0; c < variableTerms.size(); c++)
        {
            if (variableTerms[r][c] == variable)
                break;
            else Coefficient += variableTerms[r][c];        
        }
        coefficient = atoi(Coefficient.c_str());
        coefficients.push_back(coefficient);
    }
    cout << Coefficient << endl;

    for (auto &i : coefficients)
        cout << i << ' ';
    cout << endl;
        
}

int main()
{
    string userInput1, userInput2;
    char Variable;
    cout << "\nThis program is designed to do the basic foil method\n"
         << "You begin by inputting a string of characters and the\n"
         << "program will output the result.\n";
    
    cout << "What varaiable will you use: ";
    //cin >> Variable;
    Variable = 'x';
    operators op;
    op.setVariable(Variable);
    userInput1 = "x^2+22x+3";
    cout << "Input 1: " << userInput1 << endl;
    //cin >> userInput1;
    userInput2 = "x";
    cout << "Input 2: " << userInput2 << endl;
    //cin >> userInput2;
    if (op.checkForVariables(userInput1))
    {    
        op.separateTerms(userInput1);
        op.separateVariableTerms(userInput1);
        op.separateNonVariableTerms(userInput1);
        op.getCoefficients(userInput1);
    }
    return 0;
}
