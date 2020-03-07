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
	maingameimg();																		//maingame+img ��� �̹��� ���� �̱��Ͽ� ����ϴ� Ŭ����  ���� 
	SCENEMANAGER->addScene("��Ʈ��", new introscene);
	SCENEMANAGER->addScene("������", new maptool);
	SCENEMANAGER->addScene("����", new Myland);
	SCENEMANAGER->changeScene("��Ʈ��");

	
	//PLAYER->init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SCENEMANAGER->release();
	//PLAYER->release();
	//_maptool->release();
}

void mainGame::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	ANIMATIONMANAGER->update();
	//PLAYER->update();
//	_maptool->update();
}

void mainGame::render(/*HDC hdc*/)
{
	//��� ��Ʈ��
	//	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(getMemDC(), CAMERA->getCameraCenter().x - WINSIZEX / 2, CAMERA->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//====================================================
	SCENEMANAGER->render();
	//_maptool->render();
	//PLAYER->render(getMemDC());
	TIMEMANAGER->render(CAMERA->getCameraDC());
	//=====================================================
	//������� ������ HDC�� �׸���.(��������!!)
//his->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(this->getBackBuffer());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getCameraCenter().x - WINSIZEX / 2, CAMERA->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY);									//���� ������ �ʿ��� �� 

}








