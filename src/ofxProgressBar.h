#pragma once

#include "ofMain.h"

// TODO:
// - time-to-complettion estimate

class ofxProgressBar {

public:
    ofxProgressBar();
    ofxProgressBar(int x, int y, int w, int h, int * value, int max);
    ofxProgressBar(int x, int y, int w, int h, int * value, int * max);

    //ofxProgressBar( ofxProgressBar& other );
    
    float progress(); //0.0-1.0
    void draw();
    void hide();
    void show();
    
    void setBackgroundColor(ofColor c);
    void setBarColor(ofColor c);
    void setBorderSize(int b);
    void setLabel(string labelText);
    void setFont(ofTrueTypeFont f);
    void setFontColor(ofColor c);
    void setLabelPosition(ofVec2f p);
    
    // Use these to set the progress and max of the bar
    // directly
    void setProgress(int p);
    void setMax(int m);
    
    int getMax(){ 
        if(useSavedMax){
            return savedMax;
        } else {
            return *max; 
        }
    }
    
private:
    int x,y,w,h;
    int * max;
    int * value;
    int borderSize;
    ofColor backgroundColor;
    ofColor barColor;
    bool hidden;
    
    string label;
    
    int savedMax;
    bool useSavedMax;
    
    ofTrueTypeFont font;
    ofColor fontColor;
    ofVec2f labelPosition;
    
    void init();
};

