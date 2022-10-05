class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mxPrice=0, miPrice=INT_MAX;
        int res=0;
        for(int price: prices){
            if(price<mxPrice){
                int currProf=mxPrice-miPrice;
                res+=currProf;
                mxPrice=price;
                miPrice=price;
            }
            else{
                miPrice=min(miPrice, price);
                mxPrice=max(mxPrice, price);
            }
        }
        
        res+=(mxPrice-miPrice);
        return res;
    }
};
