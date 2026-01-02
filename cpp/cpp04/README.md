# CPP 04

Polymorphism, virtual functions and deep copies.

---

## 🐾 ex00 — Polymorphism (Animal / WrongAnimal)
What I did
- Implemented `Animal` with a virtual `makeSound()` and virtual destructor so derived classes behave correctly through base pointers.
- Implemented `Dog` and `Cat` overriding `makeSound()`.
- Implemented `WrongAnimal` / `WrongCat` without virtual functions to demonstrate the difference.

Key skeleton I used
```cpp
// Animal.hpp
class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal&);
    virtual ~Animal();           // important: virtual
    Animal& operator=(const Animal&);
    virtual void makeSound() const;
    std::string getType() const;
};
```

```cpp
// WrongAnimal.hpp
class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal&);
    ~WrongAnimal();              // not virtual on purpose
    WrongAnimal& operator=(const WrongAnimal&);
    void makeSound() const;     // not virtual -> shows wrong behaviour
    std::string getType() const;
};
```

Why this way
- I kept the base interface minimal and used `virtual` only where polymorphism is intended. The Wrong* pair shows the effect of missing virtual dispatch.

---

## 🧠 ex02 — Deep copy with Brain (Cat/Dog with Brain)
What I did
- Added a `Brain` class that holds an array of ideas (C-style fixed array).
- `Dog` and `Cat` contain a `Brain*` and implement deep copy in copy ctor + assignment (new/delete).
- Ensured no shallow copies: copying an animal duplicates brain contents, not the pointer.

Key skeletons I used
```cpp
// Brain.hpp
class Brain {
public:
    Brain();
    Brain(const Brain&);
    Brain& operator=(const Brain&);
    ~Brain();
    std::string ideas[100];
};
```

```cpp
// Dog.hpp (similar for Cat)
class Dog : public Animal {
public:
    Dog();
    Dog(const Dog&);
    Dog& operator=(const Dog&);
    ~Dog();
    void makeSound() const;
private:
    Brain* _brain; // allocate in ctor, deep-copy in copy ctor/oper=
};
```

Why this way
- Manual resource management with clear ownership: each Animal owns its Brain. Copying allocates a fresh Brain and copies content.

---

## 🔬 ex01 / ex03 — notes
What I did
- ex01 / ex03 follow the same pattern: implement classes according to the subject, keep canonical form, and write small mains that validate polymorphism, object lifetime and copies.
- Where required I used `virtual` and abstract patterns (pure virtual) to force derived implementation.

Minimal test I used for sanity checks
```cpp
int main() {
    const Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; ++i) {
        std::cout << animals[i]->getType() << " => ";
        animals[i]->makeSound();
    }

    // deep copy test
    Dog d1;
    d1.getBrain()->ideas[0] = "eat";
    Dog d2 = d1; // copy ctor
    d2.getBrain()->ideas[0] = "sleep";
    // verify d1 brain not changed

    for (int i = 0; i < 4; ++i)
        delete animals[i];
}
```
