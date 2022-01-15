class Solution{
public:
    int minSteps(int d){
        int steps = 1, sum = 0;
        while(1){
            sum += steps;
            if(sum==d || (sum>d && (d-sum)%2==0))
                return steps;
            steps++;
        }
        return 0;
    }
};