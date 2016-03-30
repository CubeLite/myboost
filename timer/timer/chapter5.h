#include "stdafx.h"
#include <boost/lexical_cast.hpp>

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
}