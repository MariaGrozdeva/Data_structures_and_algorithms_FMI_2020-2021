
#include "EdgeListGraph.h"

EdgeListGraph::EdgeListGraph(int n, bool oriented) : Graph(n, oriented)
{}

int EdgeListGraph::addVertex()
{
	vertexCount++;
	return vertexCount - 1;
}

void EdgeListGraph::addEdge(int start, int end, int weight)
{
	if (!existsVertex(start) || !existsVertex(end))
		throw "Invalid vertices!";

	edges.push_back({ start, end, weight });
	if (!oriented)
		edges.push_back({ end, start, weight });
}

void EdgeListGraph::removeEdge(int start, int end) // O(m)
{
	if (!existsVertex(start) || !existsVertex(end))
		throw "Invalid vertices!";

	bool found = false;
	for (auto it = edges.begin(); it != edges.end();)
	{
		if ((it->start == start && it->end == end) || (!oriented && it->start == end && it->end == start))
			it = edges.erase(it);
		else
			it++;
	}
}
void EdgeListGraph::getSuccessors(int vertex, std::vector<std::pair<int, int>>& vertexAdj) const
{
	if (!existsVertex(vertex))
		throw "Invalid vertex!";

	for (auto it = edges.begin(); it != edges.end(); it++)
	{
		if (it->start == vertex)
			vertexAdj.push_back(std::make_pair(it->end, it->weight));
	}
}