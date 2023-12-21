#pragma once
#include "NPC.h"

struct Slaver : public NPC
{
    Slaver(int x, int y);
    Slaver(std::istream &is);

    void print(std::ostream &os) override;

    bool is_dragon() const override;

    bool accept(std::shared_ptr<NPC> other) override;
    bool fight(std::shared_ptr<Slaver> other) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<KnightErrant> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Slaver &dragon);
};