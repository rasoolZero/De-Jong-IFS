#pragma once
#include <cinder/Cinder.h>
#include <cinder/gl/gl.h>

using namespace ci;

class DeJong
{
public:
	DeJong(float a = 1.4f, float b = -2.3f, float c = 2.4f, float d = -2.1f, int const size = 512);
	void update();
	void draw();
private:
	vec2 point;
	int size;
	float a, b, c, d;

	ci::gl::VertBatchRef vertexArray;
	ci::gl::FboRef frameBuffer;


	vec2 dejong(vec2 point);
};

