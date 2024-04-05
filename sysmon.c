#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <string.h>

// Function to get CPU usage
double getCpuUsage() {
    FILE* file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Error opening /proc/stat");
        return -1;
    }

    unsigned long long user, nice, system, idle, iowait, irq, softirq;
    fscanf(file, "cpu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq);
    fclose(file);

    unsigned long long totalCpuTime = user + nice + system + idle + iowait + irq + softirq;
    unsigned long long idleCpuTime = idle;

    // Calculate CPU usage percentage
    double cpuUsage = ((double)(totalCpuTime - idleCpuTime) / totalCpuTime) * 100.0;
    
    return cpuUsage;
}

// Function to get RAM usage
double getRamUsage() {
    struct sysinfo info;
    sysinfo(&info);
    double totalRam = (double)info.totalram * info.mem_unit;
    double freeRam = (double)info.freeram * info.mem_unit;
    return ((totalRam - freeRam) / totalRam) * 100;
}

// Function to get disk usage
double getDiskUsage() {
    FILE* file = fopen("/proc/mounts", "r");
    if (!file) {
        perror("Error opening /proc/mounts");
        return -1;
    }

    char device[256], mountPoint[256], type[256], options[256];
    unsigned long long total, free, dummy;
    double diskUsage = 0;

    while (fscanf(file, "%255s %255s %255s %255s %llu %llu %llu\n", device, mountPoint, type, options, &total, &free, &dummy) != EOF) {
        if (strcmp(type, "ext4") == 0 || strcmp(type, "ext3") == 0 || strcmp(type, "ext2") == 0) {
            diskUsage += ((double)(total - free) / total) * 100;
        }
    }

    fclose(file);

    return diskUsage;
}

int main() {
    // Loop infinitely to continuously update and display system information
    while (1) {
        // Clear the screen
        system("clear");


printf("      _______.____    ____  _______..___  ___.   ______   .__   __. \n");
printf("    /       |\\   \\  /   / /       ||   \\/   |  /  __  \\  |  \\ |  |\n");
printf("   |   (----` \\   \\/   / |   (----`|  \\  /  | |  |  |  | |   \\|  |\n");
printf("    \\   \\      \\_    _/   \\   \\    |  |\\/|  | |  |  |  | |  . `  |\n");
printf(".----)   |       |  | .----)   |   |  |  |  | |  `--'  | |  |\\   |\n");
printf("|_______/        |__| |_______/    |__|  |__|  \\______/  |__| \\__|\n");
                                                                   

        printf("\nReal-time System Monitoring (Press Ctrl+C to exit):\n");
        printf("CPU Usage: %.2f%%\n", getCpuUsage());
        printf("RAM Usage: %.2f%%\n", getRamUsage());
        printf("Disk Usage: %.2f%%\n", getDiskUsage());

        // Sleep for a certain interval (e.g., 1 second)
        sleep(1);
    }

    return 0;
}

