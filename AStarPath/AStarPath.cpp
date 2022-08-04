#include <iostream>
#include "Edge.h"

void FindPath(char origin, char dest, std::vector<Edge*> edges);

//  TODO: Implement heuristics
//  Use Vector of Vectors for a coordinate
// Breadth first tree from a starting point
// Mark which part has been visited
//  Check if endpoint was met
int main()
{
    //  Sample map
    //  Edges in the map
    //  Assumes that values are letters
    std::vector<Edge*> edges;
    edges.push_back(new Edge('a', 'b', 5));
    edges.push_back(new Edge('b', 'c', 1));
    edges.push_back(new Edge('a', 'd', 7));
    edges.push_back(new Edge('c', 'd', 1));

    //  Sample request
    //  (a, d)
    FindPath('a', 'd', edges);
}

void FindPath(char origin, char dest, std::vector<Edge*> edges)
{
    std::vector<Edge*> paths;
    //  Build paths from edges
    for (unsigned int i = 0; i < edges.size(); i++)
    {
        if ((edges[i]->GetOrigin() == origin))
        {
            edges[i]->Visit();
            paths.push_back(edges[i]);
        }
    }

    //  Checks through all the initial paths
    for (unsigned int i = 0; i < paths.size(); i++)
    {
        //  Checks if the current path has the origin and destination
        /*if (((edges[i]->GetOrigin() == origin) && (edges[i]->GetDestination() == dest))
            || ((edges[i]->GetOrigin() == dest) && (edges[i]->GetDestination() == origin)))*/
        if ((paths[i]->GetOrigin() == dest) || (paths[i]->GetDestination() == dest))
        {
            //  Path has been found
            paths[i]->PathFound();
            continue;
        }

        //  Otherwise iterate through the unvisited edges to find paths to the destination
        unsigned int j = 0;
        while (j < edges.size())
        {
            if (edges[j]->GetVisited())
            {
                j++;
                continue;
            }

            //  Checks if the edge matches either of the origin or destination
            if ((paths[i]->GetOrigin() == edges[j]->GetOrigin())
                || (paths[i]->GetOrigin() == edges[j]->GetDestination())
                || (paths[i]->GetDestination() == edges[j]->GetOrigin())
                || (paths[i]->GetDestination() == edges[j]->GetDestination())
                || (edges[j]->GetOrigin() == dest)
                || (edges[j]->GetDestination() == dest))
            {
                //  Set the current path edge to the current edge looked at
                edges[j]->SetPrevEdge(paths[i]);

                //  Set the path to visited
                edges[j]->Visit();
                //paths.push_back(edges[j]);
                paths[i] = edges[j];
                j = 0;
            }
            j++;
        }
    }

    if (paths.size() == 0)
    {
        std::cout << "Path from " << origin << " to " << dest << " could not be found." << std::endl;
        return;
    }

    //  Iterate through all paths to find the shortest one
    unsigned int shortest = 1000000;
    for (unsigned int i = 0; i < paths.size(); i++)
    {
        Edge* currentEdge = paths[i];
        unsigned int distance = currentEdge->GetDistance();
        while (currentEdge->GetPrevEdge() != nullptr)
        {
            currentEdge = currentEdge->GetPrevEdge();
            distance += currentEdge->GetDistance();
        }

        if (distance < shortest)
        {
            shortest = distance;
        }
    }

     std::cout << "The shortest path from " << origin << " to " << dest << " is " << shortest << std::endl;
}