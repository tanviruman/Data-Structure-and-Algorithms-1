Y//ou are given a list of tasks, where each task is represented as (StartTime, FinishTime). 
//The goal is to sort the tasks based on their durations (calculated as FinishTime- StartTime) in ascending order.

#include <iostream> 
// Includes the standard input-output stream library to allow use of cin, cout, etc.

using namespace std; 
// Allows the use of standard library names (e.g., cout, cin) without the "std::" prefix.

int Duration(int start, int end) 
{
    return end - start; 
    // Function to calculate and return the duration of a task given its start and end times.
}

void Sort(int tasks[][2], int n) 
{
    // Function to sort tasks based on their duration using an insertion sort algorithm.
    for (int i = 1; i < n; i++) 
    {
        int keyStart = tasks[i][0]; 
        // Stores the start time of the current task.

        int keyEnd = tasks[i][1]; 
        // Stores the end time of the current task.

        int keyDuration = Duration(keyStart, keyEnd); 
        // Calculates the duration of the current task using the Duration function.

        int j = i - 1; 
        // Index variable to iterate backward through the sorted portion of the array.

        while (j >= 0 && Duration(tasks[j][0], tasks[j][1]) > keyDuration) 
        {
            // While there are elements in the sorted portion with a greater duration than the current task:
            tasks[j + 1][0] = tasks[j][0]; 
            // Shift the start time of the task to the next position.

            tasks[j + 1][1] = tasks[j][1]; 
            // Shift the end time of the task to the next position.

            j--; 
            // Move to the previous task in the sorted portion.
        }

        tasks[j + 1][0] = keyStart; 
        // Insert the start time of the current task in the correct position.

        tasks[j + 1][1] = keyEnd; 
        // Insert the end time of the current task in the correct position.
    }
}

int main() 
{
    int tasks[3][2] = {{2, 5}, {1, 3}, {4, 6}}; 
    // Declares a 2D array where each row represents a task with its start and end times.

    int n = 3; 
    // Number of tasks in the array.

    Sort(tasks, n); 
    // Calls the Sort function to sort the tasks by duration.

    cout << "Sorted tasks: "; 
    // Prints a label for the sorted tasks.

    for (int i = 0; i < n; i++) 
    {
        cout << "(" << tasks[i][0] << ", " << tasks[i][1] << ") "; 
        // Prints each task in the format (start, end).
    }
    cout << endl; 
    // Prints a newline for better readability.

    return 0; 
    // Returns 0, indicating successful execution.
}
