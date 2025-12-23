# 🍝 Philo

This project introduces us to the concept of **multithreading**. We will see what a **mutex** is and how to avoid **data races**.
The project asks us to simulate the [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem).

---

## 🧩 Problem description

We have a `n` number of philosophers sitting around a round table.  
Each philosopher alternates between **thinking**, **eating**, and **sleeping**.

To eat, a philosopher needs **two forks**:
- one fork on their left
- one fork on their right

There are as many forks as philosophers, meaning forks are **shared resources**.

The challenge is to coordinate the philosophers so that:
- No philosopher **dies of starvation**
- No **data race** occurs
- No **deadlock** happens
- The simulation follows strict timing rules

---

## 🧠 Rules of the simulation

- Each philosopher is represented by a **thread**
- Each fork is protected by a **mutex**
- A philosopher must lock both forks before eating
- After eating, the philosopher releases the forks
- A philosopher dies if they do not eat within `time_to_die`
- When a philosopher dies, the simulation stops immediately

All actions must be printed following this format:

[timestamp] [philosopher_id] is eating
[timestamp] [philosopher_id] is sleeping
[timestamp] [philosopher_id] is thinking
[timestamp] [philosopher_id] died

---

## ⏱️ Program arguments

./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]

### Arguments

- **number_of_philosophers**  
  Number of philosophers and forks

- **time_to_die** (ms)  
  Time a philosopher can survive without eating

- **time_to_eat** (ms)  
  Time a philosopher spends eating

- **time_to_sleep** (ms)  
  Time a philosopher spends sleeping

- **number_of_times_each_philosopher_must_eat** (optional)  
  If provided, the simulation stops once all philosophers have eaten this many times

---

## 🔐 Concepts covered

This project introduces several important low-level concepts:

- Multithreading with `pthread`
- Mutexes (`pthread_mutex_t`)
- Critical sections
- Data races
- Deadlocks
- Precise time management

Proper synchronization is mandatory to avoid undefined behavior.

---

## 🧵 What is a thread?

A **thread** is a unit of execution inside a program.

### In simple terms
Think of a thread as a **worker**:
- One program can have **multiple workers**
- All workers run **at the same time**
- They share the same memory

### In this project
- **Each philosopher is a thread**
- All philosophers run simultaneously
- Each one decides when to think, eat, or sleep

Without threads, philosophers would act **one after another**, which would not
represent a real concurrency problem.

---

## 🔐 What is a mutex?

A **mutex** (short for *mutual exclusion*) is a **lock**.

### In simple terms
Imagine a **single key for a room**:
- Only one person can be inside the room at a time
- To enter, you must take the key
- When you leave, you give the key back

If someone already has the key, others must **wait**.

### In this project
- **Each fork is protected by a mutex**
- When a philosopher wants to eat:
  1. They lock the left fork (mutex)
  2. They lock the right fork (mutex)
  3. They eat
  4. They unlock both forks

This prevents **two philosophers from using the same fork at the same time**.

---

## ⚠️ Why do we need mutexes?

Without mutexes, two threads could:
- Access the same data at the same time
- Modify shared values incorrectly
- Cause **data races**
- Produce undefined behavior

Mutexes ensure:
- Only one thread accesses a resource at a time
- Shared data stays consistent
- The program behaves predictably

---

## 💥 What is a data race?

A **data race** happens when:
- Two or more threads access the same data
- At least one of them writes to it
- There is no protection (mutex)

In the philosophers project, data races can occur on:
- Forks
- Time of last meal
- Death status
- Print output

Mutexes are used to **protect these critical sections**.

---

## 🕰️ How the simulation works

1. The program starts all philosopher threads
2. Each philosopher loops:
   - Thinks
   - Takes forks (mutex lock)
   - Eats
   - Releases forks (mutex unlock)
   - Sleeps
3. A monitoring system checks if a philosopher dies
4. If a philosopher dies, the simulation stops

---
