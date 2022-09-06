#include "App.h"

void De_Jong_IFSApp::setup()
{
	ci::app::setWindowSize(size, size);
	ci::app::setFrameRate(500);
	a = 1.4f, b = -2.3f, c = 2.4f, d = -2.1f;
	dj = DeJong(a, b, c, d, size);
	timer.start();
	framesPassed = 0;
	ci::app::getElapsedFrames();
	frameCounterString = "fps : ";
}

void De_Jong_IFSApp::update()
{
	dj.update();
	updateFPS();
}

void De_Jong_IFSApp::draw()
{
	dj.draw();

	ci::gl::drawString(frameCounterString, {0,0});
}

void De_Jong_IFSApp::updateFPS()
{
	if (timer.getSeconds() >= 1.0) {
		size_t elapsedFrames = ci::app::getElapsedFrames();
		fps = elapsedFrames - framesPassed;
		framesPassed = elapsedFrames;
		frameCounterString = "fps : " + std::to_string(fps);
		timer.start();
	}
}
