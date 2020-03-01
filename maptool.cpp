#include "stdafx.h"
#include "mapTool.h"

maptool::maptool() {}

maptool::~maptool() {}

HRESULT maptool::init()
{
	setUp();
	return S_OK;
}

void maptool::relaese() {}

void maptool::update()
{
	cameraMove();
}

void maptool::render()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 100 < _tile[i].x && _tile[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _tile[i].y&& _tile[i].y < CAMERAY + WINSIZEY + 100)
		{
			if (_tile[i].terrain != TERAIN_NONE) continue;

			Rectangle(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].rc.right, _tile[i].rc.bottom);

			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				SetBkMode(getMemDC(), TRANSPARENT);
				////색상
				SetTextColor(getMemDC(), RGB(255, 0, 0));

				char str[128];
				sprintf_s(str, "%d", i);
				TextOut(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, str, strlen(str));
			}
		}
	}
}

void maptool::save()
{
}

void maptool::load()
{
}

void maptool::cameraMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && CAMERA->getCameraCenter().x - WINSIZEX / 2 > 0)
	{
		CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x - 50, CAMERA->getCameraCenter().y));
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && CAMERA->getCameraCenter().x + WINSIZEX / 2 < TILESIZEX)
	{
		CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x + 50, CAMERA->getCameraCenter().y));
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && CAMERA->getCameraCenter().y - WINSIZEY / 2 > 0)
	{
		CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x, CAMERA->getCameraCenter().y - 50));
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && CAMERA->getCameraCenter().y + WINSIZEY / 2 < TILESIZEY)
	{
		CAMERA->setCameraCenter(PointMake(CAMERA->getCameraCenter().x, CAMERA->getCameraCenter().y + 50));
	}
}

void maptool::setUp()
{
	//타일 셋팅
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			SetRect(&_tile[i * TILEX + j].rc, j * TILESIZE, i * TILESIZE, j* TILESIZE + TILESIZE, i * TILESIZE + TILESIZE);
		}
	}

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tile[i].x = _tile[i].rc.left + (_tile[i].rc.right - _tile[i].rc.left) / 2;
		_tile[i].y = _tile[i].rc.top + (_tile[i].rc.bottom - _tile[i].rc.top) / 2;
	}

	mapInit();
}

void maptool::mapInit()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		// 지형 초기설정
		_tile[i].terrain = TERAIN_NONE;

		_tile[i].terrainFrameX = 0;
		_tile[i].terrainFrameY = 0;

		//오브젝트 초기 설정
		_tile[i].obj = OBJ_NONE;

		_tile[i].objFrameX = 0;
		_tile[i].objFrameY = 0;

	}


}
