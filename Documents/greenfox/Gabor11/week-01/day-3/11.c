#include <stdio.h>

int main() {
	int k = 1521;
	// tell if k is dividable by 3 or 5

	if (k% 3 || k% 5){
        printf("%d is dividable by 3 or 5.", k);
	}else {
        printf("no.");}
	return 0;
}
