# CPP 01

Memory allocation, pointers to members, references and switch statements.

## 🧠 | ex 00

The goal of this exercice is to create a very simple Zombie class, with a private string and two functions: 
```cpp
Zombie* newZombie(std::string name)
void randomChump(std::string name)
```
 
Here you need to need to determine in wich case you need to allocate a Zombie on the stack or on the heap. We can see that the first function return a pointer, we can understand that this function 
will allocate a new zombie on the stack.

## 🧟 | ex 01

Here we need to create a hord of zombies. For that we juste init an array of type `Zombie` and allocate `N` size. We can do that like that:

```cpp
Zombie*	zombieHord(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie*	new_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		new_horde[i].update_name(name);
	return (new_horde);
}
```

Don't forget to delete them with 
```cpp 
delete	[]horde;
```

## 👉 | ex 02

This exercice is juste a ToDo list tat you need to follow.

## 👊 | ex 03

In this exercice you need to create twoo classes, `HumanA` and `HumanB`. You also need to create a `Weapon` class. Every `Human` classes have a `Weapon` class as a private attribute. Here an example:

```cpp
class HumanB
{
	private:
		
		std::string	name;
		Weapon	*weapon;

	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};
```

## 🔄 | ex 04

This exercice ask us to create a program that takes three parameters: `filename` `string_to_replace` and `replacement_string`. 
Then you need to read the file and replace every occurence of `string_to_replace` and replace it by `replacement_string`. To do so, you can use the `get_line` function that work like out *gnl* function.
After reading the line you need to search for the string and then output the result in the .output file. The main loop can look like this:

```cpp
while (std::getline(MyReadFile, Buffer))
	{
		for (int i = 0; i < (int)Buffer.length(); i++)
		{
			if (Buffer[i] == s1[0] && is_s2(Buffer, i, s1))
			{
				i += s1.length() - 1;
				MyFile << s2;
			}
			else
				MyFile << Buffer[i];
		};
	}
```

Other usefull function for this exercice are `ofstream` and `ifstream` to read and and write in a file.

## 🤓 | ex 05

Do you know Harl ? We all do, don't we ? Here you need to create a `Harl` class that have 4 private member function:

```cpp
void debug( void );
void info( void );
void warning( void );
void error( void );
```

Harl also has a public member function that calls the four member functions above depending on the level passed as a parameter:

```cpp
void complain( std::string level );
```

The goal of this exercise is to use pointers to member functions. This is not a
suggestion.

Here is an exemple of pointer to member functions:

```cpp
void (Harl::*funcsptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
```

You will loop in this array in order to call the right function.

## ☝️🤓 | ex 06

This exercice is the same, but you will take an input to know what Harl will say. It will display all messages from this level and above.
The subject give you a hint to use `switch` statement (personally I didn't).
