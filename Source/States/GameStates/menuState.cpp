#include "menuState.h"
#include "CSGD_DirectInput.h"
#include "objManager.h"
#include "viewManager.h"
#include "baseObj.h"
#include "game.h"
#include "datatypes.h"
#include "physics.h"
#include "bitFont.h"

#define CURSOR "Resource/ScS_menuCursor.png"

menuState::menuState(int x, int y, unsigned int color, unsigned int highlight)
	: xPos(x), yPos(y), textColor(color), highlightColor(highlight)
{}

void menuState::enter(void)
{
	theInput = inputDevice::GetInstance();
	theFont = bitFont::getInstance();

	menuPos = 0;
	cursorID = viewManager::getInstance()->loadTexture(CURSOR);
}

void menuState::exit(void)
{
	viewManager::getInstance()->releaseTexture(cursorID);
}

bool menuState::input(float dt)
{
	if (theInput->KeyPressed(DIK_RETURN))
	{
		menuHandler();
	}

	if (theInput->KeyPressed(DIK_DOWN))
	{
		if(menuPos < menuLast)
			menuPos++;
		else
			menuPos = 0;
	}

	if(theInput->KeyPressed(DIK_UP))
	{
		if(menuPos > 0)
			menuPos--;
		else
			menuPos = menuLast;
	}

	return true;
}

void menuState::update(float dt)
{

}

void menuState::render(void) const
{
	//Draw menu items
	for(int c = 0; c < menuLast+1; c++)
		if(c != menuPos)
			theFont->drawText(menuItemString[c], xPos, yPos + c * 50, textColor);
		else //For the selected item, use highlight color
			theFont->drawText(menuItemString[c], xPos, yPos + c * 50, highlightColor);

	//Draw meun cursor at the selected item
	viewManager::getInstance()->drawTexture(cursorID,
		&vector3(float(xPos-70), float(yPos-20 + menuPos * 50), 0));
}