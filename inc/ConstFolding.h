#pragma once

#include "Transformer.h"
#include "Expression.h"
#include "Number.h"
#include "BinaryOperation.h"
#include "FunctionCall.h"
#include "Variable.h"

struct ConstFolding : Transformer {
	Expression * transformNumber( Number const * number );
	Expression * transformBinaryOperation( BinaryOperation const * binop );
	Expression * transformFunctionCall( FunctionCall const * fcall );
	Expression * transformVariable( Variable const * var );
};
