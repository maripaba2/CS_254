#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

void printJobSequence(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<char> sequence(maxDeadline, '\0');
    int totalProfit = 0;

    for (const auto& job : jobs) {
        for (int i = job.deadline - 1; i >= 0; i--) {
            if (sequence[i] == '\0') {
                sequence[i] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Following is the maximum profit sequence of jobs: [";
    for (int i = 0; i < maxDeadline; i++) {
        if (sequence[i] != '\0') {
            cout << sequence[i];
            if (i < maxDeadline - 1 && sequence[i + 1] != '\0')
                cout << ", ";
        }
    }
    cout << "], Total profit = " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        {'a', 4, 20},
        {'b', 1, 10},
        {'c', 1, 40},
        {'d', 1, 30}
    };

    printJobSequence(jobs);

    return 0;
}
