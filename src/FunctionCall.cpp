#include "../inc/FunctionCall.h"

FunctionCall::FunctionCall( std::string const & name, Expression const * arg )
	: name_( name ), arg_( arg )
{
	assert( arg_ );
	assert( name_ == "sqrt" || name_ == "abs" );
}

std::string const & FunctionCall::name( ) const
{
	return name_;
}

Expression const * FunctionCall::arg( ) const
{
	return arg_;
}

double FunctionCall::evaluate( Scope * sc ) const
{
	if ( name_ == "sqrt" )
		return sqrt( arg_->evaluate( sc ) );
	else if ( name_ == "abs" )
		return abs( arg_->evaluate( sc ) );
	else
		assert( 0 );
}

FunctionCall::~FunctionCall( )
{
	delete arg_;
}

Expression * FunctionCall::transform( Transformer *tr ) const
{
	return tr->transformFunctionCall( this );
}

