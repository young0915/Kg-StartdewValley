#pragma once
#include"gameNode.h"
#include "introscene.h"
#include "Myland.h"
#include "maptool.h"


class mainGame :  public gameNode
{
private:
	//maptool* _maptool;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();	//초기화
	virtual void release();//해제
	virtual void update();//연산하는곳
	virtual void render(/*HDC hdc*/);//그리는곳

	void maingameimg();


	
};

