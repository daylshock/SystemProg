// StaticMatchLib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "StaticMatchLib.h"

// TODO: Это пример библиотечной функции.
namespace StaticMatchLib
{
	bool BasicMatchLib::isPointOnSegment(PointXY p, Segment s)
	{
		int minX = std::min(s.start.X, s.end.X);
		int maxX = std::max(s.start.X, s.end.X);
		int minY = std::min(s.start.Y, s.end.Y);
		int maxY = std::max(s.start.Y, s.end.Y);

		if (p.X >= minX && p.X <= maxX && p.Y >= minY && p.Y <= maxY) {
			return true;
		}
		return false;
	}
}