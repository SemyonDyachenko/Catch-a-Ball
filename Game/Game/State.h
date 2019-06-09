#ifndef STATE_H
#define STATE_H


#include "Entity.h"


class State
{
private:

protected:
	std::stack<State*>* states;
	sf::RenderWindow * window; // ����
	//std::map<std::string, int>* supportedKeys;
	//std::map<std::string, int> keybinds;
	bool quit; // ��������� ���������� �� ���������� � ������� ���������� (state)
	
	//res
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;



	std::vector<sf::Texture> textures;

	//funcs
	//virtual void keybinds() = 0;

public:
	State(sf::RenderWindow * window,std::stack<State*>* states); // ����������� ��������� �� ���� sfml ����
	virtual ~State();// ����������� ����������

	const bool& getQuit() const; // �������� �������� quit ������ �� ���������

	virtual void checkForQuit(); // ������� �������� �� ����� ���������

	//������� ������� ����������� ������ ���� ��������������
	virtual void endState() = 0; //���������� �������� ���������
	virtual void updateMousePosition();
	virtual void updateInput(const float& time) = 0; // ������� ������� �������� �� ���������� �������� ���������� 
	virtual void update(const float& time) = 0; // ������ ��������� ����� delta time (Dt)
	virtual void render(sf::RenderWindow * window) = 0; // ������� �������
};

#endif

