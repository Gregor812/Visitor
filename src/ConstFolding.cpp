#include "../inc/ConstFolding.h"

Expression * ConstFolding::transformNumber( Number const * number )
{
	return ( Expression * )new Number( *number );
}

Expression * ConstFolding::transformBinaryOperation( BinaryOperation const * binop )
{
	Expression * new_left, *new_right;
	Scope * sc;
	new_left = binop->left( )->transform( this );
	new_right = binop->right( )->transform( this );

	if ( dynamic_cast< Number * >( new_left ) && dynamic_cast< Number * >( new_right ) )
	{
		delete new_left;
		delete new_right;
		return ( Expression * ) new Number( binop->evaluate( sc ) );
	}
	else
		return ( Expression * ) new BinaryOperation( new_left, binop->operation( ), new_right );
}

Expression * ConstFolding::transformFunctionCall( FunctionCall const * fcall )
{
	Expression * new_arg;
	Scope * sc;
	new_arg = fcall->arg( )->transform( this );

	if ( dynamic_cast< Number * >( new_arg ) )
	{
		delete new_arg;
		return ( Expression * ) new Number( fcall->evaluate( sc ) );
	}
	else
		return ( Expression * ) new FunctionCall( fcall->name( ), new_arg );
}

Expression * ConstFolding::transformVariable( Variable const * var )
{
	return ( Expression * )new Variable( *var );
}
