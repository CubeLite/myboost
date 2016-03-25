#include "stdafx.h"
#include "chapter2.h"
#include <iostream>
#include <ostream>
#include<fstream>
#include <vector>
#include <boost/timer.hpp>
#include <boost/progress.hpp>

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;

#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/pool/singleton_pool.hpp>
#include <boost/pool/pool_alloc.hpp>

using namespace boost;
using namespace std;
using namespace chapter2;

void chapter2::demo_scoped_ptr()
{
	std::auto_ptr<int> ap(new int(10));
	assert(ap.get() != 0);

	scoped_ptr<int> sp(ap);
	assert(ap.get() == 0);
	assert(sp.get() != 0);
}

void chapter2::demo_share_ptr_cast()
{
	shared_ptr<std::exception> sp1(new bad_exception("error"));
	shared_ptr<bad_exception> sp2 = dynamic_pointer_cast<bad_exception>(sp1);
	shared_ptr<std::exception> sp3 = static_pointer_cast<std::exception>(sp2);
	assert(sp3 == sp1);
}

void chapter2::demo_make_shared_ptr()
{
	shared_ptr<string> sp = make_shared<string>("hello");
	assert(sp.unique());
}

void chapter2::demo_shared_ptr_vector()
{
	typedef vector<shared_ptr<int> > VS;
	VS v(10); // 10 elements in v

	int i = 0;
	for (VS::iterator pos = v.begin(); pos != v.end(); ++pos)
	{
		(*pos) = make_shared<int>(++i);
		cout << *(*pos) << ", ";
	}
	cout << endl;

	shared_ptr<int> p = v[9];
	*p = 100;
	cout << *v[9] << endl;
}
