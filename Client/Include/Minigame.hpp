#ifndef MINIGAME_HPP
#define MINIGAME_HPP

#include "Events.hpp"
#include "Player.hpp"
#include "States.hpp"

class Minigame
{
private:
    //std::vector<> Leaderboard;
    Player player;
    GameStates state;
public:
    Minigame();
    ~Minigame();
    bool Start();
private:
    void HandleEvent(GameEvents event);

    Player getPlayerData();
    bool StartGame(const Player &player);
    bool Stop();
    bool AddScore(const Player &player, int score);
    bool LoadLeaderboard();
};

#endif