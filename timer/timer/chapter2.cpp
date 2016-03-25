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