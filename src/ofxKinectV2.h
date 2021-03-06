//
//  ofxKinectV2.h
//  kinectExample
//
//  Created by Theodore Watson on 6/23/14.
//
//

#pragma once

#include "ofProtonect.h"
#include "ofMain.h"

class ofxKinectV2 : public ofThread{

    public:
    
        struct KinectDeviceInfo{
            string serial;
            int deviceId;   //if you have the same devices plugged in device 0 will always be the same Kinect
            int freenectId; //don't use this one - this is the index given by freenect2 - but this can change based on order device is plugged in
        };

        ofxKinectV2();
        ~ofxKinectV2(); 
        
        //for some reason these can't be static - so you need to make a tmp object to query them
        vector <KinectDeviceInfo> getDeviceList();
        unsigned int getNumDevices();
    
        bool open(string serial);
        bool open(unsigned int deviceId = 0);
        void update();
        void close();
    
        bool isFrameNew();
    
        ofPoint getWorldCoordinateAt(int x, int y);
        vector <ofPoint> getWorldCoordinates();

        float getDistanceAt(const int x, const int y);
        ofColor getColorAt(const int x, const int y);

        ofPixels getDepthPixels();
        ofPixels getRgbPixels();
        ofFloatPixels getRawDepthPixels();
    
        ofParameterGroup params;
        ofParameter <float> minDistance;
        ofParameter <float> maxDistance;

        static const int width = 512;
        static const int height = 424;
        static const int maxDepth = 4500;
        static const int rgbWidth = 1920;
        static const int rgbHeight = 1080;

    protected:
        void threadedFunction();

        ofPixels rgbPix;
        ofPixels depthPix;
        ofFloatPixels rawDepthPixels;
    
        bool bNewBuffer;
        bool bNewFrame;
        bool bOpened;
    
        ofProtonect protonect; 
    
        ofPixels rgbPixelsBack;
        ofPixels rgbPixelsFront;
        ofFloatPixels depthPixelsBack;
        ofFloatPixels depthPixelsFront;
    
        vector <ofPoint> pointCloudFront;
        vector <ofPoint> pointCloudBack;
        vector <ofPoint> pointCloud;

        int lastFrameNo; 

    private:

};