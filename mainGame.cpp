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
	maingameimg();																		//maingame+img 모든 이미지 모음 싱글턴에 사용하는 클래스  빼고 
	_maptool = new maptool;
	_maptool->init();

	PLAYER->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	PLAYER->release();
	_maptool->release();
}

void mainGame::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	ANIMATIONMANAGER->update();
	PLAYER->update();

	_maptool->update();
}

void mainGame::render(/*HDC hdc*/)
{
	//흰색 비트맵
	//	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(getMemDC(), CAMERA->getCameraCenter().x - WINSIZEX / 2, CAMERA->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//====================================================
	SCENEMANAGER->render();
	PLAYER->render(getMemDC());

	_maptool->render();

	PLAYER->render(getMemDC());
	TIMEMANAGER->render(CAMERA->getCameraDC());
	//=====================================================
	//백버퍼의 내용을 HDC에 그린다.(지우지마!!)
//his->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(this->getBackBuffer());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getCameraCenter().x - WINSIZEX / 2, CAMERA->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY);									//맵툴 떄문에 필요한 것 

}








