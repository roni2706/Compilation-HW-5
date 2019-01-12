#ifndef __PARSER_H
#define __PARSER_H


#include <string>
#include <iostream>
#include <stdlib.h>
#include "SymbolTable.hpp"

using std::cout;
using std::endl;
using std::string;

typedef union {
	int num;
	string* str;
	Var* var;
	StructMembers* structMembers;
	StructNode* structNode;
	FuncParams* funcParams;
	FuncNode* funcNode;
}u;
# define YYSTYPE u
#endif
