#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream in("domino.in");
ofstream out("domino.out");

int findMatchingPiece(vector< pair<int, int> > pieces, int nextPieceIndex)
{
    int i = 0;
    for(i = nextPieceIndex; i >= 0; i--)
    {
        if(pieces[i].second == pieces[nextPieceIndex].first)
            break;
    }
    return i;
}

void showChain(vector< pair<int, int> > pieces, int dp[100][100], int n, int i)
{
    out << pieces[i].first << " " << pieces[i].second << endl;
    if(i == n-1)
        return;

    for(int k = i + 1; k < n; k++)
    {
        if (dp[i][k] != dp[i][k - 1])
            out << pieces[k].first << " " << pieces[k].second << endl;
    }
}

void showChainReverse(vector< pair<int, int> > pieces, int dp[100][100], int n, int i)
{
    out << pieces[i].first << " " << pieces[i].second << endl;
    if(i == 0)
        return;

    for(int k = i - 1; k >= 0; k--)
    {
        if (dp[i][k] != dp[i][k + 1])
            out << pieces[k].first << " " << pieces[k].second << endl;
    }
}

int main()
{
    vector< pair<int, int> > pieces;
    int n, p1, p2;

    in >> n;
    for(int i = 0; i < n; i++)
    {
        in >> p1 >> p2;
        pieces.push_back( make_pair(p1, p2) );
    }

    //vector to find the actual substring
    //int father[n] = {0};

    ///dp[i][j] - longest chain using pieces i..j
    int dp[100][100];

    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    pair<int, int> lastPiece;
    for(int i = 0; i < n; i++)
    {
        lastPiece = pieces[i];
        for(int j = i + 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if(lastPiece.second == pieces[j].first)
            {
                dp[i][j]++;
                lastPiece = pieces[j];
            }
        }

        lastPiece = pieces[i];
        if(i > 0)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                dp[i][j] = dp[i][j + 1];
                if(lastPiece.first == pieces[j].second)
                {
                    dp[i][j]++;
                    lastPiece = pieces[j];
                }
            }
        }

    }

    int maxChainLength = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(dp[i][j] > maxChainLength)
                maxChainLength = dp[i][j];

    bool shown = false;
    int maxChainsCount = 0;
    for(int i = 0; i < n; i++)
    {
        bool foundLine = false;
        for(int j = 0; j < n; j++)
        {
            if(dp[i][j] == maxChainLength)
            {
                if(!shown)
                {
                    if(j >= i)
                        showChain(pieces, dp, n, i);
                    else
                        showChainReverse(pieces, dp, n, i);
                    shown = true;
                }
                foundLine = true;
            }
        }
        if(foundLine)
            maxChainsCount++;
    }

    out << maxChainsCount;

    in.close();
    out.close();
    return 0;
}
