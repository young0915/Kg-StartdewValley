#include "stdafx.h"
#include "mapTool.h"

maptool::maptool() {}

maptool::~maptool() {}

HRESULT maptool::init()
{
	setUp();
	setMaptoolBoard();																//맵툴보드 상태
	return S_OK;
}

void maptool::relaese() {}

void maptool::update()
{
	cameraMove();
	controlMaptoolBoard();													//setMaptoolBoard()의 활성화 상태 

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
	_sampleboard._boardimg->render(CAMERA->getCameraDC(), _sampleboard.boardrc.left, _sampleboard.boardrc.top);

	if (_sampleboard._isopen)
	{
		_sampleboard._button[0]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[0].x, _sampleboard._button[0].y, 0, 0);
		for (int i = 1; i < 3; i++)
		{
			_sampleboard._button[i]._btnimg->render(CAMERA->getCameraDC(), _sampleboard._button[i].x, _sampleboard._button[i].y);
		}
		for (int i = 3; i < 8; i++)
		{
			_sampleboard._button[i]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[i].x, _sampleboard._button[i].y, 0, 0);
		}
		if (PtInRect(&_sampleboard._button[0].rc, m_ptMouse))
		{
			_sampleboard._button[0]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[0].x, _sampleboard._button[0].y, 1, 0);
		}
		for (int i = 3; i < 8; i++)
		{
			if (PtInRect(&_sampleboard._button[i].rc, m_ptMouse))
			{
				_sampleboard._button[i]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[i].x, _sampleboard._button[i].y, 1, 0);
			}
		}
	}
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = 0; i < 8; i++)
		{
			Rectangle(CAMERA->getCameraDC(), _sampleboard._button[i].rc.left, _sampleboard._button[i].rc.top, _sampleboard._button[i].rc.right,_sampleboard._button[i].rc.bottom);
		}
	}

}

void maptool::save()
{
}

void maptool::load()
{
}
//맵툴에 이용할 카메라 이동
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
//
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
//맵툴 아이콘
void maptool::setMaptoolBoard()
{
	_sampleboard._isopen = false;
	_sampleboard._boardimg = IMAGEMANAGER->findImage("도구");
	_sampleboard.x = 850;
	_sampleboard.y = 50;
	_sampleboard.boardrc = RectMakeCenter(_sampleboard.x, _sampleboard.y, _sampleboard._boardimg->getWidth(), _sampleboard._boardimg->getHeight());
}
//setMaptoolBoard()의 활성화 상태 
void maptool::controlMaptoolBoard()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_sampleboard.boardrc, m_ptMouse))
		{
			_sampleboard._isopen = true;
		}
		for (int i = 0; i < 8; i++)
		{
			if (PtInRect(&_sampleboard._button[i].rc, m_ptMouse))
			{
				if (i == 0) _sampleboard._isopen = false;
			}
			if (PtInRect(&_sampleboard._button[3].rc, m_ptMouse))
			{
				_sampleboard._button[3]._btnimg->frameRender(CAMERA->getCameraDC(), WINSIZEX / 2, WINSIZEY / 2, 0, 1);
			}
		}
	}

	if (_sampleboard._isopen)
	{
		_sampleboard._boardimg = IMAGEMANAGER->findImage("맵툴");
		_sampleboard.x = WINSIZEX / 2;
		_sampleboard.y = WINSIZEY / 2;
	}
	else
	{
		_sampleboard._boardimg = IMAGEMANAGER->findImage("도구");
		_sampleboard.x = 850;
		_sampleboard.y = 50;
	}
	//샘플보드 생성
	_sampleboard.boardrc = RectMakeCenter(_sampleboard.x, _sampleboard.y, _sampleboard._boardimg->getWidth(), _sampleboard._boardimg->getHeight());

	if (_sampleboard._isopen)
	{
		_sampleboard._button[0]._btnimg = IMAGEMANAGER->findImage("나가기");
		_sampleboard._button[0].x = 850;
		_sampleboard._button[0].y = 50;
		_sampleboard._button[0].rc = RectMake(_sampleboard._button[0].x, _sampleboard._button[0].y, 26, 26);

		_sampleboard._button[1]._btnimg = IMAGEMANAGER->findImage("맵툴오른쪽");
		_sampleboard._button[1].x = WINSIZEX / 2 + 150;
		_sampleboard._button[1].y = WINSIZEY / 2 + 20;
		_sampleboard._button[1].rc = RectMake(_sampleboard._button[1].x, _sampleboard._button[1].y, _sampleboard._button[1]._btnimg->getWidth(), _sampleboard._button[1]._btnimg->getHeight());

		_sampleboard._button[2]._btnimg = IMAGEMANAGER->findImage("맵툴왼쪽");
		_sampleboard._button[2].x = WINSIZEX / 2 + 350;
		_sampleboard._button[2].y = WINSIZEY / 2 + 20;
		_sampleboard._button[2].rc = RectMake(_sampleboard._button[2].x, _sampleboard._button[2].y, _sampleboard._button[2]._btnimg->getWidth(), _sampleboard._button[2]._btnimg->getHeight());
		
		_sampleboard._button[3]._btnimg = IMAGEMANAGER->findImage("타일");
		_sampleboard._button[3].x = WINSIZEX / 2 + 120;
		_sampleboard._button[3].y = 500;
		_sampleboard._button[3].rc = RectMake(_sampleboard._button[3].x, _sampleboard._button[3].y,100,80);

		_sampleboard._button[4]._btnimg = IMAGEMANAGER->findImage("지우기");
		_sampleboard._button[4].x = WINSIZEX / 2 + 340;
		_sampleboard._button[4].y = 500;
		_sampleboard._button[4].rc = RectMake(_sampleboard._button[4].x, _sampleboard._button[4].y,100,80);


			_sampleboard._button[5]._btnimg = IMAGEMANAGER->findImage("오브젝트");
			_sampleboard._button[5].x = WINSIZEX / 2 + 230;
			_sampleboard._button[5].y = 500;
			_sampleboard._button[5].rc = RectMake(_sampleboard._button[5].x, _sampleboard._button[5].y, 100, 80);

			_sampleboard._button[6]._btnimg = IMAGEMANAGER->findImage("로드");
			_sampleboard._button[6].x = WINSIZEX / 2 + 160;
			_sampleboard._button[6].y = 600;
			_sampleboard._button[6].rc = RectMake(_sampleboard._button[6].x, _sampleboard._button[6].y, 100,80);

			_sampleboard._button[7]._btnimg = IMAGEMANAGER->findImage("저장");
			_sampleboard._button[7].x = WINSIZEX / 2 + 265;
			_sampleboard._button[7].y = 600;
			_sampleboard._button[7].rc = RectMake(_sampleboard._button[7].x, _sampleboard._button[7].y, 100, 80);
	}
}
