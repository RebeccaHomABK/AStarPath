#pragma once

struct Coord
{
	char m_x;	//	Origin coordinate
	char m_y;	//	Destination coordinate
	int m_cost;	//	Distance between x and y
	int m_heuristic;	//	Heuristic cost

	Coord(char x, char y, int cost)
		: m_x(x)
		, m_y(y)
		, m_cost(cost)
		, m_heuristic(0)
	{};

	~Coord()
	{

	}
};