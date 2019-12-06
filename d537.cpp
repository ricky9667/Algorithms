#include<bits/stdc++.h>
using namespace std;

#define N 101
struct color{
    int x, y, time;
    char color;
};

int n, max_area, t, cnt_dark;
char target, current[2][N][N];
queue<color> q;
int dir[9][2]={{1,1},{1,0},{1,-1},{0,1},{0,0},{0,-1},{-1,1},{-1,0},{-1,-1}};

bool test(int x, int y)
{
    if(x>=0 && y>=0 && x<n && y<n) return true;
    return false;
}

char combine(char a, char b)
{
    if(a=='W') return b;
    if(b=='W') return a;
    if(a==b) return a;

    if((a=='R' && b=='Y') ||( a=='Y' && b=='R')) return 'O';
    if((a=='R' && b=='B') || (a=='B' && b=='R')) return 'P';
    if((a=='Y' && b=='B') || (a=='B' && b=='Y')) return 'G';
 
    if((a=='O' && (b=='R' || b=='Y')) || (b=='O' && (a=='R' || a=='Y'))) return 'O';
    if((a=='P' && (b=='R' || b=='B')) || (b=='P' && (a=='R' || a=='B'))) return 'P';
    if((a=='G' && (b=='B' || b=='Y')) || (b=='G' && (a=='B' || a=='Y'))) return 'G';

    if((a=='O' && b=='B') || (a=='P' && b=='Y') || (a=='G' && b=='R')) return 'D';
    if((b=='O' && a=='B') || (b=='P' && a=='Y') || (b=='G' && a=='R')) return 'D';

    if((a=='O' && b=='P') || (a=='O' && b=='G') || (a=='G' && b=='P')) return 'D';
    if((b=='O' && a=='P') || (b=='O' && a=='G') || (b=='G' && a=='P')) return 'D';

    if(a=='D' || b=='D') return 'D';
}

/*
R = Red, Y = Yellow, B = Blue
O(R+Y) = Orange, P(R+B) = Purple, G(Y+B) = Green
D(R+Y+B) = Dark
*/

int diffusion(color c)
{
    for(int i=0;i<9;i++)
    {
        color next;
        next.x = c.x+dir[i][0];
        next.y = c.y+dir[i][1];
        next.time = c.time+1;
        if(test(next.x, next.y) && current[c.time%2][next.x][next.y]!='D')
        {
            next.color = combine(current[c.time%2][next.x][next.y], c.color);
            current[next.time%2][next.x][next.y] = next.color;
            // if(current[c.time%2][next.x][next.y]!='D' && next.color=='D')
            //     cnt_dark++;
        }
        if(next.color!='D') q.push(next);
    }
}

int count_area(int time)
{
    int odd_area=0, even_area=0;
    int odd_dark=0, even_dark=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(current[0][i][j]==target) even_area++;
            if(current[1][i][j]==target) odd_area++;
            if(current[0][i][j]==target) even_dark++;
            if(current[1][i][j]==target) odd_dark++;
        }
    cnt_dark = (time%2 ? odd_dark : even_dark);
    return (time%2 ? odd_area : even_area);
}

int main()
{
    cin>>n;
    for(int i=0;i<3;i++)
    {
        color c;
        cin>>c.color>>c.x>>c.y;
        c.time = 0;
        q.push(c);
        current[0][c.x][c.y]=c.color;
    }
    cin>>target;
    
    if(target=='R' || target=='Y' || target=='B') max_area=1;
    else max_area=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            current[0][i][j] = current[1][i][j] = 'W';

    t=1, cnt_dark=0;
    while(cnt_dark<n*n)
    {
        color tmp = q.front();
        q.pop();
        if(tmp.time==t) 
        {
            cout<<"t = "<<t<<'\n';
            max_area = max(max_area, count_area(t++));
            // for(int i=0;i<n;i++) // testing
            //     cout<<current[!(t%2)][i]<<'\n';
            cout<<cnt_dark<<'\n';
        }
        diffusion(tmp);
    }

    cout<<max_area<<'\n';
    return 0;
}