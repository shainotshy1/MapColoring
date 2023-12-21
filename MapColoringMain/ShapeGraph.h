#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "MapShape.h"

class Node {
public:
	int color; // If -1 then has not been visited
	std::unordered_set<int> available_colors;
	std::unordered_set<Node*> neighbors;

	Node() {
		color = -1;
	}

	void set_colors(std::vector<int>& colors) {
		available_colors = std::unordered_set<int>(colors.begin(), colors.end());
	}

	void connect(Node* other) {
		neighbors.insert(other);
	}
};

class ShapeGraph
{
private:
	std::unordered_map<MapShape*, Node*> node_map;
	int num_colors;

	void add_shape(MapShape*); // Adds a shape to the graph
	void create_edge(MapShape*, MapShape*); // Creates edge between two nodes
	bool generate_helper(Node*); // Recursive helper for map coloring

public:
	ShapeGraph(int);
	~ShapeGraph();
	void connect_shapes(std::vector<MapShape*>&); // Connects two shapes that share an edge
	bool generate_coloring(); // Returns if coloring was successful
};

