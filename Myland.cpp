#include "stdafx.h"
#include "Myland.h"

Myland::Myland(){}

Myland::~Myland(){}

HRESULT Myland::init()
{
	PLAYER->init();
	maptoolinit();

	return S_OK;
}

void Myland::release()
{
	PLAYER->release();
}
//	���� �̹��� �ҷ�����
void Myland::maptoolinit()
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
		"save/����/��5.map",												//������ ���� �Ǵ� �� ��ġ�� ���� �̸�
		GENERIC_READ,															//�����̳� ��ġ�� ����ų� ���� ����� ���� 
		0,																						//���� ���� ��� �Է�
		NULL,																				//���� �Ǵ� ��ġ�� ���� ���� �� Ư��
		OPEN_EXISTING,															//�����̳� ��ġ�� ���� ���� �ൿ
		FILE_ATTRIBUTE_NORMAL,										//�����̳� ��ġ�� ���� ���� �� Ư��
		NULL);																				//������� ������ ���� �� Ȯ�� Ư���� ���� ����
	ReadFile(file, _temp, sizeof(tagTile)*TILEX* TILEY, &read, NULL);
	CloseHandle(file);
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		_tile[i] = _temp[i];
	}
}
//���� �ҷ����� ���� �Լ�
void Myland::maptoolrender()
{
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		if (CAMERAX - 100 < _tile[i].x && _tile[i].x < CAMERAX + WINSIZEX + 100 && CAMERAY - 100 < _tile[i].y && _tile[i].y < CAMERAY + WINSIZEY + 100)
		{
			if (_tile[i].terrain == TERAIN_NONE) Rectangle(getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].rc.right, _tile[i].rc.bottom);
			else IMAGEMANAGER->frameRender("�����ٴ�", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].terrainFrameX, _tile[i].terrainFrameY);

			if (_tile[i].obj == OBJ_NONE) continue;
			IMAGEMANAGER->frameRender("�����ٴ�", getMemDC(), _tile[i].rc.left, _tile[i].rc.top, _tile[i].objFrameX, _tile[i].objFrameY);
		}
	}
}

void Myland::update()
{
	PLAYER->update();
}



void Myland::render()
{
	PLAYER->render(CAMERA->getCameraDC());
	maptoolrender();																					//���� �ҷ����� ���� �Լ�
}

