#include "../inc/Number.h"

Number::Number( ) : value_( 0 )
{ }

Number::Number( double value ) : value_( value )
{ }

double Number::value( ) const
{
	return value_;
}

double Number::evaluate( Scope * sc ) const
{
	return value_;
}

Expression * Number::transform( Transformer *tr ) const
{
	return tr->transformNumber( this );
}

Number operator-( Number const & n )
{
	return Number( -n.value( ) );
}

Number operator-( Number const & n1, Number const & n2 )
{
	return Number( n1.value( ) - n2.value( ) );
}

Number operator+( Number const & n1, Number const & n2 )
{
	return Number( n1.value( ) + n2.value( ) );
}

Number operator-( Number const & n1, double d )
{
	return Number( n1.value( ) - d );
}

Number operator-( double d, Number const & n1 )
{
	return -( n1 - d );
}

Number operator+( Number const & n1, double d )
{
	return Number( n1.value( ) + d );
}

Number operator+( double d, Number const & n1 )
{
	return ( n1 + d );
}

