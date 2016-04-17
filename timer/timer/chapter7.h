#include "stdafx.h"
#include <boost/optional.hpp>
#include <boost/swap.hpp>
#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>
#include <boost/typeof/std/utility.hpp>

namespace chapter7
{
	template<typename T>
	void print_container(T& container)
	{
		cout << "begin print container...." << endl;
		for (BOOST_AUTO(pos, container.begin()); pos != container.end(); ++pos)
		{
			cout << *pos << endl;
		}
		cout << "print container is done." << endl;
	}

	

	void demo_dynamic_bitset();

	void demo_unorder_set();

	void demo_bimap();

	void demo_circular_buffer();

	void demo_tuple();
}