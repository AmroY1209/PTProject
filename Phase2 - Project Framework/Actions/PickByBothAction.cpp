#include "PickByBothAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"


PickByBothAction::PickByBothAction(ApplicationManager* pApp) :Action(pApp)
{
	Cx = 0;
	Cy = 0;
	no_of_figs = 0;
	rightPick = 0;
	wrongPick = 0;
	for (int i = 0; i < 35; i++)
	{
		num_of_combinations[i] = 0;
	}
}

PickByBothAction::~PickByBothAction()
{
}

void PickByBothAction::printScore(int score)
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
void PickByBothAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Game: Pick Figures by both Type and Color , Click on a figure to start playing ");

	fig = pManager->GetDrawnFigs();
	no_of_figs = pManager->GetFigCount();
	for (int i = 0; i < no_of_figs; i++)
	{
		if (fig[i]->GetGFXINFO().isFilled && !(dynamic_cast<CLine*>(fig[i])))   //counts the number of each combination
		{
			if (operator==(fig[i]->GetGFXINFO().FillClr, WHITE))
			{
				if (dynamic_cast<CRectangle*>(fig[i]))
					num_of_combinations[0]++;
				else if (dynamic_cast<CTriangle*>(fig[i]))
					num_of_combinations[1]++;
				else
					num_of_combinations[2]++;
			}
			else if (operator==(fig[i]->GetGFXINFO().FillClr, BLACK))
			{
				if (dynamic_cast<CRectangle*>(fig[i]))
					num_of_combinations[3]++;
				else if (dynamic_cast<CTriangle*>(fig[i]))
					num_of_combinations[4]++;
				else
					num_of_combinations[5]++;
			}
			else if (operator==(fig[i]->GetGFXINFO().FillClr, RED))
			{
				if (dynamic_cast<CRectangle*>(fig[i]))
					num_of_combinations[6]++;
				else if (dynamic_cast<CTriangle*>(fig[i]))
					num_of_combinations[7]++;
				else
					num_of_combinations[8]++;
			}
			else if (operator==(fig[i]->GetGFXINFO().FillClr, GREEN))
			{
				if (dynamic_cast<CRectangle*>(fig[i]))
					num_of_combinations[9]++;
				else if (dynamic_cast<CTriangle*>(fig[i]))
					num_of_combinations[10]++;
				else
					num_of_combinations[11]++;
			}
			else if (operator==(fig[i]->GetGFXINFO().FillClr, BLUE))
			{
				if (dynamic_cast<CRectangle*>(fig[i]))
					num_of_combinations[12]++;
				else if (dynamic_cast<CTriangle*>(fig[i]))
					num_of_combinations[13]++;
				else
					num_of_combinations[14]++;
			}
			else if (operator==(fig[i]->GetGFXINFO().FillClr, YELLOW))
			{
				if (dynamic_cast<CRectangle*>(fig[i]))
					num_of_combinations[15]++;
				else if (dynamic_cast<CTriangle*>(fig[i]))
					num_of_combinations[16]++;
				else
					num_of_combinations[17]++;
			}
			else if (operator==(fig[i]->GetGFXINFO().FillClr, PURPLE))
			{
				if (dynamic_cast<CRectangle*>(fig[i]))
					num_of_combinations[18]++;
				else if (dynamic_cast<CTriangle*>(fig[i]))
					num_of_combinations[19]++;
				else
					num_of_combinations[20]++;
			}
			else if (operator==(fig[i]->GetGFXINFO().FillClr, ORANGE))
			{
				if (dynamic_cast<CRectangle*>(fig[i]))
					num_of_combinations[21]++;
				else if (dynamic_cast<CTriangle*>(fig[i]))
					num_of_combinations[22]++;
				else
					num_of_combinations[23]++;
			}
		}
		else if (dynamic_cast<CLine*>(fig[i]))
		{
			if (operator==(fig[i]->GetGFXINFO().DrawClr, WHITE))
				num_of_combinations[24]++;
			else if (operator==(fig[i]->GetGFXINFO().DrawClr, BLACK))
				num_of_combinations[25]++;
			else if (operator==(fig[i]->GetGFXINFO().DrawClr, RED))
				num_of_combinations[26]++;
			else if (operator==(fig[i]->GetGFXINFO().DrawClr, GREEN))
				num_of_combinations[27]++;
			else if (operator==(fig[i]->GetGFXINFO().DrawClr, BLUE))
				num_of_combinations[28]++;
			else if (operator==(fig[i]->GetGFXINFO().DrawClr, YELLOW))
				num_of_combinations[29]++;
			else if (operator==(fig[i]->GetGFXINFO().DrawClr, PURPLE))
				num_of_combinations[30]++;
			else if (operator==(fig[i]->GetGFXINFO().DrawClr, ORANGE))
				num_of_combinations[31]++;
		}
		else if ((fig[i]->GetGFXINFO().isFilled == false))   //number of uncolored figures
		{
			if (dynamic_cast<CRectangle*>(fig[i]))
				num_of_combinations[32]++;
			else if (dynamic_cast<CTriangle*>(fig[i]))
				num_of_combinations[33]++;
			else
				num_of_combinations[34]++;
		}
		fig[i]->unHide();
	}
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void PickByBothAction::Execute()
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
				if (dynamic_cast<CRectangle*>(type))
				{
					no_to_pick = num_of_combinations[0];
					pOut->PrintMessage("Pick all white rectangles!");
					wR = 1;
				}
				else if (dynamic_cast<CTriangle*>(type))
				{
					no_to_pick = num_of_combinations[1];
					pOut->PrintMessage("Pick all white triangles!");
					wT = 2;
				}
				else
				{
					no_to_pick = num_of_combinations[2];
					pOut->PrintMessage("Pick all white circles!");
					wC = 3;
				}
			}
			else if (operator==(type->GetGFXINFO().FillClr, BLACK))
			{
				if (dynamic_cast<CRectangle*>(type))
				{
					no_to_pick = num_of_combinations[3];
					pOut->PrintMessage("Pick all black rectangles!");
					bR = 4;
				}
				else if (dynamic_cast<CTriangle*>(type))
				{
					no_to_pick = num_of_combinations[4];
					pOut->PrintMessage("Pick all black triangles!");
					bT = 5;
				}
				else
				{
					no_to_pick = num_of_combinations[5];
					pOut->PrintMessage("Pick all black circles!");
					bC = 6;
				}
			}
			else if (operator==(type->GetGFXINFO().FillClr, RED))
			{
				if (dynamic_cast<CRectangle*>(type))
				{
					no_to_pick = num_of_combinations[6];
					pOut->PrintMessage("Pick all red rectangles!");
					rR = 7;
				}
				else if (dynamic_cast<CTriangle*>(type))
				{
					no_to_pick = num_of_combinations[7];
					pOut->PrintMessage("Pick all red triangles!");
					rT = 8;
				}
				else
				{
					no_to_pick = num_of_combinations[8];
					pOut->PrintMessage("Pick all red circles!");
					rC = 9;
				}
			}
			else if (operator==(type->GetGFXINFO().FillClr, GREEN))
			{
				if (dynamic_cast<CRectangle*>(type))
				{
					no_to_pick = num_of_combinations[9];
					pOut->PrintMessage("Pick all green rectangles!");
					gR = 10;
				}
				else if (dynamic_cast<CTriangle*>(type))
				{
					no_to_pick = num_of_combinations[10];
					pOut->PrintMessage("Pick all green triangles!");
					gT = 11;
				}
				else
				{
					no_to_pick = num_of_combinations[11];
					pOut->PrintMessage("Pick all green circles!");
					gC = 12;
				}
			}
			else if (operator==(type->GetGFXINFO().FillClr, BLUE))
			{
				if (dynamic_cast<CRectangle*>(type))
				{
					no_to_pick = num_of_combinations[12];
					pOut->PrintMessage("Pick all blue rectangles!");
					blueR = 13;
				}
				else if (dynamic_cast<CTriangle*>(type))
				{
					no_to_pick = num_of_combinations[13];
					pOut->PrintMessage("Pick all blue triangles!");
					blueT = 14;
				}
				else
				{
					no_to_pick = num_of_combinations[14];
					pOut->PrintMessage("Pick all blue circles!");
					blueC = 15;
				}
			}
			else if (operator==(type->GetGFXINFO().FillClr, YELLOW))
			{
				if (dynamic_cast<CRectangle*>(type))
				{
					no_to_pick = num_of_combinations[15];
					pOut->PrintMessage("Pick all yellow rectangles!");
					yR = 16;
				}
				else if (dynamic_cast<CTriangle*>(type))
				{
					no_to_pick = num_of_combinations[16];
					pOut->PrintMessage("Pick all yellow triangles!");
					yT = 17;
				}
				else
				{
					no_to_pick = num_of_combinations[17];
					pOut->PrintMessage("Pick all yellow circles!");
					yC = 18;
				}
			}
			else if (operator==(type->GetGFXINFO().FillClr, PURPLE))
			{
				if (dynamic_cast<CRectangle*>(type))
				{
					no_to_pick = num_of_combinations[18];
					pOut->PrintMessage("Pick all purple rectangles!");
					pR = 19;
				}
				else if (dynamic_cast<CTriangle*>(type))
				{
					no_to_pick = num_of_combinations[19];
					pOut->PrintMessage("Pick all purple triangles!");
					pT = 20;
				}
				else
				{
					no_to_pick = num_of_combinations[20];
					pOut->PrintMessage("Pick all purple circles!");
					pC = 21;
				}
			}
			else if (operator==(type->GetGFXINFO().FillClr, ORANGE))
			{
				if (dynamic_cast<CRectangle*>(type))
				{
					no_to_pick = num_of_combinations[21];
					pOut->PrintMessage("Pick all orange rectangles!");
					oR = 22;
				}
				else if (dynamic_cast<CTriangle*>(type))
				{
					no_to_pick = num_of_combinations[22];
					pOut->PrintMessage("Pick all orange triangles!");
					oT = 23;
				}
				else
				{
					no_to_pick = num_of_combinations[23];
					pOut->PrintMessage("Pick all orange circles!");
					oC = 24;
				}
			}
		}
		else if (dynamic_cast<CLine*>(type))
		{
			if (operator==(type->GetGFXINFO().DrawClr, WHITE))
			{
				no_to_pick = num_of_combinations[24];
				pOut->PrintMessage("Pick all white lines!");
				wL = 25;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, BLACK))
			{
				no_to_pick = num_of_combinations[25];
				pOut->PrintMessage("Pick all black lines!");
				bL = 26;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, RED))
			{
				no_to_pick = num_of_combinations[26];
				pOut->PrintMessage("Pick all red lines!");
				rL = 27;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, GREEN))
			{
				no_to_pick = num_of_combinations[27];
				pOut->PrintMessage("Pick all green lines!");
				gL = 28;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, BLUE))
			{
				no_to_pick = num_of_combinations[28];
				pOut->PrintMessage("Pick all blue lines!");
				blueL = 29;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, YELLOW))
			{
				no_to_pick = num_of_combinations[29];
				pOut->PrintMessage("Pick all yellow lines!");
				yL = 30;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, PURPLE))
			{
				no_to_pick = num_of_combinations[30];
				pOut->PrintMessage("Pick all purple lines!");
				pL = 31;
			}
			else if (operator==(type->GetGFXINFO().DrawClr, ORANGE))
			{
				no_to_pick = num_of_combinations[31];
				pOut->PrintMessage("Pick all orange lines!");
				oL = 32;
			}
		}
		else if ((type->GetGFXINFO().isFilled == false))   //number of uncolored figures
		{
			if (dynamic_cast<CRectangle*>(type))
			{
				no_to_pick = num_of_combinations[32];
				pOut->PrintMessage("Pick all uncolored rectangles!");
				uncoloredR = 33;
			}
			else if (dynamic_cast<CTriangle*>(type))
			{
				no_to_pick = num_of_combinations[33];
				pOut->PrintMessage("Pick all uncolored triangles!");
				uncoloredT = 34;
			}
			else
			{
				no_to_pick = num_of_combinations[34];
				pOut->PrintMessage("Pick all uncolored circles!");
				uncoloredC = 35;
			}
		}
		while (no_to_pick > 0)
		{
			pIn->GetPointClicked(Cx, Cy);
			if (Cy > UI.ToolBarHeight || Cx > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				CFigure* selectedFigure = pManager->GetFigure(Cx, Cy);
				if (selectedFigure != NULL)
				{
					if (operator==(selectedFigure->GetGFXINFO().FillClr, WHITE) && (dynamic_cast<CRectangle*>(selectedFigure)) && wR == 1)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, WHITE) && (dynamic_cast<CTriangle*>(selectedFigure)) && wT == 2)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, WHITE) && (dynamic_cast<CCircle*>(selectedFigure)) && wC == 3)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, BLACK) && (dynamic_cast<CRectangle*>(selectedFigure)) && bR == 4)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, BLACK) && (dynamic_cast<CTriangle*>(selectedFigure)) && bT == 5)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, BLACK) && (dynamic_cast<CCircle*>(selectedFigure)) && bC == 6)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, RED) && (dynamic_cast<CRectangle*>(selectedFigure)) && rR == 7)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, RED) && (dynamic_cast<CTriangle*>(selectedFigure)) && rT == 8)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, RED) && (dynamic_cast<CCircle*>(selectedFigure)) && rC == 9)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, GREEN) && (dynamic_cast<CRectangle*>(selectedFigure)) && gR == 10)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, GREEN) && (dynamic_cast<CTriangle*>(selectedFigure)) && gT == 11)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, GREEN) && (dynamic_cast<CCircle*>(selectedFigure)) && gC == 12)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, BLUE) && (dynamic_cast<CRectangle*>(selectedFigure)) && blueR == 13)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, BLUE) && (dynamic_cast<CTriangle*>(selectedFigure)) && blueT == 14)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, BLUE) && (dynamic_cast<CCircle*>(selectedFigure)) && blueC == 15)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, YELLOW) && (dynamic_cast<CRectangle*>(selectedFigure)) && yR == 16)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, YELLOW) && (dynamic_cast<CTriangle*>(selectedFigure)) && yT == 17)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, YELLOW) && (dynamic_cast<CCircle*>(selectedFigure)) && yC == 18)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, PURPLE) && (dynamic_cast<CRectangle*>(selectedFigure)) && pR == 19)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, PURPLE) && (dynamic_cast<CTriangle*>(selectedFigure)) && pT == 20)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, PURPLE) && (dynamic_cast<CCircle*>(selectedFigure)) && pC == 21)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, ORANGE) && (dynamic_cast<CRectangle*>(selectedFigure)) && oR == 22)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, ORANGE) && (dynamic_cast<CTriangle*>(selectedFigure)) && oT == 23)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().FillClr, ORANGE) && (dynamic_cast<CCircle*>(selectedFigure)) && oC == 24)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, WHITE) && (dynamic_cast<CLine*>(selectedFigure)) && wL == 25)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, BLACK) && (dynamic_cast<CLine*>(selectedFigure)) && bL == 26)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, RED) && (dynamic_cast<CLine*>(selectedFigure)) && rL == 27)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, GREEN) && (dynamic_cast<CLine*>(selectedFigure)) && gL == 28)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, BLUE) && (dynamic_cast<CLine*>(selectedFigure)) && blueL == 29)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, YELLOW) && (dynamic_cast<CLine*>(selectedFigure)) && yL == 30)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, PURPLE) && (dynamic_cast<CLine*>(selectedFigure)) && pL == 31)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if (operator==(selectedFigure->GetGFXINFO().DrawClr, ORANGE) && (dynamic_cast<CLine*>(selectedFigure)) && oL == 32)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if ((selectedFigure->GetGFXINFO().isFilled == false) && (dynamic_cast<CRectangle*>(selectedFigure)) && uncoloredR == 33)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if ((selectedFigure->GetGFXINFO().isFilled == false) && (dynamic_cast<CTriangle*>(selectedFigure)) && uncoloredT == 34)
					{
						printScore(1);
						selectedFigure->hide();
						pManager->UpdateInterface_PlayMode();
						no_to_pick--;
					}
					else if ((selectedFigure->GetGFXINFO().isFilled == false) && (dynamic_cast<CCircle*>(selectedFigure)) && uncoloredC == 35)
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


void  PickByBothAction::Undo()
{

}
void PickByBothAction::Redo()
{

}