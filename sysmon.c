#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to get and print system information
void printSystemInfo() {
    // System call to get memory usage (example)
    // Replace this with platform-specific code for accurate memory usage
    double memoryUsage = rand() % 100; // Random value for demonstration purposes
    printf("Memory Usage: %.2f%%\n", memoryUsage);

    // System call to get CPU usage (example)
    // Replace this with platform-specific code for accurate CPU usage
    double cpuUsage = rand() % 100; // Random value for demonstration purposes
    printf("CPU Usage: %.2f%%\n", cpuUsage);

    // Add more system information as needed
}

int main() {
    // ASCII art
    printf(" _______  _______  _______  _______  _______ \n");
    printf("(  ____ \\(  ___  )(       )(  ____ \\(  ____ \\ \n");
    printf("| (    \\/| (   ) || () () || (    \\/| (    \\/ \n");
    printf("| (_____ | (___) || || || || (__    | (_____  \n");
    printf("(_____  )|  ___  || |(_)| ||  __)   (_____  ) \n");
    printf("      ) || (   ) || |   | || (            ) | \n");
    printf("/\\____) || )   ( || )   ( || (____/\\/\\____) / \n");
    printf("\\_______)|/     \\||/     \\|(_______/\\______/  \n");

    // Loop infinitely to continuously update and display system information
    while (1) {
        // Clear the screen
        system("clear");

        // Print system information
        printf("\nReal-time System Monitoring (Press Ctrl+C to exit):\n");
        printSystemInfo();

        // Sleep for a certain interval (e.g., 1 second)
        sleep(1);
    }

    return 0;
}

