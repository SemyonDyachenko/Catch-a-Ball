#include "Game.h"


void Game::initWindow()
{
	/* here init and create window */
	this->vertical_sync_enable = false;
	this->FrameRateLimit = 120;
	this->winSizeX = 800;
	this->winSizeY = 600;
	this->winTitle = "Sfml game";
	this->window = new sf::RenderWindow(sf::VideoMode(winSizeX, winSizeY), winTitle);
	this->window->setVerticalSyncEnabled(this->vertical_sync_enable);
	this->window->setFramerateLimit(this->FrameRateLimit);
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window));
	this->states.push(new GameState(this->window));
}

Game::Game()
{
	this->initWindow();
	this->initStates();
	//this->initKeys();
}


Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) 
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Game::endApplication()
{
	std::cout << "Ending App" << std::endl;
}

void Game::updateDeltaTime()
{
	this->time = this->clock.restart().asSeconds();
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateEvents();

	if (!this->states.empty()) 
	{
		this->states.top()->update(this->time);

		if (this->states.top()->getQuit())
		{

			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
		//App end
	else {
		this->window->close();
		this->endApplication();
	}
	
	
}

void Game::render()
{
	//clear
	window->clear();

	//render here 
	if (!this->states.empty()) {
		this->states.top()->render(this->window);
	}

	// display
	window->display();
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}