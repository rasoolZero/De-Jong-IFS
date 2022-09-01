#include "App.h"

void De_Jong_IFSApp::setup()
{
	a = 1.4f, b = -2.3f, c = 2.4f, d = -2.1f;
	vertexArray = ci::gl::VertBatch::create(GL_POINTS);
	gl::Fbo::Format hdrFormat;
	hdrFormat.setColorTextureFormat(gl::Texture::Format().internalFormat(GL_RGBA32F));
	hdrFormat.setSamples(4);
	frameBuffer = ci::gl::Fbo::create(size, size, hdrFormat);
	frameBuffer->bindFramebuffer();
	gl::clear(ColorA(0.0, 0.0, 0.0, 0.0));
	frameBuffer->unbindFramebuffer();
	point = vec2(0, 0);
	app::App::setWindowSize(size, size);
	gl::clear();
}

void De_Jong_IFSApp::update()
{
	vertexArray->clear();
	for (int i = 0; i < 500; i++) {
		point = dejong(point);
		vertexArray->color(0.9, 0.9, 0.9,0.2);
		vertexArray->vertex(vec2(point.x * size / 4, point.y * size / 4));
	}
}

void De_Jong_IFSApp::draw()
{
	{
		frameBuffer->bindFramebuffer();
		auto blending1 = gl::ScopedBlend(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		gl::pushMatrices();
		gl::translate(size / 2, size / 2);
		vertexArray->draw();
		gl::popMatrices();
		frameBuffer->unbindFramebuffer();
	}
	{
		gl::clear();
		auto blending2 = gl::ScopedBlend(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		gl::draw(frameBuffer->getColorTexture());
	}
}

vec2 De_Jong_IFSApp::dejong(vec2 point)
{
	float newX = sin(a * point.y) - cos(b * point.x);
	float newY = sin(c * point.x) - cos(d * point.y);
	return vec2(newX,newY);
}
