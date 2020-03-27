#include "stdafx.h"
#include "stone.h"

stone::stone()
{
}

stone::~stone()
{
}

HRESULT stone::init()
{
	return S_OK;
}

HRESULT stone::init(const char* imagename, STONE_TYPE tone, STONE_STATE sstate, POINT position, int atk)
{
	_tone = tone;
	_sstate = sstate;
	_img = IMAGEMANAGER->findImage(imagename);
	_rc = RectMakeCenter(position.x, position.y, _img->getWidth(), _img->getHeight());
	_atk = atk;

	switch (_tone)
	{
	case ETC_STONE:
		_item = ITEMMANAGER->additem("��");
		break;
	case RUBY_STONE:
		_item = ITEMMANAGER->additem("���");
		break;
	case GRASS_TYPE:
		_item = ITEMMANAGER->additem("����");
		break;
	case TREE_TYPE:
		_item = ITEMMANAGER->additem("����");
		break;
	}
	
	return S_OK;
}

void stone::release(){}

void stone::update()
{
	_item.update();
}

void stone::render()
{
	if (KEYMANAGER->isToggleKey('P'))
	{
		//��
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	}
	_img->render(getMemDC(), _rc.left, _rc.top);
	_item.render();					//�������� ����
}
