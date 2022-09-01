#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class De_Jong_IFSApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void De_Jong_IFSApp::setup()
{
}

void De_Jong_IFSApp::mouseDown( MouseEvent event )
{
}

void De_Jong_IFSApp::update()
{
}

void De_Jong_IFSApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( De_Jong_IFSApp, RendererGl )
