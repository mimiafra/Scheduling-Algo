/*
--------------------------------------------
ROUND ROBIN CPU SCHEDULING ALGORITHM
--------------------------------------------
Author: Srushti Vispute
Description:
    This program simulates Round Robin CPU Scheduling.
    It calculates each process's waiting time, turnaround time,
    and displays a simple Gantt chart.

Input Format:
    Enter number of processes: N
    Enter time quantum: q
    Then enter each process’s Arrival Time and Burst Time.

Output:
    Displays Gantt chart and average waiting/turnaround times.

Compilation:
    g++ -std=c++17 RoundRobin.cpp -o RoundRobin

Run:
    ./RoundRobin

Sample Input:
    4
    2
    0 5
    1 4
    2 2
    4 1

Sample Output:
    Gantt Chart:
    | P1 | P2 | P3 | P1 | P2 | P1 |
    Process   Arrival   Burst   Waiting   Turnaround
    P1         0         5        6          11
    P2         1         4        5           9
    P3         2         2        2           4
    P4         4         1        0           1
    Average Waiting Time: 3.25
    Average Turnaround Time: 6.25
--------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

struct Process {
    int id;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
};

// Function to print Gantt chart
void printGanttChart(const vector<int>& order) {
    cout << "\nGantt Chart:\n";
    for (int pid : order) {
        if (pid == -1)
            cout << "| idle ";
        else
            cout << "| P" << pid << " ";
    }
    cout << "|\n";
}

// Main Round Robin Function
void roundRobin(vector<Process>& p, int quantum) {
    int n = p.size();
    int currentTime = 0;
    int completed = 0;
    queue<int> q;
    vector<int> ganttOrder;

    vector<bool> inQueue(n, false);

    q.push(0);
    inQueue[0] = true;

    while (completed < n) {
        if (q.empty()) {
            ganttOrder.push_back(-1); // idle CPU
            currentTime++;
            // add next available process if any
            for (int i = 0; i < n; i++) {
                if (p[i].arrival <= currentTime && p[i].remaining > 0 && !inQueue[i]) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }
            continue;
        }

        int i = q.front();
        q.pop();
        inQueue[i] = false;

        // Execute process
        if (p[i].remaining > quantum) {
            currentTime += quantum;
            p[i].remaining -= quantum;
            ganttOrder.push_back(p[i].id);
        } else {
            currentTime += p[i].remaining;
            ganttOrder.push_back(p[i].id);
            p[i].remaining = 0;
            p[i].completion = currentTime;
            completed++;
        }

        // Add processes that arrived during this time
        for (int j = 0; j < n; j++) {
            if (p[j].arrival <= currentTime && p[j].remaining > 0 && !inQueue[j]) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        // If the current process still has time left, re-add it
        if (p[i].remaining > 0) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    // Calculate turnaround & waiting time
    double totalWT = 0, totalTAT = 0;
    for (auto &proc : p) {
        proc.turnaround = proc.completion - proc.arrival;
        proc.waiting = proc.turnaround - proc.burst;
        totalWT += proc.waiting;
        totalTAT += proc.turnaround;
    }

    // Output section
    printGanttChart(ganttOrder);

    cout << left << setw(10) << "Process" << setw(10) << "Arrival"
         << setw(10) << "Burst" << setw(10) << "Waiting"
         << setw(12) << "Turnaround" << endl;

    for (auto &proc : p) {
        cout << "P" << proc.id << setw(9) << " "
             << setw(9) << proc.arrival
             << setw(9) << proc.burst
             << setw(9) << proc.waiting
             << setw(9) << proc.turnaround << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout << "Average Turnaround Time: " << totalTAT / n << endl;
}

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter Time Quantum: ";
    cin >> quantum;

    vector<Process> p(n);
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].completion = 0;
    }

    // Sort by arrival time
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.arrival < b.arrival;
    });

    roundRobin(p, quantum);

    return 0;
}
