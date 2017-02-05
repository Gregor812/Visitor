#pragma once

#include <string>

struct Scope {
	virtual ~Scope( )
	{ }

	virtual double variableValue( std::string const &name ) const = 0;
};
