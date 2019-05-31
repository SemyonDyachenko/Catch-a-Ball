#include "State.h"




State::State(sf::RenderWindow * window,std::stack<State*>* states)
{
	this->window = window;
	this->quit = false; // �� ��������� �������� ������ �� ��������� ����� = false
	this->states = states;
	//this->supportedKeys = supportedKeys;
}

State::~State()
{
}

const bool & State::getQuit() const
{
	return this->quit; // ��������� ������� ��������� ����������
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) /* ���� ������ ������� escape �� ��������� ���������� ������  = true �� ���� �� ����� �� ��������� (state) */
	{
		this->quit = true;
	}
}


void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}


