#include "stdafx.h"
#include <boost/noncopyable.hpp>
#include <boost/utility.hpp>
#include <boost/operators.hpp>

#include <boost/typeof/typeof.hpp>
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

namespace chapter4
{
	class Nocopy : boost::noncopyable
	{};

	class Point 
		: boost::less_than_comparable<Point>
		, boost::equality_comparable<Point>
	{
	private:
		int x;
		int y;
		int z;

	public:
		explicit Point(int x = 0, int y = 0, int z = 0);
		void Print() const;

	public:
		friend bool operator<(const Point& pt1, const Point& pt2)
		{
			return (pt1.x*pt1.x + pt1.y*pt1.y + pt1.z*pt1.z) < (pt2.x*pt2.x + pt2.y*pt2.y + pt2.z*pt2.z);
		}

		friend bool operator==(const Point& pt1, const Point& pt2)
		{
			return pt1.x == pt2.x && pt1.y == pt2.y && pt1.z == pt2.z;
		}
	};

	namespace ex
	{
		struct demo_class
		{
			int a;
			int b;
		};
	}

	void demo_typeof_auto();

	void demo_optional();

	void demo_assign();

	void demo_tribool();

	void demo_operator();
}
BOOST_TYPEOF_REGISTER_TYPE(chapter4::ex::demo_class) // Ïò typeof ¿â×¢²áÀà