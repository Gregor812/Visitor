#pragma once

#include <string>
#include <cassert>
#include <cmath>
#include "Scope.h"
#include "Transformer.h"

struct Expression {
	virtual double evaluate( Scope * sc ) const = 0;
	virtual Expression * transform( Transformer * tr ) const = 0;
	virtual ~Expression( )
	{ }
};

bool check_equals( Expression const * left, Expression const * right );
