# Priority-Based Multithreaded Task Scheduler (C++)

A lightweight thread pool implementation in C++ that executes tasks based on priority using multiple worker threads.

This project demonstrates core concurrency concepts including thread management, synchronization, and priority-based scheduling.

---

## Features

- Multithreaded task execution
- Priority-based scheduling using `std::priority_queue`
- Thread-safe shared queue using `std::mutex`
- Graceful shutdown handling
- Modern C++ (C++17)

---

## How It Works

- A fixed number of worker threads are created at initialization.
- Tasks are pushed into a shared priority queue.
- Workers continuously check the queue and execute the highest-priority task available.
- Lower priority value = higher execution priority.
- Once a worker completes a task, it fetches the next available task.


---

## Build and Run

Make sure all files are in the same directory.

Compile and Run: Mac/Linux

```bash
g++ -std=c++17 main.cpp -o scheduler -pthread
./scheduler
```
Compile and Run: Windows

```bash
g++ -std=c++17 main.cpp -o scheduler -pthread
scheduler.exe
```




