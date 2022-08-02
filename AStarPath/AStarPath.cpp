#include <iostream>
#include <vector>

#include "Path.h"

void FindPaths(char origin, std::vector<Coord*> unvisited, std::vector<Path*>& visited);

int main()
{
    //  Sample map
    std::vector<Coord*> unvisited;
    unvisited.push_back(new Coord('a', 'b', 5));
    unvisited.push_back(new Coord('b', 'c', 1));
    unvisited.push_back(new Coord('a', 'd', 7));
    unvisited.push_back(new Coord('c', 'd', 1));

    std::vector<Path*> visited;

    //  Sample request
    //  (a, d)
    char x = 'a';
    char y = 'b';

    //  Find paths from an origin point
    FindPaths(x, unvisited, visited);

    //  Display all paths
    for (unsigned int i = 0; i < visited.size(); i++)
    {
        std::cout << "(" << visited[i]->GetOrigin() << ", " << visited[i]->GetDest() << "): " << visited[i]->TotalDistance() << std::endl;
    }

    //  Find the destination point
    for (unsigned int i = 0; i < visited.size(); i++)
    {
        if (visited[i]->GetDest() == y)
        {
            std::cout << "Going from " << x << " to " << y << " will cost " << visited[i]->TotalDistance() << std::endl;
        }
    }
}

//  TODO: Get all paths and not just immediate Coords
void FindPaths(char origin, std::vector<Coord*> unvisited, std::vector<Path*>& visited)
{
    unsigned int i = 0;
    do
    {
        if ((unvisited[i]->m_x == origin) || (unvisited[i]->m_y))
        {
            //  Set the visited 
            visited.push_back(new Path(unvisited[i], unvisited[i]));
            unvisited.erase(unvisited.begin() + i);
            i = 0;
        }
        else
        {
            i++;
        }
    } while (i < unvisited.size());
}