/*
 * GuiHandler.h
 *
 * Created: 20. 07. 2020 15:48:33
 *  Author: Megaforce
 */

#include "LCD_Ili9341.h"
#include "ugui.h"
#include "ugui_config.h"
#include "config.h"
#include "Globals.h"
 
#ifndef GuiHandler_H_
#define GuiHandler_H_

void startUp();
void mainScreenTime();
void mainScreenTemp();
void fermentationScreen();

#endif /* GuiHandler_H_ */