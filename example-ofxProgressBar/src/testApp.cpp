#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    value = 0;
    max = 8000;
    
    // can set the max value as a constant or a pointer 
    // use pointer for a changing max, a la filling/emptying queue, etc.
    progressBar = ofxProgressBar(10, 10, 500, 20, &value, &max);
    
    // alternately use with a fixed max:
    // progressBar = ofxProgressBar(10, 10, 500, 20, &value, 8000);
    go = false;
}

//--------------------------------------------------------------
void testApp::update(){
    if(go && value <= max){
        value += 50;
        max += 40; 
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    progressBar.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'h'){
        progressBar.hide();
    }
    if(key == 's'){
        progressBar.show();
    } if(key == ' '){
        go = !go;
    }
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