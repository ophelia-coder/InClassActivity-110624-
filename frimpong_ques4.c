
#include <stdio.h>



int main(){

int numbers[10] = {10,20,3,4,6,7,8,9,22,11};

int *ptr2max = numbers;
for(int i=0;i<10;i++){
if(numbers[i] > *ptr2max){
	*ptr2max = numbers[i];
}
}
printf("max =%d\n", *ptr2max);
return 0;

}
