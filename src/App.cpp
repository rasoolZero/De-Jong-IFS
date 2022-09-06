#include "App.h"

void De_Jong_IFSApp::setup()
{
	ci::app::setWindowSize(size, size);
	ci::app::setFrameRate(500);
	a = 1.4f, b = -2.3f, c = 2.4f, d = -2.1f;
	dj = DeJong(a, b, c, d, size,10000,{0.9f,0.9f, 0.9f, 0.01f});
	timer.start();
	framesPassed = 0;
	ci::app::getElapsedFrames();
	frameCounterString = "fps : ";
	setupParams();
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
	paramInterface->draw();
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

void De_Jong_IFSApp::setupParams()
{
	using namespace std::placeholders;

	paramInterface = ci::params::InterfaceGl::create("De Jong IFS Controls", { size / 2,size });

	paramInterface->addParam<ColorA>("color", std::bind(&DeJong::setColor, &dj, _1), std::bind(&DeJong::getColor, &dj));
	paramInterface->addParam<int>("iterations per frame", std::bind(&DeJong::setIterations, &dj, _1), std::bind(&DeJong::getIterations, &dj)).min(500);
	paramInterface->addSeparator();
	paramInterface->addParam<float>("A", std::bind(&DeJong::setA, &dj, _1), std::bind(&DeJong::getA, &dj));
	paramInterface->addParam<float>("B", std::bind(&DeJong::setB, &dj, _1), std::bind(&DeJong::getB, &dj));
	paramInterface->addParam<float>("C", std::bind(&DeJong::setC, &dj, _1), std::bind(&DeJong::getC, &dj));
	paramInterface->addParam<float>("D", std::bind(&DeJong::setD, &dj, _1), std::bind(&DeJong::getD, &dj));




}
