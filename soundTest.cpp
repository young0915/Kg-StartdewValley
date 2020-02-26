#include "stdafx.h"
#include "soundTest.h"


soundTest::soundTest()
{
}


soundTest::~soundTest()
{
}

HRESULT soundTest::init()
{
	SOUNDMANAGER->addSound("�˷���", "sound/snow_flower.mp3", true, true);
	return S_OK;
}

void soundTest::release()
{
}

void soundTest::update()
{
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		SOUNDMANAGER->play("�˷���", 1.0f);
	}
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		SOUNDMANAGER->stop("�˷���");
	}
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		SOUNDMANAGER->resume("�˷���");
	}
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		SOUNDMANAGER->pause("�˷���");
	}

}
