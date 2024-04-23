#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

const int M = 3; // Assuming M is 3 for simplicity
const double η_0 = 0.01; // Local learning rate
const double Γ = 60.0; // Timeout in seconds

// Algorithm 1: Commit Rate Adjustment at the Scheduler
double ONLINEEVALUATE(int Ctarget) {
    std::cout << "Online evaluation for Ctarget: " << Ctarget << std::endl;
    // Simulate training for 1 minute
    std::this_thread::sleep_for(std::chrono::seconds(10));
    double reward = 1.0; // Example reward value
    return reward;
}

int DECIDECOMMITRATE(int Ctarget) {
    double r1 = ONLINEEVALUATE(Ctarget);
    double r2 = ONLINEEVALUATE(Ctarget + 1);

    if (r2 > r1) {
        return DECIDECOMMITRATE(Ctarget + 1);
    } else {
        return Ctarget;
    }
}

void MAINFUNCTION() {
    int Ctarget;

    for (int e = 1; e <= 2; ++e) {
        Ctarget = 0;
        for (int i = 0; i < M; ++i) {
            if (Ctarget < (i + 1)) {
                Ctarget = i + 1;
            }
        }

        Ctarget = DECIDECOMMITRATE(Ctarget);
        
        std::cout << "Epoch " << e << ": Optimal Ctarget = " << Ctarget << std::endl;
        
        // Simulate running for remaining time
        std::this_thread::sleep_for(std::chrono::seconds(30)); // Sleep for 30 seconds
    }
}

// Worker function
void WORKER(int worker_id) {
    int deltaC_target = 0;

    for (int e = 1; e <= 2; ++e) {
        // Receive ∆C_target from the scheduler
        deltaC_target = worker_id + 1; // Example value

        double timeout = Γ * deltaC_target;
        std::cout << "Worker " << worker_id << " received deltaC_target: " << deltaC_target << ", Timeout: " << timeout << " seconds" << std::endl;

        // Simulate training until model convergence
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Sleep for 5 seconds

        // Commit Ui to the PS
        std::cout << "Worker " << worker_id << " committed Ui to PS" << std::endl;

        // Simulate receiving updated global model parameters and update local model
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Sleep for 3 seconds

        // Restart timer
        std::cout << "Worker " << worker_id << " restarted timer" << std::endl;
    }
}

// Parameter Server function
void PARAMETERSERVER() {
    for (int e = 1; e <= 2; ++e) {
        // Simulate checking for commit Ui from workers
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Sleep for 2 seconds
        std::cout << "Parameter Server checked for commits" << std::endl;

        // Simulate updating global model parameters
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep for 1 second
        std::cout << "Parameter Server updated global model parameters" << std::endl;
    }
}

int main() {
    // Run MAINFUNCTION in a separate thread
    std::thread main_thread(MAINFUNCTION);

    // Create worker threads
    std::vector<std::thread> worker_threads;
    for (int i = 0; i < M; ++i) {
        worker_threads.push_back(std::thread(WORKER, i));
    }

    // Run Parameter Server
    PARAMETERSERVER();

    // Join threads
    main_thread.join();
    for (auto& thread : worker_threads) {
        thread.join();
    }

    return 0;
}