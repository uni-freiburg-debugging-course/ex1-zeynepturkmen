#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

//after getting the said 'token's it does the operation and returns the result
int evaluator(const string theOperator, int operand1, int operand2) {
    if (theOperator == "+") {
        return operand1 + operand2;
    } else if (theOperator == "-") {
        return operand1 - operand2;
    } else if (theOperator == "*") {
        return operand1 * operand2;
    }
    throw invalid_argument("operator not recognized.");
}

//gets the line of expression as an input, parses it into 'token's
int parser_and_evaluator(const string input) {
    string word, theOperator;
    int operand1, operand2;
    
    stringstream ss(input);
    
    //TODO: I prob will have to change this part later on but yea
    //ignore all until the paranthesis
    ss.ignore(numeric_limits<streamsize>::max(), '(');

    //checking whether its in the correct format aka whether it says 'simplify'
    ss >> word;
    if (word != "simplify") {
        throw invalid_argument("unrecognized keyword.");
    }
    ss.ignore(numeric_limits<streamsize>::max(), '(');
    ss >> theOperator >> operand1 >> operand2;

    return evaluator(theOperator, operand1, operand2);
}

//its now a main function that takes an input argument
int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "invalid arguments, please enter the file name." << endl;
        return 1;
    }

    ifstream input(argv[1]);
    
    if (!input.is_open()) {
        cerr << "failed to open file " << argv[1] << endl;
        return 1;
    }

    string line;
    //read the document line by line
    while (getline(input, line)) {
        try {
            //parse and evaluate the line
            int result = parser_and_evaluator(line);
            //format the output for negative results
            ostringstream formatted;
            if (result < 0) {
              formatted << "(- " << -result << ")";
            } else {
              formatted << result;
            }
            cout << formatted.str() << endl;
        } catch (const exception& e) {
            cerr << "error occured: " << e.what() << endl;
        }
    }
    input.close();  //close the file and return
    return 0;
}
