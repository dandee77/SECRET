#include "game.h"

Game::Game()
{

}

void Game::Update()
{
    player.Move();
}

void Game::Draw()
{
    player.Draw();
}