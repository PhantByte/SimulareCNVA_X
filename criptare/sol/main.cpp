#include<bits/stdc++.h>
#include<cmath>
using namespace std;
ifstream fin("criptare.in");
ofstream fout("criptare.out");

int c;
string s;

vector<string> v;

int main()
{

    fin>>c;

    if(c==1)
    {
        fin>>s;
        string cop=s;
        int n=s.size();
        int i=1;
        while(i<=n)
        {
            v.push_back(s);
            char a;
            a=s[0];
            for(int i=0; i<n; i++)
                s[i]=s[i+1];
            s[n-1]=a;
            i++;
        }
        sort(v.begin(), v.end());

        string sol;
        int index=0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]==cop)index=i;
            sol=sol+v[i][n-1];
        }


        fout<<sol<<index;


    }

    if(c==2)
    {
        fin>>s;
        int p=1;
        int index=0;
        int n=0;
        string cop;
        while(s[s.size()-1]>='0' && s[s.size()-1]<='9')
        {
            index=index+(s[s.size()-1]-48)*p;
            s.resize(s.size()-1);
            n=s.size();
            cop=s;
            p=p*10;
        }
        int m[102];
        for(int i=0; i<n; i++)
            m[i]=i;

        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(cop[i]>cop[j] || (cop[i]==cop[j] && m[i]>m[j]))
                {
                    swap(cop[i], cop[j]);
                    swap(m[i], m[j]);
                }
            }
        }

        for(int i=1; i<=n; i++)
        {
            fout<<cop[index];
            index=m[index];
        }


    }


    if(c==3)
    {
        fin>>s;
        string cop=s;
        int n=s.size();
        int i=1;
        while(i<=n)
        {
            v.push_back(s);
            char a;
            a=s[0];
            for(int i=0; i<n; i++)
                s[i]=s[i+1];
            s[n-1]=a;
            i++;
        }
        sort(v.begin(), v.end());
        int maxi=0;
        for(int i1=0; i1<n; i1++)
        {
            for(int j1=0; j1<n; j1++)
            {
                for(int i2=i1+1; i2<n; i2++)
                    for(int j2=j1+1; j2<n; j2++)
                    {
                        if(v[i1][j1]==v[i2][j2] && v[i1][j1]==v[i1][j2] && v[i1][j1]==v[i2][j1])
                            if(abs(i2-i1+1)*abs(j2-j1+1)>maxi)
                            {
                                maxi=abs(i2-i1+1)*abs(j2-j1+1);
                            }
                    }
            }

        }
        fout<<maxi;
    }

    return 0;
}