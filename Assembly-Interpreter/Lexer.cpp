#include "Lexer.h"

Lexer::Lexer(string input) : _input(input) {
    int i = 0;
    string token = "";

    for (i = 0; i < input.size(); i++) {
        if (input[i] == END_OF_LINE) {
            break;
        }
        else if (Utilities::isOperator(input[i])) {
            this -> _tokens.push(token);
            token = input[i];
            this -> _tokens.push(token);
            token = "";
        }
        else if(Utilities::isIgnored(input[i])) {
            if (token.size() > 0) {
                this->_tokens.push(token);
                token = "";
            }
        }
        else {
            token += input[i];
        }
    }

    if (token.size()) {
        this -> _tokens.push(token);
    }
}

queue<string> Lexer::getTokens()
{
    return this -> _tokens;
}

void Lexer::printLexer() {
    while (!_tokens.empty()) {
        cout << _tokens.front() << "#";
        _tokens.pop();
    }

    cout << std::endl;
}

