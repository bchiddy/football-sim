# Premier League Simulator

This command line program written in C++ allows you to run a Monte Carlo simulation a Premier League season and display the resulting league table. It provides a fun and interactive way to predict the outcomes of matches and see how your favorite teams perform over the course of a season.

## Features

- **Season Simulation:** The program simulates an entire Premier League season, generating random match outcomes based on predefined team strengths.
- **Realistic Results:** The simulated match outcomes take into account the relative strengths of the competing teams, ensuring that the results reflect the probabilities seen in real season.
- **League Table:** After the simulation is complete, the program calculates and displays the final league table, showing the rankings of all teams based on their performance throughout the season.
- **Team Statistics:** In addition to the league table, the program provides individual team statistics such as total wins, losses, draws, goals scored, and goals conceded.
- **Customization:** You can customize the program to add or remove teams, adjust team strengths, or modify any other aspect of the simulation to suit your preferences.

## Getting Started

To use the Premier League Simulator, follow these steps:

1. **Clone the Repository:** Start by cloning this repository to your local machine.

```git clone https://github.com/bchiddy/football-sim```

2. **Compile the Program:** Compile the C++ source code using your preferred compiler. For example, using `g++`:

```g++ -o simulator main.cpp```

3. **Run the Program:** Execute the compiled binary to start the Premier League simulation.

4. **View the Results:** Once the simulation is complete, the program will display the final league table along with team statistics.

## Customization

To customize the Premier League Simulator according to your preferences, you can modify various aspects of the program:

- **Team List:** Edit the `teams.txt` file to add or remove teams from the simulation. Each line represents a team, and you can include as many teams as you like.

- **Team Strengths:** Adjust the relative strengths of the teams by modifying the `teamStrengths` array in the `main.cpp` file. The values represent the probabilities of a team winning, losing, or drawing a match.

- **Simulation Parameters:** You can modify other simulation parameters such as the number of matches played, the points awarded for a win or a draw, or any other relevant factors in the `main.cpp` file.

## Contributions

Contributions to the Premier League Simulator project are welcome! If you have any suggestions, bug reports, or feature requests, please feel free to submit them by opening an issue on the project's GitHub repository.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
