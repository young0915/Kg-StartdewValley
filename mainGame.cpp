#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init(true);

	_maptool = new maptool;
	
	PLAYER->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	PLAYER->release();

}

void mainGame::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	PLAYER->update();
}

void mainGame::render(/*HDC hdc*/)
{
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//====================================================
	SCENEMANAGER->render();
	PLAYER->render(getMemDC());
	TIMEMANAGER->render(getMemDC());
	//=====================================================
	//������� ������ HDC�� �׸���.(��������!!)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}








