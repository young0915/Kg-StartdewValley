#include "stdafx.h"
#include "Alex.h"

Alex::Alex()
{
}

Alex::~Alex()
{
}

HRESULT Alex::init()
{
	_alex._img = IMAGEMANAGER->findImage("¾Ë·º½º");
	ANIMATIONMANAGER->addAnimation("¸öÂ¯", "¾Ë·º½º", 0, 3, 10, false, true);
	//½ÃÀÛ ¾Ö´Ï¸ÞÀÌ¼Ç ¼³Á¤
	_alex._ani = ANIMATIONMANAGER->findAnimation("¸öÂ¯");
	ANIMATIONMANAGER->resume("¸öÂ¯");
	return S_OK;
}

void Alex::release()
{
}

void Alex::update()
{
}

void Alex::render()
{
	_alex._img->aniRender(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, _alex._ani);
}
