#include "stdafx.h"
#include <boost/lexical_cast.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/static_assert.hpp>
using namespace boost::assign;
using namespace boost;

namespace chapter6
{
	template<typename T>
	T my_min(T a, T b)
	{
		BOOST_STATIC_ASSERT(sizeof(T) < sizeof(int));
		return a < b ? a : b;
	}

	void demo_boost_assertion();

	void demo_boost_static_assertion();
}