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
}
