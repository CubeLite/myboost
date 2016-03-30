#include "stdafx.h"
#include "chapter5.h"
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
using namespace boost;

using namespace std;
using namespace chapter5;

void chapter5::demo_lexical_cast()
{
	int x = lexical_cast<int>("100");
	assert(x == 100);

	long y = lexical_cast<long>("2000");
	float pi = lexical_cast<float>("3.14159");
	double e = lexical_cast<double>("2.71828");

	cout << x << y << pi << e << endl;

	string str = lexical_cast<string>(456);
	cout << str << endl;

	cout << lexical_cast<string>(0.618) << endl;
	cout << lexical_cast<string>(0x10) << endl;

	try
	{
		int xx = lexical_cast<int>("hello world");
	}
	catch (bad_lexical_cast& e)
	{
		cout << e.what() << endl;
	}

	assert(NumValid<double>("3.14"));
	assert(!NumValid<int>("3.14"));
	assert(NumValid<int>("65535"));

	cout << lexical_cast<string>(LexicalClazz()) << endl;
}

void chapter5::demo_format()
{
	cout << format("%s:%d + %d = %d\n") %"sum" %1 %2 %(1+2) << endl;

	format fmt("(%1% + %2%) * %2% = %3%\n");
	fmt %2 %5;
	fmt %((2+5)*5);
	cout << fmt.str() << endl;
}
