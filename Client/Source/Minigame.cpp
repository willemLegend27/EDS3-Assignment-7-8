#include "Minigame.hpp"

Minigame::Minigame()
{
}

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

GameStates Minigame::HandleSetupState(GameEvents event)
{
    GameStates currentState = GameStates::SETUP;

    switch (event)
    //entry/ ui.printGameMenu(); minigame.getPlayerData(ui.getPlayer)
    //events: SHUTDOWN, START_GAME, CHECK_LEADERBOARD
    {
    case GameEvents::SETUP_GAME:
        break;
    case GameEvents::SHUTDOWN:
        break;
    case GameEvents::CHECK_LEADERBOARD:
        break;
    default:
        break;
    }

    return currentState;
}

GameStates Minigame::HandlePlayingState(GameEvents event)
{
    GameStates currentState = GameStates::SETUP;

    switch (event)
    //entry/ minigame.startGame(Player)
    //internal MoveRight, MoveLeft
    //events: SETUP_GAME, GAME_OVER
    {
    default:
        break;
    }

    return currentState;
}

GameStates Minigame::HandleLeaderboardState(GameEvents event)
{
    GameStates currentState = GameStates::SETUP;

    switch (event)
    //entry/ minigame.LoadLeaderboard
    //exit/ ui.ClearScreen()
    //events: SETUP_GAME
    {
    default:
        break;
    }

    return currentState;
}
