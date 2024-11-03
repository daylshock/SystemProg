#pragma once
#include "algorithm"
#include <mutex>
#include <vector>
namespace StaticMatchLib 
{
	class PointXY 
	{
	public:
		PointXY(const PointXY& );
		PointXY(int, int);
		int X;
		int Y;
	private:
		std::mutex mtx;
	};
	class Segment 
	{
	public:
		Segment(const Segment&);
		Segment(PointXY, PointXY);
		PointXY getStart();
		PointXY getEnd();
	private:
		std::mutex mtx;
		PointXY start, end;
	};
	class Line 
	{
	public:
		Line(std::vector<PointXY>);
		std::vector<PointXY> getPoints();
	private:
		std::vector<PointXY> points;
		std::mutex mtx;
	};
	class BasicMatchLib 
	{
	public:
		static bool isPointOnSegment(PointXY p, Segment s);
	};
}