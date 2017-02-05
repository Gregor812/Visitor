#pragma once

#include "Expression.h"
#include "Number.h"
#include "BinaryOperation.h"
#include "FunctionCall.h"
#include "Variable.h"

struct Transformer {
	virtual ~Transformer( )
	{ }

	virtual Expression * transformNumber( Number const * number ) = 0;
	virtual Expression * transformBinaryOperation( BinaryOperation const * binop ) = 0;
	virtual Expression * transformFunctionCall( FunctionCall const * fcall ) = 0;
	virtual Expression * transformVariable( Variable const * var ) = 0;
};
