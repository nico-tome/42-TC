# CPP 02

Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form.

## 🏛️ | ex 00

This exercice ask you to create a class in **Orthodox Canonical Form**, that mean:

- A default constructor that initializes the fixed-point number value to 0.
- A copy constructor.
- A copy assignment operator overload.
- A destructor.

You simply need to follow the instruction.

## 🔢 | ex 01

Here again you only need to follow the instruction by adding two constructors and two functions. You need to pay attention to where you add theme (*private* or *public*).

## ✖️ | ex 02

Here we learn **operator overload**. We do that by declarating a function like that:

```cpp
bool	operator>(const Fixed &other) const;
bool	operator<(const Fixed &other) const;
bool	operator>=(const Fixed &other) const;
bool	operator<=(const Fixed &other) const;
bool	operator==(const Fixed &other) const;
bool	operator!=(const Fixed &other) const;

float	operator+(const Fixed &other) const;
float	operator-(const Fixed &other) const;
float	operator*(const Fixed &other) const;
float	operator/(const Fixed &other) const;

Fixed	operator++(void);
Fixed	operator--(void);
Fixed	operator++(int);
Fixed	operator--(int);
```

## 🔺 | ex 03

Now we will use the *FixedPoint* class to implement a BSP (binary space partition) function. We need to check if a point is in a triangle or not.
To do that you have something like this:

```cpp
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	c1 = point.cross(a, b);
	float	c2 = point.cross(b, c);
	float	c3 = point.cross(c, a);

	bool	pos = (c1 < 0.f) || (c2 < 0.f) || (c3 < 0.f);
	bool	neg = (c1 > 0.f) || (c2 > 0.f) || (c3 > 0.f);

	return !(neg && pos);
}
```

Where cross return a floating number, positiv if the point is at the left of a segment and negative if the point is at the right of the segment.
