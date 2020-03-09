#include "stdafx.h"
#include "MineScene.h"

MineScene::MineScene()
{
}

MineScene::~MineScene()
{
}

HRESULT MineScene::init()
{
	
	mapinit();
	return S_OK;
}

void MineScene::release()
{
}

void MineScene::update()
{
}

// 동굴 이미지 정보
void MineScene::mapinit()
{
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			SetRect(&_tile[i * TILEX + j].rc, j * TILESIZE, i * TILESIZE, j* TILESIZE + TILESIZE, i * TILESIZE + TILESIZE);
		}
	}
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_tile[i].x = _tile[i].rc.left + (_tile[i].rc.right - _tile[i].rc.left) / 2;
		_tile[i].y = _tile[i].rc.top + (_tile[i].rc.bottom - _tile[i].rc.top) / 2;
	}

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
	ReadFile(file, _temp, sizeof(tagTile)*TILEX* TILEY, &read, NULL);
	CloseHandle(file);
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_tile[i] = _temp[i];
	}
}
//동굴 랜더
void MineScene::maprender()
{
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (CAMERAX - 100 < _tile[i].x && _tile[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _tile[i].y && _tile[i].y < CAMERAY + WINSIZEY + 100)
		{
			if (_tile[i].terrain == TERAIN_NONE) Rectangle(getMemDC(), _tile[i].rc.top, _tile[i].rc.left, _tile[i].rc.right, _tile[i].rc.bottom);
			else IMAGEMANAGER->frameRender("맵툴바닥", getMemDC(), _tile[i].rc.top, _tile[i].rc.left, _tile[i].terrainFrameX, _tile[i].terrainFrameY);

			if (_tile[i].obj == OBJ_NONE) continue;
			IMAGEMANAGER->frameRender("맵툴바닥", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].objFrameX, _tile[i].objFrameY);
		}
	}

}


void MineScene::render()
{
	maprender();
}
