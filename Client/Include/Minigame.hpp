#ifndef MINIGAME_HPP
#define MINIGAME_HPP

#include "Enums/Events.hpp"
#include "Player.hpp"

class Minigame
{
private:
    //std::vector<> Leaderboard;
    Player player;
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