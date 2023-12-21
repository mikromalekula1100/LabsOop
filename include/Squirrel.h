#pragma once
#include "NPC.h"

struct Squirrel : public NPC
{
    Squirrel(int x, int y);
    Squirrel(std::istream &is);
    void print(std::ostream &os) override;
    void save(std::ostream &os) override;
    bool is_knight() const override;
    bool accept(std::shared_ptr<NPC> other) override;
    bool fight(std::shared_ptr<Slaver> other) override;
    bool fight(std::shared_ptr<Squirrel> other) override;
    bool fight(std::shared_ptr<KnightErrant> other) override;
    friend std::ostream &operator<<(std::ostream &os, Squirrel &knight);
};