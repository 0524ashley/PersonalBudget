# Personal Budget

## Overview

The **Personal Budget** application is designed to help users manage their personal finances by tracking their income and expenses. It provides a graphical interface for setting budgets, adding expenses, generating reports, and tracking financial progress over time. The application is developed using **Qt** and is intended to run on Linux or Windows systems.

## Features

- **Set a Budget**: Allows users to define a budget and track spending against it.
- **Add Expenses**: Users can add and categorize expenses, which are automatically reflected in the budget.
- **Expense Report**: Generate visual reports, including pie charts, to analyze expenses by category.
- **Login System**: Provides secure authentication with a simple login and registration feature (username: `admin`, password: `admin`).
- **Basic Expense Management**: Supports creating, viewing, and deleting expenses and categories.
  
## Advanced Features (Planned)

- **Database Integration**: Store user data (expenses, budgets) in a database (e.g., SQLite) for persistent storage.
- **Income Tracking**: Users can track their income alongside their expenses.
- **Recurring Expenses and Income**: Automatically add recurring transactions like rent or salary.
- **Cloud Sync**: Sync data across multiple devices using cloud storage.
- **Mobile Version**: Develop an Android/iOS version for managing budgets on the go.

## Installation

### Prerequisites

1. **Qt 5 or Qt 6**: This project uses Qt for creating the graphical interface and managing the application logic.
2. **C++ Compiler**: Make sure you have a working C++ compiler.
3. **CMake**: The project uses CMake for building the application.

### Steps

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/personal-budget.git
    cd personal-budget
    ```

2. Build the project using CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. Run the application:

    ```bash
    ./PersonalBudget
    ```

## Usage

1. **Login**: Enter `admin` as the username and `admin` as the password to log into the application.
2. **Set Budget**: Enter your total budget amount and hit "Set Budget".
3. **Add Expenses**: Add your expenses along with categories and see them reflected in the budget.
4. **Generate Report**: Click the "View Report" button to see a pie chart breakdown of your expenses by category.

## Troubleshooting

- **SQL Database Issues**: If you're facing issues with the SQL database, ensure that your system has the necessary database drivers installed. The project was developed with the intention of using SQL but wasn't fully integrated due to setup issues.
- **Missing Libraries**: If you see errors regarding missing libraries like `QtSql` or `QtCharts`, ensure that your Qt installation includes these modules.

## Contributing

Contributions are welcome! If you'd like to contribute to the project, follow these steps:

1. Fork the repository.
2. Create a new branch for your feature (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is open-source and available under the [MIT License](LICENSE).

## Acknowledgements

- **Qt**: For providing the framework to create the graphical user interface.
- **GitHub**: For version control and hosting the repository.
- **Charting Libraries**: For integrating charts to visualize expenses.

## Future Improvements

- Implement a more secure login system (e.g., password hashing, 2FA).
- Add a fully-featured reporting system with more advanced chart types.
- Enable multi-user support, allowing users to manage different budgets.

