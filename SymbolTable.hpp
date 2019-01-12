#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

/****************************************************************************/
/*                                 INCLUDE                                  */
/****************************************************************************/

#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;
using std::set;
#define N 18

/****************************************************************************/
/*                                EXCEPTIONS                                */
/****************************************************************************/

class VariableNotFoundException : public std::exception {};
class NameAlreadyExistsException : public std::exception {};
class FunctionNotFoundException : public std::exception {};
class StructNotFoundException : public std::exception {};
class InvalidTypeNameException : public std::exception {};
class RemovedBaseScopeException : public std::exception {};
class InvalidInputException : public std::exception {};
class NoScopesException : public std::exception {};
class TypeNotInScopeException : public std::exception {};
class InvalidInitiatorNameException : public std::exception {};
class InvalidRegNumberException : public std::exception {};



/****************************************************************************/
/*                              CLASS REG POOL                              */
/****************************************************************************/
class RegPool {
public:
	RegPool();
	~RegPool();
	int allocateReg();
	void freeReg(int reg);
	
private:
	bool regPool[N];
};

/****************************************************************************/
/*                                CLASS VAR                                 */
/****************************************************************************/
class Var {
public:
	// Constructors
	Var(const string& name, const string& type, int place = 0, int size = 1);
	Var(const Var& var);
	// Destructor
	~Var();
	// Functions
	const string& getName() const;
	const string& getType() const;
	int getPlace() const;
	int getSize() const;
	int getReg() const;
	void freeReg();
	void allocReg(int reg);
	vector<int> truelist;
	vector<int> falselist;
	vector<int> nextlist;
	string quad;
private:
	string _name;
	string _type;
	int _place;
	int _size;
	int _reg;
};

/****************************************************************************/
/*                           CLASS STRUCT_MEMBERS                           */
/****************************************************************************/

class StructMembers {
public:
	// Constructor
	StructMembers();
	StructMembers(const StructMembers& structMembers);
	// Destructor
	~StructMembers();
	// Functions
	void addMember(const Var& var);
	const vector<Var*>& getMembers() const;
	const vector<string>& getMembersNames() const;
	const vector<string>& getMembersTypes() const;
	const Var& find(const string& name) const;
	bool isNameUsed(const string& name) const;
	int size() const;
	int memSize() const;
	bool isTypeExists(const string& name) const;
	const Var& operator[](int i) const;
private:
	vector<Var*>* _members;
	vector<string>* _membersNames;
	vector<string>* _membersTypes;
};

/****************************************************************************/
/*                             CLASS STRUCT_NODE                            */
/****************************************************************************/

class StructNode {
public:
	// Constructors
	StructNode(const string& name);
	StructNode(
		const string& name,
		const StructMembers& structMems);
	// Destructor
	~StructNode();
	// Functions
	void addMember(const Var& var);
	const string& getName() const;
	const vector<string>& getMembersNames() const;
	const vector<string>& getMembersTypes() const;
	const Var& find(const string& name) const;
	int size() const;
	int memSize() const;
private:
	string _name;
	StructMembers* _structMems;
};

/****************************************************************************/
/*                             CLASS FUNC_PARAMS                            */
/****************************************************************************/

class FuncParams {
public:
	// Constructors
	FuncParams();
	FuncParams(const FuncParams& funcParams);
	// Destructor
	~FuncParams();
	// Functions
	void addParam(const Var& var);
	const vector<Var*>& getParameters() const;
	const vector<string>& getParamsNames() const;
	const vector<string>& getParamsTypes() const;
	const Var& find(const string& name) const;
	bool isNameUsed(const string& name) const;
	int size() const;
	const Var& operator[](int i) const;
private:
	vector<Var*>* _parameters;
	vector<string>* _paramsNames;
	vector<string>* _paramsTypes;
};

/****************************************************************************/
/*                             CLASS FUNC_NODE                              */
/****************************************************************************/

class FuncNode {
public:
	// Constructors
	FuncNode(
		const string& name,
		const string& retType);
	FuncNode(
		const string& name,
		const string& retType,
		const FuncParams& funcParams);
	// Destructor
	~FuncNode();
	// Functions
	void addParam(const Var& var);
	const string& getName()const;
	const string& getRetType()const;
	const vector<string>& getParamsNames() const;
	const vector<string>& getParamsTypes() const;
	const Var& find(const string& name)const;
	void print()const;
	int size() const;
	bool isRetTypeValid(const string& name) const;

private:
	string _name;
	string _retType;
	FuncParams* _funcParams;
};

/****************************************************************************/
/*                               CLASS SCOPE                                */
/****************************************************************************/

class Scope {
public:
	// Constructors
	Scope(
		const string& initiator,
		const string& retType = "void",
		int bottom = 0);
	Scope(
		const string types[],
		int size,
		const string& initiator,
		const string& retType = "void",
		int bottom = 0);
	Scope(
		const vector<string>& types, 
		const string& initiator,
		const string& retType = "void",
		int bottom = 0);
	// Destructor
	~Scope();
	// Functions
	const string& getRetType() const;
	const string& getInitiator() const;
	const vector<Var*>& getVariables()const;
	const Var& getVariable(const string& name)const;
	void addVariable(const Var& var, bool passed = false);
	void addVariable(const string& name, const string& type, int size, bool passed = false);
	const vector<string>& getTypes()const;
	void addType(const string& typeName);
	void printScope()const;
	bool isNameUsed(const string& name)const;
	bool isTypeExists(const string& name) const;
	bool isRetTypeValid(const string& name) const;
	bool isInitiatorValid(const string& name) const;
	int bottom() const;
	int stackSize() const;
private:
	string _initiator;
	string _retType;
	int _bottom;
	vector<Var*>* _variables;
	vector<string>* _types;
};

/****************************************************************************/
/*                            CLASS SYMBOL_TABLE                            */
/****************************************************************************/

class SymbolTable {
public:

	// Creates new SymbolTable with a base Scope.
	SymbolTable(
		const string& initiator,
		const string& retType = "void");

	// Creates new SymbolTable with a base Scope.
	SymbolTable(
		const string baseTypes[],
		int size,
		const string& initiator,
		const string& retType = "void");

	// Creates new SymbolTable with a base Scope.
	SymbolTable(
		const vector<string>& baseTypes,
		const string& initiator,
		const string& retType = "void");

	// Destroys the SymbolTable with all its content.
	~SymbolTable();

	// adds a new empty scope.
	void addScope(
		const string& initiator,
		const string& retType = "void");

	// adds a new scope with the given available type names.
	void addScope(
		const string paramsNames[],
		const string paramsTypes[],
		int size,
		const string& initiator,
		const string& retType = "void");

	// adds a new scope with the given available type names.
	void addScope(
		const vector<string>& paramsNames,
		const vector<string>& paramsTypes, 
		const string& initiator,
		const string& retType = "void");

	// Removes the current Scope.
	// If base scope is removed throws: RemovedBaseScopeException.
	void removeScope();

	// Prints the current Scope.
	// Note that this does not print the function header if the scope is a 
	// part of a function decleration (use printFunction for that).
	void printScope() const;

	//
	const vector<Scope*>& getScopes() const;

	// Returnsthe current Scope.
	const Scope& getScope() const;

	const string& getScopeInitiator() const;

	const string& getScopeRetType() const;

	// Adds the given type name to the current Scope.
	// If the given name exists in some context (either as a variable, a
	// struct or a function name) throws: NameAlreadyExistsException.
	void addType(const string& typeName);

	// Returns all the available types.
	const set<string>& getTypes() const;

	//
	void removeType(const string& typeName);

	// Adds the given variable to the current Scope.
	// If the given name exists in some context (either as a variable, a
	// struct or a function name) throws: NameAlreadyExistsException.
	// If the given type is invalid throws: InvalidTypeNameException.
	void addVar(const Var& var, bool passed = false);

	// Adds a new variable with the given name and type to the current Scope.
	// If the given name exists in some context (either as a variable, a
	// struct or a function name) throws: NameAlreadyExistsException.
	// If the given type is invalid throws: InvalidTypeNameException.
	void addVar(const string& name, const string& type, bool passed = false);
	
	// Returns a variable with the given name.
	// If the given name does not represents a variable throws:
	// VariableNotFoundException.
	const Var& findVar(const string& name) const;
	
	// Returns all the available variables.
	const set<string>& getVars() const;
	
	void removeVar(const string& name);

	//
	void addFunc(
		const string& name,
		const string& retType);

	//
	void addFunc(
		const string& name,
		const string& retType,
		const string paramsNames[],
		const string paramsTypes[],
		int size);

	// Adds a new function object with the given name, return type and 
	// function parameters, which are passed as two vectors, one for names and 
	// one for types.
	// If the given name exists in some context (either as a variable, a
	// struct or a function name) or there are two identical strings
	// in the given paramsNames throws: NameAlreadyExistsException.
	// If the given return type or one of the passed parameters types is 
	// invalid throws: InvalidTypeNameException.
	void addFunc(
		const string& name,
		const string& retType,
		const vector<string>& paramsNames,
		const vector<string>& paramsTypes);

	// Adds a new function object with the given name, return type, and optional
	// funcParams object.
	// If the given name exists in some context (either as a variable, a
	// struct or a function name) throws: NameAlreadyExistsException.
	// If the given return type is invalid throws: InvalidTypeNameException.
	void addFunc(
		const string& name,
		const string& retType,
		const FuncParams& funcParams);

	// Adds the given function object to the table.
	// if the function's name already exists in some context (either as a 
	// variable, a struct or a function name) throws: NameAlreadyExistsException.
	void addFunc(const FuncNode& funcNode);

	// Returns a function object with the given name.
	// If no such function exists throws: FunctionNotFoundException.
	const FuncNode& findFunc(const string& name) const;

	// Prints all function headers.
	void printFuncs() const;

	const vector<FuncNode*>& getFuncs() const;
	
	
	// Adds a new struct with the given name, and optional StructMembers
	// object, to the *current Scope*.
	// If the given name exists in some context (either as a variable, a
	// struct or a function name) throws: NameAlreadyExistsException.
	void addStruct(
		const string& name,
		const StructMembers& structMems
	);

	void addStruct(
		const string& name,
		const string names[],
		const string types[],
		int size
	);


	// Adds a new struct with the given name, return type and members,
	// which are passed as two vectors, one for names and one for types.
	// If the given name exists in some context (either as a variable, a
	// struct or a function name) or there are two identical names
	// in the given paramsNames throws: NameAlreadyExistsException.
	// If the given return type or one of the passed parameters types is 
	// invalid throws: InvalidTypeNameException.
	void addStruct(
		const string& name,
		const vector<string>& names,
		const vector<string>& types
	);


	// Adds the given struct with the given name, and optional StructMembers
	// object, to the *current Scope*.
	// if the struct's name already exists in some context (either as a variable,
	// a struct or a function name) throws: NameAlreadyExistsException.
	void addStruct(const StructNode& structNode);


	// Returns a struct object with the given name.
	// If no such struct exists throws: StructNotFoundException.
	const StructNode& findStruct(const string& name) const;
	

	const set<StructNode*>& getStructs() const;


	// Removes the struct object with the given name.
	// If no such struct exists throws: StructNotFoundException.
	// note that this automaticly happen when removeScope is called.
	void removeStruct(const string& name);

	// Prints the struct object with the given name.
	// If no such struct exists throws: StructNotFoundException.
	// note that this automaticly happen when printScope is called.
	void printStructs() const;
	
	// Return true if the given name is used in some context (either
	// as a variable, a struct or function name), or false otherwise.
	bool isNameUsed(const string& name) const;
	
	// Returns true if the given type name exists or false otherwise.
	bool isTypeExists(const string& name) const;
	
	int scopesSize() const;
	
private:

	int typeSize(const string& type) const;

	vector<Scope*>* _scopes;
	set<StructNode*>* _structs;
	vector<FuncNode*>* _functions;
	set<string>* _availableVariables;
	set<string>* _availableTypes;
};

string printTypeName(const string& name);

vector<string> printTypeNames(const vector<string>& names);

#endif  // SYMBOLTABLE_H_