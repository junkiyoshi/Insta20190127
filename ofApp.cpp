#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(5);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	this->draw_torus(200, 60, 7, 2);

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_torus(float R, float r, float p, float q) {

	ofColor color;
	for (int t_start = ofGetFrameNum() * 0.75; t_start < ofGetFrameNum() * 0.75 + 360; t_start += 30) {

		ofSetColor(39);
		for (int t = t_start; t <= t_start + 20; t++) {

			ofDrawLine(this->make_point(R, r, t, p, q), this->make_point(R, r, t + 1, p, q));
		}

		color.setHsb(ofMap(t_start % 360, 0, 360, 0, 255), 255, 255);
		ofSetColor(color);

		ofDrawSphere(this->make_point(R, r, t_start + 25, p, q), 10);
	}
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float t, float p, float q) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.39
	float x = (R + r * cos(p * t * DEG_TO_RAD)) * cos(q * t * DEG_TO_RAD);
	float y = (R + r * cos(p * t * DEG_TO_RAD)) * sin(q * t * DEG_TO_RAD);
	float z = r * sin(p * t * DEG_TO_RAD);

	return glm::vec3(x, y, z);
}
//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}