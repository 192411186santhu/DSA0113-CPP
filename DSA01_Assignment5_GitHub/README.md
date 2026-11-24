# DSA01 – Assignment 5 (CO5)

**Topic:** Reliable Software with Runtime Polymorphism and Exceptions  
**Case study:** Hospital Billing and Insurance Claims

## Repository contents

- `Assignment_5_Completed.docx` – completed assignment document.
- `TaskB1_Polymorphic_Billing/` – runtime polymorphism and virtual destructor demonstration.
- `TaskB2_Exception_Handling/` – custom exceptions, catching and rethrowing.
- `TaskB3_Benchmark/` – virtual dispatch vs switch benchmark.
- `TaskB4_Extension/` – extended billing hierarchy with an emergency bill and corporate payer.
- `screenshots/` – add your genuine program-output and sanitizer screenshots here.

## Requirements

- C++ compiler supporting C++17 (for example, g++).
- Recommended compiler flags: `-std=c++17 -Wall -Wextra`.
- For the benchmark, compile with `-O2`.
- For memory-safety checks, compile with AddressSanitizer where supported.

## Compile and run

Run each command from the repository root:

```bash
g++ -std=c++17 -Wall -Wextra TaskB1_Polymorphic_Billing/main.cpp -o task_b1
./task_b1

g++ -std=c++17 -Wall -Wextra TaskB2_Exception_Handling/main.cpp -o task_b2
./task_b2

g++ -std=c++17 -O2 -Wall -Wextra TaskB3_Benchmark/main.cpp -o task_b3
./task_b3

g++ -std=c++17 -Wall -Wextra TaskB4_Extension/main.cpp -o task_b4
./task_b4
```

On Windows, run the generated `.exe` file instead of `./task_b1`, etc.

## Before submission

1. Replace the student-detail blanks in the Word document.
2. Compile and execute every program on your own computer.
3. Add genuine terminal screenshots to `screenshots/`.
4. Record your own benchmark timings in the assignment document. Timings vary by CPU, compiler and operating system; do not copy fabricated values.
5. Check that the GitHub repository name follows the course instructions, for example `DSA01-<RegisterNumber>-Assignment5`.

## Suggested GitHub upload

Create a new GitHub repository, extract this ZIP, then upload the extracted folder contents (not the ZIP itself) using **Add file → Upload files**, or use Git:

```bash
git init
git add .
git commit -m "Add DSA01 Assignment 5"
git branch -M main
git remote add origin https://github.com/<username>/<repository>.git
git push -u origin main
```

Replace `<username>` and `<repository>` with your own GitHub details.
