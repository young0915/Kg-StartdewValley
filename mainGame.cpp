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
	_maptool->init();
	
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

	_maptool->update();
}

void mainGame::render(/*HDC hdc*/)
{
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//====================================================
	SCENEMANAGER->render();
	PLAYER->render(getMemDC());
	TIMEMANAGER->render(getMemDC());
	_maptool->render();
	//=====================================================
	//백버퍼의 내용을 HDC에 그린다.(지우지마!!)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}








