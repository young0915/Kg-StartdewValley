#pragma once
#include"gameNode.h"
#define PLAYERSPEED 5
#define CAMERASPEED 5

class minimap : public gameNode
{
private:

	image * _rockman;
	int _index;
	int _count;
	int _camera;
	bool _isLeft;


	RECT mini_rc;
public:
	minimap();
	~minimap();

	HRESULT init();	//�ʱ�ȭ
	void release();//����
	void update();//�����ϴ°�
	void render();//�׸��°�
};

