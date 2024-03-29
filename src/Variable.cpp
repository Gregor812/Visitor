#include "../inc/Variable.h"

Variable::Variable( std::string const &name ) : name_( name )
{ }

std::string const & Variable::name( ) const
{
	return name_;
}

double Variable::evaluate( Scope * sc ) const
{
	return sc->variableValue( name( ) );
}

Expression * Variable::transform( Transformer *tr ) const
{
	return tr->transformVariable( this );
}