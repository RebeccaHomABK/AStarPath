#include "Edge.h"

//	Constructor
Edge::Edge(char origin, char dest, int distance)
	: m_origin(origin)
	, m_destination(dest)
	, m_distance(distance)
	, m_visited(false)
{
}

//	Destructor
Edge::~Edge()
{
	if (m_prevEdge != nullptr)
	{
		delete m_prevEdge;
	}
}

//	Helper
void Edge::Visit()
{
	m_visited = true;
}

void Edge::PathFound()
{
	m_pathFound = true;
}

void Edge::FindConnections(std::vector<Edge*> totalEdges)
{
	//	Set this to visited
	this->Visit();

	//	Get all connections where the origin and destinations match
	for (unsigned int i = 0; i < totalEdges.size(); i++)
	{
		if (((totalEdges[i]->GetOrigin() == m_origin)
			|| (totalEdges[i]->GetOrigin() == m_destination)
			|| (totalEdges[i]->GetDestination() == m_origin)
			|| (totalEdges[i]->GetDestination() == m_destination)) 
			&& !((totalEdges[i]->GetOrigin() == m_origin) 
				&& (totalEdges[i]->GetDestination() == m_destination))
			&& !(totalEdges[i]->GetVisited()))
		{
			m_connections.push_back(totalEdges[i]);
			totalEdges[i]->Visit();
		}
	}
}
