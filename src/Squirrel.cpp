#include "Slaver.h"
#include "Squirrel.h"
#include "KnightErrant.h"

Squirrel::Squirrel(int x, int y) : NPC(SquirrelType, x, y) {}
Squirrel::Squirrel(std::istream &is) : NPC(SquirrelType, is) {}

void Squirrel::print(std::ostream &os)
{
    os << *this;
}

void Squirrel::save(std::ostream &os)
{
    os << SquirrelType << std::endl;
    NPC::save(os);
}
bool Squirrel::is_knight() const
{
    return true;
}

bool Squirrel::accept(std::shared_ptr<NPC> other)
{
    bool success = other->fight(std::make_shared<Squirrel>(*this));

    return success;
}

bool Squirrel::fight(std::shared_ptr<Slaver> other)
{
    fight_notify(other, true);
    return true;
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other)
{
    fight_notify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<KnightErrant> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Squirrel &knight)
{
    os << "knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}