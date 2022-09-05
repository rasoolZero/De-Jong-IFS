#include "App.h"

void De_Jong_IFSApp::setup()
{
	ci::app::setWindowSize(size, size);
	ci::app::setFrameRate(500);
	a = 1.4f, b = -2.3f, c = 2.4f, d = -2.1f;
	dj = DeJong(a, b, c, d, size);
	timer.start();
	framesPassed = 0;
}

void De_Jong_IFSApp::update()
{
	dj.update();
}

void De_Jong_IFSApp::draw()
{
	dj.draw();

	ci::gl::drawString(frameCounterString, {0,0});
}

void De_Jong_IFSApp::updateFPS()
{
	if (timer.getSeconds() >= 1.0) {
		fps = ci::app::getElapsedFrames() - framesPassed;
		framesPassed = ci::app::getElapsedFrames();
		frameCounterString = "fps : " + std::to_string(fps);
		timer.stop();
		timer.start();
	}
}
