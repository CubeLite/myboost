#include "stdafx.h"
#include "chapter11.h"
#include <iostream>
#include <ostream>
#include<fstream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>



#include <boost/assign.hpp>
using namespace boost::assign;

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/array.hpp>
#include <boost/dynamic_bitset.hpp>
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
using namespace boost;
using namespace boost::bimaps;
using namespace boost::tuples;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost::xpressive;

#define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>


using namespace std;
using namespace chapter11;

int add(int a, int b) 
{
	return a + b;
}

int g(int a, int b, int c)
{
	return a + b*c;
}

typedef int (*f_type)(int, int);
typedef int (*g_type)(int, int);

void chapter11::demo_result_of()
{
	typedef double (*Func)(double);
	Func func = std::sqrt;

	result_of<Func(double)>::type x = func(9);
	cout << x << endl;

	BOOST_AUTO(xx, CallFunc(func, 9.0));
	cout << xx << endl;
}

void chapter11::demo_ref()
{
	double x = 2.0;
	cout << std::sqrt(ref(x)) << endl;
	cout << x << endl;
}

void chapter11::demo_bind()
{
	cout << bind(add, 1, 2)() << endl;
	cout << bind(g, 1,2,3)() << endl;

	cout << bind(add, _1, 2)(1) << endl;
	cout << bind(g, _1, 2, 3)(1) << endl;

	Tag tag;
	cout << bind(&Tag::add, tag, _1, _2)(1, 2) << endl;
	cout << bind(&Tag::add, &tag, _1, _2)(1, 2) << endl;
}

void chapter11::demo_function()
{
	function<int(int,int)> func;
	assert(!func);

	func = add;
	if (func)
	{
		cout << func(10, 20) << endl;
	}
	func = 0;
	assert(func.empty());
	
	Tag tag;

	func = bind(&Tag::add, &tag, _1, _2);
	cout << func(10, 20) << endl;

	function<int(Tag&, int, int)> func2;
	func2 = bind(&Tag::add, _1, _2, _3);
	
	cout << func2(tag, 10, 20) << endl;
}
