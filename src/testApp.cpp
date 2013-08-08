#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofEnableSmoothing();
  ofSetFrameRate(2);
  ofSetVerticalSync(true);
  width = ofGetWidth();
  height = ofGetHeight();

  shader.load("reaction");
  ping.allocate(width,height);
  pong.allocate(width,height);
  iFBO = 0;
  buffers[0] = &ping;
  buffers[1] = &pong;

  passes = 1;
  diffU = 0.25;
  diffV = 0.04;
  f = 0.047;
  k = 0.1;
}

//--------------------------------------------------------------
void testApp::update(){
  for( int i = 0; i < passes ; i++ ){
    //begin shader
    buffers[iFBO]->begin();
    shader.begin();
    setUniforms();
    ofRect(0,0,width,height);
    shader.end();
    buffers[iFBO]->end();

    iFBO = (iFBO + 1) % 2;
  }

}

//--------------------------------------------------------------
void testApp::draw(){
  buffers[iFBO]->draw(0,0,width,height);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
  buffers[iFBO]->begin();
  ofSetColor(255);
  ofCircle(x, y, 10);
  buffers[iFBO]->end();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void testApp::setUniforms(){ 
  shader.setUniformTexture("backbuffer", buffers[0]->getTextureReference(),0);
  shader.setUniformTexture("tex0", buffers[1]->getTextureReference(),1);
  shader.setUniform1f( "diffU", (float)diffU);
  shader.setUniform1f( "diffV", (float)diffV);
  shader.setUniform1f( "f", (float)f );
  shader.setUniform1f( "k", (float)k );
}
