#include "../inc/CopySyntaxTree.h" 

Expression * CopySyntaxTree::transformNumber( Number const * number )
{
	return ( Expression * )new Number( *number );
}

Expression * CopySyntaxTree::transformBinaryOperation( BinaryOperation const * binop )
{
	return ( Expression * )new BinaryOperation( binop->left( )->transform( this ), binop->operation( ), binop->right( )->transform( this ) );
}

Expression * CopySyntaxTree::transformFunctionCall( FunctionCall const * fcall )
{
	return ( Expression * )new FunctionCall( fcall->name( ), fcall->arg( )->transform( this ) );
}

Expression * CopySyntaxTree::transformVariable( Variable const * var )
{
	return ( Expression * )new Variable( *var );
}
