#include "Minigame.hpp"

Minigame::Minigame()
{
}

bool Minigame::Close()
{
    //back to IRC UI
    return false;
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
    {
    case GameEvents::START_GAME:
        HandlePlayingEntry();
        break;
    case GameEvents::SHUTDOWN:
        Minigame::Close();
        break;
    case GameEvents::CHECK_LEADERBOARD:
        HandleLeaderboardEntry();
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
    {
    case GameEvents::SETUP_GAME:
        HandleSetupEntry();
        break;
    case GameEvents::GAME_OVER:
        //minigame.AddScore; minigame.stop
        HandleLeaderboardEntry();
        break;
    //INTERNAL EVENTS
    case GameEvents::MoveLeft:
        break;
    case GameEvents::MoveRight:
        break;
    default:
        break;
    }

    return currentState;
}

GameStates Minigame::HandleLeaderboardState(GameEvents event)
{
    GameStates currentState = GameStates::SETUP;

    switch (event)
    {
    case GameEvents::SETUP_GAME:
        HandleSetupEntry();
        break;
    default:
        break;
    }

    return currentState;
}

void Minigame::HandleSetupEntry()
{
    //ui.printGameMenu()
    //minigame.GetPlayerData(ui.GetPlayer)
}

void Minigame::HandleSetupExit()
{
}

void Minigame::HandlePlayingEntry()
{
    //minigame.StartGame(Player)
}

void Minigame::HandlePlayingExit()
{
}

void Minigame::HandleLeaderboardEntry()
{
    //Minigame::LoadLeaderboard();
}

void Minigame::HandleLeaderboardExit()
{
    //ui.Clear()
}