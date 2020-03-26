#include "stdafx.h"
#include "stone.h"

stone::stone()
{
}

stone::~stone()
{
}

HRESULT stone::init(const char * imagename, POINT position, int atk)
{
	//_img = imagename;
	IMAGEMANAGER->findImage(imagename);

	return S_OK;
}

void stone::release()
{
}

void stone::update()
{
}

void stone::render()
{
}
