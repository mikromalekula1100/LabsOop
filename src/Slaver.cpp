#include "Slaver.h"
#include "Squirrel.h"
#include "KnightErrant.h"

Slaver::Slaver(int x, int y) : NPC(SlaverType, x, y) {}
Slaver::Slaver(std::istream &is) : NPC(SlaverType, is) {}

void Slaver::print(std::ostream &os)
{
    os << *this;
}

bool Slaver::is_dragon() const 
{
    return true;
}

bool Slaver::accept(std::shared_ptr<NPC> other)
{
    bool success = other->fight(std::make_shared<Slaver>(*this));
    
    return success;
}

bool Slaver::fight(std::shared_ptr<Slaver> other) 
{
    fight_notify(other, false);
    return false;
}

bool Slaver::fight(std::shared_ptr<Squirrel> other) 
{
    fight_notify(other, false);
    return false;
}

bool Slaver::fight(std::shared_ptr<KnightErrant> other) 
{
    fight_notify(other, false);
    return false;
}

void Slaver::save(std::ostream &os) 
{
    os << SlaverType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Slaver &dragon)
{
    os << "dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}