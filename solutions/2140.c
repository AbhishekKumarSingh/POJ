//suppose to run in nlogn time. But gives time limit exceded, while algorithm with complexity n^2 gets accepted.

#include <stdio.h>

int get_fterm(int start, int end, int lterm, int num){
    long long sum;
    int mid = (start + end)/2;
    // sum of AP = (n/2)(a+l); here n = l-a+1;
    sum = ((lterm-mid+1)*(lterm+mid))/2;
    if (start > end)
        return 0;
    if (sum == num)
        return mid;
    if (sum > num)
        return get_fterm(mid+1, end, lterm, num);
    else {
        return get_fterm(start, mid-1, lterm, num);
    }
}

int num_ways(int ncows) {
    int i, limit, fterm = 0, count = 0;
    if (ncows < 1)
        return 0;
    if (ncows == 1)
        return 1;
    (ncows % 2 == 0)?(limit = ncows/2) : (limit = (ncows/2)+1);

    for (i = limit; i > 0; i--) {
        // i is last term of AP. Sum of AP = (n/2)(a+l);
        // finding first term using binary search mechanism
        fterm = get_fterm(1, i, i, ncows);
        if (fterm)
            count++;
    }
    // +1 for number itself.
    return count+1;
}

int main()
{
    int num_cow;
    scanf("%d", &num_cow);
    printf("%d\n", num_ways(num_cow));
    return 0;
}
