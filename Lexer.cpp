#include "Lexer.h"

/*
* This c'tor gets the user input and split it into tokens and store them in strings queue.
* Input:
* input - the user commands line.
*/
Lexer::Lexer(string input) : _input(input) {
    int i = 0;
    string token = "";

    //loop over all the user chars input
    for (i = 0; i < input.size(); i++) {
        //check if the line ended by the "End Of Line" char.
        if (input[i] == END_OF_LINE) {
            return;
        }
        //check if the char is an operator
        else if (Utilities::isOperator(input[i])) {
            //checks if there is already token that saved and push it
            if (token.size() > 0) {
                this->_tokens.push(token);
            }

            //push the operator token
            token = input[i];
            this -> _tokens.push(token);
            token = "";
        }
        //check if the char doest have special meaning to the lexer.
        else if(Utilities::isIgnored(input[i])) {
            //checks if there is already token that saved and push it
            if (token.size() > 0) {
                this->_tokens.push(token);
                token = "";
            }
        }
        else {
            //add another char to the current token
            token += input[i];
        }
    }

    //checks if there is already token that saved and push it
    if (token.size()) {
        this -> _tokens.push(token);
    }
}

/*
* This function return the strings queue of th Tokens.
* Output: queue of all the Tokens.
*/
queue<string> Lexer::getTokens() {
    return this -> _tokens;
}
