#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9


// preferences[i][j] is jth preference for voter i
// remember: this is one of your matrixes/tables
int preferences[MAX_VOTERS][MAX_CANDIDATES];


// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;


// Array of candidates
candidate candidates[MAX_CANDIDATES];


// Numbers of voters and candidates
int voter_count;
int candidate_count;


// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }



    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
// below we are shifting away from ./runoff to start
// at Alice's position count
// this also creates a table!
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
// + 1 is meant to move the candidate into a workable index

            string name = get_string("Rank %i: ", j + 1); //
            // Comparable: https://www.studytonight.com/c/array-in-function-in-c.php

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }



    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie) // ------------------------------>> be good to unpack this line for yourself
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}





// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
// you already know what's being checked in these 2 lines ...
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
// don't let this 'i' below freak you out
// 'i' has two dimensions wrt the candidate_count
// the dimensions are stored in 'name' from earlier
// remember: we used 2 for loops to query for votes/rank (2D!)
// so a vote name consists of an [i-voter] & [j-rank]
            preferences[voter][rank] = i;
// you could think of the above line as: int ageArray[] = {2, 8, 4, 12};
            return true;
        }
    }
    return false;
}


// Tabulate votes for non-eliminated candidates

// The function should update the number of votes each candidate has at this stage in the runoff.
// Recall that at each stage in the runoff, every voter effectively votes for their top-preferred candidate who has not already been eliminated.
// you don't need to code the stage. A stage begins after elimination, resetting votes and tabulation.

// Hints

// Recall that voter_count stores the number of voters in the election and that, for each voter in our election, we want to count one ballot.
// Recall that for a voter i, their top choice candidate is represented by preferences[i][0], their second choice candidate by preferences[i][1], etc.
// Recall that the candidate struct has a field called eliminated, which will be true if the candidate has been eliminated from the election.
// Recall that the candidate struct has a field called votes, which you’ll likely want to update for each voter’s preferred candidate.
// Once you’ve cast a vote for a voter’s first non-eliminated candidate, you’ll want to stop there, not continue down their ballot! Recall that you can break out of a loop early using break inside of a conditional.

void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // you need to check the voter's top preference and update the candidate's vote total
            // battling with 2 things: 1) should I update preferences and 2) should program skip
            // a candidate that has been labelled elimiated?
            if (candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}



// -------------------------------------------------------------------
// Print the winner of the election, if there is one

// If any candidate has more than half of the vote, their name should be printed and the function should return true.
// If nobody has won the election yet, the function should return false.

// Hints

// Recall that voter_count stores the number of voters in the election.
// Given that, how would you express the number of votes needed to win the election?

bool print_winner(void)
{
    int target = voter_count / 2;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > target)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// -------------------------------------------------------------------

// Return the minimum number of votes any remaining candidate has

// The function should return the minimum vote total for any candidate who is still in the election.

// Hints

// You’ll likely want to loop through the candidates to find the one who is both still in the election and has the fewest number of votes.
// What information should you keep track of as you loop through the candidates?

int find_min(void)
{
    int minimum = INT_MAX;

    for (int i = 0; candidate_count < i; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < minimum)
        {
            minimum = candidates[i].votes;
        }
    }
    return minimum;
}




//-----------------------------------------------------------------


// Return true if the election is tied between all candidates, false otherwise


// The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
// The function should return true if every candidate remaining in the election has the same number of votes, and should return false otherwise.

// Hints

// Recall that a tie happens if every candidate still in the election has the same number of votes.
// Note, too, that the is_tie function takes an argument min, which is the smallest number of votes any candidate currently has.
// How might you use that information to determine if the election is a tie (or, conversely, not a tie)?

bool is_tie(int min)
{
    int eliminate = 0;
    int counter = 0;
    for (int i = 0; candidate_count < i; i++)
    {
        if (!candidates[i].eliminated)
        {
            eliminate++;
            if (candidates[i].votes == min)
            {
                counter++;
            }
         }
    }
    if (counter == eliminate)
    {
        return true;
    }
    return false;
}



// Complete the eliminate function.

// The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
// The function should eliminate the candidate (or candidates) who have min number of votes.


// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; candidate_count < i; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
            // candidates[i].votes = 0; ?? no...
        }
    }
    return;
}

