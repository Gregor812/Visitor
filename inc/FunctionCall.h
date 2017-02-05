#pragma once

#include "Expression.h"
#include <string>
#include "Scope.h"
#include "Transformer.h"

struct FunctionCall : Expression {
	FunctionCall( std::string const &name, Expression const * arg );
	std::string const & name( ) const;
	Expression const * arg( ) const;
	double evaluate( Scope * sc ) const;
	Expression *transform( Transformer *tr ) const;
	~FunctionCall( );

private:
	std::string const name_;
	Expression const * arg_;
};
