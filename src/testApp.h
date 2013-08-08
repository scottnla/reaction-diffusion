#pragma once

#include "ofMain.h"
#include "tweener.h"
#include "ofxSwapBuffer.h"

class testApp : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  void setUniforms();

 private:
  ofShader shader;
  ofFbo ping, pong;
  ofFbo * buffers[2];
  int iFBO;
  float width, height;
  int passes;
  float diffU, diffV, f, k;  
};
