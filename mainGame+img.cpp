#include "stdafx.h"
#include "mainGame.h"

/*
�̹��� ����
*/

void mainGame::maingameimg()
{
	//���� UI
	IMAGEMANAGER->addImage("����", "images/����/����UI/maptool2.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/����/����UI/Ui_menuKinds.bmp", 18 * 3, 18 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����������", "images/����/����UI/Ui_maptool_beforeButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������", "images/����/����UI/Ui_maptool_nextButton.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "images/����/����UI/Ui_cancelButton.bmp", 26 * 2, 12 * 2, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����", "images/����/����UI/Ui_maptool_erase.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ε�", "images/����/����UI/Ui_maptool_load.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "images/����/����UI/Ui_maptool_save.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ��", "images/����/����UI/Ui_maptool_tile.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������Ʈ", "images/����/����UI/Ui_maptool_object.bmp", 200, 80, 2, 1, true, RGB(255, 0, 255));


	//���� �̹���
	IMAGEMANAGER->addFrameImage("�����ٴ�", "images/����/maptool_tile.bmp", 600, 2100, 12, 42, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��1", "images/����/��1.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��2", "images/����/��2.bmp", 300 ,50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��3", "images/����/��3.bmp", 100, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��4", "images/����/��4.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "images/����/������.bmp", 60, 60, true, RGB(255, 0, 255));

	//�÷��̾� �� 
	IMAGEMANAGER->addFrameImage("�Ӹ�", "images/cloth/�Ӹ�.bmp", 33 * 2, 128 * 2, 6, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ĵ�Ƽ", "images/cloth/�ĵ�Ƽ.bmp", 24 * 2, 34 * 2, 3, 4, true, RGB(255, 0, 255));

	//��Ʈ�� ��
	IMAGEMANAGER->addImage("����ȭ��", "images/introscene/title_backGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����1", "images/introscene/title_cloud1.bmp", WINSIZEX * 3, WINSIZEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����2", "images/introscene/title_cloud2.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����3", "images/introscene/title_cloud3.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����4", "images/introscene/title_cloud4.bmp", WINSIZEX * 3, WINSIZEY * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����5", "images/introscene/title_cloud5.bmp", WINSIZEX * 2, WINSIZEY * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����6", "images/introscene/title_cloud10.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����7", "images/introscene/title_cloud6.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "images/introscene/��������.bmp", 600, 350, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "images/introscene/����.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������ư", "images/introscene/map.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������ư", "images/introscene/������.bmp", 148 * 3, 58 * 3, 2, 1, true, RGB(255, 0, 255));

	//���� 
	IMAGEMANAGER->addFrameImage("�ɰ�", "images/����/�ɰ�.bmp", 64*3, 96*3, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "images/����/����.bmp", 64*3, 64*3, 4, 4, true, RGB(255, 0, 255));

	//Ŀ�� 
	IMAGEMANAGER->addFrameImage("Ŀ��", "images/cursor/Ui_cursor.bmp", 128 * 2, 16 * 2, 8, 1, true, RGB(255, 0, 255));
	 
	//�κ��丮
	IMAGEMANAGER->addImage("�κ��丮", "images/�κ��丮/Ui_mainInventory.bmp", 655, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("E���丮", "images/�κ��丮/�κ��丮â.bmp", 680,540, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�κ�ĭ", "images/�κ��丮/�κ��丮���ĭ.bmp", 47, 67, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "images/�κ��丮/��������.bmp", 20*3, 27*3, true, RGB(255, 0, 255));

	//�ǹ�
	IMAGEMANAGER->addImage("����", "images/����/����.bmp", 400, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/����/����.bmp", 400, 140, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/����/����.bmp", 70, 146, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ħ��", "images/����/����/housebed.bmp", 32, 49, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ħ��2", "images/����/����/ħ��2.bmp", 32, 33, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/����/��1.bmp", 240*3, 165*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����1", "images/����/��11.bmp", 240*3, 100*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��1", "images/����/���ٽ�����.bmp", 113*4, 100*4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��11", "images/���ٽ�����1.bmp", 113*4, 150*4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��2", "images/����/��2.bmp", 150*3, 170*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��22", "images/����/��22.bmp", 150*3, 100*3, true, RGB(255, 0, 255));

	//������
	IMAGEMANAGER->addImage("����", "images/item/����.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���ھ���", "images/item/���ھ���.bmp", 14*3, 16*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ݸ��ö�� ����", "images/item/�ݸ��ö�� ����.bmp", 16*3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "images/item/������.bmp", 16 * 3, 14 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�Ǵս� ����","images/item/�Ǵս�����.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "images/item/�ɰ�.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("����", "images/item/����.bmp", 16*3, 16*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "images/item/��.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/item/����.bmp", 16 * 3, 15 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���", "images/item/���.bmp", 11 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���Ѹ���(������)", "images/item/���Ѹ���.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/item/��.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/item/����.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "images/item/�������.bmp", 16 * 3, 16 * 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���(������)", "images/item/���.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����(������)", "images/item/����.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ȣ��(������)", "images/item/ȣ��.bmp", 48, 48, true, RGB(255, 0, 255));

	//UI
	IMAGEMANAGER->addImage("�ð�", "images/UI/Ui_time.bmp", 72*3, 57*3, true, RGB(255, 0, 255));

	//����
	IMAGEMANAGER->addImage("����������", "images/shop/Ui_shop.bmp", 650, 395, true, RGB(255,0,255));
	IMAGEMANAGER->addImage("����ĭ", "images/shop/����ĭ.bmp", 478, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ī��Ʈ", "images/shop/ī��Ʈ.bmp", 100, 50, true, RGB(255, 0, 255));

	//���
	IMAGEMANAGER->addImage("����1", "images/etc/����1.bmp", 48, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����2", "images/etc/����2.bmp", 50*3, 100*3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "images/��Ÿ���/������.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���", "images/��Ÿ���/���.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ܵ�", "images/etc/�ܵ�.bmp", 48, 48, true, RGB(255, 0, 255));

	//����
	IMAGEMANAGER->addImage("����� ��", "images/Ÿ��/�������.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���Ѹ���Ÿ��", "images/Ÿ��/���Ѹ���Ÿ��.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ȣ��Ÿ��", "images/Ÿ��/ȣ��Ÿ��.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���ڳ���", "images/Ÿ��/���ڳ���.bmp", 312, 72, 8,1,true, RGB(255, 0, 255));


	//NPC
	 IMAGEMANAGER->addFrameImage("�ƺ����", "images/NPC/Abigail.bmp", 64 * 3, 32 * 3, 4, 1, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addFrameImage("�˷���", "images/NPC/Alex.bmp", 64 * 3, 64 * 3, 4, 2, true, RGB(255, 0, 255));
	 IMAGEMANAGER->addFrameImage("���ٽ���", "images/NPC/Sebastian.bmp", 64 * 3, 64 * 3, 4, 2, true, RGB(255, 0, 255));


}


