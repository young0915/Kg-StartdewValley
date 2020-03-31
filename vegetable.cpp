#include "stdafx.h"
#include "vegetable.h"

vegetable::vegetable()
{
}

vegetable::~vegetable()
{
}

HRESULT vegetable::init(const char * imagename, POINT postion, VEGETABLESTATE vegstate, bool isgrowup)
{
	count = 0;
	index = 0;
	_vegetableimg = IMAGEMANAGER->findImage(imagename);
	rc = RectMakeCenter(postion.x, postion.y, _vegetableimg->getFrameWidth(), _vegetableimg->getFrameHeight());
	_isgrow = vegstate;
	_isgrowup = isgrowup; 
	_item = ITEMMANAGER->additem("감자");
	return S_OK;
}

void vegetable::release(){}

void vegetable::update()
{
	_item.update();
	vegatablegrow();
}

void vegetable::render()
{
	_item.render();
	if (KEYMANAGER->isToggleKey('L'))
	{ 
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	}
	_vegetableimg->frameRender(getMemDC(), rc.left, rc.top);
}

void vegetable::vegatablegrow()
{
	if (!_isgrow)
	{
		count++;
		_vegetableimg->setFrameY(0);
		if (count % 5 == 0)
		{
			count = 0;
			index++;
			if (index >= _vegetableimg->getMaxFrameX())
			{
				index = 8;
				//_isgrow = GROWING;																				//이때  vegetableManager에서 아이템 출력
			}
		}
		_vegetableimg->setFrameX(index);
	}
}

