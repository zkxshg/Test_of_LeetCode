// Quick sort
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size();
        for (int i = 0; i < len; i++) A[i] = A[i]*A[i];
        QuickSort(A, 0, A.size()-1);
        return A;
    }
    void QuickSort(vector<int>& B, int f, int l){
        int x = B[f];
        int i = f + 1;
        int j = l;
        while (i < j){
            while (j >= f + 1 && B[j] >= x) j--;  // 顺序颠倒会引发 heap-buffer-overflow！！ 
            while (i <= l && B[i] <= x) i++;
            if (i < j){
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
        if (B[f] > B[j]){
            B[f] = B[j];
            B[j] = x;
        }
        if (f < j-1) QuickSort(B, f, j-1);
        if (j+1 < l) QuickSort(B, j+1, l);
    }
};

// demo

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void QuickSort(vector<int>& B, int f, int l);
int counter = 0;
int main()
{
    vector<int>obj = {-1,2,2};
    vector<int>& A = obj;
    int len = A.size();
    cout << A.begin() ;
    for (int i = 0; i < len; i++) A[i] = A[i]*A[i];
    QuickSort(A, 0, A.size()-1);
    for (int i = 0; i < obj.size(); i++) cout << A[i] << ",";
    return 0;
}
 void QuickSort(vector<int>& B, int f, int l){
        int x = B[f];
        int i = f + 1;
        int j = l;
        while (i < j){
            while (B[j] >= x && j >= f + 1) j--;
            while (B[i] <= x && i <= l) i++;
            if (i < j){
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
            cout << "i = " << i << " and j = " << j << endl;
        }
        if (B[f] > B[j]){
            B[f] = B[j];
            B[j] = x;
        }
        cout << "f = " << f << ", l = " << l << endl;
        for (int i = 0; i < B.size(); i++) cout << B[i] << "," ;
        cout << endl;
        counter ++;
        if (f < j-1) QuickSort(B, f, j-1);
        if (j+1 < l) QuickSort(B, j+1, l);
    }
