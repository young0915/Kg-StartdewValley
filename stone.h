#pragma once
#include "gameNode.h"
class stone :public gameNode
{
private:
	image* _img;
	RECT _rc;

	int _atk;

public :
	stone();
	~stone();
						//�̹��� 								��ġ x, y     �÷��̾� ���� ��� �ϴ� ���ݷ�
	HRESULT init(const char* imagename, POINT position, int atk);
	void release();
	void update();
	void render();

	RECT getstonerc() { return _rc; }
};


//���̶� ��� �︮�Ѵ� �� 
