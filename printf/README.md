# 🖨️ ft_printf

The **ft_printf** project is one of the first big C projects in the 42 curriculum.
Its goal is to recreate a simplified version of the standard C function
`printf`.

Through this project, we learn how to:
- Parse a string
- Handle **variable arguments**
- Manage formatted output
- Write clean and modular C code

---

## 🧩 Project description

`printf` is a function that prints formatted text to the standard output.

Example from the standard library:
``` c
printf("Hello %s, you are %d years old\n", name, age);
```

In this project, we must implement our own version called **`ft_printf`**,
without using the real `printf`.

### Required behavior

* Handle different **format specifiers**
* Print characters, strings, numbers, pointers, etc.
* Return the **number of characters printed**
* Follow the same logic as the real `printf` (within the project limits)

---

## 📌 Supported conversions (mandatory part)

Usually, `ft_printf` must handle:

* `%c` → character
* `%s` → string
* `%p` → pointer
* `%d` / `%i` → signed integer
* `%u` → unsigned integer
* `%x` / `%X` → hexadecimal
* `%%` → percent sign

---

## 🔍 Example usage

``` c
#include "ft_printf.h"

int main(void)
{
    int age = 18;

    ft_printf("Hello %s!\n", "Nicolas");
    ft_printf("You are %d years old.\n", age);
    ft_printf("Hex value: %x\n", age);
    ft_printf("Percent sign: %%\n");

    return (0);
}
```

Output:

```
Hello Nicolas!
You are 18 years old.
Hex value: 12
Percent sign: %
```

---

## 🛠️ How does `ft_printf` work? (simple explanation)

At its core, `ft_printf` does **three main things**:

### 1️⃣ Read the format string

`ft_printf` reads the string **character by character**.

* If the character is **not** `%` → print it directly
* If the character **is** `%` → special behavior starts

---

### 2️⃣ Detect a format specifier

When `%` is found:

* Look at the **next character**
* Decide what type of data must be printed (`c`, `s`, `d`, etc.)

Example:

``` c
"%d" → print an integer
"%s" → print a string
```

---

### 3️⃣ Print the correct value

Depending on the specifier:

* Call the correct function
* Convert the value if needed (number → string, base 10 → base 16, etc.)
* Print it
* Count printed characters

This is why the project is often split into small functions:

* `print_char`
* `print_string`
* `print_number`
* `print_hex`
* etc.

---

## 🧠 How do we get the arguments? (`va_arg`)

This project introduces **variadic functions**.

### What is a variadic function?

A variadic function is a function that can take a **variable number of arguments**.

Example:

```c
ft_printf("Age: %d, Name: %s\n", 18, "Nicolas");
```

Here, the number and types of arguments depend on the format string.

---

## 🔐 The `va_list` system

C provides tools to handle variable arguments via `<stdarg.h>`:

* `va_list` → stores arguments
* `va_start` → initializes access to arguments
* `va_arg` → retrieves the next argument
* `va_end` → cleans up

### Example

```c
#include <stdarg.h>

void example(int count, ...)
{
    va_list args;
    int i;

    va_start(args, count);
    i = va_arg(args, int); // get next argument as int
    va_end(args);
}
```

---

## 🔄 How `va_arg` is used in ft_printf

In `ft_printf`:

1. Initialize `va_list`
2. When a `%` is found:

   * Use `va_arg` with the correct type
3. Print the value
4. Continue parsing the format string

Example:

```c
if (format[i] == 'd')
    print_int(va_arg(args, int));
else if (format[i] == 's')
    print_string(va_arg(args, char *));
```

The **order of `va_arg` calls must exactly match the format string**.

---
