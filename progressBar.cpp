#include "stdafx.h"
#include "progressBar.h"
progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(char * frontImage, char * backImage, float x, float y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMakeCenter(x, y, width, height);

	_progressBarFront = new image;
	_progressBarFront->init(frontImage, x, y, width, height, true, RGB(255, 0, 255));

	_progressBarBack = new image;
	_progressBarBack->init(backImage, x, y, width, height, true, RGB(255, 0, 255));


	_height = _progressBarFront->getWidth();

	return S_OK;
}

void progressBar::release()
{
	SAFE_DELETE(_progressBarFront);
	SAFE_DELETE(_progressBarBack);
}

void progressBar::update()
{
}

void progressBar::render()
{
	_progressBarBack->render(CAMERA->getCameraDC(), _rcProgress.left, _y, 0, 0, _progressBarBack->getWidth(), _progressBarBack->getHeight());
	_progressBarFront->render(CAMERA->getCameraDC(), _rcProgress.left, _y + 32, 0, 0, _progressBarBack->getWidth(), _height- 32);
}
void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_height = (currentGauge / maxGauge)* _progressBarBack->getHeight();
}

energybar::energybar()
{
}

energybar::~energybar()
{
}

HRESULT energybar::init(char * frontImage, char * backImage, float x, float y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMakeCenter(x, y, width, height);

	_progressBarFront = new image;
	_progressBarFront->init(frontImage, x, y, width, height, true, RGB(255, 0, 255));

	_progressBarBack = new image;
	_progressBarBack->init(backImage, x, y, width, height, true, RGB(255, 0, 255));


	_height = _progressBarFront->getWidth();

	return S_OK;
}

void energybar::release()
{
	SAFE_DELETE(_progressBarFront);
	SAFE_DELETE(_progressBarBack);
}


void energybar::render()
{
	_progressBarBack->render(CAMERA->getCameraDC(), _rcProgress.left, _y, 0, 0, _progressBarBack->getWidth(), _progressBarBack->getHeight());
	_progressBarFront->render(CAMERA->getCameraDC(), _rcProgress.left, _y + 32, 0, 0, _progressBarBack->getWidth(), _height - 32);
}

void energybar::setGauge(float currentGauge, float maxGauge)
{
	_height = (currentGauge / maxGauge)* _progressBarBack->getHeight();
}
