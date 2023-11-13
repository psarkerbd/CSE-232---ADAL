#include<bits/stdc++.h>
using namespace std;

const int diagonal_dir = 1;
const int left_dir = 2;
const int up_dir = 0;

int LCS[100][100], direction[100][100];

void initialization(int n)
{
    for(int i=0; i<=n; i++)
    {
        LCS[0][i] = 0;
    }

    for(int i=0; i<=n; i++)
    {
        LCS[i][0] = 0;
    }
}

void print_lcs(int i, int j, string X)
{
    if(i==0 || j==0)
    {
        return;
    }

    if(direction[i][j] == diagonal_dir)
    {
        print_lcs(i-1, j-1, X);
        cout << X[i-1];
    }

    else if(direction[i][j] == up_dir)
    {
        print_lcs(i-1, j, X);
    }

    else
    {
        print_lcs(i, j-1, X);
    }
}

void Longest_Common_Subsequence(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    initialization(n);

    int i, j;

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(X[i-1] == Y[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
                direction[i][j] = diagonal_dir;
            }

            else if(LCS[i-1][j] >= LCS[i][j-1])
            {
                LCS[i][j] = LCS[i-1][j];
                direction[i][j] = up_dir;
            }

            else
            {
                LCS[i][j] = LCS[i][j-1];
                direction[i][j] = left_dir;
            }
        }
    }

    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            cout << LCS[i][j] << " ";
        }

        cout << "\n";
    }

    cout << "The length of the longest common subsequence is = " << LCS[m][n] << "\n";

    print_lcs(m, n, X);
}

int main()
{
    string X = "ACADB";
    string Y = "CBDA";

    Longest_Common_Subsequence(X,Y);

    //cout << "Length of X is = " << m << "\nLength of Y is = " << n;

    return 0;
}