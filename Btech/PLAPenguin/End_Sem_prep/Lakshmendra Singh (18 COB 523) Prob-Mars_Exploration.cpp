#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
#define MANYTESTS 0
#include <bits/stdc++.h>
using namespace std;
#define Size(x) (int(x.size()))

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c == 13) continue;
    if(c == 10) return s;
    s += c;
    }
  return s;
  }

int scanerr;

int getNum() {
#ifdef LINEBYLINE
  string s = getLine();
  return atoi(s.c_str());
#else
  int i;
  scanerr = scanf("%d", &i);
  return i;
#endif
  }

string getStr() {
#ifdef LINEBYLINE
  return getStr();
#else
  scanerr = scanf("%s", buf);
  return buf;
#endif
  }

#line 10 "work.cpp"
void solveCase() {
  int res = 0;

  string s = getStr();
  int N = 0;
  for(int i=0; i<Size(s); i++)
    if(s[i] != (i%3 == 1 ? 'O' : 'S')) N++;
  
  printf("%d\n", N);
  }
#define P 1000000007

int main() {

  if(!MANYTESTS) Tests = 1;
  else Tests = getNum();
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
  return 0;
  }

