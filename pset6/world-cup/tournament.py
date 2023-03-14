# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    argV = sys.argv[1]
    with open(argV, 'r') as file:
        reader = csv.DictReader(file)
        for team in reader:
            team["rating"] = int(team["rating"])
            teams.append(team)
              #teams.append(int(row['rating'])) ???
              #teams = reader.readlines()
    # file.close()



    # TODO: Simulate N tournaments and keep track of win counts
    counts = {}
    for i in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1


    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners

def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # for i in range(0, len(teams):
    #     winning_team = teams[]

    #you don't need to recode the logic from the simulate_round function
    #you do, however, need to do something while something is still true
    while len(teams) > 1:
    # for i in range(0, len(team_list)):
        # print(winning_team)
        teams = simulate_round(teams)
    #total_teams = len(teams)

    #remember that you are dealing with a LIST of dictionaries here
    #so you need to specify BOTH the index and key!
    return teams[0]["team"]


if __name__ == "__main__":
    main()
