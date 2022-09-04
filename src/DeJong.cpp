#include "DeJong.h"

DeJong::DeJong(float a, float b, float c, float d, int const size)
	: size(size)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;


	point = vec2(0, 0);
	vertexArray = ci::gl::VertBatch::create(GL_POINTS);
	setupFramebuffer();
}

void DeJong::update()
{
	vertexArray->clear();
	for (int i = 0; i < 500; i++) {
		point = dejong(point);
		vertexArray->color(0.9, 0.9, 0.9, 0.2);
		vertexArray->vertex(vec2(point.x * size / 4, point.y * size / 4));
	}
}

void DeJong::draw()
{
	drawVertexarray();
	drawFramebuffer();
}

void DeJong::setupFramebuffer()
{
	gl::Fbo::Format hdrFormat;
	hdrFormat.setSamples(4);
	frameBuffer = ci::gl::Fbo::create(size, size, hdrFormat);
	frameBuffer->bindFramebuffer();
	gl::clear(ColorA(0.0, 0.0, 0.0, 0.0));
	frameBuffer->unbindFramebuffer();
}

void DeJong::drawVertexarray()
{
	frameBuffer->bindFramebuffer();
	auto blending = gl::ScopedBlend(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	auto scopedMatrix = gl::ScopedMatrices();
	gl::translate(size / 2, size / 2);
	vertexArray->draw();
	frameBuffer->unbindFramebuffer();
}

void DeJong::drawFramebuffer()
{
	gl::clear();
	auto blending = gl::ScopedBlend(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	gl::draw(frameBuffer->getColorTexture());
}

vec2 DeJong::dejong(vec2 point)
{
	float newX = sin(a * point.y) - cos(b * point.x);
	float newY = sin(c * point.x) - cos(d * point.y);
	return vec2(newX, newY);
}
