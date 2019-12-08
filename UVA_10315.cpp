#include<bits/stdc++.h>
using namespace std;

#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS wez(testow)while(testow--) //for multilple cases problems
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define clr(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1]
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF 1001001001
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n",n); }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 10000
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi;
typedef vector<string>vs;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef map<int,int>mpii;
// directions
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }


int realNumber(char c){
    if(c>='2' && c<='9')return char2Int(c);

    else if (c=='T')return 10;
    else if (c=='J')return 11;
    else if (c=='Q')return 12;
    else if (c=='K')return 13;
    else if (c=='A')return 14;

}

bool straight_flush(vs fhalf,vi fhalfNum){
    F(i,0,5){
        if(fhalf[i][1]!=fhalf[0][1]){
            return 0;
        }
    }
    F(i,1,5){
        if(fhalfNum[i]!=fhalfNum[i-1]+1)return 0;
    }
    return 1;
}

bool four_kind(vs fhalf,vi fhalfNum){
    mpii x;
    int maxx=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;
        maxx=max(maxx,x[fhalfNum[i]] );
    }
    if(maxx>=4)return 1;
    else return 0;
}

bool full_house(vs fhalf,vi fhalfNum){
    mpii x;
    int maxx=INT_MIN;
    int maxx2=INT_MIN;
    int mx=INT_MIN;
    int mx2=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;

    }

    FE(i,2,14){
        if(x[i]>=maxx){
            maxx=x[i];
            mx=i;
        }
    }
    FE(i,2,14){
        if(x[i]>=maxx2 && i!=mx){
            maxx2=x[i];
            mx2=i;
        }
    }

    //cout<<maxx<<" "<<maxx2<<endl;
    if(maxx==3 && maxx2==2)return 1;
    else return 0;
}

bool flush(vs fhalf,vi fhalfNum){
    F(i,0,5){
        if(fhalf[i][1]!=fhalf[0][1]){
            return 0;
        }
    }

    return 1;
}

bool straight(vs fhalf,vi fhalfNum){
    F(i,1,5){
        if(fhalfNum[i]!=fhalfNum[i-1]+1)return 0;
    }
    return 1;
}

bool three_kind(vs fhalf,vi fhalfNum){
    mpii x;
    int maxx=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;
        if(x[fhalfNum[i]]>=maxx){
            maxx=x[fhalfNum[i]];

        }
    }
    if(maxx==3)return 1;
    else return 0;
}

bool two_pairs(vs fhalf,vi fhalfNum){
    mpii x;
    int maxx=INT_MIN;
    int maxx2=INT_MIN;
    int mx=INT_MIN;
    int mx2=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;

    }

    FE(i,2,14){
        if(x[i]>=maxx){
            maxx=x[i];
            mx=i;
        }
    }
    FE(i,2,14){
        if(x[i]>=maxx2 && i!=mx){
            maxx2=x[i];
            mx2=i;
        }
    }
    if(maxx==2 && maxx2==2)return 1;
    else return 0;
}

bool pairs(vs fhalf,vi fhalfNum){
     mpii x;
    int maxx=INT_MIN;

    F(i,0,5){
        x[fhalfNum[i]]++;
        if(x[fhalfNum[i]]>=maxx){
            maxx=x[fhalfNum[i]];

        }
    }
    if(maxx==2)return 1;
    else return 0;
}

int eval_straightFlush(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
    FFE(i,4,0){
        if(fhalfNum[i]>lhalfNum[i]) return 1;
        else if (lhalfNum[i]>fhalfNum[i])return 2;

    }
    return -1;
}

int eval_fourKind(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
    mpii x;
    int maxx=INT_MIN;
    int mx=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;
        if(x[fhalfNum[i]]>=maxx){
            maxx=x[fhalfNum[i]];
            mx=fhalfNum[i];
        }
    }
    //printV(fhalfNum);

    mpii y;
    int maxy=INT_MIN;
    int my=INT_MIN;
    F(i,0,5){
        y[lhalfNum[i]]++;
        if(y[lhalfNum[i]]>=maxy){
            maxy=y[lhalfNum[i]];
            my=lhalfNum[i];
        }
    }
    //cout<<mx<<" "<<my<<endl;

    if(mx>my)return 1;
    else if(my>mx)return 2;
    else{
        FE(i,2,14){
            if(x[i]==1 || x[i]==5)mx=i;
            if(y[i]==1 || y[i]==5)my=i;
        }

        if(mx>my)return 1;
        else if(my>mx)return 2;
        else return -1;

    }
}

int eval_fullHouse(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
     mpii x;
    int maxx=INT_MIN;
    int maxx2=INT_MIN;
    int mx=INT_MIN;
    int mx2=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;

    }

    FE(i,2,14){
        if(x[i]>=maxx){
            maxx=x[i];
            mx=i;
        }
    }
    FE(i,2,14){
        if(x[i]>=maxx2 && i!=mx){
            maxx2=x[i];
            mx2=i;
        }
    }

     mpii y;
    int maxy=INT_MIN;
    int maxy2=INT_MIN;
    int my=INT_MIN;
    int my2=INT_MIN;
    F(i,0,5){
        y[lhalfNum[i]]++;

    }

    FE(i,2,14){
        if(y[i]>=maxy){
            maxy=y[i];
            my=i;
        }
    }
    FE(i,2,14){
        if(y[i]>=maxy2 && i!=my){
            maxy2=y[i];
            my2=i;
        }
    }

    if(mx>my)return 1;
    else if(my>mx)return 2;
    else{
        if(mx2>my2)return 1;
        else if(my2>mx2)return 2;
        else return -1;
    }
}

int eval_flush(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
     FFE(i,4,0){
        if(fhalfNum[i]>lhalfNum[i]) return 1;
        else if (lhalfNum[i]>fhalfNum[i])return 2;

    }
    return -1;
}

int eval_straight(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
    FFE(i,4,0){
        if(fhalfNum[i]>lhalfNum[i]) return 1;
        else if (lhalfNum[i]>fhalfNum[i])return 2;

    }
    return -1;
}

int eval_threeKind(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
     mpii x;
    int maxx=INT_MIN;
    int maxx2=INT_MIN;
    int mx=INT_MIN;
    int mx2=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;

    }

    FE(i,2,14){
        if(x[i]>=maxx){
            maxx=x[i];
            mx=i;
        }
    }


     mpii y;
    int maxy=INT_MIN;
    int maxy2=INT_MIN;
    int my=INT_MIN;
    int my2=INT_MIN;
    F(i,0,5){
        y[lhalfNum[i]]++;

    }

    FE(i,2,14){
        if(y[i]>=maxy){
            maxy=y[i];
            my=i;
        }
    }
    if(mx>my)return 1;
    else if(my>mx) return 2;
    else{
        vi p;
        vi q;
         FE(i,2,14){
            if(x[i]==1)p.pb(i);
            if(y[i]==1)q.pb(i);
        }

        if(p[1]>q[1])return 1;
        else if(q[1]>p[1])return 2;
        else {
            if(p[0]>q[0])return 1;
            else if(q[0]>p[0])return 2;
            else return -1;
        }
    }


}
int eval_twoPairs(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
     mpii x;
    int maxx=INT_MIN;
    int maxx2=INT_MIN;
    int mx=INT_MIN;
    int mx2=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;

    }

    FE(i,2,14){
        if(x[i]>=maxx){
            maxx=x[i];
            mx=i;
        }
    }
    FE(i,2,14){
        if(x[i]>=maxx2 && i!=mx){
            maxx2=x[i];
            mx2=i;
        }
    }

     mpii y;
    int maxy=INT_MIN;
    int maxy2=INT_MIN;
    int my=INT_MIN;
    int my2=INT_MIN;
    F(i,0,5){
        y[lhalfNum[i]]++;

    }



    FE(i,2,14){
        if(y[i]>=maxy){
            maxy=y[i];
            my=i;
        }
    }
    FE(i,2,14){
        if(y[i]>=maxy2 && i!=my){
            maxy2=y[i];
            my2=i;
        }
    }
    //cout<<maxx<<" "<<maxy<<" "<<maxx2<<" "<<maxy2<<endl;
   // cout<<mx<<" "<<my<<" "<<mx2<<" "<<my2<<endl;

    if(mx>my)return 1;
    else if(my>mx)return 2;
    else{
        if(mx2>my2)return 1;
        else if(my2>mx2)return 2;
        else{
            int mx3,my3;
            FE(i,2,14){
            if(x[i]==1)mx3=i;
            if(y[i]==1)my3=i;
        }
         if(mx3>my3)return 1;
         else if(my3>mx3)return 2;
         else return -1;

        }
    }
}

int eval_pairs(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
     mpii x;
    int maxx=INT_MIN;
    int maxx2=INT_MIN;
    int mx=INT_MIN;
    int mx2=INT_MIN;
    F(i,0,5){
        x[fhalfNum[i]]++;

    }

    FE(i,2,14){
        if(x[i]>=maxx){
            maxx=x[i];
            mx=i;
        }
    }


     mpii y;
    int maxy=INT_MIN;
    int maxy2=INT_MIN;
    int my=INT_MIN;
    int my2=INT_MIN;
    F(i,0,5){
        y[lhalfNum[i]]++;

    }

    FE(i,2,14){
        if(y[i]>=maxy){
            maxy=y[i];
            my=i;
        }
    }

    if(mx>my)return 1;
    else if(my>mx)return 2;
    else{
            vi p;
        vi q;
         FE(i,2,14){
            if(x[i]==1)p.pb(i);
            if(y[i]==1)q.pb(i);
        }

        FFE(i,2,0){
            if(p[i]>q[i])return 1;
            else if(p[i]<q[i])return 2;
        }
        return -1;

    }
}

int eval_highCards(vs fhalf,vs lhalf, vi fhalfNum,vi lhalfNum){
    FFE(i,4,0){
        if(fhalfNum[i]>lhalfNum[i]) return 1;
        else if (lhalfNum[i]>fhalfNum[i])return 2;

    }
    return -1;
}




int typeDefine(vs fhalf,vi fhalfNum){
    if(straight_flush(fhalf,fhalfNum)){
        return 9;
    }
    else if(four_kind(fhalf,fhalfNum)){
        return 8;
    }
    else if(full_house(fhalf,fhalfNum)){
        return 7;
    }
    else if(flush(fhalf,fhalfNum)){
        return 6;
    }
    else if(straight(fhalf,fhalfNum)){
        return 5;
    }
    else if(three_kind(fhalf,fhalfNum)){
        return 4;
    }
    else if(two_pairs(fhalf,fhalfNum)){
        return 3;
    }
    else if(pairs(fhalf,fhalfNum)){
        return 2;
    }
    else return 1;

}




main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str;
    while(cin>>str){
        vs dans;
        dans.pb(str);
        FE(i,1,9){
            string x;
            cin>>x;
            dans.pb(x);
        }
        vs fhalf,lhalf;
        vi fhalfNum,lhalfNum;

        F(i,0,5){
            fhalf.pb(dans[i]);
        }
        F(i,5,10){
            lhalf.pb(dans[i]);
        }
        F(i,0,5){
            fhalfNum.pb(realNumber(dans[i][0]));
        }
        F(i,5,10){
            lhalfNum.pb(realNumber(dans[i][0]));
        }

        sort(ALL(fhalfNum));
        sort(ALL(lhalfNum));

        int type1=typeDefine(fhalf,fhalfNum);
        int type2=typeDefine(lhalf,lhalfNum);

        //cout<<type1<<" "<<type2<<endl;
        if(type1 > type2)printf("Black wins.\n");
        else if(type2>type1)printf("White wins.\n");
        else{
            int ans;
            if(type1==9 && type2==9){
                ans=eval_straightFlush(fhalf,lhalf,fhalfNum,lhalfNum);
            }
            else if(type1==8 && type2==8){
                ans=eval_fourKind(fhalf,lhalf,fhalfNum,lhalfNum);
            }
            else if(type1==7 && type2==7){
                ans=eval_fullHouse(fhalf,lhalf,fhalfNum,lhalfNum);
            }
            else if(type1==6 && type2==6){
                ans=eval_flush(fhalf,lhalf,fhalfNum,lhalfNum);
            }
            else if(type1==5 && type2==5){
                ans=eval_straight(fhalf,lhalf,fhalfNum,lhalfNum);
            }
            else if(type1==4 && type2==4){
                ans=eval_threeKind(fhalf,lhalf,fhalfNum,lhalfNum);
            }
            else if(type1==3 && type2==3){
                ans=eval_twoPairs(fhalf,lhalf,fhalfNum,lhalfNum);
            }
            else if(type1==2 && type2==2){
                ans=eval_pairs(fhalf,lhalf,fhalfNum,lhalfNum);
            }
            else{
                ans=eval_highCards(fhalf,lhalf,fhalfNum,lhalfNum);
            }

            if(ans==1)printf("Black wins.\n");
            else if(ans==2)printf("White wins.\n");
            else printf("Tie.\n");
        }


    }
}





