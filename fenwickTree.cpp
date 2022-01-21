class fenwick{
    vector<int> fen;
public:
    fenwick(int n){
        fen.resize(n+1);
        REP1(i,n) fen[i] = 0;
    }
    void buid(vector<int> &v, int n){
        REP(i,n){
            int index = i;
            index++;
            int val = v[i];
            while(index<=n){
                fen[index] += val;
                index += (index & (-index));
            }
        }
    }
    int getSum(int index){
        int sum = 0;
        while(index>=1){
            sum += fen[index];
            index -= (index & (-index));
        }
        return sum;
    }
};