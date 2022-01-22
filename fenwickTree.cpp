class fenwick{
    vector<int> fen;
public:
    fenwick(int n){
        fen.resize(n+1);
        REP1(i,n) fen[i] = 0;
    }
    // 0 based call and 1 based update
    void update(int index, int val, int n){
        index++;
        while(index<=n){
            fen[index] += val;
            index += (index & (-index));
        }
    }
    void buid(vector<int> &v, int n){
        REP(i,n){
            int index = i;
            int val = v[i];
            update(index, val, n);
        }
    }
    // 0 based call and 1 based sum
    int getSum(int index){
        index++;
        int sum = 0;
        while(index>=1){
            sum += fen[index];
            index -= (index & (-index));
        }
        return sum;
    }
};