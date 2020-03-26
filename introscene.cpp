#include "stdafx.h"
#include "introscene.h"

introscene::introscene(){}

introscene::~introscene(){}

HRESULT introscene::init()
{
	IMAGEMANAGER->findImage("����ȭ��");
	cloudinit();
	loopX = 0;
	loopY = 0;
	_tile._img = IMAGEMANAGER->findImage("��������");
	
	_button[0]._img = IMAGEMANAGER->findImage("����");
	_button[0].x = 100;
	_button[0].y = 500;
	_button[0].rc = RectMake(_button[0].x, _button[0].y, _button[0]._img->getFrameWidth(), _button[0]._img->getFrameHeight());
	
	_button[1]._img = IMAGEMANAGER->findImage("������ư");
	_button[1].x = 360;
	_button[1].y = 500;
	_button[1].rc = RectMake(_button[1].x, _button[1].y, _button[1]._img->getFrameWidth(), _button[1]._img->getFrameHeight());
	_button[2]._img = IMAGEMANAGER->findImage("�������ư");
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
	IMAGEMANAGER->render("����ȭ��", getMemDC());
	
	cloudrender();																				//���� ������
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
				//����
				if (i == 0)
				{
					SCENEMANAGER->changeScene("����");
				}
				else if (i == 1)
				{
					SCENEMANAGER->changeScene("������");
				}
				else
				{

				}
			}
		}
	}
}
//���� �ʱ�ȭ��
void introscene::cloudinit()
{
	_cloud[0] = IMAGEMANAGER->findImage("����1");
	_cloud[1] = IMAGEMANAGER->findImage("����2");
	_cloud[2] = IMAGEMANAGER->findImage("����3");
	_cloud[3] = IMAGEMANAGER->findImage("����4");
	_cloud[4] = IMAGEMANAGER->findImage("����5");
	_cloud[5] = IMAGEMANAGER->findImage("����6");
	_cloud[6] = IMAGEMANAGER->findImage("����7");
}
//���� ������ ����
void introscene::cloudrender()
{
	_cloud[0]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 0.05f, loopY);							//���� ������
	_cloud[1]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 2.f, loopY);							//���� ������
	_cloud[2]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), loopX++, loopY);							//���� ������
	_cloud[3]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 0.2f, loopY);							//���� ������
	_cloud[4]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 1.f, loopY);							//���� ������
	_cloud[5]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 0.1f, loopY);							//���� ������
	_cloud[6]->loopRender(CAMERA->getCameraDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), speed += 0.01f, loopY);							//���� ������

}
