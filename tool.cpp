#include "stdafx.h"
#include "tool.h"

//tool::tool()
//{
//}
//
//tool::~tool()
//{
//}
//
//HRESULT tool::init()
//{
//	_ax._img = IMAGEMANAGER->findImage("µµ³¢");
//	_ax._tdir = T_NONE;
//	_ax.count = 0;
//	_ax.index = 0;
//	return S_OK;
//}
//
//void tool::release()
//{
//}
//
//
//void tool::update()
//{
//	
//}
//void tool::axemove(int x, int y, TOOLDIR _dir)
//{
//	_ax.x = x;
//	switch (_ax._tdir)
//	{
//	case T_DOWN:
//		_ax.count++;
//		_ax._img->setFrameY(0);
//		if (_ax.count % 5 == 0)
//		{
//			_ax.count = 0;
//			_ax.index++;
//			if (_ax.index >= _ax._img->getMaxFrameX())
//			{
//				_ax.index = 0;
//			}
//		}
//		_ax._img->setFrameX(_ax.index);
//		break;
//	case T_RIGHT:
//		_ax.count++;
//		_ax._img->setFrameY(1);
//		if (_ax.count % 5 == 0)
//		{
//			_ax.count = 0;
//			_ax.index++;
//			if (_ax.index >= _ax._img->getMaxFrameX())
//			{
//				_ax.index = 0;
//			}
//		}
//		_ax._img->setFrameX(_ax.index);
//		break;
//	case T_LEFT:
//		_ax.count++;
//		_ax._img->setFrameY(2);
//		if (_ax.count % 5 == 0)
//		{
//			_ax.count = 0;
//			_ax.index++;
//			if (_ax.index >= _ax._img->getMaxFrameX())
//			{
//				_ax.index = 0;
//			}
//		}
//		_ax._img->setFrameX(_ax.index);
//		break;
//	}
//}
//void tool::pickmove(int x, int y, TOOLDIR _dir)
//{
//}
//void tool::homiemove(int x, int y, TOOLDIR _dir)
//{
//}
//void tool::watercanmove(int x, int y, TOOLDIR _dir)
//{
//}
//
//
//void tool::render()
//{
//	_ax._img->frameRender(CAMERA->getCameraDC(), _ax.x, _ax.y, _ax._img->getFrameWidth(), _ax._img->getFrameHeight());
//}