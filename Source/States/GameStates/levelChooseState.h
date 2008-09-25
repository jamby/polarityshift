//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	File:			"levelChooseState.h"
//	Author:			Jared Hamby (JH)
//	Purpose:		Handles the level choosing menu
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "menuState.h"

class levelChooseState : public menuState
{
protected:
	enum menuOptions { LEVEL1, LEVEL2, LEVEL3, LEVEL4, LEVEL5, LEVEL6, LEVEL7, LEVEL8, LEVEL9, LEVEL10, BACK, TOTAL };

	int foregroundID;
	float m_fTime, m_fXPer, m_fXLerp, m_fSoundPer, m_fSoundLerp;
	int m_nSelectedLevel;

	float m_fCounter;

	void menuHandler();

	//int m_nParticleImageID;

	levelChooseState(void);
	levelChooseState(const levelChooseState&);
	levelChooseState& operator=(const levelChooseState&);
	virtual ~levelChooseState(void);
public:

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"getInstance"
	//	Last Modified:	September 9th, 2008
	//	Purpose:		Gets the instance of the singleton
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	static levelChooseState* getInstance();

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"enter"
	//	Last Modified:	September 9th, 2008
	//	Purpose:		enters the level choose state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void enter(void);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"exit"
	//	Last Modified:	September 9th, 2008
	//	Purpose:		exits the level choose state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void exit(void);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"udpate"
	//	Last Modified:	September 9th, 2008
	//	Purpose:		updates the level choose state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void update(float dt);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"render"
	//	Last Modified:	September 9th, 2008
	//	Purpose:		renders the level choose state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void render(void) const;

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"input"
	//	Last Modified:	September 18th, 2008
	//	Purpose:		Input for the menu states
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual bool input(float dt);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"Accessors"
	//	Last Modified:	September 9th, 2008
	//	Purpose:		accesses certain variables in the level choose state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	int GetPlayLevel() const { return m_nSelectedLevel; }

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"Mutators"
	//	Last Modified:	September 9th, 2008
	//	Purpose:		modifies certain variables in the level choose state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetPlayLevel(int val) { m_nSelectedLevel = val; }	
	
};
