#include "NPC.h"
#include "Slaver.h"
#include "Squirrel.h"
#include "KnightErrant.h"

// Text Observer
class TextObserver : public IFightObserver
{
private:
    TextObserver(){};

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static TextObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {       
             
                std::cout << std::endl
                        << "Murder --------" << std::endl;
                attacker->print(std::cout);
                defender->print(std::cout);
        }
    }
};

class FiltObserver : public IFightObserver
{
private:
    FiltObserver(){};

public:
    static std::shared_ptr<IFightObserver> get()
    {
        static FiltObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver *) {});
    }

    void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
    {
        if (win)
        {       
                std::ofstream fs("log.txt", std::ios::app);
                fs<< "Murder --------" << std::endl;
    
                attacker->print(fs);
                defender->print(fs);
                fs<<std::endl;
                fs.flush();
                fs.close();
        }
    }
};

// Фабрики -----------------------------------
std::shared_ptr<NPC> factory(std::istream &is)
{
    std::shared_ptr<NPC> result;
    int type{0};
    if (is >> type)
    {
        switch (type)
        {
        case SlaverType:
            result = std::make_shared<Slaver>(is);
            break;
        case SquirrelType:
            result = std::make_shared<Squirrel>(is);
            break;
        case KnightErrantType:
            result = std::make_shared<KnightErrant>(is);
            break;
        }
    }
    else
        std::cerr << "unexpected NPC type:" << type << std::endl;

    if (result){
        result->subscribe(TextObserver::get());
        result->subscribe(FiltObserver::get());
    }

    return result;
}

std::shared_ptr<NPC> factory(NpcType type, int x, int y)
{
    std::shared_ptr<NPC> result;
    switch (type)
    {
    case SlaverType:
        result = std::make_shared<Slaver>(x, y);
        break;
    case SquirrelType:
        result = std::make_shared<Squirrel>(x, y);
        break;
    case KnightErrantType:
        result = std::make_shared<KnightErrant>(x, y);
        break;
    default:
        break;
    }
    if (result){
        result->subscribe(TextObserver::get());
        result->subscribe(FiltObserver::get());
    }
        

    return result;
}

// save array to file
void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &n : array)
        n->save(fs);
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);
    if (is.good() && is.is_open())
    {
        int count;
        is >> count;
        for (int i = 0; i < count; ++i)
            result.insert(factory(is));
        is.close();
    }
    else
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return result;
}

// print to screen
std::ostream &operator<<(std::ostream &os, const set_t &array)
{
    for (auto &n : array)
        n->print(os);
    return os;
}


set_t fight(const set_t &array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array)
        for (const auto &defender : array)
            if ((attacker != defender) && (attacker->is_close(defender, distance)))
            {   
                VisitorFight fight;
                bool success{false};
                success = attacker->accept(fight, attacker);

                if (success)
                    dead_list.insert(defender);
            }

    return dead_list;
}

int main()
{
    set_t array; 

    // Гененрируем начальное распределение монстров
    std::cout << "Generating ..." << std::endl;
    for (size_t i = 0; i < 15; ++i)
        array.insert(factory(NpcType(std::rand() % 3 + 1),
                             std::rand() % 100,
                             std::rand() % 100));
    std::cout << "Saving ..." << std::endl;

    save(array, "npc.txt");

    std::cout << "Loading ..." << std::endl;
    array = load("npc.txt");

    std::cout << "Fighting ..." << std::endl
              << array;

    for (size_t distance = 20; (distance <= 100) && !array.empty(); distance += 10)
    {
        auto dead_list = fight(array, distance);
        for (auto &d : dead_list)
            array.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;

    }

    std::cout << "Survivors:" << array;

    return 0;
}