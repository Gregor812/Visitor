#include "../inc/Expression.h"
#include "../inc/Number.h"
#include "../inc/BinaryOperation.h"
#include "../inc/FunctionCall.h"
#include "../inc/Variable.h"
#include "../inc/Transformer.h"
#include "../inc/ConstFolding.h"
#include "../inc/CopySyntaxTree.h"

int main( )
{
	Expression *start_expr = new BinaryOperation (
		new FunctionCall(
			"sqrt",
			new BinaryOperation(
				new Number( 2 ),
				BinaryOperation::PLUS,
				new Number( 8 )
			)
		),
		BinaryOperation::PLUS,
		new Number( 1 )
	);
	
	ConstFolding   *constFolder = new ConstFolding( );
	CopySyntaxTree *syntaxCopy = new CopySyntaxTree( );

	Expression *folded_expr = start_expr->transform( constFolder );
	Expression *copied_expr = start_expr->transform( syntaxCopy );

	return 0;
}