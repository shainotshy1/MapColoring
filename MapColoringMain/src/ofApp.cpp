#include "ofApp.h"
#include "../MapGenerator.h"
#include <unordered_map>

//--------------------------------------------------------------
void ofApp::setup(){
	MapGenerator generator;
	num_colors = 4;
	MapShape* shape = new MapShape();
	shape->add_edge(50, 50, 50, 950);
	shape->add_edge(50, 950, 950, 950);
	shape->add_edge(950, 950, 950, 50);
	shape->add_edge(950, 50, 50, 50);
	shapes.push_back(shape);
	generator.generate(shapes, num_colors);

	color_map[0] = ofColor(255, 255, 255);
	color_map[1] = ofColor(100, 100, 255);
	color_map[2] = ofColor(255, 100, 100);
	color_map[3] = ofColor(100, 255, 100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	for (MapShape* shape : shapes) {
		shape->display(color_map);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
