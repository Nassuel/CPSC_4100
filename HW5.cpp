/**
 * @file HW5
 * @author Nassuel Valera Cuevas
 * @see "Seattle University, CPSC4100, Winter 2019"
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << input.at(i) << " ";
    }
    cout << endl;
}

// KSRec function
int KSRec(int c, int i, int n, vector<int> values, vector<int> weight, int **T, int **Keep)
{
    if (i > n)
    {
        if (T[c][n + 1] == 0)
            T[c][n + 1] = 0;
        return T[c][n + 1];
    }
    else
    {
        if (weight[i] > c)
        {
            if (T[c][i + 1] == 0)
                T[c][i + 1] = KSRec(c, i + 1, n, values, weight, T, Keep);
            return T[c][i + 1];
        }
        else
        {
            int oof = weight[i];
            if (T[c][i + 1] == 0)
                T[c][i + 1] = KSRec(c, i + 1, n, values, weight, T, Keep);
            if (T[c - oof][i + 1] == 0)
            {
                T[c - oof][i + 1] = KSRec(c - oof, i + 1, n, values, weight, T, Keep);
            }
            return max(T[c][i + 1], values[i] + T[c - oof][i + 1]);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
        cout << "Please pass in 2 arguments where the first argument is the capacity of the knapsack and the second is the file or the path of the file. E.g. \"20 /file/path/fileName.txt\"";
        return 0;
    }

    // Vectors
    vector<int> weight;
    vector<int> values;

    // Read file bit
    ifstream myReadFile;

    string file(argv[2]);

    file = "./" + file;
    myReadFile.open(file.c_str());

    string line;

    // Get line from file
    while (getline(myReadFile, line))
    {
        stringstream linestream(line);
        string value;
        string state;

        int num;

        // Iterate through the linestream line
        while (getline(linestream, value, ','))
        {
            if (value == "Weight")
                state = "Weight";
            if (value == "Value")
                state = "Value";

            stringstream check(value);
            check >> num;

            if (state == "Weight" && value != "Weight")
                weight.push_back(num);
            if (state == "Value" && value != "Value")
                values.push_back(num);
        }
    }

    // If the vectors are empty, the return error
    if (weight.size() == 0 || values.size() == 0)
    {
        cout << "File not found or file format is incorrect. File path or name may be incorrect. Please check and run again." << endl;
        return 0;
    }

    myReadFile.close();

    cout << "Read in values " << endl;
    cout << "Values ";
    print(values);
    cout << "Weight ";
    print(weight);

    // Get vector sizes for Keep and Table arrays
    int w = weight.size();
    int n = values.size();

    int c = 0;
    stringstream check(argv[1]);
    check >> c;

    // Creating table array dynamically
    int **Keep = new int *[c + 2];

    for (int i = 0; i < c + 2; i++)
    {
        Keep[i] = new int[n + 2];
    }

    // Making sure array memory reference is set to 0
    for (int i = 0; i < c + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
            Keep[i][j] = 0;
    }

    // Creating table array dynamically
    int **T = new int *[c + 2]; //[c + 1][n + 1];

    for (int i = 0; i < c + 2; i++)
    {
        T[i] = new int[n + 2];
    }

    // Making sure array memory reference is set to 0
    for (int i = 0; i < c + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
            T[i][j] = 0;
    }

    // Call to KSRec function
    int optSum = KSRec(c, 0, n, values, weight, T, Keep);

    cout << "Optimal Sum: " << optSum << endl;

    // int *keepInd = new int[c + 2];

    // for (int i = 0; i < c + 2; i++)
    // {
    //     for (int j = 0; j < n + 2; j++)
    //     {
    //         cout << " Row " << i << " " << j << " " << T[i][j] << endl;
    //         keepInd[i] = T[i][j];
    //     }
    //     cout << endl;
    // }

    // // Sum vars
    // int wSum(0);
    // int vSum(0);

    // int keeSize = sizeof(keepInd) / sizeof(keepInd[0]);

    // // Print outs
    // cout << "Weights: ";
    // for (int i = 0; i < keeSize; i++)
    // {
    //     if (keepInd[i])
    //     {
    //         wSum += weight[i];
    //         cout << weight[i] << " ";
    //     }
    // }
    // cout << endl;

    // cout << "Values: ";
    // for (int i = 0; i < keeSize; i++)
    // {
    //     if (keepInd[i])
    //     {
    //         vSum += values[i];
    //         cout << values[i] << " ";
    //     }
    // }
    // cout << endl;

    // cout << "Optimal value: " << vSum << endl;
    // cout << "Sum of weight: " << wSum << endl;

    // Deleting allocated memory
    for (int i = 0; i < c + 2; i++)
    {
        delete[] T[i];
        delete[] Keep[i];
    }

    T = 0;
    Keep = 0;
    //delete[] keepInd;

    //keepInd = 0;

    return 0;
};