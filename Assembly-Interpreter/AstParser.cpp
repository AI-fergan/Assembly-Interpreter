#include "AstParser.h"

AstParser::AstParser(queue<string> tokens) {
	int opcode = 0;

	while (!tokens.empty()) {
		if (Utilities::isOpcode(tokens.front())) {
			AstNode* node = new OpcodesNode(Utilities::getOpcode(tokens.front()), tokens.front());
			this->_branches.push_back(node);
			opcode++;
		}
		else if (Utilities::isOperator(tokens.front()[0])) {
			AstNode* node = new OperatorsNode(Utilities::getOperator(tokens.front()[0]), tokens.front());
			this->_branches[opcode - 1]->add(node);
		}
		else {
			AstNode* node = new OperatorsNode(Operators::none, tokens.front());
			this->_branches[opcode - 1]->add(node);
		}

		tokens.pop();
	}
}

std::vector<AstNode*>AstParser::getBranches() {
	return this->_branches;
}