// timer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ostream>
#include<fstream>
#include <vector>
#include <boost/timer.hpp>
#include <boost/progress.hpp>

#define BOOST_DATE_TIME_SOURCE
#include <libs/date_time/src/gregorian/greg_names.hpp>
#include <libs/date_time/src/gregorian/date_generators.cpp>
#include <libs/date_time/src/gregorian/greg_month.cpp>
#include <libs/date_time/src/gregorian/greg_weekday.cpp>
#include <libs/date_time/src/gregorian/gregorian_types.cpp>

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;

using namespace boost;
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

void chapter1_4() 
{
	time_duration td = duration_from_string("1:20:30:001");
	cout << td;
}

void chapter1_3() 
{
	gregorian::date d1;
	gregorian::date d2(gregorian::from_string("2016/03/24"));
	gregorian::date d3(gregorian::neg_infin);
	gregorian::date d4(gregorian::not_a_date_time);
	gregorian::date d5(gregorian::max_date_time);
	gregorian::date d6(gregorian::min_date_time);

	cout<<d1<<endl;
	cout<<d2<<endl;
	cout<<d3<<endl;
	cout<<d4<<endl;
	cout<<d5<<endl;
	cout<<d6<<endl;

	date dt1(2000,1,1);
	date dt2(2008,8,8);
	cout<<dt2-dt1<<endl;
	assert(dt1 + (dt2-dt1) == dt2);

	date_period dp1(dt2, dt1);
	assert(dp1.begin().day() == 8);
}

void chapter1_2()
{
	std::vector<string> v(100000);
	std::ofstream fs("d:/text.txt");

	progress_display pd(v.size());

	std::vector<string>::iterator it = v.begin();
	for (; it < v.end(); ++it)
	{
		fs << *it << endl;
		++pd;
	}
}

void chapter1_1()
{
	timer t;
	cout <<"max timespan:" << t.elapsed_max()/3600 << "h" <<endl;
	cout <<"min timespan:" << t.elapsed_min()/3600 << "s" <<endl;

	cout <<"now time elapsed:" << t.elapsed() << "s" <<endl;

	progress_timer pt;
	for (int i = 0; i < 1000000; i++)
	{
		i++;
		i--;

	}
}