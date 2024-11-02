#pragma once
#include "algorithm"
namespace StaticMatchLib 
{
	struct PointXY 
	{
		int X;
		int Y;
	};
	struct Segment 
	{
		PointXY start, end;
	};
	class BasicMatchLib 
	{
	public:
		static bool isPointOnSegment(PointXY p, Segment s);
	};
}