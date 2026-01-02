# CPP 03

Inheritance

---

## 🤖 ex00 — ClapTrap
What I did
- Implemented a simple class that holds the robot state and three main actions: `attack`, `takeDamage`, `beRepaired`.
- Added the canonical functions: default ctor, param ctor (name), copy ctor, copy assignment, dtor.
- Used initialization lists everywhere and kept members private.

Key skeleton I used
```cpp
// ClapTrap.hpp (structure only)
class ClapTrap {
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap&);
    ClapTrap& operator=(const ClapTrap&);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
    std::string _name;
    unsigned int _hp;
    unsigned int _energy;
    unsigned int _attack;
};
```

Why this way
- Keeping canonical form avoids surprises in copies and tests.
- Initialization lists give predictable member values from the start.

---

## 🙌 ex01 — FragTrap
What I did
- Derived `FragTrap` from `ClapTrap`.
- Kept ClapTrap's members inherited; I only changed the default values (hp, energy, attack) in the FragTrap constructors.
- Added `highFivesGuys()` as FragTrap's unique method.
- Ensured construction/destruction messages show the right order (ClapTrap constructed first, FragTrap after).

Skeleton
```cpp
// FragTrap.hpp
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap&);
    FragTrap& operator=(const FragTrap&);
    ~FragTrap();

    void highFivesGuys(void);
};
```

Why this way
- I avoided redeclaring ClapTrap members. FragTrap just sets new defaults by calling the appropriate ClapTrap ctor.

---

## 💎 ex02/ex03 — DiamondTrap
What I did
- `DiamondTrap` combines `FragTrap` and `ScavTrap`. To avoid two ClapTrap subobjects I used virtual inheritance on both intermediate classes (Frag/Scav inherit from ClapTrap virtually). This guarantees a single ClapTrap inside DiamondTrap.
- `DiamondTrap` keeps its own private `name` (subject rules), and sets the ClapTrap name with the required suffix (for the tests I set ClapTrap's stored name to my name + "_clap_name" in the constructor).
- I chose the attribute sources explicitly:
  - hit points from FragTrap,
  - energy points from ScavTrap,
  - attack damage from FragTrap.
- Implemented `whoAmI()` to print the DiamondTrap name and the ClapTrap name (qualified where necessary).

Minimal outline
```cpp
// FragTrap.hpp / ScavTrap.hpp
class FragTrap : virtual public ClapTrap { /* ... */ };
class ScavTrap : virtual public ClapTrap { /* ... */ };

// DiamondTrap.hpp
class DiamondTrap : public FragTrap, public ScavTrap {
public:
    DiamondTrap(std::string name);
    void whoAmI();
private:
    std::string _name; // DiamondTrap's own name
};
```

Why this way
- Virtual inheritance solves the diamond problem cleanly and keeps constructor/destructor order predictable.
- Explicitly choosing which parent's defaults I rely on makes the class behavior deterministic for tests.
