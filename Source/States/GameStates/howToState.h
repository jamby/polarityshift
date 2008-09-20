//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	File:			"howToState.h"
//	Author:			Jared Hamby (JH)
//	Purpose:		Handles the how to state
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "menuState.h"
class CSGD_FModManager;

class howToState : public menuState
{
protected:
	enum menuOptions { BACK, TOTAL };

	int foregroundID;
	float m_fTime, m_fXPer, m_fXLerp, m_fSoundPer, m_fSoundLerp;
	CSGD_FModManager* m_pFMOD;
	bool m_bMainMenu;

	void menuHandler();

	//int m_nParticleImageID;

	howToState(void);
	howToState(const howToState&);
	howToState& operator=(const howToState&);
	virtual ~howToState(void);
public:

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"getInstance"
	//	Last Modified:	September 19th, 2008
	//	Purpose:		Gets the instance of the singleton
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	static howToState* getInstance();

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"enter"
	//	Last Modified:	September 19th, 2008
	//	Purpose:		enters the credits state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void enter(void);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"exit"
	//	Last Modified:	September 19th, 2008
	//	Purpose:		exits the credits state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void exit(void);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"udpate"
	//	Last Modified:	September 19th, 2008
	//	Purpose:		updates the credits state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void update(float dt);

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//	Function:		"render"
	//	Last Modified:	September 19th, 2008
	//	Purpose:		renders the credits state
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void render(void) const;
};