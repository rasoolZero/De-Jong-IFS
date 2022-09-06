#pragma once
#include <cinder/Cinder.h>
#include <cinder/gl/gl.h>

using namespace ci;

class DeJong
{
public:
	DeJong(float a = 1.4f, float b = -2.3f, float c = 2.4f, float d = -2.1f, int const size = 512, int const iterationsPerFrame = 10000, ci::ColorA color = {0.9f,0.9f,0.9f,0.1f});
	void update();
	void draw();
	float getA() { return a; }
	float getB() { return b; }
	float getC() { return c; }
	float getD() { return d; }

	void setA(float input) { a = input; setupFramebuffer(); }
	void setB(float input) { b = input; setupFramebuffer(); }
	void setC(float input) { c = input; setupFramebuffer(); }
	void setD(float input) { d = input; setupFramebuffer(); }

	ci::ColorA getColor() { return color; }
	void setColor(ci::ColorA input) { color = input; setupFramebuffer(); }

	int getIterations() { return iterationsPerFrame; }
	void setIterations(int input) { iterationsPerFrame = input; }

private:
	vec2 point;
	int size;
	int iterationsPerFrame;
	ci::ColorA color;
	float a, b, c, d;

	ci::gl::VertBatchRef vertexArray;
	ci::gl::FboRef frameBuffer;

	void setupFramebuffer();

	void drawVertexarray();
	void drawFramebuffer();

	vec2 dejong(vec2 point);
};

