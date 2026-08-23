class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.size();

        int k = n / 2;
        int leftCount = 0;
        int leftSum = 0;
        for (int i = 0; i < k; i++)
        {
            if (num[i] == '?')
            {
                leftCount++;
            }
            else
            {
                int val = num[i] - '0';
                leftSum += val;
            }
        }

        int rightCount = 0;
        int rightSum = 0;
        for (int i = k; i < n; i++)
        {
            if (num[i] == '?')
            {
                rightCount++;
            }
            else
            {
                int val = num[i] - '0';
                rightSum += val;
            }
        }

        // if count==1 or count is odd means alice pick at the end then alice win
        if ((leftCount + rightCount) == 1 || (leftCount + rightCount) % 2 == 1)
        {
            return true;
        }

        // //alice can take left side '?' and bob can take right side '?' to cancel out each other
        // while(leftCount>0 && rightCount>0){
        //     leftCount--;
        //     rightCount--;
        // }

        // int diff=abs(leftSum-rightSum);
        // //if only left '?' present
        // if(leftCount!=0){
        //   if(leftCount==2 && diff==9){
        //     return false;
        //   }else if(leftCount==4 && diff==18){
        //     return false;
        //   }else{
        //     return true;
        //   }
        // }

        // //if only right '?' present
        // if(rightCount!=0){
        //   if(rightCount==2 && diff==9){
        //     return false;
        //   }else if(rightCount==4 && diff==18){
        //     return false;
        //   }else{
        //     return true;
        //   }
        // }

        // Bob wins only in this exact case
        if (2 * (leftSum - rightSum) ==
            9 * (rightCount - leftCount))
        {
            return false;
        }

        return true;
    }
};