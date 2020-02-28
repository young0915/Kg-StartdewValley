#pragma once
#include"image.h"
//����� �̹����� ����ƽ���� ����

static image* _backBuffer = IMAGEMANAGER->addImage("backbuffer", WINSIZEX, WINSIZEY);
class gameNode
{

private:
	//image * _backBuffer;		//�����

	//void setBackBuffer();		//����� ����

	HDC _hdc;
	bool _managerInit;

public:
	gameNode();
	~gameNode();


	virtual HRESULT init();
	virtual HRESULT init(bool managerInit);
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);


	//������
	/*int _ctrSelect;
	void setCtrSelect(int num) { _ctrSelect = num; }


	*/
	virtual void setMap();
	virtual void save();
	virtual void load();


	//����� ������
	image* getBackBuffer() { return _backBuffer; }

	//�߰�(�޸� DC)
	HDC getMemDC() { return _backBuffer->getMemDC(); }

	//�߰� HDC���
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};
#define CAMERAX CAMERA->getCameraXY().x
#define CAMERAY CAMERA->getCameraXY().y

