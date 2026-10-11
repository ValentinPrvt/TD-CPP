#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SearchingAlgorithm {
protected:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;

public:
    SearchingAlgorithm() {
        numberComparisons = 0;
    }

    virtual int search(vector<int> v, int target) = 0;

    void displaySearchResults(ostream& out, int results, int target) {
        totalComparisons = totalComparisons + numberComparisons;
        totalSearch = totalSearch + 1;
        averageComparisons = (double)totalComparisons / totalSearch;

        out << "Pour trouver " << target << " a l'indice " << results
            << " : " << numberComparisons << " comparaisons" << endl;
    }
};

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0;

class LinearSearch : public SearchingAlgorithm {
public:
    int search(vector<int> v, int target) {
        numberComparisons = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            numberComparisons++;
            if (v[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

class JumpSearch : public SearchingAlgorithm {
public:
    int search(vector<int> v, int target) {
        numberComparisons = 0;
        int n = v.size();
        int step = sqrt(n);
        int i = 0;

        // on saute tant que l'element est plus petit que target
        while (i < n && v[i] < target) {
            numberComparisons++;
            i = i + step;
        }

        // target est entre i - step + 1 et i : on cherche un par un
        int start = i - step + 1;
        if (start < 0) {
            start = 0;
        }
        for (int j = start; j < n && j <= i; j++) {
            numberComparisons++;
            if (v[j] == target) {
                return j;
            }
        }
        return -1;
    }
};

class BinarySearch : public SearchingAlgorithm {
public:
    int search(vector<int> v, int target) {
        numberComparisons = 0;
        int low = 0;
        int high = v.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            numberComparisons++;
            if (v[mid] == target) {
                return mid;
            }
            if (v[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
