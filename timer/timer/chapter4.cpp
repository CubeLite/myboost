#include "stdafx.h"
#include "chapter4.h"
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
using namespace boost;

#include <boost/assign.hpp>
using namespace boost::assign;

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace boost::uuids;

using namespace std;
using namespace chapter4;

chapter4::Point::Point(int x, int y, int z): x(x), y(y), z(z)
{
}

void chapter4::Point::Print() const
{
	cout << "Point(" << x << "," << y << "," << z << ")" << endl;
}


vector<string> vfunc()
{
	vector<string> v(10);
	return v;
}

void chapter4::demo_typeof_auto()
{
	BOOST_TYPEOF(2.0*3) x = 2.0 * 3;
	BOOST_AUTO(y, 2+3);

	BOOST_AUTO(&a, new double[20]);
	BOOST_AUTO(p, make_pair(1, "string"));

	BOOST_AUTO(v, vfunc());
	std::cout << v.size() << endl;

	BOOST_AUTO(cc, make_pair("test", ex::demo_class()));
	cout << typeid(cc).name() << endl;
	cc.second.a = 10;
	cc.second.b = 20;
	cout << cc.second.a << cc.second.b << endl;
}

void chapter4::demo_optional()
{
	optional<int> op0;
	optional<int> op1(none);
	assert(!op0);
	assert(op0 == op1);
	assert(op1.get_value_or(253) == 253);

	optional<string> ops("test");
	cout << *ops << endl;

	vector<int> v(10);
	optional<vector<int>& > opv(v);
	assert(opv);

	opv->push_back(5);
	assert(opv->size() == 11);
	
	opv = none;
	assert(!opv);

	BOOST_AUTO(x, make_optional(5));
	cout << *x << endl;
}

void chapter4::demo_assign()
{
	vector<int> v;
	v += 1,2,3,4,5, 2*6;
	assert(v.size() == 6);

	set<string> s;
	s += "cpp", "java", "c#", "golang";

	map<int, string> m;
	m += make_pair(1, "one"), make_pair(2, "two");

	push_back(v) (11)(22)(33);

	list<string> li;
	push_front(li)("cpp")("java")("c#")("golang");

	set<double> sd;
	insert(sd)(3.14)(0.618)(1.732);

	map<int, string> mm;
	insert(mm)(1, "one")(2, "two");

	vector<int> v3 = list_of(1) (2) (3); // 构造时完成数据填充
	deque<string> d3 = (list_of("power")("bomb"), "phazon", "suit");
	map<int, string> m3 = map_list_of(1, "one")(2, "two");

	vector<int> v4 = list_of(1).repeat(3, 2)(3)(4)(5);
	// v4 = 1, 2, 2, 2, 3, 4, 5

	multiset<int> ms;
	insert(ms).repeat_fun(5, &rand).repeat(2, 1), 10;
	// ms = x, x, x, x, x, 1, 1, 10
}

void chapter4::demo_tribool()
{
	tribool tb(true);
	tribool tb2(!tb);
	if (tb)
	{
		cout << "true" << endl;
	}

	tb2 = indeterminate;
	assert(indeterminate(tb2));
	cout << tb2 << endl;

	if (tb2 == indeterminate)
	{
		cout << "indeterminate" << endl;
	}

	cout << (tb2 || true) << endl;
	cout << (tb2 && false) << endl;
}

void chapter4::demo_operator()
{
	Point p0, p1(1,2,3), p2(3,0,5), p3(3,2,1), p4(p1);
	assert(p0 < p1 && p1 < p2);
	assert(p2 > p0); // Point继承 less_than_comparable，自动生成 > 的实现
	assert(p1 <= p3);
	assert(!(p1 < p3) && !(p1 < p3));

	assert(p1 == p4);
	assert(p0 != p1);

	vector<Point> v = (list_of(p0), p1, p2, p3, p4);
	BOOST_AUTO(pos, std::find(v.begin(), v.end(), Point(1,2,3)));

	pos->Print();
	(p1+p2).Print();
	assert((p2-p2) == p0);
}

void chapter4::demo_exception()
{
	try
	{
		try
		{
			throw MyException() << ErrNo(10);
		}
		catch (MyException& e)
		{
			cout << *get_error_info<ErrNo>(e) << endl;
			cout << e.what() << endl;
			e << ErrStr("other info");
			throw;
		}
	}	
	catch (MyException& e)
	{
		cout << *get_error_info<ErrStr>(e) << endl;
	}
}

void chapter4::demo_uuid()
{
	uuid u = nil_uuid();
	assert(uuid::static_size() == 16);
	cout << u << endl;

	string_generator sgen;
	uuid u1 = sgen("1023456789abcdef0123456789abcdef");
	cout << u1 << endl;

	uuid u2 = sgen("10234567-89ab-cdef-0123-456789abcdef");
	cout << u2 << endl;

	uuid u3 = sgen(L"{10234567-89ab-cdef-0123-456789abcdef}");
	cout << u3 << endl;

	random_generator rgen;
	uuid u4 = rgen();
	cout << u4 << endl;
}

