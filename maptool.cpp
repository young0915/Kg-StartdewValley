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

	//sampleRc()�ȿ� ���� �̹���
	for (int i = 0; i < 36; i++)
	{
		_springfloor[i] = new image;
		_springfloor[i]->init("images/����/maptool_tile1_spring.bmp", 576, 576, 12, 12, true, RGB(255, 0, 255));

		_mountainsimg[i] = new image;
		_mountainsimg[i]->init("images/����/maptool_tile2_spring.bmp", 576, 576, 12, 12, true, RGB(255, 0, 255));

		_mine[i] = new image;
		_mine[i]->init("images/����/mine.bmp", 800, 800, 16, 16, true, RGB(255, 0, 255));
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
	//Ÿ��
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 100 < _tile[i].x && _tile[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _tile[i].y&& _tile[i].y < CAMERAY + WINSIZEY + 100)
		{

			if (_tile[i].terrain == TERAIN_NONE) Rectangle(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].rc.right, _tile[i].rc.bottom);
			else  IMAGEMANAGER->frameRender("���ٴ�", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainFrameX, _tile[i].terrainFrameY);
			/*_springfloor[i]->frameRender(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainFrameX, _tile[i].terrainFrameY);*/


			//else _springfloor[i]->frameRender("���ٴ�", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainFrameX, _tile[i].terrainFrameY);
			if (_tile[i].obj == OBJ_NONE) continue;

			IMAGEMANAGER->frameRender("���ٴ�", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].objFrameX, _tile[i].objFrameY);
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
		if (PtInRect(&_sampleboard._button[0].rc, m_ptMouse)) { _sampleboard._button[0]._btnimg->frameRender(CAMERA->getCameraDC(), _sampleboard._button[0].x, _sampleboard._button[0].y, 1, 0); }								//�������ư�� ������ �� �Ͼ�� ȿ��
		//Ÿ��, ������Ʈ, �����, ����, �ε� ��ư
		for (int i = 0; i < 5; i++)
		{
			_samplebutton[i]._btnimg->frameRender(CAMERA->getCameraDC(), _samplebutton[i].x, _samplebutton[i].y, 0, 0);
			if (PtInRect(&_samplebutton[i].rc, m_ptMouse)) { _samplebutton[i]._btnimg->frameRender(CAMERA->getCameraDC(), _samplebutton[i].x, _samplebutton[i].y, 1, 0); } //��ư�� ������ �Ͼ�� ȿ��
		}
		//��
		for (int i = 0; i < 36; i++)
		{
			Rectangle(CAMERA->getCameraDC(), rc[i].left, rc[i].top, rc[i].right, rc[i].bottom);
			if (page >= 0 && page <= 3)
			{
				_springfloor[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);										//���� ��ġ
			}
			if (page >= 4 && page <= 8)
			{
				_mountainsimg[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);										//���� ��ġ
			}
			if (page >= 9 && page <= 12)
			{
				_mine[i]->frameRender(CAMERA->getCameraDC(), rc[i].left, rc[i].top);
			}
		}

	}//_sampleboard._isopen true


}

//���̺�
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
			wsprintf(save, "save/��%d.map", arrNum + 1);

			for (int i = 0; i < TILEX* TILEY; i++)
			{
				_temp[i] = _tile[i];
			}

			file = CreateFile
			(																									//������ ���� �Ǵ� �� ��ġ�� ���� �̸�
				save,																						//�����̳� ��ġ�� ����ų� ���� ����� ����
				GENERIC_WRITE,																	// ���� ������� �Է�
				0,																								//���� �Ǵ� ��ġ�� ���� ���� �� Ư��
				NULL,																						//�����̳� ��ġ�� ���� ���� �ൿ
				CREATE_ALWAYS,																	//�����̳� ��ġ�� ���� ���� �� Ư��
				FILE_ATTRIBUTE_NORMAL,												//������� ������ ���� �� Ư�� Ȯ�� Ư���� ���� ����
				NULL);

			WriteFile(file, _temp, sizeof(tagTile)*TILEX*TILEY, &write, NULL);
			CloseHandle(file);
		}
	}
}
//�ε�
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
			wsprintf(save, "save/��%d.map", arrNum + 1);

			file = CreateFile
			(save,										//������ ���� �Ǵ� �� ��ġ�� �����̸�
				GENERIC_READ,				//�����̳� ��ġ�� ����ų� ���� ����� ����
				0,											//���� ���� ��� �Է�
				NULL,									// ���� �Ǵ� ��ġ�� �� �� ���� �� �ൿ
				OPEN_EXISTING,				//�����̳� ��ġ�� ���� ���� �ൿ
				FILE_ATTRIBUTE_NORMAL,	//�����̳� ��ġ�� ���� ���� �� Ư��
				NULL);											//�������  ������ ���� �� Ư�� Ȯ�� Ư���� ���� ���� 

			ReadFile(file, _temp, sizeof(tagTile)*TILEX*TILEY, &read, NULL);
			CloseHandle(file);
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
				if (i == 0) _sampleboard._isopen = false;																							//�ݱ� ��ư Ŭ�� �� ����
			}
		}
		if (PtInRect(&_sampleboard._button[1].rc, m_ptMouse))																	//������ �������� 
		{
			if (page >= 0) page--;
		}
		if (PtInRect(&_sampleboard._button[2].rc, m_ptMouse))																	//������ ���ķ�
		{
			if (page >= 0) page++;
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
	if (PtInRect(&_samplebutton[0].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _select = TRRAINDRAW;
	if (PtInRect(&_samplebutton[1].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _select = ERASER;
	if (PtInRect(&_samplebutton[2].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _select = OBJDRAW;
	if (PtInRect(&_samplebutton[3].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) { load(); }
	if (PtInRect(&_samplebutton[3].rc, m_ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) { save(); }

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
		if (page >= 0 && page < 13)
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
		for (int j = 0; j < 36; j++)
		{
			//����Ǯ �� 
			if (page >= 0 && page <= 3)
			{
				rc[i] = RectMakeCenter(582 + i * 55, 120, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());						//Ÿ�� ù��ĭ		
				rc[i + 6] = RectMakeCenter(582 + i * 55, 175, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());				//Ÿ�� �ι�° ��ĭ
				rc[i + 12] = RectMakeCenter(582 + i * 55, 230, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 18] = RectMakeCenter(582 + i * 55, 285, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 24] = RectMakeCenter(582 + i * 55, 340, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 30] = RectMakeCenter(582 + i * 55, 395, _springfloor[j]->getFrameWidth(), _springfloor[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
			}
			//��  
			if (page >= 4 && page <= 7)
			{
				rc[i] = RectMakeCenter(582 + i * 55, 120, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());						//Ÿ�� ù��ĭ		
				rc[i + 6] = RectMakeCenter(582 + i * 55, 175, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());				//Ÿ�� �ι�° ��ĭ
				rc[i + 12] = RectMakeCenter(582 + i * 55, 230, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 18] = RectMakeCenter(582 + i * 55, 285, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 24] = RectMakeCenter(582 + i * 55, 340, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
				rc[i + 30] = RectMakeCenter(582 + i * 55, 395, _mountainsimg[j]->getFrameWidth(), _mountainsimg[j]->getFrameHeight());		//Ÿ�� �� �� ĭ
			}
			//����
			if (page >= 8 && page <= 12)
			{
				rc[i] = RectMakeCenter(582 + i * 55, 120, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());						//Ÿ�� ù��ĭ		
				rc[i + 6] = RectMakeCenter(582 + i * 55, 175, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());					//Ÿ�� �ι�° ��ĭ
				rc[i + 12] = RectMakeCenter(582 + i * 55, 230, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());			//Ÿ�� �� �� ĭ
				rc[i + 18] = RectMakeCenter(582 + i * 55, 285, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());			//Ÿ�� �� �� ĭ
				rc[i + 24] = RectMakeCenter(582 + i * 55, 340, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());			//Ÿ�� �� �� ĭ
				rc[i + 30] = RectMakeCenter(582 + i * 55, 395, _mine[j]->getFrameWidth(), _mine[j]->getFrameHeight());			//Ÿ�� �� �� ĭ
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
//Ÿ�� �� ����
void maptool::setMap()
{
	//���� Ÿ��
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
//����Ÿ�� ��� �Լ�
//�̰� �����ؾ� �� ��?
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
			}//������ 2 
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
