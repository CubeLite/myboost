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
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
using namespace boost;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost::xpressive;

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

void chapter5::demo_string_algo()
{
	string str("readme.txt");
	if (ends_with(str, "txt"))
	{
		cout << to_upper_copy(str) + " UPPER" << endl;
		assert(ends_with(str, "txt"));
	}

	replace_first(str, "readme", "followme");
	cout << str << endl;

	string str2 = erase_first_copy(str, "txt");
	cout << str2 << endl;

	string strx("Power Bomb");
	assert(iends_with(strx, "bomb"));
	assert(!ends_with(strx, "bomb"));

	assert(starts_with(strx, "Pow"));
	assert(contains(strx, "er"));

	string strx2 = to_lower_copy(strx);
	assert(iequals(strx, strx2));

	string strx3("power suit");
	assert(ilexicographical_compare(strx, strx3));

	assert(all(strx2.substr(0, 5), is_lower()));
}

void chapter5::demo_string_algo_trim()
{
	format fmt("|%s|\n");

	string str = "   samus aran    ";
	cout << fmt %trim_copy(str) << endl;
	cout << fmt %trim_left_copy(str) << endl;

	string str2 = "2010 Happy new Year!!!";
	cout << fmt %trim_left_copy_if(str2, is_digit());
	cout << fmt %trim_right_copy_if(str2, is_punct());
	cout << fmt %trim_copy_if(str2, is_punct() || is_digit() || is_space());
}

void chapter5::demo_string_algo_find()
{
	format fmt("|%s|. pos = %d\n");

	string str = "Long long ago, there was a king.";

	iterator_range<string::iterator> rge;

	rge = find_first(str, "long");
	cout << fmt %rge %(rge.begin() - str.begin()) << endl;

	rge = ifind_first(str, "long");
	cout << fmt %rge %(rge.begin() - str.begin()) << endl;

	rge = find_nth(str, "ng", 2);
	cout << fmt %rge %(rge.begin() - str.begin()) << endl;

	rge = find_head(str, 4);
	cout << fmt %rge %(rge.begin() - str.begin()) << endl;

	rge = find_tail(str, 5);
	cout << fmt %rge %(rge.begin() - str.begin()) << endl;

	rge = find_first(str, "samus"); // can't find
	cout << fmt %rge %(rge.begin() - str.begin()) << endl;
}

void chapter5::demo_string_algo_split()
{
	string str = "Samus,Link.Zelda::Mario-Luigi+zelda";

	deque<string> d;
	ifind_all(d, str, "zELDA");
	assert(d.size() == 2);
	for (BOOST_AUTO(pos, d.begin()); pos != d.end(); ++pos)
	{
		cout << "[" << *pos << "] " ;
	}
	cout << endl;

	list<iterator_range<string::iterator> > li; // list<string> li; // is also ok
	split(li, str, is_any_of(",.:-+"));
	for (BOOST_AUTO(pos, li.begin()); pos != li.end(); ++pos)
	{
		cout << "[" << *pos << "] " ;
	}
	cout << endl;

	li.clear();
	split(li, str, is_any_of(".:-"), token_compress_on);
	for (BOOST_AUTO(pos, li.begin()); pos != li.end(); ++pos)
	{
		cout << "[" << *pos << "] " ;
	}
	cout << endl;
}

void chapter5::demo_string_algo_join()
{
	vector<string> v = list_of("Samus")("Link")("Zelda")("Mario");
	cout << join(v, "+") << endl;

	struct is_contains_a
	{
		bool operator() (const string& x)
		{
			return contains(x, "a");
		}
	};
	cout << join_if(v, "**", is_contains_a());
}

void chapter5::demo_tokenizer()
{
	string str("Link raise the master-sword.");

	tokenizer<> tok(str);

	for (BOOST_AUTO(pos, tok.begin()); pos != tok.end(); ++pos)
	{
		cout << *pos << endl;
	}

	string str2 = "id,100,name,\"mario\"";

	escaped_list_separator<char> sep;
	tokenizer<escaped_list_separator<char> > tok2(str2, sep);
	printToken(tok2);
}

void chapter5::demo_xpressive()
{
	cregex reg = cregex::compile("a.c");
	assert(regex_match("abc", reg));
	assert(regex_match("a+c", reg));

	assert(!regex_match("ac", reg));
	assert(!regex_match("adb", reg));

	cregex reg2 = cregex::compile("\\d{6}((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))", icase);

	cmatch what;
	assert(regex_match("999555197001019999", what, reg2));
	for (BOOST_AUTO(pos, what.begin()); pos != what.end(); ++pos)
	{
		cout << "[" << *pos << "]";
	}
	cout << endl;

	cout << "date:" << what[1] << what[3] << what[5] << endl;
}

void chapter5::demo_xpressive_search()
{
	char* str = "there is a POWER-suit item";
	cregex reg = cregex::compile("(power)-(.{4})", icase);

	assert(regex_search(str, reg));

	cmatch what;
	regex_search(str, what, reg);
	assert(what.size() == 3);

	for (BOOST_AUTO(pos, what.begin()); pos != what.end(); ++pos)
	{
		cout << *pos << endl;
	}
	assert(!regex_search("error message", reg));
}
