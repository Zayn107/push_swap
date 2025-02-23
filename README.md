# Push Swap

## Introduction

The **Push Swap** project is part of the 42 curriculum and challenges students to create an efficient sorting algorithm using only a limited set of stack operations. The goal is to sort a stack of integers with the fewest possible moves.

## Objectives

- Implement a sorting algorithm with **optimal performance**.
- Utilize **stack-based operations** to manipulate data.
- Manage **algorithmic complexity** for efficient sorting.
- Handle **edge cases** such as duplicate numbers and invalid input.

## Allowed Operations

- `sa` → Swap the first two elements of stack A.
- `sb` → Swap the first two elements of stack B.
- `ss` → Swap the first two elements of both stacks.
- `pa` → Push the top element from stack B to stack A.
- `pb` → Push the top element from stack A to stack B.
- `ra` → Rotate stack A upwards.
- `rb` → Rotate stack B upwards.
- `rr` → Rotate both stacks upwards.
- `rra` → Reverse rotate stack A.
- `rrb` → Reverse rotate stack B.
- `rrr` → Reverse rotate both stacks.

## Implementation Details

- The program is written in **C**.
- Uses **two stacks (A and B)** for sorting.
- Implements a combination of **sorting algorithms** (e.g., quicksort, radix sort, insertion sort) based on the number of elements.
- Handles **parsing of input arguments** and validates data.

## Compilation & Usage

### Compilation

```bash
make
```

This generates an executable called `push_swap`.

### Usage

```bash
./push_swap <list of integers>
```

#### Example:

```bash
./push_swap 4 67 3 87 23
```

The program will output a series of operations that will sort the numbers using the allowed moves.

## Evaluation Criteria

- The number of operations used to sort the stack.
- Efficiency in handling different stack sizes.
- Proper memory management and error handling.

## Possible Enhancements

- Implement a **visualizer** to track sorting progress.
- Optimize sorting for **large inputs**.
- Improve **algorithm selection** based on input size.

## Resources

- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

## Author

This project was completed as part of the **42 School** curriculum.

---

### Disclaimer

This project is for educational purposes only and follows the **42 project guidelines**.
