#pragma once
#include <vector>
class Edge
{
	char m_origin;
	char m_destination;
	int m_distance;

	bool m_visited;
	bool m_pathFound;

	Edge* m_prevEdge;
	std::vector<Edge*> m_connections;

public: 
	Edge(char origin, char dest, int distance);

	~Edge();

	//	Getter
	char GetOrigin() { return m_origin; }
	char GetDestination() { return m_destination; }
	int GetDistance() { return m_distance; }
	bool GetVisited() { return m_visited; }
	Edge* GetPrevEdge() { return m_prevEdge; }
	std::vector<Edge*> GetConnections() { return m_connections; }

	//	Setter
	void SetPrevEdge(Edge* prev) { m_prevEdge = prev; }

	//	Helper
	void Visit();
	void PathFound();
	void FindConnections(std::vector<Edge*> totalEdges);
};