/****************************************************************************/
/*                                 INCLUDE                                  */
/****************************************************************************/

#include "SymbolTable.hpp"
#include "output.hpp"
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;


#define DEBUG(x) do { \
  if (debugging_enabled) { out << x << endl; } \
} while (0)

/****************************************************************************/
/*                              CLASS REG POOL                              */
/****************************************************************************/

RegPool::RegPool() : regPool(new vector<bool*>) {
	reallocPool();
}

RegPool::~RegPool() {
	while ( !regPool->empty() ) {
		delete(regPool->back());
	}
	delete(regPool);
}

int RegPool::allocateReg() {
	bool* currentRegPool = (regPool->back()); 
	for( int i = 0 ; i < N ; i++ ) {
		if ( !currentRegPool[i] ) {
			currentRegPool[i] = true;
			return i+8;
		}
	}		
	throw InvalidRegNumberException();
}

void RegPool::freeReg(int reg) {
	if ( reg < 8 || reg > 25 ) {
		throw InvalidRegNumberException();
	}
	bool* currentRegPool = (regPool->back()); 
	(currentRegPool)[reg-8] = false;
}

vector<int> RegPool::usedRegs() {
	bool* currentRegPool = (regPool->back()); 
	vector<int> used;
	for( int i = 0 ; i < N ; i++ ) {
		if ( currentRegPool[i] ) {
			used.push_back(i+8);
		}
	}		
	return used;
}

void RegPool::reallocPool() {
	regPool->push_back(new bool[N]);
	for( int i = 0 ; i < N ; i++ ) {
		(regPool->back())[i] = false;
	}	
}

void RegPool::deallocPool() {
	delete(regPool->back());
	regPool->pop_back();
}

/****************************************************************************/
/*                              BACKPATCHABLE                               */
/****************************************************************************/

// Constructors
Backpatchable::Backpatchable() : _reg(0) {}
// Destructor
Backpatchable::~Backpatchable() {}
// Functions
vector<int>& Backpatchable::truelist() {
	return _truelist;
}

vector<int>& Backpatchable::falselist() {
	return _falselist;
}

vector<int>& Backpatchable::nextlist(){
	return _nextlist;
}

vector<int>& Backpatchable::returnlist(){
	return _returnlist;
}

vector<int>& Backpatchable::breaklist(){
	return _breaklist;
}

vector<int>& Backpatchable::continuelist(){
	return _continuelist;
}

string& Backpatchable::quad(){
	return _quad;
}
	
int Backpatchable::getReg() const {
	return _reg;
}

void Backpatchable::freeReg() {
	_reg = 0;
}

void Backpatchable::allocReg(int reg) {
	_reg = reg;
}

/****************************************************************************/
/*                                CLASS VAR                                 */
/****************************************************************************/

Var::Var(const string& name, const string& type, int place, int size) :
	_name(name), _type(type), _place(place), _size(size), _reg(0)  {}

Var::Var(const Var& var) :
	_name(var.getName()),
	_type(var.getType()),
	_place(var.getPlace()),
	_size(var.getSize()),
	_reg(var.getReg()) {}

Var::~Var() {}

const string& Var::getName() const {
	return _name;
}

const string& Var::getType() const {
	return _type;
}

int Var::getPlace() const {
	return _place;
}

int Var::getSize() const {
	return _size;
}

/****************************************************************************/
/*                           CLASS STRUCT_MEMBERS                           */
/****************************************************************************/

StructMembers::StructMembers() : 
		_members(new vector<Var*>()),
		_membersNames(new vector<string>()),
		_membersTypes(new vector<string>()){}

StructMembers::StructMembers(const StructMembers& structMembers) :
		_members(new vector<Var*>()),
		_membersNames(new vector<string>()),
		_membersTypes(new vector<string>()) {
	for (int i = 0; i < structMembers.size(); i++) {
		addMember(structMembers[i]);
	}
}

StructMembers::~StructMembers() {
	for (int i = 0; i < size(); i++) {
		delete ((*_members)[i]);
	}
	delete (_members);
	delete (_membersNames);
	delete (_membersTypes);
}

void StructMembers::addMember(const Var& var) {
	if (isNameUsed(var.getName())) {
		throw NameAlreadyExistsException();
	}
	if (!isTypeExists(var.getType())) {
		throw InvalidTypeNameException();
	}
	_members->push_back(
		new Var(
			var.getName(),
			var.getType(),
			memSize(),
			var.getSize()
		)
	);
	_membersNames->push_back(var.getName());
	_membersTypes->push_back(var.getType());
}

const vector<Var*>& StructMembers::getMembers() const {
	return *_members;
}

const vector<string>& StructMembers::getMembersNames() const {
	return *_membersNames;
}

const vector<string>& StructMembers::getMembersTypes() const {
	return *_membersTypes;
}

const Var& StructMembers::find(const string& name) const {
	for (int i = 0; i < size(); i++) {
		if (getMembers()[i]->getName() == name) {
			return *(getMembers()[i]);
		}
	}
	throw VariableNotFoundException();
}

bool StructMembers::isNameUsed(const string& name) const {
	const vector<string>::iterator start = _membersNames->begin();
	const vector<string>::iterator end = _membersNames->end();
	if (std::find(start, end, name) == end) {
		return false;
	}
	return true;
}

int StructMembers::size() const {
	return getMembers().size();
}

int StructMembers::memSize() const {
	int size = 0;
	for (int i = 0; i < this->size(); i++) {
		size += getMembers()[i]->getSize();
	}
	return size;
}

bool StructMembers::isTypeExists(const string& name) const {
	if (name != "int" && name != "bool" && name != "byte") {
		return false;
	}
	return true;
}

const Var& StructMembers::operator[](int i) const {
	return *(getMembers()[i]);
}

/****************************************************************************/
/*                             CLASS STRUCT_NODE                            */
/****************************************************************************/

StructNode::StructNode(const string& name) :
		_name(name), _structMems(new StructMembers()){}

StructNode::StructNode(const string& name, const StructMembers& structMems) :
		_name(name), _structMems(new StructMembers(structMems)){}

StructNode::~StructNode() {
	delete (_structMems);
}

void StructNode::addMember(const Var& var) {
	_structMems->addMember(var);
}

const string& StructNode::getName() const {
	return _name;
}

const vector<string>& StructNode::getMembersNames() const {
	return _structMems->getMembersNames();
}

const vector<string>& StructNode::getMembersTypes() const {
	return _structMems->getMembersTypes();
}

const Var& StructNode::find(const string& name) const {
	return _structMems->find(name);
}

int StructNode::size() const {
	return _structMems->size();
}

int StructNode::memSize() const {
	return _structMems->memSize();
}

const Var& StructNode::operator[](int i) const {
	return (*_structMems)[i];
}


/****************************************************************************/
/*                             CLASS FUNC_PARAMS                            */
/****************************************************************************/

FuncParams::FuncParams() :
		_parameters(new vector<Var*>()),
		_paramsNames(new vector<string>()),
		_paramsTypes(new vector<string>()) {
}

FuncParams::FuncParams(const FuncParams& funcParams) :
		_parameters(new vector<Var*>()),
		_paramsNames(new vector<string>()),
		_paramsTypes(new vector<string>()) {
	for (int i = 0; i < funcParams.size(); i++) {
		addParam(funcParams[i]);
	}
}

FuncParams::~FuncParams() {
	for (int i = 0; i < size(); i++) {
		delete ((*_parameters)[i]);
	}
	delete (_parameters);
	delete (_paramsNames);
	delete (_paramsTypes);
}

void FuncParams::addParam(const Var& var) {
	if (var.getName() != "__temp") {
		if (isNameUsed(var.getName())) {
			throw NameAlreadyExistsException();
		}
	}
	_parameters->push_back(new Var(var));
	_paramsNames->push_back(var.getName());
	_paramsTypes->push_back(var.getType());
}

const vector<Var*>& FuncParams::getParameters() const {
	return *_parameters;
}

const vector<string>& FuncParams::getParamsNames() const {
	return *_paramsNames;
}

const vector<string>& FuncParams::getParamsTypes() const {
	return *_paramsTypes;
}

const Var& FuncParams::find(const string& name) const {
	for (int i = 0; i < size(); i++) {
		if (getParameters()[i]->getName() == name) {
			return *(getParameters()[i]);
		}
	}
	throw VariableNotFoundException();
}

bool FuncParams::isNameUsed(const string& name) const {
	const vector<string>::iterator start = _paramsNames->begin();
	const vector<string>::iterator end = _paramsNames->end();
	if (std::find(start, end, name) == end) {
		return false;
	}
	return true;
}

int FuncParams::size() const {
	return _parameters->size();
}

int FuncParams::memSize() const {
	int size = 0;
	for (int i = 0; i < this->size(); i++) {
		size += getParameters()[i]->getSize();
	}
	return size; 
}

const Var& FuncParams::operator[](int i) const {
	return *(getParameters()[i]);
}

/****************************************************************************/
/*                             CLASS FUNC_NODE                              */
/****************************************************************************/
FuncNode::FuncNode(
	const string& name,
	const string& retType) :
	_name(name), _retType(retType), _funcParams(new FuncParams()) {
	if (!isRetTypeValid(retType)) {
		throw InvalidTypeNameException();
	}
}

FuncNode::FuncNode(
	const string& name,
	const string& retType,
	const FuncParams& funcParams) :
	_name(name), _retType(retType), _funcParams(new FuncParams(funcParams)) {
	if (!isRetTypeValid(retType)) {
		throw InvalidTypeNameException();
	}
}

FuncNode::~FuncNode() {
	delete (_funcParams);
}

void FuncNode::addParam(const Var& var) {
	_funcParams->addParam(var);
}

const string& FuncNode::getName() const {
	return _name;
}

const string& FuncNode::getRetType() const {
	return _retType;
}

const vector<string>& FuncNode::getParamsNames() const {
	return _funcParams->getParamsNames();
}

const vector<string>& FuncNode::getParamsTypes() const {
	return _funcParams->getParamsTypes();
}

const Var& FuncNode::find(const string& name) const {
	return _funcParams->find(name);
}

void FuncNode::print() const {
	cout << "TODO: add implementation" << endl;
	// TODO: add implementation
}

int FuncNode::size() const {
	return _funcParams->size();
}

int FuncNode::memSize() const {
	return _funcParams->memSize();
}

bool FuncNode::isRetTypeValid(const string& name) const {
	if (name != "int" && name != "bool" && name != "byte" && name != "void") {
		return false;
	}
	return true;
}

/****************************************************************************/
/*                               CLASS SCOPE                                */
/****************************************************************************/

Scope::Scope(
	const string& initiator,
	const string& retType,
	int bottom) :
		_initiator(initiator),
		_retType(retType),
		_bottom(bottom),
		_variables(new vector<Var*>()), 
		_types(new vector<string>()) {
	if (!isRetTypeValid(retType)) {
		throw InvalidTypeNameException();
	}
	if (!isInitiatorValid(initiator)) {
		throw InvalidInitiatorNameException();
	}
}

Scope::Scope(
	const string types[], 
	int size, 
	const string& initiator,
	const string& retType,
	int bottom) :
		_initiator(initiator),
		_retType(retType),
		_bottom(bottom),
		_variables(new vector<Var*>()), 
		_types(new vector<string>()) {
	if (!isRetTypeValid(retType)) {
		throw InvalidTypeNameException();
	}
	if (!isInitiatorValid(initiator)) {
		throw InvalidInitiatorNameException();
	}
	for (int i = 0; i < size; i++) {
		addType(types[i]);
	}
}

Scope::Scope(
	const vector<string>& types,
	const string& initiator,
	const string& retType,
	int bottom) :
		_initiator(initiator),
		_retType(retType),
		_bottom(bottom),
		_variables(new vector<Var*>()), 
		_types(new vector<string>()) {
	if (!isRetTypeValid(retType)) {
		throw InvalidTypeNameException();
	}
	if (!isInitiatorValid(initiator)) {
		throw InvalidInitiatorNameException();
	}
	for (int i = 0; i < types.size(); i++) {
		addType(types[i]);
	}
}

Scope::~Scope() {
	int size = getVariables().size();
	for (int i = 0; i < size; i++) {
		delete ((*_variables)[i]);
	}
	delete (_variables);
	delete (_types);
}
const string& Scope::getInitiator() const {
	return _initiator;
}

const string& Scope::getRetType() const {
	return _retType;
}

const vector<Var*>& Scope::getVariables() const {
	return *_variables;
}

const Var& Scope::getVariable(const string& name) const {
	for (int i = 0; i < getVariables().size(); i++) {
		if (getVariables()[i]->getName() == name) {
			return (*(getVariables()[i]));
		}
	}
	throw VariableNotFoundException();
}

void Scope::addVariable(const string& name, const string& type, int size, bool passed) {
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	if (passed) {
		_variables->push_back(new Var(name, type, bottom()-size, size));
		_bottom -= size;
	}
	else {
		_variables->push_back(new Var(name, type, bottom() + stackSize(), size));
	}
}

void Scope::addVariable(const Var& var, bool passed) {
	addVariable(var.getName(), var.getType(), var.getSize(), passed);
}

const vector<string>& Scope::getTypes() const {
	return *_types;
}

void Scope::addType(const string& typeName) {
	if (isNameUsed(typeName)) {
		throw NameAlreadyExistsException();
	}
	_types->push_back(typeName);
}

void Scope::printScope() const {
	output::endScope(); 
	for (int i = 0; i < getVariables().size(); i++) {
			const Var* var = getVariables()[i];
			output::printID(var->getName(), var->getPlace() , printTypeName(var->getType()));
	}
}

bool Scope::isNameUsed(const string& name) const {
	for (int i = 0; i < getVariables().size(); i++) {
		if (getVariables()[i]->getName() == name) {
			return true;
		}
	}
	return isTypeExists(name);
}

bool Scope::isTypeExists(const string& name) const {
	for (int i = 0; i < getTypes().size(); i++) {
		if (getTypes()[i] == name) {
			return true;
		}
	}
	return false;
}

bool Scope::isRetTypeValid(const string& name) const {
	if (name != "int" && name != "bool" && name != "byte" && name != "void") {
		return false;
	}
	return true;
}

bool Scope::isInitiatorValid(const string& name) const {
	if (name != "function" && name != "if" && name != "else" && name != "while" && name != "block") {
		return false;
	}
	return true;
}

int Scope::bottom() const {
	return _bottom;
}

int Scope::stackSize() const {
	int size = 0;
	for (int i = 0; i < getVariables().size(); i++) {
		size += getVariables()[i]->getSize();
	}
	return size;
}

/****************************************************************************/
/*                            CLASS SYMBOL_TABLE                            */
/****************************************************************************/

// Creates new SymbolTable with a base Scope.
SymbolTable::SymbolTable(
	const string& initiator,
	const string& retType) :
		_scopes(new vector<Scope*>()),
		_structs(new set<StructNode*>()),
		_functions(new vector<FuncNode*>()),
		_availableVariables(new set<string>()),
		_availableTypes(new set<string>()) {
	_scopes->push_back(new Scope(initiator,retType));
}

// Creates new SymbolTable with a base Scope.
SymbolTable::SymbolTable(
	const string baseTypes[], 
	int size, 
	const string& initiator,
	const string& retType) :
		_scopes(new vector<Scope*>()),
		_structs(new set<StructNode*>()),
		_functions(new vector<FuncNode*>()),
		_availableVariables(new set<string>()),
		_availableTypes(new set<string>()) {
	_scopes->push_back(new Scope(initiator, retType));
	for (int i = 0; i < size; i++) {
		addType(baseTypes[i]);
		_availableTypes->insert(baseTypes[i]);
	}
}

// Creates new SymbolTable with a base Scope.
SymbolTable::SymbolTable(
	const vector<string>& baseTypes, 
	const string& initiator, 
	const string& retType) :
		_scopes(new vector<Scope*>()),
		_structs(new set<StructNode*>()),
		_functions(new vector<FuncNode*>()),
		_availableVariables(new set<string>()),
		_availableTypes(new set<string>()) {
	_scopes->push_back(new Scope(initiator, retType));
	for (int i = 0; i < baseTypes.size(); i++) {
		addType(baseTypes[i]);
		_availableTypes->insert(baseTypes[i]);
	}
}

// Destroys the SymbolTable with all its content.
SymbolTable::~SymbolTable() {
	for (int i = 0; i < scopesSize(); i++) {
		delete ((*_scopes)[i]);
	}
	delete (_scopes);
	for (set<StructNode*>::iterator it = _structs->begin();
		it != _structs->end(); ++it) {
		delete (*it);
	}
	delete (_structs);
	for (int i = 0; i < getFuncs().size(); i++) {
		delete ((*_functions)[i]);
	}
	delete (_functions);
	delete (_availableVariables);
	delete (_availableTypes);
}

// adds a new scope with the given available type names.
void SymbolTable::addScope(
	const string& initiator, 
	const string& retType) {
	int newBottom = _scopes->back()->bottom() + _scopes->back()->stackSize();
	_scopes->push_back(new Scope(initiator,retType, newBottom));
}

// adds a new scope with the given available type names.
void SymbolTable::addScope(
	const string paramsNames[],
	const string paramsTypes[],
	int size,
	const string& initiator,
	const string& retType) {
	addScope(initiator,retType);
	for (int i = 0; i < size; i++) {
		addVar(paramsNames[i], paramsTypes[i], true);
	}
}

// adds a new scope with the given available type names.
void SymbolTable::addScope(
	const vector<string>& paramsNames,
	const vector<string>& paramsTypes,
	const string& initiator, 
	const string& retType) {
	addScope(initiator,retType);
	for (int i = 0; i < paramsNames.size(); i++) {
		addVar(paramsNames[i], paramsTypes[i], true);
	}
}

// Removes the current Scope.
// If base scope is removed throws: RemovedBaseScopeException.
void SymbolTable::removeScope() {
	if (!scopesSize()) {
		throw NoScopesException();
	}
	const vector<string>& types = getScope().getTypes();
	for (int i = 0; i < types.size(); i++) {
		try {
			removeStruct(types[i]);
		}
		catch (StructNotFoundException e) {
			// All is well
		}
	}
	const vector<Var*>& vars = getScope().getVariables();
	for (int i = 0; i < vars.size(); i++) {
		removeVar(vars[i]->getName());
	}
	delete (_scopes->back());
	_scopes->pop_back();
	if (_scopes->empty()) {
		throw RemovedBaseScopeException();
	}
}

// Prints the current Scope.
// Note that this does not print the function header if the scope is a 
// part of a function decleration (use printFunction for that).
void SymbolTable::printScope() const {
	getScope().printScope();
}

const vector< Scope*>& SymbolTable::getScopes() const {
	return *_scopes;
}

// Returns the current Scope.
const Scope& SymbolTable::getScope() const {
	return *(_scopes->back());
}

const string& SymbolTable::getScopeInitiator() const {
	return getScope().getInitiator();
}

const string& SymbolTable::getScopeRetType() const {
	return getScope().getRetType();
}

// Adds the given type name to the current Scope.
// If the given name exists in some context (either as a variable, a
// struct or a function name) throws: NameAlreadyExistsException.
void SymbolTable::addType(const string& typeName) {
	if (isNameUsed(typeName)) {
		throw NameAlreadyExistsException();
	}
	_scopes->back()->addType(typeName);
	_availableTypes->insert(typeName);
}

// Returns all the available types.
const set<string>& SymbolTable::getTypes() const {
	return *_availableTypes;
}

void SymbolTable::removeType(const string& typeName) {
	if (_availableTypes->find(typeName) == _availableTypes->end()) {
		throw InvalidTypeNameException();
	}
	_availableTypes->erase(typeName);
}

// Adds the given variable to the current Scope.
// If the given name exists in some context (either as a variable, a
// struct or a function name) throws: NameAlreadyExistsException.
// If the given type is invalid throws: InvalidTypeNameException.
void SymbolTable::addVar(const Var& var, bool passed){
	addVar(var.getName(), var.getType(), passed);
}

// Adds a new variable with the given name and type to the current Scope.
// If the given name exists in some context (either as a variable, a
// struct or a function name) throws: NameAlreadyExistsException.
// If the given type is invalid throws: InvalidTypeNameException.
void SymbolTable::addVar(const string& name, const string& type, bool passed) {
	if (name == "") {
		throw InvalidInputException();
	}
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	if (!isTypeExists(type)){
		throw InvalidTypeNameException();
	}
	_scopes->back()->addVariable(name, type, typeSize(type), passed);
	_availableVariables->insert(name);
}


// Returns a variable with the given name.
// If the given name does not represents a variable throws:
// VariableNotFoundException.
const Var& SymbolTable::findVar(const string& name) const {
	if (_availableVariables->find(name) == _availableVariables->end()) {
		throw VariableNotFoundException();
	}
	for (int i = 0; i < scopesSize(); i++) {
		const vector<Var*>& scopeVariables = getScopes()[i]->getVariables();
		for (int j = 0; j < scopeVariables.size(); j++) {
			if (scopeVariables[j]->getName() == name) {
				return *(scopeVariables[j]);
			}
		}
	}
	throw VariableNotFoundException();
}


// Returns all the available variables.
const set<string>& SymbolTable::getVars() const {
	return *_availableVariables;
}


void SymbolTable::removeVar(const string& name) {
	_availableVariables->erase(name);
}


void SymbolTable::addFunc(
	const string& name,
	const string& retType) {
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	_functions->push_back(new FuncNode(name, retType));
}


void SymbolTable::addFunc(
	const string& name,
	const string& retType,
	const string paramsNames[],
	const string paramsTypes[],
	int size) {
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	FuncNode* func;
	try {
		func = new FuncNode(name, retType);
		for (int i = 0; i < size; i++) {
			func->addParam(Var(paramsNames[i], paramsTypes[i]));
		}
		_functions->push_back(func);
	}
	catch (std::exception e) {
		delete (func);
		throw;
	}
}


// Adds a new function object with the given name, return type and 
// function parameters, which are passed as two vectors, one for names and 
// one for types.
// If the given name exists in some context (either as a variable, a
// struct or a function name) or there are two identical strings
// in the given paramsNames throws: NameAlreadyExistsException.
// If the given return type or one of the passed parameters types is 
// invalid throws: InvalidTypeNameException.
void SymbolTable::addFunc(
	const string& name,
	const string& retType,
	const vector<string>& paramsNames,
	const vector<string>& paramsTypes) {
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	FuncNode* func;
	try {
		func = new FuncNode(name, retType);
		for (int i = 0; i < paramsNames.size(); i++) {
			func->addParam(Var(paramsNames[i], paramsTypes[i]));
		}
		_functions->push_back(func);
	}
	catch (std::exception e) {
		delete (func);
		throw;
	}
}


// Adds a new function object with the given name, return type, and optional
// funcParams object.
// If the given name exists in some context (either as a variable, a
// struct or a function name) throws: NameAlreadyExistsException.
// If the given return type is invalid throws: InvalidTypeNameException.
void SymbolTable::addFunc(
	const string& name,
	const string& retType,
	const FuncParams& funcParams) {
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	FuncNode* func;
	try {
		func = new FuncNode(name, retType);
		for (int i = 0; i < funcParams.size(); i++) {
			Var var(
				funcParams[i].getName(), 
				funcParams[i].getType(),
				funcParams[i].getPlace(),
				typeSize(funcParams[i].getType())
			);
			func->addParam(var);
		}
		_functions->push_back(func);
	}
	catch (std::exception e) {
		delete (func);
		throw;
	}
}


// Adds the given function object to the table.
// if the function's name already exists in some context (either as a 
// variable, a struct or a function name) throws: NameAlreadyExistsException.
void SymbolTable::addFunc(const FuncNode& funcNode) {
	addFunc(
		funcNode.getName(),
		funcNode.getRetType(),
		funcNode.getParamsNames(),
		funcNode.getParamsTypes());	
}


// Returns a function object with the given name.
// If no such function exists throws: FunctionNotFoundException.
const FuncNode& SymbolTable::findFunc(const string& name) const {
	for (int i = 0; i < getFuncs().size(); i++) {
		if ((getFuncs()[i])->getName() == name) {
			return *(getFuncs()[i]);
		}
	}
	throw FunctionNotFoundException();
}


// Prints all function headers.
void SymbolTable::printFuncs() const {
	for (int i = 0; i < getFuncs().size(); i++) {
		const FuncNode* func = getFuncs()[i];
		const string& retType = printTypeName(func->getRetType());
		vector<string> paramTypes;
		output::printID(func->getName(), 0,
			output::makeFunctionType(retType, printTypeNames(func->getParamsTypes())));
	}
}


const vector<FuncNode*>& SymbolTable::getFuncs() const {
	return *_functions;
}


// Adds a new struct with the given name, and optional StructMembers
// object, to the *current Scope*.
// If the given name exists in some context (either as a variable, a
// struct or a function name) throws: NameAlreadyExistsException.
void SymbolTable::addStruct(
	const string& name,
	const StructMembers& structMems) {
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	addType(name);
	_structs->insert(new StructNode(name, structMems));
}

void SymbolTable::addStruct(
	const string& name,
	const string names[],
	const string types[],
	int size) {
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	if (!names || !types) {
		throw InvalidInputException();
	}
	if (!size) {
		throw InvalidInputException();
	}
	addType(name);
	StructNode* structNode;
	try {
		structNode = new StructNode(name);
		for (int i = 0; i < size; i++) {
			structNode->addMember(Var(names[i], types[i]));
		}
		_structs->insert(structNode);
	} 
	catch (std::exception e) {
		delete (structNode);
		throw;
	}
}

// Adds a new struct with the given name, return type and members,
// which are passed as two vectors, one for names and one for types.
// If the given name exists in some context (either as a variable, a
// struct or a function name) or there are two identical names
// in the given paramsNames throws: NameAlreadyExistsException.
// If the given return type or one of the passed parameters types is 
// invalid throws: invalidTypeNameException.
void SymbolTable::addStruct(
	const string& name,
	const vector<string>& names,
	const vector<string>& types) {
	if (isNameUsed(name)) {
		throw NameAlreadyExistsException();
	}
	addType(name);
	StructNode* structNode;
	try {
		structNode = new StructNode(name);
		for (int i = 0; i < names.size(); i++) {
			structNode->addMember(Var(names[i], types[i]));
		}
		_structs->insert(structNode);
	}
	catch (std::exception e) {
		delete (structNode);
		throw;
	}
}

// Returns a struct object with the given name.
// If no such struct exists throws: StructNotFoundException.
const StructNode& SymbolTable::findStruct(const string& name) const {
	set<StructNode*>::iterator it;
	set<StructNode*>::iterator start = _structs->begin();
	set<StructNode*>::iterator end = _structs->end();
	for (it = start; it != end; ++it) {
		if ((*it)->getName() == name) {
			return **it;
		}
	}
	throw StructNotFoundException();
}

const set<StructNode*>& SymbolTable::getStructs() const {
	return *_structs;
}

// Removes the struct object with the given name.
// If no such struct exists throws: StructNotFoundException.
// note that this automaticly happen when removeScope is called.
void SymbolTable::removeStruct(const string& name) {
	set<StructNode*>::iterator it;
	set<StructNode*>::iterator start = _structs->begin();
	set<StructNode*>::iterator end = _structs->end();
	for (it = start; it != end; ++it) {
		if ((*it)->getName() == name) {
			_structs->erase(*it);
			delete (*it);
			removeType(name);
			return;
		}
	}
	throw StructNotFoundException();
}

// Prints the struct object with the given name.
// If no such struct exists throws: StructNotFoundException.
// note that this automaticly happen when printScope is called.
void SymbolTable::printStructs() const {
	const Scope& scope = getScope();
	for (int i = 0; i < scope.getTypes().size(); i++) {
		const string& type = scope.getTypes()[i];
		if (type != "int" && type != "byte" && type != "bool" && type != "string") {
			try {
				const StructNode& strct = findStruct(scope.getTypes()[i]);
				output::printStructType(
					strct.getName(),
					printTypeNames(strct.getMembersTypes()),
					strct.getMembersNames());
			}
			catch (StructNotFoundException e) {
				throw StructNotFoundException();
			}
		}
	}
}

// Returns true if the given name is used in some context (either
// as a variable, a struct or function name), or false otherwise.
bool SymbolTable::isNameUsed(const string& name) const {
	try {
		findVar(name);
		return true;
	}
	catch (VariableNotFoundException e) {
		// is not a variable
	}
	try {
		findFunc(name);
		return true;
	}
	catch (FunctionNotFoundException e) {
		// is not a function
	}
	try {
		findStruct(name);
		return true;
	}
	catch (StructNotFoundException e) {
		// is not a struct
	}
	return false;
}

// Returns true if the given type name exists or false otherwise.
bool SymbolTable::isTypeExists(const string& name) const {
	if (_availableTypes->find(name) == _availableTypes->end()) {
		return false;
	}
	return true;
}

int SymbolTable::scopesSize() const {
	return _scopes->size();
}

int SymbolTable::typeSize(const string& type) const {
	if (type == "int") {
		return 4;
	}
	if (type == "byte") {
		return 4;
	}
	if (type == "bool") {
		return 4;
	}
	return findStruct(type).memSize();
}

string printTypeName(const string& name) {
	if (name == "int") {
		return "INT";
	}
	if (name == "byte") {
		return "BYTE";
	}
	if (name == "bool") {
		return "BOOL";
	}
	if (name == "string") {
		return "STRING";
	}
	if (name == "void") {
		return "VOID";
	}
	return "struct " + name;
}

vector<string> printTypeNames(const vector<string>& names) {
	vector<string> retVector;
	for (int i = 0; i < names.size(); i++) {
		retVector.push_back(printTypeName(names[i]));
	}
	return retVector;
}
