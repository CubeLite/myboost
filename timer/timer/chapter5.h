#include "stdafx.h"
#include <boost/lexical_cast.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/assign/list_of.hpp>
using namespace boost::assign;

namespace chapter5
{
	template<typename T>
	bool NumValid(const char *str)
	{
		try
		{
			boost::lexical_cast<T>(str);
			return true;
		}
		catch (boost::bad_lexical_cast&)
		{
			return false;
		}
	}

	class LexicalClazz
	{
		friend std::ostream& operator<<(std::ostream& os, const LexicalClazz& x)
		{
			os << "demo lexical class's Name";
			return os;
		}
	};

	void demo_lexical_cast();

	void demo_format();

	void demo_string_algo();
	void demo_string_algo_trim();
	void demo_string_algo_find();
	void demo_string_algo_split();
	void demo_string_algo_join();

	template<typename T>
	void printToken(T &tok)
	{
		for (BOOST_AUTO(pos, tok.begin()); pos != tok.end(); ++pos)
		{
			cout << "[" << *pos << "]";
		}
		cout << endl;
	}
	void demo_tokenizer();
}