#pragma once

#include "Expression.h"
#include "Number.h"
#include "Scope.h"
#include "Transformer.h"

struct BinaryOperation : Expression {
	enum {
		PLUS = '+',
		MINUS = '-',
		DIV = '/',
		MUL = '*'
	};

	BinaryOperation( Expression const * left = new Number( 0 ), int op = BinaryOperation::PLUS, Expression const * right = new Number( 0 ) );
	Expression const * left( ) const;
	Expression const * right( ) const;
	int operation( ) const;
	double evaluate( Scope * sc ) const;
	Expression *transform( Transformer *tr ) const;
	~BinaryOperation( );

private:
	Expression const * left_;
	Expression const * right_;
	int op_;
};
