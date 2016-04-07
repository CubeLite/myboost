#include "stdafx.h"
#include "chapter6.h"
#include <iostream>
#include <ostream>
#include<fstream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>

#include <boost/optional.hpp>
#include <boost/swap.hpp>
#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>


#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
using namespace boost;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost::xpressive;

#define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>


using namespace std;
using namespace chapter6;


#include <boost/format.hpp>
namespace boost
{
	void assertion_failed(char const * expr, char const * function, char const * file, long line)
	{
		boost::format fmt("Assertion failed!\n Expression: %s\nFunction: %s\nFile: %s\nLine: %ld\n\n");
		fmt %expr %function %file %line;
		cout << fmt;
	}
}

double func(int x)
{
	BOOST_ASSERT(x != 0 && "divided by zero");
	return 1.0 / x;
}

void chapter6::demo_boost_assertion()
{
	func(0);
}

void chapter6::demo_boost_static_assertion()
{
	cout << my_min((short)1, (short)3);
	//cout << my_min(1L, 3L); // 编译期执行检查，放开直接编译失败
}