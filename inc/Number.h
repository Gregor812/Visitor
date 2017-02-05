#pragma once

#include "Expression.h"
#include "Scope.h"
#include "Transformer.h"

struct Number : Expression {
	Number( );
	Number( double value );
	double value( ) const;
	double evaluate( Scope * sc ) const;
	Expression * transform( Transformer * tr ) const;

private:
	double value_;
};

Number operator-( Number const & n );
Number operator-( Number const & n1, Number const & n2 );
Number operator+( Number const & n1, Number const & n2 );
Number operator-( Number const & n1, double d );
Number operator-( double d, Number const & n1 );
Number operator+( Number const & n1, double d );
Number operator+( double d, Number const & n1 );
