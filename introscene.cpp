#include "stdafx.h"
#include "introscene.h"

introscene::introscene(){}

introscene::~introscene(){}

HRESULT introscene::init()
{
	IMAGEMANAGER->findImage("시작화면");
	cloudinit();
	loopX = 0;
	loopY = 0;
	_tile._img = IMAGEMANAGER->findImage("게임제목");
	
	_button[0]._img = IMAGEMANAGER->findImage("시작");
	_button[0].x = 100;
	_button[0].y = 500;
	_button[0].rc = RectMake(_button[0].x, _button[0].y, _button[0]._img->getFrameWidth(), _button[0]._img->getFrameHeight());
	
	_button[1]._img = IMAGEMANAGER->findImage("맵툴버튼");
	_button[1].x = 360;
	_button[1].y = 500;
	_button[1].rc = RectMake(_button[1].x, _button[1].y, _button[1]._img->getFrameWidth(), _button[1]._img->getFrameHeight());
	_button[2]._img = IMAGEMANAGER->findImage("나가기버튼");
	_button[2].x = 610;
	_button[2].y = 500;
	_button[2].rc = RectMake(_button[2].x, _button[2].y, _button[2]._img->getFrameWidth(), _button[2]._img->getFrameHeight());
	

	return S_OK;
}

void introscene::release()
{
	for (int i = 0; i < 3; i++)
	{
		SAFE_DELETE(_button[i]._img);
	}
	for (int i = 0; i < 7; i++)
	{
		SAFE_DELETE(_cloud[i]);
	}
}

void introscene::update()
{
	introbtnn();
}



void introscene::render()
{
	IMAGEMANAGER->render("시작화면", getMemDC());
	
	cloudrender();																				//구름 움직임
	_tile._img->render(CAMERA->getCameraDC(), 160, WINSIZEY / 2 - 300);
	_button[0]._img->frameRender(CAMERA->getCameraDC(), _button[0].rc.left,  _button[0].rc.top, 0,0);
	_button[1]._img->frameRender(CAMERA->getCameraDC(), _button[1].rc.left, _button[1].rc.top, 0, 0);
	_button[2]._img->frameRender(CAMERA->getCameraDC(), _button[2].rc.left, _button[2].rc.top, 0, 0);

	for (int i = 0; i < 3; i++)
	{
		if (PtInRect(&_button[i].rc, m_ptMouse))
		{
			_button[i]._img->frameRender(CAMERA->getCameraDC(), _button[i].rc.left, _button[i].rc.top, 1, 0);
		}
	}
}
void introscene::introbtnn()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 3; i++)
		{
			if (PtInRect(&_button[i].rc, m_ptMouse))
			{
				//시작
				if (i == 0)
				{
					SCENEMANAGER->changeScene("내땅");
				}
				else if (i == 1)
				{
					SCENEMANAGER->changeScene("맵툴들");
				}
				else
				{

				}
			}
		}
	}
}
//구름 초기화값
void introscene::cloudinit()
{
	_cloud[0] = IMAGEMANAGER->findImage("구름1");
	_cloud[1] = IMAGEMANAGER->findImage("구름2");
	_cloud[2] = IMAGEMANAGER->findImage("구름3");
	_cloud[3] = IMAGEMANAGER->findImage("구름4");
	_cloud[4] = IMAGEMANAGER->findImage("구름5");
	_cloud[5] = IMAGEMANAGER->findImage("구름6");
	_cloud[6] = IMAGEMANAGER->findImage("구름7");
}
//구름 움직임 랜더
void introscene::cloudrender()
{
	_cloud[0]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 0.05f, loopY);							//구름 움직임
	_cloud[1]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 2.f, loopY);							//구름 움직임
	_cloud[2]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), loopX++, loopY);							//구름 움직임
	_cloud[3]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 0.2f, loopY);							//구름 움직임
	_cloud[4]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 1.f, loopY);							//구름 움직임
	_cloud[5]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 0.1f, loopY);							//구름 움직임
	_cloud[6]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 0.01f, loopY);							//구름 움직임

}
