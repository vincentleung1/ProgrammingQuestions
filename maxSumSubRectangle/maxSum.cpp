/*
    @Author Vincent Leung
    @Date   June 24th, 2017
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kadaneAlgorithm(vector<int> A) {
    int max_so_far = A[0], max_ending_here = A[0];

    for (int i = 1; i < A.size(); i++) {
        int x = A[i];
        max_ending_here = max(x, max_ending_here + x);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {
	// Get the input for the problem
	int testCases, R, C;
	cin >> testCases;
	vector<vector <vector<int>>> cases;
	for (int k = 0; k < testCases; k++){
	    vector <vector<int>> test;
    	cin >> R >> C;
    	for (int i = 0; i < R; i++) {
    	    vector<int> thisRow;
    	    int temp;
    	    for(int j = 0; j < C; j++) {
    	        cin >> temp;
    	        thisRow.push_back(temp);
    	    }
    	    test.push_back(thisRow);
    	}
    	cases.push_back(test);
	}

	// Print out the test cases
	for(int i = 0; i < cases.size(); i++){
	    cout << "Test case: " << i+1 << endl;
	    for(int j = 0; j < cases[i].size(); j++){
	        for (int k = 0; k < cases[i][j].size(); k++){
	            cout << cases[i][j][k] << " ";
	        }
	        cout << endl;
	    }
	}

    // Now that we have them, find the maximum rectangle.
    // cases [i]  holds a test.
    // test [j] holds a row
    // row [k] holds the value of the jth row's k'th index

    int currentMax = 0;
    // Apply Kadane's algorithm on the matrix repeatedly O(n^2) times
    for (int i = 0; i < cases.size(); i++){ // For each case...
        for(int l = 0; l < cases[i].size(); l++){ // Up -- pivot
            vector<int> tempArr (cases[i][l].size(), 0);
            for (int j = l; j < cases[i].size(); j++){ // Down -- pivot
                for (int k = 0; k < cases[i][j].size(); k++){ // Row
                    // Add the row to tempArr
                    tempArr[k] += cases[i][j][k];
                }
                // Take the max between previous iteration and this iteration
                currentMax = max(currentMax, kadaneAlgorithm(tempArr));
            }
        }
        // Print and reset the current maximum for the next "up" pivot
        cout << currentMax << endl;
        currentMax = 0;
    }
	return 0;
}
