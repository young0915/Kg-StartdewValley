#include "stdafx.h"
#include "gameNode.h"
gameNode::gameNode()
{
}
gameNode::~gameNode()
{
}
image* gameNode::_backBuffer = NULL;
image * gameNode::setBackBuffer()
{

	_backBuffer = new image;
	_backBuffer->init(TOTALSIZEX, TOTALSIZEY);

	return _backBuffer;
}
HRESULT gameNode::init()
{


	_hdc = GetDC(m_hWnd);
	_managerInit = false;
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(m_hWnd);
	_managerInit = managerInit;

	if (managerInit)
	{

		setBackBuffer();
		//SetTimer(m_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		SCENEMANAGER->init();
		SOUNDMANAGER->init();
		ANIMATIONMANAGER->init();
		EFFECTMANAGER->init();
		TXTDATA->init();
		CAMERA->init();
		CURSOR->init();
	}
	         
	return S_OK;
}

void gameNode::release()

{
	if (_managerInit)
	{
		//타이머 해제
		//KillTimer(m_hWnd, 1);
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		ANIMATIONMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		RND->releaseSingleton();
		TXTDATA->releaseSingleton();
		CAMERA->releaseSingleton();
		CURSOR->releaseSingleton();

		KEYMANAGER->release();
		IMAGEMANAGER->release();
		TIMEMANAGER->release();
		SCENEMANAGER->release();
		ANIMATIONMANAGER->release();
		EFFECTMANAGER->release();
		CAMERA->release();
		CURSOR->release();

	}

	ReleaseDC(m_hWnd, _hdc);
}

void gameNode::update()
{

	//더블버퍼 이후 사용 하지 않는다.(true->false)
	//InvalidateRect(m_hWnd, NULL, false);

	CAMERA->update();
	CURSOR->update();



}

void gameNode::render(HDC hdc)
{
}

void gameNode::render()
{
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//PAINTSTRUCT ps;
	//HDC hdc;

	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		m_ptMouse.x = LOWORD(lParam);
		m_ptMouse.y = HIWORD(lParam);
	
		break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
	//	this > setMap();
		break;
	
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
