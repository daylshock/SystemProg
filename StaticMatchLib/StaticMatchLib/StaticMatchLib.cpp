// StaticMatchLib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "StaticMatchLib.h"

// TODO: Это пример библиотечной функции.
namespace StaticMatchLib
{
	PointXY::PointXY(int X, int Y) : X(X), Y(Y) {}
	PointXY::PointXY(const PointXY& obj) 
	{
		X = obj.X;
		Y = obj.Y;
	}

	Segment::Segment(PointXY start, PointXY end) : start(start), end(end) {}

	PointXY Segment::getStart() { return start; }
	PointXY Segment::getEnd() { return end; }

	Line::Line(std::vector<PointXY> points) : points(points) {}

	std::vector<PointXY> Line::getPoints() {
		std::lock_guard<std::mutex> lock(mtx);
		return points;
	}

	bool BasicMatchLib::isPointOnSegment(PointXY &p, Segment &s)
	{
		std::lock_guard<std::mutex> lock(p.mtx);
		std::lock_guard<std::mutex> lock1(s.mtx);

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