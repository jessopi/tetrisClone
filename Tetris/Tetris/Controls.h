#pragma once
#include "Ui.h"

class Controls : public Ui
{
public:
	Controls();
	void display(sf::RenderWindow &, int,gameSound &);
private:
	void construct_backButton();
	void construct_textBox();
	tgui::TextBox::Ptr textBox;
	tgui::Button::Ptr backButton;
};