/*
=========================================check prime===============================================
bool isPrime(int n){
    if(n==1) return false;
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0){
            return false;
        }
    }
    return true;
}

============================================ sieve and to find kth prime ==================================================

//here false is prime

bool is_Prime[1000001];
void sieve(){
    int maxN = 1000000;
    is_Prime[0] = is_Prime[1] = true;
    for (int i = 2; i*i <= maxN; i++)
    {
        if(!is_Prime[i]){
            for(int j=i*i; j<=maxN; j+=i){
                is_Prime[j] = true;
            }
        }
    }
    //to find kth prime make an array and check if !is_Prime[i] array input i
}

==================================================prime factorization=============================

void primeFact(int n){
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i==0){
            int cnt = 0;
            while (n%i == 0)
            {
                cnt++, n/= i;
            }
            cout<<i<<"^"<<cnt<<endl;
        }
    }
    if(n>1) cout<<n<<"^"<<1<<endl;
}

***(log(n) time complexity) Using sieve:-
    Set all the elements to -1 then mark all the numbers to their least prime number(that is for
    every number make its multiple to itself till end from i itself not from i*i) 
    and then for i th elements if ar[i] = x, then make i/=x, then ar[new i] till i==1

=============================================exponential power======================================
for   a^n
void power(int a, int n){
    int res = 1;
    while(n){
        if(n%2){
            res *= a, n--;
        }else{
            a *= a, n/=2;
        } 
    }
    return res;
}

modulo exponential:-

void power(int a, int n, int p){
    int res = 1;
    while(n){
        if(n%2){
            res = (res*a)%p, n--;
        }else{
            a = (a*a)%p, n/=2;
        } 
    }
    return res;
}

===========================================Matrix Exponentiation=================================
#define N 101
int ar[N][N], I[N][N];

void mulMat(int A[][N], int B[][N], int dim){
    int res[dim+1][dim+1];

    REP(i, dim){
        REP(j, dim){
            res[i][j] = 0;
            REP(k, dim) res[i][j] += A[i][k] * B[k][j];
        }
    }
    REP(i, dim) REP(j, dim) A[i][j] = res[i][j];
}

void powerMat(int A[][N], int dim, int n){
    REP(i,dim) REP(j,dim)
    {
        if(i==j) I[i][j] = 1;
        else    I[i][j] = 0;
    }
    // exponential
    while(n){
        if(n%2) mulMat(I, A, dim), n--;
        else    mulMat(A, A, dim), n/=2;
    }

    REP(i, dim) REP(j,dim)  A[i][j]=I[i][j];
}
// function call -> powerMat(ar, dim, n); ar is passed as refrence and n is power to the matrix



================================== Nth fibonacci or recurrence term in O(Logn) ==================
Any recurrence for e.g. fibonacci :- 1,1,2,3,5,8,13.....
    [f1 f2] * [A B] = [f2 f3]
              [C D]
    f1*A + f2*C = f2 -> A=0,C=1 for fibonacci
    f1*B + f2*D = f3 -> B=1,D=1 for fibonacci
    [f1 f2] * [A B]^n-1 = [fn fn+1]
              [C D]

================================== Nth fibonacci or recurrence term in O(Logn) ==================
*/


/*
================================Modular Arithmetic==============================================
--> GCD :
    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
    Property -> gcd(a, b) == gcd(a-b, b) // a>b
    ans[0] = ar[0];
    REP1(i,n-1){
        ans[i] = gcd(ans[i-1], ar[i]);
    }
    suf[n-1] = ar[n-1];
    for(int i=n-2;i>=0;i--){
        suf[i] = gcd(ar[i], suf[i+1]);
    }
    cout<<gcd(suf[r+1], ans[l-1]);

*/
