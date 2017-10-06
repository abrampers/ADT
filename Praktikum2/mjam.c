#include <stdio.h>
#include "jam.h"
#include "boolean.h"

int main() {

	//Kamus
	int n, i;
	long temp;
	JAM J, K, JAkh, JAwal;
	scanf("%d",&n);

	for(i = 1; i <= n; i++) {
		printf("[%d]\n",i);
		BacaJAM(&J);
		BacaJAM(&K);

		if(JLT(J,K)) {
			temp = Durasi(J,K);
		} else temp = Durasi(K,J);

		if (temp >= 86400) temp = temp - 86400;

		printf("%ld\n",temp);

		if (i == 1 && JLT(J,K) == true) {
			JAwal = J;
			JAkh = K;
		} else if (i == 1 && JGT(J,K) == true){
			JAwal = K;
			JAkh = J;
		} else {
			if (JLT(J,JAwal) == true)
				JAwal = J;
			if (JLT(K,JAwal) == true)
				JAwal = K;

			if (JGT(J,JAkh) == true)
				JAkh = J;
			if (JGT(K,JAkh) == true)
				JAkh = K;

		}


	}

	TulisJAM(JAwal);
	printf("\n");
	TulisJAM(JAkh);
	printf("\n");

	return 0;
}
