#pragma once
#include "Coord.h"

struct Path
{
	Coord* m_origin;
	Coord* m_dest;
	Path* m_prev;

	Path(Coord* origin, Coord* dest)
		: m_origin(origin)
		, m_dest(dest)
		, m_prev(nullptr)
	{

	}

	Path(Coord* origin, Coord* dest, Path* prev)
		: m_origin(origin)
		, m_dest(dest)
		, m_prev(prev)
	{
		
	}

	~Path()
	{
		m_origin = nullptr;
		m_dest = nullptr;
		m_prev = nullptr;
	}

	//	Member functions
	int TotalDistance();
	char GetOrigin() { return m_origin->m_x; }
	char GetDest() { return m_dest->m_y; }
};