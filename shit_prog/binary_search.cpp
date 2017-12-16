





static int binarySearch( int array[],int lenght,int key){
	int low=0;
	int high=lenght-1;
	int middle;
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

int ricerca(int array[],int key,int left,int right){
	if(left>right)
}
