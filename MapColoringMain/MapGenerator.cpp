#include <unordered_set>
#include "MapGenerator.h"
#include "ofApp.h"
#include "ShapeGraph.h"
#include "Edge.h"
#include "MapShape.h"

void MapGenerator::generate(std::vector<MapShape*>& shapes, int num_colors)
{
	std::unordered_map<Edge*, std::vector<MapShape*>> m;
	ShapeGraph sg(num_colors);
	for (MapShape* shape : shapes) {
		for (Edge* edge : shape->edges) {
			m[edge].push_back(shape);
		}
	}
	for (auto [edge, shapes] : m) {
		sg.connect_shapes(shapes);
	}
	sg.generate_coloring();
}
