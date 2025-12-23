# 🔄 push_swap

The **push_swap** project is a sorting algorithm challenge from the 42 curriculum.
The goal is simple in theory: sort a list of integers using **two stacks** and a
very limited set of operations. i personally used the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

---

## 🧩 Project description

The program receives a list of integers as arguments and must sort them in
ascending order using two stacks:

- **Stack A**: contains the numbers to sort
- **Stack B**: starts empty and is used as a helper

Only a limited set of operations is allowed:
- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

The challenge is not only to sort the numbers, but to do it using **as few
operations as possible**.

---

## 🧠 My approach

Before coding anything, I understood that **brute force is not an option**.
The number of operations must stay low, especially for large inputs (100 or 500
numbers).

I split the project into **clear steps**:
1. Input parsing and error handling
2. Special cases (small stacks)
3. Efficient sorting for large stacks
4. Cost optimization

For large stacks, I chose to implement the **Turkish algorithm**.

---

## 🧮 Small stack optimization

For small inputs, I handled them separately:

- **2 numbers** → simple swap if needed
- **3 numbers** → hardcoded logic (minimal moves)
- **5 numbers** → push smallest values to stack B, sort stack A, then push back

This guarantees optimal or near-optimal results for small cases.

---

## 🇹🇷 The Turkish algorithm (explained simply)

The Turkish algorithm is based on the idea of **pushing numbers to stack B in an
optimized order**, then reinserting them correctly into stack A.

### Step 1️⃣ Push everything except a base

I start by pushing 2 numbers from **stack A to stack B**. This will give me a start to work with.

---

### Step 2️⃣ Calculate the cost of each move

For each number in stack A, I calculate:
- The number of rotations needed in stack A to bring it to the top
- The number of rotations needed in stack B to place it correctly

Each element has a **total cost** (number of operations needed to move it).

---

### Step 3️⃣ Choose the cheapest move

Among all elements in stack A, I always choose the one with the **lowest cost**.

This is the key idea of the algorithm:
> Always perform the most efficient move available.

This greedy approach keeps the total number of operations low.

---

### Step 4️⃣ Optimize rotations

When possible, I use **combined rotations**:
- `rr` instead of `ra` + `rb`
- `rrr` instead of `rra` + `rrb`

This significantly reduces the number of operations.

I will do those stpes until 3 elements remain in stack A.
---

### Step 5️⃣ Push back to stack A

Once rotations are done:
- I push the selected element from stack B to stack A
- The element is placed directly in the correct position

This process is repeated until stack B is empty.

---

## 🔁 Final rotation

At the end, stack A is sorted but may not start with the smallest number.
I rotate stack A until the smallest value is on top.

The result is a fully sorted stack using an optimized number of operations.

---

Again, here the article I used for this project: [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
