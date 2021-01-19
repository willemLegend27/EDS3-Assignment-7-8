#ifndef MINIGAME_HPP
#define MINIGAME_HPP

#include "../Enums/Events.hpp"
#include "../Enums/GameEvents.hpp"
#include "../Enums/States.hpp"
#include "Player.hpp"

class Minigame
{
private:
    Player player;
    GameStates state;

public:
    Minigame();
    ~Minigame();
    bool Start();

private:
    void HandleEvent(GameEvents event);

    Player GetPlayerData();
    bool StartGame(const Player &player);
    bool Stop();
    bool AddScore(const Player &player, int score);
    bool LoadLeaderboard();
    GameStates HandleSetupState(GameEvents event);
    GameStates HandlePlayingState(GameEvents event);
    GameStates HandleLeaderboardState(GameEvents event);
};

#endif