class Solution{
public:
    int *findTwoElement(int *a, int n) {
        int *result = new int(2);
        for(int i=0;i<n;i++){
            int index = abs(a[i])-1;
            if(a[index]<0)
                result[0] = index+1;
            else
                a[index] *= -1; 
        }
        
        for(int i=0;i<n;i++)
            if(a[i]>0){
                result[1] = i+1;
                break;
            }                 
    
        return result;
    }
};