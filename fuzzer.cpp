#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

string generate_expression(vector<string> & operators) {
    int idx = rand() % operators.size(); //pick a random operator
    
    //create 2 random integers between [0,999] to avoid overflow stuff
    int operand1 = rand() % 1000;
    int operand2 = rand() % 1000;

    string expression = "(simplify (" + operators[idx] + " " + to_string(operand1) + " " + to_string(operand2) + "))";
    return expression;
}

int main() {
    //create a vector of all supported operands
    vector<string> operators;
    operators.push_back("+");
    operators.push_back("-");
    operators.push_back("*");
    
    //create an output file to feed into both the z3 and my own parser
    ofstream outfile("input.txt");
    if (!outfile.is_open()) {
        cerr << "couldn't create the file for writing." << endl;
        return 1;
    }

    //create 10 random expressions and write them to the output file
    for (int i = 0; i < 100; ++i) {
        string expr = generate_expression(operators);
        outfile << expr << endl;
    }
    
    //close the file and return
    outfile.close();
    return 0;
}
