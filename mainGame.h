#pragma once
#include"gameNode.h"
#include "introscene.h"
#include "Myland.h"
#include "Myland1.h"
#include "Myland2.h"
#include "Myland3.h"
#include "MineScene.h"
#include "maptool.h"
#include "shopscene.h"
#include "Myhouse.h"
#include "Town.h"
#include "town2.h"



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

