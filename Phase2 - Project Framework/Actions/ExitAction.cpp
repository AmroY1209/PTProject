#include "Action.h"
#include "ExitAction.h"
#include "SaveAction.h"
#include "../ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
	Saved = pManager->GetIsSaved();
}

void ExitAction::Execute()
{
	ReadActionParameters();

}


char ExitAction::SaveBefExit()
{
	ReadActionParameters();

	if (!Saved)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		pOut->PrintMessage("Are you sure you want to exit without saving? y/n");
		termination = pIn->GetString(pOut);
		if (termination == "y" || termination == "Y" || termination == "yes")
		{
			exit = 'y';
		}
		else if (termination == "n" || termination == "N" || termination == "no")
		{
			exit = 'n';
			//Action* pAct;
			//pAct = new SaveAction(pManager);
			//exit = 'y';
		}
	}
	else
	{
		exit = 'y';
	}
	return exit;
}
void ExitAction::Undo()
{

}
void ExitAction::Redo()
{

}

ExitAction::~ExitAction()
{

}