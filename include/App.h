#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;

class De_Jong_IFSApp : public app::App
{
public:
	void setup() override;
	void update() override;
	void draw() override;
private:
	vec2 point;
	float a, b, c, d;

	ci::gl::VertBatchRef vertexArray;
	ci::gl::FboRef frameBuffer;
	int const size = 512;

	vec2 dejong(vec2 point);
};

