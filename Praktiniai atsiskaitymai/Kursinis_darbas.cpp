#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

struct Stats {
    long long comparisons = 0;
    long long swaps = 0;
    long long timeMicroseconds = 0;
};

void insertionSort(vector<int>& arr, Stats& stats) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            stats.comparisons++;

            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats.swaps++;
                j--;
            }
            else {
                break;
            }
        }

        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int left, int mid, int right, Stats& stats) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {

        stats.comparisons++;

        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right, Stats& stats) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, stats);
    mergeSort(arr, mid + 1, right, stats);

    merge(arr, left, mid, right, stats);
}

vector<int> generateRandomData(int size) {

    vector<int> data(size);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100000);

    for (int i = 0; i < size; i++)
        data[i] = dist(gen);

    return data;
}

vector<int> generateSortedData(int size) {

    vector<int> data(size);

    for (int i = 0; i < size; i++)
        data[i] = i;

    return data;
}

vector<int> generateReverseData(int size) {

    vector<int> data(size);

    for (int i = 0; i < size; i++)
        data[i] = size - i;

    return data;
}

Stats testInsertion(vector<int> data) {

    Stats stats;

    auto start = high_resolution_clock::now();

    insertionSort(data, stats);

    auto stop = high_resolution_clock::now();

    stats.timeMicroseconds =
        duration_cast<microseconds>(stop - start).count();

    return stats;
}

Stats testMerge(vector<int> data) {

    Stats stats;

    auto start = high_resolution_clock::now();

    mergeSort(data, 0, data.size() - 1, stats);

    auto stop = high_resolution_clock::now();

    stats.timeMicroseconds =
        duration_cast<microseconds>(stop - start).count();

    return stats;
}

void runTest(const vector<int>& originalData,
             const string& dataType,
             int size) {

    Stats insertionAvg;
    Stats mergeAvg;

    for (int i = 0; i < 5; i++) {

        Stats s1 = testInsertion(originalData);
        Stats s2 = testMerge(originalData);

        insertionAvg.timeMicroseconds += s1.timeMicroseconds;
        insertionAvg.comparisons += s1.comparisons;
        insertionAvg.swaps += s1.swaps;

        mergeAvg.timeMicroseconds += s2.timeMicroseconds;
        mergeAvg.comparisons += s2.comparisons;
    }

    insertionAvg.timeMicroseconds /= 5;
    insertionAvg.comparisons /= 5;
    insertionAvg.swaps /= 5;

    mergeAvg.timeMicroseconds /= 5;
    mergeAvg.comparisons /= 5;

    cout << "\n=========================================\n";
    cout << "Data type: " << dataType << endl;
    cout << "Size: " << size << endl;

    cout << "\nInsertion Sort\n";
    cout << "Time (us): " << insertionAvg.timeMicroseconds << endl;
    cout << "Comparisons: " << insertionAvg.comparisons << endl;
    cout << "Swaps: " << insertionAvg.swaps << endl;

    cout << "\nMerge Sort\n";
    cout << "Time (us): " << mergeAvg.timeMicroseconds << endl;
    cout << "Comparisons: " << mergeAvg.comparisons << endl;
    cout << "Swaps: N/A" << endl;
}

int main() {

    vector<int> sizes = {5000, 10000, 50000};

    for (int size : sizes) {

        vector<int> randomData =
            generateRandomData(size);

        vector<int> sortedData =
            generateSortedData(size);

        vector<int> reverseData =
            generateReverseData(size);

        runTest(randomData, "Random", size);
        runTest(sortedData, "Sorted", size);
        runTest(reverseData, "Reverse", size);
    }

    return 0;
}