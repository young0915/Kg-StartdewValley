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
	IMAGEMANAGER->addFrameImage("맵툴바닥", "images/맵툴/maptool_tile.bmp", 600, 1550, 12, 31, true, RGB(255, 0, 255));
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
	//지형
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (_map[i].terrain == TERAIN_NONE) continue;
		else  IMAGEMANAGER->frameRender("맵툴바닥", getMemDC(), _map[i].rc.left, _map[i].rc.top, _map[i].terrainFrameX, _map[i].terrainFrameY);
		//오브젝트
		if (_map[i].obj == OBJ_NONE) continue;
		IMAGEMANAGER->frameRender("맵툴바닥", getMemDC(), _map[i].rc.left, _map[i].rc.top, _map[i].objFrameX, _map[i].objFrameY);
	}
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 100 < _map[i].x && _map[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _map[i].y&& _map[i].y < CAMERAY + WINSIZEY + 100)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				SetBkMode(getMemDC(), TRANSPARENT);
				//색상
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
//내 땅
void tileManager::Mylandload(int x, int y)
{
	int startpoint;
	int endpoint;
	startpoint = x;
	endpoint = y;
	HANDLE file;
	DWORD read;

	file = CreateFile(
		"save/내땅/맵5.map",												//생성할 파일 또는 열 장치나 파일 이름
		GENERIC_READ,															//파일이나 장치를 만들거나 열때 사용할 권한 
		0,																						//파일 공유 모드 입력
		NULL,																				//파일 또는 장치를 열때 보안 및 특성
		OPEN_EXISTING,															//파일이나 장치를 열때 취할 행동
		FILE_ATTRIBUTE_NORMAL,										//파일이나 장치를 열때 갖게 될 특성
		NULL);																				//만들어질 파일이 갖게 될 확장 특성에 대한 정보
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
	//속성 정의
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
//동굴
void tileManager::Mineload()
{
	HANDLE file;
	DWORD read;

	file = CreateFile(
		"save/동굴/맵5.map",												//생성할 파일 또는 열 장치나 파일 이름
		GENERIC_READ,															//파일이나 장치를 만들거나 열때 사용할 권한 
		0,																						//파일 공유 모드 입력
		NULL,																				//파일 또는 장치를 열때 보안 및 특성
		OPEN_EXISTING,															//파일이나 장치를 열때 취할 행동
		FILE_ATTRIBUTE_NORMAL,										//파일이나 장치를 열때 갖게 될 특성
		NULL);																				//만들어질 파일이 갖게 될 확장 특성에 대한 정보
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
	//속성 정의
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
		if (_map[i].obj == OBJ_FARM)					//농장 
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
