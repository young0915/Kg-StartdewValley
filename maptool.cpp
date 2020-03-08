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
	setUp();																	//Ÿ�� �����ϴ� �Լ�
	setsampleboard();												//���ú���
	page = 0;																//�̹��� �ʱ�ȭ
	mouse = false;

	//mapKind = SPRING_FLOOR;

	//sampleRc()�ȿ� ���� �̹���
	for (int i = 0; i < 36; i++)
	{
		_springfloor[i] = new image;
		_springfloor[i]->init("images/����/maptool_tile.bmp", 600, 1300, 12, 26, true, RGB(255, 0, 255));
	}

	_mousePoint.x = CAMERA->getCameraXY().x + m_ptMouse.x;
	_mousePoint.y = CAMERA->getCameraXY().y + m_ptMouse.y;
	//_cursor = new cusor;
	//_cursor->init();
	return S_OK;
}

void maptool::release() {}

void maptool::update()
{
	_mousePoint.x = CAMERA->getCameraXY().x + m_ptMouse.x;
	_mousePoint.y = CAMERA->getCameraXY().y + m_ptMouse.y;
	if (PtInRect(&_sampleboard.boardrc, _mousePoint))
	{
		mouse = true;
	}
	else
	{
		mouse = false;
	}

	CameraMove();
	sampleboardcontrol();
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		_end.x = _mousePoint.x;
		_end.y = _mousePoint.y;

		drage();
	}

	//_cursor->update();
}

void maptool::render()
{
	//Ÿ��WWWS
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 100 < _tile[i].x && _tile[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _tile[i].y&& _tile[i].y < CAMERAY + WINSIZEY + 100)
		{

			if (_tile[i].terrain == TERAIN_NONE) Rectangle(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].rc.right, _tile[i].rc.bottom);
			else
			{
				IMAGEMANAGER->frameRender("�����ٴ�", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainFrameX, _tile[i].terrainFrameY);

			}

			if (_tile[i].obj == OBJ_NONE)continue;
			IMAGEMANAGER->frameRender("�����ٴ�", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].objFrameX, _tile[i].objFrameY);
		}
	}

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 100 < _tile[i].x && _tile[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _tile[i].y&& _tile[i].y < CAMERAY + WINSIZEY + 100)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				SetBkMode(getMemDC(), TRANSPARENT);
				//����
				SetTextColor(getMemDC(), RGB(255, 0, 0));

				char str[128];
				sprintf_s(str, "%d", i);
				TextOut(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, str, strlen(str));
			}
		}
	}

	//���� ���� ������ �Ǵ� ���ú��� ���
	_sampleboard._boardimg->render(CAMERA->getCameraDC(), _sampleboard.x, _sampleboard.y);
	//���ú��� Ȱ��ȭ�̸�
	if (_sampleboard._isopen)
	{
		//Ÿ�� UI
		_sampleboard._button[0]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[0].x, _sampleboard._button[0].y, 0, 0);
		//������ �ѱ��
		_sampleboard._button[1]._btnimg->render(CAMERA->getCameraDC(), _sampleboard._button[1].x, _sampleboard._button[1].y);
		_sampleboard._button[2]._btnimg->render(CAMERA->getCameraDC(), _sampleboard._button[2].x, _sampleboard._button[2].y);
		if (PtInRect(&_sampleboard._button[0].rc, _mousePoint)) { _sampleboard._button[0]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[0].x, _sampleboard._button[0].y, 1, 0); }								//�������ư�� ������ �� �Ͼ�� ȿ��
		//Ÿ��, ������Ʈ, �����, ����, �ε� ��ư
		for (int i = 0; i < 5; i++)
		{
			_samplebutton[i]._btnimg->frameRender(CAMERA->getCameraDC(), _samplebutton[i].x, _samplebutton[i].y, 0, 0);
			if (PtInRect(&_samplebutton[i].rc, _mousePoint)) { _samplebutton[i]._btnimg->frameRender(CAMERA->getCameraDC(), _samplebutton[i].x, _samplebutton[i].y, 1, 0); } //��ư�� ������ �Ͼ�� ȿ��
		}
		//��
		for (int i = 0; i < 36; i++)
		{
			Rectangle(CAMERA->getCameraDC(), rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);

			if (page < 9)
			{
				_springfloor[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);										//���� ��ġ
			}
			//if (page >= 4 && page <= 8)
			//{
			//	_springfloor[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);										//���� ��ġ
			//}
			//if (page >= 9 && page <= 12)
			//{
			//	_springfloor[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);
			//}
		}

	}//_sampleboard._isopen true
	//_cursor->render();
}

void maptool::drage()
{
	if (_start.x == NULL && _start.y == NULL) return;

	POINT temp;

	if (_start.x > _end.x)
	{
		temp.x = _start.x;
		_start.x = _end.x;
		_end.x = temp.x;
	}

	if (_start.y > _end.y)
	{
		temp.y = _start.y;
		_start.y = _end.y;
		_end.y = temp.y;
	}

	RECT d_rc;

	SetRect(&d_rc, _start.x, _start.y, _end.x, _end.y);

	RECT tempRc;

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (IntersectRect(&tempRc, &d_rc, &_tile[i].rc))
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
					_tile[i].objFrameX = NULL;
					_tile[i].objFrameY = NULL;

					_tile[i].obj = OBJ_NONE;
				}
				else
				{
					_tile[i].terrainFrameX = NULL;
					_tile[i].terrainFrameY = NULL;

					_tile[i].terrain = TERAIN_NONE;
				}
			}
		}
	}

	_start.x = NULL;
	_start.y = NULL;
	_end.x = NULL;
	_end.y = NULL;
}

//���̺�
void maptool::save()
{
	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(&_samplebutton[4].rc, _mousePoint))
		{
			HANDLE file;
			DWORD write;
			int arrNum;
			arrNum = i;
			char save[128];
			wsprintf(save, "save/��%d.map", arrNum + 1);

			for (int i = 0; i < TILEX* TILEY; i++)
			{
				_temp[i] = _tile[i];
			}

			file = CreateFile
			(save,				//������ ���϶Ǵ� �� ��ġ�� �����̸�
				GENERIC_WRITE,			//�����̳� ��ġ�� ����ų� ���� ����� ����
				0,						//���� ���� ����Է�
				NULL,					//���϶Ǵ� ��ġ�� ���� ���� �� Ư��
				CREATE_ALWAYS,			//�����̳� ��ġ�� ���� ���� �ൿ
				FILE_ATTRIBUTE_NORMAL,  //�����̳� ��ġ�� ���� ���� �� Ư��
				NULL);					//������� ������ ���� �� Ư�� Ȯ�� Ư���� ���� ����

			WriteFile(file, _temp, sizeof(tagTile) * TILEX * TILEY, &write, NULL);
			CloseHandle(file);
		}
	}

}

//�ε�
void maptool::load()
{

	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(&_samplebutton[3].rc, _mousePoint))
		{
			HANDLE file;
			DWORD read;
			int arrNum;
			arrNum = i;
			char save[128];
			wsprintf(save, "save/��%d.map", arrNum + 1);

			file = CreateFile
			(save,			//������ ���϶Ǵ� �� ��ġ�� �����̸�
				GENERIC_READ,		//�����̳� ��ġ�� ����ų� ���� ����� ����
				0,					//���� ���� ����Է�
				NULL,				//���϶Ǵ� ��ġ�� ���� ���� �� Ư��
				OPEN_EXISTING,		//�����̳� ��ġ�� ���� ���� �ൿ
				FILE_ATTRIBUTE_NORMAL, //�����̳� ��ġ�� ���� ���� �� Ư��
				NULL);				//������� ������ ���� �� Ư�� Ȯ�� Ư���� ���� ����

			ReadFile(file, _temp, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
			CloseHandle(file);

			for (int i = 0; i < TILEX* TILEY; i++)
			{
				_tile[i] = _temp[i];
			}
		}
	}

}

//������ �̿��� ī�޶� �̵�
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
//Ÿ�� �����ϴ� �Լ�
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

// ���ú� �ʱ�ȭ ����
void maptool::mapinit()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		// ���� �ʱ⼳��
		_tile[i].terrain = TERAIN_NONE;

		_tile[i].terrainFrameX = 0;
		_tile[i].terrainFrameY = 0;

		//������Ʈ �ʱ� ����
		_tile[i].obj = OBJ_NONE;

		_tile[i].objFrameX = 0;
		_tile[i].objFrameY = 0;
	}
}
//���� Ÿ�� ����
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
//���ú�  ������ ���� �� 
//=================================================
//���ú���
void maptool::setsampleboard()
{
	_sampleboard._isopen = false;
	_sampleboard._boardimg = IMAGEMANAGER->findImage("����");
	_sampleboard.x = 800;
	_sampleboard.y = 50;
	_sampleboard.boardrc = RectMake(_sampleboard.x, _sampleboard.y, _sampleboard._boardimg->getWidth(), _sampleboard._boardimg->getHeight());
}

//���ú��忡�� ��ư �����ϴ� �Լ�
void maptool::sampleboardcontrol()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (mouse)
		{
			if (page >= 0)setsampleMap();
		}
		else
		{

			setMap();
			_start.x = _mousePoint.x;
			_start.y = _mousePoint.y;
		}

		if (PtInRect(&_sampleboard.boardrc, _mousePoint))
		{
			_sampleboard._isopen = true;
		}

		for (int i = 0; i < 3; i++)
		{
			if (PtInRect(&_sampleboard._button[i].rc, _mousePoint))
			{
				if (i == 0) _sampleboard._isopen = false;																							//�ݱ� ��ư Ŭ�� �� ����
			}
		}
		if (PtInRect(&_sampleboard._button[1].rc, _mousePoint))																	//������ �������� 
		{
			if (page >= 0) page--;
		}
		if (PtInRect(&_sampleboard._button[2].rc, _mousePoint))																	//������ ���ķ�
		{
			if (page >= 0) page++;

			//if (page < 4) mapKind = SPRING_FLOOR;																													// ������ ����
			//else if (page ==4 ||page ==5 ||page ==6 || page == 7) mapKind = MOUNTAIN;																										// ������ ����
			//else if (page ==8 || page ==9 || page ==10 || page ==11 || page == 12)mapKind = MINE;
		}
		if (_sampleboard._isopen)
		{
			_sampleboard._boardimg = IMAGEMANAGER->findImage("����");
			_sampleboard.x = 0;
			_sampleboard.y = 0;
		}
		else
		{
			_sampleboard._isopen = false;
			_sampleboard._boardimg = IMAGEMANAGER->findImage("����");
			_sampleboard.x = 800;
			_sampleboard.y = 50;
		}
		if (_sampleboard._isopen) sampleboardcontrol();
	}
	if (_sampleboard._isopen) setboardbutton();
	if (!_sampleboard._isopen) page = 0;
	//��ư 
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		if (PtInRect(&_samplebutton[0].rc, _mousePoint)) _select = TRRAINDRAW;
		if (PtInRect(&_samplebutton[2].rc, _mousePoint)) _select = OBJDRAW;
		if (PtInRect(&_samplebutton[1].rc, _mousePoint)) _select = ERASER;
		load();
		save();
	}

	_sampleboard.boardrc = RectMake(_sampleboard.x, _sampleboard.y, _sampleboard._boardimg->getWidth(), _sampleboard._boardimg->getHeight());
}
//���� ���� ����
void maptool::setboardbutton()
{
	if (_sampleboard._isopen)
	{
		_sampleboard._button[0]._btnimg = IMAGEMANAGER->findImage("������");
		_sampleboard._button[0].x = 850;
		_sampleboard._button[0].y = 50;
		_sampleboard._button[0].rc = RectMake(_sampleboard._button[0].x, _sampleboard._button[0].y, 26, 26);
		if (page >= 0)
		{
			_sampleboard._button[1]._btnimg = IMAGEMANAGER->findImage("����������");
			_sampleboard._button[1].x = WINSIZEX / 2 + 150;
			_sampleboard._button[1].y = WINSIZEY / 2 + 60;
			_sampleboard._button[1].rc = RectMake(_sampleboard._button[1].x, _sampleboard._button[1].y,
				_sampleboard._button[1]._btnimg->getWidth(), _sampleboard._button[1]._btnimg->getHeight());

			_sampleboard._button[2]._btnimg = IMAGEMANAGER->findImage("��������");
			_sampleboard._button[2].x = WINSIZEX / 2 + 350;
			_sampleboard._button[2].y = WINSIZEY / 2 + 60;
			_sampleboard._button[2].rc = RectMake(_sampleboard._button[2].x, _sampleboard._button[2].y,
				_sampleboard._button[2]._btnimg->getWidth(), _sampleboard._button[2]._btnimg->getHeight());

			_samplebutton[0]._btnimg = IMAGEMANAGER->findImage("Ÿ��");
			_samplebutton[0].x = WINSIZEX / 2 + 120;
			_samplebutton[0].y = 500;
			_samplebutton[0].rc = RectMake(_samplebutton[0].x, _samplebutton[0].y, 100, 80);

			_samplebutton[1]._btnimg = IMAGEMANAGER->findImage("�����");
			_samplebutton[1].x = WINSIZEX / 2 + 340;
			_samplebutton[1].y = 500;
			_samplebutton[1].rc = RectMake(_samplebutton[1].x, _samplebutton[1].y, 100, 80);

			_samplebutton[2]._btnimg = IMAGEMANAGER->findImage("������Ʈ");
			_samplebutton[2].x = WINSIZEX / 2 + 230;
			_samplebutton[2].y = 500;
			_samplebutton[2].rc = RectMake(_samplebutton[2].x, _samplebutton[2].y, 100, 80);

			_samplebutton[3]._btnimg = IMAGEMANAGER->findImage("�ε�");
			_samplebutton[3].x = WINSIZEX / 2 + 160;
			_samplebutton[3].y = 600;
			_samplebutton[3].rc = RectMake(_samplebutton[3].x, _samplebutton[3].y, 100, 80);

			_samplebutton[4]._btnimg = IMAGEMANAGER->findImage("����");
			_samplebutton[4].x = WINSIZEX / 2 + 265;
			_samplebutton[4].y = 600;
			_samplebutton[4].rc = RectMake(_samplebutton[4].x, _samplebutton[4].y, 100, 80);
		}
		setpageSample();
		if (page < 9)
		{
			sampleRc();
		}
	}

}
//��Ʈ �Ѹ���
//�̰� ����
void maptool::sampleRc()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			//����Ǯ �� 
		//	if (page >= 0 && page < 4)
			if (page < 9)
			{
				rc[i] = RectMakeCenter(582 + i * 55, 120, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());						//Ÿ�� ù��ĭ		
				rc[i + 6] = RectMakeCenter(582 + i * 55, 175, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());				//Ÿ�� �ι�° ��ĭ
				rc[i + 12] = RectMakeCenter(582 + i * 55, 230, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 18] = RectMakeCenter(582 + i * 55, 285, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 24] = RectMakeCenter(582 + i * 55, 340, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 30] = RectMakeCenter(582 + i * 55, 395, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
			}

		}
	}

}
//���� �������� ���� �̹�����
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
				_springfloor[i]->setFrameX(i);
				_springfloor[i]->setFrameY(12);
			}
			else if (i >= 12 && i <= 23)
			{
				_springfloor[i]->setFrameX(i - 12);
				_springfloor[i]->setFrameY(13);
			}
			else if (i >= 24 && i <= 35)
			{
				_springfloor[i]->setFrameX(i - 24);
				_springfloor[i]->setFrameY(14);
			}
		}
		else if (page == 5)
		{
			if (i < 12)
			{
				_springfloor[i]->setFrameX(i);
				_springfloor[i]->setFrameY(15);
			}
			else if (i >= 12 && i <= 23)
			{
				_springfloor[i]->setFrameX(i - 12);
				_springfloor[i]->setFrameY(16);
			}
			else if (i >= 24 && i <= 35)
			{
				_springfloor[i]->setFrameX(i - 24);
				_springfloor[i]->setFrameY(17);
			}
		}
		else if (page == 6)
		{
			if (i < 12)
			{
				_springfloor[i]->setFrameX(i);
				_springfloor[i]->setFrameY(18);
			}
			else if (i >= 12 && i <= 23)
			{
				_springfloor[i]->setFrameX(i - 12);
				_springfloor[i]->setFrameY(19);
			}
			else if (i >= 24 && i <= 35)
			{
				_springfloor[i]->setFrameX(i - 24);
				_springfloor[i]->setFrameY(20);
			}
		}
		else if (page == 7)
		{
			if (i < 12)
			{
				_springfloor[i]->setFrameX(i);
				_springfloor[i]->setFrameY(21);
			}
			else if (i >= 12 && i <= 23)
			{
				_springfloor[i]->setFrameX(i - 12);
				_springfloor[i]->setFrameY(22);
			}
			else if (i >= 24 && i <= 35)
			{
_springfloor[i]->setFrameX(i - 24);
_springfloor[i]->setFrameY(23);
			}
		}
		else if (page == 8)
		{
		if (i < 12)
		{
			_springfloor[i]->setFrameX(i);
			_springfloor[i]->setFrameY(24);
		}
		else if (i >= 12 && i <= 23)
		{
			_springfloor[i]->setFrameX(i - 12);
			_springfloor[i]->setFrameY(25);
		}
		else if (i >= 24 && i <= 35)
		{
			_springfloor[i]->setFrameX(i - 24);
			_springfloor[i]->setFrameY(26);
		}
		}
	}
}
//Ÿ�� �� ����
void maptool::setMap()
{
	//���� Ÿ��
	for (int i = 0; i < TILEX* TILEY; i++)
	{
		if (PtInRect(&_tile[i].rc, _mousePoint))
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
					_tile[i].objFrameX = NULL;
					_tile[i].objFrameY = NULL;
					_tile[i].obj = OBJ_NONE;
				}
				else
				{
					_tile[i].terrainFrameX = NULL;
					_tile[i].terrainFrameY = NULL;
					_tile[i].terrain = TERAIN_NONE;
				}
			}
			InvalidateRect(m_hWnd, NULL, false);
			break;
		}
	}
}
//����Ÿ�� ��� �Լ�
void maptool::setsampleMap()
{
	for (int i = 0; i < 36; i++)
	{
		if (PtInRect(&rc[i], _mousePoint))
		{
			if (page < 13)
			{
				_currentTile.x = _springfloor[i]->getFrameX();
				_currentTile.y = _springfloor[i]->getFrameY();
			}
			break;
		}
	}
}

TERRAIN maptool::terrainSelect(int frameX, int frameY)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 6; j < 23; j++)
		{
			if (frameX == i && frameY == j)
			{
				return TERAIN_WALL;
			}
		}
	}
	return TERAIN_GROUND;
}

OBJECT maptool::objSelect(int frameX, int frameY)
{
	if ((frameX == 7 && frameY == 5) || (frameX == 7 && frameY == 7))
	{
		return OBJ_FLOWER;
	}
	if ((frameX == 4 && frameY == 0) || (frameX == 10 && frameY == 0))
	{
		return OBJ_FARM;
	}
	for (int i = 0; i < 12; i++)
	{
		for (int j = 6; j < 23; j++)
		{
			if (frameX == i && frameY == j)return OBJ_WALL;
		}
	}
	return OBJ_NONE;
}
