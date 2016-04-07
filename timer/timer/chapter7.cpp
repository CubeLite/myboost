#include "stdafx.h"
#include "chapter7.h"
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
#include <boost/typeof/std/utility.hpp>

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
using namespace boost;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost::xpressive;

#define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>


using namespace std;
using namespace chapter7;



void chapter7::demo_dynamic_bitset()
{
	dynamic_bitset<> db1;
	dynamic_bitset<> db2(10);
	dynamic_bitset<> db3(0x16, BOOST_BINARY(10101));
	dynamic_bitset<> db4(string("0100"));
	dynamic_bitset<> db5 = db3;

	dynamic_bitset<> dbx(4, BOOST_BINARY(1010));
	dbx[0] &= 1;
	dbx[1] ^= 1;
	cout << dbx << endl;
}

void chapter7::demo_unorder_set()
{
	unordered_set<int> us = (list_of(1),2,3,4,5);
	for (BOOST_AUTO(p, us.begin()); p != us.end(); ++p)
	{
		cout << *p << endl;
	}

	BOOST_AUTO(p, us.find(5));
	cout << *p << endl;
}
