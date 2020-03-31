#include "stdafx.h"
#include "aStarScene.h"

aStarScene::aStarScene() :_rat(new rat)
{
	//박쥐 위치 잡아주기
	_rat->init();
}

aStarScene::~aStarScene()
{
	delete _rat;
}

HRESULT aStarScene::init(tagTile  _tile[])
{
	RECT temp;

	exTile = NULL;
	enemyDirection = DIRECTION_DOWN;
	enemyMoveOk = false;

	moveCount = 0;

	deltaTime = 0;

	m_startX = 0;
	m_startY = 0;

	m_endX = 0;
	m_endY = 0;

	//타일 셋팅
	for (int i = 0; i < astarTileY; i++)
	{
		for (int j = 0; j < astarTileX; j++)
		{
			tile[j + i * astarTileX].rc = _tile[(i + 12) * 50 + (j + 4)].rc;
		}
	}

	startTile = endTile = -1;

	currentselect = SELECT_START;

	isFind = false;
	noPath = false;
	startAstar = false;


	temp.left = tile[20].rc.left;
	temp.top = tile[20].rc.top;
	temp.right = tile[20].rc.right;
	temp.bottom = tile[20].rc.bottom;

	_rat->setrat(temp);
	_enemyrect = _rat->getratInfo().rc;

	blockType();


	return S_OK;
}

void aStarScene::release() {}

void aStarScene::update(tagTile _tile[], RECT playerRc)
{
	_rat->update();
	RECT temp;

	for (int i = 0; i < openlist.size(); i++)
	{
		for (int j = 0; j < closelist.size(); j++)
		{
			for (int z = 0; z < pathList.size(); z++)
			{
				if (IntersectRect(&temp, &_rat->getrat(), &PLAYER->getweapon()))
				{
					openlist.erase(openlist.begin() + i);
					closelist.erase(closelist.begin() + j);
					pathList.erase(pathList.begin() + z); 
				//	_rat->release();
				}
			}
		}
	}


	RECT temp1;
	PLAYER->getPlayerrect() = playerRc;
	deltaTime = TIMEMANAGER->getElapsedTime();
	pastTime += deltaTime;

	if (IntersectRect(&temp1, &playerRc, &_rat->_rat.collison1) && !firstPos && !startAstar)
	{
		currentselect = SELECT_START;
		startAstar = true;
		enemylistSet();
	}

	playerTileSet(playerRc);

	if (!isFind && startAstar && !noPath)
	{
		Astar();
	}
	if (isFind)
	{
		rectMoveDirect();
	}
	if (enemyMoveOk)
	{
		switch (enemyDirection)
		{
		case DIRECTION_LEFT:
			if (moveX + 4 < toGoX)
			{
				toGoX = _enemyrect.left;
				if (pastTime > addCharDeley)
				{
					OffsetRect(&_enemyrect, -4, 0);
					_rat->setrat(_enemyrect);
				}
			}
			else enemyMoveOk = false;
			break;
		case DIRECTION_RIGHT:
			if (moveX + 4 > toGoX)
			{
				toGoX = _enemyrect.right;
				if (pastTime > addCharDeley)
				{
					OffsetRect(&_enemyrect, 4, 0);
					_rat->setrat(_enemyrect);
				}
			}
			else  enemyMoveOk = false;
			break;

		case DIRECTION_UP:
			if (moveY + 4 < toGoY)
			{
				toGoY = _enemyrect.top;
				if (pastTime > addCharDeley)
				{
					OffsetRect(&_enemyrect, 0, -4);
					_rat->setrat(_enemyrect);
				}
			}
			else enemyMoveOk = false;
			break;
		case DIRECTION_DOWN:
			if (moveY + 4 > toGoY)
			{
				toGoY = _enemyrect.bottom;
				if (pastTime > addCharDeley)
				{
					OffsetRect(&_enemyrect, 0, 4);
					_rat->setrat(_enemyrect);
				}
			}
			else enemyMoveOk = false;
			break;
		case DIRECTION_LEFTUP:
			if (moveX + 4 < toGoX && moveY + 4 < toGoY)
			{
				toGoX = _enemyrect.left;
				toGoY = _enemyrect.bottom;
				if (pastTime > addCharDeley)
				{
					OffsetRect(&_enemyrect, -4, 4);
					_rat->setrat(_enemyrect);
				}
			}
			else enemyMoveOk = false;
			break;
		case DIRECTION_RIGHTDOWN:
			if (moveX + 4 > toGoX && moveY + 4 > toGoY)
			{
				toGoX = _enemyrect.right;
				toGoY = _enemyrect.bottom;
				if (pastTime > addCharDeley)
				{
					OffsetRect(&_enemyrect, 4, 4);
					_rat->setrat(_enemyrect);
				}
			}
			else enemyMoveOk = false;
			break;
		case DIRECTION_LEFTDOWN:
			if (moveX + 4 < toGoX && moveY + 4 > toGoY)
			{
				toGoX = _enemyrect.left;
				toGoY = _enemyrect.bottom;
				if (pastTime > addCharDeley)
				{
					OffsetRect(&_enemyrect, -4, 4);
					_rat->setrat(_enemyrect);
				}
			}
			else enemyMoveOk = false;
			break;
		case DIRECTION_RIGHTUP:
			if (moveX + 4 > toGoX && moveY + 4 < toGoY)
			{
				toGoX = _enemyrect.left;
				toGoY = _enemyrect.top;

				if (pastTime > addCharDeley)
				{
					OffsetRect(&_enemyrect, 4, -4);
					_rat->setrat(_enemyrect);
				}
			}
			else enemyMoveOk = false;
			break;
		default:
			break;
		}
	}


}

void aStarScene::render()
{

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		for (int i = 0; i < astarTileSize; i++)
		{
			if (tile[i].block)
			{
				if (i == startTile)
				{
					startTile = -1;
				}
				if (i == endTile)
				{
					endTile = -1;
				}
			}
			else if (i == startTile)
			{
				colorRectangle(getMemDC(), tile[i].rc.left, tile[i].rc.top, 50, 50, 0, 255, 0);
			}
			else if (i == endTile)
			{
				colorRectangle(getMemDC(), tile[i].rc.left, tile[i].rc.top, 50, 50, 255, 0, 0);
			}
			else if (tile[i].showState == STATE_OPEN)
			{
				colorRectangle(getMemDC(), tile[i].rc.left, tile[i].rc.top, 50, 50, 128, 255, 255);
			}
			else if (tile[i].showState == STATE_CLOSE)		//초록줄
			{
				colorRectangle(getMemDC(), tile[i].rc.left, tile[i].rc.top, 50, 50, 128, 255, 0);
			}
			else if (tile[i].showState == STATE_PATH)			//찾는줄
			{
				colorRectangle(getMemDC(), tile[i].rc.left, tile[i].rc.top, 50, 50, 255, 128, 128);
			}
		}
		for (int i = 0; i < astarTileSize; i++)
		{
			if (KEYMANAGER->isToggleKey('0'))
			{
				SetBkMode(getMemDC(), TRANSPARENT);
				//색상
				SetTextColor(getMemDC(), RGB(255, 0, 0));

				char str[128];
				sprintf_s(str, "%d", i);
				TextOut(getMemDC(), tile[i].rc.left, tile[i].rc.top, str, strlen(str));
			}
		}
	//	_rat->render();
		colorRectangle(getMemDC(), _rat->getratInfo().rc.left, _rat->getratInfo().rc.top, 50, 50, 100, 100, 30);
		colorRectangle(getMemDC(), tile[m_endY * 20 + m_endX].rc.left, tile[m_endY * 20 + m_endX].rc.top, 50, 50, 0, 255, 0);  // 플레이어
		colorRectangle(getMemDC(), tile[m_startY * 20 + m_startX].rc.left, tile[m_startY * 20 + m_startX].rc.top, 50, 50, 0, 0, 200);
	}
	_rat->render();
}

void aStarScene::Astar()
{
	int endX = endTile % astarTileX;
	int endY = endTile / astarTileX;																	//  x로 구하기 때문에 astartTIleX로 나눔

	int currentX = currentTile % astarTileX;
	int currentY = currentTile / astarTileX;

	// left , right , up , down , leftup , rightdown , leftdown , rightup
	int dx[] = { -1, 1, 0,0,-1,1,-1,1 };
	int dy[] = { 0, 0, -1, 1, -1, 1,1,-1 };
	bool tempBlock[8];

	//방향 찾는 반복문
	for (int i = 0; i < 8; i++)
	{
		int x = currentX + dx[i];
		int y = currentY + dy[i];
		tempBlock[i] = false;

		//해당방향으로 움직인 타일이 유효한 타일인지 확인
		if (0 <= x && x < astarTileX && 0 <= y && y < astarTileY)
		{
			bool isOpen;
			if (tile[y*astarTileX + x].block) tempBlock[i] = true;
			else
			{
				bool isClose = false;
				for (int j = 0; j < closelist.size(); j++)
				{
					if (closelist[j] == y * astarTileX + x)
					{
						isClose = true;
						break;
					}
				}
				if (isClose) continue;
				if (i < 4)
				{
					tile[y*astarTileX + x].g = 10;
				}
				else
				{
					// leftup인 경우 left나 up에 블락있으면 안됨
					if (i == DIRECTION_LEFTUP &&
						tempBlock[DIRECTION_LEFT] || tempBlock[DIRECTION_UP]) continue;
					// rightdown인 경우 right나 down에 블락있으면 안됨
					if (i == DIRECTION_RIGHTDOWN &&
						tempBlock[DIRECTION_RIGHT] || tempBlock[DIRECTION_DOWN]) continue;
					// rightup인 경우 right나 up에 블락있으면 안됨
					if (i == DIRECTION_RIGHTUP &&
						tempBlock[DIRECTION_RIGHT] || tempBlock[DIRECTION_UP]) continue;
					// leftdown인 경우 left나 down에 블락있으면 안됨
					if (i == DIRECTION_LEFTDOWN &&
						tempBlock[DIRECTION_LEFT] || tempBlock[DIRECTION_DOWN]) continue;
					tile[y * astarTileX + x].g = 14;

				}
				//abs절대값

				tile[y * astarTileX + x].h = (abs(endX - x) + abs(endY - y)) * 10;
				tile[y * astarTileX + x].f = tile[y * astarTileX + x].g + tile[y * astarTileX + x].h;
				// 오픈리스트에 있으면 g 비용 비교 후 처리
				isOpen = false;
				for (int i = 0; i < openlist.size(); i++)
				{
					if (openlist[i] == y * astarTileX + x)
					{
						isOpen = true;
						if (tile[openlist[i]].g > tile[y * astarTileX + x].g)
						{
							tile[openlist[i]].h = tile[y * astarTileX + x].h;
							tile[openlist[i]].g = tile[y * astarTileX + x].g;
							tile[openlist[i]].f = tile[y * astarTileX + x].f;
							tile[openlist[i]].node = currentTile;
						}
					}
				}
				// 없으면 그냥 넣고 부모 설정
					//끝점이  다른 곳으로 가는 곳
				if (!isOpen)
				{
					openlist.push_back(y * astarTileX + x);
					tile[y * astarTileX + x].node = currentTile;
				}
				// find
				if (y * astarTileX + x == endTile)
				{
					isFind = true;
				}
			}
		}
	}

	// 선택 지점 열린목록에서 빼기
	for (iter = openlist.begin(); iter != openlist.end(); ++iter)
	{
		if ((*iter) == currentTile)
		{
			iter = openlist.erase(iter);
			break;
		}
	}
	// not Find
	if (openlist.size() == 0)
	{
		noPath = true;
	}
	// 현재 타일 클로즈리스트에 넣기
	closelist.push_back(currentTile);

	if (openlist.size() != 0)
	{
		// find minimum f cost in openList
		int min = tile[*openlist.begin()].h;
		currentTile = *openlist.begin();
		for (iter = openlist.begin(); iter != openlist.end(); ++iter)
		{
			if (min >= tile[(*iter)].h)
			{
				min = tile[(*iter)].h;
				currentTile = *iter;
			}
		}
	}
	//}
	// 타일 렌더를 위해 상태 저장
	for (int i = 0; i < openlist.size(); i++)
	{
		tile[openlist[i]].showState = STATE_OPEN;
	}
	for (int i = 0; i < closelist.size(); i++)
	{
		tile[closelist[i]].showState = STATE_CLOSE;
	}
	// 길 찾기 성공시 각 타일에 길찾기 상태 저장
	int tempTile = endTile;
	while (tile[tempTile].node != startTile && isFind)
	{
		tempTile = tile[tempTile].node;
		tile[tempTile].showState = STATE_PATH;
		pathList.push_back(tile[tempTile].node);																			//계속 갱신하기 위해서,길(데이터) 담으면 노드에 따라 길
		firstPos = true;
	}
}

void aStarScene::enemylistSet()
{
	if (startAstar)
	{
		m_startX = (_enemyrect.left / 50) - 4;
		m_startY = abs(_enemyrect.top / 50) - 12;

		startTile = m_startY * astarTileX + m_startX;
		currentTile = startTile;

		if (currentTile != exTile)
		{
			openlist.push_back(currentTile);
			exTile = currentTile;
			firstPos = true;
		}
	}
}

void aStarScene::playerTileSet(RECT rc)
{
	PLAYER->getPlayerrect() = rc;
	if (startAstar)  // path를 완료 하면 모든걸 초기화 시켜줘야함 
	{
		m_endX = (rc.left / 50) - 4;
		m_endY = ((rc.top + 25) / 50) - 11;

		endTile = m_endY * astarTileX + m_endX;
	}
}

void aStarScene::blockType()
{
	for (int i = 0; i < astarTileX* astarTileY; i++)
	{
		if (tile[i].obj = OBJ_WALL)
		{
			tile[i].block = false;
		}
	}
}
// enemy 움직이는 곳
void aStarScene::rectMoveDirect()
{
	int max;
	RECT temp = _rat->getratInfo().rc;

	if (pathList.size() >= 1)																//시작점에서 끝점 길이
		max = pathList.size() - 1;
	else max = 0;

	if (max == 0)
	{
		isFind = false;
		noPath = false;
		pathList.clear();
		closelist.clear();
		openlist.clear();
		startAstar = false;
		firstPos = false;
		directionCount = 0;
	}

	if (!enemyMoveOk)
	{
		for (int i = max; i > 0; i)
		{
			i -= directionCount;

			// 벡터의 크기가 0이 아닐때			
			if (i == 0)
			{
				isFind = false;
				pathList.clear();
				closelist.clear();
				openlist.clear();
				startAstar = false;
				firstPos = false;
				noPath = false;
				directionCount = 0;
			}
			if (i > 0)
			{
				if (pathList.at(i) - pathList.at(i - 1) == 21) // 좌상단( x : -50 , y : -50)
				{
					enemyDirection = DIRECTION_LEFTUP;

					moveX = tile[pathList.at(i - 1)].rc.left;
					toGoX = tile[pathList.at(i)].rc.left;

					moveY = tile[pathList.at(i - 1)].rc.bottom;
					toGoY = tile[pathList.at(i)].rc.bottom;

					enemyMoveOk = true;
					directionCount += 1;
					pastTime = 0;
					break;
				}

				if (pathList.at(i) - pathList.at(i - 1) == 20) // 중상단 (y : - 50)
				{
					enemyDirection = DIRECTION_UP;
					moveY = tile[pathList.at(i - 1)].rc.top;
					toGoY = tile[pathList.at(i)].rc.top;
					enemyMoveOk = true;
					directionCount += 1;
					pastTime = 0;
					break;
				}

				if (pathList.at(i) - pathList.at(i - 1) == 19) // 우상단 (x : 50 , y : -50)
				{
					enemyDirection = DIRECTION_RIGHTUP;
					moveX = tile[pathList.at(i - 1)].rc.right;
					toGoX = tile[pathList.at(i)].rc.right;

					moveY = tile[pathList.at(i - 1)].rc.top;
					toGoY = tile[pathList.at(i)].rc.top;
					enemyMoveOk = true;
					directionCount += 1;
					pastTime = 0;
					break;
				}

				if (pathList.at(i) - pathList.at(i - 1) == 1)  // 왼쪽 ( x: -50)
				{
					enemyDirection = DIRECTION_LEFT;
					moveX = tile[pathList.at(i - 1)].rc.left;
					toGoX = tile[pathList.at(i)].rc.left;
					enemyMoveOk = true;
					directionCount += 1;
					pastTime = 0;
					break;
				}

				if (pathList.at(i) - pathList.at(i - 1) == -1)  // 오른쪽 ( x: 50)
				{
					enemyDirection = DIRECTION_RIGHT;
					moveX = tile[pathList.at(i - 1)].rc.right;
					toGoX = tile[pathList.at(i)].rc.right;
					enemyMoveOk = true;
					directionCount += 1;
					pastTime = 0;
					break;
				}

				if (pathList.at(i) - pathList.at(i - 1) == -19) // 좌하단 (x: -50 , y: 50)
				{
					enemyDirection = DIRECTION_LEFTDOWN;
					moveX = tile[pathList.at(i - 1)].rc.left;
					toGoX = tile[pathList.at(i)].rc.left;

					moveY = tile[pathList.at(i - 1)].rc.bottom;
					toGoY = tile[pathList.at(i)].rc.bottom;

					enemyMoveOk = true;
					directionCount += 1;
					pastTime = 0;
					break;
				}

				if (pathList.at(i) - pathList.at(i - 1) == -20) // 중하단
				{
					enemyDirection = DIRECTION_DOWN;
					moveY = tile[pathList.at(i - 1)].rc.bottom;
					toGoY = tile[pathList.at(i)].rc.bottom;
					enemyMoveOk = true;
					directionCount += 1;
					pastTime = 0;
					break;
				}

				if (pathList.at(i) - pathList.at(i - 1) == -21) // 우하단 ( x: 50 , y :50)
				{
					enemyDirection = DIRECTION_RIGHTDOWN;
					moveX = tile[pathList.at(i - 1)].rc.right;
					toGoX = tile[pathList.at(i)].rc.right;

					moveY = tile[pathList.at(i - 1)].rc.bottom;
					toGoY = tile[pathList.at(i)].rc.bottom;
					enemyMoveOk = true;
					directionCount += 1;
					pastTime = 0;
					break;
				}
			}
		}
	}
}

void aStarScene::remove(int num)
{

}
