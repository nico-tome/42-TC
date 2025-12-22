# 📃 Get Next Line

The goal of this project is to create a very usefull function that read line by line a file, or the standar input.
With this project we learn static variable, wich is a variable that keep her state beetween function's calls and `fd` wich mean *File Descriptor* and is used for interacting with files.

For exemple:

```c
void  foo(void)
{
  static int  x;

  if (!x)
    x = 0;
  else
    x++;
  printf("%d\n", x);
}

int  main(void)
{
  for (int i = 0; i < 10; i++)
    foo();
}
```

The output will be:
```bash
> 0
> 1
> 2
> 3
> 4
> 5
> 6
> 7
> 8
> 9
```

So after understanding that we can think our function like that:

1) Read an ammount of byte in the file and store it in a read_buffer.
2) After that we will join ou buffer with the new read bytes and our static buffer.
3) We check if in our read bytes we have a new line (with the '\n' char) or the end of the file (with the value return by the `read` function that should be equal to the `read_buffer` size, if not we reach the end of the file). If we found one of the two cases we truncate the buffer to the next line char and store that in a value to return later. After that we clean the static `buffer` by keeping only chars after what we returned. The we return the string to return.

For exemple in the file:
```
Hello!
World
```
With a `read_buffer` size of 2 the varaibles states should look like this:
```
read_buffer: "He" | buffer: "He"
read_buffer: "ll" | buffer: "Hell"
read_buffer: "o!" | buffer: "Hello!"
read_buffer: "\nW" | buffer: "Hello!\nW" -> we will return "Hello!\n" and clean buffer to make it look like "W"
read_buffer: "or" | buffer: "Wor"
read_buffer: "ld" | buffer: "World"
read_buffer: '' (we reach the end) | buffer "World" -> we will return "World" and clean buffer to make it empty
```

My advice to complete this project is to create the function `get_next_line`, wich will call a function `read` that will read `n` bytes from the file until the end or read the `\n` character and return the static `buffer` + the bytes readed. Then call a `get_line` function that will return the line to return into a variable that will be return by the `get_next_line` function. And lastely call a `clean_buffer` function that will remove the returned line and keep the extra characters.

For me the hardest part of this project was to keep my function leak free and norm it. So good luck !
