#pragma once
#include"gameNode.h"
#include "introscene.h"
#include "Myland.h"
#include "MineScene.h"
#include "maptool.h"


class mainGame :  public gameNode
{
private:

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//�ʱ�ȭ
	virtual void release();//����
	virtual void update();//�����ϴ°�
	virtual void render(/*HDC hdc*/);//�׸��°�

	void maingameimg();


	
};

