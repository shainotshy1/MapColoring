#pragma once
#include <vector>
#include <unordered_map>
#include "ofColor.h"
#include "Edge.h"
#include "MapGenerator.h"

class MapShape
{
private:
	std::vector<Edge*> edges;
	int color;
public:
	MapShape() {
		color = -1;
	}
	~MapShape() {
		for (Edge* edge : edges) delete edge;
	}
	void add_edge(float x1, float y1, float x2, float y2) {
		Edge* edge = new Edge({x1, y1, x2, y2});
		edges.push_back(edge);
	}
	void set_color(int color) {
		this->color = color;
	}
	void display(std::unordered_map<int, ofColor>&);

	friend class MapGenerator;
};

