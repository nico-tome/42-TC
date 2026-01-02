# CPP 00

Namespaces, basic classes, I/O, static members, and simple resource management.

---

## 📣 ex00 — megaphone
What I did
- Implemented a small program that prints input arguments in uppercase or a default message when no args are given.
- Used C-style helpers (`cstring`) for string length and `toupper` to convert each character.

Key idea I followed
- Keep main tiny and explicit: handle the "no args" case first, otherwise loop arguments and characters and print toupper(c).

Minimal main skeleton I used
```cpp
int main(int ac, char **av) {
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else {
        for (int i = 1; i < ac; ++i)
            for (size_t j = 0; j < std::strlen(av[i]); ++j)
                std::cout << (char)std::toupper(av[i][j]);
        std::cout << '\n';
    }
    return 0;
}
```

Why this way
- No complex parsing required, just deterministic character transformation — easiest to test and match the subject.

---

## 📱 ex01 — PhoneBook
What I did
- Implemented `Contact` and `Phonebook` classes.
- Phonebook stores up to 8 contacts in a fixed array, overwriting the oldest contact when full.
- Implemented user loop (ADD / SEARCH / EXIT) and pretty table display with truncation for columns.

Key design choices
- Store contacts in a fixed-size `Contact contacts[8]` for simplicity (subject requirement).
- Provide getters that return truncated strings (with a trailing '.') for table display.
- Centralize input handling in Phonebook methods so `main` stays clean.

Important skeletons (structure only)
```cpp
// Contact.hpp
class Contact {
public:
    Contact();
    ~Contact();
    void set_new(std::string first, std::string last, std::string nick,
                 std::string phone, std::string secret);
    std::string get_first_name(int max_size);
    // ... other getters
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;
};
```

```cpp
// PhoneBook.hpp
class Phonebook {
public:
    Phonebook();
    ~Phonebook();
    void add_contact();
    void search_contact();
    void show_contact(int idx);
private:
    int size; // number of added contacts (wraps with % 8)
    Contact contacts[8];
};
```

Minimal main loop I used
```cpp
int main() {
    Phonebook phonebook;
    std::string cmd;
    while (std::getline(std::cin, cmd)) {
        if (cmd == "ADD") phonebook.add_contact();
        else if (cmd == "SEARCH") phonebook.search_contact();
        else if (cmd == "EXIT") break;
        else std::cout << "Command not valid\n";
    }
}
```

Why this way
- Clear separation: Phonebook manages I/O details and Contact stores simple data. Table formatting done with iomanip for deterministic output.

---

## 🏦 ex02 — Account
What I did
- Implemented an `Account` class that tracks:
  - per-account amount, deposits, withdrawals,
  - global static counters: number of accounts, total amount, total deposits/withdrawals.
- Implemented `_displayTimestamp()` helper for the required log format.
- Wrote `makeDeposit`, `makeWithdrawal`, `displayStatus`, and static `displayAccountsInfos` used by the provided tests.

Key design choices
- Static members hold global state; instance members hold per-account state.
- Timestamp formatting via `std::strftime` so output matches tests.
- Tests are driven by the provided `tests.cpp` (I ran it to validate formatting and counters).

Class skeleton I used
```cpp
class Account {
public:
    Account(int initial_deposit);
    ~Account();
    void makeDeposit(int deposit);
    bool makeWithdrawal(int withdrawal);
    int checkAmount(void) const;
    void displayStatus(void) const;

    static void displayAccountsInfos(void);
    static int getNbAccounts(void);
    // ... other static getters

private:
    static void _displayTimestamp(void);
    static int _nbAccounts;
    static int _totalAmount;
    static int _totalNbDeposits;
    static int _totalNbWithdrawals;

    int _accountIndex;
    int _amount;
    int _nbDeposits;
    int _nbWithdrawals;
};
```
