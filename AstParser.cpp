#include "AstParser.h"

/*
* This c'tor get queue of tokens and parse it by the interpreter rules and creare Ast.
* Input:
* tokens - the queue of tokens to parse.
*/
AstParser::AstParser(queue<string> tokens) {
	int param = 0;
	int i = 0;
	AstNode* tmp = nullptr;

	//check if the first token is opcode
	if (Utilities::isOpcode(tokens.front())) {
		AstNode* node = new AstNode(tokens.front(), OPCODE);
		this->_branches.push_back(node);
		tokens.pop();
	}
	else {
		//if the first token isnt opcode the line is not valid and the parser throw execption
		throw SyntaxError("Parser ERROR - Opcode not found");
	}
	
	//loop over all the tokens
	while (!tokens.empty()) {
		//check if the token is operator
		if (Utilities::isOperator(tokens.front()[0])) {
			AstNode* node = new AstNode(tokens.front(), OPERATOR);
			this->_branches[0]->add(node);
		}
		//if it isnt oprtator it continue the flow to see where the token should be save, 
		//and what is the type of the token
		else {
			AstNode* node = new AstNode(tokens.front(), TOKEN);
			//checks if the token isnt the first token in the line after the opcode
			if (this->_branches[0]->getBranches().size() > 0) {
				//check if there is operator in the opcode branches
				if (Utilities::isOperator(this->_branches[0]->getBranches()[0]->getData()[0])) {					
					//check if there is any token that saved to later
					if (tmp) {
						//push the saved token to the first operator in the first opcode branches
						this->_branches[0]->getBranches()[0]->add(tmp);
						tmp = nullptr;
					}
					//push the seconed token to the first operator in the first opcode branches
					this->_branches[0]->getBranches()[0]->add(node);
					param = 0;
				}
				else {
					throw SyntaxError("Parser ERROR - Operator not found");
				}
			}
			//if the token is the first in the line after the opcode without any operator 
			//the parser save it to check what to do with it later.
			else {
				//check if it isnt the first non type token in the line
				if (param != 0) {
					throw SyntaxError("Parser ERROR - Operator not found");
				}

				//save the token
				tmp = node;
				param++;
			}
		}

		tokens.pop();
	}

	//check if there is token that unused
	if (this->_branches[0]->getBranches().size() == 0 && tmp)
		this->_branches[0]->add(tmp);
}

/*
* This function return the branches of Ast node in vector.
* Output: Vector of the branches of the Ast Node.
*/
std::vector<AstNode*>AstParser::getBranches() {
	return this->_branches;
}
