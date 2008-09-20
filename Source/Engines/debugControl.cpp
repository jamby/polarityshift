#include "debugControl.h"
#include "../objects/objManager.h"
#include "../wrappers/viewManager.h"
#include "CTileEngine.h"
#include "../wrappers/dxrenderer.h"
#include "../eventSystem/eventIDs.h"
#include "../eventSystem/gameEvent.h"
#include "../objects/baseObj.h"

#define RENDERER dxRenderer

debugControl::debugControl() : ready(false), locked(false)
{
	OM = objManager::getInstance();
	VM = viewManager::getInstance();
	TE = CTileEngine::GetInstance();
	Re = RENDERER::getInstance();

	dot.top = dot.left = -2;
	dot.bottom = dot.right = 2;
}

debugControl::~debugControl()
{
}

void debugControl::initialize()
{
	uCount = rCount = 0;
	//In case anything needs to be done.
	getMapCollisions();

	ready = true;
}

void debugControl::shutdown()
{
}

void debugControl::update(float dt)
{
	if(uCount > rCount)
		return;

	if(locked)
		Sleep(1);

	locked = true;
	lineGroups.clear();
	posPts.clear();
	
	const std::vector<baseObj*> objl = OM->getList();
	for(unsigned c = 0; c < objl.size(); c++)
	{
		drawGroup lines;

		const polygon* poly = objl[c]->getCollisionPoly();
		for(int d = 0; d < poly->vertexCount; d++)
			lines.pts.push_back(poly->vertecies[d].coords);

		lineGroups.push_back(lines);

		const rect& re = objl[c]->getCollisionRect();

		/*drawGroup box;

		box.pts.push_back(vector3((float)re.left, (float)re.top));
		box.pts.push_back(vector3((float)re.right, (float)re.top));
		box.pts.push_back(vector3((float)re.right, (float)re.bottom));
		box.pts.push_back(vector3((float)re.left, (float)re.bottom));

		lineGroups.push_back(box);*/

		posPts.push_back(objl[c]->getPosition());

	}
	uCount++;
	locked = false;

	//The idea is for text displays, but that's for later.
}

void debugControl::render()
{
	if(rCount >= uCount)
		return;

	if(!ready)
		return;

	Re->EndSprites();
	Re->BeginLines();

	if(locked)
		Sleep(1);

	locked = true;
	for(unsigned c = 0; c < lineGroups.size(); c++)
	{
		for(unsigned d = 1; d < lineGroups[c].pts.size(); d++)
		{
			if(d >= lineGroups[c].pts.size())
				continue;

			Re->drawLine(lineGroups[c].pts[d - 1],
							 lineGroups[c].pts[d], 0xff00ffff);
		}
		if(lineGroups[c].pts.size() > 2)
			Re->drawLine(lineGroups[c].pts[lineGroups[c].pts.size() -1], lineGroups[c].pts[0], 0xff00ffff);
	}

	for(unsigned c = 0; c < mapLines.size(); c++)
	{
		for(unsigned d = 1; d < mapLines[c].pts.size(); d++)
		{
			Re->drawLine(mapLines[c].pts[d - 1],
							 mapLines[c].pts[d], 0xff00ffff);
		}
		if(mapLines[c].pts.size() > 2)
			Re->drawLine(mapLines[c].pts[mapLines[c].pts.size() -1], mapLines[c].pts[0], 0xff00ffff);
	
	}
	for(unsigned c = 0; c < magLines.size(); c++)
	{
		for(unsigned d = 1; d < magLines[c].pts.size(); d++)
		{
			Re->drawLine(magLines[c].pts[d - 1],
				magLines[c].pts[d], 0xff88ffff);
		}
		if(magLines[c].pts.size() > 2)
			Re->drawLine(magLines[c].pts[magLines[c].pts.size() -1], magLines[c].pts[0], 0xff00ffff);

	}
	rect draw;
	for(unsigned c = 0; c < posPts.size(); c++)
	{
		draw.left = dot.left + (int)posPts[c].x;
		draw.right = dot.right + (int)posPts[c].x;
		draw.top = dot.top + (int)posPts[c].y;
		draw.bottom = dot.bottom + (int)posPts[c].y;

		Re->drawRect(draw, 0x000000ff);
	}
	rCount++;
	locked = false;

	Re->EndLines();
	Re->EndNoPresent();
	Re->BeginScene();
	Re->BeginSprites();
}

void debugControl::HandleEvent(gameEvent *ev)
{
	switch(ev->getEventID())
	{
	case EVENT_LEVELLOADED:
		ready = false;
		getMapCollisions();
		ready = true;
	default:
		break;
	}
}

void debugControl::getMapCollisions()
{
	vector<RECT>& colRects= TE->GetCollisions();
	vector<RECT>& magRects = TE->GetMagnets();

	mapLines.clear();
	magLines.clear();

	for(unsigned c = 0; c < colRects.size(); c++)
	{
		drawGroup lines;

		lines.pts.push_back(vector3((float)colRects[c].left, (float)colRects[c].top));
		lines.pts.push_back(vector3((float)colRects[c].right, (float)colRects[c].top));
		lines.pts.push_back(vector3((float)colRects[c].right, (float)colRects[c].bottom));
		lines.pts.push_back(vector3((float)colRects[c].left, (float)colRects[c].bottom));

		mapLines.push_back(lines);
	}

	for(unsigned c = 0; c < magRects.size(); c++)
	{
		drawGroup lines;

		lines.pts.push_back(vector3((float)magRects[c].left, (float)magRects[c].top));
		lines.pts.push_back(vector3((float)magRects[c].right, (float)magRects[c].top));
		lines.pts.push_back(vector3((float)magRects[c].right, (float)magRects[c].bottom));
		lines.pts.push_back(vector3((float)magRects[c].left, (float)magRects[c].bottom));

		magLines.push_back(lines);
	}
}