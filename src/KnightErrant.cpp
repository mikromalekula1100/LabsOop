#include "Slaver.h"
#include "Squirrel.h"
#include "KnightErrant.h"

KnightErrant::KnightErrant(int x, int y) : NPC(KnightErrantType, x, y) {}
KnightErrant::KnightErrant(std::istream &is) : NPC(KnightErrantType, is) {}

void KnightErrant::print(std::ostream &os)
{
    os << *this;
}

void KnightErrant::save(std::ostream &os)
{
    os << KnightErrantType << std::endl;
    NPC::save(os);
}

bool KnightErrant::is_black_knight() const
{
    return true;
}

bool KnightErrant::accept(std::shared_ptr<NPC> other)
{
    bool success = other->fight(std::make_shared<KnightErrant>(*this));

    return success;
}

bool KnightErrant::fight(std::shared_ptr<Slaver> other)
{
    fight_notify(other, true);
    return true;
}

bool KnightErrant::fight(std::shared_ptr<Squirrel> other)
{
    fight_notify(other, true);
    return true;
}

bool KnightErrant::fight(std::shared_ptr<KnightErrant> other)
{
    fight_notify(other, true);
    return true;
}

std::ostream &operator<<(std::ostream &os, KnightErrant &knight)
{
    os << "black knight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}