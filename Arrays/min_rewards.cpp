/*
    Imagine that you're a teacher who's just graded the final exam in a class. You
    have a list of student scores on the final exam in a particular order (not
    necessarily sorted), and you want to reward your students. You decide to do so
    fairly by giving them arbitrary rewards following two rules:
    -All students must receive at least one reward.
    -Any given student must receive strictly more rewards than an adjacent
    student (a student immediately to the left or to the right) with a lower
    score and must receive strictly fewer rewards than an adjacent student with
    a higher score.
    Write a function that takes in a list of scores and returns the minimum number
    of rewards that you must give out to students to satisfy the two rules.
    You can assume that all students have different scores; in other words, the
    scores are all unique.
    Ex : a = [8, 4, 2, 1, 3, 6, 7, 9, 5]
    output : 25 // you would give out the following rewards: [4, 3, 2, 1, 2, 3, 4, 5, 1]

*/

// My approach

#include <vector>
using namespace std;

int minRewards(vector<int> scores)
{
    int i = 1;
    unordered_map<int, int> rewards;
    for (int i = 0; i < scores.size(); i++)
    {
        rewards[i] = 1;
    }
    while (i < scores.size() - 1)
    {
        bool bottom = scores[i] < scores[i + 1] && scores[i] < scores[i - 1];
        if (!bottom)
        {
            i++;
            continue;
        }
        int left = i - 1;
        while (scores[left] > scores[left + 1] && left >= 0)
        {
            rewards[left] = max(rewards[left], i - left + 1);
            left--;
        }
        int right = i + 1;
        while (scores[right] > scores[right - 1] && right < scores.size())
        {
            rewards[right] = max(rewards[right], right - i + 1);
            right++;
        }
        i = right;
    }
    int result = 0;
    for (int i = 0; i < scores.size(); i++)
    {
        result += rewards[i];
        cout << rewards[i] << "\n";
    }
    if (result == scores.size())
        return result * (result + 1) / 2;

    return result;
}
