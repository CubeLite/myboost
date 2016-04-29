#include "stdafx.h"
#include <boost/optional.hpp>
#include <boost/swap.hpp>
#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>
#include <boost/typeof/std/utility.hpp>
#include <boost/utility/result_of.hpp>
#include <boost/ref.hpp>

namespace chapter11
{
	template<typename Func, typename Param>
	typename boost::result_of<Func(Param)>::type CallFunc(Func f, Param param)
	{
		return f(param);
	}

	struct Tag
	{
		int add(int a, int b)
		{
			return a+b;
		}
	};

	void demo_result_of();

	void demo_ref();

	void demo_bind();
}