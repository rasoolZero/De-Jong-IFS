#include "App.h"

void De_Jong_IFSApp::setup()
{
	ci::app::setWindowSize(size, size);
	a = 1.4f, b = -2.3f, c = 2.4f, d = -2.1f;
	dj = DeJong(a, b, c, d, size);
}

void De_Jong_IFSApp::update()
{
	dj.update();
}

void De_Jong_IFSApp::draw()
{
	dj.draw();
}
