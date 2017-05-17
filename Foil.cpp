#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

const char addition = '+';
const char subtraction = '-';
const char multiplication = '*';
const char division = '/';

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
        char checkString;
        string subString;
        vector<string> terms;
        vector<string> variableTerms;
        vector<string> nonVariableTerms;
        int position1 = 0;
        char variable;
        int variablePosition;
        string s;
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

bool operators::checkForVariables(string userInput)
{
    if (userInput.find(variable, 0) != string::npos) return true;
    else return false;
}

void operators::separateTerms(string userInput)
{
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

void operators::separateVariableTerms(string userInput)
{
    for (int r = 0; r < terms.size(); r++)
        for (int c = 0; c < terms.size(); c++)
            if (terms[r][c] == variable)
                variableTerms.push_back(terms[r]);
          
    for (auto &i : variableTerms)
        cout << i << ' ';
    cout << endl;
}

void operators::separateNonVariableTerms(string userInput)
{
    for (int r = 0; r < terms.size(); r++)
    {
        for (int c = 0; c < terms.size(); c++)
        {
            if (terms[r][c] == variable)
                break;
            else
                nonVariableTerms.push_back(terms[r]);
            break;
        }
    }

    for (auto &i : nonVariableTerms)
        cout << i << ' ';
    cout << endl;
}

void operators::getCoefficients(const string userInput)
{
    
}

int main()
{
    string userInput1, userInput2;
    char Variable;
    cout << "\nThis program is designed to do the basic foil method\n"
         << "You begin by inputting a string of characters and the\n"
         << "program will output the result.\n";
    
    cout << "What varaiable will you use: ";
    cin >> Variable;
    operators op;
    op.setVariable(Variable);
    cout << "Input 1: ";
    cin >> userInput1;
    cout << "Input 2: ";
    cin >> userInput2;

    if (op.checkForVariables(userInput1))
    {    
        op.separateTerms(userInput1);
        op.separateVariableTerms(userInput1);
        op.separateNonVariableTerms(userInput1);
    }
    return 0;
}
