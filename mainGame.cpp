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
	SCENEMANAGER->addScene("����1", new Myland1);
	SCENEMANAGER->addScene("����2", new Myland2);
	SCENEMANAGER->addScene("����3", new Myland3);
	SCENEMANAGER->addScene("����", new Myhouse);
	SCENEMANAGER->addScene("����", new MineScene);
	SCENEMANAGER->addScene("����", new shopscene);
	SCENEMANAGER->addScene("����1", new Town);
	SCENEMANAGER->addScene("����2", new town2);

	SCENEMANAGER->changeScene("��Ʈ��");
	CURSOR->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	CURSOR->release();
	SCENEMANAGER->release();
	ANIMATIONMANAGER->deleteALL();
}

void mainGame::update()
{
	gameNode::update();
	SCENEMANAGER->update();
	ANIMATIONMANAGER->update();
	CURSOR->update();
}

void mainGame::render(/*HDC hdc*/)
{
	//��� ��Ʈ��
	//	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(getMemDC(), CAMERA->getCameraCenter().x - WINSIZEX / 2, CAMERA->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//====================================================
	SCENEMANAGER->render();
	CURSOR->render(getMemDC());
	TIMEMANAGER->render(CAMERA->getCameraDC());

	
	//=====================================================
	//������� ������ HDC�� �׸���.(��������!!)
//his->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(this->getBackBuffer());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getCameraCenter().x - WINSIZEX / 2, CAMERA->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY);									//���� ������ �ʿ��� �� 

}








