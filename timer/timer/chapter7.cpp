#include "stdafx.h"
#include "chapter7.h"
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
using namespace boost;
using namespace boost::bimaps;
using namespace boost::tuples;

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

void chapter7::demo_bimap()
{
	bimap<int, string> bm;

	bm.left.insert(make_pair(1, "111"));
	bm.left.insert(make_pair(2, "222"));

	bm.right.insert(make_pair("string", 10));
	bm.right.insert(make_pair("bimap", 20));

	for (BOOST_AUTO(pos, bm.left.begin()); pos != bm.left.end(); ++pos)
	{
		cout << "left[" << pos->first << "]=" << pos->second << endl;
	}

	// muliset_of is located at namespace boost::bimaps
	bimap<multiset_of<int>, multiset_of<string> > bm2;

	bimap<tagged<int, struct id>, tagged<string, struct name> > bmtag;
	bmtag.by<id>().insert(make_pair(1, "samus"));
}


void chapter7::demo_circular_buffer()
{
	circular_buffer<int> cb((list_of(1), 2, 3));
	print_container(cb); // 1, 2, 3

	cb.push_back(4);
	print_container(cb); // 2, 3, 4
}

typedef tuple<int, double, string> Tuple3;
Tuple3 func()
{
	return make_tuple(1, 2.1, "hello");
}

template<typename T>
void print_tuple(const T& tuplex)
{
	cout << tuplex.get_head() << ',';
	print_tuple(tuplex.get_tail());
}
void print_tuple(const boost::tuples::null_type&){}

template<typename Visitor, typename Tuple>
typename result_of<Visitor(Tuple&)>::type
visit_tuple(Visitor v, const Tuple &t)
{
	v(t.get_head());
	return visit_tuple(v, t.get_tail());
}

struct print_visitor
{
	typedef void result_type;
	template<typename T>
	result_type operator() (const T &t)
	{
		cout << t << ",";
	}
};

template<>
void visit_tuple<print_visitor, tuples::null_type>(print_visitor, const tuples::null_type&)
{}

void chapter7::demo_tuple()
{
	typedef tuple<int, string, double> my_tuple;
	my_tuple t1;
	my_tuple t2(1, "abc");
	my_tuple t3 = t1;

	assert(t1 == t3);
	assert(t2 != t3);
	assert(typeid(int) == typeid(tuples::element<0, my_tuple>::type));
	assert(typeid(string) == typeid(tuples::element<1, my_tuple>::type));
	cout << tuples::length<my_tuple>::value << endl;

	int x = 10;
	tuple<int&> t4(x);

	tuple<int, double> t5 = make_tuple(1, 3.14);
	assert(t5.get<0>() == 1);
	assert(t5.get<1>() == 3.14);
	assert(boost::get<0>(t5) == 1);

	cout << t5 << endl; // (1 3.14)

	cout << tuples::set_open('[') << tuples::set_close(']');
	cout << tuples::set_delimiter(',');
	cout << t5 << endl; // [1, 3.14]

	int i;
	double d;
	string str;
	boost::tie(i, d, str) = func();
	cout << i << d << str << endl;

	double dd;
	boost::tie(tuples::ignore, dd, tuples::ignore) = func();
	cout << dd << endl;

	Tuple3 tx6 = func();
	cout << tx6 << endl;

	print_tuple(tx6);
	visit_tuple(print_visitor(), tx6);
}
