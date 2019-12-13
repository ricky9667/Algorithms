#include<iostream>
#include<time.h>
using namespace std;

#define MAXN 1000
int n;
const double k1 = 10.0f;
const double k2 = 1.0f;

// 定義型態 molecule 存取資訊
struct molecule{
    char state = 'A'; // 存取狀態
    double kp = k1; // 存取速率常數, 預設為10
    double kTotal = 0; // 存取kTotal, 預設0
} m[MAXN];

// 計算 kTotal
void calculateTotal()
{
    for(int i=1;i<=n;i++)
        m[i].kTotal = m[i-1].kTotal + m[i].kp;
}

// 二分搜
int findLoc(double value, int l, int r)
{
    int mid = (l+r)/2;
    if(l+1==r)
        return r;
    if(value > m[mid].kTotal) 
        return findLoc(value, mid, r);
    if(value < m[mid].kTotal)
        return findLoc(value, l, mid);
}

// 切換狀態 
void switchStatus(int loc)
{
    // AB交換, 1 10交換
    // k1=10, k2=1
    if(m[loc].state=='A')
    {
        m[loc].state = 'B';
        m[loc].kp = k2; 
    }
    else
    {
        m[loc].state = 'A';
        m[loc].kp = k1;
    }
}

void printResult()
{
    // 輸出狀態: A/B
    cout<<"\nState   : ";
    for(int i=1;i<=n;i++)
        printf("%c ",m[i].state);
    
    // 輸出速率常數(?): 1/10
    cout<<"\nRate(Kp): ";
    for(int i=1;i<=n;i++)
        cout<<m[i].kp<<' ';

    // 輸出 Ktotal
    cout<<"\nKtotal  : ";
    for(int i=1;i<=n;i++)
        cout<<m[i].kTotal<<' ';

    cout<<'\n';
}

int main() 
{
    char ch = '1';
    // 設定 rand() seed
    srand(time(NULL)); 

    // 輸入分子數量
    cout<<"Input number of molecules: ";
    cin>>n;

    while(true)
    {
        // 輸入 0 跳出迴圈
        if(ch == '0') 
            break;

        // 計算 kTotal 總和
        calculateTotal();
        // 印出結果
        printResult();

        // 用輸入字元來暫停無限迴圈
        cout<<"\nInput anything to see next result (0 to exit): \n";
        cin>>ch;

        // 取一個 0~1 的隨機值放進 rdm
        double rdm = ((double) rand()/RAND_MAX );
        // kRand = (0~1 隨機值) * kTotal
        double kRand = rdm * m[n].kTotal;

        // 排版用
        cout<<"==================================================\n\n";
        // 印出 (0~1 隨機值) * kTotal
        cout<<"\nValue = "<<kRand<<"\n";
        // 利用二分搜尋法找出比kRand大的最小值的編號
        int location = findLoc(kRand, 0, n+1);

        // 切換位於 location 此分子的狀態
        switchStatus(location);
    }
    return 0;
}

/****************************************/
/* Made by https://github.com/ricky9667 */
/****************************************/