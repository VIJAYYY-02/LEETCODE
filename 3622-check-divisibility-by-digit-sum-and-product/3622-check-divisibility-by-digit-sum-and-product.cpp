class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int mul=1;
        while(temp>0){
             sum+=temp%10;
             mul*=temp%10;
            temp=temp/10;
        }
       int s=sum+mul;
       return (n%s==0);
        
    }
};