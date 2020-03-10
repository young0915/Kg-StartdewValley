#include "stdafx.h"
#include "tileManager.h"

tileManager::tileManager()
{
}

tileManager::~tileManager()
{
}

HRESULT tileManager::init()
{
	IMAGEMANAGER->addFrameImage("�����ٴ�", "images/����/maptool_tile.bmp", 600, 1550, 12, 31, true, RGB(255, 0, 255));
	return S_OK;
}

void tileManager::release()
{
}

void tileManager::update()
{
}

void tileManager::render()
{
	//����
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_map[i].terrain == TERAIN_NONE) continue;
		else  IMAGEMANAGER->frameRender("�����ٴ�", getMemDC(), _map[i].rc.left, _map[i].rc.top, _map[i].terrainFrameX, _map[i].terrainFrameY);
		//������Ʈ
		if (_map[i].obj == OBJ_NONE) continue;
		IMAGEMANAGER->frameRender("�����ٴ�", getMemDC(), _map[i].rc.left, _map[i].rc.top, _map[i].objFrameX, _map[i].objFrameY);
	}
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 100 < _map[i].x && _map[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _map[i].y&& _map[i].y < CAMERAY + WINSIZEY + 100)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				SetBkMode(getMemDC(), TRANSPARENT);
				//����
				SetTextColor(getMemDC(), RGB(255, 0, 0));

				char str[128];
				sprintf_s(str, "%d", i);
				TextOut(getMemDC(), _map[i].rc.left, _map[i].rc.top, str, strlen(str));
			}
		}
	}

}

void tileManager::mapattribute()
{
}
//�� ��
void tileManager::Mylandload(int x, int y)
{
	int startpoint;
	int endpoint;
	startpoint = x;
	endpoint = y;
	HANDLE file;
	DWORD read;

	file = CreateFile(
		"save/����/��5.map",												//������ ���� �Ǵ� �� ��ġ�� ���� �̸�
		GENERIC_READ,															//�����̳� ��ġ�� ����ų� ���� ����� ���� 
		0,																						//���� ���� ��� �Է�
		NULL,																				//���� �Ǵ� ��ġ�� ���� ���� �� Ư��
		OPEN_EXISTING,															//�����̳� ��ġ�� ���� ���� �ൿ
		FILE_ATTRIBUTE_NORMAL,										//�����̳� ��ġ�� ���� ���� �� Ư��
		NULL);																				//������� ������ ���� �� Ȯ�� Ư���� ���� ����
	ReadFile(file, _map, sizeof(tagTile)* TILEX*TILEY, &read, NULL);

	_pos[0] = 415;
	_pos[1] = 30;

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_OBJattribute[i].strengh = 0;
		if (_map[i].obj == OBJ_PLAYER && _map[i].obj == OBJ_FARM && _map[i].obj == OBJ_FLOWER)
		{
			_map[i].obj = OBJ_NONE;
		}

	}
	//�Ӽ� ����
	memset(_attribute, 0, sizeof(DWORD)*TILEX*TILEY);
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_map[i].terrain == TERAIN_WALL)
		{
			_attribute[i] |= ATTR_UNMOVABLE;
		}
		if (_map[i].obj == OBJ_WALL)
		{
			_attribute[i] |= ATTR_UNMOVABLE;
			_OBJattribute[i].strengh = 1;
		}
	}
}
//����
void tileManager::Mineload()
{
	HANDLE file;
	DWORD read;

	file = CreateFile(
		"save/����/��5.map",												//������ ���� �Ǵ� �� ��ġ�� ���� �̸�
		GENERIC_READ,															//�����̳� ��ġ�� ����ų� ���� ����� ���� 
		0,																						//���� ���� ��� �Է�
		NULL,																				//���� �Ǵ� ��ġ�� ���� ���� �� Ư��
		OPEN_EXISTING,															//�����̳� ��ġ�� ���� ���� �ൿ
		FILE_ATTRIBUTE_NORMAL,										//�����̳� ��ġ�� ���� ���� �� Ư��
		NULL);																				//������� ������ ���� �� Ȯ�� Ư���� ���� ����
	ReadFile(file, _map, sizeof(tagTile)*TILEX* TILEY, &read, NULL);
	ReadFile(file, _pos, sizeof(int) * 2, &read, NULL);
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_OBJattribute[i].strengh = 0;
		if (_map[i].obj == OBJ_PLAYER)
		{
			_map[i].obj = OBJ_NONE;
		}
	}
	//�Ӽ� ����
	memset(_attribute, 0, sizeof(DWORD)*TILEX*TILEY);
	for (int i = 0; i < TILEX* TILESIZEY; i++)
	{
		if (_map[i].terrain == TERAIN_WALL)
		{
			_attribute[i] |= ATTR_UNMOVABLE;
		}
		if (_map[i].obj == OBJ_WALL)
		{
			_attribute[i] |= ATTR_UNMOVABLE;
			_OBJattribute[i].strengh = 1;
		}
		if (_map[i].obj == OBJ_FARM)					//���� 
		{
			_attribute[i] |= ATTR_UNMOVABLE;
			_OBJattribute[i].strengh = 3;
		}
	}

}

void tileManager::attackBlock(int tileN)
{
	if (_map[tileN].obj == OBJ_WALL) return;
	_OBJattribute[tileN].strengh--;

	if (_OBJattribute[tileN].strengh <= 0)
	{
		_OBJattribute[tileN].strengh = 0;
		_attribute[tileN] = 0;
		_map[tileN].obj = OBJ_NONE;
	}
}
