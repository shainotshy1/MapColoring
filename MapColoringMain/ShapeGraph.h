#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "MapShape.h"

class Node {
public:
	int color; // If -1 then has not been visited
	std::unordered_set<int> available_colors;
	std::vector<Node*> neighbors;

	Node() {
		color = -1;
	}

	void set_colors(std::vector<int>& colors) {
		available_colors = std::unordered_set<int>(colors.begin(), colors.end());
	}

	void connect(Node* other) {
		neighbors.push_back(other);
	}
};

class ShapeGraph
{
private:
	std::unordered_map<MapShape*, Node*> node_map;
	int num_colors;

	ShapeGraph(int);
	~ShapeGraph();
	void add_shape(MapShape*);
	void create_edge(MapShape*, MapShape*);
	bool generate_helper(Node*);
public:
	void connect_shapes(std::vector<MapShape*>&);
	bool generate_coloring(); // returns if coloring was successful
};

