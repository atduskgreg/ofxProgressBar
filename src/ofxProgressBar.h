#pragma once

#include "ofMain.h"

class ofxProgressBar {

public:
    ofxProgressBar();
    ofxProgressBar(int x, int y, int w, int h, int * value, int max);
    ofxProgressBar(int x, int y, int w, int h, int * value, int * max);

    float progress(); //0.0-1.0
    void draw();
    void hide();
    void show();
    
    void setBackgroundColor(ofColor c);
    void setBarColor(ofColor c);
    void setBorderSize(int b);
    
private:
    int x,y,w,h;
    int * max;
    int * value;
    int borderSize;
    ofColor backgroundColor;
    ofColor barColor;
    bool hidden;
    
    int savedMax;
    bool useSavedMax;
    
    void init();
};

