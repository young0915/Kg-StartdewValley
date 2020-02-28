
#include "stdafx.h"
#include "cameraManager.h"

cameraManager::cameraManager()
{
}

cameraManager::~cameraManager()
{
}

HRESULT cameraManager::init()
{
	_camera = IMAGEMANAGER->addImage("ī�޶�", WINSIZEX, WINSIZEY);									//ī�޶� �� �����ְ� ó���ϰ�
	_center = PointMake(WINSIZEX / 2, WINSIZEY / 2);															//�߽� ����ְ�
	_cameraXY = PointMake(_center.x - WINSIZEX / 2, _center.y - WINSIZEY / 2);			//ī�޶� �߽� ���
	return S_OK;
}

void cameraManager::release()
{
}

void cameraManager::update()
{
	_cameraXY = PointMake(_center.x - WINSIZEX / 2, _center.y - WINSIZEY / 2);			//ī�޶�� ��� �ٲ����� ������ �ʿ�
}

void cameraManager::render(HDC hdc)
{
}

void cameraManager::render(image * img)
{
	GdiTransparentBlt														//	 Ư�� �ҽ��κ��� �ȼ��� �����ϴ� �簢���� ������ ��Ʈ ����� �����մϴ�. �ش� �Լ� ����� TransparentBIt�� ���� 
	(img->getMemDC(),														//������ ����� �Ǵ� device context�� handle ��
		_center.x - WINSIZEX / 2,										//��� �簢���� ���� �� �𼭸��� �� ���� .x
		_center.y - WINSIZEY / 2,										//��� �簢���� ���� �� �𼭸��� �� ���� .y
		WINSIZEX,																	//��� �簢������  �� ���� ��		
		WINSIZEY,																	//��� �簢������  �� ���� ����																			
		_camera->getMemDC(), 										//�����(�ҽ�)����� device context�� handle ���Դϴ�.
		0,																					//�ҽ� ������ �� ������ x��ǥ
		0,																					//�ҽ� ������ �� ������ y��ǥ
		WINSIZEX,																	//�ҽ� �簢���� �� ���� ��
		WINSIZEY,																	//�ҽ� �簢���� �� ���� ���� 
		RGB(255, 0, 255));													//���� ��Ʈ���� ����ó�� �� RGB ��
}

void cameraManager::setCameraDC(POINT point)
{
	_center.x = point.x;
	_center.y = point.y;
}
