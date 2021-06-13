#include "PickByColorAction.h"
#include "..\ApplicationManager.h"
#include "..\CMUgraphicsLib\colors.cpp"
#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"

PickByColorAction::PickByColorAction(ApplicationManager* pApp) :Action(pApp)
{
	Cx = 0;
	Cy = 0;
	no_of_figs = 0;
	rightPick = 0;
	wrongPick = 0;
	for (int i = 0; i < 9; i++)
	{
		num_of_each_color[i] = 0;
	}
}

PickByColorAction::~PickByColorAction()
{
}

void PickByColorAction::printScore(int score)
{
	string msg;
	if (score == 1)
	{
		rightPick++;
		msg = "Right, Keep Going!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";
	}
	else if (score == 2)
	{
		wrongPick++;
		msg = "Wrong, Look carfully!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";
	}
	else if (score == 3)
		msg = "YOU WIN!, Your score is: " + to_string(rightPick) + " Valid, and " + to_string(wrongPick) + " Invalid.";

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage(msg);
}
void PickByColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Game: Pick Figures by Color , Click on a figure to start playing ");

	fig = pManager->GetDrawnFigs();
	no_of_figs = pManager->GetFigCount();
	for (int i = 0; i < no_of_figs; i++)
	{
		if (fig[i]->GetGFXINFO().isFilled && !(dynamic_cast<CLine*>(fig[i])))   //counts the number of figures of each color
		{
			if (operator==(fig[i]->GetGFXINFO().FillClr, WHITE))
				num_of_each_color[0]++;
			else if (operator==(fig[i]->GetGFXINFO().FillClr, BLACK))
				num_of_each_color[1]++;
			else if (operator==(fig[i]->GetGFXINFO().FillClr, RED))
				num_of_each_color[2]++;
			else if (operator==(fig[i]->GetGFXINFO().FillClr, GREEN))
				num_of_each_color[3]++;
			else if (operator==(fig[i]->GetGFXINFO().FillClr, BLUE))
				num_of_each_color[4]++;
			else if (operator==(fig[i]->GetGFXINFO().FillClr, YELLOW))
				num_of_each_color[5]++;
			else if (operator==(fig[i]->GetGFXINFO().FillClr, PURPLE))
				num_of_each_color[6]++;
			else if (operator==(fig[i]->GetGFXINFO().FillClr, ORANGE))
				num_of_each_color[7]++;
		}
		else if (dynamic_cast<CLine*>(fig[i]))
		{
				if (operator==(fig[i]->GetGFXINFO().DrawClr, WHITE))
					num_of_each_color[0]++;
				else if (operator==(fig[i]->GetGFXINFO().DrawClr, BLACK))
					num_of_each_color[1]++;
				else if (operator==(fig[i]->GetGFXINFO().DrawClr, RED))
					num_of_each_color[2]++;
				else if (operator==(fig[i]->GetGFXINFO().DrawClr, GREEN))
					num_of_each_color[3]++;
				else if (operator==(fig[i]->GetGFXINFO().DrawClr, BLUE))
					num_of_each_color[4]++;
				else if (operator==(fig[i]->GetGFXINFO().DrawClr, YELLOW))
					num_of_each_color[5]++;
				else if (operator==(fig[i]->GetGFXINFO().DrawClr, PURPLE))
					num_of_each_color[6]++;
				else if (operator==(fig[i]->GetGFXINFO().DrawClr, ORANGE))
					num_of_each_color[7]++;
		}
		else
			num_of_each_color[8]++;    //number of uncolored figures  (not line & not colored)

		fig[i]->unHide();
	}

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void PickByColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (no_of_figs > 1)
	{
		CFigure* type = pManager->GetFigure(Cx, Cy);
		if (type->GetGFXINFO().isFilled && !(dynamic_cast<CLine*>(type)))
		{
			if (operator==(type->GetGFXINFO().FillClr, WHITE))
			{
				no_to_pick = num_of_each_color[0];
				pOut->PrintMessage("Pick all white figures!");
				w = 1;
			}
			else if (operator==(type->GetGFXINFO().FillClr, BLACK))
			{
				no_to_pick = num_of_each_color[1];
				pOut->PrintMessage("Pick all black figures!");
				b = 2;
			}
			else if (operator==(type->GetGFXINFO().FillClr, RED))
			{
				no_to_pick = num_of_each_color[2];
				pOut->PrintMessage("Pick all red figures!");
				r = 3;
			}
			else if (operator==(type->GetGFXINFO().FillClr, GREEN))
			{
				no_to_pick = num_of_each_color[3];
				pOut->PrintMessage("Pick all green figures!");
				g = 4;
			}
			else if (operator==(type->GetGFXINFO().FillClr, BLUE))
			{
				no_to_pick = num_of_each_color[4];
				pOut->PrintMessage("Pick all blue figures!");
				blue = 5;
			}
			else if (operator==(type->GetGFXINFO().FillClr, YELLOW))
			{
				no_to_pick = num_of_each_color[5];
				pOut->PrintMessage("Pick all yellow figures!");
				y = 6;
			}
			else if (operator==(type->GetGFXINFO().FillClr, PURPLE))
			{
				no_to_pick = num_of_each_color[6];
				pOut->PrintMessage("Pick all purple figures!");
				p = 7;
			}
			else if (operator==(type->GetGFXINFO().FillClr, ORANGE))
			{
				no_to_pick = num_of_each_color[7];
				pOut->PrintMessage("Pick all orange figures!");
				o = 8;
			}
		}
		else if (dynamic_cast<CLine*>(type))
		{
			if (operator==(type->GetGFXINFO().DrawClr, WHITE))
			{
				no_to_pick = num_of_each_color[0];
				pOut->PrintMessage("Pick all white lines!");
				w = 1;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, BLACK))
			{
				no_to_pick = num_of_each_color[1];
				pOut->PrintMessage("Pick all black lines!");
				b = 2;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, RED))
			{
				no_to_pick = num_of_each_color[2];
				pOut->PrintMessage("Pick all red lines!");
				r = 3;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, GREEN))
			{
				no_to_pick = num_of_each_color[3];
				pOut->PrintMessage("Pick all green lines!");
				g = 4;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, BLUE))
			{
				no_to_pick = num_of_each_color[4];
				pOut->PrintMessage("Pick all blue lines!");
				blue = 5;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, YELLOW))
			{
				no_to_pick = num_of_each_color[5];
				pOut->PrintMessage("Pick all yellow lines!");
				y = 6;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, PURPLE))
			{
				no_to_pick = num_of_each_color[6];
				pOut->PrintMessage("Pick all purple lines!");
				p = 7;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, ORANGE))
			{
				no_to_pick = num_of_each_color[7];
				pOut->PrintMessage("Pick all orange lines!");
				o = 8;
			}
		}
		else
		{
			no_to_pick = num_of_each_color[8];
			pOut->PrintMessage("Pick all uncolored figures!");
			uncolored = 9;
		}
		while (no_to_pick > 0)
		{
			pIn->GetPointClicked(Cx, Cy);
			if (Cy > UI.ToolBarHeight || Cx > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				CFigure* selectedFigure = pManager->GetFigure(Cx, Cy);
				if (selectedFigure != NULL)
				{
					if (operator==(selectedFigure->GetGFXINFO().FillClr, WHITE) && !(dynamic_cast<CLine*>(selectedFigure)) && w==1)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, BLACK) && !(dynamic_cast<CLine*>(selectedFigure)) && b == 2)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, RED) && !(dynamic_cast<CLine*>(selectedFigure)) && r == 3)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, GREEN) && !(dynamic_cast<CLine*>(selectedFigure)) && g == 4)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, BLUE) && !(dynamic_cast<CLine*>(selectedFigure)) && blue == 5)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, YELLOW) && !(dynamic_cast<CLine*>(selectedFigure)) && y == 6)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, PURPLE) && !(dynamic_cast<CLine*>(selectedFigure)) && p == 7)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, ORANGE) && !(dynamic_cast<CLine*>(selectedFigure)) && o == 8)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, WHITE) && (dynamic_cast<CLine*>(selectedFigure)) && w == 1) 
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, BLACK) && (dynamic_cast<CLine*>(selectedFigure)) && b == 2)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, RED) && (dynamic_cast<CLine*>(selectedFigure)) && r == 3)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, GREEN) && (dynamic_cast<CLine*>(selectedFigure)) && g == 4)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, BLUE) && (dynamic_cast<CLine*>(selectedFigure)) && blue == 5)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, YELLOW) && (dynamic_cast<CLine*>(selectedFigure)) && y == 6)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, PURPLE) && (dynamic_cast<CLine*>(selectedFigure)) && p == 7)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, ORANGE) && (dynamic_cast<CLine*>(selectedFigure)) && o == 8)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if ((selectedFigure->GetGFXINFO().isFilled==false) && uncolored == 9)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else
					{
						printScore(2);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
					}
				}
			}
			else
			{
				pOut->PrintMessage("Toolbar clicked, you stopped the game");
				no_to_pick = -1;
			}
			if (no_to_pick == 0)
				printScore(3);
		}
	}
	else
	pOut->PrintMessage("You must draw at least two figures to play!");
	for (int i = 0; i < no_of_figs; i++)
	{
		fig[i]->unHide();
		pManager->UpdateInterface_PlayMode();
	}
}