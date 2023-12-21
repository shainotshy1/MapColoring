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
	if (shapes.size() == 0) return;
	if (shapes.size() == 1) add_shape(shapes[0]);
	int curr = 0;
	while (curr < shapes.size()) {
		for (int i = curr + 1; i < shapes.size(); i++) {
			create_edge(shapes[curr], shapes[i]);
		}
		curr++;
	}
}

bool ShapeGraph::generate_coloring()
{
	if (node_map.size() == 0) return true;
	std::vector<int> colors(num_colors);
	for (int i = 0; i < num_colors; i++) {
		colors.push_back(i);
	}
	for (auto [shape, node] : node_map) {
		node->set_colors(colors);
	}
	auto [_, node] = *(node_map.begin());

	bool status = generate_helper(node);
	for (auto [shape, node] : node_map) {
		shape->set_color(node->color);
	}
}

bool ShapeGraph::generate_helper(Node* node)
{
	if (node->color != -1) return true; // already visited
	if (node->available_colors.size() == 0) return false; // no available colors

	for (int color : node->available_colors) {
		// Set color of current node
		node->color = color;

		// Remove set color from available colors of neighbors
		std::vector<Node*> marked;
		for (Node* neighbor : node->neighbors) {
			auto color_ptr = neighbor->available_colors.find(color);
			if (color_ptr != neighbor->available_colors.end()) {
				neighbor->available_colors.erase(color_ptr);
				marked.push_back(neighbor);
			}
		}

		bool status = true;
		// Call generate_helper recursively on neighbors
		for (Node* neighbor : node->neighbors) {
			if (!generate_helper(neighbor)) {
				status = false;
				break;
			}
		}

		// Add back color if the backtracking is unsuccessful and go to next color, else return true
		for (Node* neighbor : marked) {
			neighbor->available_colors.insert(color);
		}
		
		// Check if coloring is complete, else try next color for node
		if (status) {
			return true;
		}
	}

	// Make color -1 to signify unvisited node
	node->color = -1;
	return false;
}
