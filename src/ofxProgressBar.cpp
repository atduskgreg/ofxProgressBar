#include "ofxProgressBar.h"

ofxProgressBar::ofxProgressBar(){};

ofxProgressBar::ofxProgressBar(int _x, int _y, int _w, int _h, int * _value, int _max){
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    value = _value;
    savedMax = _max;
    useSavedMax = true;
    
    init();
}

ofxProgressBar::ofxProgressBar(int _x, int _y, int _w, int _h, int * _value, int * _max){
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    value = _value;
    max = _max;
    useSavedMax = false;
    
    init();
}

void ofxProgressBar::init(){
    backgroundColor = ofColor(125);
    barColor = ofColor(90);
    fontColor = ofColor(90);
    
    labelPosition.x = x+3;
    labelPosition.y = y-10;
    
    borderSize = 1;
    hidden = false;
    label = "";
}

float ofxProgressBar::progress(){
    if(useSavedMax){
        return (float)(*value)/(float)savedMax;
    } else {
        return (float)(*value)/(float)(*max);    
    }
}

void ofxProgressBar::hide(){
    hidden = true;
}

void ofxProgressBar::show(){
    hidden = false;
}

void ofxProgressBar::setBackgroundColor(ofColor c){
    backgroundColor = c;
}

void ofxProgressBar::setBarColor(ofColor c){
    barColor = c;
}

void ofxProgressBar::setBorderSize(int b){
    borderSize = b;
}

void ofxProgressBar::setLabel(string labelText){
    cout << labelText << endl;
    label = labelText;
}

void ofxProgressBar::setLabelPosition(ofVec2f p){
    labelPosition = p;
}

void ofxProgressBar::setFont(ofTrueTypeFont f){
    font = f;
}

void ofxProgressBar::setFontColor(ofColor c){
    fontColor = c;
}

void ofxProgressBar::setProgress(int p){
    *value = p;
}

void ofxProgressBar::setMax(int m){
    if(useSavedMax){
        savedMax = m;
    } else {
        *max = m;    
    }
}

void ofxProgressBar::draw(){
    if(!hidden){
        ofPushStyle();
        ofSetColor(fontColor);
        font.drawString(label, labelPosition.x, labelPosition.y);
        
        ofSetColor(backgroundColor);
        ofFill();
        ofRect(x, y, w, h);
        
        ofSetColor(barColor);
        float width = ofClamp(progress() * (w-(2*borderSize)), 0, w-(2*borderSize));
        ofRect(x+borderSize, y+borderSize, width, h-(2*borderSize));
        ofPopStyle();
    }
}


