#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
typedef vector<int>::iterator vit;
typedef map<int,int>::iterator mit;

const int inf = 1000000000;
struct edge
{
    int r,c,cost,next;
    edge(){}
    edge(int r,int c,int cost,int next):r(r),c(c),cost(cost),next(next){}
}ln[1000000];
int n,m,k;
int flow,cost,tot = 2,st,ed;
bool found;
int d[1100],x[1100],now[1100];
bool v[1100];
map<string,int> des;
string people[505];
int plan[505];
queue<int> que;

void add(int l,int r,int c,int cost)
{
    ln[tot] = edge(r,c,cost,x[l]);
    x[l] = tot++;
    ln[tot] = edge(l,0,-cost,x[r]);
    x[r] = tot++;
}

void relax(int p)
{
   // cerr << p << ' ' << d[p] << endl;
    v[p] = 0;
    for (int i = x[p];i;i = ln[i].next)
        if (ln[i^1].c && d[ln[i].r] > d[p] - ln[i].cost)
        {
            d[ln[i].r] = d[p] - ln[i].cost;
            if (!v[ln[i].r])
            {
                v[ln[i].r] = 1;
                que.push(ln[i].r);
            }
        }
}

void pre()
{
    memset(d,63,sizeof(d));
    memset(v,0,sizeof(v));
    d[ed] = 0;
    v[ed] = 1;
    que.push(ed);
    while (!que.empty())
    {
        relax(que.front());
        que.pop();
    }
}

void sap(int p)
{
    if (p == ed)
    {
        cost += d[st];
        flow++;
        found = true;
        return;
    }
    int i;
    v[p] = true;
    for (i = now[p];i;i = ln[i].next)
    {
        now[p] = i;
        if (ln[i].c && !v[ln[i].r] && d[ln[i].r] + ln[i].cost == d[p])
        {
            sap(ln[i].r);
            if (found) break;
        }
    }
    if (found)
    {
        ln[i].c--;
        ln[i^1].c++;
    }
}

void relab()
{
    int mind = inf;
    for (int p = st;p <= ed;++p)
    {
        now[p] = x[p];
        if (v[p])
            for (int i = x[p];i;i = ln[i].next)
                if (!v[ln[i].r] && ln[i].c && d[ln[i].r] + ln[i].cost - d[p] < mind)
                    mind = d[ln[i].r] + ln[i].cost - d[p];
    }
    for (int p = st;p <= ed;++p)
        if (v[p]) d[p] += mind;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0;i < k;++i)
    {
        string str;
        int price;
        cin >> str >> price;
        des[str] = price;
    }
    int sum = 0;
    for (int i = 1;i <= n;++i)
    {
        cin >> people[i];
        sum += des[people[i]];
    }

    st = 0;
    ed = n + n + 3;
    int S = n + n + 1;
    int T = n + n + 2;

    add(T,S,m,0);
    for (int i = 1;i <= n;++i)
    {
        add(i,ed,1,0);
        add(st,n + i,1,0);
        add(S,i,1,0);
        add(n + i,T,1,0);
        for (int j = i + 1;j <= n;++j)
            if (people[i] == people[j])
                add(n+i,j,1,-des[people[i]]);
            else add(n+i,j,1,0);
    }

    pre();
    //for (int i = st;i <= ed;++i)
    //    cerr << i << ' ' << d[i] << endl;
    memcpy(now,x,sizeof(x));
    while (d[st] < inf)
    {
        memset(v,0,sizeof(v));
        found = false;
        sap(st);
        if (!found) relab();
    }
    assert(flow == n);
    //cerr << flow << endl;
    printf("%.5lf\n",sum + .2 * cost);
    int mtot = 0;
    for (int p = 1;p <= n;++p)
    {
        for (int i = x[p];i;i = ln[i].next)
        {
            if (ln[i].c && ln[i].r <= n + n && ln[i].r > n)
            {
                plan[p] = plan[ln[i].r - n];
                break;
            }
        }
        if (!plan[p]) plan[p] = ++mtot;
        printf("%d\n",plan[p]);
    }
    return 0;
}

