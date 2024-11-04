#pragma once
#include "algorithm"
#include <mutex>
#include <vector>
namespace StaticMatchLib 
{
	struct PointXY
	{
		PointXY(int,int);
		PointXY(const PointXY&);
		int X;
		int Y;
std::mutex mtx;
	};
	struct Segment 
	{
		Segment(PointXY, PointXY);
		PointXY getStart();
		PointXY getEnd();
std::mutex mtx;
	private:
		PointXY start, end;
	};
	struct Line 
	{
		Line(std::vector<PointXY>);
		std::vector<PointXY> getPoints();
		std::vector<PointXY> points;
		std::mutex mtx;
	};
	class BasicMatchLib 
	{
	public:
		static bool isPointOnSegment(PointXY &p, Segment &s);
	};
}