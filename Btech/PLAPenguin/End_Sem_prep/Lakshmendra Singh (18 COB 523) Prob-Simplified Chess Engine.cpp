#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

char board[4][4];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool inr(int i, int j)
{
    if(i>=0&&i<4&&j>=0&&j<4) return true;
    return 0;
}

bool win(char board[][4], bool player, int move)
{
    if(move<0) return false;
    if(player)
    {
        bool res = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(board[i][j]>='A'&&board[i][j]<='Z')
                {
                    char c = board[i][j];
                    if(c == 'R')
                    {
                        for(int k = 1; k < 4; k++)
                        {
                            int x = k+i; int y = j;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                    }
                    if(c == 'B')
                    {
                        //cerr<<"AKS\n";
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i+k; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i+k; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }                        
                    }
                    if(c == 'N')
                    {
                        //cerr<<"QWKQQ"<<endl;
                        for(int k = 0; k < 8; k++)
                        {
                            int x = dx[k]+i; int y = dy[k]+j;
                            //cerr<<"MOVE :"<<x<<' '<<y<<'\n';
                            if(!inr(x,y)) continue;
                            if(board[x][y]>='A'&&board[x][y]<='Z') continue;
                            if(board[x][y]=='q') 
                            {
                                //cerr<<"HERE\n"; 
                                return true;
                            }
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //cerr<<x<<' '<<y<<' '<<res<<'\n';
                            //cerr<<"MOVE :"<<x<<' '<<y<<'\n';
                            if(res) return true;
                        }
                    }
                    if(c == 'Q')
                    {
                        //cerr<<"QW\n";
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i+k; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i+k; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = k+i; int y = j;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='A'&&board[x][y]<='Z') break;
                            if(board[x][y]=='q') return 1;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res|=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(res) return true;
                            if(board[x][y]!='.') break;
                        }
                    }
                }
                //cerr<<i<<' '<<j<<'\n';
            }
        }
        return res;
    }
    else
    {
        bool res = 1;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                char c = board[i][j];
                    if(c == 'r')
                    {
                        for(int k = 1; k < 4; k++)
                        {
                            int x = k+i; int y = j;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            //if(board[x][y]!='.') break;
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                    }
                    if(c == 'b')
                    {
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i+k; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i+k; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }                        
                    }
                    if(c == 'n')
                    {
                        for(int k = 0; k < 8; k++)
                        {
                            int x = dx[k]+i; int y = dy[k]+j;
                            if(!inr(x,y)) continue;
                            if(board[x][y]>='a'&&board[x][y]<='z') continue;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            //if(board[x][y]!='.') break;
                        }
                    }
                    if(c == 'q')
                    {
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i+k; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i+k; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }    
                        for(int k = 1; k < 4; k++)
                        {
                            int x = k+i; int y = j;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i; int y = j+k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i-k; int y = j;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }
                        for(int k = 1; k < 4; k++)
                        {
                            int x = i; int y = j-k;
                            if(!inr(x,y)) break;
                            if(board[x][y]>='a'&&board[x][y]<='z') break;
                            if(board[x][y]=='Q') return false;
                            char a[4][4];
                            for(int z=0;z<4;z++)
                            {
                                for(int up=0; up<4;up++)
                                {
                                    a[z][up] = board[z][up];
                                }
                            }
                            a[x][y] = a[i][j];
                            a[i][j]='.';
                            res&=win(a,(player^1),move-1);
                            if(!res) return false;
                            if(board[x][y]!='.') break;
                        }                    
                    }
            }
        }
        return res;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                board[i][j] = '.';
            }
        }
        int w, b, m;
        cin>>w>>b>>m;
        
        for(int i = 0; i < w; i++)
        {
            char c; char p; int y;
            cin>>c>>p>>y;
            int x = p-'A';
            y--;
            board[x][y] = c;
        }
        for(int i = 0; i < b; i++)
        {
            char c; char p; int y;
            cin>>c>>p>>y;
            int x = p-'A';
            y--;
            board[x][y] = c - 'A' + 'a';
        }
        
        if(win(board, 1, m-1))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}

