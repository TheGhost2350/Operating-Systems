#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Memory block structure
struct MemoryBlock {
    int id;
    int size;
    bool allocated;
};

// Function to display memory status
void displayMemory(const vector<MemoryBlock>& memory) {
    cout << "Memory Status:" << endl;
    cout << "ID\tSize\tAllocated" << endl;
    for (const MemoryBlock& block : memory) {
        cout << block.id << "\t" << block.size << "\t" << (block.allocated ? "Yes" : "No") << endl;
    }
    cout << endl;
}

// Function to allocate memory using First Fit strategy
void firstFit(vector<MemoryBlock>& memory, int processId, int processSize) {
    for (MemoryBlock& block : memory) {
        if (!block.allocated && block.size >= processSize) {
            block.allocated = true;
            cout << "Process " << processId << " allocated to Memory Block " << block.id << " using First Fit" << endl;
            return;
        }
    }
    cout << "Unable to allocate Process " << processId << " using First Fit" << endl;
}

// Function to allocate memory using Best Fit strategy
void bestFit(vector<MemoryBlock>& memory, int processId, int processSize) {
    int bestFitIndex = -1;
    int bestFitSize = INT_MAX;

    for (size_t i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize && memory[i].size < bestFitSize) {
            bestFitIndex = i;
            bestFitSize = memory[i].size;
        }
    }

    if (bestFitIndex != -1) {
        memory[bestFitIndex].allocated = true;
        cout << "Process " << processId << " allocated to Memory Block " << memory[bestFitIndex].id << " using Best Fit" << endl;
    } else {
        cout << "Unable to allocate Process " << processId << " using Best Fit" << endl;
    }
}

// Function to allocate memory using Worst Fit strategy
void worstFit(vector<MemoryBlock>& memory, int processId, int processSize) {
    int worstFitIndex = -1;
    int worstFitSize = -1;

    for (size_t i = 0; i < memory.size(); ++i) {
        if (!memory[i].allocated && memory[i].size >= processSize && memory[i].size > worstFitSize) {
            worstFitIndex = i;
            worstFitSize = memory[i].size;
        }
    }

    if (worstFitIndex != -1) {
        memory[worstFitIndex].allocated = true;
        cout << "Process " << processId << " allocated to Memory Block " << memory[worstFitIndex].id << " using Worst Fit" << endl;
    } else {
        cout << "Unable to allocate Process " << processId << " using Worst Fit" << endl;
    }
}

int main() {
    // Initialize memory blocks
    vector<MemoryBlock> memory = {
        {1, 50, false},
        {2, 200, false},
        {3, 70, false},
        {4, 150, false},
        {5, 100, false}
    };

    // Display initial memory status
    displayMemory(memory);

    // Allocate processes using different strategies
    int processId = 1;
    int processSize;

    cout << "Enter size for Process " << processId << ": ";
    cin >> processSize;
    firstFit(memory, processId, processSize);
    displayMemory(memory);

    processId = 2;
    cout << "Enter size for Process " << processId << ": ";
    cin >> processSize;
    bestFit(memory, processId, processSize);
    displayMemory(memory);

    processId = 3;
    cout << "Enter size for Process " << processId << ": ";
    cin >> processSize;
    worstFit(memory, processId, processSize);
    displayMemory(memory);

    return 0;
}

