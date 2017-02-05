#pragma once

#include "Expression.h"
#include <string>
#include "Scope.h"
#include "Transformer.h"

struct Variable : Expression {
	Variable( std::string const &name );
	std::string const &name( ) const;
	double evaluate( Scope * sc ) const;
	Expression *transform( Transformer *tr ) const;

private:
	std::string const name_;
};