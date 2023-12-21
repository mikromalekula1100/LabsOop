    #pragma once
    #include "NPC.h"

    struct KnightErrant : public NPC
    {
        KnightErrant(int x, int y);
        KnightErrant(std::istream &is);

        void print(std::ostream &os) override;
        void save(std::ostream &os) override;
        bool is_black_knight() const override;

        
        bool accept(std::shared_ptr<NPC> other) override;
        bool fight(std::shared_ptr<Slaver> other) override;
        bool fight(std::shared_ptr<Squirrel> other) override;
        bool fight(std::shared_ptr<KnightErrant> other) override;
        friend std::ostream &operator<<(std::ostream &os, KnightErrant &knight);
    };

    // slavevr