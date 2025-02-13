///Cod semifrumos (am folosit struct ca sa ma dau mare ca stiu struct))
#include <fstream>
#include <queue>
using namespace std;
ifstream cin("mewtwo.in");
ofstream cout("mewtwo.out");
const int INF = 1e9;
char mat[1001][1001];
int dist[1001][1001],n,m;
int di[] = {0,0,1,-1}, dj[] = {1,-1,0,0};
struct P{
    int x, y;
    void read(int l, int m)
    {
        x = l;
        y = m;
    }
};
queue<pair<int,int>> q;
void Lee(int x, int y)
{
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            dist[i][j] = INF;
     dist[x][y] = 0;
     q.push({x,y});
        while(!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            for(int k = 0;k<4;k++)
            {
                int ci = i + di[k], cj = j + dj[k];
                if(ci<1||cj<1||ci>n||cj>m) continue;
                if(dist[ci][cj]!=INF || mat[ci][cj] == '#') continue;
                dist[ci][cj] = dist[i][j] + 1;
                q.push({ci,cj});
            }
        }
}
int main()
{
    P A, M, G;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='A') A.read(i,j);
            if(mat[i][j]=='M') M.read(i,j);
            if(mat[i][j]=='G') G.read(i,j);
        }
    Lee(A.x,A.y);
    int distM = dist[M.x][M.y];
    Lee(M.x,M.y);
    int distG = dist[G.x][G.y];
    cout<<distM + distG;
    return 0;
}
