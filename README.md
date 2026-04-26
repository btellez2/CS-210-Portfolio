# CS 210 Portfolio

## Project: Investment Calculator

This project is an investment calculator written in C++. The program helps a user estimate how an investment can grow over time with and without additional monthly deposits. It asks the user for an initial investment amount, monthly deposit, annual interest rate, and number of years. Then it displays reports showing the year-end balance and interest earned. The problem this project solves is helping users better understand long-term savings growth and the impact of consistent monthly deposits.

## Reflection

One thing I did particularly well in this project was organizing the program into multiple files. I used a header file, an implementation file, and a main file, which made the code easier to read and manage. I also used clear output formatting so the investment reports were easier for the user to understand.

One area where I could enhance my code is input validation. In the future, I could improve the program by checking for negative numbers, invalid characters, or unrealistic values before running the calculations. This would make the program more secure and reliable because it would prevent incorrect input from causing bad results or program errors. I could also add more comments in certain sections to explain the calculation process more clearly.

The most challenging part of the project was calculating and displaying the yearly investment growth correctly. I had to make sure the interest was calculated month by month and then summarized at the end of each year. I overcame this by breaking the problem into smaller steps, testing different input values, and checking that the output matched the expected format. Resources such as zyBooks, course examples, instructor feedback, and C++ documentation are tools I can continue adding to my support network.

The skills from this project that will transfer to other projects include object-oriented programming, using classes, organizing code across multiple files, using functions, formatting output, and testing calculations. These skills are important for future programming courses and real-world software development.

I made this program maintainable, readable, and adaptable by separating the class definition from the implementation, using meaningful function names, and keeping the main file simple. This structure makes it easier to update the program later, such as adding better input validation, new reports, or different investment options.

## Files Included

- `main.cpp`
- `InvestmentCalculator.h`
- `InvestmentCalculator.cpp`
