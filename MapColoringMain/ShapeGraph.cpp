#include "ShapeGraph.h"

ShapeGraph::ShapeGraph(int n) 
	: num_colors(n)
{
}

ShapeGraph::~ShapeGraph()
{
	for (auto [shape, node] : node_map) {
		delete node;
	}
}

void ShapeGraph::add_shape(MapShape* shape)
{
	Node* node = new Node();
	node_map[shape] = node;
}

void ShapeGraph::create_edge(MapShape* s1, MapShape* s2)
{
	if (node_map.find(s1) == node_map.end()) add_shape(s1);	
	if (node_map.find(s2) == node_map.end()) add_shape(s2);
	Node* n1 = node_map[s1];
	Node* n2 = node_map[s2];
	n1->connect(n2);
	n2->connect(n1);
}

void ShapeGraph::connect_shapes(std::vector<MapShape*>& shapes)
{
	int curr = 0;
	while (curr < shapes.size() - 1) {
		for (int i = curr + 1; i < shapes.size(); i++) {
			create_edge(shapes[curr], shapes[i]);
		}
		curr++;
	}
}

bool ShapeGraph::generate_coloring()
{
	std::vector<int> colors(num_colors);
	for (int i = 0; i < num_colors; i++) {
		colors.push_back(i);
	}
	for (auto [shape, node] : node_map) {
		node->set_colors(colors);
	}
	return true;
}

bool ShapeGraph::generate_helper(Node* node)
{
	if (node->color != -1) return true; // already visited
	if (node->available_colors.size() == 0) return false; // no available colors
	for (int color : node->available_colors) {
		node->color = color;
		for (Node* neighbor : node->neighbors) {
			auto color_ptr = neighbor->available_colors.find(color);
			if (color_ptr != neighbor->available_colors.end()) neighbor->available_colors.erase(color_ptr);
		}
		// call generate_helper recursively
		// add back color if the backtracking is unsuccessful and go to next color, else return true
	}

	return false;
}
