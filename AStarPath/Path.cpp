#include "Path.h"

//	Member functions
int Path::TotalDistance()
{
	int distance = 0;
	Coord* point = m_dest;

	do
	{
		distance += m_dest->m_cost;
		if (m_prev != nullptr)
		{
			point = m_prev->m_dest;
		}
	} while (m_origin != point);

	return distance;
}