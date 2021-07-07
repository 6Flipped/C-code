#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int main()
{
	int arr[4][4] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};

	return 0;
}

//int main()
//{
//	int i, j, a = 0;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (j % 2)
//				break;
//			a++;
//		} a++;
//	} printf("%d\n", a);
//}

//int main()
//{
//	int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 }, * q[4], k;
//	for (k = 0; k < 4; k++) {
//		q[k] = &a[k * 3];
//	} 
//		printf("%d\n", q[3][1]);
//	return 0;
//}
//
//int search(int* nums, int numsSize, int target)
//{
//    int low =0, high = numsSize - 1,mid=0;
//    while (low <= high)
//    {
//        mid = (low + high) / 2;
//        if (*(nums + mid) > target)
//            high = mid - 1;
//        else if (*(nums + mid) < target)
//            low = mid + 1;
//        else
//            return mid;
//    }
//    if (low > high)
//        return -1;
//    else
//        return 0;
//}
//
//int main()
//{
//
//    int arr1[6] = { -1,0,3,5,9,12 };
//    int target, i;
//    scanf("%d", &target);
//    i = search(arr1, 6, target);
//    printf("%d\n", i);
//    return 0;
//}