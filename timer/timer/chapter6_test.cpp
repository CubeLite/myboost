#include "stdafx.h"

//#define BOOST_TEST_INCLUDED
//#include <boost/test/unit_test.hpp>
//#include <boost/smart_ptr.hpp>
//
//#include <iostream>
//#include <ostream>
//#include<fstream>
//#include <vector>
//#include <deque>
//#include <string>
//#include <cstdlib>
//
//#include <boost/optional.hpp>
//#include <boost/swap.hpp>
//#include <boost/logic/tribool.hpp>
//#include <boost/logic/tribool_io.hpp>
//
//#include <boost/assign.hpp>
//
//#include <boost/lexical_cast.hpp>
//#include <boost/format.hpp>
//#include <boost/algorithm/string.hpp>
//#include <boost/tokenizer.hpp>
//using namespace boost;
//
//#include <boost/xpressive/xpressive_dynamic.hpp>
//using namespace boost::xpressive;
//
//#define BOOST_ENABLE_ASSERT_HANDLER
//#include <boost/assert.hpp>
//
//using namespace std;
//
//struct global_fixture
//{
//	global_fixture()
//	{
//		cout << ("global setup\n");
//	}
//
//	~global_fixture()
//	{
//		cout << ("global teardown\n");
//	}
//};
//
//// 初始化单元测试全局环境
//BOOST_GLOBAL_FIXTURE(global_fixture);
//
//// 定义测试套件
//BOOST_AUTO_TEST_SUITE(s_smart_ptr)
//
//// 测试案例
//BOOST_AUTO_TEST_CASE(t_scoped_ptr)
//{
//	scoped_ptr<int> p(new int(874));
//	BOOST_CHECK(p);
//	BOOST_CHECK_EQUAL(*p, 874);
//
//	p.reset();
//	BOOST_CHECK(p == 0);
//}
//
//BOOST_AUTO_TEST_CASE(t_shared_ptr)
//{
//	shared_ptr<int> p(new int(100));
//
//	BOOST_CHECK(p);
//	BOOST_CHECK_EQUAL(*p, 100);
//	BOOST_CHECK_EQUAL(p.use_count(), 1);
//
//	shared_ptr<int> p2 = p;
//	BOOST_CHECK_EQUAL(p, p2);
//	BOOST_CHECK_EQUAL(p.use_count(), 2);
//	BOOST_CHECK_EQUAL(p2.use_count(), 2);
//
//	*p2 = 255;
//	BOOST_CHECK_EQUAL(*p, 255);
//	BOOST_CHECK_GT(*p, 200);
//}
//
//// 测试套件结束
//BOOST_AUTO_TEST_SUITE_END()
//
//// 测试套件2
//struct assign_fixture
//{
//	assign_fixture()
//	{
//		cout << ("suit setup\n");
//	}
//	~assign_fixture()
//	{
//		cout << ("suit teardown\n");
//	}
//
//	vector<int> v;
//};
//
//BOOST_FIXTURE_TEST_SUITE(s_assign, assign_fixture)
//
//BOOST_AUTO_TEST_CASE(t_assign1)
//{
//	using namespace boost::assign;
//	v += 1,2,3,4;
//	BOOST_CHECK_EQUAL(v.size(), 4);
//	BOOST_CHECK_EQUAL(v[2], 3);
//}
//
//BOOST_AUTO_TEST_CASE(t_assign2)
//{
//	using namespace boost::assign;
//	push_back(v)(10)(20)(30);
//
//	BOOST_CHECK_EQUAL(v.empty(), false);
//	BOOST_CHECK_EQUAL(v.size(), 3);
//	BOOST_CHECK_LT(v[0], v[1]);
//}
//
//BOOST_AUTO_TEST_SUITE_END()