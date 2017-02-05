#pragma once

#include "Expression.h"

struct ScopedPtr {
	explicit ScopedPtr( Expression *ptr = 0 )
	{
		if ( ptr )
			ptr_ = ptr;
	}

	~ScopedPtr( )
	{
		delete ptr_;
		ptr_ = 0;
	}

	Expression* get( ) const
	{
		return ptr_;
	}

	Expression* release( )
	{
		Expression * temp = ptr_;
		ptr_ = 0;
		return temp;
	}

	void reset( Expression *ptr = 0 )
	{
		delete ptr_;
		if ( ptr )
			ptr_ = ptr;
	}

	Expression & operator*( ) const
	{
		return *ptr_;
	}

	Expression* operator->( ) const
	{
		return ptr_;
	}

private:
	ScopedPtr( const ScopedPtr& );
	ScopedPtr& operator=( const ScopedPtr& );

	Expression *ptr_;
};
