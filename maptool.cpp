#include "stdafx.h"
#include "maptool.h"

maptool::maptool()
{
}

maptool::~maptool()
{
}

HRESULT maptool::init()
{
	setUp();																	//타일 셋팅하는 함수
	setsampleboard();												//샘플보드
	page = 0;																//이미지 초기화
	mouse = false;

	//sampleRc()안에 넣을 이미지
	for (int i = 0; i < 36; i++)
	{
		_springfloor[i] = new image;
		_springfloor[i]->init("images/맵툴/maptool_tile1_spring.bmp", 576, 576, 12, 12, true, RGB(255, 0, 255));

		_mountainsimg[i] = new image;
		_mountainsimg[i]->init("images/맵툴/maptool_tile2_spring.bmp", 576, 576, 12, 12, true, RGB(255, 0, 255));

		_mine[i] = new image;
		_mine[i]->init("images/맵툴/mine.bmp", 800, 800, 16, 16, true, RGB(255, 0, 255));
	}
	m_ptMouse.x = CAMERA->getCameraXY().x + m_ptMouse.x;
	m_ptMouse.y = CAMERA->getCameraXY().y + m_ptMouse.y;
	return S_OK;
}

void maptool::release() {}

void maptool::update()
{
	m_ptMouse.x = CAMERA->getCameraXY().x + m_ptMouse.x;
	m_ptMouse.y = CAMERA->getCameraXY().y + m_ptMouse.y;
	if (PtInRect(&_sampleboard.boardrc, m_ptMouse))
	{
		mouse = true;
	}
	else
	{
		mouse = false;
	}

	CameraMove();
	sampleboardcontrol();
}

void maptool::render()
{
	//타일
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 100 < _tile[i].x && _tile[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _tile[i].y&& _tile[i].y < CAMERAY + WINSIZEY + 100)
		{

			if (_tile[i].terrain == TERAIN_NONE) Rectangle(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].rc.right, _tile[i].rc.bottom);
			else  IMAGEMANAGER->frameRender("봄바닥", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainFrameX, _tile[i].terrainFrameY);
			/*_springfloor[i]->frameRender(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainFrameX, _tile[i].terrainFrameY);*/


			//else _springfloor[i]->frameRender("봄바닥", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainFrameX, _tile[i].terrainFrameY);
			if (_tile[i].obj == OBJ_NONE) continue;

			IMAGEMANAGER->frameRender("봄바닥", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].objFrameX, _tile[i].objFrameY);
		}
	}
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 100 < _tile[i].x && _tile[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _tile[i].y&& _tile[i].y < CAMERAY + WINSIZEY + 100)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				SetBkMode(getMemDC(), TRANSPARENT);
				//색상
				SetTextColor(getMemDC(), RGB(255, 0, 0));

				char str[128];
				sprintf_s(str, "%d", i);
				TextOut(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, str, strlen(str));
			}
		}
	}


	//샘플 보드 아이콘 또는 샘플보드 출력
	_sampleboard._boardimg->render(CAMERA->getCameraDC(), _sampleboard.x, _sampleboard.y);
	//샘플보드 활성화이면
	if (_sampleboard._isopen)
	{
		//타일 UI
		_sampleboard._button[0]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[0].x, _sampleboard._button[0].y, 0, 0);
		//페이지 넘기기
		_sampleboard._button[1]._btnimg->render(CAMERA->getCameraDC(), _sampleboard._button[1].x, _sampleboard._button[1].y);
		_sampleboard._button[2]._btnimg->render(CAMERA->getCameraDC(), _sampleboard._button[2].x, _sampleboard._button[2].y);
		if (PtInRect(&_sampleboard._button[0].rc, m_ptMouse)) { _sampleboard._button[0]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[0].x, _sampleboard._button[0].y, 1, 0); }								//나가기버튼을 눌렀을 때 일어나는 효과
		//타일, 오브젝트, 지우기, 저장, 로드 버튼
		for (int i = 0; i < 5; i++)
		{
			_samplebutton[i]._btnimg->frameRender(CAMERA->getCameraDC(), _samplebutton[i].x, _samplebutton[i].y, 0, 0);
			if (PtInRect(&_samplebutton[i].rc, m_ptMouse)) { _samplebutton[i]._btnimg->frameRender(CAMERA->getCameraDC(), _samplebutton[i].x, _samplebutton[i].y, 1, 0); } //버튼을 누르면 일어나는 효과
		}
		//맵
		for (int i = 0; i < 36; i++)
		{
			Rectangle(CAMERA->getCameraDC(), rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);
			if (page >= 0 && page <= 3)
			{
				_springfloor[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);										//샘플 배치
			}
			if (page >= 4 && page <= 8)
			{
				_mountainsimg[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);										//샘플 배치
			}
			if (page >= 9 && page <= 12)
			{
				_mine[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);
			}
		}

	}//_sampleboard._isopen true


}

//세이브
void maptool::save()
{
	for (int i = 0; i < 36; i++)
	{
		if (PtInRect(&_samplebutton[3].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			HANDLE file;
			DWORD write;
			int arrNum;
			arrNum = i;
			char save[128];
			wsprintf(save, "save/맵%d.map", arrNum + 1);

			for (int i = 0; i < TILEX* TILEY; i++)
			{
				_temp[i] = _tile[i];
			}

			file = CreateFile
			(																									//생성할 파일 또는 열 장치나 파일 이름
				save,																						//파일이나 장치를 만들거나 열때 사용할 권한
				GENERIC_WRITE,																	// 파일 공유모드 입력
				0,																								//파일 또는 장치를 열때 보안 및 특성
				NULL,																						//파일이나 장치를 열때 취할 행동
				CREATE_ALWAYS,																	//파일이나 장치를 열때 갖게 될 특성
				FILE_ATTRIBUTE_NORMAL,												//만들어질 파일이 갖게 될 특성 확장 특성에 대한 정보
				NULL);

			WriteFile(file, _temp, sizeof(tagTile)*TILEX*TILEY, &write, NULL);
			CloseHandle(file);
		}
	}
}
//로드
void maptool::load()
{
	for (int i = 0; i < 36; i++)
	{
		if (PtInRect(&_samplebutton[4].rc, m_ptMouse))
		{
			HANDLE file;
			DWORD read;
			int arrNum;
			arrNum = i;
			char save[128];
			wsprintf(save, "save/맵%d.map", arrNum + 1);

			file = CreateFile
			(save,										//생성할 파일 또는 열 장치나 파일이름
				GENERIC_READ,				//파일이나 장치를 만들거나 열때 사용할 권한
				0,											//파일 공유 모드 입력
				NULL,									// 파일 또는 장치를 열 때 보안 및 행동
				OPEN_EXISTING,				//파일이나 장치를 열때 취할 행동
				FILE_ATTRIBUTE_NORMAL,	//파일이나 장치를 열때 갖게 될 특성
				NULL);											//만들어질  파일이 갖게 될 특성 확장 특성에 대한 정보 

			ReadFile(file, _temp, sizeof(tagTile)*TILEX*TILEY, &read, NULL);
			CloseHandle(file);
		}
	}
}
//맵툴에 이용할 카메라 이동
void maptool::CameraMove()
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
//타일 셋팅하는 함수
void maptool::setUp()
{
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

	mapinit();
}

// 샘플북 초기화 설정
void maptool::mapinit()
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
//샘플 타일 설정
void maptool::setsampleTile()
{
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{
			_sampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			_sampleTile[i * SAMPLETILEX + j].terrainFrameY = i;
		}
	}
}
//=================================================
//샘플북  디자인 위한 곳 
//=================================================
//샘플보드
void maptool::setsampleboard()
{
	_sampleboard._isopen = false;
	_sampleboard._boardimg = IMAGEMANAGER->findImage("도구");
	_sampleboard.x = 800;
	_sampleboard.y = 50;
	_sampleboard.boardrc = RectMake(_sampleboard.x, _sampleboard.y, _sampleboard._boardimg->getWidth(), _sampleboard._boardimg->getHeight());
}

//샘플보드에서 버튼 조정하는 함수
void maptool::sampleboardcontrol()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		//		setMap();
		if (mouse)
		{
			if (page >= 0)setsampleMap();
		}
		else
		{
			setMap();
			_start.x = m_ptMouse.x;
			_start.y = m_ptMouse.y;
		}

		if (PtInRect(&_sampleboard.boardrc, m_ptMouse))
		{
			_sampleboard._isopen = true;
		}

		for (int i = 0; i < 3; i++)
		{
			if (PtInRect(&_sampleboard._button[i].rc, m_ptMouse))
			{
				if (i == 0) _sampleboard._isopen = false;																							//닫기 버튼 클릭 시 닫힘
			}
		}
		if (PtInRect(&_sampleboard._button[1].rc, m_ptMouse))																	//페이지 이전으로 
		{
			if (page >= 0) page--;
		}
		if (PtInRect(&_sampleboard._button[2].rc, m_ptMouse))																	//페이지 이후로
		{
			if (page >= 0) page++;
		}
		if (_sampleboard._isopen)
		{
			_sampleboard._boardimg = IMAGEMANAGER->findImage("맵툴");
			_sampleboard.x = 0;
			_sampleboard.y = 0;
		}
		else
		{
			_sampleboard._isopen = false;
			_sampleboard._boardimg = IMAGEMANAGER->findImage("도구");
			_sampleboard.x = 800;
			_sampleboard.y = 50;
		}
		if (_sampleboard._isopen) sampleboardcontrol();
	}
	if (_sampleboard._isopen) setboardbutton();
	if (!_sampleboard._isopen) page = 0;
	//버튼 
	if (PtInRect(&_samplebutton[0].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _select = TRRAINDRAW;
	if (PtInRect(&_samplebutton[1].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _select = ERASER;
	if (PtInRect(&_samplebutton[2].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _select = OBJDRAW;
	if (PtInRect(&_samplebutton[3].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) { load(); }
	if (PtInRect(&_samplebutton[3].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) { save(); }

	_sampleboard.boardrc = RectMake(_sampleboard.x, _sampleboard.y, _sampleboard._boardimg->getWidth(), _sampleboard._boardimg->getHeight());
}
//샘플 보드 설정
void maptool::setboardbutton()
{
	if (_sampleboard._isopen)
	{
		_sampleboard._button[0]._btnimg = IMAGEMANAGER->findImage("나가기");
		_sampleboard._button[0].x = 850;
		_sampleboard._button[0].y = 50;
		_sampleboard._button[0].rc = RectMake(_sampleboard._button[0].x, _sampleboard._button[0].y, 26, 26);
		if (page >= 0)
		{
			_sampleboard._button[1]._btnimg = IMAGEMANAGER->findImage("맵툴오른쪽");
			_sampleboard._button[1].x = WINSIZEX / 2 + 150;
			_sampleboard._button[1].y = WINSIZEY / 2 + 60;
			_sampleboard._button[1].rc = RectMake(_sampleboard._button[1].x, _sampleboard._button[1].y,
				_sampleboard._button[1]._btnimg->getWidth(), _sampleboard._button[1]._btnimg->getHeight());

			_sampleboard._button[2]._btnimg = IMAGEMANAGER->findImage("맵툴왼쪽");
			_sampleboard._button[2].x = WINSIZEX / 2 + 350;
			_sampleboard._button[2].y = WINSIZEY / 2 + 60;
			_sampleboard._button[2].rc = RectMake(_sampleboard._button[2].x, _sampleboard._button[2].y,
				_sampleboard._button[2]._btnimg->getWidth(), _sampleboard._button[2]._btnimg->getHeight());

			_samplebutton[0]._btnimg = IMAGEMANAGER->findImage("타일");
			_samplebutton[0].x = WINSIZEX / 2 + 120;
			_samplebutton[0].y = 500;
			_samplebutton[0].rc = RectMake(_samplebutton[0].x, _samplebutton[0].y, 100, 80);

			_samplebutton[1]._btnimg = IMAGEMANAGER->findImage("지우기");
			_samplebutton[1].x = WINSIZEX / 2 + 340;
			_samplebutton[1].y = 500;
			_samplebutton[1].rc = RectMake(_samplebutton[1].x, _samplebutton[1].y, 100, 80);

			_samplebutton[2]._btnimg = IMAGEMANAGER->findImage("오브젝트");
			_samplebutton[2].x = WINSIZEX / 2 + 230;
			_samplebutton[2].y = 500;
			_samplebutton[2].rc = RectMake(_samplebutton[2].x, _samplebutton[2].y, 100, 80);

			_samplebutton[3]._btnimg = IMAGEMANAGER->findImage("로드");
			_samplebutton[3].x = WINSIZEX / 2 + 160;
			_samplebutton[3].y = 600;
			_samplebutton[3].rc = RectMake(_samplebutton[3].x, _samplebutton[3].y, 100, 80);

			_samplebutton[4]._btnimg = IMAGEMANAGER->findImage("저장");
			_samplebutton[4].x = WINSIZEX / 2 + 265;
			_samplebutton[4].y = 600;
			_samplebutton[4].rc = RectMake(_samplebutton[4].x, _samplebutton[4].y, 100, 80);
		}
		setpageSample();
		if (page >= 0 && page < 13)
		{
			sampleRc();
		}
	}
}
//랙트 뿌리기
//이거 수정
void maptool::sampleRc()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 36; j++)
		{
			//나무풀 밭 
			if (page >= 0 && page <= 3)
			{
				rc[i] = RectMakeCenter(582 + i * 55, 120, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());						//타일 첫줄칸		
				rc[i + 6] = RectMakeCenter(582 + i * 55, 175, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());				//타일 두번째 줄칸
				rc[i + 12] = RectMakeCenter(582 + i * 55, 230, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//타일 셋 줄 칸
				rc[i + 18] = RectMakeCenter(582 + i * 55, 285, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//타일 셋 줄 칸
				rc[i + 24] = RectMakeCenter(582 + i * 55, 340, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//타일 셋 줄 칸
				rc[i + 30] = RectMakeCenter(582 + i * 55, 395, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//타일 셋 줄 칸
			}
			//산  
			if (page >= 4 && page <= 7)
			{
				rc[i] = RectMakeCenter(582 + i * 55, 120, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());						//타일 첫줄칸		
				rc[i + 6] = RectMakeCenter(582 + i * 55, 175, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());				//타일 두번째 줄칸
				rc[i + 12] = RectMakeCenter(582 + i * 55, 230, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());		//타일 셋 줄 칸
				rc[i + 18] = RectMakeCenter(582 + i * 55, 285, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());		//타일 셋 줄 칸
				rc[i + 24] = RectMakeCenter(582 + i * 55, 340, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());		//타일 셋 줄 칸
				rc[i + 30] = RectMakeCenter(582 + i * 55, 395, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());		//타일 셋 줄 칸
			}
			//동굴
			if (page >= 8 && page <= 12)
			{
				rc[i] = RectMakeCenter(582 + i * 55, 120, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());						//타일 첫줄칸		
				rc[i + 6] = RectMakeCenter(582 + i * 55, 175, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());					//타일 두번째 줄칸
				rc[i + 12] = RectMakeCenter(582 + i * 55, 230, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());			//타일 셋 줄 칸
				rc[i + 18] = RectMakeCenter(582 + i * 55, 285, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());			//타일 셋 줄 칸
				rc[i + 24] = RectMakeCenter(582 + i * 55, 340, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());			//타일 셋 줄 칸
				rc[i + 30] = RectMakeCenter(582 + i * 55, 395, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());			//타일 셋 줄 칸
			}
		}
	}

}
//샘플 페이지에 넣을 이미지들
void maptool::setpageSample()
{
	for (int i = 0; i < 36; i++)
	{
		if (page == 0)
		{
			if (i < 12)
			{
				_springfloor[i]->setFrameX(i);
				_springfloor[i]->setFrameY(0);
			}
			else if (i >= 12 && i <= 23)
			{
				_springfloor[i]->setFrameX(i - 12);
				_springfloor[i]->setFrameY(1);
			}
			else if (i >= 24 && i <= 35)
			{
				_springfloor[i]->setFrameX(i - 24);
				_springfloor[i]->setFrameY(2);
			}
		}
		else if (page == 1)
		{
			if (i < 12)
			{
				_springfloor[i]->setFrameX(i);
				_springfloor[i]->setFrameY(3);
			}
			else if (i >= 12 && i <= 23)
			{
				_springfloor[i]->setFrameX(i - 12);
				_springfloor[i]->setFrameY(4);
			}
			else if (i >= 24 && i <= 35)
			{
				_springfloor[i]->setFrameX(i - 24);
				_springfloor[i]->setFrameY(5);
			}
		}
		else if (page == 2)
		{
			if (i < 12)
			{
				_springfloor[i]->setFrameX(i);
				_springfloor[i]->setFrameY(6);
			}
			else if (i >= 12 && i <= 23)
			{
				_springfloor[i]->setFrameX(i - 12);
				_springfloor[i]->setFrameY(7);
			}
			else if (i >= 24 && i <= 35)
			{
				_springfloor[i]->setFrameX(i - 24);
				_springfloor[i]->setFrameY(8);
			}
		}
		else if (page == 3)
		{
			if (i < 12)
			{
				_springfloor[i]->setFrameX(i);
				_springfloor[i]->setFrameY(9);
			}
			else if (i >= 12 && i <= 23)
			{
				_springfloor[i]->setFrameX(i - 12);
				_springfloor[i]->setFrameY(10);
			}
			else if (i >= 24 && i <= 35)
			{
				_springfloor[i]->setFrameX(i - 24);
				_springfloor[i]->setFrameY(11);
			}
		}
		else if (page == 4)
		{
			if (i < 12)
			{
				_mountainsimg[i]->setFrameX(i);
				_mountainsimg[i]->setFrameY(0);
			}
			else if (i >= 12 && i <= 23)
			{
				_mountainsimg[i]->setFrameX(i - 12);
				_mountainsimg[i]->setFrameY(1);
			}
			else if (i >= 24 && i <= 35)
			{
				_mountainsimg[i]->setFrameX(i - 24);
				_mountainsimg[i]->setFrameY(2);
			}
		}
		else if (page == 5)
		{
			if (i < 12)
			{
				_mountainsimg[i]->setFrameX(i);
				_mountainsimg[i]->setFrameY(3);
			}
			else if (i >= 12 && i <= 23)
			{
				_mountainsimg[i]->setFrameX(i - 12);
				_mountainsimg[i]->setFrameY(4);
			}
			else if (i >= 24 && i <= 35)
			{
				_mountainsimg[i]->setFrameX(i - 24);
				_mountainsimg[i]->setFrameY(5);
			}
		}
		else if (page == 6)
		{
			if (i < 12)
			{
				_mountainsimg[i]->setFrameX(i);
				_mountainsimg[i]->setFrameY(6);
			}
			else if (i >= 12 && i <= 23)
			{
				_mountainsimg[i]->setFrameX(i - 12);
				_mountainsimg[i]->setFrameY(7);
			}
			else if (i >= 24 && i <= 35)
			{
				_mountainsimg[i]->setFrameX(i - 24);
				_mountainsimg[i]->setFrameY(8);
			}
		}
		else if (page == 7)
		{
			if (i < 12)
			{
				_mountainsimg[i]->setFrameX(i);
				_mountainsimg[i]->setFrameY(9);
			}
			else if (i >= 12 && i <= 23)
			{
				_mountainsimg[i]->setFrameX(i - 12);
				_mountainsimg[i]->setFrameY(10);
			}
			else if (i >= 24 && i <= 35)
			{
				_mountainsimg[i]->setFrameX(i - 24);
				_mountainsimg[i]->setFrameY(11);
			}
		}
		else if (page == 8)
		{
			if (i < 12)
			{
				_mine[i]->setFrameX(i);
				_mine[i]->setFrameY(0);
			}
			else if (i >= 12 && i <= 23)
			{
				_mine[i]->setFrameX(i - 12);
				_mine[i]->setFrameX(1);
			}
			else if (i >= 24 && i <= 35)
			{
				_mine[i]->setFrameX(i - 24);
				_mine[i]->setFrameY(2);
			}
		}
		else if (page == 9)
		{
			if (i < 12)
			{
				_mine[i]->setFrameX(i);
				_mine[i]->setFrameY(3);
			}
			else if (i >= 12 && i <= 23)
			{
				_mine[i]->setFrameX(i - 12);
				_mine[i]->setFrameX(4);
			}
			else if (i >= 24 && i <= 35)
			{
				_mine[i]->setFrameX(i - 24);
				_mine[i]->setFrameY(5);
			}
		}
		else	if (page == 10)
		{
			if (i < 12)
			{
				_mine[i]->setFrameX(i);
				_mine[i]->setFrameY(6);
			}
			if (i >= 12 && i <= 23)
			{
				_mine[i]->setFrameX(i - 12);
				_mine[i]->setFrameY(7);
			}
			if (i >= 24 && i <= 35)
			{
				_mine[i]->setFrameX(i - 24);
				_mine[i]->setFrameY(8);
			}
		}
		else if (page == 11)
		{
			if (i < 12)
			{
				_mine[i]->setFrameX(i);
				_mine[i]->setFrameY(9);
			}
			if (i >= 12 && i <= 23)
			{
				_mine[i]->setFrameX(i - 12);
				_mine[i]->setFrameY(10);
			}
			if (i >= 24 && i <= 35)
			{
				_mine[i]->setFrameX(i - 24);
				_mine[i]->setFrameY(11);
			}
		}
		else if (page == 12)
		{
			if (i < 12)
			{
				_mine[i]->setFrameX(i);
				_mine[i]->setFrameY(12);
			}
			if (i >= 12 && i <= 23)
			{
				_mine[i]->setFrameX(i - 12);
				_mine[i]->setFrameY(13);
			}
			if (i >= 24 && i <= 35)
			{
				_mine[i]->setFrameX(i - 24);
				_mine[i]->setFrameY(14);
			}
		}
	}
}
//타일 들 설정
void maptool::setMap()
{
	//왼쪽 타일
	for (int i = 0; i < TILEX* TILEY; i++)
	{
		if (PtInRect(&_tile[i].rc, m_ptMouse))
		{
			if (_select == TRRAINDRAW)
			{
				_tile[i].terrainFrameX = _currentTile.x;
				_tile[i].terrainFrameY = _currentTile.y;

				_tile[i].terrain = terrainSelect(_currentTile.x, _currentTile.y);
			}
			else if (_select == OBJDRAW)
			{
				_tile[i].objFrameX = _currentTile.x;
				_tile[i].objFrameY = _currentTile.y;
				_tile[i].obj = objSelect(_currentTile.x, _currentTile.y);
			}
			else if (_select == ERASER)
			{
				if (_tile[i].obj != OBJ_NONE)
				{
					_tile[i].objFrameX = 0;
					_tile[i].objFrameY = 0;
					_tile[i].obj = OBJ_NONE;
				}
				else
				{
					_tile[i].terrainFrameX = 0;
					_tile[i].terrainFrameY = 0;
					_tile[i].terrain = TERAIN_NONE;
				}
			}
			InvalidateRect(m_hWnd, NULL, false);
			break;
		}
	}
}
//현재타일 찍기 함수
//이건 수정해야 할 듯?
void maptool::setsampleMap()
{
	for (int i = 0; i < 36; i++)
	{
		if (PtInRect(&rc[i], m_ptMouse))
		{
			if (page >= 0 && page <= 3)
			{
				_currentTile.x = _springfloor[i]->getFrameX();
				_currentTile.y = _springfloor[i]->getFrameY();
			}
			if (page >= 4 && page <= 8)
			{
				_currentTile.x = _mountainsimg[i]->getFrameX();
				_currentTile.y = _mountainsimg[i]->getFrameY();
			}
			if (page >= 9 && page <= 12)
			{
				_currentTile.x = _mine[i]->getFrameX();
				_currentTile.y = _mine[i]->getFrameY();
			}
			break;
		}
	}
}

TERRAIN maptool::terrainSelect(int frameX, int frameY)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (page >= 0 && page <= 1)
			{
				if (frameX == i && frameY == j)
					return TERAIN_GROUND;
			}
			else if (page == 2)
			{
				if (i >= 2 && i <= 5 && j == 5)
				{
					return TERAIN_WALL;
				}
				else
				{
					return TERAIN_GROUND;
				}
			}
			else if (page == 3)
			{
				if ((i >= 2 && i <= 5 && j == 1) || (i >= 3 && i <= 5 && j == 3) || (i >= 3 && i <= 5 && j == 5))
				{
					return   TERAIN_WALL;
				}
				else
				{
					return TERAIN_GROUND;
				}
			}
			else if (page == 4)
			{
				if ((i >= 0 && i <= 1 && j == 0) || (i >= 0 && i <= 1 && i == 3 && j == 2) || (i >= 0 && i <= 1 && i == 3 && j == 4))
				{
					if ((frameX == i && frameY == j) || (frameX == 0 && frameY == 1) || (frameX == 4 && frameY == 1) || (frameX == 4 && frameY == 4) || (frameX == 4 && frameY == 5))
					{
						return TERAIN_GROUND;
					}
					else
					{
						return TERAIN_WALL;
					}
				}
			}
			else if (page == 5)
			{
				if ((i >= 2 && i <= 5 && j == 0) || (i >= 1 && i <= 5 && j == 1) || (i >= 4 && i <= 5 && j == 2) || (i >= 4 && i <= 5 && j == 3) || (i >= 0 && i <= 1 && j == 4) || (i >= 4 && i <= 5 && j == 4) || (i >= 0 && i <= 4 && j == 5))
				{
					if (frameX == i && frameY == j || (frameX == 3 && frameY == 2) || (frameX == 2 && frameY == 3))
					{
						return TERAIN_WALL;
					}
				}
				else if ((frameX == 3 && frameY == 2) || (frameX == 3 && frameY == 3) || (frameX == 3 && frameY == 4) || (frameX == 5 && frameY == 5))
				{
					return TERAIN_GROUND;
				}
			}
			else if (page == 6)
			{
				if ((i >= 0 && i <= 5 && j == 0) || (i >= 0 && i <= 1 || j == 1) || (i >= 1 && i <= 5 && j == 2) || (i >= 0 && i <= 5 && j == 3) || (i >= 1 && i <= 5 && j == 4) || (i >= 0 && i <= 4 && j == 5))
				{
					if (frameX == i && frameY == j)return TERAIN_WALL;
				}
				else
				{
					return TERAIN_GROUND;
				}
			}
			else if (page == 7)
			{
				if ((i >= 1 && i <= 5 && j == 1) || (i >= 0 && i <= 4 && j == 1) || (i >= 1 && i <= 5 && j == 2))
				{
					if ((frameX == i && frameY == j) || (frameX == 0 && frameY == 4))
					{
						return TERAIN_WALL;
					}
					else
					{
						return TERAIN_GROUND;
					}
				}
			}
		}
	}
	return TERAIN_GROUND;
}

OBJECT maptool::objSelect(int frameX, int frameY)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (page == 0)
			{
				if (frameX == 3 && frameY == 0 || frameX == 4 && frameY == 0 || frameX == 1 && frameY == 2 || frameX == 0 && frameY == 5 && frameX == 1 && frameY == 5)
				{
					return OBJ_FARM;
				}
				if (frameX == 5 && frameY == 0 || frameX == 0 && frameY == 1)
				{
					return OBJ_TREE;
				}
				if ((i >= 2 && i <= 5 && j == 3) && (i >= 2 && i <= 5 && j == 5))
				{
					if (frameX == i && frameY == j)
					{
						return OBJ_RIVER;
					}
				}
			}
			if (page == 1)
			{
				if (i >= 1 && i <= 2 && j == 1)
				{
					if (frameX == i && frameY == j)
					{
						return OBJ_STONE;
					}
				}
				if (i >= 2 && i <= 4 && j == 1 || (i >= 2 && i <= 4 && j == 3) || (i >= 2 && i <= 4 && j == 5))
				{
					if (frameX == i && frameY == j)
					{
						return OBJ_RIVER;
					}
				}
			}//페이지 2 
			if (page == 2)
			{
				if (i >= 2 && i <= 4 && j == 1 || i >= 2 && i <= 5 && j == 3)
				{
					if (frameX == i && frameY == j)return OBJ_RIVER;
				}
				if (i >= 2 && i <= 4 && j == 5)
				{
					if (frameX == i && frameY == j)return OBJ_WALL;
				}
			}
			if (page == 3)
			{
				if (i >= 2 && i <= 5 && j == 1 || i >= 3 && i <= 5 && j == 3 || i >= 3 && i <= 5 || j == 5)
				{
					if (frameX == i && frameY == j)
					{
						return OBJ_WALL;
					}
				}
			}
		}
	}
	return OBJ_NONE;
}
