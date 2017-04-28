#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

        void convertTerms();
        void seperateTerms(string userInput);
        void setVariable(const char Variable);
    private:
        char checkString;
        string subString;
        vector<string> terms;
        vector<string> variableTerms;
        vecotr<string> nonVariableTerms;
        const int beginning = 0;
        int position1 = 0;
        char variable;
        int length;
        int variablePosition;
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
}

void operators::seperateTerms(string userInput)
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
    for (auto i = terms.begin(); i != terms.end(); ++i)
            std::cout << *i << ' ';
}

void operators::convertTerms()
{
       
}

int main()
{
    string userInput1, userInput2;
    char Variable;
    cout << "This program is designed to do the basic foil method\n"
         << "You begin by inputting a string of characters and the\n"
         << "program will output the result.\n";
    
    cout << "What varaiable will you use?";
    cin >> Variable;
    operators op;
    op.setVariable(Variable);
    cout << "Input 1: ";
    cin >> userInput1;
    cout << "Input 2: ";
    cin >> userInput2;
    op.seperateTerms(userInput1);
    return 0;
}
