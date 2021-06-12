#pragma once
#include "../ApplicationManager.h"
#include "Action.h"

class ExitAction : public Action
{
	bool Saved;
	string termination;
	char exit;
public:
	ExitAction(ApplicationManager* pmanager);
	virtual void ReadActionParameters();
	virtual void Execute();
	char SaveBefExit();
	~ExitAction();
};