int longestMountain(vector<int>& arr) {
        int max_peak = 0;
        int count = 0;
        bool peak_found = false;
        for(int i=1;i<arr.size()-1;i++)
        {
            //found the peak
            if(arr[i-1]<arr[i] && arr[i+1]<arr[i])
            {
                int j=i;
                count = 1;
                peak_found = true;
                //Traversing Back to count the length of the left side
                while(j>0 && arr[j-1]<arr[j])
                {
                    count++;
                    j--;
                }
            }
            //Counting the right side length
            if(arr[i+1]<arr[i])
                count++;
            //In case not part of mountain
            else
                peak_found = false;
            if(max_peak<count && peak_found)
                max_peak = count;
        }
        return max_peak;
    }