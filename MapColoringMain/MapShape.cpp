#include "MapShape.h"
#include <ofGraphics.h>
#include <iostream>

void MapShape::display(std::unordered_map<int, ofColor>& m)
{
	assert(m.find(color) != m.end());
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofSetColor(m[color]);
	ofBeginShape();
	for (int i = 0; i < edges.size(); i++) {
		ofVertex(edges[i]->x1, edges[i]->y1);
	}
	ofEndShape();
}