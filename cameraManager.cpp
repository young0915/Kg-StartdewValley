
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
	_camera = IMAGEMANAGER->addImage("카메라", WINSIZEX, WINSIZEY);									//카메라 다 보여주게 처리하고
	_center = PointMake(WINSIZEX / 2, WINSIZEY / 2);															//중심 잡아주고
	_cameraXY = PointMake(_center.x - WINSIZEX / 2, _center.y - WINSIZEY / 2);			//카메라 중심 잡고
	return S_OK;
}

void cameraManager::release()
{
}

void cameraManager::update()
{
	_cameraXY = PointMake(_center.x - WINSIZEX / 2, _center.y - WINSIZEY / 2);			//카메라는 계속 바꿔지기 때문에 필요
}

void cameraManager::render(HDC hdc)
{
}

void cameraManager::render(image * img)
{
	GdiTransparentBlt														//	 특정 소스로부터 픽셀에 대응하는 사각형의 데이터 비트 블록을 전송합니다. 해당 함수 기능은 TransparentBIt와 같음 
	(img->getMemDC(),														//복사의 대상이 되는 device context의 handle 값
		_center.x - WINSIZEX / 2,										//대상 사각형의 왼쪽 위 모서리의 논리 단위 .x
		_center.y - WINSIZEY / 2,										//대상 사각형의 왼쪽 위 모서리의 논리 단위 .y
		WINSIZEX,																	//대상 사각혀으이  논리 단위 폭		
		WINSIZEY,																	//대상 사각혀으이  논리 단위 높이																			
		_camera->getMemDC(), 										//복사될(소스)대사의 device context의 handle 값입니다.
		0,																					//소스 구형의 논리 단위로 x좌표
		0,																					//소스 구형의 논리 단위로 y좌표
		WINSIZEX,																	//소스 사각형의 논리 단위 폭
		WINSIZEY,																	//소스 사각형의 논리 단위 높이 
		RGB(255, 0, 255));													//원본 비트맵의 투명처리 될 RGB 값
}

void cameraManager::setCameraDC(POINT point)
{
	_center.x = point.x;
	_center.y = point.y;
}
