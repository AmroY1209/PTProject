#include "CopyAction.h"
#include "..\ApplicationManager.h"

CopyAction::CopyAction(ApplicationManager* pApp):Action(pApp)
{
	Cx =0;
	Cy =0;
}
CopyAction::~CopyAction()
{
}
void CopyAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Copy Figure: Selected figure has been copied to the Clipboard");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void CopyAction::Execute()
{
	ReadActionParameters();
	fig = pManager->GetFigure(Cx, Cy);  //Get the coordinates of the selected figure
	pManager->SetClipboard(fig);
	pManager->SetIsFigCut(false);       //The Figure is copied not cut
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}