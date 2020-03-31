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
	SCENEMANAGER->addScene("인트로", new introscene);
	SCENEMANAGER->addScene("맵툴들", new maptool);
	SCENEMANAGER->addScene("내땅", new Myland);
	SCENEMANAGER->addScene("내땅1", new Myland1);
	SCENEMANAGER->addScene("내땅2", new Myland2);
	SCENEMANAGER->addScene("내땅3", new Myland3);
	SCENEMANAGER->addScene("내집", new Myhouse);
	SCENEMANAGER->addScene("동굴", new MineScene);
	SCENEMANAGER->addScene("상점", new shopscene);
	SCENEMANAGER->addScene("마을1", new Town);
	SCENEMANAGER->addScene("마을2", new town2);

	SCENEMANAGER->changeScene("인트로");
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
	//흰색 비트맵
	//	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(getMemDC(), CAMERA->getCameraCenter().x - WINSIZEX / 2, CAMERA->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(CAMERA->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	//====================================================
	SCENEMANAGER->render();
	CURSOR->render(getMemDC());
	TIMEMANAGER->render(CAMERA->getCameraDC());

	
	//=====================================================
	//백버퍼의 내용을 HDC에 그린다.(지우지마!!)
//his->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERA->render(this->getBackBuffer());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERA->getCameraCenter().x - WINSIZEX / 2, CAMERA->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY);									//맵툴 떄문에 필요한 것 

}








