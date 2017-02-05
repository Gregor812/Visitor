#include "../inc/BinaryOperation.h"

BinaryOperation::BinaryOperation( Expression const * left, int op, Expression const * right )
	: left_( left ), op_( op ), right_( right )
{
	assert( left_ && right_ );
}

Expression const * BinaryOperation::left( ) const
{
	return left_;
}

Expression const * BinaryOperation::right( ) const
{
	return right_;
}

int BinaryOperation::operation( ) const
{
	return op_;
}

double BinaryOperation::evaluate( Scope * sc ) const
{
	double left = left_->evaluate( sc );
	double right = right_->evaluate( sc );
	switch ( op_ )
	{
		case PLUS: return left + right;
			break;
		case MINUS: return left - right;
			break;
		case DIV: return left / right;
			break;
		case MUL: return left * right;
			break;
	}
}

Expression * BinaryOperation::transform( Transformer *tr ) const
{
	return tr->transformBinaryOperation( this );
}

BinaryOperation::~BinaryOperation( )
{
	delete left_;
	delete right_;
}
