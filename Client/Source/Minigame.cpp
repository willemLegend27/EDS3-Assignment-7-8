#include "Minigame.hpp"

Minigame::Minigame()
{}

void Minigame::HandleEvent(GameEvents event)
{
    switch (this->state)
    {
    case GameStates::SETUP:
        this->state = HandleSetupState(event);
        break;
    case GameStates::PLAYING:
        this->state = HandlePlayingState(event);
        break;
    case GameStates::LEADERBOARD:
        this->state = HandleLeaderboardState(event);
        break;
    default:
        break;
    }
}

GameStates HandleSetupState(GameEvents event)
{
    GameStates currentState = GameStates::SETUP;
    return currentState;
}

GameStates HandlePlayingState(GameEvents event)
{
    GameStates currentState = GameStates::SETUP;
    return currentState;
}

GameStates HandleLeaderboardState(GameEvents event)
{
    GameStates currentState = GameStates::SETUP;
    return currentState;
}