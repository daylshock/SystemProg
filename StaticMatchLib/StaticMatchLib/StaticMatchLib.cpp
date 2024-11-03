// StaticMatchLib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "StaticMatchLib.h"

// TODO: Это пример библиотечной функции.
namespace StaticMatchLib
{
	PointXY::PointXY(const PointXY& obj) 
	{
		X = obj.X;
		Y = obj.Y;
	}
	PointXY::PointXY(int X, int Y) : X(Y), Y(Y) {}

	Segment::Segment(const Segment& obj) : start(start), end(end)
	{
		start.X = obj.start.X;
		start.Y = obj.end.Y;
		end.X = obj.end.X;
		end.Y = obj.end.Y;
	}
	Segment::Segment(PointXY start, PointXY end) : start(start), end(end) {}

	PointXY Segment::getStart() {
		std::lock_guard<std::mutex> lock(mtx);
		return start;
	}

	PointXY Segment::getEnd() {
		std::lock_guard<std::mutex> lock(mtx);
		return end;
	}
	Line::Line(std::vector<PointXY> points) : points(points) {}

	std::vector<PointXY> Line::getPoints() {
		std::lock_guard<std::mutex> lock(mtx);
		return points;
	}
	bool BasicMatchLib::isPointOnSegment(PointXY p, Segment s)
	{
		int minX = std::min(s.getStart().X, s.getEnd().X);
		int maxX = std::max(s.getStart().X, s.getEnd().X);
		int minY = std::min(s.getStart().Y, s.getEnd().Y);
		int maxY = std::max(s.getStart().Y, s.getEnd().Y);

		if (p.X >= minX && p.X <= maxX && p.Y >= minY && p.Y <= maxY) {
			return true;
		}
		return false;
	}
}