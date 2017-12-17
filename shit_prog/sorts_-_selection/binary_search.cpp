//programmer:UAI GOD AKA Locicero Giorgio AKA josura
//functions for binary search

//iteration with static memory
static int binarySearch( int array[],int lenght,int key){
	int low=0,high=lenght-1, middle;
	while(low<=high){
		middle=(low+high)/2;
		if (key==array[middle])
		return middle;
		else if (key<array[middle])
		high=middle-1;
		else
		low=middle+1;
	}
	return -1;
}

//recursion
int ricerca(int arr[],int key,int left,int right){
 	if (right>=left){
        int mid = left+(right-left)/2;
        if (arr[mid]==key) return mid;
        if (arr[mid]>key) return ricerca(arr, left, mid-1, key);
        return ricerca(arr, mid+1, right, key);
   }
   return -1;
}
