# Empowering Edge Systems : Distrubuted Machine LEarning in Heterogeneous Environments  
This distributed training method is critical for handling sensitive or extensive data locally without the inefficiencies and privacy concerns of central cloud processing. Instead of transmitting all data to a central server, edge devices compute model updates locally and share only parameter updates, significantly reducing bandwidth requirements and enhancing data privacy.  

------------------------------------------------------------

# Description
The algorithm which we implemented was **Adaptive Synchronous Parallel (ADSP)**   

The ADSP (Adaptive Synchronous Parallel) model, a new parameter synchronization method designed for distributed machine learning using heterogeneous edge systems and a central parameter server (PS). ADSP aims to maximize the computational efficiency of each worker and balance the trade-off between hardware utilization and statistical efficiency to minimize the time required for model convergence.  

In ADSP, training time is segmented into equal-sized intervals called check periods, marked by checkpoints. The process whereby a worker sends its computed gradients to the PS is termed a commit, and the frequency of these commits during a check period is defined as the commit rate.  

The system comprises two main modules:  
1) A novel synchronization model that allows faster systems to train more before each update, while ensuring uniform commit rates across all workers.  
2) A global commit rate search algorithm that determines the optimal commit rate for all workers to facilitate rapid convergence.  

---

# ADSP Workflow  
        Task A1    Task B1    Task C1
          |          |          |
          v          v          v
        Synchronization Point 1
          |          |          |
          v          v          v
        Task A2    Task B2    Task C2
          |          |          |
          v          v          v
        Synchronization Point 2  

---

# ADSP Algorithm and Analysis
![image](https://github.com/Satish-Babu-M/Distributed-ML-in-Heterogeneous-Environments/assets/167501522/d5c19dfd-d34d-4029-b559-54e4c10d8490)  


The Adaptive Synchronous Parallel (ADSP) algorithm is designed to address the wide variability in computational power and network delays among edge devices in distributed machine learning systems. The key strategy of ADSP is to manage this heterogeneity by allowing each device (or worker) to process a different number of mini-batches between updates, depending on its capabilities. This approach eliminates the need for faster devices to wait for slower ones, ensuring that all workers commit their updates at approximately the same frequency over time. This adaptation not only makes the training process more efficient but also helps maintain consistent model convergence across the network.  

# Conclusion  
ADSP minimizes waiting times during training and ensures that all workers contribute approximately equally to the model's convergence. Testbed experiments demonstrate that ADSP can accelerate convergence by up to 62.4% compared to existing synchronization models and is adaptable to various levels of system heterogeneity and large-scale ML applications.

## Running the project and Execution
First of all, clone the project:

```git clone https://github.com/jbvincey/InstantAppSample.git```  

Then open the downloaded code with code editor and made local changes.  

**To compile the code, Enter the following command**
For Windows, MacOS and Linux :  

```clang++ main.cpp -o main```  # If using clang++  
 or  
```g++ main.cpp -o main```      # If using g++  

**Run the executable**  

After compilation, you can run the executable directly from the terminal.  

For Windows : 
```./main.exe```  

For MacOS and Linux : 
```./main```  


## Results  
![Output](https://github.com/Satish-Babu-M/Distributed-ML-in-Heterogeneous-Environments/assets/167501522/e764bff6-8aa7-4889-9a1a-649492316d47)





