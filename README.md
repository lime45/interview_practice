# Job description:
## Detailed Scope of Work:
* Senior Embedded Developers with 7–10 years of C-language coding experience on Embedded Systems.
* Unit testing of Embedded C functions, along with strong C-Coding Embedded Developer experience. 
* Code Review of embedded C and C++ source code.
* The ability to effectively Unit Test SW functions written in the C programming language
* Intermediate (or advanced) knowledge of C.
* The ability to set up and use development boards, debuggers, and other hardware.
* Other duties as needed and as skills allow.
## Additional Desired Characteristics:
* Extensive experience with the C programming language.
* Experience with detailed Code Review activities.
* Experience with the application of Coding Rules and Guidelines to code under review.
* Experience with achieving complete code coverage.

=============================================================================

# Here are targeted interview tips for this Senior Embedded C Developer role:

## 1. Technical Areas to Review
* C language deep-dive: pointers, memory management, volatile, const correctness, bit manipulation, structures/unions, preprocessor directives
* Embedded specifics: ISRs, RTOS concepts, memory-mapped I/O, low-power design, bootloaders, linker scripts
* Unit testing frameworks: Ceedling, Unity, CMock, Google Test for C++; demonstrate test-first mindset
* Code coverage: line, branch, MC/DC; tools like gcov, lcov, Bullseye, VectorCAST
* Coding standards: MISRA C, CERT C, JSF++, or other automotive/aerospace guidelines
* Debugging: JTAG/SWD, logic analyzers, oscilloscopes, printf debugging, GDB mastery
## 2. Prepare Concrete Examples (STAR Method)
For each requirement, have 2–3 stories ready:

* Code review: How you improved code quality, caught bugs, enforced standards
    Talk about a watchdog timer and subtract vs add make inside code coverage
* Unit testing: A project where you achieved high coverage; challenges with hardware dependencies
    
* Hardware setup: Debugging a elusive board issue, bringing up new silicon, integrating peripherals
    I2C issue with 
* Mentorship: Guiding junior engineers on C best practices

## 3. Sample Interview Questions
1. Technical:

Explain the difference between volatile and const.
How do you handle reentrancy in ISRs?
   Don't allow it! or use critical sections to protect data or disable interrupts
   if there are higher level interrupts that could interrupt
What’s the purpose of the static keyword in C?
   static makes a variable persistent in a file OR
   static functions are "private" to a file, can more easily be optimized by compiler
Describe a time you optimized for memory or speed.

How would you unit test a function that directly manipulates hardware registers?
   I would create mock functions to simulate HAL functions
2. Code Review Scenario:
“Here’s a snippet with potential bugs. Find them and suggest fixes.”
Be ready to discuss trade-offs in coding guidelines (e.g., MISRA rule violations vs. readability)
Behavioral:

“Tell me about a difficult code review you conducted.”
“How do you ensure complete code coverage in a legacy codebase?”
“Describe a time you had to debug a problem that only appeared in production.”
Tellabs, health report, only occurred on a system free of errors

## 4. Questions to Ask Them
1. What coding standards do you enforce, and how are deviations handled?
2. What’s your typical toolchain (compiler, debugger, test framework)?
3. How do you measure and track code coverage? Is 100% branch coverage required?
4. What’s the balance between new development and maintenance?
5. What’s the biggest embedded challenge the team is facing right now?

## 5. Practical Prep
1. Bring a notepad to sketch diagrams (memory maps, timing, state machines)
2. Ask if you can use a whiteboard or paper during technical questions
3. If doing a live coding exercise, talk through your thought process; it’s as important as the solution
4. Be honest about gaps—senior roles value knowing when to ask for help
## 6. Mindset
1. They’re looking for quality-first, disciplined C developers who can elevate a team
2. Emphasize collaboration: code review is a team activity, not a critique
3. Highlight experience with safety-critical or regulated industries if applicable


# General notes
## SPI bus
### comm lines
* MOSI (master out slave in)
* MISO (master in slave out)
* CS (chip select)
* SCLK (SPI Clock)

## I2C bus
### comm lines
* SDA - serial data
* SCL - serial clock
clock stretching - the slave holds the clock line low to indicate that it is processing data and isn't ready for new data

## UART
### comm lines
* receive
* transmit
* power
* ground

common bauds, 115200, 9600
FTDI FT232R/FT232RL is most common chip for USB to UART conversion

## cyclic dependency graph
### commonly use 'graphviz'
