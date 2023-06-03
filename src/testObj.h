#pragma once
#include "ofMain.h"
#include "ofxFilikaInteractiveContainer.h"


class testObj : public ofxFilikaInteractiveContainer {
private:
	float			sFac;
	ofImage			img;
	string imgSrc;
public:
	ofEvent<string> BUTTON_CLICKED;

	void setup(string _imgSrc) {
		// Override setup function
		enableMouseEvents();	// to enable mouse events
		enableTouchEvents();	// to enable touch events

		// you should set your display object's screen coordinates and size
		// otherwise interaction doesn't work.
		// Keep in mind that objects are aligned according to top-left corner
		// But, they are scaled and rotated from center of the container

		imgSrc = _imgSrc;
		img.load(imgSrc);

		this->x = 0;
		this->y = 0;
		this->width = img.getWidth();
		this->height = img.getHeight();
	}

	void draw() {
		ofPushMatrix();
		
		ofTranslate(this->x + this->width * 0.5, this->y + this->height*0.5);
		ofScale(1 + sFac, 1 + sFac);
		ofTranslate(-this->width*0.5, -this->height*0.5);
		//ofDrawRectangle(0,0, width, height);
		
		img.draw(0,0);
		
		ofPopMatrix();
		


		// Override draw function
		//drawDebug();			// to enable screen debug view of your container
	}

	virtual void onPress(int x, int y, int button) {
		sFac = -0.1;
		//printf("MyTestObject::onPress(x: %i, y: %i, button: %i)\n", x, y, button);
	}

	virtual void onRelease(int x, int y, int button) {
		sFac = 0;
		//printf("MyTestObject::onRelease(x: %i, y: %i, button: %i)\n", x, y, button);
		ofNotifyEvent(BUTTON_CLICKED, imgSrc);
	}

	virtual void onReleaseOutside(int x, int y, int button) {
		sFac = 0;
		//printf("MyTestObject::onReleaseOutside(x: %i, y: %i, button: %i)\n", x, y, button);
		ofNotifyEvent(BUTTON_CLICKED, imgSrc);
	}
};