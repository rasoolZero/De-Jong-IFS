#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "DeJong.h"

using namespace ci;

class De_Jong_IFSApp : public app::App
{
public:
	void setup() override;
	void update() override;
	void draw() override;
private:

	DeJong dj;

	float a, b, c, d;
	int const size = 512;

};

